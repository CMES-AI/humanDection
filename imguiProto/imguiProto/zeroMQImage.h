#pragma once


#include <zmq.h>
#include <string>

#include <cassert>
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <opencv2/opencv.hpp>
class zeroMQImage
{
public:
    zeroMQImage();
    virtual ~zeroMQImage();

    void init(const char* addr);
    void close();

    int sendMessage(const std::string& message);

    void waitMessage(std::queue<cv::Mat>* dataQueue, std::mutex* mtx);

private:
    std::string receiveMessage(void* socket);
    void zmqThread();
   
private:
    void* requester;
    void* context;
    std::atomic<bool> running;
    std::thread serverThread;

    std::queue<cv::Mat>* dataQueue; // ���� ������ ť
    std::mutex* mtx; // ����ȭ�� ���� ���ؽ�
};

