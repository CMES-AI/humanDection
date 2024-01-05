// Generated with ImRAD 0.6
// visit https://github.com/tpecholt/imrad

#pragma once

#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include <string>
#include <vector>
#include <mutex>
#include <queue>

#include <opencv2/opencv.hpp>

#include "imgui.h"
#include "imgui_internal.h"
class AlertCamera
{
public:
    /// @begin interface
    static void DrawSetCamera();
    static void leftMenu();
    static void bottomInfo();

    bool value1 = false;
    
    
    static void ShowPolygon(ImVec2 imagePos, ImVec2 imageSize);
private:
    /// @begin impl
    static void PreviewCamera(std::queue<cv::Mat>* dataQueue_, std::mutex* mtx_);
    static bool TextButton(std::string label, bool &hoverdButton);
    static void SettingView();
    static void DrawPolygon(ImGuiWindow* window, const std::vector<ImVec2>& points, ImU32 col);
    
    /// @end impl
};


extern AlertCamera alertCamera;
