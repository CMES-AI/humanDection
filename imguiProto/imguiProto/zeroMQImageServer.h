#pragma once

#include <zmq.h>
#include <string>
#include <thread>

class string;
class zeroMQImageServer
{
public:
    zeroMQImageServer();
    virtual ~zeroMQImageServer();

    void init();
    void runServer();
    void closeServer();
    void sendMessage(const std::string& message);

private:
    void* responder;
    void* context;

    void zmqThread();
    std::thread serverThread;
};

