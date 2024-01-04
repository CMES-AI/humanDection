#include "zeroMQServer.h"

#include <cassert>
#include <iostream>


zeroMQServer::zeroMQServer() {

}

zeroMQServer::~zeroMQServer() {

}

void zeroMQServer::init() {
    // 컨텍스트와 소켓 준비
    context = zmq_ctx_new();
    responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://172.16.20.51:5555");
    assert(rc == 0);
}
void zeroMQServer::runServer() {
    std::string msg = receiveMessage();
    std::cout << "Received: " << msg << std::endl;
    sendMessage( "World");
}
void zeroMQServer::closeServer() {

}
void zeroMQServer::sendMessage(const std::string& message) {
    zmq_msg_t zmqMessage;
    zmq_msg_init_size(&zmqMessage, message.size());
    memcpy(zmq_msg_data(&zmqMessage), message.data(), message.size());
    zmq_msg_send(&zmqMessage, responder, 0);
    zmq_msg_close(&zmqMessage);
}

std::string zeroMQServer::receiveMessage() {
    zmq_msg_t zmqMessage;
    zmq_msg_init(&zmqMessage);
    zmq_msg_recv(&zmqMessage, responder, 0);
    std::string msg(static_cast<char*>(zmq_msg_data(&zmqMessage)), zmq_msg_size(&zmqMessage));
    zmq_msg_close(&zmqMessage);
    return msg;
}


