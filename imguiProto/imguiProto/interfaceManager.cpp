
#include "interfaceManager.h"
#include "zeroMQ.h"
#include "zeroMQServer.h"
#include "zeroMQImage.h"
#include "zeroMQImageServer.h"


void interfaceManager::intZeroMQ() {
    if (NULL == zeroMq) {
        zeroMq = new zeroMQ();
        zeroMq->init();
    }
    
}
void interfaceManager::runZeroMQ() {
    zeroMq->waitMessage();
}

void interfaceManager::sendZeroMQ(const std::string& message) {
    zeroMq->sendMessage(message);
}

interfaceManager::interfaceManager() : zeroMq(NULL){

}

void interfaceManager::intZeroMQServer() {
    if (NULL == zeroMqServer) {
        zeroMqServer = new zeroMQServer();
        zeroMqServer->init();
    }
}
void interfaceManager::runZeroMQServer() {
    zeroMqServer->runServer();
}
void interfaceManager::sendZeroMQServer(const std::string& message) {
    zeroMqServer->sendMessage(message);
}


void interfaceManager::intZeroMQImage_1(const char* addr) {
    if (NULL == zeromqimage_1) {
        zeromqimage_1 = new zeroMQImage();
        zeromqimage_1->init(addr);
    }
}
void interfaceManager::runZeroMQImage_1(std::queue<cv::Mat>* dataQueue, std::mutex* mtx) {
    zeromqimage_1->waitMessage(dataQueue, mtx);
}

void interfaceManager::sendZeroMQImage_1(const std::string& message) {
    zeromqimage_1->sendMessage(message);
}

void interfaceManager::intZeroMQImage_2(const char* addr) {
    if (NULL == zeromqimage_2) {
        zeromqimage_2 = new zeroMQImage();
        zeromqimage_2->init(addr);
    }
}
void interfaceManager::runZeroMQImage_2(std::queue<cv::Mat>* dataQueue, std::mutex* mtx) {
    zeromqimage_2->waitMessage(dataQueue, mtx);
}

void interfaceManager::sendZeroMQImage_2(const std::string& message) {
    zeromqimage_2->sendMessage(message);
}

void interfaceManager::intZeroMQImageServer() {
    if (NULL == zeromqimageserver) {
        zeromqimageserver = new zeroMQImageServer();
        zeromqimageserver->init();
    }
}
void interfaceManager::runZeroMQImageServer() {
    zeromqimageserver->runServer();
}
void interfaceManager::sendZeroMQImageServer(const std::string& message) {
    zeromqimageserver->sendMessage(message);
}
