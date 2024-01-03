#pragma once

#include <zmq.h>
#include <string>

class string;
class zeroMQServer
{
public:
    zeroMQServer();
    virtual ~zeroMQServer();

    void init();
    void runServer();
    void closeServer();
    std::string receiveMessage();
    void sendMessage(const std::string& message);
    
private:
    void* responder;
    void* context;
};

