#pragma once


#include <zmq.h>
#include <string>

#include <cassert>
#include <iostream>
#include <thread>
class zeroMQImage
{
public:
    zeroMQImage();
    virtual ~zeroMQImage();

    void init();
    void close();

    int sendMessage(const std::string& message);

    void waitMessage();

private:
    std::string receiveMessage(void* socket);
    void zmqThread();
   
private:
    void* requester;
    void* context;
    std::atomic<bool> running;
    std::thread serverThread;
};

