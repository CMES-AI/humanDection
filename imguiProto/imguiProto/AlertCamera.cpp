// Generated with ImRAD 0.6
// visit https://github.com/tpecholt/imrad

#include "AlertCamera.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


AlertCamera alertCamera;


const int monitoringMode = 0;
const int settingMode = 1;
const int stopMode = 2;

static bool check_0 = false; // 체크박스의 초기 상태를 설정합니다.
static bool check_1 = true; // 체크박스의 초기 상태를 설정합니다.
static bool check_2 = false; // 체크박스의 초기 상태를 설정합니다.
static bool MonitorHoveredButton = false; // 체크박스의 초기 상태를 설정합니다.
static bool SettingHoveredButton = false; // 체크박스의 초기 상태를 설정합니다.
static bool StopHoveredButton = false; // 체크박스의 초기 상태를 설정합니다.
static bool HoveredButton = false; // 체크박스의 초기 상태를 설정합니다.
static int modeSetting = monitoringMode;
static std::vector<ImVec2> pointsLeft;
static std::vector<ImVec2> pointsRight;

GLuint LoadTexture(const char* filepath)
{
    int width, height, channels;
    unsigned char* image = stbi_load(filepath, &width, &height, &channels, 0);
    if (!image) {
        //std::cerr << "Failed to load image: " << filepath << std::endl;
        return 0;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    stbi_image_free(image);
    return texture;
}



void AlertCamera::DrawSetCamera()
{
    /// @style Classic
    /// @unit px
    /// @begin TopWindow
    
    bool tmpOpen;
    ImGui::SetNextWindowSize(ImVec2(1600, 1024));
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    if (ImGui::Begin("###AlertCamera", &tmpOpen, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings))
    {
        ImGui::BeginGroup();

            ImGui::BeginGroup();
            if (AlertCamera::TextButton("Monitoring", MonitorHoveredButton)) {
                modeSetting = monitoringMode;
            }


            if (AlertCamera::TextButton("Stop", StopHoveredButton)) {
                modeSetting = settingMode;
            }

            if (AlertCamera::TextButton("Setting", SettingHoveredButton)) {
                modeSetting = settingMode;
            }
            ImGui::EndGroup();

            ImGui::Dummy(ImVec2(200, 700));
    
        
            int m_selectedItem = -1;
            std::vector<std::string> m_items = { "Item 1", "Item 2", "Item 3", "Item 4" };

        
            // 리스트의 시작 위치를 저장
            ImVec2 list_start_pos = ImGui::GetCursorScreenPos();
            
            for (int i = 0; i < m_items.size(); i++) {
                std::string itemid = "##" + std::to_string(i);
                ImGui::Selectable("2024_01_Item:", &m_selectedItem, ImGuiSelectableFlags_None, ImVec2(250, 35));
                
            }

            // 리스트의 끝 위치를 저장
            ImVec2 list_end_pos = ImGui::GetCursorScreenPos();

            // 윈도우의 ImDrawList를 가져옴
            ImDrawList* draw_list = ImGui::GetWindowDrawList();

            // 리스트 영역에 배경을 그림
            draw_list->AddRectFilled(list_start_pos, list_end_pos, IM_COL32(255, 0, 0, 150));

        ImGui::EndGroup();
        if (modeSetting == monitoringMode) {

            ImGui::SameLine();

            ImGui::BeginGroup();
            ImGui::Dummy(ImVec2(600, 30));


            AlertCamera::PreviewCamera();
            ImGui::SameLine();
            ImGui::Separator();
            ImGui::SameLine();
            AlertCamera::PreviewCamera();

            ImGui::Dummy(ImVec2(200, 300));
            if (ImGui::BeginTabBar("MyTabBar")) {
                if (ImGui::BeginTabItem("Status")) {
                    ImGui::Text("202316_13_06 was selected");
                    ImGui::EndTabItem();
                }
                ImGui::SameLine(); // Keep following content on the same line
                ImGui::Dummy(ImVec2(50.0f, 0.0f)); // Add some horizontal spacing
                ImGui::SameLine(); // Keep following content on the same line
                
                ImGui::EndTabBar();
            }
            ImGui::EndGroup();

        }
        else if (modeSetting == settingMode) {

        }
       
    }

    ImGui::End();
}
void AlertCamera::SettingView() {

}

void AlertCamera::leftMenu() {

}

void AlertCamera::bottomInfo() {

}

void AlertCamera::PreviewCamera()
{

    // 텍스처 로드 (텍스처 핸들러는 플랫폼 및 렌더러에 따라 다름)
    GLuint  texture = LoadTexture("..\\..\\misc\\images\\kcch.png");
    ImTextureID textureID = (ImTextureID)(intptr_t)texture;
    // 이미지 뷰어

    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return;
   
        // 이미지의 크기와 위치를 계산 (예: 윈도우의 중앙에 이미지를 표시)
        ImVec2 imagePos = ImGui::GetCursorScreenPos(); // 이미지 위치 저장
        ImVec2 windowSize = ImGui::GetWindowSize();
        ImVec2 imageSize = ImVec2(640, 480);
      //  ImVec2 imagePos = ImVec2((windowSize.x - imageSize.x) * 0.5f, (windowSize.y - imageSize.y) * 0.5f);

        

        // 테두리를 그립니다.
        window->DrawList->AddRect(imagePos, ImVec2(imagePos.x + imageSize.x, imagePos.y + imageSize.y), IM_COL32(150, 150, 150, 255), 0.0f, 0xf, 20.0f); // 테두리 두께를 20.0f로 설정
        // 이미지 렌더링
        //ImGui::SetCursorPos(imagePos);
        ImGui::Image(textureID, imageSize);
        ShowPolygon(imagePos, imageSize);
  
}

bool AlertCamera::TextButton(std::string label, bool &hoverdButton) {
   ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
   ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 투명한 색으로 설정
   ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.0f)); // 투명한 색으로 설정

    if (hoverdButton == true) {
        // 스타일 색상 변경
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 1.0f, 1.0f)); // 빨간색으로 설정
    }
    else {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f)); // 빨간색으로 설정
    }
    bool bSelect = false;
    bSelect = ImGui::Button(label.c_str(), {130, 40});
    if (ImGui::IsItemHovered()) {
        // 마우스가 버튼 위에 있을 때 수행할 작업
        hoverdButton = true;
    }
    else {
        hoverdButton = false;
    }
    ImGui::PopStyleColor(4);
    return bSelect;
}


void AlertCamera::DrawPolygon(ImGuiWindow* window, const std::vector<ImVec2>& points, ImU32 col)
{
    if (points.size() > 2)
        window->DrawList->AddPolyline(&points[0], points.size(), col, true, 1.0f);
}

void AlertCamera::ShowPolygon(ImVec2 imagePos, ImVec2 imageSize)
{

    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return;

    if (ImGui::IsMouseClicked(0))
    {
        ImVec2 pos = ImGui::GetMousePos();
        if (pos.x >= imagePos.x && pos.x <= imagePos.x + imageSize.x && pos.y >= imagePos.y && pos.y <= imagePos.y + imageSize.y)
        {
            if (pos.x > imageSize.x + 300) {
                pointsRight.push_back(pos);
            }
            else {
                pointsLeft.push_back(pos);
            }
            // 마우스 위치가 이미지 영역 내에 있을 때만 점을 추가합니다.       
        }
    }

   
    if (ImGui::IsMouseClicked(1) && pointsLeft.size() > 2)
    {
        ImVec2 pos = ImGui::GetMousePos();
        if (pos.x < imageSize.x + 300) {
            pointsLeft.push_back(pointsLeft[0]); // close the polygon
            DrawPolygon(window, pointsLeft, IM_COL32(255, 0, 0, 255));
            pointsLeft.clear();
        }
    }

    if (ImGui::IsMouseClicked(1) && pointsRight.size() > 2)
    {
        ImVec2 pos = ImGui::GetMousePos();
        if (pos.x > 920) {
            pointsRight.push_back(pointsRight[0]); // close the polygon
            DrawPolygon(window, pointsRight, IM_COL32(255, 0, 0, 255));
            pointsRight.clear();
        }
    }
    
    DrawPolygon(window, pointsLeft, IM_COL32(255, 0, 0, 255));
    DrawPolygon(window, pointsRight, IM_COL32(255, 0, 0, 255));

    
}
