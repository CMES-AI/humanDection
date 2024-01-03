#pragma once

#include <string>

class zeroMQ;
class zeroMQServer;

class interfaceManager
{

public:
    // Singleton ��ü�� ��ȯ�ϴ� �Լ�
    static interfaceManager& getInstance() {
        static interfaceManager instance;
        return instance;
    }

    // ���� �����ڿ� ���� �����ڸ� �����Ͽ� ���縦 ����
    interfaceManager(const interfaceManager&) = delete;
    void operator=(const interfaceManager&) = delete;
    void intZeroMQ();
    void runZeroMQ();
    void sendZeroMQ(const std::string& message);


    void intZeroMQServer();
    void runZeroMQServer();
    void sendZeroMQServer(const std::string& message);

private:
    // �����ڸ� private���� �����Ͽ� �ܺο����� ������ ����
    interfaceManager();

    zeroMQ* zeroMq;
    zeroMQServer* zeroMqServer;
};

