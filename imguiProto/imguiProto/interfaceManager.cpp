
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


void interfaceManager::intZeroMQImage() {
    if (NULL == zeromqimage) {
        zeromqimage = new zeroMQImage();
        zeromqimage->init();
    }
}
void interfaceManager::runZeroMQImage() {
    zeromqimage->waitMessage();
}

void interfaceManager::sendZeroMQImage(const std::string& message) {
    zeromqimage->sendMessage(message);
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
