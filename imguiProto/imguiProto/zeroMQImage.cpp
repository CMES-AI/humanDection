#include "zeroMQImage.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include "dataManager.h"

typedef unsigned char uchar;
using namespace std;

zeroMQImage::zeroMQImage() : requester(NULL), context(NULL), running(true) {

}

zeroMQImage::~zeroMQImage() {

}

void zeroMQImage::init(const char* addr) {
    // 컨텍스트와 소켓 준비
    context = zmq_ctx_new();
    requester = zmq_socket(context, ZMQ_SUB);
    int rc = zmq_connect(requester, addr);

    assert(rc == 0);

    // Subscribe to all messages
    rc = zmq_setsockopt(requester, ZMQ_SUBSCRIBE, "", 0);
    assert(rc == 0);
}
void zeroMQImage::close() {

    serverThread.join();
    zmq_close(requester);
    zmq_ctx_destroy(context);
}
int  zeroMQImage::sendMessage(const std::string& message) {
    // Load the image

    std::string imagePath = "..\\..\\misc\\images\\kcch.png";

    cv::Mat img = cv::imread(imagePath, cv::IMREAD_COLOR);

    // Check if the image was loaded
    if (img.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
        return -1;
    }
    // Convert the image to a buffer
    std::vector<uchar> buffer;
    cv::imencode(".png", img, buffer);

    // Send the image
    zmq_send(requester, reinterpret_cast<void*>(buffer.data()), buffer.size(), 0);
    return 0;
}
std::string zeroMQImage::receiveMessage(void* socket) {
    zmq_msg_t zmqMessage;
    zmq_msg_init(&zmqMessage);
    zmq_msg_recv(&zmqMessage, socket, 0);
    std::string msg(static_cast<char*>(zmq_msg_data(&zmqMessage)), zmq_msg_size(&zmqMessage));
    zmq_msg_close(&zmqMessage);

    return msg;
}

void zeroMQImage::waitMessage(std::queue<cv::Mat>* dataQueue_, std::mutex* mtx_) {

    dataQueue = dataQueue_; // 공유 데이터 큐
    mtx = mtx_; // 동기화를 위한 뮤텍스
    serverThread = std::thread(&zeroMQImage::zmqThread, this);
}

void zeroMQImage::zmqThread() {
    zmq_msg_t reply;
    int rc = zmq_msg_init(&reply);
    assert(rc == 0);

    for (;;) {

        rc = zmq_msg_recv(&reply, requester, 0);
        assert(rc != -1);
        // Get the size of the received message
        size_t size = zmq_msg_size(&reply);

        std::cout << "Received: " << size << std::endl;
        // Create a cv::Mat object from the received data
        cv::Mat img = cv::imdecode(cv::Mat(1, size, CV_8UC1, zmq_msg_data(&reply)), cv::IMREAD_COLOR);

        std::lock_guard<std::mutex> lock(*mtx);
        dataQueue->push(img);

//        cv::imshow("Received", img);
        cv::waitKey(1);
    }

    
   
      
   

     

}
