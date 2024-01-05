#pragma once

#include <string>

#include <mutex>
#include <queue>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

typedef unsigned char uchar;
using namespace std;

class dataManager
{
public:
    // Singleton ��ü�� ��ȯ�ϴ� �Լ�
    static dataManager& getInstance() {
        static dataManager instance;
        return instance;
    }

    // ���� �����ڿ� ���� �����ڸ� �����Ͽ� ���縦 ����
    dataManager(const dataManager&) = delete;
    void operator=(const dataManager&) = delete;

    // �����ڸ� private���� �����Ͽ� �ܺο����� ������ ����
    dataManager();


    std::queue<cv::Mat> dataQueue_1; // ���� ������ ť
    std::mutex mtx_1; // ����ȭ�� ���� ���ؽ�

    std::queue<cv::Mat> dataQueue_2; // ���� ������ ť
    std::mutex mtx_2; // ����ȭ�� ���� ���ؽ�
};

