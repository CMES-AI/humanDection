
#include "interfaceManager.h"
#include "zeroMQ.h"
#include "zeroMQServer.h"

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

