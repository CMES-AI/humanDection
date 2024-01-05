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
    // 생성자를 private으로 설정하여 외부에서의 생성을 방지
    interfaceManager();

    zeroMQ* zeroMq;
    zeroMQServer* zeroMqServer;
    zeroMQImage* zeromqimage_1;
    zeroMQImage* zeromqimage_2;
    zeroMQImageServer* zeromqimageserver;
};

