#pragma once

#include <string>
#include <mutex>
#include <queue>

#include <opencv2/opencv.hpp>

class zeroMQ;
class zeroMQServer;
class zeroMQImage;
class zeroMQImageServer;

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

    void intZeroMQImage_1(const char* addr);
    void runZeroMQImage_1(std::queue<cv::Mat>* dataQueue, std::mutex* mtx);
    void sendZeroMQImage_1(const std::string& message);

    void intZeroMQImage_2(const char* addr);
    void runZeroMQImage_2(std::queue<cv::Mat>* dataQueue, std::mutex* mtx);
    void sendZeroMQImage_2(const std::string& message);

    void intZeroMQImageServer();
    void runZeroMQImageServer();
    void sendZeroMQImageServer(const std::string& message);



private:
    // �����ڸ� private���� �����Ͽ� �ܺο����� ������ ����
    interfaceManager();

    zeroMQ* zeroMq;
    zeroMQServer* zeroMqServer;
    zeroMQImage* zeromqimage_1;
    zeroMQImage* zeromqimage_2;
    zeroMQImageServer* zeromqimageserver;
};

