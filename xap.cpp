// Externals
#include <iostream>
#include <string>
#include <unistd.h>
#include <atomic>
#include <vector>
#include <chrono>
#include <thread>
#include <GLFW/glfw3.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XInput2.h>

// Internals
#include "Core/Level.hpp"
#include "Core/Player.hpp"
#include "Core/LocalPlayer.hpp"
#include "Core/Camera.hpp"

#include "Features/Aimbot.hpp"
#include "Features/Sense.hpp"
#include "Features/Radar.hpp"
#include "Features/Triggerbot.hpp"
#include "Features/Misc.hpp"
#include "Features/Glow.hpp"
//#include "Features/Test.hpp"

#include "Overlay/Overlay.hpp"

#include "Utils/Config.hpp"
#include "Utils/Modules.hpp"
#include "Utils/Memory.hpp"
#include "Utils/XDisplay.hpp"

// Objects
XDisplay* X11Display = new XDisplay();
Overlay OverlayWindow = Overlay();
ImDrawList* Canvas;

// Game Objects
Level* Map = new Level();
LocalPlayer* Myself = new LocalPlayer();
Camera* GameCamera = new Camera();

// Players
std::vector<Player*>* HumanPlayers = new std::vector<Player*>;
std::vector<Player*>* Dummies = new std::vector<Player*>;
std::vector<Player*>* Players = new std::vector<Player*>;

// Features
Sense* ESP = new Sense(Map, Players, GameCamera, Myself, X11Display);
Radar* MapRadar = new Radar(X11Display, Players, GameCamera, Map, Myself);
Glow* GlowESP = new Glow(Map, Players, GameCamera, Myself);
Aimbot* AimAssist = new Aimbot(X11Display, Map, Myself, Players);
//RCS* Recoil = new RCS(X11Display, Map, Myself);
Triggerbot* Trigger = new Triggerbot(X11Display, Map, Myself, Players);
Misc* MiscTab = new Misc(X11Display, Map, Myself, Players);
//Test* Testing = new Test(X11Display, Map, Myself);
Overlay* Home = new Overlay;

// Booleans and Variables
bool IsMenuOpened = true;

// Thread
std::atomic_bool StopThread(false);

// Inputs
void HandleKeyEvent(Display* display, XEvent* Event) {
    if (Event->type == KeyPress) {
        if (IsMenuOpened) {
            IsMenuOpened = false;
            Modules::Home::IsMenuOpened = false;
            OverlayWindow.CaptureInput(false);
        } else {
            IsMenuOpened = true;
            Modules::Home::IsMenuOpened = true;
            OverlayWindow.CaptureInput(true);
        }
    }
}

void X11EventListener() {
    Display* display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    XGrabKey(display, XKeysymToKeycode(display, XK_Insert), AnyModifier, root, False, GrabModeAsync, GrabModeAsync);
    XEvent event;
    while (!StopThread) {
        XNextEvent(display, &event);
        HandleKeyEvent(display, &event);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    XCloseDisplay(display);
}

// Overlay
bool InitializeOverlayWindow() {
    if (!OverlayWindow.InitializeOverlay()) {
        OverlayWindow.DestroyOverlay();
        return false;
    }
    int ScreenWidth;
    int ScreenHeight;
    OverlayWindow.GetScreenResolution(ScreenWidth, ScreenHeight);
    GameCamera->Initialize(ScreenWidth, ScreenHeight);
    std::cout << "overlay initialized" << std::endl;
    return true;
}

// Config
void LoadConfig() {
    bool success = ReadConfig("config.ini");
    if (success)
        std::cout << "successfully read config" << std::endl;
    else
        std::cout << "can't read config for some reason so new config file has been created" << std::endl;

    // Aimbot //
    AimAssist->AimbotEnabled = Config::Aimbot::Enabled;
    AimAssist->AimbotMode = Config::Aimbot::AimbotMode;
    Modules::Aimbot::BindMethod = Config::Aimbot::BindMethod;
    Modules::Aimbot::AimBind = static_cast<InputKeyType>(Config::Aimbot::AimBind);
    Modules::Aimbot::ExtraBind = static_cast<InputKeyType>(Config::Aimbot::ExtraBind);
    AimAssist->ClosestHitbox = Config::Aimbot::ClosestHitbox;
    Modules::Aimbot::Hitbox = static_cast<HitboxType>(Config::Aimbot::HitBox);
    AimAssist->TeamCheck = Config::Aimbot::TeamCheck;
    AimAssist->VisCheck = Config::Aimbot::VisCheck;
    AimAssist->PredictMovement = Config::Aimbot::PredictMovement;
    AimAssist->PredictBulletDrop = Config::Aimbot::PredictBulletDrop;
    AimAssist->Speed = Config::Aimbot::Speed;
    AimAssist->Smooth = Config::Aimbot::Smooth;
    AimAssist->HipfireSmooth = Config::Aimbot::HipfireSmooth;
    AimAssist->ADSSmooth = Config::Aimbot::ADSSmooth;
    AimAssist->SmoothDistance = Config::Aimbot::SmoothDistance;
    AimAssist->Delay = Config::Aimbot::Delay;
    AimAssist->Deadzone = Config::Aimbot::Deadzone;
    AimAssist->FOV = Config::Aimbot::FOV;
    AimAssist->ZoomScale = Config::Aimbot::ZoomScale;
    AimAssist->MinDistance = Config::Aimbot::MinDistance;
    AimAssist->HipfireDistance = Config::Aimbot::HipfireDistance;
    AimAssist->ZoomDistance = Config::Aimbot::ZoomDistance;
    //Weapons
    AimAssist->P2020 = Config::Aimbot::P2020;
    AimAssist->RE45 = Config::Aimbot::RE45;
    AimAssist->Alternator = Config::Aimbot::Alternator;
    AimAssist->R99 = Config::Aimbot::R99;
    AimAssist->R301 = Config::Aimbot::R301;
    AimAssist->Spitfire = Config::Aimbot::Spitfire;
    AimAssist->G7 = Config::Aimbot::G7;
    AimAssist->Flatline = Config::Aimbot::Flatline;
    AimAssist->Hemlock = Config::Aimbot::Hemlock;
    AimAssist->Repeater = Config::Aimbot::Repeater;
    AimAssist->Rampage = Config::Aimbot::Rampage;
    AimAssist->CARSMG = Config::Aimbot::CARSMG;
    AimAssist->Havoc = Config::Aimbot::Havoc;
    AimAssist->Devotion = Config::Aimbot::Devotion;
    AimAssist->LSTAR = Config::Aimbot::LSTAR;
    AimAssist->TripleTake = Config::Aimbot::TripleTake;
    AimAssist->Volt = Config::Aimbot::Volt;
    AimAssist->Nemesis = Config::Aimbot::Nemesis;
    AimAssist->Mozambique = Config::Aimbot::Mozambique;
    AimAssist->EVA8 = Config::Aimbot::EVA8;
    AimAssist->Peacekeeper = Config::Aimbot::Peacekeeper;
    AimAssist->Mastiff = Config::Aimbot::Mastiff;
    AimAssist->Longbow = Config::Aimbot::Longbow;
    AimAssist->ChargeRifle = Config::Aimbot::ChargeRifle;
    AimAssist->Sentinel = Config::Aimbot::Sentinel;
    AimAssist->Wingman = Config::Aimbot::Wingman;
    AimAssist->Prowler = Config::Aimbot::Prowler;
    AimAssist->Bocek = Config::Aimbot::Bocek;
    AimAssist->Kraber = Config::Aimbot::Kraber;
    AimAssist->Knife = Config::Aimbot::Knife;
    
    //---------------Advanced---------------//
    AimAssist->AdvancedAim = Config::Aimbot::AdvancedAim;
    //Aimbot Mode 0 - xap-client
    AimAssist->AdvancedClosestHitbox = Config::Aimbot::AdvancedClosestHitbox;
    AimAssist->AdvancedHitbox = Config::Aimbot::AdvancedHitbox;
    AimAssist->AdvancedSpeed = Config::Aimbot::AdvancedSpeed;
    AimAssist->AdvancedSmooth = Config::Aimbot::AdvancedSmooth;
    AimAssist->AdvancedHipfireSmooth = Config::Aimbot::AdvancedHipfireSmooth;
    AimAssist->AdvancedADSSmooth = Config::Aimbot::AdvancedADSSmooth;
	
    //Aimbot Mode 1 - Grinder
    AimAssist->AdvancedHipfireSmooth1 = Config::Aimbot::AdvancedHipfireSmooth1;
    AimAssist->AdvancedADSSmooth1 = Config::Aimbot::AdvancedADSSmooth1;
    AimAssist->AdvancedExtraSmooth1 = Config::Aimbot::AdvancedExtraSmooth1;
    AimAssist->AdvancedDeadzone = Config::Aimbot::AdvancedDeadzone;
    AimAssist->AdvancedFOV1 = Config::Aimbot::AdvancedFOV1;
    AimAssist->AdvancedMinDistance1 = Config::Aimbot::AdvancedMinDistance1;
    AimAssist->AdvancedMaxDistance1 = Config::Aimbot::AdvancedMaxDistance1;
    
    //Advanced OnFire & OnADS
    AimAssist->P2020Fire = Config::Aimbot::P2020Fire;
    AimAssist->P2020ADS = Config::Aimbot::P2020ADS;
    AimAssist->RE45Fire = Config::Aimbot::RE45Fire;
    AimAssist->RE45ADS = Config::Aimbot::RE45ADS;
    AimAssist->AlternatorFire = Config::Aimbot::AlternatorFire;
    AimAssist->AlternatorADS = Config::Aimbot::AlternatorADS;
    AimAssist->R99Fire = Config::Aimbot::R99Fire;
    AimAssist->R99ADS = Config::Aimbot::R99ADS;
    AimAssist->R301Fire = Config::Aimbot::R301Fire;
    AimAssist->R301ADS = Config::Aimbot::R301ADS;
    AimAssist->SpitfireFire = Config::Aimbot::SpitfireFire;
    AimAssist->SpitfireADS = Config::Aimbot::SpitfireADS;
    AimAssist->G7Fire = Config::Aimbot::G7Fire;
    AimAssist->G7ADS = Config::Aimbot::G7ADS;
    AimAssist->FlatlineFire = Config::Aimbot::FlatlineFire;
    AimAssist->FlatlineADS = Config::Aimbot::FlatlineADS;
    AimAssist->HemlockFire = Config::Aimbot::HemlockFire;
    AimAssist->HemlockADS = Config::Aimbot::HemlockADS;
    AimAssist->RepeaterFire = Config::Aimbot::RepeaterFire;
    AimAssist->RepeaterADS = Config::Aimbot::RepeaterADS;
    AimAssist->RampageFire = Config::Aimbot::RampageFire;
    AimAssist->RampageADS = Config::Aimbot::RampageADS;
    AimAssist->CARSMGFire = Config::Aimbot::CARSMGFire;
    AimAssist->CARSMGADS = Config::Aimbot::CARSMGADS;
    AimAssist->HavocFire = Config::Aimbot::HavocFire;
    AimAssist->HavocADS = Config::Aimbot::HavocADS;
    AimAssist->DevotionFire = Config::Aimbot::DevotionFire;
    AimAssist->DevotionADS = Config::Aimbot::DevotionADS;
    AimAssist->LSTARFire = Config::Aimbot::LSTARFire;
    AimAssist->LSTARADS = Config::Aimbot::LSTARADS;
    AimAssist->TripleTakeFire = Config::Aimbot::TripleTakeFire;
    AimAssist->TripleTakeADS = Config::Aimbot::TripleTakeADS;
    AimAssist->VoltFire = Config::Aimbot::VoltFire;
    AimAssist->VoltADS = Config::Aimbot::VoltADS;
    AimAssist->NemesisFire = Config::Aimbot::NemesisFire;
    AimAssist->NemesisADS = Config::Aimbot::NemesisADS;
    AimAssist->MozambiqueFire = Config::Aimbot::MozambiqueFire;
    AimAssist->MozambiqueADS = Config::Aimbot::MozambiqueADS;
    AimAssist->EVA8Fire = Config::Aimbot::EVA8Fire;
    AimAssist->EVA8ADS = Config::Aimbot::EVA8ADS;
    AimAssist->PeacekeeperFire = Config::Aimbot::PeacekeeperFire;
    AimAssist->PeacekeeperADS = Config::Aimbot::PeacekeeperADS;
    AimAssist->MastiffFire = Config::Aimbot::MastiffFire;
    AimAssist->MastiffADS = Config::Aimbot::MastiffADS;
    AimAssist->LongbowFire = Config::Aimbot::LongbowFire;
    AimAssist->LongbowADS = Config::Aimbot::LongbowADS;
    AimAssist->ChargeRifleFire = Config::Aimbot::ChargeRifleFire;
    AimAssist->ChargeRifleADS = Config::Aimbot::ChargeRifleADS;
    AimAssist->SentinelFire = Config::Aimbot::SentinelFire;
    AimAssist->SentinelADS = Config::Aimbot::SentinelADS;
    AimAssist->WingmanFire = Config::Aimbot::WingmanFire;
    AimAssist->WingmanADS = Config::Aimbot::WingmanADS;
    AimAssist->ProwlerFire = Config::Aimbot::ProwlerFire;
    AimAssist->ProwlerADS = Config::Aimbot::ProwlerADS;
    AimAssist->KraberFire = Config::Aimbot::KraberFire;
    AimAssist->KraberADS = Config::Aimbot::KraberADS;
    AimAssist->BocekFire = Config::Aimbot::BocekFire;
    AimAssist->BocekADS = Config::Aimbot::BocekADS;
    AimAssist->ThrowingKnifeFire = Config::Aimbot::ThrowingKnifeFire;
    AimAssist->ThrowingKnifeADS = Config::Aimbot::ThrowingKnifeADS;

    //Keybinds
    Modules::Aimbot::P2020AimBind = static_cast<InputKeyType>(Config::Aimbot::P2020AimBind);
    Modules::Aimbot::P2020ExtraBind = static_cast<InputKeyType>(Config::Aimbot::P2020ExtraBind);
    Modules::Aimbot::RE45AimBind = static_cast<InputKeyType>(Config::Aimbot::RE45AimBind);
    Modules::Aimbot::RE45ExtraBind = static_cast<InputKeyType>(Config::Aimbot::RE45ExtraBind);
    Modules::Aimbot::AlternatorAimBind = static_cast<InputKeyType>(Config::Aimbot::AlternatorAimBind);
    Modules::Aimbot::AlternatorExtraBind = static_cast<InputKeyType>(Config::Aimbot::AlternatorExtraBind);
    Modules::Aimbot::R99AimBind = static_cast<InputKeyType>(Config::Aimbot::R99AimBind);
    Modules::Aimbot::R99ExtraBind = static_cast<InputKeyType>(Config::Aimbot::R99ExtraBind);
    Modules::Aimbot::R301AimBind = static_cast<InputKeyType>(Config::Aimbot::R301AimBind);
    Modules::Aimbot::R301ExtraBind = static_cast<InputKeyType>(Config::Aimbot::R301ExtraBind);
    Modules::Aimbot::SpitfireAimBind = static_cast<InputKeyType>(Config::Aimbot::SpitfireAimBind);
    Modules::Aimbot::SpitfireExtraBind = static_cast<InputKeyType>(Config::Aimbot::SpitfireExtraBind);
    Modules::Aimbot::G7AimBind = static_cast<InputKeyType>(Config::Aimbot::G7AimBind);
    Modules::Aimbot::G7ExtraBind = static_cast<InputKeyType>(Config::Aimbot::G7ExtraBind);
    Modules::Aimbot::FlatlineAimBind = static_cast<InputKeyType>(Config::Aimbot::FlatlineAimBind);
    Modules::Aimbot::FlatlineExtraBind = static_cast<InputKeyType>(Config::Aimbot::FlatlineExtraBind);
    Modules::Aimbot::HemlockAimBind = static_cast<InputKeyType>(Config::Aimbot::HemlockAimBind);
    Modules::Aimbot::HemlockExtraBind = static_cast<InputKeyType>(Config::Aimbot::HemlockExtraBind);
    Modules::Aimbot::RepeaterAimBind = static_cast<InputKeyType>(Config::Aimbot::RepeaterAimBind);
    Modules::Aimbot::RepeaterExtraBind = static_cast<InputKeyType>(Config::Aimbot::RepeaterExtraBind);
    Modules::Aimbot::RampageAimBind = static_cast<InputKeyType>(Config::Aimbot::RampageAimBind);
    Modules::Aimbot::RampageExtraBind = static_cast<InputKeyType>(Config::Aimbot::RampageExtraBind);
    Modules::Aimbot::CARSMGAimBind = static_cast<InputKeyType>(Config::Aimbot::CARSMGAimBind);
    Modules::Aimbot::CARSMGExtraBind = static_cast<InputKeyType>(Config::Aimbot::CARSMGExtraBind);
    Modules::Aimbot::HavocAimBind = static_cast<InputKeyType>(Config::Aimbot::HavocAimBind);
    Modules::Aimbot::HavocExtraBind = static_cast<InputKeyType>(Config::Aimbot::HavocExtraBind);
    Modules::Aimbot::DevotionAimBind = static_cast<InputKeyType>(Config::Aimbot::DevotionAimBind);
    Modules::Aimbot::DevotionExtraBind = static_cast<InputKeyType>(Config::Aimbot::DevotionExtraBind);
    Modules::Aimbot::LSTARAimBind = static_cast<InputKeyType>(Config::Aimbot::LSTARAimBind);
    Modules::Aimbot::LSTARExtraBind = static_cast<InputKeyType>(Config::Aimbot::LSTARExtraBind);
    Modules::Aimbot::TripleTakeAimBind = static_cast<InputKeyType>(Config::Aimbot::TripleTakeAimBind);
    Modules::Aimbot::TripleTakeExtraBind = static_cast<InputKeyType>(Config::Aimbot::TripleTakeExtraBind);
    Modules::Aimbot::VoltAimBind = static_cast<InputKeyType>(Config::Aimbot::VoltAimBind);
    Modules::Aimbot::VoltExtraBind = static_cast<InputKeyType>(Config::Aimbot::VoltExtraBind);
    Modules::Aimbot::NemesisAimBind = static_cast<InputKeyType>(Config::Aimbot::NemesisAimBind);
    Modules::Aimbot::NemesisExtraBind = static_cast<InputKeyType>(Config::Aimbot::NemesisExtraBind);
    Modules::Aimbot::MozambiqueAimBind = static_cast<InputKeyType>(Config::Aimbot::MozambiqueAimBind);
    Modules::Aimbot::MozambiqueExtraBind = static_cast<InputKeyType>(Config::Aimbot::MozambiqueExtraBind);
    Modules::Aimbot::EVA8AimBind = static_cast<InputKeyType>(Config::Aimbot::EVA8AimBind);
    Modules::Aimbot::EVA8ExtraBind = static_cast<InputKeyType>(Config::Aimbot::EVA8ExtraBind);
    Modules::Aimbot::PeacekeeperAimBind = static_cast<InputKeyType>(Config::Aimbot::PeacekeeperAimBind);
    Modules::Aimbot::PeacekeeperExtraBind = static_cast<InputKeyType>(Config::Aimbot::PeacekeeperExtraBind);
    Modules::Aimbot::MastiffAimBind = static_cast<InputKeyType>(Config::Aimbot::MastiffAimBind);
    Modules::Aimbot::MastiffExtraBind = static_cast<InputKeyType>(Config::Aimbot::MastiffExtraBind);
    Modules::Aimbot::WingmanAimBind = static_cast<InputKeyType>(Config::Aimbot::WingmanAimBind);
    Modules::Aimbot::WingmanExtraBind = static_cast<InputKeyType>(Config::Aimbot::WingmanExtraBind);
    Modules::Aimbot::BocekAimBind = static_cast<InputKeyType>(Config::Aimbot::BocekAimBind);
    Modules::Aimbot::BocekExtraBind = static_cast<InputKeyType>(Config::Aimbot::BocekExtraBind);
    Modules::Aimbot::ProwlerAimBind = static_cast<InputKeyType>(Config::Aimbot::ProwlerAimBind);
    Modules::Aimbot::ProwlerExtraBind = static_cast<InputKeyType>(Config::Aimbot::ProwlerExtraBind);
    Modules::Aimbot::KraberAimBind = static_cast<InputKeyType>(Config::Aimbot::KraberAimBind);
    Modules::Aimbot::KraberExtraBind = static_cast<InputKeyType>(Config::Aimbot::KraberExtraBind);
    Modules::Aimbot::ThrowingKnifeAimBind = static_cast<InputKeyType>(Config::Aimbot::ThrowingKnifeAimBind);
    Modules::Aimbot::ThrowingKnifeExtraBind = static_cast<InputKeyType>(Config::Aimbot::ThrowingKnifeExtraBind);

    //Aimbot Mode 0 & 1 - xap-client & grinder
    AimAssist->P2020ClosestHitbox = Config::Aimbot::P2020ClosestHitbox;
    AimAssist->P2020Hitbox = Config::Aimbot::P2020Hitbox;
    AimAssist->P2020Speed = Config::Aimbot::P2020Speed;
    AimAssist->P2020HipfireSmooth = Config::Aimbot::P2020HipfireSmooth;
    AimAssist->P2020ADSSmooth = Config::Aimbot::P2020ADSSmooth;

    AimAssist->RE45ClosestHitbox = Config::Aimbot::RE45ClosestHitbox;
    AimAssist->RE45Hitbox = Config::Aimbot::RE45Hitbox;
    AimAssist->RE45Speed = Config::Aimbot::RE45Speed;
    AimAssist->RE45HipfireSmooth = Config::Aimbot::RE45HipfireSmooth;
    AimAssist->RE45ADSSmooth = Config::Aimbot::RE45ADSSmooth;

    AimAssist->AlternatorClosestHitbox = Config::Aimbot::AlternatorClosestHitbox;
    AimAssist->AlternatorHitbox = Config::Aimbot::AlternatorHitbox; 
    AimAssist->AlternatorSpeed = Config::Aimbot::AlternatorSpeed;
    AimAssist->AlternatorHipfireSmooth = Config::Aimbot::AlternatorHipfireSmooth;
    AimAssist->AlternatorADSSmooth = Config::Aimbot::AlternatorADSSmooth;

    AimAssist->R99ClosestHitbox = Config::Aimbot::R99ClosestHitbox;
    AimAssist->R99Hitbox = Config::Aimbot::R99Hitbox;
    AimAssist->R99Speed = Config::Aimbot::R99Speed;
    AimAssist->R99HipfireSmooth = Config::Aimbot::R99HipfireSmooth;
    AimAssist->R99ADSSmooth = Config::Aimbot::R99ADSSmooth;

    AimAssist->R301ClosestHitbox = Config::Aimbot::R301ClosestHitbox;
    AimAssist->R301Hitbox = Config::Aimbot::R301Hitbox;
    AimAssist->R301Speed = Config::Aimbot::R301Speed;
    AimAssist->R301HipfireSmooth = Config::Aimbot::R301HipfireSmooth;
    AimAssist->R301ADSSmooth = Config::Aimbot::R301ADSSmooth;

    AimAssist->SpitfireClosestHitbox = Config::Aimbot::SpitfireClosestHitbox;
    AimAssist->SpitfireHitbox = Config::Aimbot::SpitfireHitbox;
    AimAssist->SpitfireSpeed = Config::Aimbot::SpitfireSpeed;
    AimAssist->SpitfireHipfireSmooth = Config::Aimbot::SpitfireHipfireSmooth;
    AimAssist->SpitfireADSSmooth = Config::Aimbot::SpitfireADSSmooth;

    AimAssist->G7ClosestHitbox = Config::Aimbot::G7ClosestHitbox;
    AimAssist->G7Hitbox = Config::Aimbot::G7Hitbox;
    AimAssist->G7Speed = Config::Aimbot::G7Speed;
    AimAssist->G7HipfireSmooth = Config::Aimbot::G7HipfireSmooth;
    AimAssist->G7ADSSmooth = Config::Aimbot::G7ADSSmooth;

    AimAssist->FlatlineClosestHitbox = Config::Aimbot::FlatlineClosestHitbox;
    AimAssist->FlatlineHitbox = Config::Aimbot::FlatlineHitbox;
    AimAssist->FlatlineSpeed = Config::Aimbot::FlatlineSpeed;
    AimAssist->FlatlineHipfireSmooth = Config::Aimbot::FlatlineHipfireSmooth;
    AimAssist->FlatlineADSSmooth = Config::Aimbot::FlatlineADSSmooth;

    AimAssist->HemlockClosestHitbox = Config::Aimbot::HemlockClosestHitbox;
    AimAssist->HemlockHitbox = Config::Aimbot::HemlockHitbox;
    AimAssist->HemlockSpeed = Config::Aimbot::HemlockSpeed;
    AimAssist->HemlockHipfireSmooth = Config::Aimbot::HemlockHipfireSmooth;
    AimAssist->HemlockADSSmooth = Config::Aimbot::HemlockADSSmooth;

    AimAssist->RepeaterClosestHitbox = Config::Aimbot::RepeaterClosestHitbox;
    AimAssist->RepeaterHitbox = Config::Aimbot::RepeaterHitbox;
    AimAssist->RepeaterSpeed = Config::Aimbot::RepeaterSpeed;
    AimAssist->RepeaterHipfireSmooth = Config::Aimbot::RepeaterHipfireSmooth;
    AimAssist->RepeaterADSSmooth = Config::Aimbot::RepeaterADSSmooth;

    AimAssist->RampageClosestHitbox = Config::Aimbot::RampageClosestHitbox;
    AimAssist->RampageHitbox = Config::Aimbot::RampageHitbox;
    AimAssist->RampageSpeed = Config::Aimbot::RampageSpeed;
    AimAssist->RampageHipfireSmooth = Config::Aimbot::RampageHipfireSmooth;
    AimAssist->RampageADSSmooth = Config::Aimbot::RampageADSSmooth;

    AimAssist->CARSMGClosestHitbox = Config::Aimbot::CARSMGClosestHitbox;
    AimAssist->CARSMGHitbox = Config::Aimbot::CARSMGHitbox;
    AimAssist->CARSMGSpeed = Config::Aimbot::CARSMGSpeed;
    AimAssist->CARSMGHipfireSmooth = Config::Aimbot::CARSMGHipfireSmooth;
    AimAssist->CARSMGADSSmooth = Config::Aimbot::CARSMGADSSmooth;

    AimAssist->HavocClosestHitbox = Config::Aimbot::HavocClosestHitbox;
    AimAssist->HavocHitbox = Config::Aimbot::HavocHitbox;
    AimAssist->HavocSpeed = Config::Aimbot::HavocSpeed;
    AimAssist->HavocHipfireSmooth = Config::Aimbot::HavocHipfireSmooth;
    AimAssist->HavocADSSmooth = Config::Aimbot::HavocADSSmooth;

    AimAssist->DevotionClosestHitbox = Config::Aimbot::DevotionClosestHitbox;
    AimAssist->DevotionHitbox = Config::Aimbot::DevotionHitbox;
    AimAssist->DevotionSpeed = Config::Aimbot::DevotionSpeed;
    AimAssist->DevotionHipfireSmooth = Config::Aimbot::DevotionHipfireSmooth;
    AimAssist->DevotionADSSmooth = Config::Aimbot::DevotionADSSmooth;

    AimAssist->LSTARClosestHitbox = Config::Aimbot::LSTARClosestHitbox;
    AimAssist->LSTARHitbox = Config::Aimbot::LSTARHitbox;
    AimAssist->LSTARSpeed = Config::Aimbot::LSTARSpeed;
    AimAssist->LSTARHipfireSmooth = Config::Aimbot::LSTARHipfireSmooth;
    AimAssist->LSTARADSSmooth = Config::Aimbot::LSTARADSSmooth;

    AimAssist->TripleTakeClosestHitbox = Config::Aimbot::TripleTakeClosestHitbox;
    AimAssist->TripleTakeHitbox = Config::Aimbot::TripleTakeHitbox;
    AimAssist->TripleTakeSpeed = Config::Aimbot::TripleTakeSpeed;
    AimAssist->TripleTakeHipfireSmooth = Config::Aimbot::TripleTakeHipfireSmooth;
    AimAssist->TripleTakeADSSmooth = Config::Aimbot::TripleTakeADSSmooth;

    AimAssist->VoltClosestHitbox = Config::Aimbot::VoltClosestHitbox;
    AimAssist->VoltHitbox = Config::Aimbot::VoltHitbox;
    AimAssist->VoltSpeed = Config::Aimbot::VoltSpeed;
    AimAssist->VoltHipfireSmooth = Config::Aimbot::VoltHipfireSmooth;
    AimAssist->VoltADSSmooth = Config::Aimbot::VoltADSSmooth;

    AimAssist->NemesisClosestHitbox = Config::Aimbot::NemesisClosestHitbox;
    AimAssist->NemesisHitbox = Config::Aimbot::NemesisHitbox;
    AimAssist->NemesisSpeed = Config::Aimbot::NemesisSpeed;
    AimAssist->NemesisHipfireSmooth = Config::Aimbot::NemesisHipfireSmooth;
    AimAssist->NemesisADSSmooth = Config::Aimbot::NemesisADSSmooth;

    AimAssist->MozambiqueClosestHitbox = Config::Aimbot::MozambiqueClosestHitbox;
    AimAssist->MozambiqueHitbox = Config::Aimbot::MozambiqueHitbox;
    AimAssist->MozambiqueSpeed = Config::Aimbot::MozambiqueSpeed;
    AimAssist->MozambiqueHipfireSmooth = Config::Aimbot::MozambiqueHipfireSmooth;
    AimAssist->MozambiqueADSSmooth = Config::Aimbot::MozambiqueADSSmooth;

    AimAssist->EVA8ClosestHitbox = Config::Aimbot::EVA8ClosestHitbox;
    AimAssist->EVA8Hitbox = Config::Aimbot::EVA8Hitbox;
    AimAssist->EVA8Speed = Config::Aimbot::EVA8Speed;
    AimAssist->EVA8HipfireSmooth = Config::Aimbot::EVA8HipfireSmooth;
    AimAssist->EVA8ADSSmooth = Config::Aimbot::EVA8ADSSmooth;

    AimAssist->PeacekeeperClosestHitbox = Config::Aimbot::PeacekeeperClosestHitbox;
    AimAssist->PeacekeeperHitbox = Config::Aimbot::PeacekeeperHitbox;
    AimAssist->PeacekeeperSpeed = Config::Aimbot::PeacekeeperSpeed;
    AimAssist->PeacekeeperHipfireSmooth = Config::Aimbot::PeacekeeperHipfireSmooth;
    AimAssist->PeacekeeperADSSmooth = Config::Aimbot::PeacekeeperADSSmooth;

    AimAssist->MastiffClosestHitbox = Config::Aimbot::MastiffClosestHitbox;
    AimAssist->MastiffHitbox = Config::Aimbot::MastiffHitbox;
    AimAssist->MastiffSpeed = Config::Aimbot::MastiffSpeed;
    AimAssist->MastiffHipfireSmooth = Config::Aimbot::MastiffHipfireSmooth;
    AimAssist->MastiffADSSmooth = Config::Aimbot::MastiffADSSmooth;

    AimAssist->LongbowClosestHitbox = Config::Aimbot::LongbowClosestHitbox;
    AimAssist->LongbowHitbox = Config::Aimbot::LongbowHitbox;
    AimAssist->LongbowSpeed = Config::Aimbot::LongbowSpeed;
    AimAssist->LongbowHipfireSmooth = Config::Aimbot::LongbowHipfireSmooth;
    AimAssist->LongbowADSSmooth = Config::Aimbot::LongbowADSSmooth;
 
    AimAssist->ChargeRifleClosestHitbox = Config::Aimbot::ChargeRifleClosestHitbox;
    AimAssist->ChargeRifleHitbox = Config::Aimbot::ChargeRifleHitbox;
    AimAssist->ChargeRifleSpeed = Config::Aimbot::ChargeRifleSpeed;
    AimAssist->ChargeRifleHipfireSmooth = Config::Aimbot::ChargeRifleHipfireSmooth;
    AimAssist->ChargeRifleADSSmooth = Config::Aimbot::ChargeRifleADSSmooth;

    AimAssist->SentinelClosestHitbox = Config::Aimbot::SentinelClosestHitbox;
    AimAssist->SentinelHitbox = Config::Aimbot::SentinelHitbox;
    AimAssist->SentinelSpeed = Config::Aimbot::SentinelSpeed;
    AimAssist->SentinelHipfireSmooth = Config::Aimbot::SentinelHipfireSmooth;
    AimAssist->SentinelADSSmooth = Config::Aimbot::SentinelADSSmooth;

    AimAssist->WingmanClosestHitbox = Config::Aimbot::WingmanClosestHitbox;
    AimAssist->WingmanHitbox = Config::Aimbot::WingmanHitbox;
    AimAssist->WingmanSpeed = Config::Aimbot::WingmanSpeed;
    AimAssist->WingmanHipfireSmooth = Config::Aimbot::WingmanHipfireSmooth;
    AimAssist->WingmanADSSmooth = Config::Aimbot::WingmanADSSmooth;

    AimAssist->ProwlerClosestHitbox = Config::Aimbot::ProwlerClosestHitbox;
    AimAssist->ProwlerHitbox = Config::Aimbot::ProwlerHitbox;
    AimAssist->ProwlerSpeed = Config::Aimbot::ProwlerSpeed;
    AimAssist->ProwlerHipfireSmooth = Config::Aimbot::ProwlerHipfireSmooth;
    AimAssist->ProwlerADSSmooth = Config::Aimbot::ProwlerADSSmooth;

    AimAssist->BocekClosestHitbox = Config::Aimbot::BocekClosestHitbox;
    AimAssist->BocekHitbox = Config::Aimbot::BocekHitbox;
    AimAssist->BocekSpeed = Config::Aimbot::BocekSpeed;
    AimAssist->BocekHipfireSmooth = Config::Aimbot::BocekHipfireSmooth;
    AimAssist->BocekADSSmooth = Config::Aimbot::BocekADSSmooth;

    AimAssist->KraberClosestHitbox = Config::Aimbot::KraberClosestHitbox;
    AimAssist->KraberHitbox = Config::Aimbot::KraberHitbox;
    AimAssist->KraberSpeed = Config::Aimbot::KraberSpeed;
    AimAssist->KraberHipfireSmooth = Config::Aimbot::KraberHipfireSmooth;
    AimAssist->KraberADSSmooth = Config::Aimbot::KraberADSSmooth;

    AimAssist->ThrowingKnifeClosestHitbox = Config::Aimbot::ThrowingKnifeClosestHitbox;
    AimAssist->ThrowingKnifeHitbox = Config::Aimbot::ThrowingKnifeHitbox;
    AimAssist->ThrowingKnifeSpeed = Config::Aimbot::ThrowingKnifeSpeed;
    AimAssist->ThrowingKnifeHipfireSmooth = Config::Aimbot::ThrowingKnifeHipfireSmooth;
    AimAssist->ThrowingKnifeADSSmooth = Config::Aimbot::ThrowingKnifeADSSmooth;
    
    //Aimbot Mode 1 - Grinder
    AimAssist->P2020HipfireSmooth1 = Config::Aimbot::P2020HipfireSmooth1;
    AimAssist->P2020ADSSmooth1 = Config::Aimbot::P2020ADSSmooth1;
    AimAssist->P2020ExtraSmooth1 = Config::Aimbot::P2020ExtraSmooth1;
    AimAssist->P2020Deadzone = Config::Aimbot::P2020Deadzone;
    AimAssist->P2020FOV1 = Config::Aimbot::P2020FOV1;
    AimAssist->P2020MinDistance1 = Config::Aimbot::P2020MinDistance1;
    AimAssist->P2020MaxDistance1 = Config::Aimbot::P2020MaxDistance1;
    AimAssist->RE45HipfireSmooth1 = Config::Aimbot::RE45HipfireSmooth1;
    AimAssist->RE45ADSSmooth1 = Config::Aimbot::RE45ADSSmooth1;
    AimAssist->RE45ExtraSmooth1 = Config::Aimbot::RE45ExtraSmooth1;
    AimAssist->RE45Deadzone = Config::Aimbot::RE45Deadzone;
    AimAssist->RE45FOV1 = Config::Aimbot::RE45FOV1;
    AimAssist->RE45MinDistance1 = Config::Aimbot::RE45MinDistance1;
    AimAssist->RE45MaxDistance1 = Config::Aimbot::RE45MaxDistance1;
    AimAssist->AlternatorHipfireSmooth1 = Config::Aimbot::AlternatorHipfireSmooth1;
    AimAssist->AlternatorADSSmooth1 = Config::Aimbot::AlternatorADSSmooth1;
    AimAssist->AlternatorExtraSmooth1 = Config::Aimbot::AlternatorExtraSmooth1;
    AimAssist->AlternatorDeadzone = Config::Aimbot::AlternatorDeadzone;
    AimAssist->AlternatorFOV1 = Config::Aimbot::AlternatorFOV1;
    AimAssist->AlternatorMinDistance1 = Config::Aimbot::AlternatorMinDistance1;
    AimAssist->AlternatorMaxDistance1 = Config::Aimbot::AlternatorMaxDistance1;
    AimAssist->R99HipfireSmooth1 = Config::Aimbot::R99HipfireSmooth1;
    AimAssist->R99ADSSmooth1 = Config::Aimbot::R99ADSSmooth1;
    AimAssist->R99ExtraSmooth1 = Config::Aimbot::R99ExtraSmooth1;
    AimAssist->R99Deadzone = Config::Aimbot::R99Deadzone;
    AimAssist->R99FOV1 = Config::Aimbot::R99FOV1;
    AimAssist->R99MinDistance1 = Config::Aimbot::R99MinDistance1;
    AimAssist->R99MaxDistance1 = Config::Aimbot::R99MaxDistance1;
    AimAssist->R301HipfireSmooth1 = Config::Aimbot::R301HipfireSmooth1;
    AimAssist->R301ADSSmooth1 = Config::Aimbot::R301ADSSmooth1;
    AimAssist->R301ExtraSmooth1 = Config::Aimbot::R301ExtraSmooth1;
    AimAssist->R301Deadzone = Config::Aimbot::R301Deadzone;
    AimAssist->R301FOV1 = Config::Aimbot::R301FOV1;
    AimAssist->R301MinDistance1 = Config::Aimbot::R301MinDistance1;
    AimAssist->R301MaxDistance1 = Config::Aimbot::R301MaxDistance1;
    AimAssist->SpitfireHipfireSmooth1 = Config::Aimbot::SpitfireHipfireSmooth1;
    AimAssist->SpitfireADSSmooth1 = Config::Aimbot::SpitfireADSSmooth1;
    AimAssist->SpitfireExtraSmooth1 = Config::Aimbot::SpitfireExtraSmooth1;
    AimAssist->SpitfireDeadzone = Config::Aimbot::SpitfireDeadzone;
    AimAssist->SpitfireFOV1 = Config::Aimbot::SpitfireFOV1;
    AimAssist->SpitfireMinDistance1 = Config::Aimbot::SpitfireMinDistance1;
    AimAssist->SpitfireMaxDistance1 = Config::Aimbot::SpitfireMaxDistance1;
    AimAssist->G7HipfireSmooth1 = Config::Aimbot::G7HipfireSmooth1;
    AimAssist->G7ADSSmooth1 = Config::Aimbot::G7ADSSmooth1;
    AimAssist->G7ExtraSmooth1 = Config::Aimbot::G7ExtraSmooth1;
    AimAssist->G7Deadzone = Config::Aimbot::G7Deadzone;
    AimAssist->G7FOV1 = Config::Aimbot::G7FOV1;
    AimAssist->G7MinDistance1 = Config::Aimbot::G7MinDistance1;
    AimAssist->G7MaxDistance1 = Config::Aimbot::G7MaxDistance1;
    AimAssist->FlatlineHipfireSmooth1 = Config::Aimbot::FlatlineHipfireSmooth1;
    AimAssist->FlatlineADSSmooth1 = Config::Aimbot::FlatlineADSSmooth1;
    AimAssist->FlatlineExtraSmooth1 = Config::Aimbot::FlatlineExtraSmooth1;
    AimAssist->FlatlineDeadzone = Config::Aimbot::FlatlineDeadzone;
    AimAssist->FlatlineFOV1 = Config::Aimbot::FlatlineFOV1;
    AimAssist->FlatlineMinDistance1 = Config::Aimbot::FlatlineMinDistance1;
    AimAssist->FlatlineMaxDistance1 = Config::Aimbot::FlatlineMaxDistance1;
    AimAssist->HemlockHipfireSmooth1 = Config::Aimbot::HemlockHipfireSmooth1;
    AimAssist->HemlockADSSmooth1 = Config::Aimbot::HemlockADSSmooth1;
    AimAssist->HemlockExtraSmooth1 = Config::Aimbot::HemlockExtraSmooth1;
    AimAssist->HemlockDeadzone = Config::Aimbot::HemlockDeadzone;
    AimAssist->HemlockFOV1 = Config::Aimbot::HemlockFOV1;
    AimAssist->HemlockMinDistance1 = Config::Aimbot::HemlockMinDistance1;
    AimAssist->HemlockMaxDistance1 = Config::Aimbot::HemlockMaxDistance1;
    AimAssist->RepeaterHipfireSmooth1 = Config::Aimbot::RepeaterHipfireSmooth1;
    AimAssist->RepeaterADSSmooth1 = Config::Aimbot::RepeaterADSSmooth1;
    AimAssist->RepeaterExtraSmooth1 = Config::Aimbot::RepeaterExtraSmooth1;
    AimAssist->RepeaterDeadzone = Config::Aimbot::RepeaterDeadzone;
    AimAssist->RepeaterFOV1 = Config::Aimbot::RepeaterFOV1;
    AimAssist->RepeaterMinDistance1 = Config::Aimbot::RepeaterMinDistance1;
    AimAssist->RepeaterMaxDistance1 = Config::Aimbot::RepeaterMaxDistance1;
    AimAssist->RampageHipfireSmooth1 = Config::Aimbot::RampageHipfireSmooth1;
    AimAssist->RampageADSSmooth1 = Config::Aimbot::RampageADSSmooth1;
    AimAssist->RampageExtraSmooth1 = Config::Aimbot::RampageExtraSmooth1;
    AimAssist->RampageDeadzone = Config::Aimbot::RampageDeadzone;
    AimAssist->RampageFOV1 = Config::Aimbot::RampageFOV1;
    AimAssist->RampageMinDistance1 = Config::Aimbot::RampageMinDistance1;
    AimAssist->RampageMaxDistance1 = Config::Aimbot::RampageMaxDistance1;
    AimAssist->CARSMGHipfireSmooth1 = Config::Aimbot::CARSMGHipfireSmooth1;
    AimAssist->CARSMGADSSmooth1 = Config::Aimbot::CARSMGADSSmooth1;
    AimAssist->CARSMGExtraSmooth1 = Config::Aimbot::CARSMGExtraSmooth1;
    AimAssist->CARSMGDeadzone = Config::Aimbot::CARSMGDeadzone;
    AimAssist->CARSMGFOV1 = Config::Aimbot::CARSMGFOV1;
    AimAssist->CARSMGMinDistance1 = Config::Aimbot::CARSMGMinDistance1;
    AimAssist->CARSMGMaxDistance1 = Config::Aimbot::CARSMGMaxDistance1;
    AimAssist->HavocHipfireSmooth1 = Config::Aimbot::HavocHipfireSmooth1;
    AimAssist->HavocADSSmooth1 = Config::Aimbot::HavocADSSmooth1;
    AimAssist->HavocExtraSmooth1 = Config::Aimbot::HavocExtraSmooth1;
    AimAssist->HavocDeadzone = Config::Aimbot::HavocDeadzone;
    AimAssist->HavocFOV1 = Config::Aimbot::HavocFOV1;
    AimAssist->HavocMinDistance1 = Config::Aimbot::HavocMinDistance1;
    AimAssist->HavocMaxDistance1 = Config::Aimbot::HavocMaxDistance1;
    AimAssist->DevotionHipfireSmooth1 = Config::Aimbot::DevotionHipfireSmooth1;
    AimAssist->DevotionADSSmooth1 = Config::Aimbot::DevotionADSSmooth1;
    AimAssist->DevotionExtraSmooth1 = Config::Aimbot::DevotionExtraSmooth1;
    AimAssist->DevotionDeadzone = Config::Aimbot::DevotionDeadzone;
    AimAssist->DevotionFOV1 = Config::Aimbot::DevotionFOV1;
    AimAssist->DevotionMinDistance1 = Config::Aimbot::DevotionMinDistance1;
    AimAssist->DevotionMaxDistance1 = Config::Aimbot::DevotionMaxDistance1;
    AimAssist->LSTARHipfireSmooth1 = Config::Aimbot::LSTARHipfireSmooth1;
    AimAssist->LSTARADSSmooth1 = Config::Aimbot::LSTARADSSmooth1;
    AimAssist->LSTARExtraSmooth1 = Config::Aimbot::LSTARExtraSmooth1;
    AimAssist->LSTARDeadzone = Config::Aimbot::LSTARDeadzone;
    AimAssist->LSTARFOV1 = Config::Aimbot::LSTARFOV1;
    AimAssist->LSTARMinDistance1 = Config::Aimbot::LSTARMinDistance1;
    AimAssist->LSTARMaxDistance1 = Config::Aimbot::LSTARMaxDistance1;
    AimAssist->TripleTakeHipfireSmooth1 = Config::Aimbot::TripleTakeHipfireSmooth1;
    AimAssist->TripleTakeADSSmooth1 = Config::Aimbot::TripleTakeADSSmooth1;
    AimAssist->TripleTakeExtraSmooth1 = Config::Aimbot::TripleTakeExtraSmooth1;
    AimAssist->TripleTakeDeadzone = Config::Aimbot::TripleTakeDeadzone;
    AimAssist->TripleTakeFOV1 = Config::Aimbot::TripleTakeFOV1;
    AimAssist->TripleTakeMinDistance1 = Config::Aimbot::TripleTakeMinDistance1;
    AimAssist->TripleTakeMaxDistance1 = Config::Aimbot::TripleTakeMaxDistance1;
    AimAssist->VoltHipfireSmooth1 = Config::Aimbot::VoltHipfireSmooth1;
    AimAssist->VoltADSSmooth1 = Config::Aimbot::VoltADSSmooth1;
    AimAssist->VoltExtraSmooth1 = Config::Aimbot::VoltExtraSmooth1;
    AimAssist->VoltDeadzone = Config::Aimbot::VoltDeadzone;
    AimAssist->VoltFOV1 = Config::Aimbot::VoltFOV1;
    AimAssist->VoltMinDistance1 = Config::Aimbot::VoltMinDistance1;
    AimAssist->VoltMaxDistance1 = Config::Aimbot::VoltMaxDistance1;
    AimAssist->NemesisHipfireSmooth1 = Config::Aimbot::NemesisHipfireSmooth1;
    AimAssist->NemesisADSSmooth1 = Config::Aimbot::NemesisADSSmooth1;
    AimAssist->NemesisExtraSmooth1 = Config::Aimbot::NemesisExtraSmooth1;
    AimAssist->NemesisDeadzone = Config::Aimbot::NemesisDeadzone;
    AimAssist->NemesisFOV1 = Config::Aimbot::NemesisFOV1;
    AimAssist->NemesisMinDistance1 = Config::Aimbot::NemesisMinDistance1;
    AimAssist->NemesisMaxDistance1 = Config::Aimbot::NemesisMaxDistance1;
    AimAssist->MozambiqueHipfireSmooth1 = Config::Aimbot::MozambiqueHipfireSmooth1;
    AimAssist->MozambiqueADSSmooth1 = Config::Aimbot::MozambiqueADSSmooth1;
    AimAssist->MozambiqueExtraSmooth1 = Config::Aimbot::MozambiqueExtraSmooth1;
    AimAssist->MozambiqueDeadzone = Config::Aimbot::MozambiqueDeadzone;
    AimAssist->MozambiqueFOV1 = Config::Aimbot::MozambiqueFOV1;
    AimAssist->MozambiqueMinDistance1 = Config::Aimbot::MozambiqueMinDistance1;
    AimAssist->MozambiqueMaxDistance1 = Config::Aimbot::MozambiqueMaxDistance1;
    AimAssist->EVA8HipfireSmooth1 = Config::Aimbot::EVA8HipfireSmooth1;
    AimAssist->EVA8ADSSmooth1 = Config::Aimbot::EVA8ADSSmooth1;
    AimAssist->EVA8ExtraSmooth1 = Config::Aimbot::EVA8ExtraSmooth1;
    AimAssist->EVA8Deadzone = Config::Aimbot::EVA8Deadzone;
    AimAssist->EVA8FOV1 = Config::Aimbot::EVA8FOV1;
    AimAssist->EVA8MinDistance1 = Config::Aimbot::EVA8MinDistance1;
    AimAssist->EVA8MaxDistance1 = Config::Aimbot::EVA8MaxDistance1;
    AimAssist->PeacekeeperHipfireSmooth1 = Config::Aimbot::PeacekeeperHipfireSmooth1;
    AimAssist->PeacekeeperADSSmooth1 = Config::Aimbot::PeacekeeperADSSmooth1;
    AimAssist->PeacekeeperExtraSmooth1 = Config::Aimbot::PeacekeeperExtraSmooth1;
    AimAssist->PeacekeeperDeadzone = Config::Aimbot::PeacekeeperDeadzone;
    AimAssist->PeacekeeperFOV1 = Config::Aimbot::PeacekeeperFOV1;
    AimAssist->PeacekeeperMinDistance1 = Config::Aimbot::PeacekeeperMinDistance1;
    AimAssist->PeacekeeperMaxDistance1 = Config::Aimbot::PeacekeeperMaxDistance1;
    AimAssist->MastiffHipfireSmooth1 = Config::Aimbot::MastiffHipfireSmooth1;
    AimAssist->MastiffADSSmooth1 = Config::Aimbot::MastiffADSSmooth1;
    AimAssist->MastiffExtraSmooth1 = Config::Aimbot::MastiffExtraSmooth1;
    AimAssist->MastiffDeadzone = Config::Aimbot::MastiffDeadzone;
    AimAssist->MastiffFOV1 = Config::Aimbot::MastiffFOV1;
    AimAssist->MastiffMinDistance1 = Config::Aimbot::MastiffMinDistance1;
    AimAssist->MastiffMaxDistance1 = Config::Aimbot::MastiffMaxDistance1;
    AimAssist->LongbowHipfireSmooth1 = Config::Aimbot::LongbowHipfireSmooth1;
    AimAssist->LongbowADSSmooth1 = Config::Aimbot::LongbowADSSmooth1;
    AimAssist->LongbowExtraSmooth1 = Config::Aimbot::LongbowExtraSmooth1;
    AimAssist->LongbowDeadzone = Config::Aimbot::LongbowDeadzone;
    AimAssist->LongbowFOV1 = Config::Aimbot::LongbowFOV1;
    AimAssist->LongbowMinDistance1 = Config::Aimbot::LongbowMinDistance1;
    AimAssist->LongbowMaxDistance1 = Config::Aimbot::LongbowMaxDistance1;
    AimAssist->ChargeRifleHipfireSmooth1 = Config::Aimbot::ChargeRifleHipfireSmooth1;
    AimAssist->ChargeRifleADSSmooth1 = Config::Aimbot::ChargeRifleADSSmooth1;
    AimAssist->ChargeRifleExtraSmooth1 = Config::Aimbot::ChargeRifleExtraSmooth1;
    AimAssist->ChargeRifleDeadzone = Config::Aimbot::ChargeRifleDeadzone;
    AimAssist->ChargeRifleFOV1 = Config::Aimbot::ChargeRifleFOV1;
    AimAssist->ChargeRifleMinDistance1 = Config::Aimbot::ChargeRifleMinDistance1;
    AimAssist->ChargeRifleMaxDistance1 = Config::Aimbot::ChargeRifleMaxDistance1;
    AimAssist->SentinelHipfireSmooth1 = Config::Aimbot::SentinelHipfireSmooth1;
    AimAssist->SentinelADSSmooth1 = Config::Aimbot::SentinelADSSmooth1;
    AimAssist->SentinelExtraSmooth1 = Config::Aimbot::SentinelExtraSmooth1;
    AimAssist->SentinelDeadzone = Config::Aimbot::SentinelDeadzone;
    AimAssist->SentinelFOV1 = Config::Aimbot::SentinelFOV1;
    AimAssist->SentinelMinDistance1 = Config::Aimbot::SentinelMinDistance1;
    AimAssist->SentinelMaxDistance1 = Config::Aimbot::SentinelMaxDistance1;
    AimAssist->WingmanHipfireSmooth1 = Config::Aimbot::WingmanHipfireSmooth1;
    AimAssist->WingmanADSSmooth1 = Config::Aimbot::WingmanADSSmooth1;
    AimAssist->WingmanExtraSmooth1 = Config::Aimbot::WingmanExtraSmooth1;
    AimAssist->WingmanDeadzone = Config::Aimbot::WingmanDeadzone;
    AimAssist->WingmanFOV1 = Config::Aimbot::WingmanFOV1;
    AimAssist->WingmanMinDistance1 = Config::Aimbot::WingmanMinDistance1;
    AimAssist->WingmanMaxDistance1 = Config::Aimbot::WingmanMaxDistance1;
    AimAssist->ProwlerHipfireSmooth1 = Config::Aimbot::ProwlerHipfireSmooth1;
    AimAssist->ProwlerADSSmooth1 = Config::Aimbot::ProwlerADSSmooth1;
    AimAssist->ProwlerExtraSmooth1 = Config::Aimbot::ProwlerExtraSmooth1;
    AimAssist->ProwlerDeadzone = Config::Aimbot::ProwlerDeadzone;
    AimAssist->ProwlerFOV1 = Config::Aimbot::ProwlerFOV1;
    AimAssist->ProwlerMinDistance1 = Config::Aimbot::ProwlerMinDistance1;
    AimAssist->ProwlerMaxDistance1 = Config::Aimbot::ProwlerMaxDistance1;
    AimAssist->BocekHipfireSmooth1 = Config::Aimbot::BocekHipfireSmooth1;
    AimAssist->BocekADSSmooth1 = Config::Aimbot::BocekADSSmooth1;
    AimAssist->BocekExtraSmooth1 = Config::Aimbot::BocekExtraSmooth1;
    AimAssist->BocekDeadzone = Config::Aimbot::BocekDeadzone;
    AimAssist->BocekFOV1 = Config::Aimbot::BocekFOV1;
    AimAssist->BocekMinDistance1 = Config::Aimbot::BocekMinDistance1;
    AimAssist->BocekMaxDistance1 = Config::Aimbot::BocekMaxDistance1;
    AimAssist->KraberHipfireSmooth1 = Config::Aimbot::KraberHipfireSmooth1;
    AimAssist->KraberADSSmooth1 = Config::Aimbot::KraberADSSmooth1;
    AimAssist->KraberExtraSmooth1 = Config::Aimbot::KraberExtraSmooth1;
    AimAssist->KraberDeadzone = Config::Aimbot::KraberDeadzone;
    AimAssist->KraberFOV1 = Config::Aimbot::KraberFOV1;
    AimAssist->KraberMinDistance1 = Config::Aimbot::KraberMinDistance1;
    AimAssist->KraberMaxDistance1 = Config::Aimbot::KraberMaxDistance1;
    AimAssist->ThrowingKnifeHipfireSmooth1 = Config::Aimbot::ThrowingKnifeHipfireSmooth1;
    AimAssist->ThrowingKnifeADSSmooth1 = Config::Aimbot::ThrowingKnifeADSSmooth1;
    AimAssist->ThrowingKnifeExtraSmooth1 = Config::Aimbot::ThrowingKnifeExtraSmooth1;
    AimAssist->ThrowingKnifeDeadzone = Config::Aimbot::ThrowingKnifeDeadzone;
    AimAssist->ThrowingKnifeFOV1 = Config::Aimbot::ThrowingKnifeFOV1;
    AimAssist->ThrowingKnifeMinDistance1 = Config::Aimbot::ThrowingKnifeMinDistance1;
    AimAssist->ThrowingKnifeMaxDistance1 = Config::Aimbot::ThrowingKnifeMaxDistance1;
    
    //RCS //
    //RCSEnabled = Config::RCS::RCSEnabled;
    //Recoil->OnADS = Config::RCS::OnADS;
    //PitchP = Config::RCS::PitchPower;
    //YawP = Config::RCS::YawPower;
    ////Weapons
    //Recoil->P2020 = Config::RCS::P2020;
    //Recoil->RE45 = Config::RCS::RE45;
    //Recoil->Alternator = Config::RCS::Alternator;
    //Recoil->R99 = Config::RCS::R99;
    //Recoil->R301 = Config::RCS::R301;
    //Recoil->Spitfire = Config::RCS::Spitfire;
    //Recoil->G7 = Config::RCS::G7;
    //Recoil->Flatline = Config::RCS::Flatline;
    //Recoil->Hemlock = Config::RCS::Hemlock;
    //Recoil->Repeater = Config::RCS::Repeater;
    //Recoil->Rampage = Config::RCS::Rampage;
    //Recoil->CARSMG = Config::RCS::CARSMG;
    //Recoil->Havoc = Config::RCS::Havoc;
    //Recoil->Devotion = Config::RCS::Devotion;
    //Recoil->LSTAR = Config::RCS::LSTAR;
    //Recoil->TripleTake = Config::RCS::TripleTake;
    //Recoil->Volt = Config::RCS::Volt;
    //Recoil->Nemesis = Config::RCS::Nemesis;
    //Recoil->Mozambique = Config::RCS::Mozambique;
    //Recoil->EVA8 = Config::RCS::EVA8;
    //Recoil->Peacekeeper = Config::RCS::Peacekeeper;
    //Recoil->Mastiff = Config::RCS::Mastiff;
    //Recoil->Longbow = Config::RCS::Longbow;
    //Recoil->ChargeRifle = Config::RCS::ChargeRifle;
    //Recoil->Sentinel = Config::RCS::Sentinel;
    //Recoil->Wingman = Config::RCS::Wingman;
    //Recoil->Prowler = Config::RCS::Prowler;
    //Recoil->Kraber = Config::RCS::Kraber;
    //
    ////---------------Advanced---------------//
    //Recoil->AdvancedRCS = Config::RCS::AdvancedRCS;
    ////Weapons
    //Recoil->P2020Pitch = Config::RCS::P2020Pitch;
    //Recoil->P2020Yaw = Config::RCS::P2020Yaw;
    //Recoil->RE45Pitch = Config::RCS::RE45Pitch;
    //Recoil->RE45Yaw = Config::RCS::RE45Yaw;
    //Recoil->AlternatorPitch = Config::RCS::AlternatorPitch;
    //Recoil->AlternatorYaw = Config::RCS::AlternatorYaw;
    //Recoil->R99Pitch = Config::RCS::R99Pitch;
    //Recoil->R99Yaw = Config::RCS::R99Yaw;
    //Recoil->R301Pitch = Config::RCS::R301Pitch;
    //Recoil->R301Yaw = Config::RCS::R301Yaw;
    //Recoil->SpitfirePitch = Config::RCS::SpitfirePitch;
    //Recoil->SpitfireYaw = Config::RCS::SpitfireYaw;
    //Recoil->G7Pitch = Config::RCS::G7Pitch;
    //Recoil->G7Yaw = Config::RCS::G7Yaw;
    //Recoil->FlatlinePitch = Config::RCS::FlatlinePitch;
    //Recoil->FlatlineYaw = Config::RCS::FlatlineYaw;
    //Recoil->HemlockPitch = Config::RCS::HemlockPitch;
    //Recoil->HemlockYaw = Config::RCS::HemlockYaw;
    //Recoil->RepeaterPitch = Config::RCS::RepeaterPitch;
    //Recoil->RepeaterYaw = Config::RCS::RepeaterYaw;
    //Recoil->RampagePitch = Config::RCS::RampagePitch;
    //Recoil->RampageYaw = Config::RCS::RampageYaw;
    //Recoil->CARSMGPitch = Config::RCS::CARSMGPitch;
    //Recoil->CARSMGYaw = Config::RCS::CARSMGYaw;
    //Recoil->HavocPitch = Config::RCS::HavocPitch;
    //Recoil->HavocYaw = Config::RCS::HavocYaw;
    //Recoil->DevotionPitch = Config::RCS::DevotionPitch;
    //Recoil->DevotionYaw = Config::RCS::DevotionYaw;
    //Recoil->LSTARPitch = Config::RCS::LSTARPitch;
    //Recoil->LSTARYaw = Config::RCS::LSTARYaw;
    //Recoil->TripleTakePitch = Config::RCS::TripleTakePitch;
    //Recoil->TripleTakeYaw = Config::RCS::TripleTakeYaw;
    //Recoil->VoltPitch = Config::RCS::VoltPitch;
    //Recoil->VoltYaw = Config::RCS::VoltYaw;
    //Recoil->NemesisPitch = Config::RCS::NemesisPitch;
    //Recoil->NemesisYaw = Config::RCS::NemesisYaw;
    //Recoil->MozambiquePitch = Config::RCS::MozambiquePitch;
    //Recoil->MozambiqueYaw = Config::RCS::MozambiqueYaw;
    //Recoil->EVA8Pitch = Config::RCS::EVA8Pitch;
    //Recoil->EVA8Yaw = Config::RCS::EVA8Yaw;
    //Recoil->PeacekeeperPitch = Config::RCS::PeacekeeperPitch;
    //Recoil->PeacekeeperYaw = Config::RCS::PeacekeeperYaw;
    //Recoil->MastiffPitch = Config::RCS::MastiffPitch;
    //Recoil->MastiffYaw = Config::RCS::MastiffYaw;
    //Recoil->LongbowPitch = Config::RCS::LongbowPitch;
    //Recoil->LongbowYaw = Config::RCS::LongbowYaw;
    //Recoil->ChargeRiflePitch = Config::RCS::ChargeRiflePitch;
    //Recoil->ChargeRifleYaw = Config::RCS::ChargeRifleYaw;
    //Recoil->SentinelPitch = Config::RCS::SentinelPitch;
    //Recoil->SentinelYaw = Config::RCS::SentinelYaw;
    //Recoil->WingmanPitch = Config::RCS::WingmanPitch;
    //Recoil->WingmanYaw = Config::RCS::WingmanYaw;
    //Recoil->ProwlerPitch = Config::RCS::ProwlerPitch;
    //Recoil->ProwlerYaw = Config::RCS::ProwlerYaw;
    //Recoil->KraberPitch = Config::RCS::KraberPitch;
    //Recoil->KraberYaw = Config::RCS::KraberYaw;
    
    // Glow //
    GlowESP->GlowEnabled = Config::Glow::GlowEnabled;
    GlowESP->ItemGlow = Config::Glow::ItemGlow;
    GlowESP->GlowMaxDistance = Config::Glow::GlowMaxDistance;
    GlowESP->NewGlow = Config::Glow::NewGlow;
    GlowESP->GlowColorMode = Config::Glow::GlowColorMode;
    GlowESP->GlowColorShieldMode = Config::Glow::GlowColorShieldMode;
    GlowESP->GlowRadius = Config::Glow::GlowRadius;
    GlowESP->InsideFunction = Config::Glow::InsideFunction;
    GlowESP->OutlineFunction = Config::Glow::OutlineFunction;
    GlowESP->BodyStyle = Config::Glow::BodyStyle;
    GlowESP->OutlineStyle = Config::Glow::OutlineStyle;
    GlowESP->InvisibleGlowColor[0] = Config::Glow::InvisibleGlowColorR;
    GlowESP->InvisibleGlowColor[1] = Config::Glow::InvisibleGlowColorG;
    GlowESP->InvisibleGlowColor[2] = Config::Glow::InvisibleGlowColorB;
    GlowESP->VisibleGlowColor[0] = Config::Glow::VisibleGlowColorR;
    GlowESP->VisibleGlowColor[1] = Config::Glow::VisibleGlowColorG;
    GlowESP->VisibleGlowColor[2] = Config::Glow::VisibleGlowColorB;
    GlowESP->LowGlowColor[0] = Config::Glow::LowGlowColorR;
    GlowESP->LowGlowColor[1] = Config::Glow::LowGlowColorG;
    GlowESP->LowGlowColor[2] = Config::Glow::LowGlowColorB;
    GlowESP->RedShieldColor[0] = Config::Glow::RedShieldColorR;
    GlowESP->RedShieldColor[1] = Config::Glow::RedShieldColorG;
    GlowESP->RedShieldColor[2] = Config::Glow::RedShieldColorB;
    GlowESP->PurpleShieldColor[0] = Config::Glow::PurpleShieldColorR;
    GlowESP->PurpleShieldColor[1] = Config::Glow::PurpleShieldColorG;
    GlowESP->PurpleShieldColor[2] = Config::Glow::PurpleShieldColorB;
    GlowESP->BlueShieldColor[0] = Config::Glow::BlueShieldColorR;
    GlowESP->BlueShieldColor[1] = Config::Glow::BlueShieldColorG;
    GlowESP->BlueShieldColor[2] = Config::Glow::BlueShieldColorB;
    GlowESP->GreyShieldColor[0] = Config::Glow::GreyShieldColorR;
    GlowESP->GreyShieldColor[1] = Config::Glow::GreyShieldColorG;
    GlowESP->GreyShieldColor[2] = Config::Glow::GreyShieldColorB;
    
    // ESP //
    ESP->VisibilityCheck = Config::Sense::VisibilityCheck;
    ESP->DrawBoxes = Config::Sense::DrawBoxes;
    ESP->BoxType = Config::Sense::BoxType;
    ESP->BoxStyle = Config::Sense::BoxStyle;
    ESP->BoxThickness = Config::Sense::BoxThickness;
    ESP->Skeleton = Config::Sense::Skeleton;
    ESP->SkeletonThickness = Config::Sense::SkeletonThickness;
    ESP->HealthBar = Config::Sense::HealthBar;
    ESP->ShieldBar = Config::Sense::ShieldBar;
    ESP->BarMode = Config::Sense::BarMode;
    ESP->BarStyle = Config::Sense::BarStyle;
    Modules::Sense::BarColorMode = Config::Sense::BarColorMode;
    Modules::Sense::BarBackground = Config::Sense::BarBackground;
    ESP->BarThickness = Config::Sense::BarThickness;
    ESP->BarThickness2 = Config::Sense::BarThickness2;
    ESP->BarHeight = Config::Sense::BarHeight;
    ESP->BarWidth = Config::Sense::BarWidth;
    ESP->ESPMaxDistance = Config::Sense::ESPMaxDistance;
    ESP->ShowNear = Config::Sense::ShowNear;
    ESP->DrawSeer = Config::Sense::DrawSeer;
    ESP->DrawStatus = Config::Sense::DrawStatus;
    ESP->DrawWeapon = Config::Sense::DrawWeapon;
    ESP->WeaponColorType = Config::Sense::WeaponColorType;
    ESP->ShowLegend = Config::Sense::ShowLegend;
    ESP->ShowMaxStatusValues = Config::Sense::ShowMaxStatusValues;
    ESP->DrawDistance = Config::Sense::DrawDistance;
    ESP->DrawFOVCircle = Config::Sense::DrawFOVCircle;
    ESP->DrawFilledFOVCircle = Config::Sense::DrawFilledFOVCircle;
    ESP->FOVThickness = Config::Sense::FOVThickness;
    ESP->DrawNames = Config::Sense::DrawNames;
    ESP->TracerPosition = Config::Sense::TracerPos;
    ESP->TracerBone = Config::Sense::TracerBone;
    ESP->DrawTracers = Config::Sense::DrawTracers;
    ESP->TracerThickness = Config::Sense::TracerThickness;
    ESP->ShowSpectators = Config::Sense::ShowSpectators;
    ESP->DrawCrosshair = Config::Sense::DrawCrosshair;
    ESP->CrosshairSize = Config::Sense::CrosshairSize;
    ESP->CrosshairThickness = Config::Sense::CrosshairThickness;
    ESP->GameFOV = Config::Sense::GameFOV;
    ESP->ShowTeam = Config::Sense::ShowTeam;
    ESP->TeamNames = Config::Sense::TeamNames;

    //Radar
    MapRadar->MiniMap = Config::Radar::MiniMap;
    MapRadar->MiniMapRange = Config::Radar::MiniMapRange;
    MapRadar->MiniMapScaleX = Config::Radar::MiniMapScaleX;
    MapRadar->MiniMapScaleY = Config::Radar::MiniMapScaleY;
    MapRadar->MiniMapDotSize = Config::Radar::MiniMapDotSize;
    MapRadar->MiniMapGuides = Config::Radar::MiniMapGuides;
    MapRadar->BigMap = Config::Radar::BigMap;
    
    //Colors
    Modules::Colors::InvisibleBoxColor[0] = Config::Colors::InvisibleBoxColorR;
    Modules::Colors::InvisibleBoxColor[1] = Config::Colors::InvisibleBoxColorG;
    Modules::Colors::InvisibleBoxColor[2] = Config::Colors::InvisibleBoxColorB;
    Modules::Colors::InvisibleBoxColor[3] = Config::Colors::InvisibleBoxColorA;
    Modules::Colors::VisibleBoxColor[0] = Config::Colors::VisibleBoxColorR;
    Modules::Colors::VisibleBoxColor[1] = Config::Colors::VisibleBoxColorG;
    Modules::Colors::VisibleBoxColor[2] = Config::Colors::VisibleBoxColorB;
    Modules::Colors::VisibleBoxColor[3] = Config::Colors::VisibleBoxColorA;
    Modules::Colors::InvisibleFilledBoxColor[0] = Config::Colors::InvisibleFilledBoxColorR;
    Modules::Colors::InvisibleFilledBoxColor[1] = Config::Colors::InvisibleFilledBoxColorG;
    Modules::Colors::InvisibleFilledBoxColor[2] = Config::Colors::InvisibleFilledBoxColorB;
    Modules::Colors::InvisibleFilledBoxColor[3] = Config::Colors::InvisibleFilledBoxColorA;
    Modules::Colors::VisibleFilledBoxColor[0] = Config::Colors::VisibleFilledBoxColorR;
    Modules::Colors::VisibleFilledBoxColor[1] = Config::Colors::VisibleFilledBoxColorG;
    Modules::Colors::VisibleFilledBoxColor[2] = Config::Colors::VisibleFilledBoxColorB;
    Modules::Colors::VisibleFilledBoxColor[3] = Config::Colors::VisibleFilledBoxColorA;
    Modules::Colors::InvisibleTracerColor[0] = Config::Colors::InvisibleTracerColorR;
    Modules::Colors::InvisibleTracerColor[1] = Config::Colors::InvisibleTracerColorG;
    Modules::Colors::InvisibleTracerColor[2] = Config::Colors::InvisibleTracerColorB;
    Modules::Colors::InvisibleTracerColor[3] = Config::Colors::InvisibleTracerColorA;
    Modules::Colors::VisibleTracerColor[0] = Config::Colors::VisibleTracerColorR;
    Modules::Colors::VisibleTracerColor[1] = Config::Colors::VisibleTracerColorG;
    Modules::Colors::VisibleTracerColor[2] = Config::Colors::VisibleTracerColorB;
    Modules::Colors::VisibleTracerColor[3] = Config::Colors::VisibleTracerColorA;
    Modules::Colors::InvisibleSkeletonColor[0] = Config::Colors::InvisibleSkeletonColorR;
    Modules::Colors::InvisibleSkeletonColor[1] = Config::Colors::InvisibleSkeletonColorG;
    Modules::Colors::InvisibleSkeletonColor[2] = Config::Colors::InvisibleSkeletonColorB;
    Modules::Colors::InvisibleSkeletonColor[3] = Config::Colors::InvisibleSkeletonColorA;
    Modules::Colors::VisibleSkeletonColor[0] = Config::Colors::VisibleSkeletonColorR;
    Modules::Colors::VisibleSkeletonColor[1] = Config::Colors::VisibleSkeletonColorG;
    Modules::Colors::VisibleSkeletonColor[2] = Config::Colors::VisibleSkeletonColorB;
    Modules::Colors::VisibleSkeletonColor[3] = Config::Colors::VisibleSkeletonColorA;
    Modules::Colors::InvisibleNameColor[0] = Config::Colors::InvisibleNameColorR;
    Modules::Colors::InvisibleNameColor[1] = Config::Colors::InvisibleNameColorG;
    Modules::Colors::InvisibleNameColor[2] = Config::Colors::InvisibleNameColorB;
    Modules::Colors::InvisibleNameColor[3] = Config::Colors::InvisibleNameColorA;
    Modules::Colors::VisibleNameColor[0] = Config::Colors::VisibleNameColorR;
    Modules::Colors::VisibleNameColor[1] = Config::Colors::VisibleNameColorG;
    Modules::Colors::VisibleNameColor[2] = Config::Colors::VisibleNameColorB;
    Modules::Colors::VisibleNameColor[3] = Config::Colors::VisibleNameColorA;
    Modules::Colors::InvisibleDistanceColor[0] = Config::Colors::InvisibleDistanceColorR;
    Modules::Colors::InvisibleDistanceColor[1] = Config::Colors::InvisibleDistanceColorG;
    Modules::Colors::InvisibleDistanceColor[2] = Config::Colors::InvisibleDistanceColorB;
    Modules::Colors::InvisibleDistanceColor[3] = Config::Colors::InvisibleDistanceColorA;
    Modules::Colors::VisibleDistanceColor[0] = Config::Colors::VisibleDistanceColorR;
    Modules::Colors::VisibleDistanceColor[1] = Config::Colors::VisibleDistanceColorG;
    Modules::Colors::VisibleDistanceColor[2] = Config::Colors::VisibleDistanceColorB;
    Modules::Colors::VisibleDistanceColor[3] = Config::Colors::VisibleDistanceColorA;
    Modules::Colors::InvisibleLegendColor[0] = Config::Colors::InvisibleLegendColorR;
    Modules::Colors::InvisibleLegendColor[1] = Config::Colors::InvisibleLegendColorG;
    Modules::Colors::InvisibleLegendColor[2] = Config::Colors::InvisibleLegendColorB;
    Modules::Colors::InvisibleLegendColor[3] = Config::Colors::InvisibleLegendColorA;
    Modules::Colors::VisibleLegendColor[0] = Config::Colors::VisibleLegendColorR;
    Modules::Colors::VisibleLegendColor[1] = Config::Colors::VisibleLegendColorG;
    Modules::Colors::VisibleLegendColor[2] = Config::Colors::VisibleLegendColorB;
    Modules::Colors::VisibleLegendColor[3] = Config::Colors::VisibleLegendColorA;
    Modules::Colors::FOVColor[0] = Config::Colors::FOVColorR;
    Modules::Colors::FOVColor[1] = Config::Colors::FOVColorG;
    Modules::Colors::FOVColor[2] = Config::Colors::FOVColorB;
    Modules::Colors::FOVColor[3] = Config::Colors::FOVColorA;
    Modules::Colors::FilledFOVColor[0] = Config::Colors::FilledFOVColorR;
    Modules::Colors::FilledFOVColor[1] = Config::Colors::FilledFOVColorG;
    Modules::Colors::FilledFOVColor[2] = Config::Colors::FilledFOVColorB;
    Modules::Colors::FilledFOVColor[3] = Config::Colors::FilledFOVColorA;
    Modules::Colors::VisibleWeaponColor[0] = Config::Colors::VisibleWeaponColorR;
    Modules::Colors::VisibleWeaponColor[1] = Config::Colors::VisibleWeaponColorG;
    Modules::Colors::VisibleWeaponColor[2] = Config::Colors::VisibleWeaponColorB;
    Modules::Colors::VisibleWeaponColor[3] = Config::Colors::VisibleWeaponColorA;
    Modules::Colors::InvisibleWeaponColor[0] = Config::Colors::InvisibleWeaponColorR;
    Modules::Colors::InvisibleWeaponColor[1] = Config::Colors::InvisibleWeaponColorG;
    Modules::Colors::InvisibleWeaponColor[2] = Config::Colors::InvisibleWeaponColorB;
    Modules::Colors::InvisibleWeaponColor[3] = Config::Colors::InvisibleWeaponColorA;
    Modules::Colors::NearColor[0] = Config::Colors::NearColorR;
    Modules::Colors::NearColor[1] = Config::Colors::NearColorG;
    Modules::Colors::NearColor[2] = Config::Colors::NearColorB;
    Modules::Colors::NearColor[3] = Config::Colors::NearColorA;
    Modules::Colors::TeamColor[0] = Config::Colors::TeamColorR;
    Modules::Colors::TeamColor[1] = Config::Colors::TeamColorG;
    Modules::Colors::TeamColor[2] = Config::Colors::TeamColorB;
    Modules::Colors::TeamColor[3] = Config::Colors::TeamColorA;
    Modules::Colors::TeamNameColor[0] = Config::Colors::TeamNameColorR;
    Modules::Colors::TeamNameColor[1] = Config::Colors::TeamNameColorG;
    Modules::Colors::TeamNameColor[2] = Config::Colors::TeamNameColorB;
    Modules::Colors::TeamNameColor[3] = Config::Colors::TeamNameColorA;
    Modules::Colors::CrosshairColor[0] = Config::Colors::CrosshairColorR;
    Modules::Colors::CrosshairColor[1] = Config::Colors::CrosshairColorG;
    Modules::Colors::CrosshairColor[2] = Config::Colors::CrosshairColorB;
    Modules::Colors::CrosshairColor[3] = Config::Colors::CrosshairColorA;
    //WeaponESP Colors
    Modules::Colors::LightWeaponColor[0] = Config::Colors::LightWeaponColorR;
    Modules::Colors::LightWeaponColor[1] = Config::Colors::LightWeaponColorG;
    Modules::Colors::LightWeaponColor[2] = Config::Colors::LightWeaponColorB;
    Modules::Colors::LightWeaponColor[3] = Config::Colors::LightWeaponColorA;
    Modules::Colors::HeavyWeaponColor[0] = Config::Colors::HeavyWeaponColorR;
    Modules::Colors::HeavyWeaponColor[1] = Config::Colors::HeavyWeaponColorG;
    Modules::Colors::HeavyWeaponColor[2] = Config::Colors::HeavyWeaponColorB;
    Modules::Colors::HeavyWeaponColor[3] = Config::Colors::HeavyWeaponColorA;
    Modules::Colors::EnergyWeaponColor[0] = Config::Colors::EnergyWeaponColorR;
    Modules::Colors::EnergyWeaponColor[1] = Config::Colors::EnergyWeaponColorG;
    Modules::Colors::EnergyWeaponColor[2] = Config::Colors::EnergyWeaponColorB;
    Modules::Colors::EnergyWeaponColor[3] = Config::Colors::EnergyWeaponColorA;
    Modules::Colors::ShotgunWeaponColor[0] = Config::Colors::ShotgunWeaponColorR;
    Modules::Colors::ShotgunWeaponColor[1] = Config::Colors::ShotgunWeaponColorG;
    Modules::Colors::ShotgunWeaponColor[2] = Config::Colors::ShotgunWeaponColorB;
    Modules::Colors::ShotgunWeaponColor[3] = Config::Colors::ShotgunWeaponColorA;
    Modules::Colors::SniperWeaponColor[0] = Config::Colors::SniperWeaponColorR;
    Modules::Colors::SniperWeaponColor[1] = Config::Colors::SniperWeaponColorG;
    Modules::Colors::SniperWeaponColor[2] = Config::Colors::SniperWeaponColorB;
    Modules::Colors::SniperWeaponColor[3] = Config::Colors::SniperWeaponColorA;
    Modules::Colors::LegendaryWeaponColor[0] = Config::Colors::LegendaryWeaponColorR;
    Modules::Colors::LegendaryWeaponColor[1] = Config::Colors::LegendaryWeaponColorG;
    Modules::Colors::LegendaryWeaponColor[2] = Config::Colors::LegendaryWeaponColorB;
    Modules::Colors::LegendaryWeaponColor[3] = Config::Colors::LegendaryWeaponColorA;
    Modules::Colors::MeleeWeaponColor[0] = Config::Colors::MeleeWeaponColorR;
    Modules::Colors::MeleeWeaponColor[1] = Config::Colors::MeleeWeaponColorG;
    Modules::Colors::MeleeWeaponColor[2] = Config::Colors::MeleeWeaponColorB;
    Modules::Colors::MeleeWeaponColor[3] = Config::Colors::MeleeWeaponColorA;
    Modules::Colors::ThrowableWeaponColor[0] = Config::Colors::ThrowableWeaponColorR;
    Modules::Colors::ThrowableWeaponColor[1] = Config::Colors::ThrowableWeaponColorG;
    Modules::Colors::ThrowableWeaponColor[2] = Config::Colors::ThrowableWeaponColorB;
    Modules::Colors::ThrowableWeaponColor[3] = Config::Colors::ThrowableWeaponColorA;

    // Triggerbot //
    Trigger->TriggerbotEnabled = Config::Triggerbot::Enabled;
    Trigger->OnADS = Config::Triggerbot::OnADS;
    Trigger->HipfireShotguns = Config::Triggerbot::HipfireShotguns;
    Trigger->TriggerbotRange = Config::Triggerbot::Range;
    // Weapons //
    Trigger->P2020 = Config::Triggerbot::P2020;
    Trigger->RE45 = Config::Triggerbot::RE45;
    Trigger->Alternator = Config::Triggerbot::Alternator;
    Trigger->R99 = Config::Triggerbot::R99;
    Trigger->R301 = Config::Triggerbot::R301;
    Trigger->Spitfire = Config::Triggerbot::Spitfire;
    Trigger->G7 = Config::Triggerbot::G7;
    Trigger->Flatline = Config::Triggerbot::Flatline;
    Trigger->Hemlock = Config::Triggerbot::Hemlock;
    Trigger->Repeater = Config::Triggerbot::Repeater;
    Trigger->Rampage = Config::Triggerbot::Rampage;
    Trigger->CARSMG = Config::Triggerbot::CARSMG;
    Trigger->Havoc = Config::Triggerbot::Havoc;
    Trigger->Devotion = Config::Triggerbot::Devotion;
    Trigger->LSTAR = Config::Triggerbot::LSTAR;
    Trigger->TripleTake = Config::Triggerbot::TripleTake;
    Trigger->Volt = Config::Triggerbot::Volt;
    Trigger->Nemesis = Config::Triggerbot::Nemesis;
    Trigger->Mozambique = Config::Triggerbot::Mozambique;
    Trigger->EVA8 = Config::Triggerbot::EVA8;
    Trigger->Peacekeeper = Config::Triggerbot::Peacekeeper;
    Trigger->Mastiff = Config::Triggerbot::Mastiff;
    Trigger->Longbow = Config::Triggerbot::Longbow;
    Trigger->ChargeRifle = Config::Triggerbot::ChargeRifle;
    Trigger->Sentinel = Config::Triggerbot::Sentinel;
    Trigger->Wingman = Config::Triggerbot::Wingman;
    Trigger->Prowler = Config::Triggerbot::Prowler;
    Trigger->Bocek = Config::Triggerbot::Bocek;
    Trigger->Kraber = Config::Triggerbot::Kraber;
    Trigger->Knife = Config::Triggerbot::Knife;
    
    // Misc //
    MiscTab->SkinChanger = Config::Misc::SkinChanger;
    MiscTab->AutoGrapple = Config::Misc::AutoGrapple;
    MiscTab->SuperGlide = Config::Misc::SuperGlide;
    // Weapons //
    MiscTab->SkinP2020 = Config::Misc::SkinP2020;
    MiscTab->SkinRE45 = Config::Misc::SkinRE45;
    MiscTab->SkinALTERNATOR = Config::Misc::SkinALTERNATOR;
    MiscTab->SkinR99 = Config::Misc::SkinR99;
    MiscTab->SkinR301 = Config::Misc::SkinR301;
    MiscTab->SkinSPITFIRE = Config::Misc::SkinSPITFIRE;
    MiscTab->SkinG7 = Config::Misc::SkinG7;
    MiscTab->SkinFLATLINE = Config::Misc::SkinFLATLINE;
    MiscTab->SkinHEMLOCK = Config::Misc::SkinHEMLOCK;
    MiscTab->SkinREPEATER = Config::Misc::SkinREPEATER;
    MiscTab->SkinRAMPAGE = Config::Misc::SkinRAMPAGE;
    MiscTab->SkinCAR = Config::Misc::SkinCAR;
    MiscTab->SkinHAVOC = Config::Misc::SkinHAVOC;
    MiscTab->SkinDEVOTION = Config::Misc::SkinDEVOTION;
    MiscTab->SkinLSTAR = Config::Misc::SkinLSTAR;
    MiscTab->SkinTRIPLETAKE = Config::Misc::SkinTRIPLETAKE;
    MiscTab->SkinVOLT = Config::Misc::SkinVOLT;
    MiscTab->SkinNEMESIS = Config::Misc::SkinNEMESIS;
    MiscTab->SkinMOZAMBIQUE = Config::Misc::SkinMOZAMBIQUE;
    MiscTab->SkinEVA8 = Config::Misc::SkinEVA8;
    MiscTab->SkinPEACEKEEPER = Config::Misc::SkinPEACEKEEPER;
    MiscTab->SkinMASTIFF = Config::Misc::SkinMASTIFF;
    MiscTab->SkinLONGBOW = Config::Misc::SkinLONGBOW;
    MiscTab->SkinCHARGE_RIFLE = Config::Misc::SkinCHARGE_RIFLE;
    MiscTab->SkinSENTINEL = Config::Misc::SkinSENTINEL;
    MiscTab->SkinWINGMAN = Config::Misc::SkinWINGMAN;
    MiscTab->SkinPROWLER = Config::Misc::SkinPROWLER;
    MiscTab->SkinBOCEK = Config::Misc::SkinBOCEK;
    MiscTab->SkinKRABER = Config::Misc::SkinKRABER;
    
    // Home //
    //Modules::Home::MenuX = Config::Home::MenuX;
    //Home->MenuY = Config::Home::MenuY;
    Home->TeamGamemode = Config::Home::TeamGamemode;
}

void LoadASCIIConfig() {
    Home->AsciiArt = Config::Home::AsciiArt;
    Home->AsciiArtSpeed = Config::Home::AsciiArtSpeed;
}

void LoadOverlaySave() {
    // Overlay //
    // Styling //
    if (Config::Home::Style == 0) {
	Home->Alpha                   = 1.0f;             
	Home->WindowPadding           = ImVec2(8,8);      
	Home->WindowRounding          = 0.0f;             
	Home->WindowBorderSize        = 1.0f;             
	Home->WindowMinSize           = ImVec2(32,32);    
	Home->WindowTitleAlign        = ImVec2(0.0f,0.5f);
	Home->ChildRounding           = 0.0f;             
	Home->ChildBorderSize         = 1.0f;             
	Home->PopupRounding           = 0.0f;            
	Home->PopupBorderSize         = 1.0f;        
	Home->FramePadding            = ImVec2(4,3);    
	Home->FrameRounding           = 0.0f;          
	Home->FrameBorderSize         = 0.0f;       
	Home->ItemSpacing             = ImVec2(8,4);    
	Home->ItemInnerSpacing        = ImVec2(4,4);     
	Home->CellPadding             = ImVec2(4,2);      
	Home->TouchExtraPadding       = ImVec2(0,0);     
	Home->IndentSpacing           = 21.0f;          
	Home->ColumnsMinSpacing       = 6.0f;            
	Home->ScrollbarSize           = 12.0f;          
	Home->ScrollbarRounding       = 9.0f;         
	Home->GrabMinSize             = 10.0f;      
	Home->GrabRounding            = 0.0f;          
	Home->LogSliderDeadzone       = 4.0f;             
	Home->TabRounding             = 4.0f;         
	Home->TabBorderSize           = 0.0f;            
	Home->TabMinWidthForCloseButton = 0.0f;           
	Home->ButtonTextAlign         = ImVec2(0.5f,0.5f);
	Home->SelectableTextAlign     = ImVec2(0.0f,0.0f);
    }
    
    if (Config::Home::Style == 1) {
	Home->Alpha 			= 1.0f;
	Home->DisabledAlpha 		= 1.0f;
	Home->WindowPadding 		= ImVec2(12.0f, 12.0f);
	Home->WindowRounding 		= 0.0f;
	Home->WindowBorderSize 	= 0.0f;
	Home->WindowMinSize 		= ImVec2(20.0f, 20.0f);
	Home->WindowTitleAlign 	= ImVec2(0.5f, 0.5f);
	Home->ChildRounding 		= 0.0f;
	Home->ChildBorderSize 	= 1.0f;
	Home->PopupRounding 		= 0.0f;
	Home->PopupBorderSize 	= 1.0f;
	Home->FramePadding 		= ImVec2(6.0f, 6.0f);
	Home->FrameRounding 		= 0.0f;
	Home->FrameBorderSize 	= 0.0f;
	Home->ItemSpacing 		= ImVec2(12.0f, 6.0f);
	Home->ItemInnerSpacing 	= ImVec2(6.0f, 3.0f);
	Home->CellPadding 		= ImVec2(12.0f, 6.0f);
	Home->IndentSpacing 		= 20.0f;
	Home->ColumnsMinSpacing 	= 6.0f;
	Home->ScrollbarSize 		= 12.0f;
	Home->ScrollbarRounding 	= 0.0f;
	Home->GrabMinSize 		= 12.0f;
	Home->GrabRounding 		= 0.0f;
	Home->TabRounding 		= 0.0f;
	Home->TabBorderSize 		= 0.0f;
	Home->TabMinWidthForCloseButton = 0.0f;
	Home->ButtonTextAlign 	= ImVec2(0.5f, 0.5f);
	Home->SelectableTextAlign 	= ImVec2(0.0f, 0.0f);
	Home->LogSliderDeadzone 	= 4;
    }
    if (Config::Home::Style == 2) {
	Home->Alpha			   = 1.0f;
	Home->DisabledAlpha 		   = 1.0f;
	Home->WindowPadding                   = ImVec2(8.00f, 8.00f);
	Home->FramePadding                    = ImVec2(5.00f, 2.00f);
	Home->CellPadding                     = ImVec2(6.00f, 6.00f);
	Home->ItemSpacing                     = ImVec2(6.00f, 6.00f);
	Home->ItemInnerSpacing                = ImVec2(6.00f, 6.00f);
	Home->TouchExtraPadding               = ImVec2(0.00f, 0.00f);
	Home->WindowTitleAlign                = ImVec2(0.5f, 0.5f);
	Home->IndentSpacing                      = 25;
	Home->ScrollbarSize                      = 12;
	Home->GrabMinSize                        = 10;
	Home->WindowBorderSize                   = 1;
	Home->ChildBorderSize                    = 1;
	Home->PopupBorderSize                    = 1;
	Home->FrameBorderSize                    = 1;
	Home->TabBorderSize                      = 1;
	Home->WindowRounding                     = 7;
	Home->ChildRounding                      = 4;
	Home->FrameRounding                      = 3;
	Home->PopupRounding                      = 4;
	Home->ScrollbarRounding                  = 9;
	Home->GrabRounding                       = 3;
	Home->LogSliderDeadzone                  = 4;
	Home->TabRounding                        = 4;
    }
    
    if (Config::Home::Style == 3) {
	Home->Alpha = 1.0f;
	Home->DisabledAlpha = 1.0f;
	Home->WindowPadding = ImVec2(12.0f, 12.0f);
	Home->WindowRounding = 3.0f;
	Home->WindowBorderSize = 0.0f;
	Home->WindowMinSize = ImVec2(20.0f, 20.0f);
	Home->WindowTitleAlign = ImVec2(0.5f, 0.5f);
	Home->ChildRounding = 3.0f;
	Home->ChildBorderSize = 1.0f;
	Home->PopupRounding = 0.0f;
	Home->PopupBorderSize = 1.0f;
	Home->FramePadding = ImVec2(6.0f, 6.0f);
	Home->FrameRounding = 3.0f;
	Home->FrameBorderSize = 0.0f;
	Home->ItemSpacing = ImVec2(12.0f, 6.0f);
	Home->ItemInnerSpacing = ImVec2(6.0f, 3.0f);
	Home->CellPadding = ImVec2(12.0f, 6.0f);
	Home->IndentSpacing = 20.0f;
	Home->ColumnsMinSpacing = 6.0f;
	Home->ScrollbarSize = 12.0f;
	Home->ScrollbarRounding = 0.0f;
	Home->GrabMinSize = 20.0f;
	Home->GrabRounding = 1.0f;
	Home->TabRounding = 0.0f;
	Home->TabBorderSize = 0.0f;
	Home->TabMinWidthForCloseButton = 0.0f;
	Home->ButtonTextAlign = ImVec2(0.5f, 0.5f);
	Home->SelectableTextAlign = ImVec2(0.0f, 0.0f);
    }
    
    if (Config::Home::Style == 4) {
	Home->Alpha			   = 1.0f;
	Home->DisabledAlpha                   = 1.0f;
	Home->WindowPadding                   = ImVec2(8.00f, 8.00f);
	Home->FramePadding                    = ImVec2(5.00f, 2.00f);
	Home->CellPadding                     = ImVec2(6.00f, 6.00f);
	Home->ItemSpacing                     = ImVec2(6.00f, 6.00f);
	Home->ItemInnerSpacing                = ImVec2(6.00f, 6.00f);
	Home->TouchExtraPadding               = ImVec2(0.00f, 0.00f);
	Home->WindowTitleAlign                = ImVec2(0.5f, 0.5f);
	Home->IndentSpacing                      = 25;
	Home->ScrollbarSize                      = 12;
	Home->GrabMinSize                        = 10;
	Home->WindowBorderSize                   = 1;
	Home->ChildBorderSize                    = 1;
	Home->PopupBorderSize                    = 1;
	Home->FrameBorderSize                    = 1;
	Home->TabBorderSize                      = 1;
	Home->WindowRounding                     = 7;
	Home->ChildRounding                      = 4;
	Home->FrameRounding                      = 3;
	Home->PopupRounding                      = 4;
	Home->ScrollbarRounding                  = 9;
	Home->GrabRounding                       = 3;
	Home->LogSliderDeadzone                  = 4;
	Home->TabRounding                        = 4;
    }
    
    if (Config::Home::Style == 5) {
	Home->Alpha = 1.0f;
	Home->DisabledAlpha = 1.0f;
	Home->WindowPadding = ImVec2(12.0f, 12.0f);
	Home->WindowRounding = 11.5f;
	Home->WindowBorderSize = 0.0f;
	Home->WindowMinSize = ImVec2(20.0f, 20.0f);
	Home->WindowTitleAlign = ImVec2(0.5f, 0.5f);
	Home->ChildRounding = 0.0f;
	Home->ChildBorderSize = 1.0f;
	Home->PopupRounding = 0.0f;
	Home->PopupBorderSize = 1.0f;
	Home->FramePadding = ImVec2(20.0f, 3.400000095367432f);
	Home->FrameRounding = 11.89999961853027f;
	Home->FrameBorderSize = 0.0f;
	Home->ItemSpacing = ImVec2(4.300000190734863f, 5.5f);
	Home->ItemInnerSpacing = ImVec2(7.099999904632568f, 1.799999952316284f);
	Home->CellPadding = ImVec2(12.10000038146973f, 9.199999809265137f);
	Home->IndentSpacing = 0.0f;
	Home->ColumnsMinSpacing = 4.900000095367432f;
	Home->ScrollbarSize = 12;
	Home->ScrollbarRounding = 15.89999961853027f;
	Home->GrabMinSize = 3.700000047683716f;
	Home->GrabRounding = 20.0f;
	Home->TabRounding = 0.0f;
	Home->TabBorderSize = 0.0f;
	Home->TabMinWidthForCloseButton = 0.0f;
	Home->ButtonTextAlign = ImVec2(0.5f, 0.5f);
	Home->SelectableTextAlign = ImVec2(0.0f, 0.0f);
    }
    
    // Colors //
    if (Config::Home::Color == 0) {
	Home->Text                   = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	Home->TextDisabled           = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	Home->WindowBg               = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	Home->ChildBg                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Home->PopupBg                = ImVec4(0.11f, 0.11f, 0.14f, 0.92f);
	Home->Border                 = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
	Home->BorderShadow           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Home->FrameBg                = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
	Home->FrameBgHovered         = ImVec4(0.47f, 0.47f, 0.69f, 0.40f);
	Home->FrameBgActive          = ImVec4(0.42f, 0.41f, 0.64f, 0.69f);
	Home->TitleBg                = ImVec4(0.27f, 0.27f, 0.54f, 0.83f);
	Home->TitleBgActive          = ImVec4(0.32f, 0.32f, 0.63f, 0.87f);
	Home->TitleBgCollapsed       = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
	Home->MenuBarBg              = ImVec4(0.40f, 0.40f, 0.55f, 0.80f);
	Home->ScrollbarBg            = ImVec4(0.20f, 0.25f, 0.30f, 0.00f);
	Home->ScrollbarGrab          = ImVec4(0.40f, 0.40f, 0.80f, 0.30f);
	Home->ScrollbarGrabHovered   = ImVec4(0.40f, 0.40f, 0.80f, 0.40f);
	Home->ScrollbarGrabActive    = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	Home->CheckMark              = ImVec4(0.90f, 0.90f, 0.90f, 0.50f);
	Home->SliderGrab             = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	Home->SliderGrabActive       = ImVec4(0.41f, 0.39f, 0.80f, 0.60f);
	Home->Button                 = ImVec4(0.35f, 0.40f, 0.61f, 0.62f);
	Home->ButtonHovered          = ImVec4(0.40f, 0.48f, 0.71f, 0.79f);
	Home->ButtonActive           = ImVec4(0.46f, 0.54f, 0.80f, 1.00f);
	Home->Header                 = ImVec4(0.40f, 0.40f, 0.90f, 0.45f);
	Home->HeaderHovered          = ImVec4(0.45f, 0.45f, 0.90f, 0.80f);
	Home->HeaderActive           = ImVec4(0.53f, 0.53f, 0.87f, 0.80f);
	Home->Separator              = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	Home->SeparatorHovered       = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
	Home->SeparatorActive        = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
	Home->ResizeGrip             = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	Home->ResizeGripHovered      = ImVec4(0.78f, 0.82f, 1.00f, 0.60f);
	Home->ResizeGripActive       = ImVec4(0.78f, 0.82f, 1.00f, 0.90f);
	Home->TabHovered             = Home->HeaderHovered;
	Home->PlotLines              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	Home->PlotLinesHovered       = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	Home->PlotHistogram          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	Home->PlotHistogramHovered   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	Home->TableHeaderBg          = ImVec4(0.27f, 0.27f, 0.38f, 1.00f);
	Home->TableBorderStrong      = ImVec4(0.31f, 0.31f, 0.45f, 1.00f);
	Home->TableBorderLight       = ImVec4(0.26f, 0.26f, 0.28f, 1.00f);
	Home->TableRowBg             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Home->TableRowBgAlt          = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	Home->TextSelectedBg         = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
	Home->DragDropTarget         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	Home->NavHighlight           = Home->HeaderHovered;
	Home->NavWindowingHighlight  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	Home->NavWindowingDimBg      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	Home->ModalWindowDimBg       = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
    }
    if (Config::Home::Color == 1) {
	Home->Text 		= ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	Home->TextDisabled 	= ImVec4(0.27f, 0.31f, 0.45f, 1.0f);
	Home->WindowBg 		= ImVec4(0.07f, 0.08f, 0.10f, 1.00f);
	Home->ChildBg 		= ImVec4(0.078f, 0.08f, 0.10f, 1.0f);
	Home->PopupBg 		= ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->Border 		= ImVec4(0.15f, 0.16f, 0.19f, 1.0f);
	Home->BorderShadow 	= ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->FrameBg 		= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->FrameBgHovered 	= ImVec4(0.15f, 0.16f, 0.19f, 1.0f);
	Home->FrameBgActive 	= ImVec4(0.23f, 0.21f, 0.59f, 1.0f);
	Home->TitleBg 		= ImVec4(0.047f, 0.05f, 0.07f, 1.0f);
	Home->TitleBgActive 	= ImVec4(0.04f, 0.05f, 0.07f, 1.0f);
	Home->TitleBgCollapsed 	= ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->MenuBarBg 		= ImVec4(0.09f, 0.10f, 0.12f, 1.0f);
	Home->ScrollbarBg 		= ImVec4(0.04f, 0.05f, 0.07f, 0.00f);
	Home->ScrollbarGrab 	= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->ScrollbarGrabHovered = ImVec4(0.15f, 0.16f, 0.19f, 1.0f);
	Home->ScrollbarGrabActive 	= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->CheckMark 		= ImVec4(0.49f, 0.51f, 1.0f, 1.0f);
	Home->SliderGrab 		= ImVec4(0.49f, 0.51f, 1.0f, 1.0f);
	Home->SliderGrabActive 	= ImVec4(0.53f, 0.55f, 1.0f, 1.0f);
	Home->Button 		= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->ButtonHovered 	= ImVec4(0.19f, 0.17f, 0.54f, 1.0f);
	Home->ButtonActive 	= ImVec4(0.23f, 0.21f, 0.59f, 1.0f);
	Home->Header 		= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->HeaderHovered 	= ImVec4(0.19f, 0.17f, 0.54f, 1.0f);
	Home->HeaderActive 	= ImVec4(0.23f, 0.21f, 0.59f, 1.0f);
	Home->Separator 		= ImVec4(0.15f, 0.18f, 0.25f, 1.0f);
	Home->SeparatorHovered 	= ImVec4(0.15f, 0.18f, 0.25f, 1.0f);
	Home->SeparatorActive 	= ImVec4(0.15f, 0.18f, 0.25f, 1.0f);
	Home->ResizeGrip 		= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->ResizeGripHovered 	= ImVec4(0.19f, 0.17f, 0.54f, 1.0f);
	Home->ResizeGripActive 	= ImVec4(0.23f, 0.21f, 0.59f, 1.0f);
	Home->Tab 			= ImVec4(0.04f, 0.05f, 0.07f, 1.0f);
	Home->TabHovered 		= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->TabActive 		= ImVec4(0.09f, 0.10f, 0.12f, 1.0f);
	Home->TabUnfocused 	= ImVec4(0.04f, 0.05f, 0.07f, 1.0f);
	Home->TabUnfocusedActive 	= ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->PlotLines 		= ImVec4(0.52f, 0.60f, 0.70f, 1.0f);
	Home->PlotLinesHovered 	= ImVec4(0.03f, 0.98f, 0.98f, 1.0f);
	Home->PlotHistogram 	= ImVec4(1.0f, 0.29f, 0.59f, 1.0f);
	Home->PlotHistogramHovered = ImVec4(0.99f, 0.47f, 0.69f, 1.0f);
	Home->TableHeaderBg 	= ImVec4(0.047f, 0.05f, 0.07f, 1.0f);
	Home->TableBorderStrong 	= ImVec4(0.04f, 0.05f, 0.07f, 1.0f);
	Home->TableBorderLight 	= ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	Home->TableRowBg 		= ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->TableRowBgAlt 	= ImVec4(0.09f, 0.10f, 0.12f, 1.0f);
	Home->TextSelectedBg 	= ImVec4(0.23f, 0.21f, 0.59f, 1.0f);
	Home->DragDropTarget 	= ImVec4(0.49f, 0.51f, 1.0f, 1.0f);
	Home->NavHighlight 	= ImVec4(0.49f, 0.51f, 1.0f, 1.0f);
	Home->NavWindowingHighlight = ImVec4(0.49f, 0.51f, 1.0f, 1.0f);
	Home->NavWindowingDimBg 	= ImVec4(0.19f, 0.17f, 0.54f, 0.50f);
	Home->ModalWindowDimBg 	= ImVec4(0.19f, 0.17f, 0.54f, 0.50f);
    }
    if (Config::Home::Color == 2) {
	Home->Text                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	Home->TextDisabled           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	Home->WindowBg               = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	Home->ChildBg                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Home->PopupBg                = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	Home->Border                 = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	Home->BorderShadow           = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	Home->FrameBg                = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	Home->FrameBgHovered         = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	Home->FrameBgActive          = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	Home->TitleBg                = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	Home->TitleBgActive          = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	Home->TitleBgCollapsed       = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	Home->MenuBarBg              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	Home->ScrollbarBg            = ImVec4(0.05f, 0.05f, 0.05f, 0.00f);
	Home->ScrollbarGrab          = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	Home->ScrollbarGrabHovered   = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	Home->ScrollbarGrabActive    = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	Home->CheckMark              = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	Home->SliderGrab             = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	Home->SliderGrabActive       = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	Home->Button                 = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	Home->ButtonHovered          = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	Home->ButtonActive           = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	Home->Header                 = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	Home->HeaderHovered          = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	Home->HeaderActive           = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	Home->Separator              = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	Home->SeparatorHovered       = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	Home->SeparatorActive        = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	Home->ResizeGrip             = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	Home->ResizeGripHovered      = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	Home->ResizeGripActive       = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	Home->Tab                    = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	Home->TabHovered             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	Home->TabActive              = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	Home->TabUnfocused           = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	Home->TabUnfocusedActive     = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	Home->PlotLines              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	Home->PlotLinesHovered       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	Home->PlotHistogram          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	Home->PlotHistogramHovered   = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	Home->TableHeaderBg          = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	Home->TableBorderStrong      = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	Home->TableBorderLight       = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	Home->TableRowBg             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Home->TableRowBgAlt          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	Home->TextSelectedBg         = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	Home->DragDropTarget         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	Home->NavHighlight           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	Home->NavWindowingHighlight  = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	Home->NavWindowingDimBg      = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	Home->ModalWindowDimBg       = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);
    }
    if (Config::Home::Color == 3) {
	Home->Text = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	Home->TextDisabled = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
	Home->WindowBg = ImVec4(0.00f, 0.00f, 0.00f, 0.7f);
	Home->Border = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
	Home->BorderShadow = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Home->FrameBg = ImVec4(0.00f, 1.00f, 1.00f, 0.18f);
	Home->FrameBgHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
	Home->FrameBgActive = ImVec4(0.00f, 1.00f, 1.00f, 0.66f);
	Home->PlotLines = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
	Home->Tab = ImVec4(0.00f, 1.00f, 1.00f, 0.18f);
	Home->TabHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.60f);
	Home->TabActive = ImVec4(0.00f, 1.00f, 1.00f, 0.60f);
	Home->TitleBg = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
	Home->TitleBgCollapsed = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	Home->TitleBgActive = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
	Home->MenuBarBg = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
	Home->ScrollbarBg = ImVec4(0.22f, 0.29f, 0.30f, 0.00f);
	Home->ScrollbarGrab = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
	Home->ScrollbarGrabHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	Home->ScrollbarGrabActive = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	Home->Separator = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
	Home->CheckMark = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
	Home->SliderGrab = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
	Home->SliderGrabActive = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
	Home->Button = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
	Home->ButtonHovered = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
	Home->ButtonActive = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
	Home->Header = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
	Home->HeaderHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
	Home->HeaderActive = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	Home->ResizeGrip = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	Home->ResizeGripHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	Home->ResizeGripActive = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	Home->PlotLinesHovered = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	Home->PlotHistogram = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	Home->PlotHistogramHovered = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	Home->TextSelectedBg = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);    
    }
    if (Config::Home::Color == 4) {
	Home->Text                   = ImVec4(0.00f, 0.82f, 1.00f, 1.00f);
	Home->TextDisabled           = ImVec4(0.00f, 0.36f, 0.63f, 1.00f);
	Home->WindowBg               = ImVec4(0.00f, 0.04f, 0.12f, 1.00f);
	Home->ChildBg                = ImVec4(0.03f, 0.04f, 0.22f, 1.00f);
	Home->PopupBg                = ImVec4(0.12f, 0.06f, 0.27f, 1.00f);
	Home->Border                 = ImVec4(0.61f, 0.00f, 1.00f, 1.00f);
	Home->FrameBg                = ImVec4(0.00f, 0.75f, 1.00f, 0.20f);
	Home->FrameBgHovered         = ImVec4(0.34f, 0.00f, 1.00f, 1.00f);
	Home->FrameBgActive          = ImVec4(0.08f, 0.00f, 1.00f, 1.00f);
	Home->TitleBg                = ImVec4(0.00f, 0.81f, 0.95f, 1.00f);
	Home->TitleBgActive          = ImVec4(0.61f, 0.00f, 1.00f, 1.00f);
	Home->TitleBgCollapsed       = ImVec4(0.25f, 0.00f, 0.54f, 0.81f);
	Home->MenuBarBg              = ImVec4(0.61f, 0.00f, 1.00f, 1.00f);
	Home->ScrollbarBg            = ImVec4(0.00f, 0.88f, 1.00f, 0.00f);
	Home->ScrollbarGrab          = ImVec4(0.61f, 0.00f, 1.00f, 1.00f);
	Home->ScrollbarGrabHovered   = ImVec4(0.00f, 0.82f, 1.00f, 1.00f);
	Home->ScrollbarGrabActive    = ImVec4(0.95f, 0.19f, 0.67f, 1.00f);
	Home->CheckMark              = ImVec4(0.95f, 0.19f, 0.92f, 1.00f);
	Home->SliderGrab             = ImVec4(0.00f, 1.00f, 0.95f, 1.00f);
	Home->SliderGrabActive       = ImVec4(0.81f, 0.00f, 1.00f, 1.00f);
	Home->Button                 = ImVec4(0.00f, 0.98f, 1.00f, 0.52f);
	Home->ButtonHovered          = ImVec4(0.94f, 0.00f, 1.00f, 0.80f);
	Home->ButtonActive           = ImVec4(0.01f, 0.00f, 1.00f, 1.00f);
	Home->Header                 = ImVec4(0.00f, 0.95f, 1.00f, 0.40f);
	Home->HeaderHovered          = ImVec4(0.94f, 0.00f, 1.00f, 0.80f);
	Home->HeaderActive           = ImVec4(0.01f, 0.00f, 1.00f, 1.00f);
	Home->Separator              = ImVec4(0.74f, 0.00f, 1.00f, 0.50f);
	Home->SeparatorHovered       = ImVec4(0.34f, 0.00f, 1.00f, 0.78f);
	Home->SeparatorActive        = ImVec4(0.00f, 1.00f, 0.85f, 1.00f);
	Home->ResizeGrip             = ImVec4(0.61f, 0.00f, 1.00f, 1.00f);
	Home->ResizeGripHovered      = ImVec4(0.89f, 0.26f, 0.98f, 0.67f);
	Home->ResizeGripActive       = ImVec4(0.00f, 0.88f, 1.00f, 0.95f);
	Home->Tab                    = ImVec4(0.36f, 0.00f, 1.00f, 1.00f);
	Home->TabHovered             = ImVec4(0.00f, 0.92f, 1.00f, 0.80f);
	Home->TabActive              = ImVec4(0.62f, 0.00f, 0.80f, 1.00f);
	Home->PlotHistogram          = ImVec4(0.00f, 1.00f, 0.88f, 1.00f);    
    }
    if (Config::Home::Color == 5) {
	Home->Text = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	Home->TextDisabled = ImVec4(0.27f, 0.31f, 0.45f, 1.0f);
	Home->WindowBg = ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->ChildBg = ImVec4(0.09f, 0.10f, 0.11f, 1.0f);
	Home->PopupBg = ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->Border = ImVec4(0.15f, 0.16f, 0.19f, 1.0f);
	Home->BorderShadow = ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->FrameBg = ImVec4(0.11f, 0.12f, 0.15f, 1.0f);
	Home->FrameBgHovered = ImVec4(0.15f, 0.16f, 0.19f, 1.0f);
	Home->FrameBgActive = ImVec4(0.15f, 0.16f, 0.19f, 1.0f);
	Home->TitleBg = ImVec4(0.04f, 0.05f, 0.07f, 1.0f);
	Home->TitleBgActive = ImVec4(0.047f, 0.05f, 0.07f, 1.0f);
	Home->TitleBgCollapsed = ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->MenuBarBg = ImVec4(0.09f, 0.10f, 0.12f, 1.0f);
	Home->ScrollbarBg = ImVec4(0.04f, 0.05f, 0.07f, 0.00f);
	Home->ScrollbarGrab = ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->ScrollbarGrabHovered = ImVec4(0.15f, 0.16f, 0.19f, 1.0f);
	Home->ScrollbarGrabActive = ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->CheckMark = ImVec4(0.97f, 1.0f, 0.49f, 1.0f);
	Home->SliderGrab = ImVec4(0.97f, 1.0f, 0.49f, 1.0f);
	Home->SliderGrabActive = ImVec4(1.0f, 0.79f, 0.49f, 1.0f);
	Home->Button = ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->ButtonHovered = ImVec4(0.18f, 0.18f, 0.19f, 1.0f);
	Home->ButtonActive = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
	Home->Header = ImVec4(0.14f, 0.16f, 0.20f, 1.0f);
	Home->HeaderHovered = ImVec4(0.10f, 0.10f, 0.10f, 1.0f);
	Home->HeaderActive = ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->Separator = ImVec4(0.12f, 0.14f, 0.19f, 1.0f);
	Home->SeparatorHovered = ImVec4(0.15f, 0.18f, 0.25f, 1.0f);
	Home->SeparatorActive = ImVec4(0.15f, 0.18f, 0.25f, 1.0f);
	Home->ResizeGrip = ImVec4(0.14f, 0.14f, 0.14f, 1.0f);
	Home->ResizeGripHovered = ImVec4(0.97f, 1.0f, 0.49f, 1.0f);
	Home->ResizeGripActive = ImVec4(0.99f, 1.0f, 0.99f, 1.0f);
	Home->Tab = ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->TabHovered = ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->TabActive = ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->TabUnfocused = ImVec4(0.07f, 0.08f, 0.10f, 1.0f);
	Home->TabUnfocusedActive = ImVec4(0.12f, 0.27f, 0.57f, 1.0f);
	Home->PlotLines = ImVec4(0.52f, 0.60f, 0.70f, 1.0f);
	Home->PlotLinesHovered = ImVec4(0.03f, 0.98f, 0.98f, 1.0f);
	Home->PlotHistogram = ImVec4(0.88f, 0.79f, 0.56f, 1.0f);
	Home->PlotHistogramHovered = ImVec4(0.95f, 0.95f, 0.95f, 1.0f);
	Home->TableHeaderBg = ImVec4(0.04f, 0.05f, 0.07f, 1.0f);
	Home->TableBorderStrong = ImVec4(0.04f, 0.05f, 0.07f, 1.0f);
	Home->TableBorderLight = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	Home->TableRowBg = ImVec4(0.11f, 0.13f, 0.14f, 1.0f);
	Home->TableRowBgAlt = ImVec4(0.09f, 0.10f, 0.12f, 1.0f);
	Home->TextSelectedBg = ImVec4(0.93f, 0.93f, 0.93f, 1.0f);
	Home->DragDropTarget = ImVec4(0.49f, 0.51f, 1.0f, 1.0f);
	Home->NavHighlight = ImVec4(0.26f, 0.28f, 1.0f, 1.0f);
	Home->NavWindowingHighlight = ImVec4(0.49f, 0.51f, 1.0f, 1.0f);
	Home->NavWindowingDimBg = ImVec4(0.19f, 0.17f, 0.54f, 0.50f);
	Home->ModalWindowDimBg = ImVec4(0.19f, 0.17f, 0.54f, 0.50f);
    }
    
    if (Config::Home::Color == 6) {
	Home->Text                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	Home->TextDisabled           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	Home->WindowBg               = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->ChildBg                = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->PopupBg                = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
	Home->Border                 = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->BorderShadow           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Home->FrameBg                = ImVec4(0.18f, 0.18f, 0.19f, 1.00f);
	Home->FrameBgHovered         = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	Home->FrameBgActive          = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	Home->TitleBg                = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->TitleBgActive          = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->TitleBgCollapsed       = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->MenuBarBg              = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->ScrollbarBg            = ImVec4(0.27f, 0.27f, 0.28f, 0.00f);
	Home->ScrollbarGrab          = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
	Home->ScrollbarGrabHovered   = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	Home->ScrollbarGrabActive    = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	Home->CheckMark              = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	Home->SliderGrab             = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	Home->SliderGrabActive       = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	Home->Button                 = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	Home->ButtonHovered          = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	Home->ButtonActive           = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	Home->Header                 = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->HeaderHovered          = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->HeaderActive           = ImVec4(0.27f, 0.27f, 0.28f, 1.00f);
	Home->Separator              = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	Home->SeparatorHovered       = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	Home->SeparatorActive        = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	Home->ResizeGrip             = ImVec4(0.36f, 0.38f, 0.39f, 1.00f);
	Home->ResizeGripHovered      = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	Home->ResizeGripActive       = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	Home->PlotLines              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	Home->PlotLinesHovered       = ImVec4(0.60f, 0.36f, 0.76f, 0.40f);
	Home->PlotHistogram          = ImVec4(0.61f, 0.35f, 0.71f, 1.00f);
	Home->PlotHistogramHovered   = ImVec4(0.56f, 0.27f, 0.68f, 1.00f);
	Home->TextSelectedBg         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	Home->DragDropTarget         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	Home->NavHighlight           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	Home->NavWindowingHighlight  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    }
    
    if (Config::Home::Color == 7) {
	Home->Text = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	Home->TextDisabled = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
	Home->WindowBg = ImVec4(0.05490196123719215f, 0.03529411926865578f, 0.1843137294054031f, 1.0f);
	Home->ChildBg = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->PopupBg = ImVec4(0.05490196123719215f, 0.03529411926865578f, 0.1843137294054031f, 1.0f);
	Home->Border = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->BorderShadow = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	Home->FrameBg = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->FrameBgHovered = ImVec4(0.1333333402872086f, 0.1764705926179886f, 0.5058823823928833f, 1.0f);
	Home->FrameBgActive = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->TitleBg = ImVec4(0.1333333402872086f, 0.1764705926179886f, 0.5058823823928833f, 1.0f);
	Home->TitleBgActive = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->TitleBgCollapsed = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->MenuBarBg = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->ScrollbarBg = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.00f);
	Home->ScrollbarGrab = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->ScrollbarGrabHovered = ImVec4(0.1647058874368668f, 0.7529411911964417f, 0.9490196108818054f, 1.0f);
	Home->ScrollbarGrabActive = ImVec4(0.1647058874368668f, 0.7529411911964417f, 0.9490196108818054f, 1.0f);
	Home->CheckMark = ImVec4(0.1647058874368668f, 0.7529411911964417f, 0.9490196108818054f, 1.0f);
	Home->SliderGrab = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->SliderGrabActive = ImVec4(0.1647058874368668f, 0.7529411911964417f, 0.9490196108818054f, 1.0f);
	Home->Button = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->ButtonHovered = ImVec4(0.1333333402872086f, 0.1764705926179886f, 0.5058823823928833f, 1.0f);
	Home->ButtonActive = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->Header = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->HeaderHovered = ImVec4(0.1333333402872086f, 0.1764705926179886f, 0.5058823823928833f, 1.0f);
	Home->HeaderActive = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->Separator = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
	Home->SeparatorHovered = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 0.7799999713897705f);
	Home->SeparatorActive = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 1.0f);
	Home->ResizeGrip = ImVec4(0.2313725501298904f, 0.3568627536296844f, 0.9960784316062927f, 1.0f);
	Home->ResizeGripHovered = ImVec4(0.1584483087062836f, 0.2800911366939545f, 0.8025751113891602f, 1.0f);
	Home->ResizeGripActive = ImVec4(0.09891508519649506f, 0.2253202944993973f, 0.7682403326034546f, 1.0f);
	Home->Tab = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->TabHovered = ImVec4(0.1333333402872086f, 0.1764705926179886f, 0.5058823823928833f, 1.0f);
	Home->TabActive = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->TabUnfocused = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->TabUnfocusedActive = ImVec4(0.2745098173618317f, 0.3568627536296844f, 0.9058823585510254f, 1.0f);
	Home->PlotLines = ImVec4(0.1584483087062836f, 0.2800911366939545f, 0.8025751113891602f, 1.0f);
	Home->PlotLinesHovered = ImVec4(0.2313725501298904f, 0.3568627536296844f, 0.9960784316062927f, 1.0f);
	Home->PlotHistogram = ImVec4(0.1584483087062836f, 0.2800911366939545f, 0.8025751113891602f, 1.0f);
	Home->PlotHistogramHovered = ImVec4(0.2313725501298904f, 0.3568627536296844f, 0.9960784316062927f, 1.0f);
	Home->TableHeaderBg = ImVec4(0.2313725501298904f, 0.3568627536296844f, 0.9960784316062927f, 1.0f);
	Home->TableBorderStrong = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->TableBorderLight = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->TableRowBg = ImVec4(0.1333333402872086f, 0.1764705926179886f, 0.5058823823928833f, 1.0f);
	Home->TableRowBgAlt = ImVec4(0.105882354080677f, 0.09411764889955521f, 0.3254902064800262f, 1.0f);
	Home->TextSelectedBg = ImVec4(0.2313725501298904f, 0.3568627536296844f, 0.9960784316062927f, 1.0f);
	Home->DragDropTarget = ImVec4(0.2313725501298904f, 0.3568627536296844f, 0.9960784316062927f, 1.0f);
	Home->NavHighlight = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
	Home->NavWindowingHighlight = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
	Home->NavWindowingDimBg = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
	Home->ModalWindowDimBg = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
    }

}

void SaveConfig() {
    if (!Home->Save()) std::cout << "something went wrong trying to save Home settings" << std::endl;
    if (!AimAssist->Save()) std::cout << "something went wrong trying to save Aimbot settings" << std::endl;
    //if (!Recoil->Save()) std::cout << "something went wrong trying to save RCS settings" << std::endl;
    if (!ESP->Save()) std::cout << "something went wrong trying to save ESP settings" << std::endl;
    if (!GlowESP->Save()) std::cout << "something went wrong trying to save Glow settings" << std::endl;
    if (!Trigger->Save()) std::cout << "something went wrong trying to save Triggerbot settings" << std::endl;
    if (!MiscTab->Save()) std::cout << "something went wrong trying to save Misc settings" << std::endl;
    UpdateConfig();
}

// Interface
ImVec4 ProcessingTimeColor;
void RenderUI() {
    auto io = ImGui::GetIO();
	ImGui::SetNextWindowSize(io.DisplaySize);
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("##Overlay", nullptr,
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoScrollbar |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoInputs |
		ImGuiWindowFlags_NoBackground |
		ImGuiSliderFlags_AlwaysClamp
	);
	Canvas = ImGui::GetWindowDrawList();
    //if (Map->IsPlayable)
    	MapRadar->RenderDrawings(Canvas, Myself, OverlayWindow);
    	ESP->RenderWatermark(Canvas, Myself, OverlayWindow);
        ESP->RenderDrawings(Canvas, AimAssist, Myself, OverlayWindow);
	ImGui::End();

    if (!IsMenuOpened) return;

    // Menu
    ImGui::SetNextWindowSizeConstraints(ImVec2(Modules::Home::MenuX, Modules::Home::MenuY), ImVec2(Modules::Home::MenuX, Modules::Home::MenuY));
    ImGui::SetNextWindowSize(ImVec2(Modules::Home::MenuX, Modules::Home::MenuY), ImGuiCond_FirstUseEver);
    ImGui::Begin("zap-client", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
    
    /*ProcessingTimeColor = OverlayWindow.ProcessingTime > 20 ? ProcessingTimeColor = ImVec4(1, 0.343, 0.475, 1) : ProcessingTimeColor = ImVec4(0.4, 1, 0.343, 1);
    ImGui::TextColored(ProcessingTimeColor, "Processing Time: %02dms ", OverlayWindow.ProcessingTime);
    ImGui::SameLine();*/

    /*if (OverlayWindow.AlignedButton("Save Config")) {
        SaveConfig();
        std::cout << "config saved" << std::endl;
    }    
    ImGui::SameLine();
    if (OverlayWindow.AlignedButton("Load Config")) {
        LoadConfig();
        std::cout << "config loaded" << std::endl;
    }*/   

    if (ImGui::BeginTabBar("Menus"), ImGuiTabBarFlags_NoCloseWithMiddleMouseButton | ImGuiTabBarFlags_NoTabListScrollingButtons) {
        // Draw Settings //
        Home->SetUIStyle(); //Home Tab
        AimAssist->RenderUI();
        //Recoil->RenderUI();
        Trigger->RenderUI();
        GlowESP->RenderUI();
        ESP->RenderUI();
        MapRadar->RenderUI();
        MiscTab->RenderUI();
        //Testing->RenderUI();
        
    	if (ImGui::BeginTabItem("Config", nullptr, ImGuiTabItemFlags_NoCloseWithMiddleMouseButton | ImGuiTabItemFlags_NoReorder)) {
    		ImVec2 TabSize;
		    TabSize = ImGui::GetWindowSize();
		    //Config
		    ImGui::Text("Config Saving");
		    if (ImGui::BeginChild("Config Saving Tab", ImVec2(TabSize.x - TabSize.x , (TabSize.y - TabSize.y) + 270), true)) {
                ImGui::Text("Config Saving");
                if (ImGui::Button("Save Config")) {
                    SaveConfig();
                    std::cout << "Config Saved!" << std::endl;
                }
                ImGui::EndChild();
            }

    		ImGui::Text("Config Loading");
		    if (ImGui::BeginChild("Config Loading Tab", ImVec2(TabSize.x - TabSize.x , (TabSize.y - TabSize.y) + 285), true)) {
                ImGui::Text("Config Loading");
                if (ImGui::Button("Load Config")) {
                    LoadConfig();
                    std::cout << "Config Loaded!" << std::endl;
                }
                ImGui::EndChild();
            }
            
        	ImGui::EndTabItem();
        }
    

        // Draw Credits //
        /*if (ImGui::BeginTabItem("Credits", nullptr, ImGuiTabItemFlags_NoCloseWithMiddleMouseButton | ImGuiTabItemFlags_NoReorder)) {
            ImGui::TextColored(ImVec4(0.65, 1, 0.95, 1), "Credits:");
            ImGui::TextColored(ImVec4(0.03, 1, 0.95, 1), "arturzxc: ESP, Triggerbot and X11Display's Move Mouse method");
            ImGui::TextColored(ImVec4(0.3, 1, 0.64, 1), "Koelion: ImGui Menu, AimbotResolver");
            ImGui::TextColored(ImVec4(0.3, 0.6, 0.9, 1), "unknowncheats: Offsets and ton of other things");
            ImGui::TextColored(ImVec4(0.6, 1, 0.64, 1), "Made by Azreol/Nexilist");
            ImGui::TextColored(ImVec4(0.744, 0.0400, 1.00, 1), "Pasted + Updated (With love) by Gerosity <3");
            ImGui::EndTabItem();
        }*/

        ImGui::EndTabBar();
    }

    ImGui::End();
}

// Core
bool UpdateCore() {
    try {
        // Map Checking //
        Map->Read();
        if (!Map->IsPlayable) {
            return true;
        }

        // Read Local Player //
        Myself->Read();
        if (!Myself->IsValid()) {
            return true;
        }

        // Populate Players //
        Players->clear();
        if (Map->IsFiringRange) {
            for (int i = 0; i < Dummies->size(); i++) {
                Player* p = Dummies->at(i);
                p->Read();
                if (p->BasePointer != 0 && (p->IsPlayer() || p->IsDummy()))
                    Players->push_back(p);
            }
        } else {
            for (int i = 0; i < HumanPlayers->size(); i++) {
                Player* p = HumanPlayers->at(i);
                p->Read();
                if (p->BasePointer != 0 && (p->IsPlayer() || p->IsDummy()))
                    Players->push_back(p);
            }
        }

        // Updates //
        GameCamera->Update();
        GlowESP->Update();
        //Recoil->Update();
        AimAssist->Update();
        Trigger->Update();
        MiscTab->Update();

        return true;
    } catch(const std::exception& ex) {
        std::system("clear");
        std::cout << "Error: " << ex.what() << std::endl;
        return true;
    }

    return false;
}

void SuperGlideThreadRun()
{
    while(!StopThread)
    {
        if (!Map->IsPlayable)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        if (!Myself->IsValid())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        if(!MiscTab->SuperGlide)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        if(!InputManager::isKeyDownOrPress(InputKeyType::KEYBOARD_SPACE))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        static float startjumpTime = 0;
        static bool startSg = false;
        static float traversalProgressTmp = 0.0;

        float worldtime = Memory::Read<float>(Myself->BasePointer + OFF_TIME_BASE); // Current time
        float traversalStartTime = Memory::Read<float>(Myself->BasePointer + OFF_TRAVERSAL_PROGRESS); // Time to start wall climbing
        float traversalProgress = Memory::Read<float>(Myself->BasePointer + OFF_TRAVERSAL_PROGRESS); // Wall climbing, if > 0.87 it is almost over.
        float HangOnWall = -(traversalStartTime - worldtime);

        if (HangOnWall > 0.1 && HangOnWall < 0.12)
        {
            Memory::Write<int>(OFF_REGION + OFF_IN_JUMP + 0x8, 4);
        }
        if (traversalProgress > 0.87f && !startSg && HangOnWall > 0.1f && HangOnWall < 1.5f)
        {
            //start SG
            startjumpTime = worldtime;
            startSg = true;
        }
        if (startSg)
        {
            //printf ("sg Press jump\n");
            Memory::Write<int>(OFF_REGION + OFF_IN_JUMP + 0x8, 5);
            while (Memory::Read<float>(Myself->BasePointer + OFF_TIME_BASE) - startjumpTime < 0.011);
            {
                Memory::Write<int>(OFF_REGION + OFF_IN_DUCK + 0x8, 6);
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                Memory::Write<int>(OFF_REGION + OFF_IN_JUMP + 0x8, 4);
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
            }
            startSg = false;
        }
    }
}

// Main
int main(int argc, char *argv[]) {
    if (getuid()) { 
        std::cout << "Please run as sudo!" << std::endl;
        return -1; 
    }

    // Waiting for Apex Legends to be found //
    while (Memory::GetPID() == 0) {
        std::system("clear");
        std::cout << "waiting for apex..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    std::system("clear");
    std::cout << " " << std::endl; //Spacing

    LoadASCIIConfig();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (Home->AsciiArt == 0) {
	    std::cout << "       _                        " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "       \`*-.                    " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "        )  _`-.                 " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "       .  : `. .                " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "       : _   '  \               " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "       ; *` _.   `*-._          " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "       `-.-'          `-.       " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "         ;       `       `.     " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "         :.       .        \    " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "         . \  .   :   .-'   .   " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "         '  `+.;  ;  '      :   " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "         :  '  |    ;       ;-. " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "         ; '   : :`-:     _.`* ;" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "     .*' /  .*' ; .*`- +'  `*' " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "      `*-*   `*-*  `*-*'" << std::endl;
    }
    
    if (Home->AsciiArt == 1) {
	    std::cout << " ,______________________________________       " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "|_________________,----------._ [____]  ""-,__  __....-----=====" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "               (_(||||||||||||)___________/   ""                |" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "                  `----------'        [ )) -,                   |" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "                                       ""    `,  _,--....___    |" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "                                               `/           """"" << std::endl;
    }
    
    if (Home->AsciiArt == 2) {
	    std::cout << " +--^----------,--------,-----,--------^-," << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << " | |||||||||   `--------'     |          O" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << " `+---------------------------^----------|" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "   `\_,---------,---------,--------------'" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "     / XXXXXX /'|       /'" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "    / XXXXXX /  `\    /'" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "   / XXXXXX /`-------'" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "  / XXXXXX /" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << " / XXXXXX /" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "(________(       " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << " `------'          " << std::endl;
    }
    
    if (Home->AsciiArt == 3) {
    	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⡤⠖⠊⠉⠁⠀⠀⠀⠉⠒⢦⡀⠀⠀⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⢀⠀⠀⠀⢀⡔⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⢧⣻⣆⠴⠯⣄⣤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⢠⠉⢁⡆⠈⠉⠸⠾⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣷⡄⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠸⣀⠾⢁⡀⠀⠀⠀⠈⢆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠿⠻⡄⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⡿⠇⠺⠿⠿⡟⣲⠴⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣃⡶⠿⢿⡀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⣦⣦⢀⣀⣤⡞⠁⠀⠀⠀⠀⠀⡠⢄⠀⠀⠀⠀⠀⡴⠻⣏⣶⠞⠛⠷⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠈⠉⠁⣧⠀⠙⡆⠀⠀⠀⠀⠀⠀⢸⠳⣄⡀⠀⠀⢣⠀⣻⣷⠖⠛⢷⡇" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⡟⠀⢀⡇⠀⠀⢀⢲⠛⢉⣥⠒⠁⠀⣀⡤⠋⣠⣿⡿⠿⢶⣸⠃" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⣀⠤⡴⠁⣠⠎⡇⠀⣆⡼⠛⠀⠛⠷⢶⠴⠛⠁⠀⣴⠿⠿⢷⣦⣀⡟⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠛⠿⠵⠷⣋⡴⠁⢠⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣄⣀⠀⢸⡟⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠰⣷⣄⡤⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⡿⠟⠋⠀⠀⠀" << std::endl;
    }
    
    if (Home->AsciiArt == 4) {
    	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣄⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⢻⠟⠙⣷⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⣰⠿⢿⡲⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⣰⠋⠀⠀⢸⡇" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠙⠢⣈⠛⢦⣄⠀⣀⣤⣤⡤⠤⠤⢴⣏⣀⡼⠁⠀⠀⠀⠀⡇" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⢿⠀⠀⠀⠀⠘⢲⡤⠞⠋⠁⠀⢸⡇⠀⠀⠀⠀⠈⠉⠲⣄⡀⠀⢀⡇" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠸⣇⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⢸⠹⡀⠀⠀⠀⠀⣀⠀⠀⠙⣄⣸⠃" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⢠⠏⠀⣀⡠⠤⣄⡀⠀⡏⠀⠳⣄⣴⣾⣍⡉⠉⠓⣄⠈⣧⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡏⢀⡞⠁⢠⣾⡷⠿⣿⡀⠀⠀⣿⣯⣩⣿⣿⣦⠀⢸⡄⢹⡇" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡁⢸⡄⠀⢿⢿⣿⡾⡿⢻⠀⠀⣏⠻⣏⣛⣡⠏⢀⡞⠀⠀⡇" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⠀⠳⣄⡈⠓⠶⣛⣡⠞⠠⡷⠈⠓⠚⠛⠒⠚⠙⠒⠦⢼⠇" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣤⡤⢞⡋⠉⠉⢡⡀⢀⣠⠟⠦⣄⡼⠃⠀⠀⢨⣍⣩⡟⠁" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠿⣞⢉⡥⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⢲⣴⡏⠙⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⢛⣴⣃⡀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠤⠖⢹⠁⠉⠁⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠋⢀⡏⠉⠉⠑⠒⠒⠉⠉⠉⠁⠀⠀⠀⢸⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⠀⢠⡾⠉⠀⠀⠀⢀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⠀⠀⢰⠏⠀⠀⠀⠀⢠⠞⠀⡀⠀⠀⠀⠀⠤⢤⡤⠤⠀⠀⠀⠀⣸⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠀⠀⣀⣤⡟⠀⠀⣀⡤⠞⠁⠀⠸⡇⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⢀⣴⠞⠋⢠⡟⠒⠋⠁⠀⠀⠀⠀⠀⢷⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⢠⡾⠁⠀⢠⡼⣇⠀⠀⠀⠀⣀⡤⠤⢤⣘⣇⣀⠤⠤⢤⣸⣄⡤⠤⠤⣀⡿⠀⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⢸⡇⠀⠀⠻⠤⠼⠧⠤⠤⠼⢧⣠⡀⡄⠈⡟⠀⣤⢠⡄⢸⡁⣠⠀⣆⡈⣳⠀⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠻⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⡗⠛⠒⠛⠒⠛⠛⠓⠛⠓⠛⠚⠛⠛⠋⠀⠀⠀⠀⠀" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "⠀⠀⠉⠛⠒⠶⠶⠶⠶⠶⠶⠾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    }
    
    if (Home->AsciiArt == 5) {
	    std::cout << "                                                   ████   ███                       █████   " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "                                                  ░░███  ░░░                       ░░███    " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << " █████████  ██████   ████████              ██████  ░███  ████   ██████  ████████   ███████  " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "░█░░░░███  ░░░░░███ ░░███░░███ ██████████ ███░░███ ░███ ░░███  ███░░███░░███░░███ ░░░███░   " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "░   ███░    ███████  ░███ ░███░░░░░░░░░░ ░███ ░░░  ░███  ░███ ░███████  ░███ ░███   ░███    " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "  ███░   █ ███░░███  ░███ ░███           ░███  ███ ░███  ░███ ░███░░░   ░███ ░███   ░███ ███" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << " █████████░░████████ ░███████            ░░██████  █████ █████░░██████  ████ █████  ░░█████ " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "░░░░░░░░░  ░░░░░░░░  ░███░░░              ░░░░░░  ░░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░    ░░░░░  " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "                     ░███                                                                   " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "                     █████                                                                  " << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(Home->AsciiArtSpeed));
	    std::cout << "                    ░░░░░                                                                   " << std::endl;
    }

    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "zap client - ver 0.3.1" << std::endl;
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //std::cout << "By Gerosity" << std::endl;
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "For Game Version v3.0.57.21" << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Initialize Overlay Window //
    if (!InitializeOverlayWindow()) return -1;

    // Theading //
    std::thread X11Thread(X11EventListener);
    X11Thread.detach();
    std::thread InputManagerThread(InputManager::run);
    InputManagerThread.detach();


    std::thread SuperGlideThread(SuperGlideThreadRun);
    SuperGlideThread.detach();

    // Initialize the whole process //
    try {
        for (int i = 0; i < 70; i++) 
            HumanPlayers->push_back(new Player(i, Myself));

        for (int i = 0; i < 15000; i++) 
            Dummies->push_back(new Player(i, Myself));
            
        GlowESP->Initialize();
        
        std::cout << "core initialized" << std::endl;
        std::cout << "-----------------------------" << std::endl;

        LoadConfig();
        LoadOverlaySave();
        // This is where the fun starts //
        OverlayWindow.Start(&UpdateCore, &RenderUI);
    }
    catch(...) {}

    StopThread = true;
    InputManager::StopThread = true;
    X11Thread.join();
    InputManagerThread.join();
    SuperGlideThread.join();
    return 0;
};
