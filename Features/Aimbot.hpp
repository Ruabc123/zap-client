#pragma once
#include <iostream>
#include <vector>
#include "../Core/Player.hpp"
#include "../Core/LocalPlayer.hpp"
#include "../Core/Offsets.hpp"
#include "../Core/Level.hpp"


#include "../Math/Vector2D.hpp"
#include "../Math/Vector3D.hpp"
#include "../Math/QAngle.hpp"
#include "../Math/Resolver.hpp"

#include "../Utils/Memory.hpp"
#include "../Utils/XDisplay.hpp"
#include "../Utils/Conversion.hpp"
#include "../Utils/Config.hpp"
#include "../Utils/Modules.hpp"
#include "../Utils/HitboxType.hpp"
#include "../Utils/InputManager.hpp"
#include "../Utils/InputTypes.hpp"
#include "../Utils/Weapons.hpp"

// UI //
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
//#include "RCS.hpp"

// Conversion
#define DEG2RAD( x  )  ( (float)(x) * (float)(M_PI / 180.f) )


struct Aimbot {
    bool AimbotEnabled = true;

    int AimbotMode = 0;


    float PitchP = 100;
    float YawP = 100;
    bool RCSEnabled = true;

    bool ClosestHitbox = false;
    bool OnFire = true;
    bool OnADS = true;
    bool VisCheck = true;
    bool TeamCheck = true;

    bool PredictMovement = true;
    bool PredictBulletDrop = true;
    float FinalDistance = 0;
    float Speed = 20;
    float Smooth = 0.9;
    float HipfireSmooth = 0.9;
    float ADSSmooth = 0.99;
    float SmoothDistance = 100;
    int Delay = 10;
    float FOV = 10;
    float ZoomScale = 3.0;
    float MinDistance = 1;
    float HipfireDistance = 60;
    float ZoomDistance = 160;

    //AimMode 2
    float HipfireSmooth1 = 250;
    float ADSSmooth1 = 230;
    float ExtraSmoothing = 1000;
    float Deadzone = 0.5;
    float FOV1 = 10;
    float MinDistance2 = 1;
    float MaxDistance2 = 200;

    //Weapon Toggles
    //Light
    bool P2020 = true;
    bool RE45 = true;
    bool Alternator = true;
    bool R99 = true;
    bool R301 = true;
    bool Spitfire = true;
    bool G7 = true;

    //Heavy
    bool Flatline = true;
    bool Hemlock = true;
    bool Repeater = true;
    bool Rampage = true;
    bool CARSMG = true;

    //Energy
    bool Havoc = true;
    bool Devotion = true;
    bool LSTAR = true;
    bool TripleTake = true;
    bool Volt = true;
    bool Nemesis = true;

    //Shotgun
    bool Mozambique = true;
    bool EVA8 = true;
    bool Peacekeeper = true;
    bool Mastiff = true;

    //Snipers
    bool Longbow = true;
    bool ChargeRifle = true;
    bool Sentinel = true;

    //Legendary
    bool Wingman = true;
    bool Prowler = true;
    bool Bocek = true;
    bool Kraber = true;
    bool Knife = true;

    //---------------Advanced---------------//
    bool AdvancedAim = true;
    bool AdvancedFire = true;
    bool AdvancedADS = false;
    //Aimbot Mode 0 - xap-client
    bool AdvancedClosestHitbox = true;
    float AdvancedHitbox = 2;
    float AdvancedSpeed = 20;
    float AdvancedSmooth = 0.99;
    float AdvancedHipfireSmooth = 0.99;
    float AdvancedADSSmooth = 0.99;
    //Aimbot Mode 1 - Grinder
    float AdvancedHipfireSmooth1 = 250;
    float AdvancedADSSmooth1 = 275;
    float AdvancedExtraSmooth1 = 5000;
    float AdvancedFOV1 = 10;
    float AdvancedDeadzone = 0.5;
    float AdvancedMinDistance1 = 1;
    float AdvancedMaxDistance1 = 200;

    //Advanced OnFire & OnADS - Aimbot Mode 0 & 1 - xap-client & grinder
    bool P2020Fire = true;
    bool P2020ADS = false;
    bool RE45Fire = true;
    bool RE45ADS = false;
    bool AlternatorFire = true;
    bool AlternatorADS = false;
    bool R99Fire = true;
    bool R99ADS = false;
    bool R301Fire = true;
    bool R301ADS = false;
    bool SpitfireFire = true;
    bool SpitfireADS = false;
    bool G7Fire = true;
    bool G7ADS = false;
    bool FlatlineFire = true;
    bool FlatlineADS = false;
    bool HemlockFire = true;
    bool HemlockADS = false;
    bool RepeaterFire = true;
    bool RepeaterADS = false;
    bool RampageFire = true;
    bool RampageADS = false;
    bool CARSMGFire = true;
    bool CARSMGADS = false;
    bool HavocFire = true;
    bool HavocADS = false;
    bool DevotionFire = true;
    bool DevotionADS = false;
    bool LSTARFire = true;
    bool LSTARADS = false;
    bool TripleTakeFire = true;
    bool TripleTakeADS = false;
    bool VoltFire = true;
    bool VoltADS = false;
    bool NemesisFire = true;
    bool NemesisADS = false;
    bool MozambiqueFire = true;
    bool MozambiqueADS = false;
    bool EVA8Fire = true;
    bool EVA8ADS = false;
    bool PeacekeeperFire = true;
    bool PeacekeeperADS = false;
    bool MastiffFire = true;
    bool MastiffADS = false;
    bool LongbowFire = true;
    bool LongbowADS = false;
    bool ChargeRifleFire = true;
    bool ChargeRifleADS = false;
    bool SentinelFire = true;
    bool SentinelADS = false;
    bool WingmanFire = true;
    bool WingmanADS = false;
    bool ProwlerFire = true;
    bool ProwlerADS = false;
    bool KraberFire = true;
    bool KraberADS = false;
    bool BocekFire = true;
    bool BocekADS = false;
    bool ThrowingKnifeFire = true;
    bool ThrowingKnifeADS = false;

    //Advanced Speed, Smooth + Hitbox - Aimbot Mode 0 - xap-client
    bool P2020ClosestHitbox = true;
    float P2020Hitbox = 2;
    float P2020Speed = 10;
    float P2020HipfireSmooth = 0.99;
    float P2020ADSSmooth = 0.99;
    bool RE45ClosestHitbox = true;
    float RE45Hitbox = 2;
    float RE45Speed = 0.99;
    float RE45HipfireSmooth = 10;
    float RE45ADSSmooth = 0.99;
    bool AlternatorClosestHitbox = true;
    float AlternatorHitbox = 2;
    float AlternatorSpeed = 10;
    float AlternatorHipfireSmooth = 0.99;
    float AlternatorADSSmooth = 0.99;
    bool R99ClosestHitbox = true;
    float R99Hitbox = 2;
    float R99Speed = 10;
    float R99HipfireSmooth = 0.99;
    float R99ADSSmooth = 0.99;
    bool R301ClosestHitbox = true;
    float R301Hitbox = 2;
    float R301Speed = 10;
    float R301HipfireSmooth = 0.99;
    float R301ADSSmooth = 0.99;
    bool SpitfireClosestHitbox = true;
    float SpitfireHitbox = 2;
    float SpitfireSpeed = 10;
    float SpitfireHipfireSmooth = 0.99;
    float SpitfireADSSmooth = 0.99;
    bool G7ClosestHitbox = true;
    float G7Hitbox = 2;
    float G7Speed = 10;
    float G7HipfireSmooth = 0.99;
    float G7ADSSmooth = 0.99;
    //Heavy
    bool FlatlineClosestHitbox = true;
    float FlatlineHitbox = 2;
    float FlatlineSpeed = 10;
    float FlatlineHipfireSmooth = 0.99;
    float FlatlineADSSmooth = 0.99;
    bool HemlockClosestHitbox = true;
    float HemlockHitbox = 2;
    float HemlockSpeed = 10;
    float HemlockHipfireSmooth = 0.99;
    float HemlockADSSmooth = 0.99;
    bool RepeaterClosestHitbox = true;
    float RepeaterHitbox = 2;
    float RepeaterSpeed = 10;
    float RepeaterHipfireSmooth = 0.99;
    float RepeaterADSSmooth = 0.99;
    bool RampageClosestHitbox = true;
    float RampageHitbox = 2;
    float RampageSpeed = 10;
    float RampageHipfireSmooth = 0.99;
    float RampageADSSmooth = 0.99;
    bool CARSMGClosestHitbox = true;
    float CARSMGHitbox = 2;
    float CARSMGSpeed = 10;
    float CARSMGHipfireSmooth = 0.99;
    float CARSMGADSSmooth = 0.99;
    //Energy
    bool HavocClosestHitbox = true;
    float HavocHitbox = 2;
    float HavocSpeed = 10;
    float HavocHipfireSmooth = 0.99;
    float HavocADSSmooth = 0.99;
    bool DevotionClosestHitbox = true;
    float DevotionHitbox = 2;
    float DevotionSpeed = 10;
    float DevotionHipfireSmooth = 0.99;
    float DevotionADSSmooth = 0.99;
    bool LSTARClosestHitbox = true;
    float LSTARHitbox = 2;
    float LSTARSpeed = 10;
    float LSTARHipfireSmooth = 0.99;
    float LSTARADSSmooth = 0.99;
    bool TripleTakeClosestHitbox = true;
    float TripleTakeHitbox = 2;
    float TripleTakeSpeed = 10;
    float TripleTakeHipfireSmooth = 0.99;
    float TripleTakeADSSmooth = 0.99;
    bool VoltClosestHitbox = true;
    float VoltHitbox = 2;
    float VoltSpeed = 10;
    float VoltHipfireSmooth = 0.99;
    float VoltADSSmooth = 0.99;
    bool NemesisClosestHitbox = true;
    float NemesisHitbox = 2;
    float NemesisSpeed = 10;
    float NemesisHipfireSmooth = 0.99;
    float NemesisADSSmooth = 0.99;
    //Shotguns
    bool MozambiqueClosestHitbox = true;
    float MozambiqueHitbox = 2;
    float MozambiqueSpeed = 10;
    float MozambiqueHipfireSmooth = 0.99;
    float MozambiqueADSSmooth = 0.99;
    bool EVA8ClosestHitbox = true;
    float EVA8Hitbox = 2;
    float EVA8Speed = 10;
    float EVA8HipfireSmooth = 0.99;
    float EVA8ADSSmooth = 0.99;
    bool PeacekeeperClosestHitbox = true;
    float PeacekeeperHitbox = 2;
    float PeacekeeperSpeed = 10;
    float PeacekeeperHipfireSmooth = 0.99;
    float PeacekeeperADSSmooth = 0.99;
    bool MastiffClosestHitbox = true;
    float MastiffHitbox = 2;
    float MastiffSpeed = 10;
    float MastiffHipfireSmooth = 0.99;
    float MastiffADSSmooth = 0.99;
    //Snipers
    bool LongbowClosestHitbox = true;
    float LongbowHitbox = 2;
    float LongbowSpeed = 10;
    float LongbowHipfireSmooth = 0.99;
    float LongbowADSSmooth = 0.99;
    bool ChargeRifleClosestHitbox = true;
    float ChargeRifleHitbox = 2;
    float ChargeRifleSpeed = 10;
    float ChargeRifleHipfireSmooth = 0.99;
    float ChargeRifleADSSmooth = 0.99;
    bool SentinelClosestHitbox = true;
    float SentinelHitbox = 2;
    float SentinelSpeed = 10;
    float SentinelHipfireSmooth = 0.99;
    float SentinelADSSmooth = 0.99;
    //Legendary
    bool WingmanClosestHitbox = true;
    float WingmanHitbox = 2;
    float WingmanSpeed = 10;
    float WingmanHipfireSmooth = 0.99;
    float WingmanADSSmooth = 0.99;
    bool ProwlerClosestHitbox = true;
    float ProwlerHitbox = 2;
    float ProwlerSpeed = 10;
    float ProwlerHipfireSmooth = 0.99;
    float ProwlerADSSmooth = 0.99;
    bool KraberClosestHitbox = true;
    float KraberHitbox = 2;
    float KraberSpeed = 10;
    float KraberHipfireSmooth = 0.99;
    float KraberADSSmooth = 0.99;
    bool BocekClosestHitbox = true;
    float BocekHitbox = 2;
    float BocekSpeed = 10;
    float BocekHipfireSmooth = 0.99;
    float BocekADSSmooth = 0.99;
    bool ThrowingKnifeClosestHitbox = true;
    float ThrowingKnifeHitbox = 2;
    float ThrowingKnifeSpeed = 10;
    float ThrowingKnifeHipfireSmooth = 0.99;
    float ThrowingKnifeADSSmooth = 0.99;

    //Advanced Smooth - Aimbot Mode 1 - Grinder
    float P2020HipfireSmooth1 = 250;
    float P2020ADSSmooth1 = 275;
    float P2020ExtraSmooth1 = 5000;
    float P2020Deadzone = 0.5;
    float P2020FOV1 = 10;
    float P2020MinDistance1 = 1;
    float P2020MaxDistance1 = 200;
    float RE45HipfireSmooth1 = 250;
    float RE45ADSSmooth1 = 275;
    float RE45ExtraSmooth1 = 5000;
    float RE45Deadzone = 0.5;
    float RE45FOV1 = 10;
    float RE45MinDistance1 = 1;
    float RE45MaxDistance1 = 200;
    float AlternatorHipfireSmooth1 = 250;
    float AlternatorADSSmooth1 = 275;
    float AlternatorExtraSmooth1 = 5000;
    float AlternatorDeadzone = 0.5;
    float AlternatorFOV1 = 10;
    float AlternatorMinDistance1 = 1;
    float AlternatorMaxDistance1 = 200;
    float R99HipfireSmooth1 = 250;
    float R99ADSSmooth1 = 275;
    float R99ExtraSmooth1 = 5000;
    float R99Deadzone = 0.5;
    float R99FOV1 = 10;
    float R99MinDistance1 = 1;
    float R99MaxDistance1 = 200;
    float R301HipfireSmooth1 = 250;
    float R301ADSSmooth1 = 275;
    float R301ExtraSmooth1 = 5000;
    float R301Deadzone = 0.5;
    float R301FOV1 = 10;
    float R301MinDistance1 = 1;
    float R301MaxDistance1 = 200;
    float SpitfireHipfireSmooth1 = 250;
    float SpitfireADSSmooth1 = 275;
    float SpitfireExtraSmooth1 = 5000;
    float SpitfireDeadzone = 0.5;
    float SpitfireFOV1 = 10;
    float SpitfireMinDistance1 = 1;
    float SpitfireMaxDistance1 = 200;
    float G7HipfireSmooth1 = 250;
    float G7ADSSmooth1 = 275;
    float G7ExtraSmooth1 = 5000;
    float G7Deadzone = 0.5;
    float G7FOV1 = 10;
    float G7MinDistance1 = 1;
    float G7MaxDistance1 = 200;

    float FlatlineHipfireSmooth1 = 250;
    float FlatlineADSSmooth1 = 275;
    float FlatlineExtraSmooth1 = 5000;
    float FlatlineDeadzone = 0.5;
    float FlatlineFOV1 = 10;
    float FlatlineMinDistance1 = 1;
    float FlatlineMaxDistance1 = 200;
    float HemlockHipfireSmooth1 = 250;
    float HemlockADSSmooth1 = 275;
    float HemlockExtraSmooth1 = 5000;
    float HemlockDeadzone = 0.5;
    float HemlockFOV1 = 10;
    float HemlockMinDistance1 = 1;
    float HemlockMaxDistance1 = 200;
    float RepeaterHipfireSmooth1 = 250;
    float RepeaterADSSmooth1 = 275;
    float RepeaterExtraSmooth1 = 5000;
    float RepeaterDeadzone = 0.5;
    float RepeaterFOV1 = 10;
    float RepeaterMinDistance1 = 1;
    float RepeaterMaxDistance1 = 200;
    float RampageHipfireSmooth1 = 250;
    float RampageADSSmooth1 = 275;
    float RampageExtraSmooth1 = 5000;
    float RampageDeadzone = 0.5;
    float RampageFOV1 = 10;
    float RampageMinDistance1 = 1;
    float RampageMaxDistance1 = 200;
    float CARSMGHipfireSmooth1 = 250;
    float CARSMGADSSmooth1 = 275;
    float CARSMGExtraSmooth1 = 5000;
    float CARSMGDeadzone = 0.5;
    float CARSMGFOV1 = 10;
    float CARSMGMinDistance1 = 1;
    float CARSMGMaxDistance1 = 200;

    float HavocHipfireSmooth1 = 250;
    float HavocADSSmooth1 = 275;
    float HavocExtraSmooth1 = 5000;
    float HavocDeadzone = 0.5;
    float HavocFOV1 = 10;
    float HavocMinDistance1 = 1;
    float HavocMaxDistance1 = 200;
    float DevotionHipfireSmooth1 = 250;
    float DevotionADSSmooth1 = 275;
    float DevotionExtraSmooth1 = 5000;
    float DevotionDeadzone = 0.5;
    float DevotionFOV1 = 10;
    float DevotionMinDistance1 = 1;
    float DevotionMaxDistance1 = 200;
    float LSTARHipfireSmooth1 = 250;
    float LSTARADSSmooth1 = 275;
    float LSTARExtraSmooth1 = 5000;
    float LSTARDeadzone = 0.5;
    float LSTARFOV1 = 10;
    float LSTARMinDistance1 = 1;
    float LSTARMaxDistance1 = 200;
    float TripleTakeHipfireSmooth1 = 250;
    float TripleTakeADSSmooth1 = 275;
    float TripleTakeExtraSmooth1 = 5000;
    float TripleTakeDeadzone = 0.5;
    float TripleTakeFOV1 = 10;
    float TripleTakeMinDistance1 = 1;
    float TripleTakeMaxDistance1 = 200;
    float VoltHipfireSmooth1 = 250;
    float VoltADSSmooth1 = 275;
    float VoltExtraSmooth1 = 5000;
    float VoltDeadzone = 0.5;
    float VoltFOV1 = 10;
    float VoltMinDistance1 = 1;
    float VoltMaxDistance1 = 200;
    float NemesisHipfireSmooth1 = 250;
    float NemesisADSSmooth1 = 275;
    float NemesisExtraSmooth1 = 5000;
    float NemesisDeadzone = 0.5;
    float NemesisFOV1 = 10;
    float NemesisMinDistance1 = 1;
    float NemesisMaxDistance1 = 200;

    float MozambiqueHipfireSmooth1 = 250;
    float MozambiqueADSSmooth1 = 275;
    float MozambiqueExtraSmooth1 = 5000;
    float MozambiqueDeadzone = 0.5;
    float MozambiqueFOV1 = 10;
    float MozambiqueMinDistance1 = 1;
    float MozambiqueMaxDistance1 = 200;
    float EVA8HipfireSmooth1 = 250;
    float EVA8ADSSmooth1 = 275;
    float EVA8ExtraSmooth1 = 5000;
    float EVA8Deadzone = 0.5;
    float EVA8FOV1 = 10;
    float EVA8MinDistance1 = 1;
    float EVA8MaxDistance1 = 200;
    float PeacekeeperHipfireSmooth1 = 250;
    float PeacekeeperADSSmooth1 = 275;
    float PeacekeeperExtraSmooth1 = 5000;
    float PeacekeeperDeadzone = 0.5;
    float PeacekeeperFOV1 = 10;
    float PeacekeeperMinDistance1 = 1;
    float PeacekeeperMaxDistance1 = 200;
    float MastiffHipfireSmooth1 = 250;
    float MastiffADSSmooth1 = 275;
    float MastiffExtraSmooth1 = 5000;
    float MastiffDeadzone = 0.5;
    float MastiffFOV1 = 10;
    float MastiffMinDistance1 = 1;
    float MastiffMaxDistance1 = 200;

    float LongbowHipfireSmooth1 = 250;
    float LongbowADSSmooth1 = 275;
    float LongbowExtraSmooth1 = 5000;
    float LongbowDeadzone = 0.5;
    float LongbowFOV1 = 10;
    float LongbowMinDistance1 = 1;
    float LongbowMaxDistance1 = 200;
    float ChargeRifleHipfireSmooth1 = 250;
    float ChargeRifleADSSmooth1 = 275;
    float ChargeRifleExtraSmooth1 = 5000;
    float ChargeRifleDeadzone = 0.5;
    float ChargeRifleFOV1 = 10;
    float ChargeRifleMinDistance1 = 1;
    float ChargeRifleMaxDistance1 = 200;
    float SentinelHipfireSmooth1 = 250;
    float SentinelADSSmooth1 = 275;
    float SentinelExtraSmooth1 = 5000;
    float SentinelDeadzone = 0.5;
    float SentinelFOV1 = 10;
    float SentinelMinDistance1 = 1;
    float SentinelMaxDistance1 = 200;

    float WingmanHipfireSmooth1 = 250;
    float WingmanADSSmooth1 = 275;
    float WingmanExtraSmooth1 = 5000;
    float WingmanDeadzone = 0.5;
    float WingmanFOV1 = 10;
    float WingmanMinDistance1 = 1;
    float WingmanMaxDistance1 = 200;
    float ProwlerHipfireSmooth1 = 250;
    float ProwlerADSSmooth1 = 275;
    float ProwlerExtraSmooth1 = 5000;
    float ProwlerDeadzone = 0.5;
    float ProwlerFOV1 = 10;
    float ProwlerMinDistance1 = 1;
    float ProwlerMaxDistance1 = 200;
    float BocekHipfireSmooth1 = 250;
    float BocekADSSmooth1 = 275;
    float BocekExtraSmooth1 = 5000;
    float BocekDeadzone = 0.5;
    float BocekFOV1 = 10;
    float BocekMinDistance1 = 1;
    float BocekMaxDistance1 = 200;
    float KraberHipfireSmooth1 = 250;
    float KraberADSSmooth1 = 275;
    float KraberExtraSmooth1 = 5000;
    float KraberDeadzone = 0.5;
    float KraberFOV1 = 10;
    float KraberMinDistance1 = 1;
    float KraberMaxDistance1 = 200;
    float ThrowingKnifeHipfireSmooth1 = 250;
    float ThrowingKnifeADSSmooth1 = 275;
    float ThrowingKnifeExtraSmooth1 = 5000;
    float ThrowingKnifeDeadzone = 0.5;
    float ThrowingKnifeFOV1 = 10;
    float ThrowingKnifeMinDistance1 = 1;
    float ThrowingKnifeMaxDistance1 = 200;

    XDisplay* X11Display;
    LocalPlayer* Myself;
    std::vector<Player*>* Players;
    Level* Map;

    Player* CurrentTarget = nullptr;
    bool TargetSelected = true;

    QAngle RCSLastPunch;
    std::chrono::milliseconds LastAimTime;

    std::set<int> AimList = {};

    Aimbot(XDisplay* X11Display, Level* Map, LocalPlayer* Myself, std::vector<Player*>* GamePlayers) {
        this->X11Display = X11Display;
        this->Myself = Myself;
        this->Map = Map;
        this->Players = GamePlayers;
    }

    void RenderUI() {
        if (ImGui::BeginTabItem("Aim", nullptr, ImGuiTabItemFlags_NoCloseWithMiddleMouseButton | ImGuiTabItemFlags_NoReorder)) {
            ImVec2 TabSize;
            TabSize = ImGui::GetWindowSize();
            //Aimbot
            ImGui::Text("Aimbot");
            if (ImGui::BeginChild("Aimbot Main", ImVec2(TabSize.x - TabSize.x , (TabSize.y - TabSize.y) + 270), true)) {
                ImGui::Text("Aimbot Tab");
                ImGui::Checkbox("Enabled", &AimbotEnabled);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                    ImGui::SetTooltip("Toggle the Aimbot.");

                ImGui::SameLine();
                const char* AimbotModeIndex[] = {"Cubic Bezier (xap-client)", "Grinder (Advanced)", "Memory Aim"};
                ImGui::Combo("Aimbot Method", &AimbotMode, AimbotModeIndex, IM_ARRAYSIZE(AimbotModeIndex));
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                    ImGui::SetTooltip("What Aimbot Method You Would Like.\nYou may find Grinder To Be More Legit/Smooth.");

                ImGui::SameLine();

                //ImGui::Text("Recoil Control");
                ImGui::Checkbox("Recoil Control", &RCSEnabled);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                    ImGui::SetTooltip("Will enable using mouse on xap/grinder and mem recoil with memory aim(better recoil control than mouse)however aimbot might be worse");

                if(RCSEnabled) {

                    //ImGui::Text("NoRecoil Settings");
                    if (ImGui::CollapsingHeader("Recoil Amount Removed", nullptr)) {
                        ImGui::SliderFloat("Pitch Recoil Removed %", &PitchP, 1, 100, "%.1f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("X axis Recoil Percent Removed");
                        ImGui::SliderFloat("Yaw Recoil Removed %", &YawP, 1, 100, "%.1f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("X axis Recoil Percent Removed ");
                    }
                }
                //Select Hitbox
                if (AimbotMode == 0 || AimbotMode == 2 && !AdvancedAim) {
                    ImGui::Separator();
                    ImGui::Text("Hitbox");
                    ImGui::Checkbox("Closest To Crosshair", &ClosestHitbox);
                    if (!ClosestHitbox) {
                        const char* HitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                        int HitboxTypeIndex = static_cast<int>(Modules::Aimbot::Hitbox);
                        ImGui::Combo("Hitbox Type", &HitboxTypeIndex, HitboxTypes, IM_ARRAYSIZE(HitboxTypes));
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Which bone the aimbot will aim at.");
                        Modules::Aimbot::Hitbox = static_cast<HitboxType>(HitboxTypeIndex);
                    }
                }

                ImGui::Separator();

                ImGui::Text("Aim Conditions");
                const char* BindMethodIndex[] = {"Memory", "Keybinds"};
                ImGui::Combo("Aim Bind Method", &Modules::Aimbot::BindMethod, BindMethodIndex, IM_ARRAYSIZE(BindMethodIndex));

                if (!AdvancedAim) {
                    if (Modules::Aimbot::BindMethod == 0) { //OnFire and OnADS
                        ImGui::Checkbox("On Fire", &OnFire);
                        ImGui::SameLine();
                        ImGui::Checkbox("On ADS", &OnADS);
                    }

                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                        int AimBind = static_cast<int>(Modules::Aimbot::AimBind);
                        ImGui::Combo("Aim Bind##Aimbot", &AimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                        Modules::Aimbot::AimBind = static_cast<InputKeyType>(AimBind);
                        int ExtraBind = static_cast<int>(Modules::Aimbot::ExtraBind);
                        ImGui::Combo("Extra Bind##Aimbot", &ExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                        Modules::Aimbot::ExtraBind = static_cast<InputKeyType>(ExtraBind);
                    }
                }

                ImGui::Checkbox("Team Check##Aimbot", &TeamCheck);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                    ImGui::SetTooltip("Disable this if doing 1v1s in the firing range.\nMay not work with Grinder Aim Method.");
                if (AimbotMode == 0 || AimbotMode == 2) { //xap-client
                    ImGui::SameLine();
                    ImGui::Checkbox("Visibility Check", &VisCheck);
                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Aims At Only Visible Enemies.");
                }

                ImGui::Separator();

                //Select Weapons
                ImGui::Text("Weapons");
                if (ImGui::CollapsingHeader("Selected Weapons", nullptr)) {
                    ImGui::Text("Light");
                    ImGui::Checkbox("P2020", &P2020);
                    ImGui::SameLine();
                    ImGui::Checkbox("RE-45 Auto", &RE45);
                    ImGui::SameLine();
                    ImGui::Checkbox("Alternator SMG", &Alternator);
                    ImGui::SameLine();
                    ImGui::Checkbox("R-99 SMG", &R99);
                    ImGui::SameLine();
                    ImGui::Checkbox("R-301 Carbine", &R301);
                    ImGui::Checkbox("M600 Spitfire", &Spitfire);
                    ImGui::SameLine();
                    ImGui::Checkbox("G7 Scout", &G7);

                    ImGui::Text("Heavy");
                    ImGui::Checkbox("VK-47 Flatline", &Flatline);
                    ImGui::SameLine();
                    ImGui::Checkbox("Prowler Burst SMG", &Prowler);
                    ImGui::SameLine();
                    ImGui::Checkbox("Hemlock Burst AR", &Hemlock);
                    ImGui::SameLine();
                    ImGui::Checkbox("30-30 Repeater", &Repeater);
                    ImGui::SameLine();
                    ImGui::Checkbox("Rampage LMG", &Rampage);
                    ImGui::Checkbox("C.A.R SMG", &CARSMG);

                    ImGui::Text("Energy");
                    ImGui::Checkbox("Havoc Rifle", &Havoc);
                    ImGui::SameLine();
                    ImGui::Checkbox("Devotion LMG", &Devotion);
                    ImGui::SameLine();
                    ImGui::Checkbox("L-Star EMG", &LSTAR);
                    ImGui::SameLine();
                    ImGui::Checkbox("Triple-Take", &TripleTake);
                    ImGui::SameLine();
                    ImGui::Checkbox("Volt", &Volt);
                    ImGui::Checkbox("Nemesis Burst AR", &Nemesis);

                    ImGui::Text("Shotguns");
                    ImGui::Checkbox("Mozambique", &Mozambique);
                    ImGui::SameLine();
                    ImGui::Checkbox("Peacekeeper", &Peacekeeper);
                    ImGui::SameLine();
                    ImGui::Checkbox("Mastiff", &Mastiff);

                    ImGui::Text("Snipers");
                    ImGui::Checkbox("Longbow DMR", &Longbow);
                    ImGui::SameLine();
                    ImGui::Checkbox("Charge Rifle", &ChargeRifle);
                    ImGui::SameLine();
                    ImGui::Checkbox("Sentinel", &Sentinel);

                    ImGui::Text("Legendary");
                    ImGui::Checkbox("Wingman", &Wingman);
                    ImGui::SameLine();
                    ImGui::Checkbox("EVA-8 Auto", &EVA8);
                    ImGui::SameLine();
                    ImGui::Checkbox("Bocek Compound Bow", &Bocek);
                    ImGui::Checkbox("Kraber .50-CAL Sniper", &Kraber);
                    ImGui::SameLine();
                    ImGui::Checkbox("Throwing Knife", &Knife);
                }

                if (AimbotMode == 0 && !AdvancedAim) {
                    ImGui::Separator();
                    //Smoothness Settings
                    ImGui::Text("Smoothness");
                    if (ImGui::CollapsingHeader("Smoothness Settings", nullptr)) {
                        ImGui::SliderFloat("Speed", &Speed, 1, 100, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Speed of the Aim-Assist\nHigher = Faster");

                        /*ImGui::SliderFloat("Smoothing", &Smooth, 0, 0.99, "%.3f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Smoothing for the Aim-Assist\nHigher = Smoother");*/

                        ImGui::SliderFloat("Hipefire Smoothing", &HipfireSmooth, 0, 0.99, "%.3f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Smoothing for the Aim-Assist whilst hipfiring.\nHigher = Smoother");

                        ImGui::SliderFloat("ADS Smoothing", &ADSSmooth, 0, 0.99, "%.3f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Smoothing for the Aim-Assist whilst ADS.\nHigher = Smoother");

                        ImGui::SliderFloat("Distance Smoothing", &SmoothDistance, 1, 10000, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                            ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.\nMay not change much.");
                        ImGui::SliderInt("Delay", &Delay, 1, 50);
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                            ImGui::SetTooltip("Delay time for the aimbot smoothing.\n");
                    }


                    ImGui::Separator();

                    //Prediction Settings
                    ImGui::Text("Prediction");
                    if (ImGui::CollapsingHeader("Prediction Settings", nullptr)) {
                        ImGui::Checkbox("Predict Movement", &PredictMovement);
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Predict target's movement");
                        ImGui::SameLine();
                        ImGui::Checkbox("Predict Bullet Drop", &PredictBulletDrop);
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Predict weapon's bullet drop");
                    }

                    ImGui::Separator();

                    //FOV Settings
                    ImGui::Text("FOV");
                    if (ImGui::CollapsingHeader("FOV Settings", nullptr)) {
                        ImGui::SliderFloat("FOV", &FOV, 1, 90, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Field of View");
                        ImGui::SliderFloat("Zoom Scale", &ZoomScale, 0, 5, "%.1f");
                    }

                    ImGui::Separator();

                    //Distance Settings
                    ImGui::Text("Distance");
                    if (ImGui::CollapsingHeader("Distance Settings", nullptr)) {
                        ImGui::SliderFloat("Hipfire Max Distance", &HipfireDistance, 1, 500, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Maximum Hipfire distance for Aim-Assist to work");
                        ImGui::SliderFloat("Zoom Max Distance", &ZoomDistance, 1, 500, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Maximum ADS Distance for Aim-Assist to work");
                    }
                }

                if (AimbotMode == 2 && !AdvancedAim) {
                    ImGui::Separator();
                    //Smoothness Settings
                    ImGui::Text("Smoothness");
                    if (ImGui::CollapsingHeader("Smoothness Settings", nullptr)) {
                        //ImGui::SliderFloat("Speed", &Speed, 1, 100, "%.0f");
                        //if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        //ImGui::SetTooltip("Speed of the Aim-Assist\nHigher = Faster");

                        /*ImGui::SliderFloat("Smoothing", &Smooth, 0, 0.99, "%.3f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Smoothing for the Aim-Assist\nHigher = Smoother");*/

                        ImGui::SliderFloat("Hipefire Smoothing", &HipfireSmooth, 0, 1, "%.3f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Smoothing for the Aim-Assist whilst hipfiring.\nHigher = Smoother");

                        ImGui::SliderFloat("ADS Smoothing", &ADSSmooth, 0, 1, "%.3f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Smoothing for the Aim-Assist whilst ADS.\nHigher = Smoother");

                        ImGui::SliderFloat("Distance Smoothing", &SmoothDistance, 1, 10000, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                            ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.\nMay not change much.");
                        ImGui::SliderInt("Delay", &Delay, 1, 50);
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                            ImGui::SetTooltip("Delay time for the aimbot smoothing.\n");
                    }

                    ImGui::Separator();

                    //Prediction Settings
                    ImGui::Text("Prediction");
                    if (ImGui::CollapsingHeader("Prediction Settings", nullptr)) {
                        ImGui::Checkbox("Predict Movement", &PredictMovement);
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Predict target's movement");
                        ImGui::SameLine();
                        ImGui::Checkbox("Predict Bullet Drop", &PredictBulletDrop);
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Predict weapon's bullet drop");
                    }

                    ImGui::Separator();

                    //FOV Settings
                    ImGui::Text("FOV");
                    if (ImGui::CollapsingHeader("FOV Settings", nullptr)) {
                        ImGui::SliderFloat("FOV", &FOV, 1, 90, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Field of View");
                        ImGui::SliderFloat("Zoom Scale", &ZoomScale, 0, 5, "%.1f");
                    }

                    ImGui::Separator();

                    //Distance Settings
                    ImGui::Text("Distance");
                    if (ImGui::CollapsingHeader("Distance Settings", nullptr)) {
                        ImGui::SliderFloat("Hipfire Max Distance", &HipfireDistance, 1, 500, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Maximum Hipfire distance for Aim-Assist to work");
                        ImGui::SliderFloat("Zoom Max Distance", &ZoomDistance, 1, 500, "%.0f");
                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                        ImGui::SetTooltip("Maximum ADS Distance for Aim-Assist to work");
                    }
                }

                if (AimbotMode == 1 && !AdvancedAim) {
                    ImGui::Separator();
                    ImGui::Text("Enable Advanced Aimbot To Configure The Aimbot.");
                }
                ImGui::EndChild();
            }

            ImGui::Text("Advanced Aimbot");
            if (ImGui::BeginChild("Aimbot Advanced", ImVec2(TabSize.x - TabSize.x , (TabSize.y - TabSize.y) + 285), true)) {
                ImGui::Text("Advanced Aimbot Tab");
                ImGui::Checkbox("Enable Advanced Aimbot", &AdvancedAim);
                if (AdvancedAim) {
                        ImGui::Separator();
                        ImGui::Text("Light Weapons");
                            if (P2020) {
                                if (ImGui::CollapsingHeader("P2020", nullptr)) {
                                    ImGui::Text("P2020");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##P2020Aimbot", &P2020Fire);
                                        ImGui::Checkbox("On ADS##P2020Aimbot", &P2020ADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int P2020AimBind = static_cast<int>(Modules::Aimbot::P2020AimBind);
                                        ImGui::Combo("Aim Bind##P2020Aimbot", &P2020AimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::P2020AimBind = static_cast<InputKeyType>(P2020AimBind);
                                        int P2020ExtraBind = static_cast<int>(Modules::Aimbot::P2020ExtraBind);
                                        ImGui::Combo("Extra Bind##P2020Aimbot", &P2020ExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::P2020ExtraBind = static_cast<InputKeyType>(P2020ExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##P2020AdvancedHitbox", &P2020ClosestHitbox);
                                        if (!P2020ClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* P2020HitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int P2020HitboxTypeIndex = static_cast<int>(Modules::Aimbot::P2020Hitbox);
                                            ImGui::Combo("Hitbox Type##P2020AdvancedHitbox", &P2020HitboxTypeIndex, P2020HitboxTypes, IM_ARRAYSIZE(P2020HitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::P2020Hitbox = static_cast<HitboxType>(P2020HitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedP2020", &P2020Speed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The P2020\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedP2020", &P2020HipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The P2020 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedP2020", &P2020ADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The P2020 Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedP2020", &P2020HipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The P2020 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedP2020", &P2020ADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The P2020 Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedP2020", &P2020ExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedP2020", &P2020Deadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.\n If you have very low smoothing then you might want to up this to prevent 'shaking'.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV", &P2020FOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance", &P2020MinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aim-Assist to work");
                                        ImGui::SliderFloat("Max Distance", &P2020MaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aim-Assist to work");
                                }
                            }
                        }
                            if (RE45) {
                                if (ImGui::CollapsingHeader("RE-45", nullptr)) {
                                    ImGui::Text("RE-45");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##RE45Aimbot", &RE45Fire);
                                        ImGui::Checkbox("On ADS##RE45Aimbot", &RE45ADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int RE45AimBind = static_cast<int>(Modules::Aimbot::RE45AimBind);
                                        ImGui::Combo("Aim Bind##RE45Aimbot", &RE45AimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::RE45AimBind = static_cast<InputKeyType>(RE45AimBind);
                                        int RE45ExtraBind = static_cast<int>(Modules::Aimbot::RE45ExtraBind);
                                        ImGui::Combo("Extra Bind##RE45Aimbot", &RE45ExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::RE45ExtraBind = static_cast<InputKeyType>(RE45ExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##RE45AdvancedHitbox", &RE45ClosestHitbox);
                                        if (!RE45ClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* RE45HitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int RE45HitboxTypeIndex = static_cast<int>(Modules::Aimbot::RE45Hitbox);
                                            ImGui::Combo("Hitbox Type##RE45AdvancedHitbox", &RE45HitboxTypeIndex, RE45HitboxTypes, IM_ARRAYSIZE(RE45HitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::RE45Hitbox = static_cast<HitboxType>(RE45HitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedRE45", &RE45Speed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The RE45\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedRE45", &RE45HipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The RE45 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedRE45", &RE45ADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The RE45 Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedRE45", &RE45HipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The RE45 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedRE45", &RE45ADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The RE45 Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedRE45", &RE45ExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedRE45", &RE45Deadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedRE45", &RE45FOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The RE45.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedRE45", &RE45MinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the RE45.");
                                        ImGui::SliderFloat("Max Distance", &RE45MaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the RE45.");
                                }
                            }
                        }
                            if (Alternator) {
                                if (ImGui::CollapsingHeader("Alternator", nullptr)) {
                                    ImGui::Text("Alternator");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##AlternatorAimbot", &AlternatorFire);
                                        ImGui::Checkbox("On ADS##AlternatorAimbot", &AlternatorADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int AlternatorAimBind = static_cast<int>(Modules::Aimbot::AlternatorAimBind);
                                        ImGui::Combo("Aim Bind##AlternatorAimbot", &AlternatorAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::AlternatorAimBind = static_cast<InputKeyType>(AlternatorAimBind);
                                        int AlternatorExtraBind = static_cast<int>(Modules::Aimbot::AlternatorExtraBind);
                                        ImGui::Combo("Extra Bind##AlternatorAimbot", &AlternatorExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::AlternatorExtraBind = static_cast<InputKeyType>(AlternatorExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##AlternatorAdvancedHitbox", &AlternatorClosestHitbox);
                                        if (!AlternatorClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* AlternatorHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int AlternatorHitboxTypeIndex = static_cast<int>(Modules::Aimbot::AlternatorHitbox);
                                            ImGui::Combo("Hitbox Type##AlternatorAdvancedHitbox", &AlternatorHitboxTypeIndex, AlternatorHitboxTypes, IM_ARRAYSIZE(AlternatorHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::AlternatorHitbox = static_cast<HitboxType>(AlternatorHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedAlternator", &AlternatorSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Alternator\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedAlternator", &AlternatorHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Alternator Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedAlternator", &AlternatorADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Alternator Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedAlternator", &AlternatorHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Alternator Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedAlternator", &AlternatorADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Alternator Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedAlternator", &AlternatorExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedAlternator", &AlternatorDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedAlternator", &AlternatorFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Alternator.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedAlternator", &AlternatorMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Alternator.");
                                        ImGui::SliderFloat("Max Distance", &AlternatorMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Alternator.");
                                }
                            }
                        }
                            if (R99) {
                                if (ImGui::CollapsingHeader("R-99", nullptr)) {
                                    ImGui::Text("R-99");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##R99Aimbot", &R99Fire);
                                        ImGui::Checkbox("On ADS##R99Aimbot", &R99ADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int R99AimBind = static_cast<int>(Modules::Aimbot::R99AimBind);
                                        ImGui::Combo("Aim Bind##R99Aimbot", &R99AimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::R99AimBind = static_cast<InputKeyType>(R99AimBind);
                                        int R99ExtraBind = static_cast<int>(Modules::Aimbot::R99ExtraBind);
                                        ImGui::Combo("Extra Bind##R99Aimbot", &R99ExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::R99ExtraBind = static_cast<InputKeyType>(R99ExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##R99AdvancedHitbox", &R99ClosestHitbox);
                                        if (!R99ClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* R99HitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int R99HitboxTypeIndex = static_cast<int>(Modules::Aimbot::R99Hitbox);
                                            ImGui::Combo("Hitbox Type##R99AdvancedHitbox", &R99HitboxTypeIndex, R99HitboxTypes, IM_ARRAYSIZE(R99HitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::R99Hitbox = static_cast<HitboxType>(R99HitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedR99", &R99Speed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The R99\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedR99", &R99HipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R99 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedR99", &R99ADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R99 Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedR99", &R99HipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R99 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedR99", &R99ADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R99 Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedR99", &R99ExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedR99", &R99Deadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedR99", &R99FOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The R99.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedR99", &R99MinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the R99.");
                                        ImGui::SliderFloat("Max Distance", &R99MaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the R99.");
                                }
                            }
                        }
                            if (R301) {
                                if (ImGui::CollapsingHeader("R-301", nullptr)) {
                                    ImGui::Text("R-301");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##R301Aimbot", &R301Fire);
                                        ImGui::Checkbox("On ADS##R301Aimbot", &R301ADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int R301AimBind = static_cast<int>(Modules::Aimbot::R301AimBind);
                                        ImGui::Combo("Aim Bind##R301Aimbot", &R301AimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::R301AimBind = static_cast<InputKeyType>(R301AimBind);
                                        int R301ExtraBind = static_cast<int>(Modules::Aimbot::R301ExtraBind);
                                        ImGui::Combo("Extra Bind##R301Aimbot", &R301ExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::R301ExtraBind = static_cast<InputKeyType>(R301ExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##R301AdvancedHitbox", &R301ClosestHitbox);
                                        if (!R301ClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* R301HitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int R301HitboxTypeIndex = static_cast<int>(Modules::Aimbot::R301Hitbox);
                                            ImGui::Combo("Hitbox Type##R301AdvancedHitbox", &R301HitboxTypeIndex, R301HitboxTypes, IM_ARRAYSIZE(R301HitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::R301Hitbox = static_cast<HitboxType>(R301HitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedR301", &R301Speed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The R301\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedR301", &R301HipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R301 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedR301", &R301ADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R301 Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedR301", &R301HipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R301 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedR301", &R301ADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The R301 Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedR301", &R301ExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedR301", &R301Deadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedR301", &R301FOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The R301.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedR301", &R301MinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the R301.");
                                        ImGui::SliderFloat("Max Distance", &R301MaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the R301.");
                                }
                            }
                        }
                            if (Spitfire) {
                                if (ImGui::CollapsingHeader("Spitfire", nullptr)) {
                                    ImGui::Text("Spitfire");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##SpitfireAimbot", &SpitfireFire);
                                        ImGui::Checkbox("On ADS##SpitfireAimbot", &SpitfireADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int SpitfireAimBind = static_cast<int>(Modules::Aimbot::SpitfireAimBind);
                                        ImGui::Combo("Aim Bind##SpitfireAimbot", &SpitfireAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::SpitfireAimBind = static_cast<InputKeyType>(SpitfireAimBind);
                                        int SpitfireExtraBind = static_cast<int>(Modules::Aimbot::SpitfireExtraBind);
                                        ImGui::Combo("Extra Bind##SpitfireAimbot", &SpitfireExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::SpitfireExtraBind = static_cast<InputKeyType>(SpitfireExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##SpitfireAdvancedHitbox", &SpitfireClosestHitbox);
                                        if (!SpitfireClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* SpitfireHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int SpitfireHitboxTypeIndex = static_cast<int>(Modules::Aimbot::SpitfireHitbox);
                                            ImGui::Combo("Hitbox Type##SpitfireAdvancedHitbox", &SpitfireHitboxTypeIndex, SpitfireHitboxTypes, IM_ARRAYSIZE(SpitfireHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::SpitfireHitbox = static_cast<HitboxType>(SpitfireHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedSpitfire", &SpitfireSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Spitfire\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedSpitfire", &SpitfireHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Spitfire Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedSpitfire", &SpitfireADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Spitfire Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedSpitfire", &SpitfireHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Spitfire Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedSpitfire", &SpitfireADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Spitfire Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedSpitfire", &SpitfireExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedSpitfire", &SpitfireFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Spitfire.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedSpitfire", &SpitfireMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Spitfire.");
                                        ImGui::SliderFloat("Max Distance", &SpitfireMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Spitfire.");
                                }
                            }
                        }
                            if (G7) {
                                if (ImGui::CollapsingHeader("G7 Scout", nullptr)) {
                                    ImGui::Text("G7 Scout");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##G7Aimbot", &G7Fire);
                                        ImGui::Checkbox("On ADS##G7Aimbot", &G7ADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int G7AimBind = static_cast<int>(Modules::Aimbot::G7AimBind);
                                        ImGui::Combo("Aim Bind##G7Aimbot", &G7AimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::G7AimBind = static_cast<InputKeyType>(G7AimBind);
                                        int G7ExtraBind = static_cast<int>(Modules::Aimbot::G7ExtraBind);
                                        ImGui::Combo("Extra Bind##G7Aimbot", &G7ExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::G7ExtraBind = static_cast<InputKeyType>(G7ExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##G7AdvancedHitbox", &G7ClosestHitbox);
                                        if (!G7ClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* G7HitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int G7HitboxTypeIndex = static_cast<int>(Modules::Aimbot::G7Hitbox);
                                            ImGui::Combo("Hitbox Type##G7AdvancedHitbox", &G7HitboxTypeIndex, G7HitboxTypes, IM_ARRAYSIZE(G7HitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::G7Hitbox = static_cast<HitboxType>(G7HitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedG7", &G7Speed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The G7\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedG7", &G7HipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The G7 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedG7", &G7ADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The G7 Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedG7", &G7HipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The G7 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedG7", &G7ADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The G7 Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedG7", &G7ExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedG7", &G7Deadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedG7", &G7FOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The G7.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedG7", &G7MinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the G7.");
                                        ImGui::SliderFloat("Max Distance", &G7MaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the G7.");
                                }
                            }
                        }
                        ImGui::Separator();
                            ImGui::Text("Heavy Weapons");
                            if (Flatline) {
                                if (ImGui::CollapsingHeader("Flatline", nullptr)) {
                                    ImGui::Text("Flatline");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##FlatlineAimbot", &FlatlineFire);
                                        ImGui::Checkbox("On ADS##FlatlineAimbot", &FlatlineADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int FlatlineAimBind = static_cast<int>(Modules::Aimbot::FlatlineAimBind);
                                        ImGui::Combo("Aim Bind##FlatlineAimbot", &FlatlineAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::FlatlineAimBind = static_cast<InputKeyType>(FlatlineAimBind);
                                        int FlatlineExtraBind = static_cast<int>(Modules::Aimbot::FlatlineExtraBind);
                                        ImGui::Combo("Extra Bind##FlatlineAimbot", &FlatlineExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::FlatlineExtraBind = static_cast<InputKeyType>(FlatlineExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##FlatlineAdvancedHitbox", &FlatlineClosestHitbox);
                                        if (!FlatlineClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* FlatlineHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int FlatlineHitboxTypeIndex = static_cast<int>(Modules::Aimbot::FlatlineHitbox);
                                            ImGui::Combo("Hitbox Type##FlatlineAdvancedHitbox", &FlatlineHitboxTypeIndex, FlatlineHitboxTypes, IM_ARRAYSIZE(FlatlineHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::FlatlineHitbox = static_cast<HitboxType>(FlatlineHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedFlatline", &FlatlineSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Flatline\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedFlatline", &FlatlineHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Flatline Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedFlatline", &FlatlineADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Flatline Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedFlatline", &FlatlineHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Flatline Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedFlatline", &FlatlineADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Flatline Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedFlatline", &FlatlineExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedFlatline", &FlatlineDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedFlatline", &FlatlineFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Flatline.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedFlatline", &FlatlineMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Flatline.");
                                        ImGui::SliderFloat("Max Distance", &FlatlineMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Flatline.");
                                }
                            }
                        }
                            if (Hemlock) {
                                if (ImGui::CollapsingHeader("Hemlock", nullptr)) {
                                    ImGui::Text("Hemlock");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##HemlockAimbot", &HemlockFire);
                                        ImGui::Checkbox("On ADS##HemlockAimbot", &HemlockADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int HemlockAimBind = static_cast<int>(Modules::Aimbot::HemlockAimBind);
                                        ImGui::Combo("Aim Bind##HemlockAimbot", &HemlockAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::HemlockAimBind = static_cast<InputKeyType>(HemlockAimBind);
                                        int HemlockExtraBind = static_cast<int>(Modules::Aimbot::HemlockExtraBind);
                                        ImGui::Combo("Extra Bind##HemlockAimbot", &HemlockExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::HemlockExtraBind = static_cast<InputKeyType>(HemlockExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##HemlockAdvancedHitbox", &HemlockClosestHitbox);
                                        if (!HemlockClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* HemlockHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int HemlockHitboxTypeIndex = static_cast<int>(Modules::Aimbot::HemlockHitbox);
                                            ImGui::Combo("Hitbox Type##HemlockAdvancedHitbox", &HemlockHitboxTypeIndex, HemlockHitboxTypes, IM_ARRAYSIZE(HemlockHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::HemlockHitbox = static_cast<HitboxType>(HemlockHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedHemlock", &HemlockSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Hemlock\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedHemlock", &HemlockHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Hemlock Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedHemlock", &HemlockADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Hemlock Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedHemlock", &HemlockHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Hemlock Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedHemlock", &HemlockADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Hemlock Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedHemlock", &HemlockExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedHemlock", &HemlockDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedHemlock", &HemlockFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Hemlock.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedHemlock", &HemlockMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Hemlock.");
                                        ImGui::SliderFloat("Max Distance", &HemlockMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Hemlock.");
                                }
                            }
                        }
                            if (Repeater) {
                                if (ImGui::CollapsingHeader("30-30 Repeater", nullptr)) {
                                    ImGui::Text("30-30 Repeater");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##RepeaterAimbot", &RepeaterFire);
                                        ImGui::Checkbox("On ADS##RepeaterAimbot", &RepeaterADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int RepeaterAimBind = static_cast<int>(Modules::Aimbot::RepeaterAimBind);
                                        ImGui::Combo("Aim Bind##RepeaterAimbot", &RepeaterAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::RepeaterAimBind = static_cast<InputKeyType>(RepeaterAimBind);
                                        int RepeaterExtraBind = static_cast<int>(Modules::Aimbot::RepeaterExtraBind);
                                        ImGui::Combo("Extra Bind##RepeaterAimbot", &RepeaterExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::RepeaterExtraBind = static_cast<InputKeyType>(RepeaterExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##RepeaterAdvancedHitbox", &RepeaterClosestHitbox);
                                        if (!RepeaterClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* RepeaterHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int RepeaterHitboxTypeIndex = static_cast<int>(Modules::Aimbot::RepeaterHitbox);
                                            ImGui::Combo("Hitbox Type##RepeaterAdvancedHitbox", &RepeaterHitboxTypeIndex, RepeaterHitboxTypes, IM_ARRAYSIZE(RepeaterHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::RepeaterHitbox = static_cast<HitboxType>(RepeaterHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedRepeater", &RepeaterSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Repeater\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedRepeater", &RepeaterHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Repeater Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedRepeater", &RepeaterADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Repeater Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedRepeater", &RepeaterHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Repeater Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedRepeater", &RepeaterADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Repeater Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedRepeater", &RepeaterExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedRepeater", &RepeaterDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedRepeater", &RepeaterFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Repeater.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedRepeater", &RepeaterMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Repeater.");
                                        ImGui::SliderFloat("Max Distance", &RepeaterMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Repeater.");
                                }
                            }
                        }
                            if (Rampage) {
                                if (ImGui::CollapsingHeader("Rampage", nullptr)) {
                                    ImGui::Text("Rampage");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##RampageAimbot", &RampageFire);
                                        ImGui::Checkbox("On ADS##RampageAimbot", &RampageADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int RampageAimBind = static_cast<int>(Modules::Aimbot::RampageAimBind);
                                        ImGui::Combo("Aim Bind##RampageAimbot", &RampageAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::RampageAimBind = static_cast<InputKeyType>(RampageAimBind);
                                        int RampageExtraBind = static_cast<int>(Modules::Aimbot::RampageExtraBind);
                                        ImGui::Combo("Extra Bind##RampageAimbot", &RampageExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::RampageExtraBind = static_cast<InputKeyType>(RampageExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##RampageAdvancedHitbox", &RampageClosestHitbox);
                                        if (!RampageClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* RampageHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int RampageHitboxTypeIndex = static_cast<int>(Modules::Aimbot::RampageHitbox);
                                            ImGui::Combo("Hitbox Type##RampageAdvancedHitbox", &RampageHitboxTypeIndex, RampageHitboxTypes, IM_ARRAYSIZE(RampageHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::RampageHitbox = static_cast<HitboxType>(RampageHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedRampage", &RampageSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Rampage\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedRampage", &RampageHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Rampage Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedRampage", &RampageADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Rampage Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedRampage", &RampageHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Rampage Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedRampage", &RampageADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Rampage Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedRampage", &RampageExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedRampage", &RampageDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedRampage", &RampageFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Rampage.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedRampage", &RampageMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Rampage.");
                                        ImGui::SliderFloat("Max Distance", &RampageMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Rampage.");
                                }
                            }
                        }
                            if (CARSMG) {
                                if (ImGui::CollapsingHeader("CAR SMG", nullptr)) {
                                    ImGui::Text("CAR SMG");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##CARSMGAimbot", &CARSMGFire);
                                        ImGui::Checkbox("On ADS##CARSMGAimbot", &CARSMGADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int CARSMGAimBind = static_cast<int>(Modules::Aimbot::CARSMGAimBind);
                                        ImGui::Combo("Aim Bind##CARSMGAimbot", &CARSMGAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::CARSMGAimBind = static_cast<InputKeyType>(CARSMGAimBind);
                                        int CARSMGExtraBind = static_cast<int>(Modules::Aimbot::CARSMGExtraBind);
                                        ImGui::Combo("Extra Bind##CARSMGAimbot", &CARSMGExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::CARSMGExtraBind = static_cast<InputKeyType>(CARSMGExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##CARSMGAdvancedHitbox", &CARSMGClosestHitbox);
                                        if (!CARSMGClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* CARSMGHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int CARSMGHitboxTypeIndex = static_cast<int>(Modules::Aimbot::CARSMGHitbox);
                                            ImGui::Combo("Hitbox Type##CARSMGAdvancedHitbox", &CARSMGHitboxTypeIndex, CARSMGHitboxTypes, IM_ARRAYSIZE(CARSMGHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::CARSMGHitbox = static_cast<HitboxType>(CARSMGHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedCARSMG", &CARSMGSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The CARSMG\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedCARSMG", &CARSMGHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The CARSMG Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedCARSMG", &CARSMGADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The CARSMG Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedCARSMG", &CARSMGHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The CARSMG Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedCARSMG", &CARSMGADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The CARSMG Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedCARSMG", &CARSMGExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedRepeater", &RepeaterDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedCARSMG", &CARSMGFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The CARSMG.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedCARSMG", &CARSMGMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the CARSMG.");
                                        ImGui::SliderFloat("Max Distance", &CARSMGMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the CARSMG.");
                                }
                            }
                        }
                        ImGui::Separator();
                            ImGui::Text("Energy Weapons");
                            if (Havoc) {
                                if (ImGui::CollapsingHeader("Havoc", nullptr)) {
                                    ImGui::Text("Havoc");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##HavocAimbot", &HavocFire);
                                        ImGui::Checkbox("On ADS##HavocAimbot", &HavocADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int HavocAimBind = static_cast<int>(Modules::Aimbot::HavocAimBind);
                                        ImGui::Combo("Aim Bind##HavocAimbot", &HavocAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::HavocAimBind = static_cast<InputKeyType>(HavocAimBind);
                                        int HavocExtraBind = static_cast<int>(Modules::Aimbot::HavocExtraBind);
                                        ImGui::Combo("Extra Bind##HavocAimbot", &HavocExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::HavocExtraBind = static_cast<InputKeyType>(HavocExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##HavocAdvancedHitbox", &HavocClosestHitbox);
                                        if (!HavocClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* HavocHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int HavocHitboxTypeIndex = static_cast<int>(Modules::Aimbot::HavocHitbox);
                                            ImGui::Combo("Hitbox Type##HavocAdvancedHitbox", &HavocHitboxTypeIndex, HavocHitboxTypes, IM_ARRAYSIZE(HavocHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::HavocHitbox = static_cast<HitboxType>(HavocHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedHavoc", &HavocSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Havoc\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedHavoc", &HavocHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Havoc Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedHavoc", &HavocADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Havoc Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedHavoc", &HavocHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Havoc Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedHavoc", &HavocADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Havoc Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedHavoc", &HavocExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedHavoc", &HavocDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedHavoc", &HavocFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Havoc.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedHavoc", &HavocMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Havoc.");
                                        ImGui::SliderFloat("Max Distance", &HavocMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Havoc.");
                                }
                            }
                        }
                            if (Devotion) {
                                if (ImGui::CollapsingHeader("Devotion", nullptr)) {
                                    ImGui::Text("Devotion");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##DevotionAimbot", &DevotionFire);
                                        ImGui::Checkbox("On ADS##DevotionAimbot", &DevotionADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int DevotionAimBind = static_cast<int>(Modules::Aimbot::DevotionAimBind);
                                        ImGui::Combo("Aim Bind##DevotionAimbot", &DevotionAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::DevotionAimBind = static_cast<InputKeyType>(DevotionAimBind);
                                        int DevotionExtraBind = static_cast<int>(Modules::Aimbot::DevotionExtraBind);
                                        ImGui::Combo("Extra Bind##DevotionAimbot", &DevotionExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::DevotionExtraBind = static_cast<InputKeyType>(DevotionExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##DevotionAdvancedHitbox", &DevotionClosestHitbox);
                                        if (!DevotionClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* DevotionHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int DevotionHitboxTypeIndex = static_cast<int>(Modules::Aimbot::DevotionHitbox);
                                            ImGui::Combo("Hitbox Type##DevotionAdvancedHitbox", &DevotionHitboxTypeIndex, DevotionHitboxTypes, IM_ARRAYSIZE(DevotionHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::DevotionHitbox = static_cast<HitboxType>(DevotionHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedDevotion", &DevotionSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Devotion\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedDevotion", &DevotionHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Devotion Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedDevotion", &DevotionADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Devotion Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedDevotion", &DevotionHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Devotion Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedDevotion", &DevotionADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Devotion Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedDevotion", &DevotionExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedDevotion", &DevotionDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedDevotion", &DevotionFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Devotion.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedDevotion", &DevotionMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Devotion.");
                                        ImGui::SliderFloat("Max Distance", &DevotionMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Devotion.");
                                }
                            }
                        }
                            if (LSTAR) {
                                if (ImGui::CollapsingHeader("LSTAR", nullptr)) {
                                    ImGui::Text("LSTAR");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##LSTARAimbot", &LSTARFire);
                                        ImGui::Checkbox("On ADS##LSTARAimbot", &LSTARADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int LSTARAimBind = static_cast<int>(Modules::Aimbot::LSTARAimBind);
                                        ImGui::Combo("Aim Bind##LSTARAimbot", &LSTARAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::LSTARAimBind = static_cast<InputKeyType>(LSTARAimBind);
                                        int LSTARExtraBind = static_cast<int>(Modules::Aimbot::LSTARExtraBind);
                                        ImGui::Combo("Extra Bind##LSTARAimbot", &LSTARExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::LSTARExtraBind = static_cast<InputKeyType>(LSTARExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##LSTARAdvancedHitbox", &LSTARClosestHitbox);
                                        if (!LSTARClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* LSTARHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int LSTARHitboxTypeIndex = static_cast<int>(Modules::Aimbot::LSTARHitbox);
                                            ImGui::Combo("Hitbox Type##LSTARAdvancedHitbox", &LSTARHitboxTypeIndex, LSTARHitboxTypes, IM_ARRAYSIZE(LSTARHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::LSTARHitbox = static_cast<HitboxType>(LSTARHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedLSTAR", &LSTARSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The LSTAR\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedLSTAR", &LSTARHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The LSTAR Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedLSTAR", &LSTARADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The LSTAR Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedLSTAR", &LSTARHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The LSTAR Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedLSTAR", &LSTARADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The LSTAR Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedLSTAR", &LSTARExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedLSTAR", &LSTARDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedLSTAR", &LSTARFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The LSTAR.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedLSTAR", &LSTARMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the LSTAR.");
                                        ImGui::SliderFloat("Max Distance", &LSTARMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the LSTAR.");
                                }
                            }
                        }
                            if (TripleTake) {
                                if (ImGui::CollapsingHeader("Triple Take", nullptr)) {
                                    ImGui::Text("Triple Take");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##TripleTakeAimbot", &TripleTakeFire);
                                        ImGui::Checkbox("On ADS##TripleTakeAimbot", &TripleTakeADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int TripleTakeAimBind = static_cast<int>(Modules::Aimbot::TripleTakeAimBind);
                                        ImGui::Combo("Aim Bind##TripleTakeAimbot", &TripleTakeAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::TripleTakeAimBind = static_cast<InputKeyType>(TripleTakeAimBind);
                                        int TripleTakeExtraBind = static_cast<int>(Modules::Aimbot::TripleTakeExtraBind);
                                        ImGui::Combo("Extra Bind##TripleTakeAimbot", &TripleTakeExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::TripleTakeExtraBind = static_cast<InputKeyType>(TripleTakeExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##TripleTakeAdvancedHitbox", &TripleTakeClosestHitbox);
                                        if (!TripleTakeClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* TripleTakeHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int TripleTakeHitboxTypeIndex = static_cast<int>(Modules::Aimbot::TripleTakeHitbox);
                                            ImGui::Combo("Hitbox Type##TripleTakeAdvancedHitbox", &TripleTakeHitboxTypeIndex, TripleTakeHitboxTypes, IM_ARRAYSIZE(TripleTakeHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::TripleTakeHitbox = static_cast<HitboxType>(TripleTakeHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedTripleTake", &TripleTakeSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The TripleTake\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedTripleTake", &TripleTakeHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The TripleTake Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedTripleTake", &TripleTakeADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The TripleTake Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedTripleTake", &TripleTakeHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The TripleTake Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedTripleTake", &TripleTakeADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The TripleTake Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedTripleTake", &TripleTakeExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedTripleTake", &TripleTakeDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedTripleTake", &TripleTakeFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The TripleTake.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedTripleTake", &TripleTakeMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the TripleTake.");
                                        ImGui::SliderFloat("Max Distance", &TripleTakeMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the TripleTake.");
                                }
                            }
                        }
                            if (Volt) {
                                if (ImGui::CollapsingHeader("Volt", nullptr)) {
                                    ImGui::Text("Volt");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##VoltAimbot", &VoltFire);
                                        ImGui::Checkbox("On ADS##VoltAimbot", &VoltADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int VoltAimBind = static_cast<int>(Modules::Aimbot::VoltAimBind);
                                        ImGui::Combo("Aim Bind##VoltAimbot", &VoltAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::VoltAimBind = static_cast<InputKeyType>(VoltAimBind);
                                        int VoltExtraBind = static_cast<int>(Modules::Aimbot::VoltExtraBind);
                                        ImGui::Combo("Extra Bind##VoltAimbot", &VoltExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::VoltExtraBind = static_cast<InputKeyType>(VoltExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##VoltAdvancedHitbox", &VoltClosestHitbox);
                                        if (!VoltClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* VoltHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int VoltHitboxTypeIndex = static_cast<int>(Modules::Aimbot::VoltHitbox);
                                            ImGui::Combo("Hitbox Type##VoltAdvancedHitbox", &VoltHitboxTypeIndex, VoltHitboxTypes, IM_ARRAYSIZE(VoltHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::VoltHitbox = static_cast<HitboxType>(VoltHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedVolt", &VoltSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Volt\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedVolt", &VoltHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Volt Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedVolt", &VoltADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Volt Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedVolt", &VoltHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Volt Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedVolt", &VoltADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Volt Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedVolt", &VoltExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedVolt", &VoltDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedVolt", &VoltFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Volt.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedVolt", &VoltMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Volt.");
                                        ImGui::SliderFloat("Max Distance", &VoltMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Volt.");
                                }
                            }
                        }
                            if (Nemesis) {
                                if (ImGui::CollapsingHeader("Nemesis", nullptr)) {
                                    ImGui::Text("Nemesis");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##NemesisAimbot", &NemesisFire);
                                        ImGui::Checkbox("On ADS##NemesisAimbot", &NemesisADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int NemesisAimBind = static_cast<int>(Modules::Aimbot::NemesisAimBind);
                                        ImGui::Combo("Aim Bind##NemesisAimbot", &NemesisAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::NemesisAimBind = static_cast<InputKeyType>(NemesisAimBind);
                                        int NemesisExtraBind = static_cast<int>(Modules::Aimbot::NemesisExtraBind);
                                        ImGui::Combo("Extra Bind##NemesisAimbot", &NemesisExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::NemesisExtraBind = static_cast<InputKeyType>(NemesisExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##NemesisAdvancedHitbox", &NemesisClosestHitbox);
                                        if (!NemesisClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* NemesisHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int NemesisHitboxTypeIndex = static_cast<int>(Modules::Aimbot::NemesisHitbox);
                                            ImGui::Combo("Hitbox Type##NemesisAdvancedHitbox", &NemesisHitboxTypeIndex, NemesisHitboxTypes, IM_ARRAYSIZE(NemesisHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::NemesisHitbox = static_cast<HitboxType>(NemesisHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedNemesis", &NemesisSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Nemesis\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedNemesis", &NemesisHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Nemesis Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedNemesis", &NemesisADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Nemesis Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedNemesis", &NemesisHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Nemesis Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedNemesis", &NemesisADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Nemesis Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedNemesis", &NemesisExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedNemesis", &NemesisDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedNemesis", &NemesisFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Nemesis.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedNemesis", &NemesisMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Nemesis.");
                                        ImGui::SliderFloat("Max Distance", &NemesisMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Nemesis.");
                                }
                            }
                        }
                        ImGui::Separator();
                            ImGui::Text("Shotguns");
                            if (Mozambique) {
                                if (ImGui::CollapsingHeader("Mozambique", nullptr)) {
                                    ImGui::Text("Mozambique");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##MozambiqueAimbot", &MozambiqueFire);
                                        ImGui::Checkbox("On ADS##MozambiqueAimbot", &MozambiqueADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int MozambiqueAimBind = static_cast<int>(Modules::Aimbot::MozambiqueAimBind);
                                        ImGui::Combo("Aim Bind##MozambiqueAimbot", &MozambiqueAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::MozambiqueAimBind = static_cast<InputKeyType>(MozambiqueAimBind);
                                        int MozambiqueExtraBind = static_cast<int>(Modules::Aimbot::MozambiqueExtraBind);
                                        ImGui::Combo("Extra Bind##MozambiqueAimbot", &MozambiqueExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::MozambiqueExtraBind = static_cast<InputKeyType>(MozambiqueExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##MozambiqueAdvancedHitbox", &MozambiqueClosestHitbox);
                                        if (!MozambiqueClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* MozambiqueHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int MozambiqueHitboxTypeIndex = static_cast<int>(Modules::Aimbot::MozambiqueHitbox);
                                            ImGui::Combo("Hitbox Type##MozambiqueAdvancedHitbox", &MozambiqueHitboxTypeIndex, MozambiqueHitboxTypes, IM_ARRAYSIZE(MozambiqueHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::MozambiqueHitbox = static_cast<HitboxType>(MozambiqueHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedMozambique", &MozambiqueSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Mozambique\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedMozambique", &MozambiqueHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mozambique Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedMozambique", &MozambiqueADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mozambique Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedMozambique", &MozambiqueHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mozambique Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedMozambique", &MozambiqueADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mozambique Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedMozambique", &MozambiqueExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedMozambique", &MozambiqueDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedMozambique", &MozambiqueFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Mozambique.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedMozambique", &MozambiqueMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Mozambique.");
                                        ImGui::SliderFloat("Max Distance", &MozambiqueMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Mozambique.");
                                }
                            }
                        }
                            if (EVA8) {
                                if (ImGui::CollapsingHeader("EVA8", nullptr)) {
                                    ImGui::Text("EVA8");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##EVA8Aimbot", &EVA8Fire);
                                        ImGui::Checkbox("On ADS##EVA8Aimbot", &EVA8ADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int EVA8AimBind = static_cast<int>(Modules::Aimbot::EVA8AimBind);
                                        ImGui::Combo("Aim Bind##EVA8Aimbot", &EVA8AimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::EVA8AimBind = static_cast<InputKeyType>(EVA8AimBind);
                                        int EVA8ExtraBind = static_cast<int>(Modules::Aimbot::EVA8ExtraBind);
                                        ImGui::Combo("Extra Bind##EVA8Aimbot", &EVA8ExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::EVA8ExtraBind = static_cast<InputKeyType>(EVA8ExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##EVA8AdvancedHitbox", &EVA8ClosestHitbox);
                                        if (!EVA8ClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* EVA8HitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int EVA8HitboxTypeIndex = static_cast<int>(Modules::Aimbot::EVA8Hitbox);
                                            ImGui::Combo("Hitbox Type##EVA8AdvancedHitbox", &EVA8HitboxTypeIndex, EVA8HitboxTypes, IM_ARRAYSIZE(EVA8HitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::EVA8Hitbox = static_cast<HitboxType>(EVA8HitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedEVA8", &EVA8Speed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The EVA8\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedEVA8", &EVA8HipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The EVA8 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedEVA8", &EVA8ADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The EVA8 Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedEVA8", &EVA8HipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The EVA8 Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedEVA8", &EVA8ADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The EVA8 Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedEVA8", &EVA8ExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedEVA8", &EVA8Deadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedEVA8", &EVA8FOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The EVA8.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedEVA8", &EVA8MinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the EVA8.");
                                        ImGui::SliderFloat("Max Distance", &EVA8MaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the EVA8.");
                                }
                            }
                        }
                            if (Peacekeeper) {
                                if (ImGui::CollapsingHeader("Peacekeeper", nullptr)) {
                                    ImGui::Text("Peacekeeper");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##PeacekeeperAimbot", &PeacekeeperFire);
                                        ImGui::Checkbox("On ADS##PeacekeeperAimbot", &PeacekeeperADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int PeacekeeperAimBind = static_cast<int>(Modules::Aimbot::PeacekeeperAimBind);
                                        ImGui::Combo("Aim Bind##PeacekeeperAimbot", &PeacekeeperAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::PeacekeeperAimBind = static_cast<InputKeyType>(PeacekeeperAimBind);
                                        int PeacekeeperExtraBind = static_cast<int>(Modules::Aimbot::PeacekeeperExtraBind);
                                        ImGui::Combo("Extra Bind##PeacekeeperAimbot", &PeacekeeperExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::PeacekeeperExtraBind = static_cast<InputKeyType>(PeacekeeperExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##PeacekeeperAdvancedHitbox", &PeacekeeperClosestHitbox);
                                        if (!PeacekeeperClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* PeacekeeperHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int PeacekeeperHitboxTypeIndex = static_cast<int>(Modules::Aimbot::PeacekeeperHitbox);
                                            ImGui::Combo("Hitbox Type##PeacekeeperAdvancedHitbox", &PeacekeeperHitboxTypeIndex, PeacekeeperHitboxTypes, IM_ARRAYSIZE(PeacekeeperHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::PeacekeeperHitbox = static_cast<HitboxType>(PeacekeeperHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedPeacekeeper", &PeacekeeperSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Peacekeeper\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedPeacekeeper", &PeacekeeperHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Peacekeeper Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedPeacekeeper", &PeacekeeperADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Peacekeeper Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedPeacekeeper", &PeacekeeperHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Peacekeeper Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedPeacekeeper", &PeacekeeperADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Peacekeeper Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedPeacekeeper", &PeacekeeperExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedPeacekeeper", &PeacekeeperDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedPeacekeeper", &PeacekeeperFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Peacekeeper.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedPeacekeeper", &PeacekeeperMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Peacekeeper.");
                                        ImGui::SliderFloat("Max Distance", &PeacekeeperMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Peacekeeper.");
                                }
                            }
                        }
                            if (Mastiff) {
                                if (ImGui::CollapsingHeader("Mastiff", nullptr)) {
                                    ImGui::Text("Mastiff");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##MastiffAimbot", &MastiffFire);
                                        ImGui::Checkbox("On ADS##MastiffAimbot", &MastiffADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int MastiffAimBind = static_cast<int>(Modules::Aimbot::MastiffAimBind);
                                        ImGui::Combo("Aim Bind##MastiffAimbot", &MastiffAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::MastiffAimBind = static_cast<InputKeyType>(MastiffAimBind);
                                        int MastiffExtraBind = static_cast<int>(Modules::Aimbot::MastiffExtraBind);
                                        ImGui::Combo("Extra Bind##MastiffAimbot", &MastiffExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::MastiffExtraBind = static_cast<InputKeyType>(MastiffExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##MastiffAdvancedHitbox", &MastiffClosestHitbox);
                                        if (!MastiffClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* MastiffHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int MastiffHitboxTypeIndex = static_cast<int>(Modules::Aimbot::MastiffHitbox);
                                            ImGui::Combo("Hitbox Type##MastiffAdvancedHitbox", &MastiffHitboxTypeIndex, MastiffHitboxTypes, IM_ARRAYSIZE(MastiffHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::MastiffHitbox = static_cast<HitboxType>(MastiffHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedMastiff", &MastiffSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Mastiff\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedMastiff", &MastiffHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mastiff Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedMastiff", &MastiffADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mastiff Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedMastiff", &MastiffHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mastiff Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedMastiff", &MastiffADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Mastiff Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedMastiff", &MastiffExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedMastiff", &MastiffDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedMastiff", &MastiffFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Mastiff.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedMastiff", &MastiffMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Mastiff.");
                                        ImGui::SliderFloat("Max Distance", &MastiffMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Mastiff.");
                                }
                            }
                        }
                        ImGui::Separator();
                            ImGui::Text("Snipers");
                            if (Longbow) {
                                if (ImGui::CollapsingHeader("Longbow", nullptr)) {
                                    ImGui::Text("Longbow");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##LongbowAimbot", &LongbowFire);
                                        ImGui::Checkbox("On ADS##LongbowAimbot", &LongbowADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int LongbowAimBind = static_cast<int>(Modules::Aimbot::LongbowAimBind);
                                        ImGui::Combo("Aim Bind##LongbowAimbot", &LongbowAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::LongbowAimBind = static_cast<InputKeyType>(LongbowAimBind);
                                        int LongbowExtraBind = static_cast<int>(Modules::Aimbot::LongbowExtraBind);
                                        ImGui::Combo("Extra Bind##LongbowAimbot", &LongbowExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::LongbowExtraBind = static_cast<InputKeyType>(LongbowExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##LongbowAdvancedHitbox", &LongbowClosestHitbox);
                                        if (!LongbowClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* LongbowHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int LongbowHitboxTypeIndex = static_cast<int>(Modules::Aimbot::LongbowHitbox);
                                            ImGui::Combo("Hitbox Type##LongbowAdvancedHitbox", &LongbowHitboxTypeIndex, LongbowHitboxTypes, IM_ARRAYSIZE(LongbowHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::LongbowHitbox = static_cast<HitboxType>(LongbowHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedLongbow", &LongbowSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Longbow\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedLongbow", &LongbowHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Longbow Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedLongbow", &LongbowADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Longbow Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedLongbow", &LongbowHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Longbow Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedLongbow", &LongbowADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Longbow Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedLongbow", &LongbowExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedLongbow", &LongbowDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedLongbow", &LongbowFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Longbow.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedLongbow", &LongbowMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Longbow.");
                                        ImGui::SliderFloat("Max Distance", &LongbowMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Longbow.");
                                }
                            }
                        }
                            if (ChargeRifle) {
                                if (ImGui::CollapsingHeader("Charge Rifle", nullptr)) {
                                    ImGui::Text("Charge Rifle");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##ChargeRifleAimbot", &ChargeRifleFire);
                                        ImGui::Checkbox("On ADS##ChargeRifleAimbot", &ChargeRifleADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int ChargeRifleAimBind = static_cast<int>(Modules::Aimbot::ChargeRifleAimBind);
                                        ImGui::Combo("Aim Bind##ChargeRifleAimbot", &ChargeRifleAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::ChargeRifleAimBind = static_cast<InputKeyType>(ChargeRifleAimBind);
                                        int ChargeRifleExtraBind = static_cast<int>(Modules::Aimbot::ChargeRifleExtraBind);
                                        ImGui::Combo("Extra Bind##ChargeRifleAimbot", &ChargeRifleExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::ChargeRifleExtraBind = static_cast<InputKeyType>(ChargeRifleExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##ChargeRifleAdvancedHitbox", &ChargeRifleClosestHitbox);
                                        if (!ChargeRifleClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* ChargeRifleHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int ChargeRifleHitboxTypeIndex = static_cast<int>(Modules::Aimbot::ChargeRifleHitbox);
                                            ImGui::Combo("Hitbox Type##ChargeRifleAdvancedHitbox", &ChargeRifleHitboxTypeIndex, ChargeRifleHitboxTypes, IM_ARRAYSIZE(ChargeRifleHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::ChargeRifleHitbox = static_cast<HitboxType>(ChargeRifleHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedChargeRifle", &ChargeRifleSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The ChargeRifle\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedChargeRifle", &ChargeRifleHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ChargeRifle Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedChargeRifle", &ChargeRifleADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ChargeRifle Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedChargeRifle", &ChargeRifleHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ChargeRifle Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedChargeRifle", &ChargeRifleADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ChargeRifle Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedChargeRifle", &ChargeRifleExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedChargeRifle", &ChargeRifleDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedChargeRifle", &ChargeRifleFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The ChargeRifle.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedChargeRifle", &ChargeRifleMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the ChargeRifle.");
                                        ImGui::SliderFloat("Max Distance", &ChargeRifleMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the ChargeRifle.");
                                }
                            }
                        }
                            if (Sentinel) {
                                if (ImGui::CollapsingHeader("Sentinel", nullptr)) {
                                    ImGui::Text("Sentinel");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##SentinelAimbot", &SentinelFire);
                                        ImGui::Checkbox("On ADS##SentinelAimbot", &SentinelADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int SentinelAimBind = static_cast<int>(Modules::Aimbot::SentinelAimBind);
                                        ImGui::Combo("Aim Bind##SentinelAimbot", &SentinelAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::SentinelAimBind = static_cast<InputKeyType>(SentinelAimBind);
                                        int SentinelExtraBind = static_cast<int>(Modules::Aimbot::SentinelExtraBind);
                                        ImGui::Combo("Extra Bind##SentinelAimbot", &SentinelExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::SentinelExtraBind = static_cast<InputKeyType>(SentinelExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##SentinelAdvancedHitbox", &SentinelClosestHitbox);
                                        if (!SentinelClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* SentinelHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int SentinelHitboxTypeIndex = static_cast<int>(Modules::Aimbot::SentinelHitbox);
                                            ImGui::Combo("Hitbox Type##SentinelAdvancedHitbox", &SentinelHitboxTypeIndex, SentinelHitboxTypes, IM_ARRAYSIZE(SentinelHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::SentinelHitbox = static_cast<HitboxType>(SentinelHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedSentinel", &SentinelSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Sentinel\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedSentinel", &SentinelHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Sentinel Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedSentinel", &SentinelADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Sentinel Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedSentinel", &SentinelHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Sentinel Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedSentinel", &SentinelADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Sentinel Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedSentinel", &SentinelExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedSentinel", &SentinelDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedSentinel", &SentinelFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Sentinel.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedSentinel", &SentinelMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Sentinel.");
                                        ImGui::SliderFloat("Max Distance", &SentinelMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Sentinel.");
                                }
                            }
                        }
                        ImGui::Separator();
                            ImGui::Text("Legendary Weapons");
                            if (Wingman) {
                                if (ImGui::CollapsingHeader("Wingman", nullptr)) {
                                    ImGui::Text("Wingman");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##WingmanAimbot", &WingmanFire);
                                        ImGui::Checkbox("On ADS##WingmanAimbot", &WingmanADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int WingmanAimBind = static_cast<int>(Modules::Aimbot::WingmanAimBind);
                                        ImGui::Combo("Aim Bind##WingmanAimbot", &WingmanAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::WingmanAimBind = static_cast<InputKeyType>(WingmanAimBind);
                                        int WingmanExtraBind = static_cast<int>(Modules::Aimbot::WingmanExtraBind);
                                        ImGui::Combo("Extra Bind##WingmanAimbot", &WingmanExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::WingmanExtraBind = static_cast<InputKeyType>(WingmanExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##WingmanAdvancedHitbox", &WingmanClosestHitbox);
                                        if (!WingmanClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* WingmanHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int WingmanHitboxTypeIndex = static_cast<int>(Modules::Aimbot::WingmanHitbox);
                                            ImGui::Combo("Hitbox Type##WingmanAdvancedHitbox", &WingmanHitboxTypeIndex, WingmanHitboxTypes, IM_ARRAYSIZE(WingmanHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::WingmanHitbox = static_cast<HitboxType>(WingmanHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedWingman", &WingmanSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Wingman\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedWingman", &WingmanHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Wingman Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedWingman", &WingmanADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Wingman Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedWingman", &WingmanHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Wingman Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedWingman", &WingmanADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Wingman Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedWingman", &WingmanExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedWingman", &WingmanDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedWingman", &WingmanFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Wingman.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedWingman", &WingmanMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Wingman.");
                                        ImGui::SliderFloat("Max Distance", &WingmanMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Wingman.");
                                }
                            }
                        }
                            if (Prowler) {
                                if (ImGui::CollapsingHeader("Prowler", nullptr)) {
                                    ImGui::Text("Prowler");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##ProwlerAimbot", &ProwlerFire);
                                        ImGui::Checkbox("On ADS##ProwlerAimbot", &ProwlerADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int ProwlerAimBind = static_cast<int>(Modules::Aimbot::ProwlerAimBind);
                                        ImGui::Combo("Aim Bind##ProwlerAimbot", &ProwlerAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::ProwlerAimBind = static_cast<InputKeyType>(ProwlerAimBind);
                                        int ProwlerExtraBind = static_cast<int>(Modules::Aimbot::ProwlerExtraBind);
                                        ImGui::Combo("Extra Bind##ProwlerAimbot", &ProwlerExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::ProwlerExtraBind = static_cast<InputKeyType>(ProwlerExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##ProwlerAdvancedHitbox", &ProwlerClosestHitbox);
                                        if (!ProwlerClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* ProwlerHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int ProwlerHitboxTypeIndex = static_cast<int>(Modules::Aimbot::ProwlerHitbox);
                                            ImGui::Combo("Hitbox Type##ProwlerAdvancedHitbox", &ProwlerHitboxTypeIndex, ProwlerHitboxTypes, IM_ARRAYSIZE(ProwlerHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::ProwlerHitbox = static_cast<HitboxType>(ProwlerHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedProwler", &ProwlerSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Prowler\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedProwler", &ProwlerHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Prowler Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedProwler", &ProwlerADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Prowler Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedProwler", &ProwlerHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Prowler Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedProwler", &ProwlerADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Prowler Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedProwler", &ProwlerExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedProwler", &ProwlerDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedProwler", &ProwlerFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Prowler.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedProwler", &ProwlerMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Prowler.");
                                        ImGui::SliderFloat("Max Distance", &ProwlerMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Prowler.");
                                }
                            }
                        }
                            if (Bocek) {
                                if (ImGui::CollapsingHeader("Bocek", nullptr)) {
                                    ImGui::Text("Bocek");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##BocekAimbot", &BocekFire);
                                        ImGui::Checkbox("On ADS##BocekAimbot", &BocekADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int BocekAimBind = static_cast<int>(Modules::Aimbot::BocekAimBind);
                                        ImGui::Combo("Aim Bind##BocekAimbot", &BocekAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::BocekAimBind = static_cast<InputKeyType>(BocekAimBind);
                                        int BocekExtraBind = static_cast<int>(Modules::Aimbot::BocekExtraBind);
                                        ImGui::Combo("Extra Bind##BocekAimbot", &BocekExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::BocekExtraBind = static_cast<InputKeyType>(BocekExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##BocekAdvancedHitbox", &BocekClosestHitbox);
                                        if (!BocekClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* BocekHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int BocekHitboxTypeIndex = static_cast<int>(Modules::Aimbot::BocekHitbox);
                                            ImGui::Combo("Hitbox Type##BocekAdvancedHitbox", &BocekHitboxTypeIndex, BocekHitboxTypes, IM_ARRAYSIZE(BocekHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::BocekHitbox = static_cast<HitboxType>(BocekHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedBocek", &BocekSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Bocek\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedBocek", &BocekHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Bocek Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedBocek", &BocekADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Bocek Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedBocek", &BocekHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Bocek Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedBocek", &BocekADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Bocek Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedBocek", &BocekExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedBocek", &BocekDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedBocek", &BocekFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Bocek.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedBocek", &BocekMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Bocek.");
                                        ImGui::SliderFloat("Max Distance", &BocekMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Bocek.");
                                }
                            }
                        }
                            if (Kraber) {
                                if (ImGui::CollapsingHeader("Kraber", nullptr)) {
                                    ImGui::Text("Kraber");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##KraberAimbot", &KraberFire);
                                        ImGui::Checkbox("On ADS##KraberAimbot", &KraberADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int KraberAimBind = static_cast<int>(Modules::Aimbot::KraberAimBind);
                                        ImGui::Combo("Aim Bind##KraberAimbot", &KraberAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::KraberAimBind = static_cast<InputKeyType>(KraberAimBind);
                                        int KraberExtraBind = static_cast<int>(Modules::Aimbot::KraberExtraBind);
                                        ImGui::Combo("Extra Bind##KraberAimbot", &KraberExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::KraberExtraBind = static_cast<InputKeyType>(KraberExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##KraberAdvancedHitbox", &KraberClosestHitbox);
                                        if (!KraberClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* KraberHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int KraberHitboxTypeIndex = static_cast<int>(Modules::Aimbot::KraberHitbox);
                                            ImGui::Combo("Hitbox Type##KraberAdvancedHitbox", &KraberHitboxTypeIndex, KraberHitboxTypes, IM_ARRAYSIZE(KraberHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::KraberHitbox = static_cast<HitboxType>(KraberHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedKraber", &KraberSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The Kraber\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedKraber", &KraberHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Kraber Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedKraber", &KraberADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Kraber Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedKraber", &KraberHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Kraber Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedKraber", &KraberADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The Kraber Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedKraber", &KraberExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedKraber", &KraberDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedKraber", &KraberFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The Kraber.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedKraber", &KraberMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the Kraber.");
                                        ImGui::SliderFloat("Max Distance", &KraberMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the Kraber.");
                                }
                            }
                        }
                            if (Knife) {
                                if (ImGui::CollapsingHeader("Throwing Knife", nullptr)) {
                                    ImGui::Text("Throwing Knife");
                                    if (Modules::Aimbot::BindMethod == 0) { //OnFire & OnADS
                                        ImGui::Checkbox("On Fire##ThrowingKnifeAimbot", &ThrowingKnifeFire);
                                        ImGui::Checkbox("On ADS##ThrowingKnifeAimbot", &ThrowingKnifeADS);
                                    }
                                    if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                                        int ThrowingKnifeAimBind = static_cast<int>(Modules::Aimbot::ThrowingKnifeAimBind);
                                        ImGui::Combo("Aim Bind##ThrowingKnifeAimbot", &ThrowingKnifeAimBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::ThrowingKnifeAimBind = static_cast<InputKeyType>(ThrowingKnifeAimBind);
                                        int ThrowingKnifeExtraBind = static_cast<int>(Modules::Aimbot::ThrowingKnifeExtraBind);
                                        ImGui::Combo("Extra Bind##ThrowingKnifeAimbot", &ThrowingKnifeExtraBind, InputKeyTypeNames, IM_ARRAYSIZE(InputKeyTypeNames));
                                        Modules::Aimbot::ThrowingKnifeExtraBind = static_cast<InputKeyType>(ThrowingKnifeExtraBind);
                                    }
                                    if (AimbotMode == 0) {
                                        ImGui::Text("Hitbox");
                                        ImGui::Checkbox("Closest To Crosshair##ThrowingKnifeAdvancedHitbox", &ThrowingKnifeClosestHitbox);
                                        if (!ThrowingKnifeClosestHitbox) {
                                            ImGui::SameLine();
                                            const char* ThrowingKnifeHitboxTypes[] = {"Head", "Neck", "Upper Chest", "Lower Chest", "Stomach", "Hip"};
                                            int ThrowingKnifeHitboxTypeIndex = static_cast<int>(Modules::Aimbot::ThrowingKnifeHitbox);
                                            ImGui::Combo("Hitbox Type##ThrowingKnifeAdvancedHitbox", &ThrowingKnifeHitboxTypeIndex, ThrowingKnifeHitboxTypes, IM_ARRAYSIZE(ThrowingKnifeHitboxTypes));
                                            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Which bone the aimbot will aim at.");
                                            Modules::Aimbot::ThrowingKnifeHitbox = static_cast<HitboxType>(ThrowingKnifeHitboxTypeIndex);
                                        }
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Speed##AdvancedThrowingKnife", &ThrowingKnifeSpeed, 1, 100, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Speed Of The Aim-Assist For The ThrowingKnife\nHigher = Faster");
                                        ImGui::SliderFloat("Hipfire Smoothing##AdvancedThrowingKnife", &ThrowingKnifeHipfireSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ThrowingKnife Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##AdvancedThrowingKnife", &ThrowingKnifeADSSmooth, 0, 0.99, "%.3f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ThrowingKnife Whilst ADS.\nHigher = Smoother");
                                    }
                                    if (AimbotMode == 1) {
                                        ImGui::Text("Smoothing");
                                        ImGui::SliderFloat("Hipfire Smoothing##1AdvancedThrowingKnife", &ThrowingKnifeHipfireSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ThrowingKnife Whilst Hipfiring.\nHigher = Smoother");
                                        ImGui::SliderFloat("ADS Smoothing##1AdvancedThrowingKnife", &ThrowingKnifeADSSmooth1, 1, 1000, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("Smoothing Of The Aim-Assist For The ThrowingKnife Whilst ADS.\nHigher = Smoother");
                                        ImGui::SliderFloat("Extra Smoothing##1AdvancedThrowingKnife", &ThrowingKnifeExtraSmooth1, 1, 9999, "%.0f");
                                    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Increases the smoothing depending on the distance of the player.");
                                        ImGui::SliderFloat("Deadzone##AdvancedThrowingKnife", &ThrowingKnifeDeadzone, 0, 10, "%.03f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                            ImGui::SetTooltip("If the aimbot is close enough then the aimbot will stop trying to get any closer.");

                                        ImGui::Text("FOV");
                                        ImGui::SliderFloat("FOV##1AdvancedThrowingKnife", &ThrowingKnifeFOV1, 1, 90, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Field of View For The ThrowingKnife.");
                                        ImGui::Text("Distance");
                                        ImGui::SliderFloat("Min Distance##1AdvancedThrowingKnife", &ThrowingKnifeMinDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Minimum Distance for Aimbot to work whilst holding the ThrowingKnife.");
                                        ImGui::SliderFloat("Max Distance", &ThrowingKnifeMaxDistance1, 1, 500, "%.0f");
                                        if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                                        ImGui::SetTooltip("Maximum Distance for Aimbot to work whilst holding the ThrowingKnife.");
                                    }
                            }
                        }
                    }
                ImGui::EndChild();
                }

            ImGui::EndTabItem();
            UpdateAimList();
        }
    }

    bool Save() {
        try {
            Config::Aimbot::Enabled = AimbotEnabled;
            Config::Aimbot::AimbotMode = AimbotMode;
             Config::Aimbot::RCSEnabled = RCSEnabled;
            Config::Aimbot::HitBox = static_cast<int>(Modules::Aimbot::Hitbox);
            Config::Aimbot::ClosestHitbox = ClosestHitbox;
            Config::Aimbot::BindMethod = Modules::Aimbot::BindMethod;
            Config::Aimbot::AimBind = static_cast<int>(Modules::Aimbot::AimBind);
            Config::Aimbot::ExtraBind = static_cast<int>(Modules::Aimbot::ExtraBind);
            Config::Aimbot::OnFire = OnFire;
            Config::Aimbot::OnADS = OnADS;

            Config::Aimbot::VisCheck = VisCheck;
            Config::Aimbot::TeamCheck = TeamCheck;

            Config::Aimbot::PredictMovement = PredictMovement;
            Config::Aimbot::PredictBulletDrop = PredictBulletDrop;
            Config::Aimbot::Speed = Speed;
            Config::Aimbot::Smooth = Smooth;
            Config::Aimbot::Deadzone = Deadzone;
            Config::Aimbot::HipfireSmooth = HipfireSmooth;
            Config::Aimbot::ADSSmooth = ADSSmooth;
            Config::Aimbot::SmoothDistance = SmoothDistance;
            Config::Aimbot::Delay = Delay;
            Config::Aimbot::FOV = FOV;
            Config::Aimbot::ZoomScale = ZoomScale;
            Config::Aimbot::MinDistance = MinDistance;
            Config::Aimbot::HipfireDistance = HipfireDistance;
            Config::Aimbot::ZoomDistance = ZoomDistance;

            //Weapons
            //Light
            Config::Aimbot::P2020 = P2020;
            Config::Aimbot::RE45 = RE45;
            Config::Aimbot::Alternator = Alternator;
            Config::Aimbot::R99 = R99;
            Config::Aimbot::R301 = R301;
            Config::Aimbot::Spitfire = Spitfire;
            Config::Aimbot::G7 = G7;
            //Heavy
            Config::Aimbot::Flatline = Flatline;
            Config::Aimbot::Hemlock = Hemlock;
            Config::Aimbot::Repeater = Repeater;
            Config::Aimbot::Rampage = Rampage;
            Config::Aimbot::CARSMG = CARSMG;
            //Energy
            Config::Aimbot::Havoc = Havoc;
            Config::Aimbot::Devotion = Devotion;
            Config::Aimbot::LSTAR = LSTAR;
            Config::Aimbot::TripleTake = TripleTake;
            Config::Aimbot::Volt = Volt;
            Config::Aimbot::Nemesis = Nemesis;
            //Shotguns
            Config::Aimbot::Mozambique = Mozambique;
            Config::Aimbot::EVA8 = EVA8;
            Config::Aimbot::Peacekeeper = Peacekeeper;
            Config::Aimbot::Mastiff = Mastiff;
            //Snipers
            Config::Aimbot::Longbow = Longbow;
            Config::Aimbot::ChargeRifle = ChargeRifle;
            Config::Aimbot::Sentinel = Sentinel;
            //Legendary
            Config::Aimbot::Wingman = Wingman;
            Config::Aimbot::Prowler = Prowler;
            Config::Aimbot::Bocek = Bocek;
            Config::Aimbot::Kraber = Kraber;
            Config::Aimbot::Knife = Knife;

            //----------Advanced Settings----------//
            Config::Aimbot::AdvancedAim = AdvancedAim;
            Config::Aimbot::AdvancedSpeed = AdvancedSpeed;
            Config::Aimbot::AdvancedSmooth = AdvancedSmooth;
            //Aimbot Mode 0 - xap-client
            Config::Aimbot::AdvancedHipfireSmooth = AdvancedHipfireSmooth;
            Config::Aimbot::AdvancedADSSmooth = AdvancedADSSmooth;
            //Aimbot Mode 1 - Grinder
            Config::Aimbot::AdvancedHipfireSmooth1 = AdvancedHipfireSmooth1;
            Config::Aimbot::AdvancedADSSmooth1 = AdvancedADSSmooth1;
            Config::Aimbot::AdvancedExtraSmooth1 = AdvancedExtraSmooth1;
            Config::Aimbot::AdvancedDeadzone = AdvancedDeadzone;
            Config::Aimbot::AdvancedFOV1 = AdvancedFOV1;
            Config::Aimbot::AdvancedMinDistance1 = AdvancedMinDistance1;
            Config::Aimbot::AdvancedMaxDistance1 = AdvancedMaxDistance1;

            //OnFire and OnADS
            Config::Aimbot::P2020Fire = P2020Fire;
            Config::Aimbot::P2020ADS = P2020ADS;
            Config::Aimbot::RE45Fire = RE45Fire;
            Config::Aimbot::RE45ADS = RE45ADS;
            Config::Aimbot::AlternatorFire = AlternatorFire;
            Config::Aimbot::AlternatorADS = AlternatorADS;
            Config::Aimbot::R99Fire = R99Fire;
            Config::Aimbot::R99ADS = R99ADS;
            Config::Aimbot::R301Fire = R301Fire;
            Config::Aimbot::R301ADS = R301ADS;
            Config::Aimbot::SpitfireFire = SpitfireFire;
            Config::Aimbot::SpitfireADS = SpitfireADS;
            Config::Aimbot::G7Fire = G7Fire;
            Config::Aimbot::G7ADS = G7ADS;
            Config::Aimbot::FlatlineFire = FlatlineFire;
            Config::Aimbot::FlatlineADS = FlatlineADS;
            Config::Aimbot::HemlockFire = HemlockFire;
            Config::Aimbot::HemlockADS = HemlockADS;
            Config::Aimbot::RepeaterFire = RepeaterFire;
            Config::Aimbot::RepeaterADS = RepeaterADS;
            Config::Aimbot::RampageFire = RampageFire;
            Config::Aimbot::RampageADS = RampageADS;
            Config::Aimbot::CARSMGFire = CARSMGFire;
            Config::Aimbot::CARSMGADS = CARSMGADS;
            Config::Aimbot::HavocFire = HavocFire;
            Config::Aimbot::HavocADS = HavocADS;
            Config::Aimbot::DevotionFire = DevotionFire;
            Config::Aimbot::DevotionADS = DevotionADS;
            Config::Aimbot::LSTARFire = LSTARFire;
            Config::Aimbot::LSTARADS = LSTARADS;
            Config::Aimbot::TripleTakeFire = TripleTakeFire;
            Config::Aimbot::TripleTakeADS = TripleTakeADS;
            Config::Aimbot::VoltFire = VoltFire;
            Config::Aimbot::VoltADS = VoltADS;
            Config::Aimbot::NemesisFire = NemesisFire;
            Config::Aimbot::NemesisADS = NemesisADS;
            Config::Aimbot::MozambiqueFire = MozambiqueFire;
            Config::Aimbot::MozambiqueADS = MozambiqueADS;
            Config::Aimbot::EVA8Fire = EVA8Fire;
            Config::Aimbot::EVA8ADS = EVA8ADS;
            Config::Aimbot::PeacekeeperFire = PeacekeeperFire;
            Config::Aimbot::PeacekeeperADS = PeacekeeperADS;
            Config::Aimbot::MastiffFire = MastiffFire;
            Config::Aimbot::MastiffADS = MastiffADS;
            Config::Aimbot::WingmanFire = WingmanFire;
            Config::Aimbot::WingmanADS = WingmanADS;
            Config::Aimbot::ProwlerFire = ProwlerFire;
            Config::Aimbot::ProwlerADS = ProwlerADS;
            Config::Aimbot::BocekFire = BocekFire;
            Config::Aimbot::BocekADS = BocekADS;
            Config::Aimbot::KraberFire = KraberFire;
            Config::Aimbot::KraberADS = KraberADS;
            Config::Aimbot::ThrowingKnifeFire = ThrowingKnifeFire;
            Config::Aimbot::ThrowingKnifeADS = ThrowingKnifeADS;

            //Keybinds
            Config::Aimbot::P2020AimBind = static_cast<int>(Modules::Aimbot::P2020AimBind);
            Config::Aimbot::P2020ExtraBind = static_cast<int>(Modules::Aimbot::P2020ExtraBind);
            Config::Aimbot::RE45AimBind = static_cast<int>(Modules::Aimbot::RE45AimBind);
            Config::Aimbot::RE45ExtraBind = static_cast<int>(Modules::Aimbot::RE45ExtraBind);
            Config::Aimbot::AlternatorAimBind = static_cast<int>(Modules::Aimbot::AlternatorAimBind);
            Config::Aimbot::AlternatorExtraBind = static_cast<int>(Modules::Aimbot::AlternatorExtraBind);
            Config::Aimbot::R99AimBind = static_cast<int>(Modules::Aimbot::R99AimBind);
            Config::Aimbot::R99ExtraBind = static_cast<int>(Modules::Aimbot::R99ExtraBind);
            Config::Aimbot::R301AimBind = static_cast<int>(Modules::Aimbot::R301AimBind);
            Config::Aimbot::R301ExtraBind = static_cast<int>(Modules::Aimbot::R301ExtraBind);
            Config::Aimbot::SpitfireAimBind = static_cast<int>(Modules::Aimbot::SpitfireAimBind);
            Config::Aimbot::SpitfireExtraBind = static_cast<int>(Modules::Aimbot::SpitfireExtraBind);
            Config::Aimbot::G7AimBind = static_cast<int>(Modules::Aimbot::G7AimBind);
            Config::Aimbot::G7ExtraBind = static_cast<int>(Modules::Aimbot::G7ExtraBind);
            Config::Aimbot::FlatlineAimBind = static_cast<int>(Modules::Aimbot::FlatlineAimBind);
            Config::Aimbot::FlatlineExtraBind = static_cast<int>(Modules::Aimbot::FlatlineExtraBind);
            Config::Aimbot::HemlockAimBind = static_cast<int>(Modules::Aimbot::HemlockAimBind);
            Config::Aimbot::HemlockExtraBind = static_cast<int>(Modules::Aimbot::HemlockExtraBind);
            Config::Aimbot::RepeaterAimBind = static_cast<int>(Modules::Aimbot::RepeaterAimBind);
            Config::Aimbot::RepeaterExtraBind = static_cast<int>(Modules::Aimbot::RepeaterExtraBind);
            Config::Aimbot::RampageAimBind = static_cast<int>(Modules::Aimbot::RampageAimBind);
            Config::Aimbot::RampageExtraBind = static_cast<int>(Modules::Aimbot::RampageExtraBind);
            Config::Aimbot::CARSMGAimBind = static_cast<int>(Modules::Aimbot::CARSMGAimBind);
            Config::Aimbot::CARSMGExtraBind = static_cast<int>(Modules::Aimbot::CARSMGExtraBind);
            Config::Aimbot::HavocAimBind = static_cast<int>(Modules::Aimbot::HavocAimBind);
            Config::Aimbot::HavocExtraBind = static_cast<int>(Modules::Aimbot::HavocExtraBind);
            Config::Aimbot::DevotionAimBind = static_cast<int>(Modules::Aimbot::DevotionAimBind);
            Config::Aimbot::DevotionExtraBind = static_cast<int>(Modules::Aimbot::DevotionExtraBind);
            Config::Aimbot::LSTARAimBind = static_cast<int>(Modules::Aimbot::LSTARAimBind);
            Config::Aimbot::LSTARExtraBind = static_cast<int>(Modules::Aimbot::LSTARExtraBind);
            Config::Aimbot::TripleTakeAimBind = static_cast<int>(Modules::Aimbot::TripleTakeAimBind);
            Config::Aimbot::TripleTakeExtraBind = static_cast<int>(Modules::Aimbot::TripleTakeExtraBind);
            Config::Aimbot::VoltAimBind = static_cast<int>(Modules::Aimbot::VoltAimBind);
            Config::Aimbot::VoltExtraBind = static_cast<int>(Modules::Aimbot::VoltExtraBind);
            Config::Aimbot::NemesisAimBind = static_cast<int>(Modules::Aimbot::NemesisAimBind);
            Config::Aimbot::NemesisExtraBind = static_cast<int>(Modules::Aimbot::NemesisExtraBind);
            Config::Aimbot::MozambiqueAimBind = static_cast<int>(Modules::Aimbot::MozambiqueAimBind);
            Config::Aimbot::MozambiqueExtraBind = static_cast<int>(Modules::Aimbot::MozambiqueExtraBind);
            Config::Aimbot::WingmanAimBind = static_cast<int>(Modules::Aimbot::WingmanAimBind);
            Config::Aimbot::WingmanExtraBind = static_cast<int>(Modules::Aimbot::WingmanExtraBind);
            Config::Aimbot::BocekAimBind = static_cast<int>(Modules::Aimbot::BocekAimBind);
            Config::Aimbot::BocekExtraBind = static_cast<int>(Modules::Aimbot::BocekExtraBind);
            Config::Aimbot::ProwlerAimBind = static_cast<int>(Modules::Aimbot::ProwlerAimBind);
            Config::Aimbot::ProwlerExtraBind = static_cast<int>(Modules::Aimbot::ProwlerExtraBind);
            Config::Aimbot::KraberAimBind = static_cast<int>(Modules::Aimbot::KraberAimBind);
            Config::Aimbot::KraberExtraBind = static_cast<int>(Modules::Aimbot::KraberExtraBind);
            Config::Aimbot::ThrowingKnifeAimBind = static_cast<int>(Modules::Aimbot::ThrowingKnifeAimBind);
            Config::Aimbot::ThrowingKnifeExtraBind = static_cast<int>(Modules::Aimbot::ThrowingKnifeExtraBind);


            //Advanced - Aimbot Mode 0
            //Light
            Config::Aimbot::P2020ClosestHitbox = P2020ClosestHitbox;
            Config::Aimbot::P2020Hitbox = P2020Hitbox;

            Config::Aimbot::P2020Speed = P2020Speed;
            Config::Aimbot::P2020HipfireSmooth = P2020HipfireSmooth;
            Config::Aimbot::P2020ADSSmooth = P2020ADSSmooth;
            Config::Aimbot::RE45ClosestHitbox = RE45ClosestHitbox;
            Config::Aimbot::RE45Hitbox = RE45Hitbox;

            Config::Aimbot::RE45Speed = RE45Speed;
            Config::Aimbot::RE45HipfireSmooth = RE45HipfireSmooth;
            Config::Aimbot::RE45ADSSmooth = RE45ADSSmooth;
            Config::Aimbot::AlternatorClosestHitbox = AlternatorClosestHitbox;
            Config::Aimbot::AlternatorHitbox = AlternatorHitbox;

            Config::Aimbot::AlternatorSpeed = AlternatorSpeed;
            Config::Aimbot::AlternatorHipfireSmooth = AlternatorHipfireSmooth;
            Config::Aimbot::AlternatorADSSmooth = AlternatorADSSmooth;
            Config::Aimbot::R99ClosestHitbox = R99ClosestHitbox;
            Config::Aimbot::R99Hitbox = R99Hitbox;

            Config::Aimbot::R99Speed = R99Speed;
            Config::Aimbot::R99HipfireSmooth = R99HipfireSmooth;
            Config::Aimbot::R99ADSSmooth = R99ADSSmooth;
            Config::Aimbot::R301ClosestHitbox = R301ClosestHitbox;
            Config::Aimbot::R301Hitbox = R301Hitbox;

            Config::Aimbot::R301Speed = R301Speed;
            Config::Aimbot::R301HipfireSmooth = R301HipfireSmooth;
            Config::Aimbot::R301ADSSmooth = R301ADSSmooth;
            Config::Aimbot::SpitfireClosestHitbox = SpitfireClosestHitbox;
            Config::Aimbot::SpitfireHitbox = SpitfireHitbox;

            Config::Aimbot::SpitfireSpeed = SpitfireSpeed;
            Config::Aimbot::SpitfireHipfireSmooth = SpitfireHipfireSmooth;
            Config::Aimbot::SpitfireADSSmooth = SpitfireADSSmooth;
            Config::Aimbot::G7ClosestHitbox = G7ClosestHitbox;
            Config::Aimbot::G7Hitbox = G7Hitbox;

            Config::Aimbot::G7Speed = G7Speed;
            Config::Aimbot::G7HipfireSmooth = G7HipfireSmooth;
            Config::Aimbot::G7ADSSmooth = G7ADSSmooth;
            //Heavy
            Config::Aimbot::FlatlineClosestHitbox = FlatlineClosestHitbox;
            Config::Aimbot::FlatlineHitbox = FlatlineHitbox;

            Config::Aimbot::FlatlineSpeed = FlatlineSpeed;
            Config::Aimbot::FlatlineHipfireSmooth = FlatlineHipfireSmooth;
            Config::Aimbot::FlatlineADSSmooth = FlatlineADSSmooth;
            Config::Aimbot::HemlockClosestHitbox = HemlockClosestHitbox;
            Config::Aimbot::HemlockHitbox = HemlockHitbox;

            Config::Aimbot::HemlockSpeed = HemlockSpeed;
            Config::Aimbot::HemlockHipfireSmooth = HemlockHipfireSmooth;
            Config::Aimbot::HemlockADSSmooth = HemlockADSSmooth;
            Config::Aimbot::RepeaterClosestHitbox = RepeaterClosestHitbox;
            Config::Aimbot::RepeaterHitbox = RepeaterHitbox;

            Config::Aimbot::RepeaterSpeed = RepeaterSpeed;
            Config::Aimbot::RepeaterHipfireSmooth = RepeaterHipfireSmooth;
            Config::Aimbot::RepeaterADSSmooth = RepeaterADSSmooth;
            Config::Aimbot::RampageClosestHitbox = RampageClosestHitbox;
            Config::Aimbot::RampageHitbox = RampageHitbox;

            Config::Aimbot::RampageSpeed = RampageSpeed;
            Config::Aimbot::RampageHipfireSmooth = RampageHipfireSmooth;
            Config::Aimbot::RampageADSSmooth = RampageADSSmooth;

            Config::Aimbot::CARSMGClosestHitbox = CARSMGClosestHitbox;
            Config::Aimbot::CARSMGHitbox = CARSMGHitbox;
            Config::Aimbot::CARSMGSpeed = CARSMGSpeed;
            Config::Aimbot::CARSMGHipfireSmooth = CARSMGHipfireSmooth;
            Config::Aimbot::CARSMGADSSmooth = CARSMGADSSmooth;
            //Energy
            Config::Aimbot::HavocClosestHitbox = HavocClosestHitbox;
            Config::Aimbot::HavocHitbox = HavocHitbox;
            Config::Aimbot::HavocSpeed = HavocSpeed;
            Config::Aimbot::HavocHipfireSmooth = HavocHipfireSmooth;
            Config::Aimbot::HavocADSSmooth = HavocADSSmooth;

            Config::Aimbot::DevotionClosestHitbox = DevotionClosestHitbox;
            Config::Aimbot::DevotionHitbox = DevotionHitbox;
            Config::Aimbot::DevotionSpeed = DevotionSpeed;
            Config::Aimbot::DevotionHipfireSmooth = DevotionHipfireSmooth;
            Config::Aimbot::DevotionADSSmooth = DevotionADSSmooth;

            Config::Aimbot::LSTARClosestHitbox = LSTARClosestHitbox;
            Config::Aimbot::LSTARHitbox = LSTARHitbox;
            Config::Aimbot::LSTARSpeed = LSTARSpeed;
            Config::Aimbot::LSTARHipfireSmooth = LSTARHipfireSmooth;
            Config::Aimbot::LSTARADSSmooth = LSTARADSSmooth;

            Config::Aimbot::TripleTakeClosestHitbox = TripleTakeClosestHitbox;
            Config::Aimbot::TripleTakeHitbox = TripleTakeHitbox;
            Config::Aimbot::TripleTakeSpeed = TripleTakeSpeed;
            Config::Aimbot::TripleTakeHipfireSmooth = TripleTakeHipfireSmooth;
            Config::Aimbot::TripleTakeADSSmooth = TripleTakeADSSmooth;

            Config::Aimbot::VoltClosestHitbox = VoltClosestHitbox;
            Config::Aimbot::VoltHitbox = VoltHitbox;
            Config::Aimbot::VoltSpeed = VoltSpeed;
            Config::Aimbot::VoltHipfireSmooth = VoltHipfireSmooth;
            Config::Aimbot::VoltADSSmooth = VoltADSSmooth;

            Config::Aimbot::NemesisClosestHitbox = NemesisClosestHitbox;
            Config::Aimbot::NemesisHitbox = NemesisHitbox;
            Config::Aimbot::NemesisSpeed = NemesisSpeed;
            Config::Aimbot::NemesisHipfireSmooth = NemesisHipfireSmooth;
            Config::Aimbot::NemesisADSSmooth = NemesisADSSmooth;

            //Shotguns
            Config::Aimbot::MozambiqueClosestHitbox = MozambiqueClosestHitbox;
            Config::Aimbot::MozambiqueHitbox = MozambiqueHitbox;
            Config::Aimbot::MozambiqueSpeed = MozambiqueSpeed;
            Config::Aimbot::MozambiqueHipfireSmooth = MozambiqueHipfireSmooth;
            Config::Aimbot::MozambiqueADSSmooth = MozambiqueADSSmooth;

            Config::Aimbot::EVA8ClosestHitbox = EVA8ClosestHitbox;
            Config::Aimbot::EVA8Hitbox = EVA8Hitbox;
            Config::Aimbot::EVA8Speed = EVA8Speed;
            Config::Aimbot::EVA8HipfireSmooth = EVA8HipfireSmooth;
            Config::Aimbot::EVA8ADSSmooth = EVA8ADSSmooth;

            Config::Aimbot::PeacekeeperClosestHitbox = PeacekeeperClosestHitbox;
            Config::Aimbot::PeacekeeperHitbox = PeacekeeperHitbox;
            Config::Aimbot::PeacekeeperSpeed = PeacekeeperSpeed;
            Config::Aimbot::PeacekeeperHipfireSmooth = PeacekeeperHipfireSmooth;
            Config::Aimbot::PeacekeeperADSSmooth = PeacekeeperADSSmooth;

            Config::Aimbot::MastiffClosestHitbox = MastiffClosestHitbox;
            Config::Aimbot::MastiffHitbox = MastiffHitbox;
            Config::Aimbot::MastiffSpeed = MastiffSpeed;
            Config::Aimbot::MastiffHipfireSmooth = MastiffHipfireSmooth;
            Config::Aimbot::MastiffADSSmooth = MastiffADSSmooth;

            //Snipers
            Config::Aimbot::LongbowClosestHitbox = LongbowClosestHitbox;
            Config::Aimbot::LongbowHitbox = LongbowHitbox;
            Config::Aimbot::LongbowSpeed = LongbowSpeed;
            Config::Aimbot::LongbowHipfireSmooth = LongbowHipfireSmooth;
            Config::Aimbot::LongbowADSSmooth = LongbowADSSmooth;

            Config::Aimbot::ChargeRifleClosestHitbox = ChargeRifleClosestHitbox;
            Config::Aimbot::ChargeRifleHitbox = ChargeRifleHitbox;
            Config::Aimbot::ChargeRifleSpeed = ChargeRifleSpeed;
            Config::Aimbot::ChargeRifleHipfireSmooth = ChargeRifleHipfireSmooth;
            Config::Aimbot::ChargeRifleADSSmooth = ChargeRifleADSSmooth;

            Config::Aimbot::SentinelClosestHitbox = SentinelClosestHitbox;
            Config::Aimbot::SentinelHitbox = SentinelHitbox;
            Config::Aimbot::SentinelSpeed = SentinelSpeed;
            Config::Aimbot::SentinelHipfireSmooth = SentinelHipfireSmooth;
            Config::Aimbot::SentinelADSSmooth = SentinelADSSmooth;

            //Legendary
            Config::Aimbot::WingmanClosestHitbox = WingmanClosestHitbox;
            Config::Aimbot::WingmanHitbox = WingmanHitbox;
            Config::Aimbot::WingmanSpeed = WingmanSpeed;
            Config::Aimbot::WingmanHipfireSmooth = WingmanHipfireSmooth;
            Config::Aimbot::WingmanADSSmooth = WingmanADSSmooth;

            Config::Aimbot::ProwlerClosestHitbox = ProwlerClosestHitbox;
            Config::Aimbot::ProwlerHitbox = ProwlerHitbox;
            Config::Aimbot::ProwlerSpeed = ProwlerSpeed;
            Config::Aimbot::ProwlerHipfireSmooth = ProwlerHipfireSmooth;
            Config::Aimbot::ProwlerADSSmooth = ProwlerADSSmooth;

            Config::Aimbot::BocekClosestHitbox = BocekClosestHitbox;
            Config::Aimbot::BocekHitbox = BocekHitbox;
            Config::Aimbot::BocekSpeed = BocekSpeed;
            Config::Aimbot::BocekHipfireSmooth = BocekHipfireSmooth;
            Config::Aimbot::BocekADSSmooth = BocekADSSmooth;

            Config::Aimbot::KraberClosestHitbox = KraberClosestHitbox;
            Config::Aimbot::KraberHitbox = KraberHitbox;
            Config::Aimbot::KraberSpeed = KraberSpeed;
            Config::Aimbot::KraberHipfireSmooth = KraberHipfireSmooth;
            Config::Aimbot::KraberADSSmooth = KraberADSSmooth;

            Config::Aimbot::ThrowingKnifeClosestHitbox = ThrowingKnifeClosestHitbox;
            Config::Aimbot::ThrowingKnifeHitbox = ThrowingKnifeHitbox;
            Config::Aimbot::ThrowingKnifeSpeed = ThrowingKnifeSpeed;
            Config::Aimbot::ThrowingKnifeHipfireSmooth = ThrowingKnifeHipfireSmooth;
            Config::Aimbot::ThrowingKnifeADSSmooth = ThrowingKnifeADSSmooth;


            //Aimbot Mode 1 - Grinder
            Config::Aimbot::P2020HipfireSmooth1 = P2020HipfireSmooth1;
            Config::Aimbot::P2020ADSSmooth1 = P2020ADSSmooth1;
            Config::Aimbot::P2020ExtraSmooth1 = P2020ExtraSmooth1;
            Config::Aimbot::P2020Deadzone = P2020Deadzone;
            Config::Aimbot::P2020FOV1 = P2020FOV1;
            Config::Aimbot::P2020MinDistance1 = P2020MinDistance1;
            Config::Aimbot::P2020MaxDistance1 = P2020MaxDistance1;
            Config::Aimbot::RE45HipfireSmooth1 = RE45HipfireSmooth1;
            Config::Aimbot::RE45ADSSmooth1 = RE45ADSSmooth1;
            Config::Aimbot::RE45ExtraSmooth1 = RE45ExtraSmooth1;
            Config::Aimbot::RE45Deadzone = RE45Deadzone;
            Config::Aimbot::RE45FOV1 = RE45FOV1;
            Config::Aimbot::RE45MinDistance1 = RE45MinDistance1;
            Config::Aimbot::RE45MaxDistance1 = RE45MaxDistance1;
            Config::Aimbot::AlternatorHipfireSmooth1 = AlternatorHipfireSmooth1;
            Config::Aimbot::AlternatorADSSmooth1 = AlternatorADSSmooth1;
            Config::Aimbot::AlternatorExtraSmooth1 = AlternatorExtraSmooth1;
            Config::Aimbot::AlternatorDeadzone = AlternatorDeadzone;
            Config::Aimbot::AlternatorFOV1 = AlternatorFOV1;
            Config::Aimbot::AlternatorMinDistance1 = AlternatorMinDistance1;
            Config::Aimbot::AlternatorMaxDistance1 = AlternatorMaxDistance1;
            Config::Aimbot::R99HipfireSmooth1 = R99HipfireSmooth1;
            Config::Aimbot::R99ADSSmooth1 = R99ADSSmooth1;
            Config::Aimbot::R99ExtraSmooth1 = R99ExtraSmooth1;
            Config::Aimbot::R99Deadzone = R99Deadzone;
            Config::Aimbot::R99FOV1 = R99FOV1;
            Config::Aimbot::R99MinDistance1 = R99MinDistance1;
            Config::Aimbot::R99MaxDistance1 = R99MaxDistance1;
            Config::Aimbot::R301HipfireSmooth1 = R301HipfireSmooth1;
            Config::Aimbot::R301ADSSmooth1 = R301ADSSmooth1;
            Config::Aimbot::R301ExtraSmooth1 = R301ExtraSmooth1;
            Config::Aimbot::R301Deadzone = R301Deadzone;
            Config::Aimbot::R301FOV1 = R301FOV1;
            Config::Aimbot::R301MinDistance1 = R301MinDistance1;
            Config::Aimbot::R301MaxDistance1 = R301MaxDistance1;
            Config::Aimbot::SpitfireHipfireSmooth1 = SpitfireHipfireSmooth1;
            Config::Aimbot::SpitfireADSSmooth1 = SpitfireADSSmooth1;
            Config::Aimbot::SpitfireExtraSmooth1 = SpitfireExtraSmooth1;
            Config::Aimbot::SpitfireDeadzone = SpitfireDeadzone;
            Config::Aimbot::SpitfireFOV1 = SpitfireFOV1;
            Config::Aimbot::SpitfireMinDistance1 = SpitfireMinDistance1;
            Config::Aimbot::SpitfireMaxDistance1 = SpitfireMaxDistance1;
            Config::Aimbot::G7HipfireSmooth1 = G7HipfireSmooth1;
            Config::Aimbot::G7ADSSmooth1 = G7ADSSmooth1;
            Config::Aimbot::G7ExtraSmooth1 = G7ExtraSmooth1;
            Config::Aimbot::G7Deadzone = G7Deadzone;
            Config::Aimbot::G7FOV1 = G7FOV1;
            Config::Aimbot::G7MinDistance1 = G7MinDistance1;
            Config::Aimbot::G7MaxDistance1 = G7MaxDistance1;
            Config::Aimbot::FlatlineHipfireSmooth1 = FlatlineHipfireSmooth1;
            Config::Aimbot::FlatlineADSSmooth1 = FlatlineADSSmooth1;
            Config::Aimbot::FlatlineExtraSmooth1 = FlatlineExtraSmooth1;
            Config::Aimbot::FlatlineDeadzone = FlatlineDeadzone;
            Config::Aimbot::FlatlineFOV1 = FlatlineFOV1;
            Config::Aimbot::FlatlineMinDistance1 = FlatlineMinDistance1;
            Config::Aimbot::FlatlineMaxDistance1 = FlatlineMaxDistance1;
            Config::Aimbot::HemlockHipfireSmooth1 = HemlockHipfireSmooth1;
            Config::Aimbot::HemlockADSSmooth1 = HemlockADSSmooth1;
            Config::Aimbot::HemlockExtraSmooth1 = HemlockExtraSmooth1;
            Config::Aimbot::HemlockDeadzone = HemlockDeadzone;
            Config::Aimbot::HemlockFOV1 = HemlockFOV1;
            Config::Aimbot::HemlockMinDistance1 = HemlockMinDistance1;
            Config::Aimbot::HemlockMaxDistance1 = HemlockMaxDistance1;
            Config::Aimbot::RepeaterHipfireSmooth1 = RepeaterHipfireSmooth1;
            Config::Aimbot::RepeaterADSSmooth1 = RepeaterADSSmooth1;
            Config::Aimbot::RepeaterExtraSmooth1 = RepeaterExtraSmooth1;
            Config::Aimbot::RepeaterDeadzone = RepeaterDeadzone;
            Config::Aimbot::RepeaterFOV1 = RepeaterFOV1;
            Config::Aimbot::RepeaterMinDistance1 = RepeaterMinDistance1;
            Config::Aimbot::RepeaterMaxDistance1 = RepeaterMaxDistance1;
            Config::Aimbot::RampageHipfireSmooth1 = RampageHipfireSmooth1;
            Config::Aimbot::RampageADSSmooth1 = RampageADSSmooth1;
            Config::Aimbot::RampageExtraSmooth1 = RampageExtraSmooth1;
            Config::Aimbot::RampageDeadzone = RampageDeadzone;
            Config::Aimbot::RampageFOV1 = RampageFOV1;
            Config::Aimbot::RampageMinDistance1 = RampageMinDistance1;
            Config::Aimbot::RampageMaxDistance1 = RampageMaxDistance1;
            Config::Aimbot::CARSMGHipfireSmooth1 = CARSMGHipfireSmooth1;
            Config::Aimbot::CARSMGADSSmooth1 = CARSMGADSSmooth1;
            Config::Aimbot::CARSMGExtraSmooth1 = CARSMGExtraSmooth1;
            Config::Aimbot::CARSMGDeadzone = CARSMGDeadzone;
            Config::Aimbot::CARSMGFOV1 = CARSMGFOV1;
            Config::Aimbot::CARSMGMinDistance1 = CARSMGMinDistance1;
            Config::Aimbot::CARSMGMaxDistance1 = CARSMGMaxDistance1;
            Config::Aimbot::HavocHipfireSmooth1 = HavocHipfireSmooth1;
            Config::Aimbot::HavocADSSmooth1 = HavocADSSmooth1;
            Config::Aimbot::HavocExtraSmooth1 = HavocExtraSmooth1;
            Config::Aimbot::HavocDeadzone = HavocDeadzone;
            Config::Aimbot::HavocFOV1 = HavocFOV1;
            Config::Aimbot::HavocMinDistance1 = HavocMinDistance1;
            Config::Aimbot::HavocMaxDistance1 = HavocMaxDistance1;
            Config::Aimbot::DevotionHipfireSmooth1 = DevotionHipfireSmooth1;
            Config::Aimbot::DevotionADSSmooth1 = DevotionADSSmooth1;
            Config::Aimbot::DevotionExtraSmooth1 = DevotionExtraSmooth1;
            Config::Aimbot::DevotionDeadzone = DevotionDeadzone;
            Config::Aimbot::DevotionFOV1 = DevotionFOV1;
            Config::Aimbot::DevotionMinDistance1 = DevotionMinDistance1;
            Config::Aimbot::DevotionMaxDistance1 = DevotionMaxDistance1;
            Config::Aimbot::LSTARHipfireSmooth1 = LSTARHipfireSmooth1;
            Config::Aimbot::LSTARADSSmooth1 = LSTARADSSmooth1;
            Config::Aimbot::LSTARExtraSmooth1 = LSTARExtraSmooth1;
            Config::Aimbot::LSTARDeadzone = LSTARDeadzone;
            Config::Aimbot::LSTARFOV1 = LSTARFOV1;
            Config::Aimbot::LSTARMinDistance1 = LSTARMinDistance1;
            Config::Aimbot::LSTARMaxDistance1 = LSTARMaxDistance1;
            Config::Aimbot::TripleTakeHipfireSmooth1 = TripleTakeHipfireSmooth1;
            Config::Aimbot::TripleTakeADSSmooth1 = TripleTakeADSSmooth1;
            Config::Aimbot::TripleTakeExtraSmooth1 = TripleTakeExtraSmooth1;
            Config::Aimbot::TripleTakeDeadzone = TripleTakeDeadzone;
            Config::Aimbot::TripleTakeFOV1 = TripleTakeFOV1;
            Config::Aimbot::TripleTakeMinDistance1 = TripleTakeMinDistance1;
            Config::Aimbot::TripleTakeMaxDistance1 = TripleTakeMaxDistance1;
            Config::Aimbot::VoltHipfireSmooth1 = VoltHipfireSmooth1;
            Config::Aimbot::VoltADSSmooth1 = VoltADSSmooth1;
            Config::Aimbot::VoltExtraSmooth1 = VoltExtraSmooth1;
            Config::Aimbot::VoltDeadzone = VoltDeadzone;
            Config::Aimbot::VoltFOV1 = VoltFOV1;
            Config::Aimbot::VoltMinDistance1 = VoltMinDistance1;
            Config::Aimbot::VoltMaxDistance1 = VoltMaxDistance1;
            Config::Aimbot::NemesisHipfireSmooth1 = NemesisHipfireSmooth1;
            Config::Aimbot::NemesisADSSmooth1 = NemesisADSSmooth1;
            Config::Aimbot::NemesisExtraSmooth1 = NemesisExtraSmooth1;
            Config::Aimbot::NemesisDeadzone = NemesisDeadzone;
            Config::Aimbot::NemesisFOV1 = NemesisFOV1;
            Config::Aimbot::NemesisMinDistance1 = NemesisMinDistance1;
            Config::Aimbot::NemesisMaxDistance1 = NemesisMaxDistance1;
            Config::Aimbot::MozambiqueHipfireSmooth1 = MozambiqueHipfireSmooth1;
            Config::Aimbot::MozambiqueADSSmooth1 = MozambiqueADSSmooth1;
            Config::Aimbot::MozambiqueExtraSmooth1 = MozambiqueExtraSmooth1;
            Config::Aimbot::MozambiqueDeadzone = MozambiqueDeadzone;
            Config::Aimbot::MozambiqueFOV1 = MozambiqueFOV1;
            Config::Aimbot::MozambiqueMinDistance1 = MozambiqueMinDistance1;
            Config::Aimbot::MozambiqueMaxDistance1 = MozambiqueMaxDistance1;
            Config::Aimbot::EVA8HipfireSmooth1 = EVA8HipfireSmooth1;
            Config::Aimbot::EVA8ADSSmooth1 = EVA8ADSSmooth1;
            Config::Aimbot::EVA8ExtraSmooth1 = EVA8ExtraSmooth1;
            Config::Aimbot::EVA8Deadzone = EVA8Deadzone;
            Config::Aimbot::EVA8FOV1 = EVA8FOV1;
            Config::Aimbot::EVA8MinDistance1 = EVA8MinDistance1;
            Config::Aimbot::EVA8MaxDistance1 = EVA8MaxDistance1;
            Config::Aimbot::PeacekeeperHipfireSmooth1 = PeacekeeperHipfireSmooth1;
            Config::Aimbot::PeacekeeperADSSmooth1 = PeacekeeperADSSmooth1;
            Config::Aimbot::PeacekeeperExtraSmooth1 = PeacekeeperExtraSmooth1;
            Config::Aimbot::PeacekeeperDeadzone = PeacekeeperDeadzone;
            Config::Aimbot::PeacekeeperFOV1 = PeacekeeperFOV1;
            Config::Aimbot::PeacekeeperMinDistance1 = PeacekeeperMinDistance1;
            Config::Aimbot::PeacekeeperMaxDistance1 = PeacekeeperMaxDistance1;
            Config::Aimbot::MastiffHipfireSmooth1 = MastiffHipfireSmooth1;
            Config::Aimbot::MastiffADSSmooth1 = MastiffADSSmooth1;
            Config::Aimbot::MastiffExtraSmooth1 = MastiffExtraSmooth1;
            Config::Aimbot::MastiffDeadzone = MastiffDeadzone;
            Config::Aimbot::MastiffFOV1 = MastiffFOV1;
            Config::Aimbot::MastiffMinDistance1 = MastiffMinDistance1;
            Config::Aimbot::MastiffMaxDistance1 = MastiffMaxDistance1;
            Config::Aimbot::WingmanHipfireSmooth1 = WingmanHipfireSmooth1;
            Config::Aimbot::WingmanADSSmooth1 = WingmanADSSmooth1;
            Config::Aimbot::WingmanExtraSmooth1 = WingmanExtraSmooth1;
            Config::Aimbot::WingmanDeadzone = WingmanDeadzone;
            Config::Aimbot::WingmanFOV1 = WingmanFOV1;
            Config::Aimbot::WingmanMinDistance1 = WingmanMinDistance1;
            Config::Aimbot::WingmanMaxDistance1 = WingmanMaxDistance1;
            Config::Aimbot::ProwlerHipfireSmooth1 = ProwlerHipfireSmooth1;
            Config::Aimbot::ProwlerADSSmooth1 = ProwlerADSSmooth1;
            Config::Aimbot::ProwlerExtraSmooth1 = ProwlerExtraSmooth1;
            Config::Aimbot::ProwlerDeadzone = ProwlerDeadzone;
            Config::Aimbot::ProwlerFOV1 = ProwlerFOV1;
            Config::Aimbot::ProwlerMinDistance1 = ProwlerMinDistance1;
            Config::Aimbot::ProwlerMaxDistance1 = ProwlerMaxDistance1;
            Config::Aimbot::BocekHipfireSmooth1 = BocekHipfireSmooth1;
            Config::Aimbot::BocekADSSmooth1 = BocekADSSmooth1;
            Config::Aimbot::BocekExtraSmooth1 = BocekExtraSmooth1;
            Config::Aimbot::BocekDeadzone = BocekDeadzone;
            Config::Aimbot::BocekFOV1 = BocekFOV1;
            Config::Aimbot::BocekMinDistance1 = BocekMinDistance1;
            Config::Aimbot::BocekMaxDistance1 = BocekMaxDistance1;
            Config::Aimbot::KraberHipfireSmooth1 = KraberHipfireSmooth1;
            Config::Aimbot::KraberADSSmooth1 = KraberADSSmooth1;
            Config::Aimbot::KraberExtraSmooth1 = KraberExtraSmooth1;
            Config::Aimbot::KraberDeadzone = KraberDeadzone;
            Config::Aimbot::KraberFOV1 = KraberFOV1;
            Config::Aimbot::KraberMinDistance1 = KraberMinDistance1;
            Config::Aimbot::KraberMaxDistance1 = KraberMaxDistance1;
            Config::Aimbot::ThrowingKnifeHipfireSmooth1 = ThrowingKnifeHipfireSmooth1;
            Config::Aimbot::ThrowingKnifeADSSmooth1 = ThrowingKnifeADSSmooth1;
            Config::Aimbot::ThrowingKnifeExtraSmooth1 = ThrowingKnifeExtraSmooth1;
            Config::Aimbot::ThrowingKnifeDeadzone = ThrowingKnifeDeadzone;
            Config::Aimbot::ThrowingKnifeFOV1 = ThrowingKnifeFOV1;
            Config::Aimbot::ThrowingKnifeMinDistance1 = ThrowingKnifeMinDistance1;
            Config::Aimbot::ThrowingKnifeMaxDistance1 = ThrowingKnifeMaxDistance1;

            return true;
        } catch (...) {
            return false;
        }
    }

    void UpdateAimList() {
        AimList.clear();
        //Light
        if (P2020)
            AimList.insert(AimbotId::WEAPON_P2020);
        if (RE45)
            AimList.insert(AimbotId::WEAPON_RE45);
        if (Alternator)
            AimList.insert(AimbotId::WEAPON_ALTERNATOR);
        if (R99)
            AimList.insert(AimbotId::WEAPON_R99);
        if (R301)
            AimList.insert(AimbotId::WEAPON_R301);
        if (Spitfire)
            AimList.insert(AimbotId::WEAPON_SPITFIRE);
        if (G7)
            AimList.insert(AimbotId::WEAPON_G7);
        //Heavy
        if (Flatline)
            AimList.insert(AimbotId::WEAPON_FLATLINE);
        if (Hemlock)
            AimList.insert(AimbotId::WEAPON_HEMLOCK);
        if (Repeater)
            AimList.insert(AimbotId::WEAPON_REPEATER);
        if (Rampage)
            AimList.insert(AimbotId::WEAPON_RAMPAGE);
        if (CARSMG)
            AimList.insert(AimbotId::WEAPON_CAR);
        //Energy
        if (Havoc)
            AimList.insert(AimbotId::WEAPON_HAVOC);
        if (Devotion)
            AimList.insert(AimbotId::WEAPON_DEVOTION);
        if (LSTAR)
            AimList.insert(AimbotId::WEAPON_LSTAR);
        if (TripleTake)
            AimList.insert(AimbotId::WEAPON_TRIPLETAKE);
        if (Volt)
            AimList.insert(AimbotId::WEAPON_VOLT);
        if (Nemesis)
            AimList.insert(AimbotId::WEAPON_NEMESIS);
        //Shotguns
        if (Mozambique)
            AimList.insert(AimbotId::WEAPON_MOZAMBIQUE);
        if (EVA8)
            AimList.insert(AimbotId::WEAPON_EVA8);
        if (Peacekeeper)
            AimList.insert(AimbotId::WEAPON_PEACEKEEPER);
        if (Mastiff)
            AimList.insert(AimbotId::WEAPON_MASTIFF);
        //Snipers
        if (Longbow)
            AimList.insert(AimbotId::WEAPON_LONGBOW);
        if (ChargeRifle)
            AimList.insert(AimbotId::WEAPON_CHARGE_RIFLE);
        if (Sentinel)
            AimList.insert(AimbotId::WEAPON_SENTINEL);
    //Legendary
    if (Wingman)
            AimList.insert(AimbotId::WEAPON_WINGMAN);
        if (Prowler)
            AimList.insert(AimbotId::WEAPON_PROWLER);
        if (Bocek)
            AimList.insert(AimbotId::WEAPON_BOCEK);
        if (Kraber)
            AimList.insert(AimbotId::WEAPON_KRABER);
        if (Knife)
            AimList.insert(AimbotId::WEAPON_KNIFE);
    }

    void Update() {
        if(!Map->IsPlayable) return;
        if(Myself->IsDead) return;
        if(Modules::Home::IsMenuOpened) return; //Dont aimbot whilst menu is open
        UpdateSettings(); //Updates Aimbot Settings Based On What Aimbot Mode is enabled and if advanced aim is on

        if (AimbotMode == 0 || AimbotMode == 2) { //Cubic Beizer (xap-client)
            if (!AimbotEnabled) { ReleaseTarget(); return; }

            if (Myself->IsZooming)
                FinalDistance = ZoomDistance;
            else FinalDistance = HipfireDistance;

            if (AimList.find(Myself->WeaponIndex) == AimList.end()) return;

            if (Modules::Aimbot::BindMethod == 0) { //OnFire and OnADS
                if (OnFire && OnADS) {
                    if (!Myself->IsInAttack) {
                        if (!Myself->IsZooming) {
                            ReleaseTarget();
                            TargetSelected = false;
                            CurrentTarget = nullptr;
                            return;
                        }
                    }
                    if (!Myself->IsZooming) {
                        if (!Myself->IsInAttack) {
                            ReleaseTarget();
                            TargetSelected = false;
                            CurrentTarget = nullptr;
                            return;
                        }
                    }

                    Player* Target = CurrentTarget;
                    if (!IsValidTarget(Target)) {
                        if (TargetSelected)
                        return;

                        Target = FindBestTarget();
                        if (!IsValidTarget(Target)) {
                        ReleaseTarget();
                        return;
                        }

                        CurrentTarget = Target;
                        CurrentTarget->IsLockedOn = true;
                        TargetSelected = true;
                    }

                    if (TargetSelected && CurrentTarget) {
                        std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                        if (Now >= LastAimTime + std::chrono::milliseconds(Delay)) {
                        StartAiming();
                        LastAimTime = Now + std::chrono::milliseconds((int)Utils::RandomRange(1, 10));
                        }
                        return;
                    }
                }

                if (OnFire) {
                    if (!Myself->IsInAttack) { ReleaseTarget(); TargetSelected = false; CurrentTarget = nullptr; return; }

                    Player* Target = CurrentTarget;
                    if (!IsValidTarget(Target)) {
                        if (TargetSelected)
                        return;

                        Target = FindBestTarget();
                        if (!IsValidTarget(Target)) {
                        ReleaseTarget();
                        return;
                        }

                        CurrentTarget = Target;
                        CurrentTarget->IsLockedOn = true;
                        TargetSelected = true;
                    }

                    if (TargetSelected && CurrentTarget) {
                        std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                        if (Now >= LastAimTime + std::chrono::milliseconds(Delay)) {
                        StartAiming();
                        LastAimTime = Now + std::chrono::milliseconds((int)Utils::RandomRange(1, 10));
                        }
                        return;
                    }
                }

                if (OnADS) {
                    if (!Myself->IsZooming) { ReleaseTarget(); TargetSelected = false; CurrentTarget = nullptr; return; }

                    Player* Target = CurrentTarget;
                    if (!IsValidTarget(Target)) {
                        if (TargetSelected)
                        return;

                        Target = FindBestTarget();
                        if (!IsValidTarget(Target)) {
                        ReleaseTarget();
                        return;
                        }

                        CurrentTarget = Target;
                        CurrentTarget->IsLockedOn = true;
                        TargetSelected = true;
                    }

                    if (TargetSelected && CurrentTarget) {
                        std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                        if (Now >= LastAimTime + std::chrono::milliseconds(Delay)) {
                        StartAiming();
                        LastAimTime = Now + std::chrono::milliseconds((int)Utils::RandomRange(1, 10));
                        }
                        return;
                    }
                }
            }

            else if (Modules::Aimbot::BindMethod == 1) { //Keybinds
                if (!isKeybindDown()) { ReleaseTarget(); TargetSelected = false; CurrentTarget = nullptr; return; }

                Player* Target = CurrentTarget;
                if (!IsValidTarget(Target)) {
                    if (TargetSelected)
                    return;

                    Target = FindBestTarget();
                    if (!IsValidTarget(Target)) {
                    ReleaseTarget();
                    return;
                    }

                    CurrentTarget = Target;
                    CurrentTarget->IsLockedOn = true;
                    TargetSelected = true;
                }

                if (TargetSelected && CurrentTarget) {
                    std::chrono::milliseconds Now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                    if (Now >= LastAimTime + std::chrono::milliseconds(Delay)) {
                    StartAiming();
                    LastAimTime = Now + std::chrono::milliseconds((int)Utils::RandomRange(1, 10));
                    }
                    return;
                }
            }
        }

        if (AimbotMode == 1) {
            if (!active()) { releaseTarget2(); return; }
            if (AimList.find(Myself->WeaponIndex) == AimList.end()) return;
            if (CurrentTarget == nullptr) assignTarget();
            if (CurrentTarget == nullptr) return;
            if (!CurrentTarget->IsVisible) return;
            if (CurrentTarget->Distance2DToLocalPlayer < Conversion::ToGameUnits(MinDistance2)) return;
            if (CurrentTarget->Distance2DToLocalPlayer > Conversion::ToGameUnits(MaxDistance2)) return;
            moveMouse();
        }
    }

    bool isKeybindDown() {
        bool ActivatedByAimBind = InputManager::isKeyDownOrPress(Modules::Aimbot::AimBind);
        bool ActivatedByExtraBind = InputManager::isKeyDownOrPress(Modules::Aimbot::ExtraBind);
        bool active = (ActivatedByAimBind || ActivatedByExtraBind);
        return active;
    }

    void StartAiming() {
        // Get Target Angle
        QAngle DesiredAngles = QAngle(0, 0);
        if (!GetAngle(CurrentTarget, DesiredAngles))
            return;

        //SmoothAngle(CurrentTarget, DesiredAngles);


        // Aim angles ADVANCED
        if (AdvancedAim) {
            SmoothAngle(CurrentTarget, DesiredAngles);
        Vector2D aimbotDelta = Vector2D(CalculatePitchIncrement(DesiredAngles), CalculateYawIncrement(DesiredAngles)).Multiply(AdvancedSpeed);


        int totalYawIncrementInt = RoundHalfEven(AL1AF0(aimbotDelta.x));
        int totalPitchIncrementInt = RoundHalfEven(AL1AF0(aimbotDelta.y * -1));

        // Move Mouse
        if (totalPitchIncrementInt == 0 && totalYawIncrementInt == 0) return;
        X11Display->MoveMouse(totalYawIncrementInt, totalPitchIncrementInt);
        }

        if (!AdvancedAim) {   

        if(AimbotMode == 0) {
            //SmoothAngle(CurrentTarget, DesiredAngles);
            //std::this_thread::sleep_for(std::chrono::milliseconds(20));
            //SmoothAngle(CurrentTarget, DesiredAngles);

            if(RCSEnabled) {
                QAngle punch_angle =  Memory::Read<QAngle>(Myself->BasePointer + OFF_PUNCH_ANGLES);
                punch_angle.x *=  (PitchP / 100.f);
                punch_angle.y *=  (YawP / 100.f);

                DesiredAngles -=  punch_angle;

            }

            if (DesiredAngles == QAngle(0, 0)) return;
            DesiredAngles.NormalizeAngles();
            SmoothAngle(CurrentTarget, DesiredAngles); // wasnt sure if recoil was better with this before or after recoil calc or if it even changed lul

            Vector2D aimbotD = Vector2D(CalculatePitchIncrement(DesiredAngles), CalculateYawIncrement(DesiredAngles)).Multiply(Speed);

            int totalYawIncrementInt = RoundHalfEven(AL1AF0(aimbotD.x));
            int totalPitchIncrementInt = RoundHalfEven(AL1AF0(aimbotD.y * -1));

            if (totalPitchIncrementInt == 0 && totalYawIncrementInt == 0) return;
                X11Display->MoveMouse(totalYawIncrementInt, totalPitchIncrementInt);
        }
        else if(AimbotMode == 2) {
            //SmoothAngle(CurrentTarget, DesiredAngles);

            if(RCSEnabled) {
                QAngle punch_angle = Memory::Read<QAngle>(Myself->BasePointer + OFF_PUNCH_ANGLES);

                punch_angle.x *=  (PitchP / 100.f);
                punch_angle.y *=  (YawP / 100.f);

                DesiredAngles -= punch_angle;
            }


            if (DesiredAngles == QAngle(0, 0)) return;
            DesiredAngles.NormalizeAngles();

            SmoothAngle(CurrentTarget, DesiredAngles);

            Myself->set_angles(DesiredAngles);
            //Memory::Write<QAngle>(Myself->BasePointer + OFF_VIEW_ANGLES, DesiredAngles);
        }
    }

    }

    void moveMouse() {
    float TOTAL_SMOOTH;
    if (Myself->IsZooming) {
        float ExtraSmooth = AdvancedExtraSmooth1 / CurrentTarget->DistanceToLocalPlayer;
        TOTAL_SMOOTH = (AdvancedADSSmooth1 + ExtraSmooth);
    }
    else if (!Myself->IsZooming) {
        float ExtraSmooth = AdvancedExtraSmooth1 / CurrentTarget->DistanceToLocalPlayer;
        TOTAL_SMOOTH = (AdvancedHipfireSmooth1 + ExtraSmooth);
    }
    //Aimbot calcs
    const FloatVector2D aimbotDelta = CurrentTarget->aimbotDesiredAnglesIncrement
        .multiply(100)
        .divide(TOTAL_SMOOTH);
    const double aimYawIncrement = aimbotDelta.y * -1;
    const double aimPitchIncrement = aimbotDelta.x;
    //Combine
    const double totalPitchIncrement = aimPitchIncrement;
    const double totalYawIncrement = aimYawIncrement;
    //Turn into integers
    int totalPitchIncrementInt = roundHalfEven2(atLeast_1_AwayFromZero(totalPitchIncrement));
    int totalYawIncrementInt = roundHalfEven2(atLeast_1_AwayFromZero(totalYawIncrement));
    //Deadzone - are we close enough yet?
    if (fabs(CurrentTarget->aimbotDesiredAnglesIncrement.x) < AdvancedDeadzone) totalPitchIncrementInt = 0;
    if (fabs(CurrentTarget->aimbotDesiredAnglesIncrement.y) < AdvancedDeadzone) totalYawIncrementInt = 0;
    if (totalPitchIncrementInt == 0 && totalYawIncrementInt == 0) return;
    //move mouse
    X11Display->MoveMouse(totalPitchIncrementInt, totalYawIncrementInt);
    }

    void SmoothAngle(Player* Target, QAngle& Angle) {
        QAngle ViewAngles = QAngle(Myself->ViewAngles.x, Myself->ViewAngles.y).NormalizeAngles();
        QAngle Delta = Angle - ViewAngles;
        Delta.NormalizeAngles();

        if (AdvancedAim) {
            if (Myself->IsZooming) {
            float ExtraSmooth = SmoothDistance / Target->DistanceToLocalPlayer;
            float SmoothValue = powf(this->AdvancedADSSmooth + ExtraSmooth, 0.4f);
            SmoothValue = std::min(0.99f, SmoothValue);
        }
            if (!Myself->IsZooming) {
            float ExtraSmooth = SmoothDistance / Target->DistanceToLocalPlayer;
            float SmoothValue = powf(this->AdvancedHipfireSmooth + ExtraSmooth, 0.4f);
            SmoothValue = std::min(0.99f, SmoothValue);
        }
        }

        if (!AdvancedAim) {
        if (Myself->IsZooming) {
            Smooth = ADSSmooth;
            float ExtraSmooth = SmoothDistance / Target->DistanceToLocalPlayer;
            float SmoothValue = powf(this->Smooth + ExtraSmooth, 0.4f);
            SmoothValue = std::min(0.99f, SmoothValue);
        }
        if (!Myself->IsZooming) {
            Smooth = HipfireSmooth;
            float ExtraSmooth = SmoothDistance / Target->DistanceToLocalPlayer;
            float SmoothValue = powf(this->Smooth + ExtraSmooth, 0.4f);
            SmoothValue = std::min(0.99f, SmoothValue);
        }
        }

        QAngle ToChange = QAngle();
        ToChange = Delta - Delta * Smooth;

        Angle = ViewAngles + ToChange;
    }

    bool GetAngle(Player* Target, QAngle& Angle) {
        const QAngle CurrentAngle = QAngle(Myself->ViewAngles.x, Myself->ViewAngles.y).NormalizeAngles();
        if (!CurrentAngle.isValid())
            return false;

        if (!GetAngleToTarget(Target, Angle))
            return false;

        return true;
    }

    bool GetAngleToTarget(Player* Target, QAngle& Angle) {
        Vector3D TargetPosition;
        if (!ClosestHitbox) {
        TargetPosition = Target->GetBonePosition(Modules::Aimbot::Hitbox);
        }
        if (ClosestHitbox) {
        TargetPosition = Target->GetBonePosition(static_cast<HitboxType>(GetBestBone(Target)));
        }
        Vector3D TargetVelocity = Target->AbsoluteVelocity;
        Vector3D CameraPosition = Myself->CameraPosition;
        QAngle CurrentAngle = QAngle(Myself->ViewAngles.x, Myself->ViewAngles.y).NormalizeAngles();

        if (Myself->WeaponProjectileSpeed > 1.0f) {
            if (PredictBulletDrop && PredictMovement) {
                return Resolver::CalculateAimRotationNew(CameraPosition, TargetPosition, TargetVelocity, Myself->WeaponProjectileSpeed, Myself->WeaponProjectileScale, 255, Angle);
            }
            else if (PredictMovement) {
                return Resolver::CalculateAimRotationNew(CameraPosition, TargetPosition, Vector3D(0, 0, 0), Myself->WeaponProjectileSpeed, Myself->WeaponProjectileScale, 255, Angle);
            }
            else if (PredictBulletDrop) {
                return Resolver::CalculateAimRotation(CameraPosition, TargetPosition, TargetVelocity, Myself->WeaponProjectileSpeed, Angle);
            }
        }

        Angle = Resolver::CalculateAngle(CameraPosition, TargetPosition);

        return true;
    }

    bool active() {
        bool aimbotIsOn = AimbotEnabled;
        bool combatReady = Myself->IsCombatReady();
        int weaponId = Myself->WeaponIndex;
        bool weaponDiscarded = Myself->weaponDiscarded;

        bool activatedByAimBind = InputManager::isKeyDownOrPress(Modules::Aimbot::AimBind);
        bool activatedByExtraBind = InputManager::isKeyDownOrPress(Modules::Aimbot::ExtraBind);
        bool activatedByAttackingAndIsAttacking = OnFire && Myself->IsInAttack;
        bool activatedByADSAndIsADSing = OnADS && Myself->IsZooming;
        if (Modules::Aimbot::BindMethod == 0) { //OnFire and OnADS
            bool active = aimbotIsOn
            && combatReady
            && !weaponDiscarded
            && (activatedByAttackingAndIsAttacking
                || activatedByADSAndIsADSing);
            return active;
        }
        else if (Modules::Aimbot::BindMethod == 1) { //Keybinds
            bool active = aimbotIsOn
                && combatReady
                && !weaponDiscarded
                && (activatedByAimBind
                    || activatedByExtraBind);
            return active;
        }
    }

    void assignTarget() {
        for (int i = 0;i < Players->size();i++) {
            Player* p = Players->at(i);
            if (TeamCheck) {
                if (!p->IsCombatReady())continue;
                if (!p->IsHostile) continue;
                if (!p->IsVisible) continue;
                if (p->IsAimedAt) continue;
                if (fabs(p->aimbotDesiredAnglesIncrement.x) > FOV1) continue;
                if (fabs(p->aimbotDesiredAnglesIncrement.y) > FOV1) continue;
                if (CurrentTarget == nullptr || p->aimbotScore > CurrentTarget->aimbotScore) {
                CurrentTarget = p;
                CurrentTarget->aimbotLocked = true;
                }
        }
            if (!TeamCheck) {
                if (!p->IsCombatReady())continue;
                if (!p->IsVisible) continue;
                if (p->IsAimedAt) continue;
                if (fabs(p->aimbotDesiredAnglesIncrement.x) > FOV1) continue;
                if (fabs(p->aimbotDesiredAnglesIncrement.y) > FOV1) continue;
                if (CurrentTarget == nullptr || p->aimbotScore > CurrentTarget->aimbotScore) {
                CurrentTarget = p;
                CurrentTarget->aimbotLocked = true;
                }
        }
        }
    }

    bool IsValidTarget(Player* target) {
        if (TeamCheck) {
            if (VisCheck) {
            if (target == nullptr ||
                !target->IsCombatReady() ||
                !target->IsVisible ||
                !target->IsHostile ||
                target->Distance2DToLocalPlayer < Conversion::ToGameUnits(MinDistance) ||
                target->Distance2DToLocalPlayer > Conversion::ToGameUnits(FinalDistance))
                return false;
            return true;
        }
            if (!VisCheck) {
            if (target == nullptr ||
                !target->IsCombatReady() ||
                !target->IsHostile ||
                target->Distance2DToLocalPlayer < Conversion::ToGameUnits(MinDistance) ||
                target->Distance2DToLocalPlayer > Conversion::ToGameUnits(FinalDistance))
                return false;
            return true;
        }
        } //Ignore The Warnings
        if (!TeamCheck) {
            if (VisCheck) {
            if (target == nullptr ||
                !target->IsCombatReady() ||
                !target->IsVisible ||
                target->Distance2DToLocalPlayer < Conversion::ToGameUnits(MinDistance) ||
                target->Distance2DToLocalPlayer > Conversion::ToGameUnits(FinalDistance))
                return false;
            return true;
        }
            if (!VisCheck) {
            if (target == nullptr ||
                !target->IsCombatReady() ||
                target->Distance2DToLocalPlayer < Conversion::ToGameUnits(MinDistance) ||
                target->Distance2DToLocalPlayer > Conversion::ToGameUnits(FinalDistance))
                return false;
            return true;
        }
        } //Ignore The Warnings
    } //Ignore The Warnings!!!
    float CalculatePitchIncrement(QAngle AimbotDesiredAngles) {
        float wayA = AimbotDesiredAngles.x - Myself->ViewAngles.x;
        float wayB = 180 - abs(wayA);
        if (wayA > 0 && wayB > 0)
            wayB *= -1;
        if (fabs(wayA) < fabs(wayB))
            return wayA;
        return wayB;
    }

    float CalculateYawIncrement(QAngle AimbotDesiredAngles) {
        float wayA = AimbotDesiredAngles.y - Myself->ViewAngles.y;
        float wayB = 360 - abs(wayA);
        if (wayA > 0 && wayB > 0)
            wayB *= -1;
        if (fabs(wayA) < fabs(wayB))
            return wayA;
        return wayB;
    }

    double CalculateDistanceFromCrosshair(Vector3D TargetPosition) {
        Vector3D CameraPosition = Myself->CameraPosition;
        QAngle CurrentAngle = QAngle(Myself->ViewAngles.x, Myself->ViewAngles.y).NormalizeAngles();

        if (CameraPosition.Distance(TargetPosition) <= 0.0001f)
            return -1;

        QAngle TargetAngle = Resolver::CalculateAngle(CameraPosition, TargetPosition);
        if (!TargetAngle.isValid())
            return -1;

        return CurrentAngle.distanceTo(TargetAngle);
    }

    void releaseTarget2() {
        if (CurrentTarget != nullptr && CurrentTarget->IsValid())
            CurrentTarget->aimbotLocked = false;
        CurrentTarget = nullptr;
    }

    void resetLockFlag() {
        for (int i = 0;i < Players->size();i++) {
            Player* p = Players->at(i);
            if (!p->IsCombatReady()) continue;
            p->aimbotLocked = false;
        }
        if (CurrentTarget != nullptr)
            CurrentTarget->aimbotLocked = true;
    }

    int roundHalfEven2(float x) {
        return (x >= 0.0)
            ? static_cast<int>(std::round(x))
            : static_cast<int>(std::round(-x)) * -1;
    }

    float atLeast_1_AwayFromZero(float num) {
        if (num > 0) return std::max(num, 1.0f);
        return std::min(num, -1.0f);
    }

    void ReleaseTarget() {
        if (CurrentTarget != nullptr && CurrentTarget->IsValid())
            CurrentTarget->IsLockedOn = false;

        TargetSelected = false;
        CurrentTarget = nullptr;
    }

    int RoundHalfEven(float x) {
        return (x >= 0.0)
            ? static_cast<int>(std::round(x))
            : static_cast<int>(std::round(-x)) * -1;
    }

    float AL1AF0(float num) {
        if (num > 0) return std::max(num, 1.0f);
        return std::min(num, -1.0f);
    }

    float GetFOVScale() {
        if (Myself->IsValid()) {
            if (Myself->IsZooming) {
                if (Myself->TargetZoomFOV > 1.0 && Myself->TargetZoomFOV < 90.0) {
                    return tanf(DEG2RAD(Myself->TargetZoomFOV) * (0.64285714285));
                }
            }
        }
        return 1.0;
    }

    void RecoilControl(QAngle& Angle) {
          QAngle CurrentPunch = QAngle(Myself->PunchAngles.x, Myself->PunchAngles.y).NormalizeAngles();
          QAngle NewPunch = { CurrentPunch.x - RCSLastPunch.x, CurrentPunch.y - RCSLastPunch.y };

          CurrentPunch.x *=  (PitchP / 100.f);
          CurrentPunch.y *=  (YawP / 100.f);

          Angle.x -= CurrentPunch.x;
          Angle.y -= CurrentPunch.y;

          RCSLastPunch = CurrentPunch;
      }

    int GetBestBone(Player* Target) {
        float NearestDistance = 999;
        int NearestBone = 2;
        for (int i = 0; i < 6; i++) {
            HitboxType Bone = static_cast<HitboxType>(i);
            double DistanceFromCrosshair = CalculateDistanceFromCrosshair(Target->GetBonePosition(Bone));
            if (DistanceFromCrosshair < NearestDistance) {
                NearestBone = i;
                NearestDistance = DistanceFromCrosshair;
            }
        }
        return NearestBone;
    }

    Player* FindBestTarget() {
        Player* NearestTarget = nullptr;
        float BestDistance = 9999;
        float BestFOV = std::min(FOV, FOV * (GetFOVScale() * ZoomScale));
        float LastPov = 9999;
        Vector3D CameraPosition = Myself->CameraPosition;
        for (int i = 0; i < Players->size(); i++) {
            Player* p = Players->at(i);
            if (!IsValidTarget(p)) continue;
            if (p->DistanceToLocalPlayer < Conversion::ToGameUnits(ZoomDistance)) {
                HitboxType BestBone = static_cast<HitboxType>(GetBestBone(p));
                Vector3D TargetPosition = p->GetBonePosition(BestBone);

                float Distance = CameraPosition.Distance(TargetPosition);
                float FOV = CalculateDistanceFromCrosshair(TargetPosition);

                if (FOV > BestFOV) continue;
                if (FOV > LastPov) //https://imgur.com/a/sKG5ljY
                    continue;
                //if (Distance > BestDistance) continue;

                NearestTarget = p;
                BestDistance = Distance;
                LastPov = FOV;
            }
        }
        return NearestTarget;
    }

    void UpdateSettings() {
        if (!AdvancedAim) {
            return;
        }
        int weaponHeld = Myself->WeaponIndex;


        //Keybinds && Deadzone
        if (AdvancedAim) {
            if (weaponHeld == 106) { //P2020
                Modules::Aimbot::AimBind = Modules::Aimbot::P2020AimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::P2020ExtraBind;
                Aimbot::OnFire = Aimbot::P2020Fire;
                Aimbot::OnADS = Aimbot::P2020ADS;
                Aimbot::AdvancedDeadzone = Aimbot::P2020Deadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::P2020ClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::P2020Hitbox);
                Aimbot::AdvancedSpeed = Aimbot::P2020Speed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::P2020HipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::P2020ADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::P2020HipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::P2020ADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::P2020ExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::P2020FOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::P2020MinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::P2020MaxDistance1;

            }
            if (weaponHeld == 81) { //RE45
                Modules::Aimbot::AimBind = Modules::Aimbot::RE45AimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::RE45ExtraBind;
                Aimbot::OnFire = Aimbot::RE45Fire;
                Aimbot::OnADS = Aimbot::RE45ADS;
                Aimbot::AdvancedDeadzone = Aimbot::RE45Deadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::RE45ClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::RE45Hitbox);
                Aimbot::AdvancedSpeed = Aimbot::RE45Speed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::RE45HipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::RE45ADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::RE45HipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::RE45ADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::RE45ExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::RE45FOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::RE45MinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::RE45MaxDistance1;
            }
            if (weaponHeld == 80) { //Alternator
                Modules::Aimbot::AimBind = Modules::Aimbot::AlternatorAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::AlternatorExtraBind;
                Aimbot::OnFire = Aimbot::AlternatorFire;
                Aimbot::OnADS = Aimbot::AlternatorADS;
                Aimbot::AdvancedDeadzone = Aimbot::AlternatorDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::AlternatorClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::AlternatorHitbox);
                Aimbot::AdvancedSpeed = Aimbot::AlternatorSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::AlternatorHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::AlternatorADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::AlternatorHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::AlternatorADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::AlternatorExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::AlternatorFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::AlternatorMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::AlternatorMaxDistance1;
            }
            if (weaponHeld == 105) { //R99
                Modules::Aimbot::AimBind = Modules::Aimbot::R99AimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::R99ExtraBind;
                Aimbot::OnFire = Aimbot::R99Fire;
                Aimbot::OnADS = Aimbot::R99ADS;
                Aimbot::AdvancedDeadzone = Aimbot::R99Deadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::R99ClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::R99Hitbox);
                Aimbot::AdvancedSpeed = Aimbot::R99Speed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::R99HipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::R99ADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::R99HipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::R99ADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::R99ExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::R99FOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::R99MinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::R99MaxDistance1;
            }
            if (weaponHeld == 0) { //R301
                Modules::Aimbot::AimBind = Modules::Aimbot::R301AimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::R301ExtraBind;
                Aimbot::OnFire = Aimbot::R301Fire;
                Aimbot::OnADS = Aimbot::R301ADS;
                Aimbot::AdvancedDeadzone = Aimbot::R301Deadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::R301ClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::R301Hitbox);
                Aimbot::AdvancedSpeed = Aimbot::R301Speed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::R301HipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::R301ADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::R301HipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::R301ADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::R301ExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::R301FOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::R301MinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::R301MaxDistance1;
            }
            if (weaponHeld == 107) { //Spitfire
                Modules::Aimbot::AimBind = Modules::Aimbot::SpitfireAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::SpitfireExtraBind;
                Aimbot::OnFire = Aimbot::SpitfireFire;
                Aimbot::OnADS = Aimbot::SpitfireADS;
                Aimbot::AdvancedDeadzone = Aimbot::SpitfireDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::SpitfireClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::SpitfireHitbox);
                Aimbot::AdvancedSpeed = Aimbot::SpitfireSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::SpitfireHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::SpitfireADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::SpitfireHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::SpitfireADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::SpitfireExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::SpitfireFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::SpitfireMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::SpitfireMaxDistance1;
            }
            if (weaponHeld == 90) { //G7
                Modules::Aimbot::AimBind = Modules::Aimbot::G7AimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::G7ExtraBind;
                Aimbot::OnFire = Aimbot::G7Fire;
                Aimbot::OnADS = Aimbot::G7ADS;
                Aimbot::AdvancedDeadzone = Aimbot::G7Deadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::G7ClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::G7Hitbox);
                Aimbot::AdvancedSpeed = Aimbot::G7Speed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::G7HipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::G7ADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::G7HipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::G7ADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::G7ExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::G7FOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::G7MinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::G7MaxDistance1;
            }
            //Heavy Weapons
            if (weaponHeld == 113) { //CARSMG
                Modules::Aimbot::AimBind = Modules::Aimbot::CARSMGAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::CARSMGExtraBind;
                Aimbot::OnFire = Aimbot::CARSMGFire;
                Aimbot::OnADS = Aimbot::CARSMGADS;
                Aimbot::AdvancedDeadzone = Aimbot::CARSMGDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::CARSMGClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::CARSMGHitbox);
                Aimbot::AdvancedSpeed = Aimbot::CARSMGSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::CARSMGHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::CARSMGADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::CARSMGHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::CARSMGADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::CARSMGExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::CARSMGFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::CARSMGMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::CARSMGMaxDistance1;
            }
            if (weaponHeld == 21) { //Rampage
                Modules::Aimbot::AimBind = Modules::Aimbot::RampageAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::RampageExtraBind;
                Aimbot::OnFire = Aimbot::RampageFire;
                Aimbot::OnADS = Aimbot::RampageADS;
                Aimbot::AdvancedDeadzone = Aimbot::RampageDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::RampageClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::RampageHitbox);
                Aimbot::AdvancedSpeed = Aimbot::RampageSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::RampageHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::RampageADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::RampageHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::RampageADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::RampageExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::RampageFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::RampageMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::RampageMaxDistance1;
            }
            if (weaponHeld == 112) { //Repeater
                Modules::Aimbot::AimBind = Modules::Aimbot::RepeaterAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::RepeaterExtraBind;
                Aimbot::OnFire = Aimbot::RepeaterFire;
                Aimbot::OnADS = Aimbot::RepeaterADS;
                Aimbot::AdvancedDeadzone = Aimbot::RepeaterDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::RepeaterClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::RepeaterHitbox);
                Aimbot::AdvancedSpeed = Aimbot::RepeaterSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::RepeaterHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::RepeaterADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::RepeaterHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::RepeaterADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::RepeaterExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::RepeaterFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::RepeaterMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::RepeaterMaxDistance1;
            }
            if (weaponHeld == 102) { //Prowler
                Modules::Aimbot::AimBind = Modules::Aimbot::ProwlerAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::ProwlerExtraBind;
                Aimbot::OnFire = Aimbot::ProwlerFire;
                Aimbot::OnADS = Aimbot::ProwlerADS;
                Aimbot::AdvancedDeadzone = Aimbot::ProwlerDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::ProwlerClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::ProwlerHitbox);
                Aimbot::AdvancedSpeed = Aimbot::ProwlerSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::ProwlerHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::ProwlerADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::ProwlerHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::ProwlerADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::ProwlerExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::ProwlerFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::ProwlerMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::ProwlerMaxDistance1;
            }
            if (weaponHeld == 91) { //Hemlock
                Modules::Aimbot::AimBind = Modules::Aimbot::HemlockAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::HemlockExtraBind;
                Aimbot::OnFire = Aimbot::HemlockFire;
                Aimbot::OnADS = Aimbot::HemlockADS;
                Aimbot::AdvancedDeadzone = Aimbot::HemlockDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::HemlockClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::HemlockHitbox);
                Aimbot::AdvancedSpeed = Aimbot::HemlockSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::HemlockHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::HemlockADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::HemlockHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::HemlockADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::HemlockExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::HemlockFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::HemlockMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::HemlockMaxDistance1;
            }
            if (weaponHeld == 89) { //Flatline
                Modules::Aimbot::AimBind = Modules::Aimbot::FlatlineAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::FlatlineExtraBind;
                Aimbot::OnFire = Aimbot::FlatlineFire;
                Aimbot::OnADS = Aimbot::FlatlineADS;
                Aimbot::AdvancedDeadzone = Aimbot::FlatlineDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::FlatlineClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::FlatlineHitbox);
                Aimbot::AdvancedSpeed = Aimbot::FlatlineSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::FlatlineHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::FlatlineADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::FlatlineHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::FlatlineADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::FlatlineExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::FlatlineFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::FlatlineMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::FlatlineMaxDistance1;
            }
            //Energy Weapons
            if (weaponHeld == 114) { //Nemesis
                Modules::Aimbot::AimBind = Modules::Aimbot::NemesisAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::NemesisExtraBind;
                Aimbot::OnFire = Aimbot::NemesisFire;
                Aimbot::OnADS = Aimbot::NemesisADS;
                Aimbot::AdvancedDeadzone = Aimbot::NemesisDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::NemesisClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::NemesisHitbox);
                Aimbot::AdvancedSpeed = Aimbot::NemesisSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::NemesisHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::NemesisADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::NemesisHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::NemesisADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::NemesisExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::NemesisFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::NemesisMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::NemesisMaxDistance1;
            }
            if (weaponHeld == 111) { //Volt
                Modules::Aimbot::AimBind = Modules::Aimbot::VoltAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::VoltExtraBind;
                Aimbot::OnFire = Aimbot::VoltFire;
                Aimbot::OnADS = Aimbot::VoltADS;
                Aimbot::AdvancedDeadzone = Aimbot::VoltDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::VoltClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::VoltHitbox);
                Aimbot::AdvancedSpeed = Aimbot::VoltSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::VoltHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::VoltADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::VoltHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::VoltADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::VoltExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::VoltFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::VoltMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::VoltMaxDistance1;
            }
            if (weaponHeld == 108) { //TripleTake
                Modules::Aimbot::AimBind = Modules::Aimbot::TripleTakeAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::TripleTakeExtraBind;
                Aimbot::OnFire = Aimbot::TripleTakeFire;
                Aimbot::OnADS = Aimbot::TripleTakeADS;
                Aimbot::AdvancedDeadzone = Aimbot::TripleTakeDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::TripleTakeClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::TripleTakeHitbox);
                Aimbot::AdvancedSpeed = Aimbot::TripleTakeSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::TripleTakeHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::TripleTakeADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::TripleTakeHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::TripleTakeADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::TripleTakeExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::TripleTakeFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::TripleTakeMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::TripleTakeMaxDistance1;
            }
            if (weaponHeld == 94) { //LSTAR
                Modules::Aimbot::AimBind = Modules::Aimbot::LSTARAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::LSTARExtraBind;
                Aimbot::OnFire = Aimbot::LSTARFire;
                Aimbot::OnADS = Aimbot::LSTARADS;
                Aimbot::AdvancedDeadzone = Aimbot::LSTARDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::LSTARClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::LSTARHitbox);
                Aimbot::AdvancedSpeed = Aimbot::LSTARSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::LSTARHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::LSTARADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::LSTARHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::LSTARADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::LSTARExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::LSTARFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::LSTARMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::LSTARMaxDistance1;
            }
            if (weaponHeld == 84) { //Devotion
                Modules::Aimbot::AimBind = Modules::Aimbot::DevotionAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::DevotionExtraBind;
                Aimbot::OnFire = Aimbot::DevotionFire;
                Aimbot::OnADS = Aimbot::DevotionADS;
                Aimbot::AdvancedDeadzone = Aimbot::DevotionDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::DevotionClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::DevotionHitbox);
                Aimbot::AdvancedSpeed = Aimbot::DevotionSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::DevotionHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::DevotionADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::DevotionHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::DevotionADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::DevotionExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::DevotionFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::DevotionMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::DevotionMaxDistance1;
            }
            if (weaponHeld == 86) { //Havoc
                Modules::Aimbot::AimBind = Modules::Aimbot::HavocAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::HavocExtraBind;
                Aimbot::OnFire = Aimbot::HavocFire;
                Aimbot::OnADS = Aimbot::HavocADS;
                Aimbot::AdvancedDeadzone = Aimbot::HavocDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::HavocClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::HavocHitbox);
                Aimbot::AdvancedSpeed = Aimbot::HavocSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::HavocHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::HavocADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::HavocHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::HavocADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::HavocExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::HavocFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::HavocMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::HavocMaxDistance1;
            }
            //Shotguns
            if (weaponHeld == 97) { //Mozambique
                Modules::Aimbot::AimBind = Modules::Aimbot::MozambiqueAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::MozambiqueExtraBind;
                Aimbot::OnFire = Aimbot::MozambiqueFire;
                Aimbot::OnADS = Aimbot::MozambiqueADS;
                Aimbot::AdvancedDeadzone = Aimbot::MozambiqueDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::MozambiqueClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::MozambiqueHitbox);
                Aimbot::AdvancedSpeed = Aimbot::MozambiqueSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::MozambiqueHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::MozambiqueADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::MozambiqueHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::MozambiqueADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::MozambiqueExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::MozambiqueFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::MozambiqueMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::MozambiqueMaxDistance1;
            }
            if (weaponHeld == 104) { //Peacekeeper
                Modules::Aimbot::AimBind = Modules::Aimbot::PeacekeeperAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::PeacekeeperExtraBind;
                Aimbot::OnFire = Aimbot::PeacekeeperFire;
                Aimbot::OnADS = Aimbot::PeacekeeperADS;
                Aimbot::AdvancedDeadzone = Aimbot::PeacekeeperDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::PeacekeeperClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::PeacekeeperHitbox);
                Aimbot::AdvancedSpeed = Aimbot::PeacekeeperSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::PeacekeeperHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::PeacekeeperADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::PeacekeeperHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::PeacekeeperADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::PeacekeeperExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::PeacekeeperFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::PeacekeeperMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::PeacekeeperMaxDistance1;
            }
            if (weaponHeld == 96) { //Mastiff
                Modules::Aimbot::AimBind = Modules::Aimbot::MastiffAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::MastiffExtraBind;
                Aimbot::OnFire = Aimbot::MastiffFire;
                Aimbot::OnADS = Aimbot::MastiffADS;
                Aimbot::AdvancedDeadzone = Aimbot::MastiffDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::MastiffClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::MastiffHitbox);
                Aimbot::AdvancedSpeed = Aimbot::MastiffSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::MastiffHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::MastiffADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::MastiffHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::MastiffADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::MastiffExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::MastiffFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::MastiffMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::MastiffMaxDistance1;
            }
            //Snipers
            if (weaponHeld == 1) { //Sentinel
                Modules::Aimbot::AimBind = Modules::Aimbot::SentinelAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::SentinelExtraBind;
                Aimbot::OnFire = Aimbot::SentinelFire;
                Aimbot::OnADS = Aimbot::SentinelADS;
                Aimbot::AdvancedDeadzone = Aimbot::SentinelDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::SentinelClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::SentinelHitbox);
                Aimbot::AdvancedSpeed = Aimbot::SentinelSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::SentinelHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::SentinelADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::SentinelHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::SentinelADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::SentinelExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::SentinelFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::SentinelMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::SentinelMaxDistance1;
            }
            if (weaponHeld == 83) { //ChargeRifle
                Modules::Aimbot::AimBind = Modules::Aimbot::ChargeRifleAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::ChargeRifleExtraBind;
                Aimbot::OnFire = Aimbot::ChargeRifleFire;
                Aimbot::OnADS = Aimbot::ChargeRifleADS;
                Aimbot::AdvancedDeadzone = Aimbot::ChargeRifleDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::ChargeRifleClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::ChargeRifleHitbox);
                Aimbot::AdvancedSpeed = Aimbot::ChargeRifleSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::ChargeRifleHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::ChargeRifleADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::ChargeRifleHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::ChargeRifleADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::ChargeRifleExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::ChargeRifleFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::ChargeRifleMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::ChargeRifleMaxDistance1;
            }
            if (weaponHeld == 85) { //Longbow
                Modules::Aimbot::AimBind = Modules::Aimbot::LongbowAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::LongbowExtraBind;
                Aimbot::OnFire = Aimbot::LongbowFire;
                Aimbot::OnADS = Aimbot::LongbowADS;
                Aimbot::AdvancedDeadzone = Aimbot::LongbowDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::LongbowClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::LongbowHitbox);
                Aimbot::AdvancedSpeed = Aimbot::LongbowSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::LongbowHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::LongbowADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::LongbowHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::LongbowADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::LongbowExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::LongbowFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::LongbowMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::LongbowMaxDistance1;
            }
            //Legendary Weapons
            if (weaponHeld == 110) { //Wingman
                Modules::Aimbot::AimBind = Modules::Aimbot::WingmanAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::WingmanExtraBind;
                Aimbot::OnFire = Aimbot::WingmanFire;
                Aimbot::OnADS = Aimbot::WingmanADS;
                Aimbot::AdvancedDeadzone = Aimbot::WingmanDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::WingmanClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::WingmanHitbox);
                Aimbot::AdvancedSpeed = Aimbot::WingmanSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::WingmanHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::WingmanADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::WingmanHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::WingmanADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::WingmanExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::WingmanFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::WingmanMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::WingmanMaxDistance1;
            }
            if (weaponHeld == 88) { //EVA8
                Modules::Aimbot::AimBind = Modules::Aimbot::EVA8AimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::EVA8ExtraBind;
                Aimbot::OnFire = Aimbot::EVA8Fire;
                Aimbot::OnADS = Aimbot::EVA8ADS;
                Aimbot::AdvancedDeadzone = Aimbot::EVA8Deadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::EVA8ClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::EVA8Hitbox);
                Aimbot::AdvancedSpeed = Aimbot::EVA8Speed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::EVA8HipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::EVA8ADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::EVA8HipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::EVA8ADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::EVA8ExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::EVA8FOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::EVA8MinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::EVA8MaxDistance1;
            }
            if (weaponHeld == 2) { //Bocek
                Modules::Aimbot::AimBind = Modules::Aimbot::BocekAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::BocekExtraBind;
                Aimbot::OnFire = Aimbot::BocekFire;
                Aimbot::OnADS = Aimbot::BocekADS;
                Aimbot::AdvancedDeadzone = Aimbot::BocekDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::BocekClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::BocekHitbox);
                Aimbot::AdvancedSpeed = Aimbot::BocekSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::BocekHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::BocekADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::BocekHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::BocekADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::BocekExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::BocekFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::BocekMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::BocekMaxDistance1;
            }
            if (weaponHeld == 93) { //Kraber
                Modules::Aimbot::AimBind = Modules::Aimbot::KraberAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::KraberExtraBind;
                Aimbot::OnFire = Aimbot::KraberFire;
                Aimbot::OnADS = Aimbot::KraberADS;
                Aimbot::AdvancedDeadzone = Aimbot::KraberDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::KraberClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::KraberHitbox);
                Aimbot::AdvancedSpeed = Aimbot::KraberSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::KraberHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::KraberADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::KraberHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::KraberADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::KraberExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::KraberFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::KraberMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::KraberMaxDistance1;
            }
            if (weaponHeld == 166) { //ThrowingKnife
                Modules::Aimbot::AimBind = Modules::Aimbot::ThrowingKnifeAimBind;
                Modules::Aimbot::ExtraBind = Modules::Aimbot::ThrowingKnifeExtraBind;
                Aimbot::OnFire = Aimbot::ThrowingKnifeFire;
                Aimbot::OnADS = Aimbot::ThrowingKnifeADS;
                Aimbot::AdvancedDeadzone = Aimbot::ThrowingKnifeDeadzone;
                //Cubic Bezier (xap-client)
                Aimbot::ClosestHitbox = Aimbot::ThrowingKnifeClosestHitbox;
                Modules::Aimbot::Hitbox = static_cast<HitboxType>(Modules::Aimbot::ThrowingKnifeHitbox);
                Aimbot::AdvancedSpeed = Aimbot::ThrowingKnifeSpeed;
                Aimbot::AdvancedHipfireSmooth = Aimbot::ThrowingKnifeHipfireSmooth;
                Aimbot::AdvancedADSSmooth = Aimbot::ThrowingKnifeADSSmooth;
                //Grinder
                Aimbot::AdvancedHipfireSmooth1 = Aimbot::ThrowingKnifeHipfireSmooth1;
                Aimbot::AdvancedADSSmooth1 = Aimbot::ThrowingKnifeADSSmooth1;
                Aimbot::AdvancedExtraSmooth1 = Aimbot::ThrowingKnifeExtraSmooth1;
                Aimbot::AdvancedFOV1 = Aimbot::ThrowingKnifeFOV1;
                Aimbot::AdvancedMinDistance1 = Aimbot::ThrowingKnifeMinDistance1;
                Aimbot::AdvancedMaxDistance1 = Aimbot::ThrowingKnifeMaxDistance1;
            }
        }
    }
};
