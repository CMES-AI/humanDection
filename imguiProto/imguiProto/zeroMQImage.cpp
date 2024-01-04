#include "zeroMQImage.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

typedef unsigned char uchar;
using namespace std;

zeroMQImage::zeroMQImage() : requester(NULL), context(NULL), running(true) {

}

zeroMQImage::~zeroMQImage() {

}

void zeroMQImage::init() {
    // 컨텍스트와 소켓 준비
    context = zmq_ctx_new();
    requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");


}
void zeroMQImage::close() {
  
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

void zeroMQImage::waitMessage() {

    sendMessage("start");
}

