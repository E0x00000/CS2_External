#include "Cheats.h"
#include "Render.hpp"
#include "MenuConfig.hpp"
#include "Utils/ConfigMenu.hpp"
#include "Utils/ConfigSaver.hpp"

void Particles()
{
	ImVec2 screen_size = { (float)GetSystemMetrics(SM_CXSCREEN), (float)GetSystemMetrics(SM_CYSCREEN) };

	static ImVec2 partile_pos[100];
	static ImVec2 partile_target_pos[100];
	static float partile_speed[100];
	static float partile_radius[100];

	for (int i = 1; i < 50; i++)
	{
		if (partile_pos[i].x == 0 || partile_pos[i].y == 0)
		{
			partile_pos[i].x = rand() % (int)screen_size.x + 1;
			partile_pos[i].y = 15.f;
			partile_speed[i] = 1 + rand() % 25;
			partile_radius[i] = rand() % 4;

			partile_target_pos[i].x = rand() % (int)screen_size.x;
			partile_target_pos[i].y = screen_size.y * 2;
		}

		partile_pos[i] = ImLerp(partile_pos[i], partile_target_pos[i], ImGui::GetIO().DeltaTime * (partile_speed[i] / 60));

		if (partile_pos[i].y > screen_size.y)
		{
			partile_pos[i].x = 0;
			partile_pos[i].y = 0;
		}

		ImGui::GetWindowDrawList()->AddCircleFilled(partile_pos[i], partile_radius[i], ImColor(255, 255, 255, 255));
	}

}

void Cheats::Menu()
{
	static bool IsMenuInit = false;
	if (!IsMenuInit)
	{
		auto& style = GImGui->Style;

		style.WindowRounding = 0;
		style.WindowPadding = ImVec2{ 0, 0 };
		style.WindowBorderSize = 0;
		style.FrameRounding = 3;
		style.FramePadding = ImVec2{ 16, 14 };
		style.FrameBorderSize = 0;
		style.PopupRounding = 3;
		style.PopupBorderSize = 0;
		style.ChildRounding = 4;
		style.ChildBorderSize = 0;
		style.ItemSpacing = ImVec2{ 20, 20 };
		style.ItemInnerSpacing = ImVec2{ 10, 10 };
		style.ScrollbarRounding = 4;
		style.ScrollbarSize = 4;
	}

	ImGui::Begin("Menu",nullptr,ImGuiWindowFlags_AlwaysAutoResize);
	{
		ImGui::BeginTabBar("Cheat");
		// esp menu
		if (ImGui::BeginTabItem("ESP"))
		{
			Gui.MyCheckBox("BoxESP", &MenuConfig::ShowBoxESP);
			ImGui::SameLine();
			ImGui::ColorEdit4("##BoxColor", reinterpret_cast<float*>(&MenuConfig::BoxColor), ImGuiColorEditFlags_NoInputs);

			ImGui::Combo("BoxType", &MenuConfig::BoxType, "Normal\0Dynamic");

			Gui.MyCheckBox("BoneESP", &MenuConfig::ShowBoneESP);
			ImGui::SameLine();
			ImGui::ColorEdit4("##BoneColor", reinterpret_cast<float*>(&MenuConfig::BoneColor), ImGuiColorEditFlags_NoInputs);

			Gui.MyCheckBox("EyeRay", &MenuConfig::ShowEyeRay);
			ImGui::SameLine();
			ImGui::ColorEdit4("##EyeRay", reinterpret_cast<float*>(&MenuConfig::EyeRayColor), ImGuiColorEditFlags_NoInputs);

			Gui.MyCheckBox("HealthBar", &MenuConfig::ShowHealthBar);
			ImGui::Combo("HealthBarType", &MenuConfig::HealthBarType, "Vetical\0Horizontal");

			Gui.MyCheckBox("WeaponText", &MenuConfig::ShowWeaponESP);
			Gui.MyCheckBox("Distance", &MenuConfig::ShowDistance);
			Gui.MyCheckBox("PlayerName", &MenuConfig::ShowPlayerName);

			Gui.MyCheckBox("HeadShootLine", &MenuConfig::ShowHeadShootLine);
			ImGui::SameLine();
			ImGui::ColorEdit4("##HeadShootLineColor", reinterpret_cast<float*>(&MenuConfig::HeadShootLineColor), ImGuiColorEditFlags_NoInputs);

			Gui.MyCheckBox("FovLine", &MenuConfig::ShowFovLine);
			ImGui::SameLine();
			ImGui::ColorEdit4("##FovLineColor", reinterpret_cast<float*>(&MenuConfig::FovLineColor), ImGuiColorEditFlags_NoInputs);
			float FovLineSizeMin = 20.f, FovLineSizeMax = 120.f;
			Gui.SliderScalarEx1("FovLineSize", ImGuiDataType_Float, &MenuConfig::FovLineSize, &FovLineSizeMin, &FovLineSizeMax, "%.1f", ImGuiSliderFlags_None);
		
			Gui.MyCheckBox("LineToEnemy", &MenuConfig::ShowLineToEnemy);
			ImGui::SameLine();
			ImGui::ColorEdit4("##LineToEnemyColor", reinterpret_cast<float*>(&MenuConfig::LineToEnemyColor), ImGuiColorEditFlags_NoInputs);

			Gui.MyCheckBox("CrossHair", &MenuConfig::ShowCrossHair);
			ImGui::SameLine();
			ImGui::ColorEdit4("##CrossHairColor", reinterpret_cast<float*>(&MenuConfig::CrossHairColor), ImGuiColorEditFlags_NoInputs);
			float CrossHairSizeMin = 15, CrossHairSizeMax = 200;
			Gui.SliderScalarEx1("CrossHairSize", ImGuiDataType_Float, &MenuConfig::CrossHairSize, &CrossHairSizeMin, &CrossHairSizeMax, "%.1f", ImGuiSliderFlags_None);
		
			ImGui::EndTabItem();
		}

		// aimbot menu
		if (ImGui::BeginTabItem("AimBot "))
		{
			Gui.MyCheckBox("AimBot", &MenuConfig::AimBot);

			if (ImGui::Combo("AimKey", &MenuConfig::AimBotHotKey, "LBUTTON\0MENU\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL"))// added LBUTTON
			{
				AimControl::SetHotKey(MenuConfig::AimBotHotKey);
			}

			float FovMin = 0.1f, FovMax = 89.f;
			float SmoothMin = 0.f, SmoothMax = 0.9f;
			Gui.SliderScalarEx1("AimFov", ImGuiDataType_Float, &AimControl::AimFov, &FovMin, &FovMax, "%.1f", ImGuiSliderFlags_None);
			Gui.MyCheckBox("FovCircle", &MenuConfig::ShowAimFovRange);
			ImGui::SameLine();
			ImGui::ColorEdit4("##FovCircleColor", reinterpret_cast<float*>(&MenuConfig::AimFovRangeColor), ImGuiColorEditFlags_NoInputs);

			Gui.SliderScalarEx1("Smooth", ImGuiDataType_Float, &AimControl::Smooth, &SmoothMin, &SmoothMax, "%.1f", ImGuiSliderFlags_None);
			if (ImGui::Combo("AimPos", &MenuConfig::AimPosition, "Head\0Neck\0Spine"))
			{
				switch (MenuConfig::AimPosition)
				{
				case 0:
					MenuConfig::AimPositionIndex = BONEINDEX::head;
					break;
				case 1:
					MenuConfig::AimPositionIndex = BONEINDEX::neck_0;
					break;
				case 2:
					MenuConfig::AimPositionIndex = BONEINDEX::spine_1;
					break;
				default:
					break;
				}
			}
			int BulletMin = 1, BulletMax = 6;
			float RecoilMin = 0.f, RecoilMax = 2.f;
			Gui.SliderScalarEx1("Start Bullet", ImGuiDataType_U32, &AimControl::RCSBullet, &BulletMin, &BulletMax, "%d", ImGuiSliderFlags_None);
			Gui.SliderScalarEx1("RCS Yaw", ImGuiDataType_Float, &AimControl::RCSScale.x, &RecoilMin, &RecoilMax, "%.1f", ImGuiSliderFlags_None);
			Gui.SliderScalarEx1("RCS Pitch", ImGuiDataType_Float, &AimControl::RCSScale.y, &RecoilMin, &RecoilMax, "%.1f", ImGuiSliderFlags_None);
			Gui.MyCheckBox("VisibleCheck", &MenuConfig::VisibleCheck);
		
			ImGui::EndTabItem();
		}

		// Radar menu
		if (ImGui::BeginTabItem("Radar "))
		{
			Gui.MyCheckBox("Radar", &MenuConfig::ShowRadar);
			ImGui::Combo("RadarType", &MenuConfig::RadarType, "Circle\0Arrow\0CircleWithArrow");

			Gui.MyCheckBox("CrossLine", &MenuConfig::ShowRadarCrossLine);
			ImGui::SameLine();
			ImGui::ColorEdit4("##CrossLineColor", reinterpret_cast<float*>(&MenuConfig::RadarCrossLineColor), ImGuiColorEditFlags_NoInputs);

			float ProportionMin = 500.f, ProportionMax = 3300.f;
			float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
			float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
			Gui.SliderScalarEx1("PointSize", ImGuiDataType_Float, &MenuConfig::RadarPointSizeProportion, &RadarPointSizeProportionMin, &RadarPointSizeProportionMax, "%.1f", ImGuiSliderFlags_None);
			Gui.SliderScalarEx1("Proportion", ImGuiDataType_Float, &MenuConfig::Proportion, &ProportionMin, &ProportionMax, "%.1f", ImGuiSliderFlags_None);
			Gui.SliderScalarEx1("RadarRange", ImGuiDataType_Float, &MenuConfig::RadarRange, &RadarRangeMin, &RadarRangeMax, "%.1f", ImGuiSliderFlags_None);
		
			ImGui::EndTabItem();
		}

		// TriggerBot
		if (ImGui::BeginTabItem("TriggerBot "))
		{
			Gui.MyCheckBox("TriggerBot", &MenuConfig::TriggerBot);

			if (ImGui::Combo("TriggerKey", &MenuConfig::TriggerHotKey, "MENU\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL"))
			{
				TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
			}
			if (ImGui::Combo("TriggerMode", &MenuConfig::TriggerMode, "Hold\0Toggle"))
			{
				TriggerBot::SetMode(MenuConfig::TriggerMode);
			}

			DWORD TriggerDelayMin = 15, TriggerDelayMax = 170;
			Gui.SliderScalarEx1("Delay", ImGuiDataType_U32, &TriggerBot::TriggerDelay, &TriggerDelayMin, &TriggerDelayMax, "%d", ImGuiSliderFlags_None);

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Misc "))
		{
			// moved to misc
			Gui.MyCheckBox("AntiFlashbang", &MenuConfig::AntiFlashbang);
			// TeamCheck
			Gui.MyCheckBox("TeamCheck", &MenuConfig::TeamCheck);

			ImGui::SameLine();
			// OBS Bypass
			Gui.MyCheckBox("OBSBypass", &MenuConfig::OBSBypass);

			//Bunnyhopping
			Gui.MyCheckBox("Bunnyhop ", &MenuConfig::BunnyHop);
			ImGui::SameLine();
			Gui.MyCheckBox("ShowWhenSpec", &MenuConfig::ShowWhenSpec);

			ImGui::EndTabItem();

		}

		// Render config saver
		ConfigMenu::RenderConfigMenu();
		
		ImGui::Separator();

		ImGui::Text("[HOME] HideMenu");

		ImGui::EndTabBar();
	}ImGui::End();
}

#include "OS-ImGui/OS-ImGui_Base.h"
#include "OS-ImGui/imgui/color.h"

int tabs = 0;
int sub_tabs = 0;
static float tab_alpha = 0.f;
static float tab_add;
static int active_tab = 0;
static bool animated_background = false;
void Cheats::New_Menu()
{

	ImGui::SetNextWindowSize(ImVec2(855 * dpi_scale, 790 * dpi_scale));
	ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
	{
		ImGuiStyle& s = ImGui::GetStyle();

		s.Colors[ImGuiCol_WindowBg] = ImColor(60, 65, 80, 60);
		s.Colors[ImGuiCol_ChildBg] = ImColor(20, 20, 20, 255);
		s.Colors[ImGuiCol_PopupBg] = ImColor(26, 26, 26, 255);
		s.Colors[ImGuiCol_Text] = ImColor(120, 120, 120, 255);
		s.Colors[ImGuiCol_TextDisabled] = ImColor(100, 100, 100, 255);
		s.Colors[ImGuiCol_Border] = ImColor(28, 28, 28, 255);
		s.Colors[ImGuiCol_TextSelectedBg] = ImColor(25, 22, 33, 100);

		s.Colors[ImGuiCol_ScrollbarGrab] = ImColor(24, 24, 24, 255);
		s.Colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(24, 24, 24, 255);
		s.Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(24, 24, 24, 255);

		s.WindowBorderSize = 0;
		s.WindowPadding = ImVec2(0, 0);
		s.WindowRounding = 5.f;
		s.PopupBorderSize = 0.f;
		s.PopupRounding = 5.f;
		s.ChildRounding = 7;
		s.ChildBorderSize = 1.f;
		s.FrameBorderSize = 1.0f;
		s.ScrollbarSize = 3.0f;
		s.FrameRounding = 5.f;
		s.ItemSpacing = ImVec2(0, 20);
		s.ItemInnerSpacing = ImVec2(10, 0);

		const auto& p = ImGui::GetWindowPos();


		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0, 0, 0, 0));
		ImGui::BeginChild("G-Tab", ImVec2(173 * dpi_scale, 790 * dpi_scale), false);
		{
			ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 20 * dpi_scale, ImVec2(20 * dpi_scale + p.x, 12 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Video Paste");
			ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(0 + p.x, 0 + p.y), ImVec2(273 * dpi_scale + p.x, 790 * dpi_scale + p.y), ImGui::GetColorU32(colors::Tab_Child), s.WindowRounding);

			ImGui::SetCursorPosY(60);

			ImGui::SetWindowFontScale(dpi_scale);
			if (ImGui::Tab("H", "Aimbot", "Legit,Trigger,Rage", 0 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 0;
			if (ImGui::Tab("G", "Changer", "Inventory & Profile", 1 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 1;
			if (ImGui::Tab("F", "Visuals", "Player,World,Glow", 2 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 2;
			if (ImGui::Tab("E", "Misc", "Other settings", 3 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 3;
			if (ImGui::Tab("D", "Binds", "Use keyboard to on", 4 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 4;
			if (ImGui::Tab("C", "Minigames", "Snake", 5 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 5;
			if (ImGui::Tab("B", "Config", "Manage your configs", 6 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 6;
			if (ImGui::Tab("A", "Chat", "Chat box", 7 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 7;
			if (ImGui::Tab("I", "Search", "Search for cheats", 8 == tabs, ImVec2(150 * dpi_scale, 42 * dpi_scale))) tabs = 8;

		}ImGui::EndChild();


		ImGui::PopStyleColor();

		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(0 + p.x, 0 + p.y), ImVec2(855 * dpi_scale + p.x, 790 * dpi_scale + p.y), ImGui::GetColorU32(colors::main_color), s.WindowRounding);

		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(0 + p.x, 755 * dpi_scale + p.y), ImVec2(855 * dpi_scale + p.x, 755 * dpi_scale + p.y), ImGui::GetColorU32(colors::lite_color), s.WindowRounding);

		//   ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(0 + p.x, 0 + p.y), ImVec2(705 + p.x, 60 + p.y), ImGui::GetColorU32(colors::lite_color), s.WindowRounding);


		ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 16 * dpi_scale, ImVec2(10 * dpi_scale + p.x, 765 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Uid:1337");
		ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 16 * dpi_scale, ImVec2(790 * dpi_scale + p.x, 765 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Release");
		tab_alpha = ImClamp(tab_alpha + (7.f * ImGui::GetIO().DeltaTime * (tabs == active_tab ? 1.f : -1.f)), 0.f, 1.f);
		tab_add = ImClamp(tab_add + (std::round(50.f) * ImGui::GetIO().DeltaTime * (tabs == active_tab ? 1.f : -1.f)), 0.f, 1.f);

		if (tab_alpha == 0.f && tab_add == 0.f) active_tab = tabs;


		ImGui::PushStyleVar(ImGuiStyleVar_Alpha, tab_alpha * s.Alpha);

		ImGui::SetCursorPos(ImVec2(203 * dpi_scale, 30 * dpi_scale));

		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0, 0, 0, 0));
		ImGui::BeginChild("General", ImVec2(717 * dpi_scale, 720 * dpi_scale), false);
		{
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::GetColorU32(colors::lite_color));
			switch (active_tab) {

			case 0:
			{

				ImGui::BeginChildPos("", ImVec2(620 * dpi_scale, 100 * dpi_scale));
				{
					ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 26 * dpi_scale, ImVec2(475 * dpi_scale + p.x, 55 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Aimbot");
					ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 16 * dpi_scale, ImVec2(405 * dpi_scale + p.x, 85 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Play like a pro and stay unroticed");
				}
				ImGui::EndChild();
				ImGui::SetCursorPosY(120 * dpi_scale);
				ImGui::BeginChildPos("AimBot", ImVec2(300 * dpi_scale, 580 * dpi_scale));
				{
					ImGui::SetWindowFontScale(dpi_scale);
					ImGui::Checkbox("AimBot", &MenuConfig::AimBot);

					ImGui::Keybind("Aim Bind", &MenuConfig::AimBotHotKey, true);

					float FovMin = 0.1f, FovMax = 89.f;
					float SmoothMin = 0.f, SmoothMax = 0.9f;
					ImGui::SliderFloat("Aim Fov", &AimControl::AimFov, FovMin, FovMax, "%.1f", ImGuiSliderFlags_None);
					
					

					ImGui::SliderFloat("Smooth", &AimControl::Smooth, SmoothMin, SmoothMax, "%.1f", ImGuiSliderFlags_None);
					
					int BulletMin = 0, BulletMax = 6;
					float RecoilMin = 0.f, RecoilMax = 2.f;
					ImGui::SliderInt("Start Bullet", &AimControl::RCSBullet, BulletMin, BulletMax, "%d", ImGuiSliderFlags_None);
					ImGui::SliderFloat("RCS Yaw",  &AimControl::RCSScale.x, RecoilMin, RecoilMax, "%.1f", ImGuiSliderFlags_None);
					ImGui::SliderFloat("RCS Pitch", &AimControl::RCSScale.y, RecoilMin, RecoilMax, "%.1f", ImGuiSliderFlags_None);
					



				}
				ImGui::EndChild();
				ImGui::SetCursorPos(ImVec2(320 * dpi_scale, 120 * dpi_scale));
				ImGui::BeginChildPos("Misc", ImVec2(300 * dpi_scale, 580 * dpi_scale));
				{
					
					ImGui::SetWindowFontScale(dpi_scale);
					ImGui::Checkbox("TriggerBot", &MenuConfig::TriggerBot);
					ImGui::Keybind("Trigger Key", &MenuConfig::TriggerHotKey, true);
					if (ImGui::Combo("TriggerMode", &MenuConfig::TriggerMode, "Hold\0Toggle"))
					{
					}
					ImGui::Keybind("Trigger Mode", &MenuConfig::TriggerMode, true);


					ImGui::Checkbox("Visible Check", &MenuConfig::VisibleCheck);
					ImGui::Checkbox("FovCircle", &MenuConfig::ShowAimFovRange);


					DWORD TriggerDelayMin = 15, TriggerDelayMax = 170;
					ImGui::SliderInt("Delay", &TriggerBot::TriggerDelay, TriggerDelayMin, TriggerDelayMax, "%d", ImGuiSliderFlags_None);

					if (ImGui::Combo("Hitbox", &MenuConfig::AimPosition, "Head\0Neck\0Spine"))
					{
						switch (MenuConfig::AimPosition)
						{
						case 0:
							MenuConfig::AimPositionIndex = BONEINDEX::head;
							break;
						case 1:
							MenuConfig::AimPositionIndex = BONEINDEX::neck_0;
							break;
						case 2:
							MenuConfig::AimPositionIndex = BONEINDEX::spine_1;
							break;
						default:
							break;
						}
					}
					
					ImGui::ColorEdit4("Fov Circle##FovCircleColor", reinterpret_cast<float*>(&MenuConfig::AimFovRangeColor), ImGuiColorEditFlags_NoInputs);
				}
				ImGui::EndChild();

			}
			break;
			case 2: {
				ImGui::BeginChildPos("", ImVec2(620 * dpi_scale, 100 * dpi_scale));
				{
					ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 26 * dpi_scale, ImVec2(475 * dpi_scale + p.x, 55 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Visuals");
					ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 16 * dpi_scale, ImVec2(425 * dpi_scale + p.x, 85 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Painting on Object Overlay");
				}
				ImGui::EndChild();
				ImGui::SetCursorPosY(120 * dpi_scale);
				ImGui::BeginChildPos("Esp", ImVec2(300 * dpi_scale, 580 * dpi_scale));
				{
					ImGui::SetWindowFontScale(dpi_scale);
					ImGui::Checkbox("BoxESP", &MenuConfig::ShowBoxESP);


					ImGui::Combo("BoxType", &MenuConfig::BoxType, "Normal\0Dynamic");

					ImGui::Checkbox("BoneESP", &MenuConfig::ShowBoneESP);


					ImGui::Checkbox("EyeRay", &MenuConfig::ShowEyeRay);


					ImGui::Checkbox("HealthBar", &MenuConfig::ShowHealthBar);
					ImGui::Combo("HealthBarType", &MenuConfig::HealthBarType, "Vetical\0Horizontal");

					ImGui::Checkbox("WeaponText", &MenuConfig::ShowWeaponESP);
					ImGui::Checkbox("Distance", &MenuConfig::ShowDistance);
					ImGui::Checkbox("PlayerName", &MenuConfig::ShowPlayerName);

					ImGui::Checkbox("HeadShootLine", &MenuConfig::ShowHeadShootLine);


					ImGui::Checkbox("FovLine", &MenuConfig::ShowFovLine);

					float FovLineSizeMin = 20.f, FovLineSizeMax = 120.f;
					ImGui::SliderFloat("FovLineSize", &MenuConfig::FovLineSize, FovLineSizeMin, FovLineSizeMax, "%.1f", ImGuiSliderFlags_None);

					ImGui::Checkbox("LineToEnemy", &MenuConfig::ShowLineToEnemy);


					ImGui::Checkbox("CrossHair", &MenuConfig::ShowCrossHair);

					float CrossHairSizeMin = 15, CrossHairSizeMax = 200;
					ImGui::SliderFloat("CrossHairSize", &MenuConfig::CrossHairSize, CrossHairSizeMin, CrossHairSizeMax, "%.1f", ImGuiSliderFlags_None);
				

				}
				ImGui::EndChild();
				ImGui::SetCursorPos(ImVec2(320 * dpi_scale, 120 * dpi_scale));
				ImGui::BeginChildPos("Misc", ImVec2(300 * dpi_scale, 580 * dpi_scale));
				{
					ImGui::SetWindowFontScale(dpi_scale);
					ImGui::ColorEdit4("Box Color##BoxColor", reinterpret_cast<float*>(&MenuConfig::BoxColor), ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4("Bone Color##BoneColor", reinterpret_cast<float*>(&MenuConfig::BoneColor), ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4("Eye Ray Color##EyeRay", reinterpret_cast<float*>(&MenuConfig::EyeRayColor), ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4("Headshot Line Color##HeadShootLineColor", reinterpret_cast<float*>(&MenuConfig::HeadShootLineColor), ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4("Fov Line Color##FovLineColor", reinterpret_cast<float*>(&MenuConfig::FovLineColor), ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4("Line to enemy Color##LineToEnemyColor", reinterpret_cast<float*>(&MenuConfig::LineToEnemyColor), ImGuiColorEditFlags_NoInputs);
					ImGui::ColorEdit4("Crosshair Color##CrossHairColor", reinterpret_cast<float*>(&MenuConfig::CrossHairColor), ImGuiColorEditFlags_NoInputs);
				}
				ImGui::EndChild();
			}
				  break;
			case 3: {
				ImGui::BeginChildPos("", ImVec2(620 * dpi_scale, 100 * dpi_scale));
				{
					ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 26 * dpi_scale, ImVec2(450 * dpi_scale + p.x, 55 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Miscellaneous");
					ImGui::GetForegroundDrawList()->AddText(OSImGui::tab_text3, 16 * dpi_scale, ImVec2(390 * dpi_scale + p.x, 85 * dpi_scale + p.y), ImColor(255, 255, 255, 255), "Modify menu games and other functions");
				}
				ImGui::EndChild();
				ImGui::SetCursorPosY(120 * dpi_scale);
				ImGui::BeginChildPos("Misc", ImVec2(620 * dpi_scale, 580 * dpi_scale));
				{ImGui::SetWindowFontScale(dpi_scale);
				ImGui::Checkbox("Render animated background", &animated_background);
				ImGui::SliderFloat("DPI", &dpi_scale, 1.0f, 1.2f, "%.3f", 0);
				ImGui::Checkbox("Radar", &MenuConfig::ShowRadar);
				ImGui::Combo("Radar Type", &MenuConfig::RadarType, "Circle\0Arrow\0CircleWithArrow");

				ImGui::Checkbox("CrossLine", &MenuConfig::ShowRadarCrossLine);
				ImGui::ColorEdit4("CrossLine Color##CrossLineColor", reinterpret_cast<float*>(&MenuConfig::RadarCrossLineColor), ImGuiColorEditFlags_NoInputs);

				float ProportionMin = 500.f, ProportionMax = 3300.f;
				float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
				float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
				ImGui::SliderFloat("PointSize" , &MenuConfig::RadarPointSizeProportion, RadarPointSizeProportionMin, RadarPointSizeProportionMax, "%.1f", ImGuiSliderFlags_None);
				ImGui::SliderFloat("Proportion" , &MenuConfig::Proportion, ProportionMin,ProportionMax, "%.1f", ImGuiSliderFlags_None);
				ImGui::SliderFloat("RadarRange", &MenuConfig::RadarRange, RadarRangeMin, RadarRangeMax, "%.1f", ImGuiSliderFlags_None);

				}
				ImGui::EndChild();
			}
				  break;
			case 7:
			{
				ImGui::BeginChildPos("", ImVec2(620 * dpi_scale, 400 * dpi_scale));
				{
					ImGui::SetWindowFontScale(dpi_scale);
					ImGui::Checkbox("AntiFlashbang", &MenuConfig::AntiFlashbang);
					ImGui::Checkbox("TeamCheck", &MenuConfig::TeamCheck);
					ImGui::Checkbox("OBSBypass", &MenuConfig::OBSBypass);
					ImGui::Checkbox("Bunnyhop ", &MenuConfig::BunnyHop);
					ImGui::Checkbox("ShowWhenSpec", &MenuConfig::ShowWhenSpec);
				}
				ImGui::EndChild();
			}
			break;
			case 8:
			{
				ImGui::BeginChildPos("Search here for what you want", ImVec2(620 * dpi_scale, 700 * dpi_scale));
				{
					ImGui::SetWindowFontScale(dpi_scale);
				}
				ImGui::EndChild();
			}
			break;
			}
			ImGui::PopStyleColor(1);

			ImGui::Spacing();

			ImGui::EndChild();

			ImGui::PopStyleColor(1);
		}
		if (animated_background)
			Particles();
		ImGui::PopStyleVar(1);

	}
	ImGui::End();
}

void Cheats::RadarSetting(Base_Radar& Radar)
{
	// Radar window
	ImGui::SetNextWindowBgAlpha(0.1f);
	ImGui::Begin("Radar", 0, ImGuiWindowFlags_NoResize);
	ImGui::SetWindowSize({ MenuConfig::RadarRange * 2,MenuConfig::RadarRange * 2 });

	// Radar.SetPos({ Gui.Window.Size.x / 2,Gui.Window.Size.y / 2 });
	Radar.SetDrawList(ImGui::GetWindowDrawList());
	Radar.SetPos({ ImGui::GetWindowPos().x + MenuConfig::RadarRange, ImGui::GetWindowPos().y + MenuConfig::RadarRange });
	Radar.SetProportion(MenuConfig::Proportion);
	Radar.SetRange(MenuConfig::RadarRange);
	Radar.SetSize(MenuConfig::RadarRange * 2);
	Radar.SetCrossColor(MenuConfig::RadarCrossLineColor);

	Radar.ArcArrowSize *= MenuConfig::RadarPointSizeProportion;
	Radar.ArrowSize *= MenuConfig::RadarPointSizeProportion;
	Radar.CircleSize *= MenuConfig::RadarPointSizeProportion;

	Radar.ShowCrossLine = MenuConfig::ShowRadarCrossLine;
	Radar.Opened = true;
}

void Cheats::Run()
{
	// Show menu
	static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();
	auto CurTimePoint = std::chrono::steady_clock::now();

	if (GetAsyncKeyState(VK_HOME)
		&& CurTimePoint - LastTimePoint >= std::chrono::milliseconds(150)){
		MenuConfig::ShowMenu = !MenuConfig::ShowMenu;
		LastTimePoint = CurTimePoint;
	}

	if (MenuConfig::ShowMenu)
		New_Menu();

	// Update matrix
	if (!ProcessMgr.ReadMemory(gGame.GetMatrixAddress(), gGame.View.Matrix, 64))
		return;

	// Update EntityList Entry
	gGame.UpdateEntityListEntry();

	DWORD64 LocalControllerAddress = 0;
	DWORD64 LocalPawnAddress = 0;

	if (!ProcessMgr.ReadMemory(gGame.GetLocalControllerAddress(), LocalControllerAddress))
		return;
	if (!ProcessMgr.ReadMemory(gGame.GetLocalPawnAddress(), LocalPawnAddress))
		return;

	// LocalEntity
	CEntity LocalEntity;
	static int LocalPlayerControllerIndex = 1;
	if (!LocalEntity.UpdateController(LocalControllerAddress))
		return;
	if (!LocalEntity.UpdatePawn(LocalPawnAddress) && !MenuConfig::ShowWhenSpec)
		return;

	// HealthBar Map
	static std::map<DWORD64, Render::HealthBar> HealthBarMap;

	// AimBot data
	float DistanceToSight = 0;
	float MaxAimDistance = 100000;
	Vec3  HeadPos{ 0,0,0 };
	Vec3  AimPos{ 0,0,0 };

	// Radar Data
	Base_Radar Radar;
	if (MenuConfig::ShowRadar)
		RadarSetting(Radar);

	for (int i = 0; i < 64; i++)
	{
		CEntity Entity;
		DWORD64 EntityAddress = 0;
		if (!ProcessMgr.ReadMemory<DWORD64>(gGame.GetEntityListEntry() + (i + 1) * 0x78, EntityAddress))
			continue;

		if (EntityAddress == LocalEntity.Controller.Address)
		{
			LocalPlayerControllerIndex = i;
			continue;
		}

		if (!Entity.UpdateController(EntityAddress))
			continue;

		if (!Entity.UpdatePawn(Entity.Pawn.Address))
			continue;

		if (MenuConfig::TeamCheck && Entity.Controller.TeamID == LocalEntity.Controller.TeamID)
			continue;

		if (!Entity.IsAlive())
			continue;

		// Add entity to radar
		if (MenuConfig::ShowRadar)
			Radar.AddPoint(LocalEntity.Pawn.Pos, LocalEntity.Pawn.ViewAngle.y, Entity.Pawn.Pos, ImColor(237, 85, 106, 200), MenuConfig::RadarType, Entity.Pawn.ViewAngle.y);

		if (!Entity.IsInScreen())
			continue;

		// Bone Debug
	/*	for (int BoneIndex = 0; BoneIndex < Entity.BoneData.BonePosList.size(); BoneIndex++)
		{
			Vec2 ScreenPos{};
			if (gGame.View.WorldToScreen(Entity.BoneData.BonePosList[BoneIndex].Pos, ScreenPos))
			{
				Gui.Text(std::to_string(BoneIndex), ScreenPos, ImColor(255, 255, 255, 255));
			}
		}*/

		DistanceToSight = Entity.GetBone().BonePosList[BONEINDEX::head].ScreenPos.DistanceTo({ Gui.Window.Size.x / 2,Gui.Window.Size.y / 2 });


		if (DistanceToSight < MaxAimDistance)
		{
			MaxAimDistance = DistanceToSight;
			// From: https://github.com/redbg/CS2-Internal/blob/fc8e64430176a62f8800b7467884806708a865bb/src/include/Cheats.hpp#L129
			if (!MenuConfig::VisibleCheck ||
				Entity.Pawn.bSpottedByMask & (DWORD64(1) << (LocalPlayerControllerIndex)) ||
				LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << (i)))
			{
				AimPos = Entity.GetBone().BonePosList[MenuConfig::AimPositionIndex].Pos;
				if (MenuConfig::AimPositionIndex == BONEINDEX::head)
					AimPos.z -= 1.f;
			}
		}

		// Draw Bone
		if (MenuConfig::ShowBoneESP)
			Render::DrawBone(Entity, MenuConfig::BoneColor, 1.3);

		// Draw eyeRay
		if (MenuConfig::ShowEyeRay)
			Render::ShowLosLine(Entity, 50, MenuConfig::EyeRayColor, 1.3);

		// Box
		ImVec4 Rect;
		switch (MenuConfig::BoxType)
		{
		case 0:
			Rect = Render::Get2DBox(Entity);
			break;
		case 1:
			Rect = Render::Get2DBoneRect(Entity);
			break;
		default:
			break;
		}

		// Line to enemy
		if (MenuConfig::ShowLineToEnemy)
			Render::LineToEnemy(Rect, MenuConfig::LineToEnemyColor, 1.2);

		// Draw Box
		if (MenuConfig::ShowBoxESP)
			Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, MenuConfig::BoxColor, 1.3);

		// Draw HealthBar
		if (MenuConfig::ShowHealthBar)
		{
			ImVec2 HealthBarPos, HealthBarSize;
			if (MenuConfig::HealthBarType == 0)
			{
				// Vertical
				HealthBarPos = { Rect.x - 7.f,Rect.y };
				HealthBarSize = { 7 ,Rect.w };
			}
			else
			{
				// Horizontal
				HealthBarPos = { Rect.x + Rect.z / 2 - 70 / 2,Rect.y - 13 };
				HealthBarSize = { 70,8 };
			}
			Render::DrawHealthBar(EntityAddress, 100, Entity.Pawn.Health, HealthBarPos, HealthBarSize, MenuConfig::HealthBarType);
		}

		// Draw weaponName
		if (MenuConfig::ShowWeaponESP)
			Gui.StrokeText(Entity.Pawn.WeaponName, { Rect.x,Rect.y + Rect.w }, ImColor(255, 255, 255, 255), 14);

		if (MenuConfig::ShowDistance)
			Render::DrawDistance(LocalEntity, Entity, Rect);

		if (MenuConfig::ShowPlayerName)
		{
			if (MenuConfig::HealthBarType == 0)
				Gui.StrokeText(Entity.Controller.PlayerName, { Rect.x + Rect.z / 2,Rect.y - 14 }, ImColor(255, 255, 255, 255), 14, true);
			else
				Gui.StrokeText(Entity.Controller.PlayerName, { Rect.x + Rect.z / 2,Rect.y - 13 - 14 }, ImColor(255, 255, 255, 255), 14, true);
		}

	}

	// Fov line
	if (MenuConfig::ShowFovLine)
		Render::DrawFov(LocalEntity, MenuConfig::FovLineSize, MenuConfig::FovLineColor, 1);

	// Radar render
	if (MenuConfig::ShowRadar)
	{
		Radar.Render();
		//End for radar window
		ImGui::End();
	}

	// TriggerBot
	if (MenuConfig::TriggerMode == 1 && MenuConfig::TriggerBot && GetAsyncKeyState(TriggerBot::HotKey) && MenuConfig::Pressed&& CurTimePoint - LastTimePoint >= std::chrono::milliseconds(150))
	{
		MenuConfig::Pressed = false;
		LastTimePoint = CurTimePoint;
	}
	else if (MenuConfig::TriggerMode == 1 && MenuConfig::TriggerBot && GetAsyncKeyState(TriggerBot::HotKey)&& !MenuConfig::Pressed&& CurTimePoint - LastTimePoint >= std::chrono::milliseconds(150))
	{
		MenuConfig::Pressed = true;
		LastTimePoint = CurTimePoint;
	}

	if (MenuConfig::TriggerMode == 0 && MenuConfig::TriggerBot && GetAsyncKeyState(TriggerBot::HotKey))
	{
		MenuConfig::Shoot = true;
		TriggerBot::Run(LocalEntity);
		MenuConfig::Shoot = false;
	}
	else if (MenuConfig::TriggerMode == 1 && MenuConfig::TriggerBot && MenuConfig::Pressed) 
	{
		MenuConfig::Shoot = true;
		TriggerBot::Run(LocalEntity);
		MenuConfig::Shoot = false;
	}
			


	// HeadShoot Line
	if(MenuConfig::ShowHeadShootLine)
		Render::HeadShootLine(LocalEntity, MenuConfig::HeadShootLineColor);

	// CrossHair
	if (MenuConfig::ShowCrossHair)
		Render::DrawCrossHair();

	// Fov circle
	if(MenuConfig::ShowAimFovRange)
		Render::DrawFovCircle(LocalEntity);
	
	if (MenuConfig::BunnyHop)
		Bunnyhop::Run(LocalEntity);

	if (MenuConfig::AntiFlashbang)
		AntiFlashbang::Run(LocalEntity);

	if (MenuConfig::AimBot && GetAsyncKeyState(AimControl::HotKey))
	{
		if (AimPos != Vec3(0, 0, 0))
		{
			AimControl::AimBot(LocalEntity, LocalEntity.Pawn.CameraPos, AimPos);
		}
	}
}
