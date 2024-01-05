#include "zeroMQImageServer.h"
#include "zeroMQServer.h"

#include <cassert>
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

zeroMQImageServer::zeroMQImageServer() {

}

zeroMQImageServer::~zeroMQImageServer() {

}

void zeroMQImageServer::init() {
    // 컨텍스트와 소켓 준비
    context = zmq_ctx_new();
    responder = zmq_socket(context, ZMQ_SUB);
    
    int rc = zmq_bind(responder, "tcp://*:5555");
    assert(rc == 0);
}
void zeroMQImageServer::runServer() {
    serverThread = std::thread(&zeroMQImageServer::zmqThread, this);
}
void zeroMQImageServer::closeServer() {
    // Close the socket and context
    zmq_close(responder);
    zmq_ctx_destroy(context);

}
void zeroMQImageServer::sendMessage(const std::string& message) {
    zmq_msg_t zmqMessage;
    zmq_msg_init_size(&zmqMessage, message.size());
    memcpy(zmq_msg_data(&zmqMessage), message.data(), message.size());
    zmq_msg_send(&zmqMessage, responder, 0);
    zmq_msg_close(&zmqMessage);
}

void zeroMQImageServer::zmqThread() {
    zmq_msg_t reply;
    zmq_msg_init(&reply);
    zmq_msg_recv(&reply, responder, 0);
    for (;;) {
  
        // Get the size of the received message
        size_t size = zmq_msg_size(&reply);

        // Create a cv::Mat object from the received data
        cv::Mat img = cv::imdecode(cv::Mat(1, size, CV_8UC1, zmq_msg_data(&reply)), cv::IMREAD_COLOR);

        // Display the image
        cv::imshow("Received", img);
        cv::waitKey(1);

  
    }
    zmq_msg_close(&reply);
   
}
