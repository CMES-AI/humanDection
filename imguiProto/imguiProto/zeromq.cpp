#include "zeroMQ.h"


zeroMQ::zeroMQ() : requester(NULL), context(NULL), running(true) {

}

zeroMQ::~zeroMQ() {

}

void zeroMQ::init() {
    // 컨텍스트와 소켓 준비
    context = zmq_ctx_new();
    requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://172.16.20.7:5555");
}
void zeroMQ::close() {
    if (serverThread.joinable()) {
        serverThread.join();
    }
    zmq_close(requester);
    zmq_ctx_destroy(context);
}
void  zeroMQ::sendMessage(const std::string& message) {
    zmq_msg_t zmqMessage;
    zmq_msg_init_size(&zmqMessage, message.size());
    memcpy(zmq_msg_data(&zmqMessage), message.data(), message.size());
    zmq_msg_send(&zmqMessage, requester, 0);
    zmq_msg_close(&zmqMessage);
}
std::string zeroMQ::receiveMessage(void* socket) {
    zmq_msg_t zmqMessage;
    zmq_msg_init(&zmqMessage);
    zmq_msg_recv(&zmqMessage, socket, 0);
    std::string msg(static_cast<char*>(zmq_msg_data(&zmqMessage)), zmq_msg_size(&zmqMessage));
    zmq_msg_close(&zmqMessage);
    
    return msg;
}

void zeroMQ::waitMessage() {
    
    serverThread = std::thread(&zeroMQ::zmqThread, this);
}
void zeroMQ::zmqThread() {

      sendMessage("start");

      receiveMessage(requester);
}
