#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include "../Core/Player.hpp"
#include "../Core/LocalPlayer.hpp"
#include "../Core/Offsets.hpp"
#include "../Core/GlowMode.hpp"
#include "../Core/Camera.hpp"
#include "../Core/Level.hpp"

#include "../Features/Aimbot.hpp"
#include "../Utils//Conversion.hpp"
#include "../Math/Resolver.hpp"


#include "../Overlay/Overlay.hpp"
#include "../Overlay/Renderer.hpp"

#include "../Utils/Memory.hpp"
#include "../Utils/Color.hpp"
#include "../Utils/Conversion.hpp"
#include "../Utils/Config.hpp"
#include "../Utils/Modules.hpp"
#include "../Utils/HitboxType.hpp"
#include "../Utils/XDisplay.hpp"
#include "../Utils/InputManager.hpp"
#include "../Utils/InputTypes.hpp"

// UI //
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

// Geometry
#define DEG2RAD(x) ((float)(x) * (float)(M_PI / 180.f))
#define ABS(x) ((x < 0) ? (-x) : (x))




struct Sense
{
	// ESP
	bool VisibilityCheck = false;
	bool DrawBoxes = true;
	int BoxType = 0;
	int BoxStyle = 0;
	float BoxThickness = 1.0;

	bool Skeleton = true;
	float SkeletonThickness = 1.0;

	bool HealthBar = true;
	bool ShieldBar = true;

	int BarMode = 2;
	int BarStyle = 0;
	float BarThickness = 1.0f;
	float BarThickness2 = 0.05f;
	float BarHeight = 5.0f;
	float BarWidth = 60.0f;

	float ESPMaxDistance = 200;
	bool ShowNear = false;
	bool DrawSeer = false;
	bool DrawStatus = true;
	bool DrawWeapon = false;
        bool drawlvl = true;
	bool WeaponColorType = false;
	bool ShowLegend = false;
	bool ShowMaxStatusValues = true;

	bool DrawDistance = true;
	bool DrawFOVCircle = true;
	bool DrawFilledFOVCircle = false;
	float FOVThickness = 1.0;
	bool DrawNames = true;
	int TracerPosition = 0;
	int TracerBone = 0;
	bool DrawTracers = true;
	float TracerThickness = 2.0;
	bool ShowSpectators = true;
	bool DrawCrosshair = true;
	float CrosshairSize = 7.0;
	float CrosshairThickness = 1.0;
    bool aimline = true;

	// Settings
	float GameFOV = 120;
	bool ShowTeam = false;
	bool TeamNames = false;

	// Variables
	XDisplay *X11Display;
	Camera *GameCamera;
	LocalPlayer *Myself;
	std::vector<Player *> *Players;
	std::chrono::milliseconds LastUpdateTime;
	int TotalSpectators = 0;
	std::vector<std::string> Spectators;
	Level *Map;
    Player* p = nullptr;

	Sense(Level *Map, std::vector<Player *> *Players, Camera *GameCamera, LocalPlayer *Myself, XDisplay *X11Display)
	{
		this->Players = Players;
		this->GameCamera = GameCamera;
		this->Map = Map;
		this->Myself = Myself;
		this->X11Display = X11Display;
	}

	void RenderUI()
	{
		if (ImGui::BeginTabItem("ESP", nullptr, ImGuiTabItemFlags_NoCloseWithMiddleMouseButton | ImGuiTabItemFlags_NoReorder))
		{
			ImVec2 TabSize;
			TabSize = ImGui::GetWindowSize();

			// ImGui::Columns(2, nullptr, true);
			ImGui::Text("Player ESP");
			if (ImGui::BeginChild("Player ESP", ImVec2(TabSize.x - TabSize.x, (TabSize.y - TabSize.y) + 270), true))
			{
				ImGui::Text("Boxes");
				ImGui::Checkbox("Draw Boxes", &DrawBoxes);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw a box on the enemy");
				if (DrawBoxes)
				{
					const char *BoxTypeIndex[] = {"2D", "2D Corners"};
					ImGui::Combo("Box Type", &BoxType, BoxTypeIndex, IM_ARRAYSIZE(BoxTypeIndex));
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("What Type Of Box Will Be Displayed.");

					const char *BoxStyleIndex[] = {"Thin", "Wide"};
					ImGui::Combo("Box Style", &BoxStyle, BoxStyleIndex, IM_ARRAYSIZE(BoxStyleIndex));
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("What Style Of Box Will Be Displayed.");

					ImGui::SliderFloat("Box Thickness", &BoxThickness, 1, 10, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Changes the thickness of the boxes");

					ImGui::ColorEdit4("2D Box Visible Color", Modules::Colors::VisibleBoxColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					ImGui::SameLine();
					ImGui::ColorEdit4("2D Box Invisible Color", Modules::Colors::InvisibleBoxColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);

					if (BoxType == 1)
					{
						ImGui::ColorEdit4("2D Filled Box Visible Color", Modules::Colors::VisibleFilledBoxColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("2D Filled Box Invisible Color", Modules::Colors::InvisibleFilledBoxColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					}
				}

				ImGui::Separator();

				ImGui::Text("Tracers");
				ImGui::Checkbox("Draw Tracers", &DrawTracers);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw lines to enemies");
				if (DrawTracers)
				{
					const char *TracerPos[] = {"Top", "Crosshair", "Bottom"};
					ImGui::Combo("Tracer Position", &TracerPosition, TracerPos, IM_ARRAYSIZE(TracerPos));
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Where tracers will be drawn from.");
					Config::Sense::TracerPos = TracerPosition;
					const char *TracerBones[] = {"Top", "Bottom"};
					ImGui::Combo("Tracer Bone", &TracerBone, TracerBones, IM_ARRAYSIZE(TracerBones));
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Where tracers will be drawn to.");
					Config::Sense::TracerBone = TracerBone;
					ImGui::SliderFloat("Tracer Thickness", &TracerThickness, 1, 10, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Changes the thickness of the tracers");
					ImGui::ColorEdit4("Tracer Visible Color", Modules::Colors::VisibleTracerColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					ImGui::SameLine();
					ImGui::ColorEdit4("Tracer Invisible Color", Modules::Colors::InvisibleTracerColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
				}

				ImGui::Separator();

				ImGui::Text("Skeleton");
				ImGui::Checkbox("Draw Skeleton", &Skeleton);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw the enemies skeletons (Spooky)");
				if (Skeleton)
				{
					ImGui::SliderFloat("Skeleton Thickness", &SkeletonThickness, 1, 10, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Changes the thickness of the bones");
					ImGui::ColorEdit4("Visible Color", Modules::Colors::VisibleSkeletonColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					ImGui::SameLine();
					ImGui::ColorEdit4("Invisible Color", Modules::Colors::InvisibleSkeletonColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
				}

				ImGui::Separator();

				ImGui::Text("Info Bars");
				const char *BarStyleIndex[] = {"Side", "Top", "Seer"};
				ImGui::Combo("Bar Style", &BarStyle, BarStyleIndex, IM_ARRAYSIZE(BarStyleIndex));
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Where AND What Style Of Health + Shield Bar Will Be.\nSeer = Seer's Ability.");

				if (BarStyle == 0 or BarStyle == 1)
				{
					DrawSeer = false;
					const char *BarModeIndex[] = {"Health Only", "Shield Only", "Health & Shield"};
					ImGui::Combo("Bar Mode", &BarMode, BarModeIndex, IM_ARRAYSIZE(BarModeIndex));
				}

				if (BarMode == 0 or BarMode == 1)
				{
					DrawSeer = false;
					const char *BarColorModeIndex[] = {"Max Shield", "Current Shield"};
					ImGui::Combo("Bar Color", &Modules::Sense::BarColorMode, BarColorModeIndex, IM_ARRAYSIZE(BarColorModeIndex));
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("What Color The Shield Bar Will Be.");
				}

				if (!BarStyle == 2)
				{
					ImGui::Checkbox("Bar Background", &Modules::Sense::BarBackground);
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Adds a background for the info bars.");
					if (Modules::Sense::BarBackground)
					{
						ImGui::SameLine();
						ImGui::ColorEdit4("Bar Background Color", Modules::Colors::BarBGColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					}
				}

				if (BarStyle == 2)
				{ // Seer
					ImGui::Checkbox("Draw Seer", &DrawSeer);
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Draw Seer's abilitiy (Show Health & Armor) on enemies");
				}

				if (BarStyle == 1)
				{ // Top
					DrawSeer = false;
					ImGui::SliderFloat("Bar Height", &BarHeight, 5, 20, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Height of the enemy bar");
					ImGui::SliderFloat("Bar Width", &BarWidth, 10, 125, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Width of the enemy bar");
				}

				if (BarStyle == 0)
				{ // Side
					DrawSeer = false;
					ImGui::SliderFloat("Bar Thickness##2", &BarThickness2, 0, 0.99, "%.3f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Thickness of the health/shield bar");
				}

				if (BarStyle == 1)
				{ // Top
					DrawSeer = false;
					ImGui::SliderFloat("Bar Thickness", &BarThickness, 1, 10, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Thickness of the health/shield bar");
				}

				ImGui::Separator();

				ImGui::Text("Player Info");
				ImGui::Checkbox("Draw Status", &DrawStatus);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw enemies current health and armor");
				
				if (DrawStatus)
				{
					ImGui::SameLine();
					ImGui::Checkbox("Show Max Values", &ShowMaxStatusValues);
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Adds their max health and max armor at the end.");
				}

                ImGui::Checkbox("Draw Level", &drawlvl);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                    ImGui::SetTooltip("Show What Level The Enemy Is.");

				ImGui::Checkbox("Draw Legend", &ShowLegend);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Show What Legend The Enemy Is Playing As.");
				if (ShowLegend)
				{
					ImGui::SameLine();
					ImGui::ColorEdit4("Legend Visible Color", Modules::Colors::VisibleLegendColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					ImGui::SameLine();
					ImGui::ColorEdit4("Legend Invisible Color", Modules::Colors::InvisibleLegendColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
				}

				ImGui::Checkbox("Draw Weapon", &DrawWeapon);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Show what weapon an enemy is currently holding.");
				if (DrawWeapon)
				{
					const char *WeaponColorModeIndex[] = {"Single Color", "Multiple Colors"};
					ImGui::Combo("Weapon Color Mode", &Modules::Colors::WeaponColorMode, WeaponColorModeIndex, IM_ARRAYSIZE(WeaponColorModeIndex));
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Changes The Weapon Text Color To The Ammo Type Of The Weapon.");

					if (Modules::Colors::WeaponColorMode == 0)
					{
						ImGui::SameLine();
						ImGui::ColorEdit4("Weapon Visible Color", Modules::Colors::VisibleWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("Weapon Invisible Color", Modules::Colors::InvisibleWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					}

					if (Modules::Colors::WeaponColorMode == 1)
					{
						ImGui::ColorEdit4("Light##ESPWeaponColor", Modules::Colors::LightWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("Heavy##ESPWeaponColor", Modules::Colors::HeavyWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("Energy##ESPWeaponColor", Modules::Colors::EnergyWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("Shotguns##ESPWeaponColor", Modules::Colors::ShotgunWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4("Snipers##ESPWeaponColor", Modules::Colors::SniperWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("Legendary##ESPWeaponColor", Modules::Colors::LegendaryWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("Throwables##ESPWeapon", Modules::Colors::ThrowableWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
						ImGui::SameLine();
						ImGui::ColorEdit4("Melee##ESPWeapon", Modules::Colors::MeleeWeaponColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					}
				}

				ImGui::Checkbox("Draw Names", &DrawNames);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Show enemies names.");
				if (DrawNames)
				{
					ImGui::SameLine();
					ImGui::ColorEdit4("Name Visible Color", Modules::Colors::VisibleNameColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					ImGui::SameLine();
					ImGui::ColorEdit4("Name Invisible Color", Modules::Colors::InvisibleNameColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
				}

				ImGui::Checkbox("Draw Distance", &DrawDistance);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Show how far away the enemies are");
				if (DrawDistance)
				{
					ImGui::SameLine();
					ImGui::ColorEdit4("Distance Visible Color", Modules::Colors::VisibleDistanceColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					ImGui::SameLine();
					ImGui::ColorEdit4("Distance Invisible Color", Modules::Colors::InvisibleDistanceColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
				}

				ImGui::Checkbox("Show Enemy Count Near", &ShowNear);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Show how many enemies are near");
				if (ShowNear)
				{
					ImGui::SameLine();
					ImGui::ColorEdit4("Near Color", Modules::Colors::NearColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
				}

				ImGui::EndChild();
			}

			// ImGui::NextColumn(); //Right

			ImGui::Text("Drawings");
			if (ImGui::BeginChild("Drawings", ImVec2(TabSize.x - TabSize.x, (TabSize.y - TabSize.y) + 285), true))
			{
				ImGui::Text("General");
				ImGui::SliderFloat("ESP Max Distance", &ESPMaxDistance, 0, 1000, "%.0f");
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Only those in range will ESP");
				ImGui::Checkbox("Visibility Check", &VisibilityCheck);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw's ESP ONLY on visible players");
				ImGui::Checkbox("Show Team", &ShowTeam);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw's ESP on Teammates");
				ImGui::SameLine();
				ImGui::ColorEdit4("Team Color", Modules::Colors::TeamColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);

				ImGui::Checkbox("Show Team Names", &TeamNames);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw Name ESP on Teammates");
				ImGui::SameLine();
				ImGui::ColorEdit4("Team Name Color", Modules::Colors::TeamNameColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);

				ImGui::Separator();

				ImGui::Text("Watermark");
				ImGui::Checkbox("Enable Watermark", &Modules::Watermark::Watermark);
				ImGui::Text("Watermark Settings");
				ImGui::Checkbox("Display Name", &Modules::Watermark::Name);
				ImGui::Checkbox("Display Processing Speed", &Modules::Watermark::ProcessingSpeed);
				ImGui::Checkbox("Display Spectators Number", &Modules::Watermark::Spectators);

				ImGui::Separator();

				ImGui::Text("Spectator List");
				ImGui::Checkbox("Show Spectators", &ShowSpectators);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Show spectators.");

				ImGui::Separator();

				ImGui::Text("Crosshair");
				ImGui::Checkbox("Draw Crosshair", &DrawCrosshair);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draws a crosshair");
				if (DrawCrosshair)
				{
					ImGui::SliderFloat("Crosshair Size", &CrosshairSize, 0, 1000, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Changes the size of the crosshair");
					ImGui::SliderFloat("Crosshair Thickness", &CrosshairThickness, 1, 50, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Changes the Crosshair's thickness");
					ImGui::ColorEdit4("Crosshair Color", Modules::Colors::CrosshairColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
				}

				ImGui::Separator();

				ImGui::Text("FOV Circle");
				ImGui::Checkbox("Draw FOV Circle", &DrawFOVCircle);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw FOV Circle.\nDoes Not Draw If Aimbot Mode == Grinder.");
				ImGui::Checkbox("Draw Filled FOV Circle", &DrawFilledFOVCircle);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("Draw a Filled FOV Circle");
				if (DrawFOVCircle or DrawFilledFOVCircle)
				{
					ImGui::SliderFloat("FOV Circle Thickness", &FOVThickness, 1, 10, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Changes the FOV Circle's thickness\n Recomended: 1-2");
					ImGui::SliderFloat("Game's FOV", &GameFOV, 70, 120, "%.0f");
					if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
						ImGui::SetTooltip("Your current FOV in Settings");
					if (DrawFOVCircle)
					{
						ImGui::ColorEdit4("FOV Color", Modules::Colors::FOVColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					}
					if (DrawFilledFOVCircle)
					{
						ImGui::ColorEdit4("Filled FOV Color", Modules::Colors::FilledFOVColor, ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoInputs);
					}
				}

				ImGui::EndChild();
			}

			ImGui::EndTabItem();
		}
	}

	bool Save()
	{
		try
		{
			Config::Sense::VisibilityCheck = VisibilityCheck;

			Config::Sense::DrawBoxes = DrawBoxes;
			Config::Sense::BoxType = BoxType;
			Config::Sense::BoxStyle = BoxStyle;
			Config::Sense::BoxThickness = BoxThickness;

			Config::Sense::Skeleton = Skeleton;
			Config::Sense::SkeletonThickness = SkeletonThickness;

			Config::Sense::HealthBar = HealthBar;
			Config::Sense::ShieldBar = ShieldBar;
			Config::Sense::drawlvl = drawlvl;
			Config::Sense::BarMode = BarMode;
			Config::Sense::BarStyle = BarStyle;
			Config::Sense::BarColorMode = Modules::Sense::BarColorMode;
			Config::Sense::BarBackground = Modules::Sense::BarBackground;
			Config::Sense::BarThickness = BarThickness;
			Config::Sense::BarThickness2 = BarThickness2;
			Config::Sense::BarHeight = BarHeight;
			Config::Sense::BarWidth = BarWidth;

			Config::Sense::ESPMaxDistance = ESPMaxDistance;
			Config::Sense::ShowNear = ShowNear;
			Config::Sense::DrawSeer = DrawSeer;
			Config::Sense::DrawStatus = DrawStatus;
			Config::Sense::DrawWeapon = DrawWeapon;
			Config::Sense::WeaponColorType = WeaponColorType;
			Config::Sense::ShowLegend = ShowLegend;
			Config::Sense::ShowMaxStatusValues = ShowMaxStatusValues;
			Config::Sense::DrawDistance = DrawDistance;
			Config::Sense::DrawFOVCircle = DrawFOVCircle;
			Config::Sense::DrawFilledFOVCircle = DrawFilledFOVCircle;
			Config::Sense::FOVThickness = FOVThickness;
			Config::Sense::DrawNames = DrawNames;
			Config::Sense::TracerPos = TracerPosition;
			Config::Sense::TracerBone = TracerBone;
			Config::Sense::DrawTracers = DrawTracers;
			Config::Sense::TracerThickness = TracerThickness;
			Config::Sense::ShowSpectators = ShowSpectators;
			Config::Sense::DrawCrosshair = DrawCrosshair;
			Config::Sense::CrosshairSize = CrosshairSize;
			Config::Sense::CrosshairThickness = CrosshairThickness;
			Config::Sense::GameFOV = GameFOV;
			Config::Sense::ShowTeam = ShowTeam;
			Config::Sense::TeamNames = TeamNames;

			// Colors
			// Config::Sense::WeaponColorType = WeaponColorType;
			Config::Colors::InvisibleBoxColorR = Modules::Colors::InvisibleBoxColor[0];
			Config::Colors::InvisibleBoxColorG = Modules::Colors::InvisibleBoxColor[1];
			Config::Colors::InvisibleBoxColorB = Modules::Colors::InvisibleBoxColor[2];
			Config::Colors::InvisibleBoxColorA = Modules::Colors::InvisibleBoxColor[3];
			Config::Colors::VisibleBoxColorR = Modules::Colors::VisibleBoxColor[0];
			Config::Colors::VisibleBoxColorG = Modules::Colors::VisibleBoxColor[1];
			Config::Colors::VisibleBoxColorB = Modules::Colors::VisibleBoxColor[2];
			Config::Colors::VisibleBoxColorA = Modules::Colors::VisibleBoxColor[3];
			Config::Colors::InvisibleFilledBoxColorR = Modules::Colors::InvisibleFilledBoxColor[0];
			Config::Colors::InvisibleFilledBoxColorG = Modules::Colors::InvisibleFilledBoxColor[1];
			Config::Colors::InvisibleFilledBoxColorB = Modules::Colors::InvisibleFilledBoxColor[2];
			Config::Colors::InvisibleFilledBoxColorA = Modules::Colors::InvisibleFilledBoxColor[3];
			Config::Colors::VisibleFilledBoxColorR = Modules::Colors::VisibleFilledBoxColor[0];
			Config::Colors::VisibleFilledBoxColorG = Modules::Colors::VisibleFilledBoxColor[1];
			Config::Colors::VisibleFilledBoxColorB = Modules::Colors::VisibleFilledBoxColor[2];
			Config::Colors::VisibleFilledBoxColorA = Modules::Colors::VisibleFilledBoxColor[3];
			Config::Colors::InvisibleTracerColorR = Modules::Colors::InvisibleTracerColor[0];
			Config::Colors::InvisibleTracerColorG = Modules::Colors::InvisibleTracerColor[1];
			Config::Colors::InvisibleTracerColorB = Modules::Colors::InvisibleTracerColor[2];
			Config::Colors::InvisibleTracerColorA = Modules::Colors::InvisibleTracerColor[3];
			Config::Colors::VisibleTracerColorR = Modules::Colors::VisibleTracerColor[0];
			Config::Colors::VisibleTracerColorG = Modules::Colors::VisibleTracerColor[1];
			Config::Colors::VisibleTracerColorB = Modules::Colors::VisibleTracerColor[2];
			Config::Colors::VisibleTracerColorA = Modules::Colors::VisibleTracerColor[3];
			Config::Colors::InvisibleSkeletonColorR = Modules::Colors::InvisibleSkeletonColor[0];
			Config::Colors::InvisibleSkeletonColorG = Modules::Colors::InvisibleSkeletonColor[1];
			Config::Colors::InvisibleSkeletonColorB = Modules::Colors::InvisibleSkeletonColor[2];
			Config::Colors::InvisibleSkeletonColorA = Modules::Colors::InvisibleSkeletonColor[3];
			Config::Colors::VisibleSkeletonColorR = Modules::Colors::VisibleSkeletonColor[0];
			Config::Colors::VisibleSkeletonColorG = Modules::Colors::VisibleSkeletonColor[1];
			Config::Colors::VisibleSkeletonColorB = Modules::Colors::VisibleSkeletonColor[2];
			Config::Colors::VisibleSkeletonColorA = Modules::Colors::VisibleSkeletonColor[3];
			Config::Colors::InvisibleNameColorR = Modules::Colors::InvisibleNameColor[0];
			Config::Colors::InvisibleNameColorG = Modules::Colors::InvisibleNameColor[1];
			Config::Colors::InvisibleNameColorB = Modules::Colors::InvisibleNameColor[2];
			Config::Colors::InvisibleNameColorA = Modules::Colors::InvisibleNameColor[3];
			Config::Colors::VisibleNameColorR = Modules::Colors::VisibleNameColor[0];
			Config::Colors::VisibleNameColorG = Modules::Colors::VisibleNameColor[1];
			Config::Colors::VisibleNameColorB = Modules::Colors::VisibleNameColor[2];
			Config::Colors::VisibleNameColorA = Modules::Colors::VisibleNameColor[3];
			Config::Colors::InvisibleDistanceColorR = Modules::Colors::InvisibleDistanceColor[0];
			Config::Colors::InvisibleDistanceColorG = Modules::Colors::InvisibleDistanceColor[1];
			Config::Colors::InvisibleDistanceColorB = Modules::Colors::InvisibleDistanceColor[2];
			Config::Colors::InvisibleDistanceColorA = Modules::Colors::InvisibleDistanceColor[3];
			Config::Colors::VisibleDistanceColorR = Modules::Colors::VisibleDistanceColor[0];
			Config::Colors::VisibleDistanceColorG = Modules::Colors::VisibleDistanceColor[1];
			Config::Colors::VisibleDistanceColorB = Modules::Colors::VisibleDistanceColor[2];
			Config::Colors::VisibleDistanceColorA = Modules::Colors::VisibleDistanceColor[3];
			Config::Colors::InvisibleWeaponColorR = Modules::Colors::InvisibleWeaponColor[0];
			Config::Colors::InvisibleWeaponColorG = Modules::Colors::InvisibleWeaponColor[1];
			Config::Colors::InvisibleWeaponColorB = Modules::Colors::InvisibleWeaponColor[2];
			Config::Colors::InvisibleWeaponColorA = Modules::Colors::InvisibleWeaponColor[3];
			Config::Colors::VisibleWeaponColorR = Modules::Colors::VisibleWeaponColor[0];
			Config::Colors::VisibleWeaponColorG = Modules::Colors::VisibleWeaponColor[1];
			Config::Colors::VisibleWeaponColorB = Modules::Colors::VisibleWeaponColor[2];
			Config::Colors::VisibleWeaponColorA = Modules::Colors::VisibleWeaponColor[3];
			Config::Colors::FOVColorR = Modules::Colors::FOVColor[0];
			Config::Colors::FOVColorG = Modules::Colors::FOVColor[1];
			Config::Colors::FOVColorB = Modules::Colors::FOVColor[2];
			Config::Colors::FOVColorA = Modules::Colors::FOVColor[3];
			Config::Colors::FilledFOVColorR = Modules::Colors::FilledFOVColor[0];
			Config::Colors::FilledFOVColorG = Modules::Colors::FilledFOVColor[1];
			Config::Colors::FilledFOVColorB = Modules::Colors::FilledFOVColor[2];
			Config::Colors::FilledFOVColorA = Modules::Colors::FilledFOVColor[3];
			Config::Colors::NearColorR = Modules::Colors::NearColor[0];
			Config::Colors::NearColorG = Modules::Colors::NearColor[1];
			Config::Colors::NearColorB = Modules::Colors::NearColor[2];
			Config::Colors::NearColorA = Modules::Colors::NearColor[3];
			Config::Colors::TeamColorR = Modules::Colors::TeamColor[0];
			Config::Colors::TeamColorG = Modules::Colors::TeamColor[1];
			Config::Colors::TeamColorB = Modules::Colors::TeamColor[2];
			Config::Colors::TeamColorA = Modules::Colors::TeamColor[3];
			Config::Colors::TeamNameColorR = Modules::Colors::TeamNameColor[0];
			Config::Colors::TeamNameColorG = Modules::Colors::TeamNameColor[1];
			Config::Colors::TeamNameColorB = Modules::Colors::TeamNameColor[2];
			Config::Colors::TeamNameColorA = Modules::Colors::TeamNameColor[3];
			Config::Colors::CrosshairColorR = Modules::Colors::CrosshairColor[0];
			Config::Colors::CrosshairColorG = Modules::Colors::CrosshairColor[1];
			Config::Colors::CrosshairColorB = Modules::Colors::CrosshairColor[2];
			Config::Colors::CrosshairColorA = Modules::Colors::CrosshairColor[3];
			// Weapon Colors
			Config::Colors::LightWeaponColorR = Modules::Colors::LightWeaponColor[0];
			Config::Colors::LightWeaponColorG = Modules::Colors::LightWeaponColor[1];
			Config::Colors::LightWeaponColorB = Modules::Colors::LightWeaponColor[2];
			Config::Colors::LightWeaponColorA = Modules::Colors::LightWeaponColor[3];
			Config::Colors::HeavyWeaponColorR = Modules::Colors::HeavyWeaponColor[0];
			Config::Colors::HeavyWeaponColorG = Modules::Colors::HeavyWeaponColor[1];
			Config::Colors::HeavyWeaponColorB = Modules::Colors::HeavyWeaponColor[2];
			Config::Colors::HeavyWeaponColorA = Modules::Colors::HeavyWeaponColor[3];
			Config::Colors::EnergyWeaponColorR = Modules::Colors::EnergyWeaponColor[0];
			Config::Colors::EnergyWeaponColorG = Modules::Colors::EnergyWeaponColor[1];
			Config::Colors::EnergyWeaponColorB = Modules::Colors::EnergyWeaponColor[2];
			Config::Colors::EnergyWeaponColorA = Modules::Colors::EnergyWeaponColor[3];
			Config::Colors::ShotgunWeaponColorR = Modules::Colors::ShotgunWeaponColor[0];
			Config::Colors::ShotgunWeaponColorG = Modules::Colors::ShotgunWeaponColor[1];
			Config::Colors::ShotgunWeaponColorB = Modules::Colors::ShotgunWeaponColor[2];
			Config::Colors::ShotgunWeaponColorA = Modules::Colors::ShotgunWeaponColor[3];
			Config::Colors::SniperWeaponColorR = Modules::Colors::SniperWeaponColor[0];
			Config::Colors::SniperWeaponColorG = Modules::Colors::SniperWeaponColor[1];
			Config::Colors::SniperWeaponColorB = Modules::Colors::SniperWeaponColor[2];
			Config::Colors::SniperWeaponColorA = Modules::Colors::SniperWeaponColor[3];
			Config::Colors::LegendaryWeaponColorR = Modules::Colors::LegendaryWeaponColor[0];
			Config::Colors::LegendaryWeaponColorG = Modules::Colors::LegendaryWeaponColor[1];
			Config::Colors::LegendaryWeaponColorB = Modules::Colors::LegendaryWeaponColor[2];
			Config::Colors::LegendaryWeaponColorA = Modules::Colors::LegendaryWeaponColor[3];
			Config::Colors::MeleeWeaponColorR = Modules::Colors::MeleeWeaponColor[0];
			Config::Colors::MeleeWeaponColorG = Modules::Colors::MeleeWeaponColor[1];
			Config::Colors::MeleeWeaponColorB = Modules::Colors::MeleeWeaponColor[2];
			Config::Colors::MeleeWeaponColorA = Modules::Colors::MeleeWeaponColor[3];
			Config::Colors::ThrowableWeaponColorR = Modules::Colors::ThrowableWeaponColor[0];
			Config::Colors::ThrowableWeaponColorG = Modules::Colors::ThrowableWeaponColor[1];
			Config::Colors::ThrowableWeaponColorB = Modules::Colors::ThrowableWeaponColor[2];
			Config::Colors::ThrowableWeaponColorA = Modules::Colors::ThrowableWeaponColor[3];

			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	void RenderWatermark(ImDrawList *Canvas, LocalPlayer *Myself, Overlay OverlayWindow)
	{
		int ScreenWidth;
		int ScreenHeight;
		OverlayWindow.GetScreenResolution(ScreenWidth, ScreenHeight);

		if (Modules::Watermark::Watermark)
		{
			if (Modules::Watermark::WatermarkPosition == 0)
			{ // Top Right
				ImGui::SetNextWindowPos(ImVec2(10.0f, 22.0f), ImGuiCond_Once, ImVec2(0.02f, 0.5f));
			}
			ImGui::SetNextWindowBgAlpha(0.3f);
			ImGui::Begin("Watermark", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);

			ImGuiStyle &style = ImGui::GetStyle();
			if (Modules::Watermark::Name)
			{
				ImGui::TextColored(style.Colors[ImGuiCol_Text], "zap-client");
			}

			ImGui::SameLine();
			ImGui::TextColored(ImVec4(1, 1, 1, 1), " | ");
			ImGui::SameLine();

			if (Modules::Watermark::Spectators)
			{
				std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
				if (Now >= LastUpdateTime + std::chrono::milliseconds(500))
				{
					int TempTotalSpectators = 0;
					std::vector<std::string> TempSpectators;

					for (int i = 0; i < Players->size(); i++)
					{
                        Player *p = Players->at(i);
						if (p->BasePointer == Myself->BasePointer)
							continue;
						if (p->GetViewYaw() == Myself->ViewYaw && p->IsDead)
						{
							TempTotalSpectators++;
							TempSpectators.push_back(p->GetPlayerName());
						}
					}

					TotalSpectators = TempTotalSpectators;
					Spectators = TempSpectators;
					LastUpdateTime = Now;
				}
				ImGui::Text("Spectators: ");
				ImGui::SameLine();
				ImGui::TextColored(TotalSpectators > 0 ? ImVec4(1, 0.343, 0.475, 1) : ImVec4(0.4, 1, 0.343, 1), "%d", TotalSpectators);
			}

			ImGui::SameLine();

			ImGui::TextColored(ImVec4(1, 1, 1, 1), " | ");

			ImGui::SameLine();

			if (Modules::Watermark::ProcessingSpeed)
			{
				ImVec4 ProcessingTimeColor;
				ProcessingTimeColor = OverlayWindow.ProcessingTime > 20 ? ProcessingTimeColor = ImVec4(1, 0.343, 0.475, 1) : ProcessingTimeColor = ImVec4(0.4, 1, 0.343, 1);
				ImGui::TextColored(ProcessingTimeColor, "Processing Time: %02dms ", OverlayWindow.ProcessingTime);
			}
			ImGui::End();
		}
	}

	void RenderDrawings(ImDrawList *Canvas, Aimbot *AimAssistState, LocalPlayer *Myself, Overlay OverlayWindow)
	{
		int ScreenWidth;
		int ScreenHeight;
		OverlayWindow.GetScreenResolution(ScreenWidth, ScreenHeight);

		/*bool GetWeaponID = true; //For finding weapon IDs (Local Player) DONT USE WITH SHOW SPECTATORS
		if (GetWeaponID) {
			if (!Myself->IsDead) {

			ImVec2 Center = ImGui::GetMainViewport()->GetCenter();
					ImGui::SetNextWindowPos(ImVec2(0.0f, Center.y), ImGuiCond_Once, ImVec2(0.02f, 0.5f));
					ImGui::SetNextWindowBgAlpha(0.3f);
			ImGui::Begin("Current Weapon ID", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);

			std::stringstream LocalwepID;
			LocalwepID << Myself->WeaponIndex;
			std::string LocalwepInt = LocalwepID.str() + " ";
			const char* LocalwepText = (char*)LocalwepInt.c_str();

					ImGui::Text("Current ID: ");
					ImGui::SameLine();
					ImGui::Text(LocalwepText);
					ImGui::End();
			}
		}*/

		if (!Map->IsPlayable)
			return;
		if (Myself->IsDead)
			return;

		if (ShowSpectators)
		{
			ImVec2 Center = ImGui::GetMainViewport()->GetCenter();
			ImGui::SetNextWindowPos(ImVec2(0.0f, Center.y), ImGuiCond_Once, ImVec2(0.02f, 0.5f));
			ImGui::SetNextWindowBgAlpha(0.3f);
			ImGui::Begin("Spectators", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);

			std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
			if (Now >= LastUpdateTime + std::chrono::milliseconds(1500))
			{
				int TempTotalSpectators = 0;
				std::vector<std::string> TempSpectators;

				for (int i = 0; i < Players->size(); i++)
				{
					Player *p = Players->at(i);
					if (p->BasePointer == Myself->BasePointer)
						continue;
					if (p->GetViewYaw() == Myself->ViewYaw && p->IsDead)
					{
						TempTotalSpectators++;
						TempSpectators.push_back(p->GetPlayerName());
					}
				}

				TotalSpectators = TempTotalSpectators;
				Spectators = TempSpectators;
				LastUpdateTime = Now;
			}
			ImGui::Text("Spectators: ");
			ImGui::SameLine();
			ImGui::TextColored(TotalSpectators > 0 ? ImVec4(1, 0.343, 0.475, 1) : ImVec4(0.4, 1, 0.343, 1), "%d", TotalSpectators);
			if (static_cast<int>(Spectators.size()) > 0)
			{
				ImGui::Separator();
				for (int i = 0; i < static_cast<int>(Spectators.size()); i++)
				{
					ImGui::TextColored(ImVec4(1, 0.343, 0.475, 1), "> %s", Spectators.at(i).c_str());
				}
			}
			ImGui::End();
		}

		// Draw Crosshair
		if (DrawCrosshair)
		{
			int x = (int)(ScreenWidth * 0.5f);
			int y = (int)(ScreenHeight * 0.5f);
			Renderer::DrawLine(Canvas, Vector2D(x - CrosshairSize, y), Vector2D(x + CrosshairSize, y), CrosshairThickness, ImColor(Modules::Colors::CrosshairColor[0], Modules::Colors::CrosshairColor[1], Modules::Colors::CrosshairColor[2], Modules::Colors::CrosshairColor[3])); // Left - right
			Renderer::DrawLine(Canvas, Vector2D(x, y - CrosshairSize), Vector2D(x, y + CrosshairSize), CrosshairThickness, ImColor(Modules::Colors::CrosshairColor[0], Modules::Colors::CrosshairColor[1], Modules::Colors::CrosshairColor[2], Modules::Colors::CrosshairColor[3])); // Top - bottom
		}

		// Draw FOV Circle
        if (DrawFOVCircle && (!AimAssistState->AimbotMode == 1 || AimAssistState->AimbotMode == 2) && Myself->IsCombatReady())
		{
			float FOV = std::min(AimAssistState->FOV, AimAssistState->FOV * (AimAssistState->GetFOVScale() * AimAssistState->ZoomScale));
			float Radius = tanf(DEG2RAD(FOV) / 2) / tanf(DEG2RAD(GameFOV) / 2) * ScreenWidth;
			Renderer::DrawCircle(Canvas, Vector2D(ScreenWidth / 2, ScreenHeight / 2), Radius, 40, ImColor(Modules::Colors::FOVColor[0], Modules::Colors::FOVColor[1], Modules::Colors::FOVColor[2], Modules::Colors::FOVColor[3]), FOVThickness);
		}

		// Draw Filled FOV Circle
        if (DrawFilledFOVCircle && (!AimAssistState->AimbotMode == 1 || AimAssistState->AimbotMode == 2) && Myself->IsCombatReady())
		{
			float FOV = std::min(AimAssistState->FOV, AimAssistState->FOV * (AimAssistState->GetFOVScale() * AimAssistState->ZoomScale));
			float Radius = tanf(DEG2RAD(FOV) / 2) / tanf(DEG2RAD(GameFOV) / 2) * ScreenWidth;
			Renderer::DrawCircleFilled(Canvas, Vector2D(ScreenWidth / 2, ScreenHeight / 2), Radius, 40, ImColor(Modules::Colors::FilledFOVColor[0], Modules::Colors::FilledFOVColor[1], Modules::Colors::FilledFOVColor[2], Modules::Colors::FilledFOVColor[3]));
		}

		// Draw lot of things
		int PlayersNear = 0;
		for (int i = 0; i < Players->size(); i++)
		{
			Player *p = Players->at(i);





			if (!p->IsLocal && p->IsCombatReady() && p->DistanceToLocalPlayer < (Conversion::ToGameUnits(ESPMaxDistance)))
			{
				Vector2D LocalOriginW2S, HeadPositionW2S, HeadPositionSK;
				//bool bLocalOriginW2SValid = GameCamera->WorldToScreen(p->LocalOrigin, LocalOriginW2S);
				//bool bHeadPositionW2SValid = GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Head), HeadPositionW2S);
				
				
				Vector3D entFeet = p->LocalOrigin;//Memory::Read<Vector3D>(p->BasePointer + OFF_LOCAL_ORIGIN)
                                Vector3D entHead = p->GetBonePosition(HitboxType::Head);//entFeet; entHead.z += 35.f//p->GetBonePosition(HitboxType::Head);


                if(BoxType == 1){ entHead.z += 10.f; }

                                
                                GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Head), HeadPositionSK);

				bool bLocalOriginW2SValid = GameCamera->WorldToScreen(entFeet, LocalOriginW2S);
				bool bHeadPositionW2SValid = GameCamera->WorldToScreen(entHead, HeadPositionW2S);
				/*if(!bLocalOriginW2SValid)
				{
					std::cout << "bLocalOriginW2SValid = false" << std::endl;
				}*/
				/*if(!bHeadPositionW2SValid)
				{
					std::cout << "bHeadPositionW2SValid = false" << std::endl;
				}*/

				if (!VisibilityCheck)
				{ // Always shows esp
					PlayersNear++;


                    //if(aimline)
                    //{
                        //Vector3D DesiredAngles;
                        //Vector2D ppos;


                        //Vector3D localPos = Myself->CameraPosition;
                        //Vector3D entityPos = p->GetBonePosition(HitboxType::Head);

                        //float distance = localPos.Distance(entityPos);
                       // Vector3D ptrVelocity = p->AbsoluteVelocity;

                        //float bulletGravity = Myself->WeaponProjectileScale;
                        //float bulletSpeed = Myself->WeaponProjectileSpeed;
                        //long WeaponID = Myself->WeaponEntity;

                        //entityPos = Resolver::PredictPos(entityPos, ptrVelocity, distance, bulletSpeed, bulletGravity, WeaponID);

                        //GameCamera->WorldToScreen(entityPos, ppos);

                        //if (weapon.bullet_speed().value != 1.0f ) {
                        //    auto bullet_time = target_pos.distance(Myself->CameraPosition) / weapon.bullet_speed().value;
                        //    target_pos.z += 750.0f * weapon.bullet_scale().value * 0.5f * (bullet_time * bullet_time);
                        //    bullet_time = target_pos.distance(local_head) / weapon.bullet_speed().value;
                        //    target_pos += target.abs_velocity().value * bullet_time;
                        //}


                        //Renderer::DrawLine(Canvas, HeadPositionSK, ppos, 1.f, ImColor(255,0,0));
                    //}


					// Draw Info Bars
					if (HealthBar && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{
					
					ImColor ShieldColor;
						if (p->MaxShield == 50)
						{ // white
							ShieldColor = ImColor(247, 247, 247);
						}
						else if (p->MaxShield == 75)
						{ // blue
							ShieldColor = ImColor(39, 178, 255);
						}
						else if (p->MaxShield == 100)
						{ // purple
							ShieldColor = ImColor(206, 59, 255);
						}
						else if (p->MaxShield == 125)
						{ // red
							ShieldColor = ImColor(219, 2, 2);
						}
						else
						{
							ShieldColor = ImColor(247, 247, 247);
						}
				
				int curhealth = p->Health;
				int maxHealth = p->MaxHealth;
				int shield = p->Shield;
				int maxShield = p->MaxShield;

						if (p->IsHostile)
						{ 
						Vector2D Head, Foot;
				
                        Vector3D entFeet = p->LocalOrigin;//Memory::Read<Vector3D>(p->BasePointer + OFF_LOCAL_ORIGIN)
                        Vector3D entHead = p->GetBonePosition(HitboxType::Head);//entFeet; entHead.z += 35.f//p->GetBonePosition(HitboxType::Head);
                        entHead.z += 10.f;
                                
                        GameCamera->WorldToScreen(entHead, Head);
                        GameCamera->WorldToScreen(entFeet, Foot);

                        float height = Head.y - Foot.y;
                        float width = height / 2.f;
                        float width2 = width / 10;
                        if (width2 < 2.f) width2 = 2.;
                        if (width2 > 3) width2 = 3.;
                        Renderer::DrawProgressBar(Canvas, Foot.x - 3.5f + (width / 2) - width2, Foot.y, width2, Foot.y - Head.y, p->Health, 100, ImColor(0,255,0));
                        Renderer::DrawProgressBar(Canvas, Foot.x - 8.5f + (width / 2) - width2, Foot.y, width2, Foot.y - Head.y, p->Shield, p->MaxShield, ShieldColor);
						}

					}

					// Draw Health + Shield Text
					if (DrawStatus && bLocalOriginW2SValid)
					{
						std::stringstream healthValue, shieldValue, maxHealthValue, maxShieldValue;
						healthValue << p->Health;
						shieldValue << p->Shield;
						maxHealthValue << p->MaxHealth;
						maxShieldValue << p->MaxShield;
						std::string healthInt = healthValue.str() + " HP";
						std::string shieldInt = shieldValue.str() + " AP";
						const char *healthText = (char *)healthInt.c_str();
						const char *shieldText = (char *)shieldInt.c_str();
						std::string combinedHealth = healthValue.str() + " / " + maxHealthValue.str() + " HP";
						const char *combinedHealthText = combinedHealth.c_str();
						std::string combinedShield = shieldValue.str() + " / " + maxShieldValue.str() + " AP";
						const char *combinedShieldText = combinedShield.c_str();

						ImColor ShieldColor;
						if (p->MaxShield == 50)
						{ // white
							ShieldColor = ImColor(247, 247, 247);
						}
						else if (p->MaxShield == 75)
						{ // blue
							ShieldColor = ImColor(39, 178, 255);
						}
						else if (p->MaxShield == 100)
						{ // purple
							ShieldColor = ImColor(206, 59, 255);
						}
						else if (p->MaxShield == 125)
						{ // red
							ShieldColor = ImColor(219, 2, 2);
						}
						else
						{
							ShieldColor = ImColor(247, 247, 247);
						}

						// Render Text
						if (ShowTeam)
						{
							if (!ShowMaxStatusValues)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), healthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), shieldText, ShieldColor, true, true, false);
							}
							if (ShowMaxStatusValues)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), combinedHealthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), combinedShieldText, ShieldColor, true, true, false);
							}
						}
						if (!ShowTeam)
						{
							if (!ShowMaxStatusValues && p->IsHostile)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), healthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), shieldText, ShieldColor, true, true, false);
							}
							if (ShowMaxStatusValues && p->IsHostile)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), combinedHealthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), combinedShieldText, ShieldColor, true, true, false);
							}
						}
					}

					if (DrawTracers)
					{
						// Tracers
						Vector2D chestScreenPosition;
						if (Config::Sense::TracerBone == 0)
						{
							GameCamera->WorldToScreen(p->LocalOrigin.Add(Vector3D(0, 0, 66)), chestScreenPosition);
						}
						else if (Config::Sense::TracerBone == 1)
						{
							GameCamera->WorldToScreen(p->LocalOrigin.Add(Vector3D(0, 0, 0)), chestScreenPosition);
						}

						if (DrawTracers && Config::Sense::TracerPos == 0) // top to head
						{
							if (!chestScreenPosition.IsZeroVector())
							{
								int x = (int)(ScreenWidth * 0.5f);

								if (!ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
									if (p->IsHostile & !p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::InvisibleTracerColor[0], Modules::Colors::InvisibleTracerColor[1], Modules::Colors::InvisibleTracerColor[2], Modules::Colors::InvisibleTracerColor[3]));
									}
								}

								if (ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
									if (p->IsHostile & !p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::InvisibleTracerColor[0], Modules::Colors::InvisibleTracerColor[1], Modules::Colors::InvisibleTracerColor[2], Modules::Colors::InvisibleTracerColor[3]));
									}

									if (p->IsAlly)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
									}
								}
							}
						}

						else if (DrawTracers && Config::Sense::TracerPos == 1) // middle to bottom
						{
							if (!chestScreenPosition.IsZeroVector())
							{
								int x = (int)(ScreenWidth * 0.5f);

								if (!ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
									if (p->IsHostile & !p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::InvisibleTracerColor[0], Modules::Colors::InvisibleTracerColor[1], Modules::Colors::InvisibleTracerColor[2], Modules::Colors::InvisibleTracerColor[3]));
									}
								}

								if (ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
									if (p->IsHostile & !p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::InvisibleTracerColor[0], Modules::Colors::InvisibleTracerColor[1], Modules::Colors::InvisibleTracerColor[2], Modules::Colors::InvisibleTracerColor[3]));
									}

									if (p->IsAlly)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
									}
								}
							}
						}

						else if (DrawTracers && Config::Sense::TracerPos == 2) // bottom to bottom
						{
							if (!chestScreenPosition.IsZeroVector())
							{
								int x = (int)(ScreenWidth * 0.5f);

								if (!ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
									if (p->IsHostile & !p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::InvisibleTracerColor[0], Modules::Colors::InvisibleTracerColor[1], Modules::Colors::InvisibleTracerColor[2], Modules::Colors::InvisibleTracerColor[3]));
									}
								}

								if (ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
									if (p->IsHostile & !p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::InvisibleTracerColor[0], Modules::Colors::InvisibleTracerColor[1], Modules::Colors::InvisibleTracerColor[2], Modules::Colors::InvisibleTracerColor[3]));
									}

									if (p->IsAlly)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
									}
								}
							}
						}
					}

					// Show Legend
					if (ShowLegend)
					{
                    // float height = HeadPositionW2S.y - LocalOriginW2S.y;
                    // float width = height / 4.f;
                    // float x = (LocalOriginW2S.x + width) - (width * 2) + 4.f ;

                    //    if (p->IsHostile && p->IsVisible && bLocalOriginW2SValid && bHeadPositionW2SValid && !p->IsDummy())
                    //	{
                    //		Renderer::DrawText(Canvas, Vector2D(x, HeadPositionW2S.y - 2.5), p->getPlayerModelName().c_str(), ImColor(Modules::Colors::VisibleLegendColor[0], Modules::Colors::VisibleLegendColor[1], Modules::Colors::VisibleLegendColor[2], Modules::Colors::VisibleLegendColor[3]), true, false, false);
                    //	}
                    //	if (p->IsHostile && !p->IsVisible && bLocalOriginW2SValid && bHeadPositionW2SValid && !p->IsDummy())
                    //	{
                    //		Renderer::DrawText(Canvas, Vector2D(x, HeadPositionW2S.y - 2.5), p->getPlayerModelName().c_str(), ImColor(Modules::Colors::InvisibleLegendColor[0], Modules::Colors::InvisibleLegendColor[1], Modules::Colors::InvisibleLegendColor[2], Modules::Colors::InvisibleLegendColor[3]), true, false, false);
                    //	}



                        if (p->IsHostile && p->IsVisible && bLocalOriginW2SValid && bHeadPositionW2SValid && !p->IsDummy())
                        {
                            Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(2, 0)), p->getPlayerModelName().c_str(), ImColor(Modules::Colors::VisibleLegendColor[0], Modules::Colors::VisibleLegendColor[1], Modules::Colors::VisibleLegendColor[2], Modules::Colors::VisibleLegendColor[3]), false, true, false);
                        }
                        if (p->IsHostile && !p->IsVisible && bLocalOriginW2SValid && bHeadPositionW2SValid && !p->IsDummy())
                        {
                            Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(2, 0)), p->getPlayerModelName().c_str(), ImColor(Modules::Colors::InvisibleLegendColor[0], Modules::Colors::InvisibleLegendColor[1], Modules::Colors::InvisibleLegendColor[2], Modules::Colors::InvisibleLegendColor[3]), false, true, false);
                        }

					}

					// Distance
                    if (DrawDistance && bLocalOriginW2SValid && bHeadPositionW2SValid)
                    {
                        if(!DrawNames)
                        {

                            char buffer[256];
                            const char* dist = std::to_string((int)Conversion::ToMeters(p->DistanceToLocalPlayer)).c_str();
                            const char* txt = "[";
                            const char* txt2 = " M]";
                            strncpy(buffer, txt, sizeof(buffer));
                            strncat(buffer, dist, sizeof(buffer));
                            strncat(buffer, txt2, sizeof(buffer));

                            if (ShowTeam)
                            {
                                if (!LocalOriginW2S.IsZeroVector())
                                {
                                    if (p->IsAlly)
                                    {
                                        //Renderer::DrawText(Canvas, Vector2D(x, LocalOriginW2S.y - 10.0f), buffer, ImColor(255, 255, 255), true, false, false);
                                    }
                                    if (p->IsHostile  && !p->IsVisible)
                                    {
                                        Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), buffer, ImColor(Modules::Colors::InvisibleDistanceColor[0], Modules::Colors::InvisibleDistanceColor[1], Modules::Colors::InvisibleDistanceColor[2], Modules::Colors::InvisibleDistanceColor[3]), false, true, false);
                                    }
                                    if (p->IsHostile  && p->IsVisible)
                                    {
                                        Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), buffer, ImColor(Modules::Colors::VisibleDistanceColor[0], Modules::Colors::VisibleDistanceColor[1], Modules::Colors::VisibleDistanceColor[2], Modules::Colors::VisibleDistanceColor[3]), false, true, false);
                                    }
                                }
                            }
                            if (!ShowTeam)
                            {
                                if (!LocalOriginW2S.IsZeroVector())
                                {
                                    if (p->IsHostile && p->IsVisible)
                                        Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), buffer, ImColor(Modules::Colors::VisibleDistanceColor[0], Modules::Colors::VisibleDistanceColor[1], Modules::Colors::VisibleDistanceColor[2], Modules::Colors::VisibleDistanceColor[3]), false, true, false);
                                    if (p->IsHostile  && !p->IsVisible)
                                        Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), buffer, ImColor(Modules::Colors::InvisibleDistanceColor[0], Modules::Colors::InvisibleDistanceColor[1], Modules::Colors::InvisibleDistanceColor[2], Modules::Colors::InvisibleDistanceColor[3]), false, true, false);


                                }
                            }
                        }

                    }
					// Draw Names
                    if (DrawNames && bLocalOriginW2SValid && bHeadPositionW2SValid)
                    {

                        if(DrawDistance)
                        {
                            char disttxt[256];
                            std::string buf(p->GetPlayerName());

                            const char* txt = " [";
                            const char* dist = std::to_string((int)Conversion::ToMeters(p->DistanceToLocalPlayer)).c_str();
                            const char* txt2 = " M]";

                            strncpy(disttxt, txt, sizeof(disttxt));
                            strncat(disttxt, dist, sizeof(disttxt));
                            strncat(disttxt, txt2, sizeof(disttxt));

                            buf.append(disttxt);

                            const char* name = buf.c_str();


                            if (p->IsHostile && p->IsVisible && !p->IsDummy())
                            {
                                Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), name, ImColor(Modules::Colors::VisibleNameColor[0], Modules::Colors::VisibleNameColor[1], Modules::Colors::VisibleNameColor[2], Modules::Colors::VisibleNameColor[3]), false, true, false);
                            }
                            if (p->IsHostile && !p->IsVisible && !p->IsDummy())
                            {
                                Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), name, ImColor(Modules::Colors::InvisibleNameColor[0], Modules::Colors::InvisibleNameColor[1], Modules::Colors::InvisibleNameColor[2], Modules::Colors::InvisibleNameColor[3]), false, true, false);
                            }

                            // Draw Team Names
                            if (ShowTeam && TeamNames && p->IsAlly && !p->IsDummy())
                            {
                                Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), name, ImColor(Modules::Colors::TeamNameColor[0], Modules::Colors::TeamNameColor[1], Modules::Colors::TeamNameColor[2], Modules::Colors::TeamNameColor[3]), false, true, false);
                            }
                        }
                        else
                        {
                            if (p->IsHostile && p->IsVisible && !p->IsDummy())
                            {
                                Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), p->GetPlayerName().c_str(), ImColor(Modules::Colors::VisibleNameColor[0], Modules::Colors::VisibleNameColor[1], Modules::Colors::VisibleNameColor[2], Modules::Colors::VisibleNameColor[3]), false, true, false);
                            }
                            if (p->IsHostile && !p->IsVisible && !p->IsDummy())
                            {
                                Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), p->GetPlayerName().c_str(), ImColor(Modules::Colors::InvisibleNameColor[0], Modules::Colors::InvisibleNameColor[1], Modules::Colors::InvisibleNameColor[2], Modules::Colors::InvisibleNameColor[3]), false, true, false);
                            }

                            // Draw Team Names
                            if (ShowTeam && TeamNames && p->IsAlly && !p->IsDummy())
                            {
                                Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), p->GetPlayerName().c_str(), ImColor(Modules::Colors::TeamNameColor[0], Modules::Colors::TeamNameColor[1], Modules::Colors::TeamNameColor[2], Modules::Colors::TeamNameColor[3]), false, true, false);
                            }
                        }
                    }
					// Draw Weapon
                    if (DrawWeapon && bLocalOriginW2SValid && bHeadPositionW2SValid)
                    {
                        if (p->IsHostile)
                        {
                            int weaponHeldID;
                            weaponHeldID = p->WeaponIndex;
                            const char *weaponHeldText = "Unknown";

                            ImColor weaponHeldColor;
                            weaponHeldColor = ImColor(255, 255, 255);

                            if (DrawWeapon)
                            {
                                // Light Weapons
                                if (weaponHeldID == 106)
                                { // P2020
                                    weaponHeldText = "P2020";
                                    weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
                                }
                                if (weaponHeldID == 81)
                                { // RE-45
                                    weaponHeldText = "RE-45";
                                    weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
                                }
                                if (weaponHeldID == 80)
                                { // Alternator
                                    weaponHeldText = "Alternator";
                                    weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
                                }
                                if (weaponHeldID == 105)
                                { // R-99
                                    weaponHeldText = "R-99";
                                    weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
                                }
                                if (weaponHeldID == 0)
                                { // R-301
                                    weaponHeldText = "R-301";
                                    weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
                                }
                                if (weaponHeldID == 107)
                                { // Spitfire
                                    weaponHeldText = "Spitfire";
                                    weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
                                }
                                if (weaponHeldID == 90)
                                { // G7
                                    weaponHeldText = "G7 Scout";
                                    weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
                                }
                                // Heavy Weapons
                                if (weaponHeldID == 113)
                                { // CARSMG
                                    weaponHeldText = "CAR SMG";
                                    weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
                                }
                                if (weaponHeldID == 21)
                                { // Rampage
                                    weaponHeldText = "Rampage";
                                    weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
                                }
                                if (weaponHeldID == 112)
                                { // Repeater
                                    weaponHeldText = "Repeater";
                                    weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
                                }
                                if (weaponHeldID == 91)
                                { // Hemlock
                                    weaponHeldText = "Hemlock";
                                    weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
                                }
                                if (weaponHeldID == 89)
                                { // Flatline
                                    weaponHeldText = "Flatline";
                                    weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
                                }
                                // Energy Weapons
                                if (weaponHeldID == 114)
                                { // Nemesis
                                    weaponHeldText = "Nemesis";
                                    weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
                                }
                                if (weaponHeldID == 111)
                                { // Volt
                                    weaponHeldText = "Volt";
                                    weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
                                }
                                if (weaponHeldID == 108)
                                { // TripleTake
                                    weaponHeldText = "Triple Take";
                                    weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
                                }
                                if (weaponHeldID == 94)
                                { // LSTAR
                                    weaponHeldText = "L-STAR";
                                    weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
                                }
                                if (weaponHeldID == 84)
                                { // Devotion
                                    weaponHeldText = "Devotion";
                                    weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
                                }
                                if (weaponHeldID == 86)
                                { // Havoc
                                    weaponHeldText = "Havoc";
                                    weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
                                }
                                // Shotguns
                                if (weaponHeldID == 97)
                                { // Mozambique
                                    weaponHeldText = "Mozambique";
                                    weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
                                }
                                if (weaponHeldID == 88)
                                { // EVA8
                                    weaponHeldText = "EVA-8 Auto";
                                    weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
                                }
                                if (weaponHeldID == 104)
                                { // Peacekeeper
                                    weaponHeldText = "Peacekeeper";
                                    weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
                                }
                                if (weaponHeldID == 96)
                                { // Mastiff
                                    weaponHeldText = "Mastiff";
                                    weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
                                }
                                // Snipers
                                if (weaponHeldID == 1)
                                { // Sentinel
                                    weaponHeldText = "Sentinel";
                                    weaponHeldColor = ImColor(Modules::Colors::SniperWeaponColor[0], Modules::Colors::SniperWeaponColor[1], Modules::Colors::SniperWeaponColor[2], Modules::Colors::SniperWeaponColor[3]);
                                }
                                if (weaponHeldID == 83)
                                { // ChargeRifle
                                    weaponHeldText = "Charge Rifle";
                                    weaponHeldColor = ImColor(Modules::Colors::SniperWeaponColor[0], Modules::Colors::SniperWeaponColor[1], Modules::Colors::SniperWeaponColor[2], Modules::Colors::SniperWeaponColor[3]);
                                }
                                if (weaponHeldID == 85)
                                { // Longbow
                                    weaponHeldText = "Longbow";
                                    weaponHeldColor = ImColor(Modules::Colors::SniperWeaponColor[0], Modules::Colors::SniperWeaponColor[1], Modules::Colors::SniperWeaponColor[2], Modules::Colors::SniperWeaponColor[3]);
                                }
                                // Legendary Weapons
                                if (weaponHeldID == 110)
                                { // Wingman
                                    weaponHeldText = "Wingman";
                                    weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
                                }
                                if (weaponHeldID == 102)
                                { // Prowler
                                    weaponHeldText = "Prowler";
                                    weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
                                }
                                if (weaponHeldID == 2)
                                { // Bocek
                                    weaponHeldText = "Bocek";
                                    weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
                                }
                                if (weaponHeldID == 92)
                                { // Kraber
                                    weaponHeldText = "Kraber";
                                    weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
                                }
                                if (weaponHeldID == 166)
                                { // Knife
                                    weaponHeldText = "Throwing Knife";
                                    weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
                                }
                                /*if (weaponHeldID == 3) { //BusterSword
                                    weaponHeldText = "Buster Sword";
                                    weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
                                }*/
                                // Melee & Grenade
                                if (weaponHeldID == 224) { //Thermite Grenade
                                    weaponHeldText = "Thermite Grenade";
                                    weaponHeldColor = ImColor(Modules::Colors::ThrowableWeaponColor[0], Modules::Colors::ThrowableWeaponColor[1], Modules::Colors::ThrowableWeaponColor[2], Modules::Colors::ThrowableWeaponColor[3]);;
                                }
                                if (p->IsHoldingGrenade)
                                {
                                    weaponHeldText = "Throwable";
                                    weaponHeldColor = ImColor(Modules::Colors::ThrowableWeaponColor[0], Modules::Colors::ThrowableWeaponColor[1], Modules::Colors::ThrowableWeaponColor[2], Modules::Colors::ThrowableWeaponColor[3]);
                                }
                                if (weaponHeldID == 115)
                                { // Melee
                                    weaponHeldText = "Melee";
                                    weaponHeldColor = ImColor(Modules::Colors::MeleeWeaponColor[0], Modules::Colors::MeleeWeaponColor[1], Modules::Colors::MeleeWeaponColor[2], Modules::Colors::MeleeWeaponColor[3]);
                                }
                            }

                            //float height = HeadPositionW2S.y - LocalOriginW2S.y;
                            //float width = height / 4.f;
                            //float width2 = height / 2.0f;
                            //float x = (LocalOriginW2S.x + width) - (width * 2) + 4.f;




                            if (Modules::Colors::WeaponColorMode == 1)
                            { // Changes color to ammo type
                                if (p->IsHostile)
                                {
                                    if (DrawWeapon && DrawStatus)
                                    {
                                        Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 10)), weaponHeldText, ImColor(weaponHeldColor), true, true, false);
                                    }

                                    if (DrawWeapon && !DrawStatus)
                                    {
                                        Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), weaponHeldText, ImColor(weaponHeldColor), true, true, false);
                                    }
                                }
                            }
                            if (Modules::Colors::WeaponColorMode == 0)
                            { // Single Color
                                if (p->IsHostile && p->IsVisible)
                                {
                                    if (DrawWeapon && ShowLegend)
                                    {
                                        Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 10)), weaponHeldText, ImColor(Modules::Colors::VisibleWeaponColor[0], Modules::Colors::VisibleWeaponColor[1], Modules::Colors::VisibleWeaponColor[2], Modules::Colors::VisibleWeaponColor[3]), false, true, false);
                                    }

                                    if (DrawWeapon && !ShowLegend)
                                    {
                                        Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), weaponHeldText, ImColor(Modules::Colors::VisibleWeaponColor[0], Modules::Colors::VisibleWeaponColor[1], Modules::Colors::VisibleWeaponColor[2], Modules::Colors::VisibleWeaponColor[3]), false, true, false);
                                    }
                                }
                                if (p->IsHostile && !p->IsVisible)
                                {
                                    if (DrawWeapon && ShowLegend)
                                    {
                                        Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 10)), weaponHeldText, ImColor(Modules::Colors::InvisibleWeaponColor[0], Modules::Colors::InvisibleWeaponColor[1], Modules::Colors::InvisibleWeaponColor[2], Modules::Colors::InvisibleWeaponColor[3]), false, true, false);
                                    }

                                    if (DrawWeapon && !ShowLegend)
                                    {
                                        Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), weaponHeldText, ImColor(Modules::Colors::InvisibleWeaponColor[0], Modules::Colors::InvisibleWeaponColor[1], Modules::Colors::InvisibleWeaponColor[2], Modules::Colors::InvisibleWeaponColor[3]), false, true, false);
                                    }
                                }
                            }
                        }
                    }

					/*bool TestWeaponID = false; //For finding weapon IDs (Used for finding melee ID)
					if (TestWeaponID && bLocalOriginW2SValid && bHeadPositionW2SValid) {
						if (p->IsHostile) {
							std::stringstream wepID;
							wepID << p->WeaponIndex;
							std::string wepInt = wepID.str() + " ";
							const char* wepText = (char*)wepInt.c_str();

							ImColor weaponWHeldColor;
							weaponWHeldColor = ImColor(255, 255, 255);

							Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), wepText, ImColor(weaponWHeldColor), true, true, false);
						}
					}*/

					// Draw Boxes (2D & 2D Filled)
					if (DrawBoxes && bLocalOriginW2SValid && bHeadPositionW2SValid && p->DistanceToLocalPlayer < (Conversion::ToGameUnits(ESPMaxDistance)))
					{
						if (!ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::VisibleBoxColor[0], Modules::Colors::VisibleBoxColor[1], Modules::Colors::VisibleBoxColor[2], Modules::Colors::VisibleBoxColor[3]), ImColor(Modules::Colors::VisibleFilledBoxColor[0], Modules::Colors::VisibleFilledBoxColor[1], Modules::Colors::VisibleFilledBoxColor[2], Modules::Colors::VisibleFilledBoxColor[3]), BoxThickness);
							}
							if (p->IsHostile && !p->IsVisible)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::InvisibleBoxColor[0], Modules::Colors::InvisibleBoxColor[1], Modules::Colors::InvisibleBoxColor[2], Modules::Colors::InvisibleBoxColor[3]), ImColor(Modules::Colors::InvisibleFilledBoxColor[0], Modules::Colors::InvisibleFilledBoxColor[1], Modules::Colors::InvisibleFilledBoxColor[2], Modules::Colors::InvisibleFilledBoxColor[3]), BoxThickness);
							}
						}
						if (ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::VisibleBoxColor[0], Modules::Colors::VisibleBoxColor[1], Modules::Colors::VisibleBoxColor[2], Modules::Colors::VisibleBoxColor[3]), ImColor(Modules::Colors::VisibleFilledBoxColor[0], Modules::Colors::VisibleFilledBoxColor[1], Modules::Colors::VisibleFilledBoxColor[2], Modules::Colors::VisibleFilledBoxColor[3]), BoxThickness);
							}
							if (p->IsHostile && !p->IsVisible)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::InvisibleBoxColor[0], Modules::Colors::InvisibleBoxColor[1], Modules::Colors::InvisibleBoxColor[2], Modules::Colors::InvisibleBoxColor[3]), ImColor(Modules::Colors::InvisibleFilledBoxColor[0], Modules::Colors::InvisibleFilledBoxColor[1], Modules::Colors::InvisibleFilledBoxColor[2], Modules::Colors::InvisibleFilledBoxColor[3]), BoxThickness);
							}
							if (p->IsAlly)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]), ImColor(Modules::Colors::VisibleFilledBoxColor[0], Modules::Colors::VisibleFilledBoxColor[1], Modules::Colors::VisibleFilledBoxColor[2], Modules::Colors::VisibleFilledBoxColor[3]), BoxThickness);
							}
							
						}
					}

					if (drawlvl && p->IsHostile)
                    {
                    if(p->IsDummy()) continue;


                    char buffer[256];
                    std::string lvl = std::to_string(p->GetPlayerLevel());
                    const char* lvltxt = lvl.c_str();
                    const char* txt = "[LvL: ";
                    const char* txt2 = "]";

                    strncpy(buffer, txt, sizeof(buffer));
                    strncat(buffer, lvltxt, sizeof(buffer));
                    strncat(buffer, txt2, sizeof(buffer));

                    float height = HeadPositionW2S.y - LocalOriginW2S.y;
                    float width = height / 4.f;
                    float y = LocalOriginW2S.y + (height / 2) - 6;
                    float x = (LocalOriginW2S.x + width) - (width * 2) + 4.f;
                    //Vector2D(LocalOriginW2S.x, LocalOriginW2S.y +2.f) Vector2D(x, HeadPositionW2S.y - 3.f)
                    Renderer::DrawText(Canvas, Vector2D(x, y), buffer, ImColor(255,255,255), false, false, false);


                    }
		

					// Draw Skeleton
					if (Skeleton && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{

						Vector2D Head, Neck, UpperChest, LowerChest, Stomach, Leftshoulder, Leftelbow, LeftHand, Rightshoulder, RightelbowBone, RightHand, LeftThighs, Leftknees, Leftleg, RightThighs, Rightknees, Rightleg;
						//Head bone is HeadPositionW2S
						Vector3D HeadPos = p->GetBonePosition(HitboxType::Head);
                        HeadPos.z += 3.f;
						GameCamera->WorldToScreen(HeadPos, Head);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Neck), Neck);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::UpperChest), UpperChest);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::LowerChest), LowerChest);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Stomach), Stomach);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftshoulder), Leftshoulder);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftelbow), Leftelbow);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::LeftHand), LeftHand);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Rightshoulder), Rightshoulder);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::RightelbowBone), RightelbowBone);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::RightHand), RightHand);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::LeftThighs), LeftThighs);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftknees), Leftknees);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftleg), Leftleg);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::RightThighs), RightThighs);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Rightknees), Rightknees);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Rightleg), Rightleg);

						if (!ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
							
                                Renderer::DrawCircle(Canvas, Head, 3650 / p->DistanceToLocalPlayer, 255, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]), 1.f);

                                Renderer::DrawLine(Canvas, HeadPositionSK, Neck, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
							}
							if (p->IsHostile && !p->IsVisible)
							{
                                Renderer::DrawCircle(Canvas, Head, 3650 / p->DistanceToLocalPlayer, 255, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]), 1.f);

                                Renderer::DrawLine(Canvas, HeadPositionSK, Neck, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
							}
						}

						if (ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
                                Renderer::DrawCircle(Canvas, Head, 3650 / p->DistanceToLocalPlayer, 255, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]), 1.f);

                                Renderer::DrawLine(Canvas, HeadPositionSK, Neck, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
							}
							if (p->IsHostile && !p->IsVisible)
							{
                                Renderer::DrawCircle(Canvas, Head, 3650 / p->DistanceToLocalPlayer, 255, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]), 1.f);

                                Renderer::DrawLine(Canvas, HeadPositionSK, Neck, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::InvisibleSkeletonColor[0], Modules::Colors::InvisibleSkeletonColor[1], Modules::Colors::InvisibleSkeletonColor[2], Modules::Colors::InvisibleSkeletonColor[3]));
							}

							if (p->IsAlly)
							{
                                Renderer::DrawCircle(Canvas, Head, 3650 / p->DistanceToLocalPlayer, 255, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]), 1.f);
							
								Renderer::DrawLine(Canvas, HeadPositionSK, Neck, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
							}
						}
					}

					// Seer
					if (DrawSeer && p->IsHostile && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{
						if (!HeadPositionW2S.IsZeroVector())
							Renderer::DrawSeer(Canvas, HeadPositionW2S.x, HeadPositionW2S.y - 20, p->Shield, p->MaxShield, p->Health);
					}

					// Show Near
					if (ShowNear)
					{
						// Gui DrawText Version
						Renderer::DrawText(Canvas, Vector2D(ScreenWidth * 0.5, ScreenHeight * 0.6), ("NEAR : " + std::to_string(PlayersNear)).c_str(), ImColor(Modules::Colors::NearColor[0], Modules::Colors::NearColor[1], Modules::Colors::NearColor[2], Modules::Colors::NearColor[3]), true, true, false);
					}
					PlayersNear = 0;
				}
				else //Visible Check = true
				{
					PlayersNear++;

					// Draw Info Bars
					if (HealthBar && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{
					int health = p->Health;
						int maxHealth = p->MaxHealth;
						int shield = p->Shield;
						int maxShield = p->MaxShield;

						if (p->IsHostile && p->IsVisible)
						{
							Renderer::Draw2DBar(Canvas, BarMode, BarStyle, Modules::Sense::BarColorMode, Modules::Sense::BarBackground, LocalOriginW2S, HeadPositionW2S, health, maxHealth, shield, maxShield, BarThickness, BarThickness2, BarWidth, BarHeight, ImColor(Modules::Colors::BarBGColor[0], Modules::Colors::BarBGColor[1], Modules::Colors::BarBGColor[2], Modules::Colors::BarBGColor[3]));
						}
					}
					
					

					// Draw Health + Shield Text
					if (DrawStatus && bLocalOriginW2SValid)
					{
						std::stringstream healthValue, shieldValue, maxHealthValue, maxShieldValue;
						healthValue << p->Health;
						shieldValue << p->Shield;
						maxHealthValue << p->MaxHealth;
						maxShieldValue << p->MaxShield;
						std::string healthInt = healthValue.str() + " HP";
						std::string shieldInt = shieldValue.str() + " AP";
						const char *healthText = (char *)healthInt.c_str();
						const char *shieldText = (char *)shieldInt.c_str();
						std::string combinedHealth = healthValue.str() + " / " + maxHealthValue.str() + " HP";
						const char *combinedHealthText = combinedHealth.c_str();
						std::string combinedShield = shieldValue.str() + " / " + maxShieldValue.str() + " AP";
						const char *combinedShieldText = combinedShield.c_str();

						ImColor ShieldColor;
						if (p->MaxShield == 50)
						{ // white
							ShieldColor = ImColor(247, 247, 247);
						}
						else if (p->MaxShield == 75)
						{ // blue
							ShieldColor = ImColor(39, 178, 255);
						}
						else if (p->MaxShield == 100)
						{ // purple
							ShieldColor = ImColor(206, 59, 255);
						}
						else if (p->MaxShield == 125)
						{ // red
							ShieldColor = ImColor(219, 2, 2);
						}
						else
						{
							ShieldColor = ImColor(247, 247, 247);
						}

						// Render Text
						if (ShowTeam)
						{
							if (!ShowMaxStatusValues)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), healthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), shieldText, ShieldColor, true, true, false);
							}
							if (ShowMaxStatusValues)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), combinedHealthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), combinedShieldText, ShieldColor, true, true, false);
							}
						}
						if (!ShowTeam)
						{
							if (!ShowMaxStatusValues && p->IsHostile && p->IsVisible)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), healthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), shieldText, ShieldColor, true, true, false);
							}
							if (ShowMaxStatusValues && p->IsHostile && p->IsVisible)
							{
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), combinedHealthText, ImColor(0, 255, 0), true, true, false);
								Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0 + 10)), combinedShieldText, ShieldColor, true, true, false);
							}
						}
					}

					if (DrawTracers)
					{
						// Tracers
						Vector2D chestScreenPosition;
						if (Config::Sense::TracerBone == 0)
						{
							GameCamera->WorldToScreen(p->LocalOrigin.Add(Vector3D(0, 0, 66)), chestScreenPosition);
						}
						else if (Config::Sense::TracerBone == 1)
						{
							GameCamera->WorldToScreen(p->LocalOrigin.Add(Vector3D(0, 0, 0)), chestScreenPosition);
						}

						if (DrawTracers && Config::Sense::TracerPos == 0) // top to head
						{
							if (!chestScreenPosition.IsZeroVector())
							{
								int x = (int)(ScreenWidth * 0.5f);

								if (!ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
								}

								if (ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}

									if (p->IsAlly && p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight - ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
									}
								}
							}
						}

						else if (DrawTracers && Config::Sense::TracerPos == 1) // middle to bottom
						{
							if (!chestScreenPosition.IsZeroVector())
							{
								int x = (int)(ScreenWidth * 0.5f);

								if (!ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
								}

								if (ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}

									if (p->IsAlly && p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight / 2), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
									}
								}
							}
						}

						else if (DrawTracers && Config::Sense::TracerPos == 2) // bottom to bottom
						{
							if (!chestScreenPosition.IsZeroVector())
							{
								int x = (int)(ScreenWidth * 0.5f);

								if (!ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}
								}

								if (ShowTeam)
								{
									if (p->IsHostile & p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::VisibleTracerColor[0], Modules::Colors::VisibleTracerColor[1], Modules::Colors::VisibleTracerColor[2], Modules::Colors::VisibleTracerColor[3]));
									}

									if (p->IsAlly && p->IsVisible)
									{
										Renderer::DrawLine(Canvas, Vector2D(x, ScreenHeight), chestScreenPosition, TracerThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
									}
								}
							}
						}
					}

					// Show Legend
					if (ShowLegend)
					{
						if (p->IsHostile && p->IsVisible && bLocalOriginW2SValid && bHeadPositionW2SValid && !p->IsDummy())
						{
							Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), p->getPlayerModelName().c_str(), ImColor(Modules::Colors::VisibleLegendColor[0], Modules::Colors::VisibleLegendColor[1], Modules::Colors::VisibleLegendColor[2], Modules::Colors::VisibleLegendColor[3]), true, true, false);
						}
					}

					// Distance
					if (DrawDistance && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{
						if (ShowTeam)
						{
							if (!HeadPositionW2S.IsZeroVector())
							{
								if (p->IsAlly && p->IsVisible)
								{
									//Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), std::to_string((int)Conversion::ToMeters(p->DistanceToLocalPlayer)).c_str(), ImColor(255, 255, 255), true, true, false);
								}
								if (p->IsHostile && p->IsVisible)
								{
                                    Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), std::to_string((int)Conversion::ToMeters(p->DistanceToLocalPlayer)).c_str(), ImColor(Modules::Colors::VisibleDistanceColor[0], Modules::Colors::VisibleDistanceColor[1], Modules::Colors::VisibleDistanceColor[2], Modules::Colors::VisibleDistanceColor[3]), true, true, false);
								}
							}
						}
						if (!ShowTeam)
						{
							if (!HeadPositionW2S.IsZeroVector())
							{
								if (p->IsHostile && p->IsVisible)
								{
                                    Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), std::to_string((int)Conversion::ToMeters(p->DistanceToLocalPlayer)).c_str(), ImColor(Modules::Colors::VisibleDistanceColor[0], Modules::Colors::VisibleDistanceColor[1], Modules::Colors::VisibleDistanceColor[2], Modules::Colors::VisibleDistanceColor[3]), true, true, false);
								}
							}
						}
					}

					// Draw Names
					if (DrawNames && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{
						if (p->IsHostile && p->IsVisible && !p->IsDummy())
						{
							Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), p->GetPlayerName().c_str(), ImColor(Modules::Colors::VisibleNameColor[0], Modules::Colors::VisibleNameColor[1], Modules::Colors::VisibleNameColor[2], Modules::Colors::VisibleNameColor[3]), true, true, false);
						}

						// Draw Team Names
						if (ShowTeam && TeamNames && p->IsAlly && p->IsVisible && !p->IsDummy())
						{
							Renderer::DrawText(Canvas, HeadPositionW2S.Subtract(Vector2D(0, 12)), p->GetPlayerName().c_str(), ImColor(Modules::Colors::TeamNameColor[0], Modules::Colors::TeamNameColor[1], Modules::Colors::TeamNameColor[2], Modules::Colors::TeamNameColor[3]), true, true, false);
						}
					}

					// Draw Weapon
					if (DrawWeapon && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{
						if (p->IsHostile)
						{
							int weaponHeldID;
							weaponHeldID = p->WeaponIndex;
							const char *weaponHeldText = "Unknown";

							ImColor weaponHeldColor;
							weaponHeldColor = ImColor(255, 255, 255);

							if (DrawWeapon)
							{
								// Light Weapons
								if (weaponHeldID == 106)
								{ // P2020
									weaponHeldText = "P2020";
									weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
								}
								if (weaponHeldID == 81)
								{ // RE-45
									weaponHeldText = "RE-45";
									weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
								}
								if (weaponHeldID == 80)
								{ // Alternator
									weaponHeldText = "Alternator";
									weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
								}
								if (weaponHeldID == 105)
								{ // R-99
									weaponHeldText = "R-99";
									weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
								}
								if (weaponHeldID == 0)
								{ // R-301
									weaponHeldText = "R-301";
									weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
								}
								if (weaponHeldID == 107)
								{ // Spitfire
									weaponHeldText = "Spitfire";
									weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
								}
								if (weaponHeldID == 90)
								{ // G7
									weaponHeldText = "G7 Scout";
									weaponHeldColor = ImColor(Modules::Colors::LightWeaponColor[0], Modules::Colors::LightWeaponColor[1], Modules::Colors::LightWeaponColor[2], Modules::Colors::LightWeaponColor[3]);
								}
								// Heavy Weapons
								if (weaponHeldID == 113)
								{ // CARSMG
									weaponHeldText = "CAR SMG";
									weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
								}
								if (weaponHeldID == 21)
								{ // Rampage
									weaponHeldText = "Rampage";
									weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
								}
								if (weaponHeldID == 112)
								{ // Repeater
									weaponHeldText = "Repeater";
									weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
								}
								if (weaponHeldID == 91)
								{ // Hemlock
									weaponHeldText = "Hemlock";
									weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
								}
								if (weaponHeldID == 89)
								{ // Flatline
									weaponHeldText = "Flatline";
									weaponHeldColor = ImColor(Modules::Colors::HeavyWeaponColor[0], Modules::Colors::HeavyWeaponColor[1], Modules::Colors::HeavyWeaponColor[2], Modules::Colors::HeavyWeaponColor[3]);
								}
								// Energy Weapons
								if (weaponHeldID == 114)
								{ // Nemesis
									weaponHeldText = "Nemesis";
									weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
								}
								if (weaponHeldID == 111)
								{ // Volt
									weaponHeldText = "Volt";
									weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
								}
								if (weaponHeldID == 108)
								{ // TripleTake
									weaponHeldText = "Triple Take";
									weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
								}
								if (weaponHeldID == 94)
								{ // LSTAR
									weaponHeldText = "L-STAR";
									weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
								}
								if (weaponHeldID == 84)
								{ // Devotion
									weaponHeldText = "Devotion";
									weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
								}
								if (weaponHeldID == 86)
								{ // Havoc
									weaponHeldText = "Havoc";
									weaponHeldColor = ImColor(Modules::Colors::EnergyWeaponColor[0], Modules::Colors::EnergyWeaponColor[1], Modules::Colors::EnergyWeaponColor[2], Modules::Colors::EnergyWeaponColor[3]);
								}
								// Shotguns
								if (weaponHeldID == 97)
								{ // Mozambique
									weaponHeldText = "Mozambique";
									weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
								}
								if (weaponHeldID == 88)
								{ // EVA8
									weaponHeldText = "EVA-8 Auto";
									weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
								}
								if (weaponHeldID == 104)
								{ // Peacekeeper
									weaponHeldText = "Peacekeeper";
									weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
								}
								if (weaponHeldID == 96)
								{ // Mastiff
									weaponHeldText = "Mastiff";
									weaponHeldColor = ImColor(Modules::Colors::ShotgunWeaponColor[0], Modules::Colors::ShotgunWeaponColor[1], Modules::Colors::ShotgunWeaponColor[2], Modules::Colors::ShotgunWeaponColor[3]);
								}
								// Snipers
								if (weaponHeldID == 1)
								{ // Sentinel
									weaponHeldText = "Sentinel";
									weaponHeldColor = ImColor(Modules::Colors::SniperWeaponColor[0], Modules::Colors::SniperWeaponColor[1], Modules::Colors::SniperWeaponColor[2], Modules::Colors::SniperWeaponColor[3]);
								}
								if (weaponHeldID == 83)
								{ // ChargeRifle
									weaponHeldText = "Charge Rifle";
									weaponHeldColor = ImColor(Modules::Colors::SniperWeaponColor[0], Modules::Colors::SniperWeaponColor[1], Modules::Colors::SniperWeaponColor[2], Modules::Colors::SniperWeaponColor[3]);
								}
								if (weaponHeldID == 85)
								{ // Longbow
									weaponHeldText = "Longbow";
									weaponHeldColor = ImColor(Modules::Colors::SniperWeaponColor[0], Modules::Colors::SniperWeaponColor[1], Modules::Colors::SniperWeaponColor[2], Modules::Colors::SniperWeaponColor[3]);
								}
								// Legendary Weapons
								if (weaponHeldID == 110)
								{ // Wingman
									weaponHeldText = "Wingman";
									weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
								}
								if (weaponHeldID == 102)
								{ // Prowler
									weaponHeldText = "Prowler";
									weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
								}
								if (weaponHeldID == 2)
								{ // Bocek
									weaponHeldText = "Bocek";
									weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
								}
								if (weaponHeldID == 92)
								{ // Kraber
									weaponHeldText = "Kraber";
									weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
								}
								if (weaponHeldID == 166)
								{ // Knife
									weaponHeldText = "Throwing Knife";
									weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
								}
								/*if (weaponHeldID == 3) { //BusterSword
									weaponHeldText = "Buster Sword";
									weaponHeldColor = ImColor(Modules::Colors::LegendaryWeaponColor[0], Modules::Colors::LegendaryWeaponColor[1], Modules::Colors::LegendaryWeaponColor[2], Modules::Colors::LegendaryWeaponColor[3]);
								}*/
								// Melee & Grenade
								/*if (weaponHeldID == 213) { //Thermite Grenade
									weaponHeldText = "Thermite Grenade";
									weaponHeldColor = ThrowableWeaponColor;
								}*/
								if (p->IsHoldingGrenade)
								{
									weaponHeldText = "Throwable";
									weaponHeldColor = ImColor(Modules::Colors::ThrowableWeaponColor[0], Modules::Colors::ThrowableWeaponColor[1], Modules::Colors::ThrowableWeaponColor[2], Modules::Colors::ThrowableWeaponColor[3]);
								}
								if (weaponHeldID == 115)
								{ // Melee
									weaponHeldText = "Melee";
									weaponHeldColor = ImColor(Modules::Colors::MeleeWeaponColor[0], Modules::Colors::MeleeWeaponColor[1], Modules::Colors::MeleeWeaponColor[2], Modules::Colors::MeleeWeaponColor[3]);
								}
							}

							if (Modules::Colors::WeaponColorMode == 1)
							{ // Changes color to ammo type
								if (p->IsHostile && p->IsVisible)
								{
									if (DrawWeapon && DrawStatus)
									{
										Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 20)), weaponHeldText, ImColor(weaponHeldColor), true, true, false);
									}

									if (DrawWeapon && !DrawStatus)
									{
										Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), weaponHeldText, ImColor(weaponHeldColor), true, true, false);
									}
								}
							}
							if (Modules::Colors::WeaponColorMode == 0)
							{ // Single Color
								if (p->IsHostile && p->IsVisible)
								{
									if (DrawWeapon && DrawStatus)
									{
										Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 20)), weaponHeldText, ImColor(Modules::Colors::VisibleWeaponColor[0], Modules::Colors::VisibleWeaponColor[1], Modules::Colors::VisibleWeaponColor[2], Modules::Colors::VisibleWeaponColor[3]), true, true, false);
									}

									if (DrawWeapon && !DrawStatus)
									{
										Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), weaponHeldText, ImColor(Modules::Colors::VisibleWeaponColor[0], Modules::Colors::VisibleWeaponColor[1], Modules::Colors::VisibleWeaponColor[2], Modules::Colors::VisibleWeaponColor[3]), true, true, false);
									}
								}
							}
						}
					}

					/*bool TestWeaponID = false; //For finding weapon IDs (Used for finding melee ID)
					if (TestWeaponID && bLocalOriginW2SValid && bHeadPositionW2SValid) {
						if (p->IsHostile) {
							std::stringstream wepID;
							wepID << p->WeaponIndex;
							std::string wepInt = wepID.str() + " ";
							const char* wepText = (char*)wepInt.c_str();

							ImColor weaponWHeldColor;
							weaponWHeldColor = ImColor(255, 255, 255);

							Renderer::DrawText(Canvas, LocalOriginW2S.Add(Vector2D(0, 0)), wepText, ImColor(weaponWHeldColor), true, true, false);
						}
					}*/

					// Draw Boxes (2D & 2D Filled)
					if (DrawBoxes && bLocalOriginW2SValid && bHeadPositionW2SValid && p->DistanceToLocalPlayer < (Conversion::ToGameUnits(ESPMaxDistance)))
					{
						if (!ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::VisibleBoxColor[0], Modules::Colors::VisibleBoxColor[1], Modules::Colors::VisibleBoxColor[2], Modules::Colors::VisibleBoxColor[3]), ImColor(Modules::Colors::VisibleFilledBoxColor[0], Modules::Colors::VisibleFilledBoxColor[1], Modules::Colors::VisibleFilledBoxColor[2], Modules::Colors::VisibleFilledBoxColor[3]), BoxThickness);
							}
						}
						if (ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::VisibleBoxColor[0], Modules::Colors::VisibleBoxColor[1], Modules::Colors::VisibleBoxColor[2], Modules::Colors::VisibleBoxColor[3]), ImColor(Modules::Colors::VisibleFilledBoxColor[0], Modules::Colors::VisibleFilledBoxColor[1], Modules::Colors::VisibleFilledBoxColor[2], Modules::Colors::VisibleFilledBoxColor[3]), BoxThickness);
							}
							if (p->IsAlly && p->IsVisible)
							{
								Renderer::Draw2DBox(Canvas, BoxType, BoxStyle, LocalOriginW2S, HeadPositionW2S, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]), ImColor(Modules::Colors::VisibleFilledBoxColor[0], Modules::Colors::VisibleFilledBoxColor[1], Modules::Colors::VisibleFilledBoxColor[2], Modules::Colors::VisibleFilledBoxColor[3]), BoxThickness);
							}
						}
					}

					// Draw Skeleton
					if (Skeleton && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{

						Vector2D Neck, UpperChest, LowerChest, Stomach, Leftshoulder, Leftelbow, LeftHand, Rightshoulder, RightelbowBone, RightHand, LeftThighs, Leftknees, Leftleg, RightThighs, Rightknees, Rightleg;
						//Head bone is HeadPositionW2S
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Neck), Neck);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::UpperChest), UpperChest);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::LowerChest), LowerChest);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Stomach), Stomach);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftshoulder), Leftshoulder);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftelbow), Leftelbow);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::LeftHand), LeftHand);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Rightshoulder), Rightshoulder);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::RightelbowBone), RightelbowBone);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::RightHand), RightHand);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::LeftThighs), LeftThighs);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftknees), Leftknees);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Leftleg), Leftleg);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::RightThighs), RightThighs);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Rightknees), Rightknees);
						GameCamera->WorldToScreen(p->GetBonePosition(HitboxType::Rightleg), Rightleg);

						if (!ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
								Renderer::DrawLine(Canvas, HeadPositionW2S, Neck, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
							}
						}

						if (ShowTeam)
						{
							if (p->IsHostile && p->IsVisible)
							{
								Renderer::DrawLine(Canvas, HeadPositionW2S, Neck, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::VisibleSkeletonColor[0], Modules::Colors::VisibleSkeletonColor[1], Modules::Colors::VisibleSkeletonColor[2], Modules::Colors::VisibleSkeletonColor[3]));
							}

							if (p->IsAlly && p->IsVisible)
							{
								Renderer::DrawLine(Canvas, HeadPositionW2S, Neck, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Neck, UpperChest, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, UpperChest, LowerChest, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, LowerChest, Stomach, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Neck, Leftshoulder, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Leftshoulder, Leftelbow, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Leftelbow, LeftHand, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Neck, Rightshoulder, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Rightshoulder, RightelbowBone, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, RightelbowBone, RightHand, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Stomach, LeftThighs, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, LeftThighs, Leftknees, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Leftknees, Leftleg, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Stomach, RightThighs, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, RightThighs, Rightknees, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
								Renderer::DrawLine(Canvas, Rightknees, Rightleg, SkeletonThickness, ImColor(Modules::Colors::TeamColor[0], Modules::Colors::TeamColor[1], Modules::Colors::TeamColor[2], Modules::Colors::TeamColor[3]));
							}
						}
					}

					// Seer
					if (DrawSeer && p->IsHostile && p->IsVisible && bLocalOriginW2SValid && bHeadPositionW2SValid)
					{
						if (!HeadPositionW2S.IsZeroVector())
							Renderer::DrawSeer(Canvas, HeadPositionW2S.x, HeadPositionW2S.y - 20, p->Shield, p->MaxShield, p->Health);
					}

					// Show Near
					if (ShowNear)
					{
						// Gui DrawText Version
						Renderer::DrawText(Canvas, Vector2D(ScreenWidth * 0.5, ScreenHeight * 0.6), ("NEAR : " + std::to_string(PlayersNear)).c_str(), ImColor(Modules::Colors::NearColor[0], Modules::Colors::NearColor[1], Modules::Colors::NearColor[2], Modules::Colors::NearColor[3]), true, true, false);
					}
					PlayersNear = 0;
				}
			}
		}
	}
};
