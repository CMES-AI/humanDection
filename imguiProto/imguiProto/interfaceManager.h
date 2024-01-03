#pragma once

#include <string>

class zeroMQ;
class zeroMQServer;

class interfaceManager
{

public:
    // Singleton 객체를 반환하는 함수
    static interfaceManager& getInstance() {
        static interfaceManager instance;
        return instance;
    }

    // 복사 생성자와 대입 연산자를 삭제하여 복사를 방지
    interfaceManager(const interfaceManager&) = delete;
    void operator=(const interfaceManager&) = delete;
    void intZeroMQ();
    void runZeroMQ();
    void sendZeroMQ(const std::string& message);


    void intZeroMQServer();
    void runZeroMQServer();
    void sendZeroMQServer(const std::string& message);

private:
    // 생성자를 private으로 설정하여 외부에서의 생성을 방지
    interfaceManager();

    zeroMQ* zeroMq;
    zeroMQServer* zeroMqServer;
};

