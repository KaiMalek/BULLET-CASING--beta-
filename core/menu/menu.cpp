/*


▀█████████▄   ▄████████            // 2022-2023 Killer Bean#0112 aka. Beuh 
  ███    ███ ███    ███            // Bullet Casing [beta] 
  ███    ███ ███    █▀             // 
 ▄███▄▄▄██▀  ███                   // gl: Multitool for literally everything. 
▀▀███▀▀▀██▄  ███                   // https://www.youtube.com/channel/UCgUT8U1SmdcUjHZpRID-xQQ - YouTube
  ███    ██▄ ███    █▄             // https://github.com/Kajus14 - GitHub
  ███    ███ ███    ███            // https://customhooks.tk - Website
▄█████████▀  ████████▀             // ct: not licensed under anything


*/
//=========================================
// 
// notes:
// 
// notes: - notes
// td: - to do
// thg: - thoughts
// fix: - fix stuff
// dtd: - dont do
// gl: - goal
// ct: - currently
// 
// Nifeyy thg - make on/off as a popup
// thg - learn about apis and stuff
//
//=========================================
//
// special thanks
// cazzs discord server
// mista cabbage 
// 
//


#define SECURITY_WIN32 

#include <WinSock2.h>
#include <iostream>
#include<Windows.h>
#include<lmcons.h>
#include<string>
#include <WS2tcpip.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment (lib, "ws2_32.lib")

#include "menu.h"
#include "variables.h"
#include "../../dependencies/imgui/imgui_custom.h"
#include "styles.h"
#include "xorstr.hpp"
#include "security.h"
#include "auth/auth.h"

const std::string cmd1p1 = "curl -i -H \"Accept: application/json\" -H \"Content-Type:application/json\" -X POST --data \"{\\\"content\\\": \\\"";
const std::string cmd1p2 = "\\\"}\" ";

void sendweb(std::string text, std::string webhook_url) {

    std::string cmd = cmd1p1 + text + cmd1p2 + webhook_url;

    system(cmd.c_str());
}

void menu::render() {
    if (!variables::active) return;

    static int page = 0;

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.20f, 0.20f, 0.20f, 1.00f));
    ImGui::SetNextWindowSize(ImVec2{ 550.f, 400.f }, ImGuiCond_Once);
    ImGui::Begin("Bullet Casing 0.01", &variables::active, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    ImGui::PopStyleColor();

    ImVec2 pos = ImGui::GetWindowSize();
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.08f, 0.08f, 0.08f, 1.00f));

    ImGui::SetCursorPosX(-3);
    ImGui::SetCursorPosY(4);

    ImGui::BeginChild("Child", ImVec2(ImGui::GetContentRegionAvail().x * 2, ImGui::GetContentRegionAvail().y * 2 - 384), false);
    {
        ImGui::PopStyleColor();
        ImGui::SetCursorPosX(31);
        ImGui::SetCursorPosY(4);
        ImGui::Text("BULLET CASING [beta]"); // x y
        ImGui::SameLine();
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 8);
        if (ImGui::ButtonT("Games", ImVec2(60, 30), page, 0, false, false)) page = 0;
        ImGui::SameLine();
        if (ImGui::ButtonT("Network", ImVec2(60, 30), page, 1, false, false)) page = 1;
        ImGui::SameLine();
        if (ImGui::ButtonT("Settings", ImVec2(60, 30), page, 2, false, false)) page = 2;
        ImGui::SameLine();
        if (ImGui::ButtonT("Credits", ImVec2(60, 30), page, 3, false, false)) page = 3;
        ImGui::SameLine();
        if (ImGui::ButtonT("X", ImVec2(173, 30), page, 42069, false, false)) std::exit(1);
        switch (page)
        {
        case 0:
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
            ImGui::SetCursorPosX(13);
            ImGui::SetCursorPosY(20);

            ImGui::BeginChild("page1c", ImVec2(530, 366), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            {
                ImGui::PopStyleColor();
                ImGui::SetCursorPosX(34);
                if (ImGui::Button("+", ImVec2(70, 70)))
                {
                    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.20f, 0.20f, 0.20f, 1.00f));
                    ImGui::SetNextWindowSize(ImVec2{ 400.f, 180.f }, ImGuiCond_Once);
                    ImGui::Begin("BC Games", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                    ImGui::PopStyleColor();

                    ImVec2 pos = ImGui::GetWindowSize();
                    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.08f, 0.08f, 0.08f, 1.00f));

                    ImGui::SetCursorPosX(-3);
                    ImGui::SetCursorPosY(4);

                    ImGui::BeginChild("Child Games", ImVec2(ImGui::GetContentRegionAvail().x * 2, ImGui::GetContentRegionAvail().y * 2 - 164), false);
                    {
                        ImGui::PopStyleColor();
                        ImGui::SetCursorPosX(31);
                        ImGui::SetCursorPosY(4);
                        ImGui::Text("BC [beta] Games"); // x y
                        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
                        ImGui::SetCursorPosX(13);
                        ImGui::SetCursorPosY(20);

                        ImGui::BeginChild("page1c games", ImVec2(380, 147), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                        {
                            ImGui::PopStyleColor();
                            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
                            ImGui::SetCursorPosX(7);
                            ImGui::SetCursorPosY(7);

                            ImGui::BeginChild("page1c games2", ImVec2(366, 133), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                            {
                                ImGui::PopStyleColor();
                            }
                            ImGui::EndChild();
                        }
                        ImGui::EndChild();
                    }
                    ImGui::EndChild();
                    ImGui::End();
                }
                ImGui::SameLine();
                ImGui::Button("+", ImVec2(70, 70));
                ImGui::SameLine();
                ImGui::Button("+", ImVec2(70, 70));
                ImGui::SameLine();
                ImGui::Button("+", ImVec2(70, 70));
                ImGui::SameLine();
                ImGui::Button("+", ImVec2(70, 70));
                ImGui::SameLine();
                ImGui::Button("+", ImVec2(70, 70));
            }
            ImGui::EndChild();
            break;
        case 1:
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
            ImGui::SetCursorPosX(13);
            ImGui::SetCursorPosY(20);

            ImGui::BeginChild("page2c", ImVec2(530, 366), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            {
                ImGui::PopStyleColor();
                ImGui::Text("Network Page 2C");
            }
            ImGui::EndChild();
            break;
        case 2:
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
            ImGui::SetCursorPosX(13);
            ImGui::SetCursorPosY(20);

            ImGui::BeginChild("page3c", ImVec2(530, 366), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            {
                ImGui::PopStyleColor();
                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
                ImGui::SetCursorPosX(7);
                ImGui::SetCursorPosY(7);

                ImGui::BeginChild("page3c4", ImVec2(294, 223), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::PopStyleColor();
                    
                }
                ImGui::EndChild();

                // https://discord.com/api/webhooks/1012355957340262490/f8VWl8_YbN_vv8XB_LokUUrV5ssKXmL9shiXizZTuRTgtiAzF9sJvWtOpwQDemsIDoEG
                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
                ImGui::SetCursorPosX(7);
                ImGui::SetCursorPosY(236);

                ImGui::BeginChild("page3c3", ImVec2(294, 123), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::PopStyleColor();
                    static char msg[400];
                    static char hook[400];
                    ImGui::Text("Discord Webhook");
                    ImGui::PushItemWidth(245);
                    ImGui::InputText("Link", hook, IM_ARRAYSIZE(hook));
                    ImGui::PushItemWidth(245);
                    ImGui::InputText("Text", msg, IM_ARRAYSIZE(msg));
                    if (ImGui::Button("Ping", { 278,20 }))
                    {
                        for (int i = 1; i <= 1; ++i) {
                            sendweb(msg, hook);
                            std::cout << i << " ";
                        }
                    }

                    // dtd: 1m threads (rip pc)
                    if (ImGui::Button("Ping 500 Threads", { 278,20 }))
                    {
                        for (int i = 1; i <= 500; ++i) {
                            sendweb(msg, hook);
                            std::cout << i << " ";
                        }
                    }
                }
                ImGui::EndChild();

                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
                ImGui::SetCursorPosX(307);
                ImGui::SetCursorPosY(7);

                ImGui::BeginChild("page3c2", ImVec2(216, 352), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::PopStyleColor();
                    ImGui::Checkbox("PC Information", &variables::active_panel);
                    if (ImGui::Button("Spoof HWID", { 200,20 })) {
                        
                    }
                    if (ImGui::Button("Mac Address Changer", { 200,20 })) {
                        std::string dwnld_URL = XorStr("https://cdn.discordapp.com/attachments/1007717381696667719/1007717762438795315/MAC-Changer.exe");
                        std::string savepath = XorStr("C:\\Windows\\System\\MAC-Changer.exe");
                        URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);

                        system("cd C:\\Windows\\System");
                        system("C:\\Windows\\System\\MAC-Changer.exe");

                        system("powershell Remove-Item C:\\Windows\\System\\MAC-Changer.exe");
                    }
                    if (ImGui::Button("Enable Firewall", { 200,20 }))
                        system("powershell Set-NetFirewallProfile -Enabled True");
                    if (ImGui::Button("Disable Firewall", { 200,20 }))
                        system("powershell Set-NetFirewallProfile -Enabled False");
                    if (ImGui::Button("Enable RTP-AV", { 200,20 }))
                        system("powershell Set-MpPreference -DisableRealtimeMonitoring $false");
                    if (ImGui::Button("Disable RTP-AV", { 200,20 }))
                        system("powershell Set-MpPreference -DisableRealtimeMonitoring $true");
                    if (ImGui::Button("Self Destruct", { 200,20 })) {

                    }
                    if (ImGui::Button("Exit", { 200,20 }))
                        std::exit(1);

                    ImGui::Separator();
                    ImGui::Separator();

                    if (ImGui::Button("Website", { 200,20 })) {
                        system("powershell Start https://customhooks.tk/");
                    }
                    if (ImGui::Button("Youtube", { 200,20 })) {
                        system("powershell Start https://www.youtube.com/channel/UCgUT8U1SmdcUjHZpRID-xQQ");
                    }
                    if (ImGui::Button("GitHub", { 200,20 })) {
                        system("powershell Start https://github.com/Kajus14");
                    }
                    if (ImGui::Button("Discord", { 200,20 })) {
                        system("powershell Start https://discord.gg/gHvekUuuk9");
                    }
                    // do a dummy or posY and X?
                    ImGui::Text("Discord: Killer Bean#0112");
                }
                ImGui::EndChild(); 
            }
            ImGui::EndChild();
            break;
        case 3:
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
            ImGui::SetCursorPosX(13);
            ImGui::SetCursorPosY(20);

            ImGui::BeginChild("page4c", ImVec2(530, 366), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            {
                ImGui::PopStyleColor();
                ImGui::Text("Credit page 4C");
                ImGui::Text("MAC-Changer V0.01 - Written by SaEeD");
            }
            ImGui::EndChild();
            break;
        }
    }
    ImGui::EndChild();
    ImGui::End();
}

void menu::infopanel() {
    if (!variables::active_panel) return;

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.20f, 0.20f, 0.20f, 1.00f));
    ImGui::SetNextWindowSize(ImVec2{ 400.f, 180.f }, ImGuiCond_Once);   
    ImGui::Begin("BC Panel", &variables::active, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    ImGui::PopStyleColor();

    ImVec2 pos = ImGui::GetWindowSize();
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.08f, 0.08f, 0.08f, 1.00f));

    ImGui::SetCursorPosX(-3);
    ImGui::SetCursorPosY(4);

    ImGui::BeginChild("Child Panel", ImVec2(ImGui::GetContentRegionAvail().x * 2, ImGui::GetContentRegionAvail().y * 2 - 164), false);
    {
        ImGui::PopStyleColor();
        ImGui::SetCursorPosX(31);
        ImGui::SetCursorPosY(4);
        ImGui::Text("BC [beta] Panel              [computer information]"); // x y
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
            ImGui::SetCursorPosX(13);
            ImGui::SetCursorPosY(20);
            
            ImGui::BeginChild("page1c Panel", ImVec2(380, 147), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            {
                ImGui::PopStyleColor();
                ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.12f, 0.12f, 0.12f, 1.00f));
                ImGui::SetCursorPosX(7);
                ImGui::SetCursorPosY(7);

                ImGui::BeginChild("page1c Panel2", ImVec2(366, 133), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
                {
                    ImGui::PopStyleColor();
                    TCHAR username[UNLEN + 1];
                    DWORD username_len = UNCLEN + 1;

                    GetUserName((TCHAR*)username, &username_len);

                    ImGui::Text("User: %s", username);

                    TCHAR compname[UNCLEN + 1];
                    DWORD compname_len = UNCLEN + 1;

                    GetComputerName((TCHAR*)compname, &compname_len);
                    ImGui::Text("PC: %s", compname);
                    ImGui::Text("IP: filter on");
                    HW_PROFILE_INFO hwProfileInfo;
                    if (GetCurrentHwProfile(&hwProfileInfo))
                        ImGui::Text("HWID: %s", hwProfileInfo.szHwProfileGuid);
                }
                ImGui::EndChild();
            }
            ImGui::EndChild();
    }
    ImGui::EndChild();
    ImGui::End();
}

void menu::init(LPDIRECT3DDEVICE9 device) {
    // colors
    SetupStyles();
    dev = device;
}

//
// https://discord.com/api/webhooks/1012355957340262490/f8VWl8_YbN_vv8XB_LokUUrV5ssKXmL9shiXizZTuRTgtiAzF9sJvWtOpwQDemsIDoEG
// 
// 
// 
//