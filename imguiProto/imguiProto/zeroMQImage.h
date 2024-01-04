#pragma once


#include <zmq.h>
#include <string>

#include <cassert>
#include <iostream>

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

private:
    void* requester;
    void* context;
    std::atomic<bool> running;
    
};

