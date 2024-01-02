


#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include "imradAutoGen.h"

imradAutoGen::imradAutoGen() {

}
imradAutoGen::~imradAutoGen() {

}

void imradAutoGen::drawUI() {

    /// @begin TopWindow
    glfwSetWindowTitle(window, "title");
    ImGui::SetNextWindowPos({ 0, 0 });
    int tmpWidth, tmpHeight;
    glfwGetWindowSize(window, &tmpWidth, &tmpHeight);
    ImGui::SetNextWindowSize({ (float)tmpWidth, (float)tmpHeight });
    bool tmpOpen;
    if (ImGui::Begin("###AlertCamera", &tmpOpen, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings))
    {
        if (ImGui::IsWindowAppearing())
        {
            glfwSetWindowSize(window, 1920, 1080);
            glfwSetWindowAttrib(window, GLFW_RESIZABLE, true);
            glfwSetWindowAttrib(window, GLFW_DECORATED, true);
        }
        /// @separator

        // TODO: Add Draw calls of dependant popup windows here

        /// @begin Button
        ImRad::NextColumn(1);
        ImRad::Spacing(2);
        ImGui::BeginGroup();
        ImGui::Button("\xef\x80\x82 Search", { 400, 200 });
        /// @end Button

        /// @begin Button
        ImRad::NextColumn(1);
        ImGui::Button("\xef\x80\x82 Search", { 400, 200 });
        ImGui::EndGroup();
        /// @end Button

        /// @begin Image
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        if (!value7)
            value7 = ImRad::LoadTextureFromFile("");
        ImGui::Image(value7.id, { 400, 400 });
        /// @end Image

        /// @begin Button
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::Button("\xef\x80\x82 Search", { 400, 400 });
        /// @end Button

        /// @begin Button
        ImRad::Spacing(1);
        ImGui::Button("\xef\x80\x82 Search", { 400, 400 });
        /// @end Button

        /// @begin CustomWidget
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        /// @end CustomWidget

        /// @begin ColorEdit
        ImGui::SameLine(0, 1 * ImGui::GetStyle().ItemSpacing.x);
        ImGui::SetNextItemWidth(400);
        ImGui::ColorEdit3("##value8", (float*)&value8, ImGuiColorEditFlags_None);
        /// @end ColorEdit

        /// @separator
        ImGui::End();
    }
    /// @end TopWindow

}

// Export finished with errors
// Image: file_name doesn't exist
// UserWidget: OnDraw not set!
