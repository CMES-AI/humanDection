#pragma once


#include <zmq.h>
#include <string>

class zeroMQ
{
public:
    zeroMQ();
    virtual ~zeroMQ();

    void init();
    void close();

    void sendMessage( const std::string& message);
   
    void waitMessage();

private:
    std::string receiveMessage(void* socket);
    void zmqThread();

private:
    void* requester;
    void* context;
};

