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
    // Singleton 객체를 반환하는 함수
    static dataManager& getInstance() {
        static dataManager instance;
        return instance;
    }

    // 복사 생성자와 대입 연산자를 삭제하여 복사를 방지
    dataManager(const dataManager&) = delete;
    void operator=(const dataManager&) = delete;

    // 생성자를 private으로 설정하여 외부에서의 생성을 방지
    dataManager();


    std::queue<cv::Mat> dataQueue_1; // 공유 데이터 큐
    std::mutex mtx_1; // 동기화를 위한 뮤텍스

    std::queue<cv::Mat> dataQueue_2; // 공유 데이터 큐
    std::mutex mtx_2; // 동기화를 위한 뮤텍스
};

