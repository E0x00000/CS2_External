#include "OS-ImGui_Base.h"
#include "../OS-ImGui/imgui/font.h"

/****************************************************
* Copyright (C)	: Liv
* @file			: OS-ImGui_Base.cpp
* @author		: Liv
* @email		: 1319923129@qq.com
* @version		: 1.0
* @date			: 2023/6/18	11:21
****************************************************/

namespace OSImGui
{
    bool OSImGui_Base::InitImGui(ID3D11Device* device, ID3D11DeviceContext* device_context)
    {
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;

        io.Fonts->AddFontFromMemoryTTF(&inter, sizeof inter, 16 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        tab_text1 = io.Fonts->AddFontFromMemoryTTF(&inter, sizeof inter, 12 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        tab_text2 = io.Fonts->AddFontFromMemoryTTF(&inter, sizeof inter, 24 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        tab_text3 = io.Fonts->AddFontFromMemoryTTF(&inter, sizeof inter, 40 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        ico = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 25 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        ico_2 = io.Fonts->AddFontFromMemoryTTF(&Menuicon, sizeof Menuicon, 20 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        ico_subtab = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 35 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        ico_logo = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 31 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        tab_text = io.Fonts->AddFontFromMemoryTTF(&inter, sizeof inter, 19 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());
        ico_minimize = io.Fonts->AddFontFromMemoryTTF(&icon, sizeof icon, 27 * dpi_scale, NULL, io.Fonts->GetGlyphRangesCyrillic());


        ImGui::StyleColorsDark();
        io.LogFilename = nullptr;

        if (!ImGui_ImplWin32_Init(Window.hWnd))
            throw OSException("ImGui_ImplWin32_Init() call failed.");
        if (!ImGui_ImplDX11_Init(device, device_context))
            throw OSException("ImGui_ImplDX11_Init() call failed.");

        return true;
    }

    void OSImGui_Base::CleanImGui()
    {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        g_Device.CleanupDeviceD3D();
        DestroyWindow(Window.hWnd);
        UnregisterClassA(Window.ClassName.c_str(), Window.hInstance);
    }

    std::wstring OSImGui_Base::StringToWstring(std::string& str)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(str);
    }

}