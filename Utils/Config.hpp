#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "IniReader.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
#include "../Utils/HitboxType.hpp"
#include "../Utils/InputTypes.hpp"

constexpr char ConfigFile[] = "config.ini";

#define WriteSection(key) \
conf << "[" #key "]" << "\n";
#define WritePair(section, key) \
conf << #key " = " << Config::section::key << "\n";
#define WriteSectionEnd() conf << "\n";
#define WriteComment(msg) conf << "; " << msg << '\n';

#define ReadBool(section, key) \
Config::section::key = reader.GetBoolean(#section, #key, Config::section::key);
#define ReadFloat(section, key) \
Config::section::key = reader.GetFloat(#section, #key, Config::section::key);
#define ReadInt(section, key) \
Config::section::key = reader.GetInteger(#section, #key, Config::section::key);

namespace Config {
namespace Home {
int Layout = 1;
bool TeamGamemode = true;
int AsciiArt = 5; //change the starting ascii art. 0 = cat 1, 1 = shotgun, 2 = glock, 3 = racoon, 4 = cat 2,
int AsciiArtSpeed = 100; //Speed (in milliseconds) of the ascii art
int Style = 5;
int Color = 5;
int MenuX = 754;
int MenuY = 605;
bool ErrorLogging = false;
};

namespace Aimbot {
bool RCSEnabled = true;
bool Enabled = true;
int BindMethod = 0;
int AimBind = 56;
int ExtraBind = 57;
bool OnFire = true;
bool OnADS = false;
bool ClosestHitbox = false;
int HitBox = 2;
int AimbotMode = 0;

bool VisCheck = true;
bool TeamCheck = true;

bool PredictMovement = true;
bool PredictBulletDrop = true;
float Speed = 20;
float Smooth = 0.9;
float HipfireSmooth = 0.9;
float ADSSmooth = 0.9;
float SmoothDistance = 100;
float Deadzone = 0.5;
int Delay = 10;
float FOV = 10;
float ZoomScale = 3.0;
float MinDistance = 1;
float HipfireDistance = 200;
float ZoomDistance = 200;

//Weapons
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

//Advanced Keybinds
int P2020AimBind = 56;
int P2020ExtraBind = 0;
int RE45AimBind = 56;
int RE45ExtraBind = 0;
int AlternatorAimBind = 56;
int AlternatorExtraBind = 0;
int R99AimBind = 56;
int R99ExtraBind = 0;
int R301AimBind = 56;
int R301ExtraBind = 0;
int SpitfireAimBind = 56;
int SpitfireExtraBind = 0;
int G7AimBind = 56;
int G7ExtraBind = 57;
int FlatlineAimBind = 56;
int FlatlineExtraBind = 0;
int HemlockAimBind = 56;
int HemlockExtraBind = 0;
int RepeaterAimBind = 56;
int RepeaterExtraBind = 57;
int RampageAimBind = 56;
int RampageExtraBind = 0;
int CARSMGAimBind = 56;
int CARSMGExtraBind = 0;
int HavocAimBind = 56;
int HavocExtraBind = 0;
int DevotionAimBind = 56;
int DevotionExtraBind = 0;
int LSTARAimBind = 56;
int LSTARExtraBind = 0;
int TripleTakeAimBind = 56;
int TripleTakeExtraBind = 57;
int VoltAimBind = 56;
int VoltExtraBind = 0;
int NemesisAimBind = 56;
int NemesisExtraBind = 0;
int MozambiqueAimBind = 56;
int MozambiqueExtraBind = 57;
int EVA8AimBind = 56;
int EVA8ExtraBind = 57;
int PeacekeeperAimBind = 56;
int PeacekeeperExtraBind = 57;
int MastiffAimBind = 56;
int MastiffExtraBind = 57;
int LongbowAimBind = 56;
int LongbowExtraBind = 57;
int ChargeRifleAimBind = 56;
int ChargeRifleExtraBind = 57;
int SentinelAimBind = 56;
int SentinelExtraBind = 57;
int WingmanAimBind = 56;
int WingmanExtraBind = 0;
int ProwlerAimBind = 56;
int ProwlerExtraBind = 0;
int BocekAimBind = 56;
int BocekExtraBind = 57;
int KraberAimBind = 56;
int KraberExtraBind = 57;
int ThrowingKnifeAimBind = 56;
int ThrowingKnifeExtraBind = 0;

//AdvancedHitbox
int P2020HitBox = 2;
int RE45HitBox = 2;
int AlternatorHitBox = 2;
int R99HitBox = 2;
int R301HitBox = 2;
int SpitfireHitBox = 2;
int G7HitBox = 2;
int FlatlineHitBox = 2;
int HemlockHitBox = 2;
int RepeaterHitBox = 2;
int RampageHitBox = 2;
int CARSMGHitBox = 2;
int HavocHitBox = 2;
int DevotionHitBox = 2;
int LSTARHitBox = 2;
int TripleTakeHitBox = 2;
int VoltHitBox = 2;
int NemesisHitBox = 2;
int MozambiqueHitBox = 2;
int EVA8HitBox = 2;
int MastiffHitBox = 2;
int PeacekeeperHitBox = 2;
int LongbowHitBox = 2;
int ChargeRifleHitBox = 2;
int SentinelHitBox = 2;
int WingmanHitBox = 2;
int ProwlerHitBox = 2;
int BocekHitBox = 2;
int KraberHitBox = 2;
int ThrowingKnifeHitBox = 2;

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

};

namespace RCS {
bool RCSEnabled = true;
bool OnADS = true;
float PitchPower = 4;
float YawPower = 4;

//Weapons
//Light
bool P2020 = false;
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
bool Wingman = true; //Emotional damage!
bool Prowler = true;
bool Kraber = false;

//---------------Advanced---------------//
bool AdvancedRCS = false;
float AdvancedPitchPower = 10;
float AdvancedYawPower = 10;

//Weapons
//Light
float P2020Pitch = 10;
float P2020Yaw = 10;
float RE45Pitch = 10;
float RE45Yaw = 10;
float AlternatorPitch = 10;
float AlternatorYaw = 10;
float R99Pitch = 10;
float R99Yaw = 10;
float R301Pitch = 10;
float R301Yaw = 10;
float SpitfirePitch = 10;
float SpitfireYaw = 10;
float G7Pitch = 10;
float G7Yaw = 10;
//Heavy
float FlatlinePitch = 10;
float FlatlineYaw = 10;
float HemlockPitch = 10;
float HemlockYaw = 10;
float RepeaterPitch = 10;
float RepeaterYaw = 10;
float RampagePitch = 10;
float RampageYaw = 10;
float CARSMGPitch = 10;
float CARSMGYaw = 10;
//Energy
float HavocPitch = 10;
float HavocYaw = 10;
float DevotionPitch = 10;
float DevotionYaw = 10;
float LSTARPitch = 10;
float LSTARYaw = 10;
float TripleTakePitch = 10;
float TripleTakeYaw = 10;
float VoltPitch = 10;
float VoltYaw = 10;
float NemesisPitch = 10;
float NemesisYaw = 10;
//Shotguns
float MozambiquePitch = 10;
float MozambiqueYaw = 10;
float EVA8Pitch = 10;
float EVA8Yaw = 10;
float PeacekeeperPitch = 10;
float PeacekeeperYaw = 10;
float MastiffPitch = 10;
float MastiffYaw = 10;
//Snipers
float LongbowPitch = 10;
float LongbowYaw = 10;
float ChargeRiflePitch = 10;
float ChargeRifleYaw = 10;
float SentinelPitch = 10;
float SentinelYaw = 10;
//Legendary
float WingmanPitch = 10;
float WingmanYaw = 10;
float ProwlerPitch = 10;
float ProwlerYaw = 10;
float KraberPitch = 10;
float KraberYaw = 10;
};

namespace Triggerbot {
bool Enabled = true;
bool OnADS = true;
bool HipfireShotguns = false;
float Range = 200;

//Weapons
//Light
bool P2020 = false;
bool RE45 = false;
bool Alternator = false;
bool R99 = false;
bool R301 = false;
bool Spitfire = false;
bool G7 = false;
//Heavy
bool Flatline = false;
bool Hemlock = false;
bool Repeater = false;
bool Rampage = false;
bool CARSMG = false;
//Energy
bool Havoc = false;
bool Devotion = false;
bool LSTAR = false;
bool TripleTake = false;
bool Volt = false;
bool Nemesis = false;
//Shotgun
bool Mozambique = false;
bool EVA8 = false;
bool Peacekeeper = false;
bool Mastiff = false;
//Snipers
bool Longbow = false;
bool ChargeRifle = false;
bool Sentinel = false;
//Legendary
bool Wingman = false; //Emotional damage!
bool Prowler = false;
bool Bocek = false;
bool Kraber = false;
bool Knife = false;
};

namespace Glow {
// Glow
bool GlowEnabled = false; //OLD GLOW
bool NewGlow = true;
float GlowMaxDistance = 200;
int GlowColorMode = 0;
int GlowColorShieldMode = 0;
int GlowRadius = 64;
int InsideFunction = 2; //Leave
int OutlineFunction = 125; //Leave
int BodyStyle = 13;
int OutlineStyle = 1;
bool ItemGlow = true;
//Colors
float InvisibleGlowColorR = 0.999;
float InvisibleGlowColorG = 0;
float InvisibleGlowColorB = 0;
float VisibleGlowColorR = 0;
float VisibleGlowColorG = 0.999;
float VisibleGlowColorB = 0;
float LowGlowColorR = 0.99;
float LowGlowColorG = 0.99;
float LowGlowColorB = 0;
float RedShieldColorR = 0.99;
float RedShieldColorG = 0;
float RedShieldColorB = 0;
float PurpleShieldColorR = 0.5;
float PurpleShieldColorG = 0;
float PurpleShieldColorB = 0.5;
float BlueShieldColorR = 0;
float BlueShieldColorG = 0.5;
float BlueShieldColorB = 0.999;
float GreyShieldColorR = 0.540;
float GreyShieldColorG = 0.545;
float GreyShieldColorB = 0.545;
};

namespace Sense {
//Drawings
bool VisibilityCheck = false;
bool DrawBoxes = true;
int BoxType = 0;
int BoxStyle = 0;
float BoxThickness = 1.0;

bool Skeleton = true;
float SkeletonThickness = 1.0;

bool HealthBar = true;
bool ShieldBar = true;
bool drawlvl = true;

int BarMode = 2;
int BarStyle = 0;
int BarColorMode = 0;
bool BarBackground = false;
float BarThickness = 1.0f;
float BarThickness2 = 0.05f;
float BarHeight = 5.0f;
float BarWidth = 60.0f;

float ESPMaxDistance = 200;
bool ShowNear = false;
bool DrawSeer = false;
bool DrawStatus = true;
bool DrawWeapon = false;
int WeaponColorType = 1;
bool ShowLegend = false;
bool ShowMaxStatusValues = true;

bool DrawDistance = true;
bool DrawFOVCircle = true;
bool DrawFilledFOVCircle = false;
float FOVThickness = 1.0;
bool DrawNames = true;
int TracerPos = 0;
int TracerBone = 0;
bool DrawTracers = true;
float TracerThickness = 2.0;
bool ShowSpectators = true;
bool DrawCrosshair = true;
float CrosshairSize = 7.0;
float CrosshairThickness = 1.0;

//Settings
float GameFOV = 120;
bool ShowTeam = false;
bool TeamNames = false;

//Player Info Positions (0-2 = Top, 3-4 = bottom)
int LegendPosition = 2;
int NamePosition = 3;
int DistancePosition = 4;
int StatusPosition = 0;
int WeaponPosition = 1;
};

namespace Radar {
bool MiniMap = false;
float MiniMapRange = 100;
int MiniMapScaleX = 218;
int MiniMapScaleY = 218;
int MiniMapDotSize = 5;
int MiniMapBlackBGSize = 0;
bool MiniMapGuides = false;

bool BigMap = false;
};

namespace Watermark {
bool Watermark = true;
int WatermarkPosition = 0;
bool Name = true;
bool ProcessingSpeed = true;
bool Spectators = true;
};

namespace Misc {
bool SkinChanger = false;
bool AutoGrapple = false;
bool SuperGlide = true;
//Weapon IDs
//Light
int SkinP2020 = 1;
int SkinRE45 = 1;
int SkinALTERNATOR = 1;
int SkinR99 = 1;
int SkinR301 = 1;
int SkinSPITFIRE = 1;
int SkinG7 = 1;

//Heavy
int SkinFLATLINE = 1;
int SkinHEMLOCK = 1;
int SkinREPEATER = 1;
int SkinRAMPAGE = 1;
int SkinCAR = 1;

//Energy
int SkinHAVOC = 1;
int SkinDEVOTION = 1;
int SkinLSTAR = 1;
int SkinTRIPLETAKE = 1;
int SkinVOLT = 1;
int SkinNEMESIS = 1;

//Shotgun
int SkinMOZAMBIQUE = 1;
int SkinEVA8 = 1;
int SkinPEACEKEEPER = 1;
int SkinMASTIFF = 1;

//Snipers
int SkinLONGBOW = 1;
int SkinCHARGE_RIFLE = 1;
int SkinSENTINEL = 1;

//Legendary
int SkinWINGMAN = 1;
int SkinPROWLER = 1;
int SkinBOCEK = 1;
int SkinKRABER = 1;
};

namespace Colors {
int ColorMode = 0; //0 = Simple, 1 = Advanced
//Simple
float InvisibleColorR = 0.99;
float InvisibleColorG = 0;
float InvisibleColorB = 0;
float InvisibleColorA = 0.99;
float VisibleColorR = 0;
float VisibleColorG = 0.99;
float VisibleColorB = 0;
float VisibleColorA = 0.99;
//Advanced
float InvisibleBoxColorR = 0.99;
float InvisibleBoxColorG = 0;
float InvisibleBoxColorB = 0;
float InvisibleBoxColorA = 0.99;
float VisibleBoxColorR = 0;
float VisibleBoxColorG = 0.99;
float VisibleBoxColorB = 0;
float VisibleBoxColorA = 0.99;
float InvisibleFilledBoxColorR = 0;
float InvisibleFilledBoxColorG = 0;
float InvisibleFilledBoxColorB = 0;
float InvisibleFilledBoxColorA = 0.11;
float VisibleFilledBoxColorR = 0;
float VisibleFilledBoxColorG = 0;
float VisibleFilledBoxColorB = 0;
float VisibleFilledBoxColorA = 0.11;
float InvisibleTracerColorR = 0.99;
float InvisibleTracerColorG = 0;
float InvisibleTracerColorB = 0;
float InvisibleTracerColorA = 0.99;
float VisibleTracerColorR = 0;
float VisibleTracerColorG = 0.99;
float VisibleTracerColorB = 0;
float VisibleTracerColorA = 0.99;
float InvisibleSkeletonColorR = 0.99;
float InvisibleSkeletonColorG = 0.99;
float InvisibleSkeletonColorB = 0.99;
float InvisibleSkeletonColorA = 0.99;
float VisibleSkeletonColorR = 0.99;
float VisibleSkeletonColorG = 0.99;
float VisibleSkeletonColorB = 0.99;
float VisibleSkeletonColorA = 0.99;
float InvisibleNameColorR = 0.99;
float InvisibleNameColorG = 0.99;
float InvisibleNameColorB = 0.99;
float InvisibleNameColorA = 0.99;
float VisibleNameColorR = 0.99;
float VisibleNameColorG = 0.99;
float VisibleNameColorB = 0.99;
float VisibleNameColorA = 0.99;
float InvisibleDistanceColorR = 0.99;
float InvisibleDistanceColorG = 0.99;
float InvisibleDistanceColorB = 0.99;
float InvisibleDistanceColorA = 0.99;
float VisibleDistanceColorR = 0.99;
float VisibleDistanceColorG = 0.99;
float VisibleDistanceColorB = 0.99;
float VisibleDistanceColorA = 0.99;
float InvisibleLegendColorR = 0.99;
float InvisibleLegendColorG = 0.99;
float InvisibleLegendColorB = 0.99;
float InvisibleLegendColorA = 0.99;
float VisibleLegendColorR = 0.99;
float VisibleLegendColorG = 0.99;
float VisibleLegendColorB = 0.99;
float VisibleLegendColorA = 0.99;
float FOVColorR = 0.99;
float FOVColorG = 0.99;
float FOVColorB = 0.99;
float FOVColorA = 0.99;
float FilledFOVColorR = 0;
float FilledFOVColorG = 0;
float FilledFOVColorB = 0;
float FilledFOVColorA = 0.11;
float VisibleWeaponColorR = 0.99;
float VisibleWeaponColorG = 0.99;
float VisibleWeaponColorB = 0.99;
float VisibleWeaponColorA = 0.99;
float InvisibleWeaponColorR = 0.99;
float InvisibleWeaponColorG = 0.99;
float InvisibleWeaponColorB = 0.99;
float InvisibleWeaponColorA = 0.99;
float NearColorR = 0.99;
float NearColorG = 0.99;
float NearColorB = 0.99;
float NearColorA = 0.99;
float TeamColorR = 0;
float TeamColorG = 0.99;
float TeamColorB = 0.99;
float TeamColorA = 0.99;
float TeamNameColorR = 0.99;
float TeamNameColorG = 0.99;
float TeamNameColorB = 0.99;
float TeamNameColorA = 0.99;
float CrosshairColorR = 0.99;
float CrosshairColorG = 0.99;
float CrosshairColorB = 0.99;
float CrosshairColorA = 0.99;
//WeaponESP Colors
float LightWeaponColorR = 0.990;
float LightWeaponColorG = 0.768;
float LightWeaponColorB = 0.039;
float LightWeaponColorA = 0.99;
float HeavyWeaponColorR = 0.00990;
float HeavyWeaponColorG = 0.990;
float HeavyWeaponColorB = 0.761;
float HeavyWeaponColorA = 0.99;
float EnergyWeaponColorR = 0;
float EnergyWeaponColorG = 0.99;
float EnergyWeaponColorB = 0;
float EnergyWeaponColorA = 0.99;
float ShotgunWeaponColorR = 0.99;
float ShotgunWeaponColorG = 0;
float ShotgunWeaponColorB = 0;
float ShotgunWeaponColorA = 0.99;
float SniperWeaponColorR = 0.00990;
float SniperWeaponColorG = 0.337;
float SniperWeaponColorB = 0.990;
float SniperWeaponColorA = 0.99;
float LegendaryWeaponColorR = 0.99;
float LegendaryWeaponColorG = 0.530;
float LegendaryWeaponColorB = 0.945;
float LegendaryWeaponColorA = 0.99;
float MeleeWeaponColorR = 0.99;
float MeleeWeaponColorG = 0.99;
float MeleeWeaponColorB = 0.99;
float MeleeWeaponColorA = 0.99;
float ThrowableWeaponColorR = 0.990;
float ThrowableWeaponColorG = 0.974;
float ThrowableWeaponColorB = 0.0495;
float ThrowableWeaponColorA = 0.99;
};
};

void UpdateConfig() {
    std::ofstream conf(ConfigFile);
    if (conf.is_open()) {
        WriteSection(Aimbot);
        WritePair(Aimbot, RCSEnabled);
        WritePair(Aimbot, Enabled);
        WritePair(Aimbot, AimbotMode);
        WritePair(Aimbot, ClosestHitbox);
        WritePair(Aimbot, BindMethod);
        WritePair(Aimbot, OnFire);
        WritePair(Aimbot, OnADS);
        WritePair(Aimbot, AimBind);
        WritePair(Aimbot, ExtraBind);
        WritePair(Aimbot, HitBox);
        WritePair(Aimbot, VisCheck);
        WritePair(Aimbot, TeamCheck);
        WritePair(Aimbot, PredictMovement);
        WritePair(Aimbot, PredictBulletDrop);
        WritePair(Aimbot, Speed);
        WritePair(Aimbot, Smooth);
        WritePair(Aimbot, HipfireSmooth);
        WritePair(Aimbot, ADSSmooth);
        WritePair(Aimbot, Delay);
        WritePair(Aimbot, SmoothDistance);
        WritePair(Aimbot, Deadzone);
        WritePair(Aimbot, FOV);
        WritePair(Aimbot, ZoomScale);
        WritePair(Aimbot, MinDistance);
        WritePair(Aimbot, HipfireDistance);
        WritePair(Aimbot, ZoomDistance);
        //Weapons
        //Light
        WritePair(Aimbot, P2020);
        WritePair(Aimbot, RE45);
        WritePair(Aimbot, Alternator);
        WritePair(Aimbot, R99);
        WritePair(Aimbot, R301);
        WritePair(Aimbot, Spitfire);
        WritePair(Aimbot, G7);
        //Heavy
        WritePair(Aimbot, Flatline);
        WritePair(Aimbot, Hemlock);
        WritePair(Aimbot, Repeater);
        WritePair(Aimbot, Rampage);
        WritePair(Aimbot, CARSMG);
        //Energy
        WritePair(Aimbot, Havoc);
        WritePair(Aimbot, Devotion);
        WritePair(Aimbot, LSTAR);
        WritePair(Aimbot, TripleTake);
        WritePair(Aimbot, Volt);
        WritePair(Aimbot, Nemesis);
        //Shotgun
        WritePair(Aimbot, Mozambique);
        WritePair(Aimbot, EVA8);
        WritePair(Aimbot, Peacekeeper);
        WritePair(Aimbot, Mastiff);
        //Snipers
        WritePair(Aimbot, Longbow);
        WritePair(Aimbot, ChargeRifle);
        WritePair(Aimbot, Sentinel);
        //Legendary
        WritePair(Aimbot, Wingman);
        WritePair(Aimbot, Prowler);
        WritePair(Aimbot, Bocek);
        WritePair(Aimbot, Kraber);
        WritePair(Aimbot, Knife);

        //---------------Advanced---------------//
        WritePair(Aimbot, AdvancedAim);
        //AimbotMode 0 - Cubic Bezier (xap-client)
        WritePair(Aimbot, AdvancedClosestHitbox);
        WritePair(Aimbot, AdvancedHitbox);
        WritePair(Aimbot, AdvancedSpeed);
        WritePair(Aimbot, AdvancedSmooth);
        WritePair(Aimbot, AdvancedHipfireSmooth);
        WritePair(Aimbot, AdvancedADSSmooth);
        //AimbotMode 1 - Grinder
        WritePair(Aimbot, AdvancedHipfireSmooth1);
        WritePair(Aimbot, AdvancedADSSmooth1);
        WritePair(Aimbot, AdvancedExtraSmooth1);
        WritePair(Aimbot, AdvancedFOV1);
        WritePair(Aimbot, AdvancedDeadzone);
        WritePair(Aimbot, AdvancedMinDistance1);
        WritePair(Aimbot, AdvancedMaxDistance1);

        //Aimbot Advanced - Weapons && OnADS && OnFire
        WritePair(Aimbot, P2020Fire);
        WritePair(Aimbot, P2020ADS);
        WritePair(Aimbot, RE45Fire);
        WritePair(Aimbot, RE45ADS);
        WritePair(Aimbot, AlternatorFire);
        WritePair(Aimbot, AlternatorADS);
        WritePair(Aimbot, R99Fire);
        WritePair(Aimbot, R99ADS);
        WritePair(Aimbot, R301Fire);
        WritePair(Aimbot, R301ADS);
        WritePair(Aimbot, SpitfireFire);
        WritePair(Aimbot, SpitfireADS);
        WritePair(Aimbot, G7Fire);
        WritePair(Aimbot, G7ADS);
        WritePair(Aimbot, FlatlineFire);
        WritePair(Aimbot, FlatlineADS);
        WritePair(Aimbot, HemlockFire);
        WritePair(Aimbot, HemlockADS);
        WritePair(Aimbot, RepeaterFire);
        WritePair(Aimbot, RepeaterADS);
        WritePair(Aimbot, RampageFire);
        WritePair(Aimbot, RampageADS);
        WritePair(Aimbot, CARSMGFire);
        WritePair(Aimbot, CARSMGADS);
        WritePair(Aimbot, HavocFire);
        WritePair(Aimbot, HavocADS);
        WritePair(Aimbot, DevotionFire);
        WritePair(Aimbot, DevotionADS);
        WritePair(Aimbot, LSTARFire);
        WritePair(Aimbot, LSTARADS);
        WritePair(Aimbot, TripleTakeFire);
        WritePair(Aimbot, TripleTakeADS);
        WritePair(Aimbot, VoltFire);
        WritePair(Aimbot, VoltADS);
        WritePair(Aimbot, NemesisFire);
        WritePair(Aimbot, NemesisADS);
        WritePair(Aimbot, MozambiqueFire);
        WritePair(Aimbot, MozambiqueADS);
        WritePair(Aimbot, EVA8Fire);
        WritePair(Aimbot, EVA8ADS);
        WritePair(Aimbot, PeacekeeperFire);
        WritePair(Aimbot, PeacekeeperADS);
        WritePair(Aimbot, MastiffFire);
        WritePair(Aimbot, MastiffADS);
        WritePair(Aimbot, WingmanFire);
        WritePair(Aimbot, WingmanADS);
        WritePair(Aimbot, BocekFire);
        WritePair(Aimbot, BocekADS);
        WritePair(Aimbot, ProwlerFire);
        WritePair(Aimbot, ProwlerADS);
        WritePair(Aimbot, KraberFire);
        WritePair(Aimbot, KraberADS);
        WritePair(Aimbot, ThrowingKnifeFire);
        WritePair(Aimbot, ThrowingKnifeADS);

        //Advanced Keybinds
        WritePair(Aimbot, P2020AimBind);
        WritePair(Aimbot, P2020ExtraBind);
        WritePair(Aimbot, RE45AimBind);
        WritePair(Aimbot, RE45ExtraBind);
        WritePair(Aimbot, AlternatorAimBind);
        WritePair(Aimbot, AlternatorExtraBind);
        WritePair(Aimbot, R99AimBind);
        WritePair(Aimbot, R99ExtraBind);
        WritePair(Aimbot, R301AimBind);
        WritePair(Aimbot, R301ExtraBind);
        WritePair(Aimbot, SpitfireAimBind);
        WritePair(Aimbot, SpitfireExtraBind);
        WritePair(Aimbot, G7AimBind);
        WritePair(Aimbot, G7ExtraBind);
        WritePair(Aimbot, FlatlineAimBind);
        WritePair(Aimbot, FlatlineExtraBind);
        WritePair(Aimbot, HemlockAimBind);
        WritePair(Aimbot, HemlockExtraBind);
        WritePair(Aimbot, RepeaterAimBind);
        WritePair(Aimbot, RepeaterExtraBind);
        WritePair(Aimbot, RampageAimBind);
        WritePair(Aimbot, RampageExtraBind);
        WritePair(Aimbot, CARSMGAimBind);
        WritePair(Aimbot, CARSMGExtraBind);
        WritePair(Aimbot, HavocAimBind);
        WritePair(Aimbot, HavocExtraBind);
        WritePair(Aimbot, DevotionAimBind);
        WritePair(Aimbot, DevotionExtraBind);
        WritePair(Aimbot, LSTARAimBind);
        WritePair(Aimbot, LSTARExtraBind);
        WritePair(Aimbot, TripleTakeAimBind);
        WritePair(Aimbot, TripleTakeExtraBind);
        WritePair(Aimbot, VoltAimBind);
        WritePair(Aimbot, VoltExtraBind);
        WritePair(Aimbot, NemesisAimBind);
        WritePair(Aimbot, NemesisExtraBind);
        WritePair(Aimbot, MozambiqueAimBind);
        WritePair(Aimbot, MozambiqueExtraBind);
        WritePair(Aimbot, EVA8AimBind);
        WritePair(Aimbot, EVA8ExtraBind);
        WritePair(Aimbot, PeacekeeperAimBind);
        WritePair(Aimbot, PeacekeeperExtraBind);
        WritePair(Aimbot, MastiffAimBind);
        WritePair(Aimbot, MastiffExtraBind);
        WritePair(Aimbot, LongbowAimBind);
        WritePair(Aimbot, LongbowExtraBind);
        WritePair(Aimbot, ChargeRifleAimBind);
        WritePair(Aimbot, ChargeRifleExtraBind);
        WritePair(Aimbot, SentinelAimBind);
        WritePair(Aimbot, SentinelExtraBind);
        WritePair(Aimbot, WingmanAimBind);
        WritePair(Aimbot, WingmanExtraBind);
        WritePair(Aimbot, ProwlerAimBind);
        WritePair(Aimbot, ProwlerExtraBind);
        WritePair(Aimbot, BocekAimBind);
        WritePair(Aimbot, BocekExtraBind);
        WritePair(Aimbot, KraberAimBind);
        WritePair(Aimbot, KraberExtraBind);
        WritePair(Aimbot, ThrowingKnifeAimBind);
        WritePair(Aimbot, ThrowingKnifeExtraBind);

        //Light
        WritePair(Aimbot, P2020ClosestHitbox);
        WritePair(Aimbot, P2020Hitbox);
        WritePair(Aimbot, P2020Speed);
        WritePair(Aimbot, P2020HipfireSmooth);
        WritePair(Aimbot, P2020ADSSmooth);

        WritePair(Aimbot, RE45ClosestHitbox);
        WritePair(Aimbot, RE45Hitbox);
        WritePair(Aimbot, RE45Speed);
        WritePair(Aimbot, RE45HipfireSmooth);
        WritePair(Aimbot, RE45ADSSmooth);

        WritePair(Aimbot, AlternatorClosestHitbox);
        WritePair(Aimbot, AlternatorHitbox);
        WritePair(Aimbot, AlternatorSpeed);
        WritePair(Aimbot, AlternatorHipfireSmooth);
        WritePair(Aimbot, AlternatorADSSmooth);

        WritePair(Aimbot, R99ClosestHitbox);
        WritePair(Aimbot, R99Hitbox);
        WritePair(Aimbot, R99Speed);
        WritePair(Aimbot, R99HipfireSmooth);
        WritePair(Aimbot, R99ADSSmooth);

        WritePair(Aimbot, R301ClosestHitbox);
        WritePair(Aimbot, R301Hitbox);
        WritePair(Aimbot, R301Speed);
        WritePair(Aimbot, R301HipfireSmooth);
        WritePair(Aimbot, R301ADSSmooth);

        WritePair(Aimbot, SpitfireClosestHitbox);
        WritePair(Aimbot, SpitfireHitbox);
        WritePair(Aimbot, SpitfireSpeed);
        WritePair(Aimbot, SpitfireHipfireSmooth);
        WritePair(Aimbot, SpitfireADSSmooth);

        WritePair(Aimbot, G7ClosestHitbox);
        WritePair(Aimbot, G7Hitbox);
        WritePair(Aimbot, G7Speed);
        WritePair(Aimbot, G7HipfireSmooth);
        WritePair(Aimbot, G7ADSSmooth);

        //Heavy
        WritePair(Aimbot, FlatlineClosestHitbox);
        WritePair(Aimbot, FlatlineHitbox);
        WritePair(Aimbot, FlatlineSpeed);
        WritePair(Aimbot, FlatlineHipfireSmooth);
        WritePair(Aimbot, FlatlineADSSmooth);

        WritePair(Aimbot, HemlockClosestHitbox);
        WritePair(Aimbot, HemlockHitbox);
        WritePair(Aimbot, HemlockSpeed);
        WritePair(Aimbot, HemlockHipfireSmooth);
        WritePair(Aimbot, HemlockADSSmooth);

        WritePair(Aimbot, RepeaterClosestHitbox);
        WritePair(Aimbot, RepeaterHitbox);
        WritePair(Aimbot, RepeaterSpeed);
        WritePair(Aimbot, RepeaterHipfireSmooth);
        WritePair(Aimbot, RepeaterADSSmooth);

        WritePair(Aimbot, RampageClosestHitbox);
        WritePair(Aimbot, RampageHitbox);
        WritePair(Aimbot, RampageSpeed);
        WritePair(Aimbot, RampageHipfireSmooth);
        WritePair(Aimbot, RampageADSSmooth);

        WritePair(Aimbot, CARSMGClosestHitbox);
        WritePair(Aimbot, CARSMGHitbox);
        WritePair(Aimbot, CARSMGSpeed);
        WritePair(Aimbot, CARSMGHipfireSmooth);
        WritePair(Aimbot, CARSMGADSSmooth);

        //Energy
        WritePair(Aimbot, HavocClosestHitbox);
        WritePair(Aimbot, HavocHitbox);
        WritePair(Aimbot, HavocSpeed);
        WritePair(Aimbot, HavocHipfireSmooth);
        WritePair(Aimbot, HavocADSSmooth);

        WritePair(Aimbot, DevotionClosestHitbox);
        WritePair(Aimbot, DevotionHitbox);
        WritePair(Aimbot, DevotionSpeed);
        WritePair(Aimbot, DevotionHipfireSmooth);
        WritePair(Aimbot, DevotionADSSmooth);

        WritePair(Aimbot, LSTARClosestHitbox);
        WritePair(Aimbot, LSTARHitbox);
        WritePair(Aimbot, LSTARSpeed);
        WritePair(Aimbot, LSTARHipfireSmooth);
        WritePair(Aimbot, LSTARADSSmooth);

        WritePair(Aimbot, TripleTakeClosestHitbox);
        WritePair(Aimbot, TripleTakeHitbox);
        WritePair(Aimbot, TripleTakeSpeed);
        WritePair(Aimbot, TripleTakeHipfireSmooth);
        WritePair(Aimbot, TripleTakeADSSmooth);

        WritePair(Aimbot, VoltClosestHitbox);
        WritePair(Aimbot, VoltHitbox);
        WritePair(Aimbot, VoltSpeed);
        WritePair(Aimbot, VoltHipfireSmooth);
        WritePair(Aimbot, VoltADSSmooth);

        WritePair(Aimbot, NemesisClosestHitbox);
        WritePair(Aimbot, NemesisHitbox);
        WritePair(Aimbot, NemesisSpeed);
        WritePair(Aimbot, NemesisHipfireSmooth);
        WritePair(Aimbot, NemesisADSSmooth);

        //Shotgun
        WritePair(Aimbot, MozambiqueClosestHitbox);
        WritePair(Aimbot, MozambiqueHitbox);
        WritePair(Aimbot, MozambiqueSpeed);
        WritePair(Aimbot, MozambiqueHipfireSmooth);
        WritePair(Aimbot, MozambiqueADSSmooth);

        WritePair(Aimbot, EVA8ClosestHitbox);
        WritePair(Aimbot, EVA8Hitbox);
        WritePair(Aimbot, EVA8Speed);
        WritePair(Aimbot, EVA8HipfireSmooth);
        WritePair(Aimbot, EVA8ADSSmooth);

        WritePair(Aimbot, PeacekeeperClosestHitbox);
        WritePair(Aimbot, PeacekeeperHitbox);
        WritePair(Aimbot, PeacekeeperSpeed);
        WritePair(Aimbot, PeacekeeperHipfireSmooth);
        WritePair(Aimbot, PeacekeeperADSSmooth);

        WritePair(Aimbot, MastiffClosestHitbox);
        WritePair(Aimbot, MastiffHitbox);
        WritePair(Aimbot, MastiffSpeed);
        WritePair(Aimbot, MastiffHipfireSmooth);
        WritePair(Aimbot, MastiffADSSmooth);

        //Snipers
        WritePair(Aimbot, LongbowClosestHitbox);
        WritePair(Aimbot, LongbowHitbox);
        WritePair(Aimbot, LongbowSpeed);
        WritePair(Aimbot, LongbowHipfireSmooth);
        WritePair(Aimbot, LongbowADSSmooth);

        WritePair(Aimbot, ChargeRifleClosestHitbox);
        WritePair(Aimbot, ChargeRifleHitbox);
        WritePair(Aimbot, ChargeRifleSpeed);
        WritePair(Aimbot, ChargeRifleHipfireSmooth);
        WritePair(Aimbot, ChargeRifleADSSmooth);

        WritePair(Aimbot, SentinelClosestHitbox);
        WritePair(Aimbot, SentinelHitbox);
        WritePair(Aimbot, SentinelSpeed);
        WritePair(Aimbot, SentinelHipfireSmooth);
        WritePair(Aimbot, SentinelADSSmooth);

        //Legendary
        WritePair(Aimbot, WingmanClosestHitbox);
        WritePair(Aimbot, WingmanHitbox);
        WritePair(Aimbot, WingmanSpeed);
        WritePair(Aimbot, WingmanHipfireSmooth);
        WritePair(Aimbot, WingmanADSSmooth);

        WritePair(Aimbot, ProwlerClosestHitbox);
        WritePair(Aimbot, ProwlerHitbox);
        WritePair(Aimbot, ProwlerSpeed);
        WritePair(Aimbot, ProwlerHipfireSmooth);
        WritePair(Aimbot, ProwlerADSSmooth);

        WritePair(Aimbot, BocekClosestHitbox);
        WritePair(Aimbot, BocekHitbox);
        WritePair(Aimbot, BocekSpeed);
        WritePair(Aimbot, BocekHipfireSmooth);
        WritePair(Aimbot, BocekADSSmooth);

        WritePair(Aimbot, KraberClosestHitbox);
        WritePair(Aimbot, KraberHitbox);
        WritePair(Aimbot, KraberSpeed);
        WritePair(Aimbot, KraberHipfireSmooth);
        WritePair(Aimbot, KraberADSSmooth);

        WritePair(Aimbot, ThrowingKnifeClosestHitbox);
        WritePair(Aimbot, ThrowingKnifeHitbox);
        WritePair(Aimbot, ThrowingKnifeSpeed);
        WritePair(Aimbot, ThrowingKnifeHipfireSmooth);
        WritePair(Aimbot, ThrowingKnifeADSSmooth);


        //Aimbot Mode 1 - Weapons
        //Light
        WritePair(Aimbot, P2020HipfireSmooth1);
        WritePair(Aimbot, P2020ADSSmooth1);
        WritePair(Aimbot, P2020ExtraSmooth1);
        WritePair(Aimbot, P2020Deadzone);
        WritePair(Aimbot, P2020FOV1);
        WritePair(Aimbot, P2020MinDistance1);
        WritePair(Aimbot, P2020MaxDistance1);
        WritePair(Aimbot, RE45HipfireSmooth1);
        WritePair(Aimbot, RE45ADSSmooth1);
        WritePair(Aimbot, RE45ExtraSmooth1);
        WritePair(Aimbot, RE45Deadzone);
        WritePair(Aimbot, RE45FOV1);
        WritePair(Aimbot, RE45MinDistance1);
        WritePair(Aimbot, RE45MaxDistance1);
        WritePair(Aimbot, AlternatorHipfireSmooth1);
        WritePair(Aimbot, AlternatorADSSmooth1);
        WritePair(Aimbot, AlternatorExtraSmooth1);
        WritePair(Aimbot, AlternatorDeadzone);
        WritePair(Aimbot, AlternatorFOV1);
        WritePair(Aimbot, AlternatorMinDistance1);
        WritePair(Aimbot, AlternatorMaxDistance1);
        WritePair(Aimbot, R99HipfireSmooth1);
        WritePair(Aimbot, R99ADSSmooth1);
        WritePair(Aimbot, R99ExtraSmooth1);
        WritePair(Aimbot, R99Deadzone);
        WritePair(Aimbot, R99FOV1);
        WritePair(Aimbot, R99MinDistance1);
        WritePair(Aimbot, R99MaxDistance1);
        WritePair(Aimbot, R301HipfireSmooth1);
        WritePair(Aimbot, R301ADSSmooth1);
        WritePair(Aimbot, R301ExtraSmooth1);
        WritePair(Aimbot, R301Deadzone);
        WritePair(Aimbot, R301FOV1);
        WritePair(Aimbot, R301MinDistance1);
        WritePair(Aimbot, R301MaxDistance1);
        WritePair(Aimbot, SpitfireHipfireSmooth1);
        WritePair(Aimbot, SpitfireADSSmooth1);
        WritePair(Aimbot, SpitfireExtraSmooth1);
        WritePair(Aimbot, SpitfireDeadzone);
        WritePair(Aimbot, SpitfireFOV1);
        WritePair(Aimbot, SpitfireMinDistance1);
        WritePair(Aimbot, SpitfireMaxDistance1);
        WritePair(Aimbot, G7HipfireSmooth1);
        WritePair(Aimbot, G7ADSSmooth1);
        WritePair(Aimbot, G7ExtraSmooth1);
        WritePair(Aimbot, G7Deadzone);
        WritePair(Aimbot, G7FOV1);
        WritePair(Aimbot, G7MinDistance1);
        WritePair(Aimbot, G7MaxDistance1);
        //Heavy
        WritePair(Aimbot, FlatlineHipfireSmooth1);
        WritePair(Aimbot, FlatlineADSSmooth1);
        WritePair(Aimbot, FlatlineExtraSmooth1);
        WritePair(Aimbot, FlatlineDeadzone);
        WritePair(Aimbot, FlatlineFOV1);
        WritePair(Aimbot, FlatlineMinDistance1);
        WritePair(Aimbot, FlatlineMaxDistance1);
        WritePair(Aimbot, HemlockHipfireSmooth1);
        WritePair(Aimbot, HemlockADSSmooth1);
        WritePair(Aimbot, HemlockExtraSmooth1);
        WritePair(Aimbot, HemlockDeadzone);
        WritePair(Aimbot, HemlockFOV1);
        WritePair(Aimbot, HemlockMinDistance1);
        WritePair(Aimbot, HemlockMaxDistance1);
        WritePair(Aimbot, RepeaterHipfireSmooth1);
        WritePair(Aimbot, RepeaterADSSmooth1);
        WritePair(Aimbot, RepeaterExtraSmooth1);
        WritePair(Aimbot, RepeaterDeadzone);
        WritePair(Aimbot, RepeaterFOV1);
        WritePair(Aimbot, RepeaterMinDistance1);
        WritePair(Aimbot, RepeaterMaxDistance1);
        WritePair(Aimbot, RampageHipfireSmooth1);
        WritePair(Aimbot, RampageADSSmooth1);
        WritePair(Aimbot, RampageExtraSmooth1);
        WritePair(Aimbot, RampageDeadzone);
        WritePair(Aimbot, RampageFOV1);
        WritePair(Aimbot, RampageMinDistance1);
        WritePair(Aimbot, RampageMaxDistance1);
        WritePair(Aimbot, CARSMGHipfireSmooth1);
        WritePair(Aimbot, CARSMGADSSmooth1);
        WritePair(Aimbot, CARSMGExtraSmooth1);
        WritePair(Aimbot, CARSMGDeadzone);
        WritePair(Aimbot, CARSMGFOV1);
        WritePair(Aimbot, CARSMGMinDistance1);
        WritePair(Aimbot, CARSMGMaxDistance1);
        //Energy
        WritePair(Aimbot, HavocHipfireSmooth1);
        WritePair(Aimbot, HavocADSSmooth1);
        WritePair(Aimbot, HavocExtraSmooth1);
        WritePair(Aimbot, HavocDeadzone);
        WritePair(Aimbot, HavocFOV1);
        WritePair(Aimbot, HavocMinDistance1);
        WritePair(Aimbot, HavocMaxDistance1);
        WritePair(Aimbot, DevotionHipfireSmooth1);
        WritePair(Aimbot, DevotionADSSmooth1);
        WritePair(Aimbot, DevotionExtraSmooth1);
        WritePair(Aimbot, DevotionDeadzone);
        WritePair(Aimbot, DevotionFOV1);
        WritePair(Aimbot, DevotionMinDistance1);
        WritePair(Aimbot, DevotionMaxDistance1);
        WritePair(Aimbot, LSTARHipfireSmooth1);
        WritePair(Aimbot, LSTARADSSmooth1);
        WritePair(Aimbot, LSTARExtraSmooth1);
        WritePair(Aimbot, LSTARDeadzone);
        WritePair(Aimbot, LSTARFOV1);
        WritePair(Aimbot, LSTARMinDistance1);
        WritePair(Aimbot, LSTARMaxDistance1);
        WritePair(Aimbot, TripleTakeHipfireSmooth1);
        WritePair(Aimbot, TripleTakeADSSmooth1);
        WritePair(Aimbot, TripleTakeExtraSmooth1);
        WritePair(Aimbot, TripleTakeDeadzone);
        WritePair(Aimbot, TripleTakeFOV1);
        WritePair(Aimbot, TripleTakeMinDistance1);
        WritePair(Aimbot, TripleTakeMaxDistance1);
        WritePair(Aimbot, VoltHipfireSmooth1);
        WritePair(Aimbot, VoltADSSmooth1);
        WritePair(Aimbot, VoltExtraSmooth1);
        WritePair(Aimbot, VoltDeadzone);
        WritePair(Aimbot, VoltFOV1);
        WritePair(Aimbot, VoltMinDistance1);
        WritePair(Aimbot, VoltMaxDistance1);
        WritePair(Aimbot, NemesisHipfireSmooth1);
        WritePair(Aimbot, NemesisADSSmooth1);
        WritePair(Aimbot, NemesisExtraSmooth1);
        WritePair(Aimbot, NemesisDeadzone);
        WritePair(Aimbot, NemesisFOV1);
        WritePair(Aimbot, NemesisMinDistance1);
        WritePair(Aimbot, NemesisMaxDistance1);
        //Shotgun
        WritePair(Aimbot, MozambiqueHipfireSmooth1);
        WritePair(Aimbot, MozambiqueADSSmooth1);
        WritePair(Aimbot, MozambiqueExtraSmooth1);
        WritePair(Aimbot, MozambiqueDeadzone);
        WritePair(Aimbot, MozambiqueFOV1);
        WritePair(Aimbot, MozambiqueMinDistance1);
        WritePair(Aimbot, MozambiqueMaxDistance1);
        WritePair(Aimbot, EVA8HipfireSmooth1);
        WritePair(Aimbot, EVA8ADSSmooth1);
        WritePair(Aimbot, EVA8ExtraSmooth1);
        WritePair(Aimbot, EVA8Deadzone);
        WritePair(Aimbot, EVA8FOV1);
        WritePair(Aimbot, EVA8MinDistance1);
        WritePair(Aimbot, EVA8MaxDistance1);
        WritePair(Aimbot, PeacekeeperHipfireSmooth1);
        WritePair(Aimbot, PeacekeeperADSSmooth1);
        WritePair(Aimbot, PeacekeeperExtraSmooth1);
        WritePair(Aimbot, PeacekeeperDeadzone);
        WritePair(Aimbot, PeacekeeperFOV1);
        WritePair(Aimbot, PeacekeeperMinDistance1);
        WritePair(Aimbot, PeacekeeperMaxDistance1);
        WritePair(Aimbot, MastiffHipfireSmooth1);
        WritePair(Aimbot, MastiffADSSmooth1);
        WritePair(Aimbot, MastiffExtraSmooth1);
        WritePair(Aimbot, MastiffDeadzone);
        WritePair(Aimbot, MastiffFOV1);
        WritePair(Aimbot, MastiffMinDistance1);
        WritePair(Aimbot, MastiffMaxDistance1);
        //Snipers
        WritePair(Aimbot, LongbowHipfireSmooth1);
        WritePair(Aimbot, LongbowADSSmooth1);
        WritePair(Aimbot, LongbowExtraSmooth1);
        WritePair(Aimbot, LongbowDeadzone);
        WritePair(Aimbot, LongbowFOV1);
        WritePair(Aimbot, LongbowMinDistance1);
        WritePair(Aimbot, LongbowMaxDistance1);
        WritePair(Aimbot, ChargeRifleHipfireSmooth1);
        WritePair(Aimbot, ChargeRifleADSSmooth1);
        WritePair(Aimbot, ChargeRifleExtraSmooth1);
        WritePair(Aimbot, ChargeRifleDeadzone);
        WritePair(Aimbot, ChargeRifleFOV1);
        WritePair(Aimbot, ChargeRifleMinDistance1);
        WritePair(Aimbot, ChargeRifleMaxDistance1);
        WritePair(Aimbot, SentinelHipfireSmooth1);
        WritePair(Aimbot, SentinelADSSmooth1);
        WritePair(Aimbot, SentinelExtraSmooth1);
        WritePair(Aimbot, SentinelDeadzone);
        WritePair(Aimbot, SentinelFOV1);
        WritePair(Aimbot, SentinelMinDistance1);
        WritePair(Aimbot, SentinelMaxDistance1);
        //Legendary
        WritePair(Aimbot, WingmanHipfireSmooth1);
        WritePair(Aimbot, WingmanADSSmooth1);
        WritePair(Aimbot, WingmanExtraSmooth1);
        WritePair(Aimbot, WingmanDeadzone);
        WritePair(Aimbot, WingmanFOV1);
        WritePair(Aimbot, WingmanMinDistance1);
        WritePair(Aimbot, WingmanMaxDistance1);
        WritePair(Aimbot, ProwlerHipfireSmooth1);
        WritePair(Aimbot, ProwlerADSSmooth1);
        WritePair(Aimbot, ProwlerExtraSmooth1);
        WritePair(Aimbot, ProwlerDeadzone);
        WritePair(Aimbot, ProwlerFOV1);
        WritePair(Aimbot, ProwlerMinDistance1);
        WritePair(Aimbot, ProwlerMaxDistance1);
        WritePair(Aimbot, BocekHipfireSmooth1);
        WritePair(Aimbot, BocekADSSmooth1);
        WritePair(Aimbot, BocekExtraSmooth1);
        WritePair(Aimbot, BocekDeadzone);
        WritePair(Aimbot, BocekFOV1);
        WritePair(Aimbot, BocekMinDistance1);
        WritePair(Aimbot, BocekMaxDistance1);
        WritePair(Aimbot, KraberHipfireSmooth1);
        WritePair(Aimbot, KraberADSSmooth1);
        WritePair(Aimbot, KraberExtraSmooth1);
        WritePair(Aimbot, KraberDeadzone);
        WritePair(Aimbot, KraberFOV1);
        WritePair(Aimbot, KraberMinDistance1);
        WritePair(Aimbot, KraberMaxDistance1);
        WritePair(Aimbot, ThrowingKnifeHipfireSmooth1);
        WritePair(Aimbot, ThrowingKnifeADSSmooth1);
        WritePair(Aimbot, ThrowingKnifeExtraSmooth1);
        WritePair(Aimbot, ThrowingKnifeDeadzone);
        WritePair(Aimbot, ThrowingKnifeFOV1);
        WritePair(Aimbot, ThrowingKnifeMinDistance1);
        WritePair(Aimbot, ThrowingKnifeMaxDistance1);

        WriteSectionEnd();

        WriteSection(RCS);
        WritePair(RCS, RCSEnabled);
        WritePair(RCS, OnADS);
        WritePair(RCS, PitchPower);
        WritePair(RCS, YawPower);
        //Weapons
        //Light
        WritePair(RCS, P2020);
        WritePair(RCS, RE45);
        WritePair(RCS, Alternator);
        WritePair(RCS, R99);
        WritePair(RCS, R301);
        WritePair(RCS, Spitfire);
        WritePair(RCS, G7);
        //Heavy
        WritePair(RCS, Flatline);
        WritePair(RCS, Hemlock);
        WritePair(RCS, Repeater);
        WritePair(RCS, Rampage);
        WritePair(RCS, CARSMG);
        //Energy
        WritePair(RCS, Havoc);
        WritePair(RCS, Devotion);
        WritePair(RCS, LSTAR);
        WritePair(RCS, TripleTake);
        WritePair(RCS, Volt);
        WritePair(RCS, Nemesis);
        //Shotgun
        WritePair(RCS, Mozambique);
        WritePair(RCS, EVA8);
        WritePair(RCS, Peacekeeper);
        WritePair(RCS, Mastiff);
        //Snipers
        WritePair(RCS, Longbow);
        WritePair(RCS, ChargeRifle);
        WritePair(RCS, Sentinel);
        //Legendary
        WritePair(RCS, Wingman); //Emotional damage!
        WritePair(RCS, Prowler);
        WritePair(RCS, Kraber);

        //---------------Advanced---------------//
        WritePair(RCS, AdvancedRCS);
            //Weapons
        //Light
        WritePair(RCS, P2020Pitch);
        WritePair(RCS, P2020Yaw);
        WritePair(RCS, RE45Pitch);
        WritePair(RCS, RE45Yaw);
        WritePair(RCS, AlternatorPitch);
        WritePair(RCS, AlternatorYaw);
        WritePair(RCS, R99Pitch);
        WritePair(RCS, R99Yaw);
        WritePair(RCS, R301Pitch);
        WritePair(RCS, R301Yaw);
        WritePair(RCS, SpitfirePitch);
        WritePair(RCS, SpitfireYaw);
        WritePair(RCS, G7Pitch);
        WritePair(RCS, G7Yaw);
        //Heavy
        WritePair(RCS, FlatlinePitch);
        WritePair(RCS, FlatlineYaw);
        WritePair(RCS, HemlockPitch);
        WritePair(RCS, HemlockYaw);
        WritePair(RCS, RepeaterPitch);
        WritePair(RCS, RepeaterYaw);
        WritePair(RCS, RampagePitch);
        WritePair(RCS, RampageYaw);
        WritePair(RCS, CARSMGPitch);
        WritePair(RCS, CARSMGYaw);
        //Energy
        WritePair(RCS, HavocPitch);
        WritePair(RCS, HavocYaw);
        WritePair(RCS, DevotionPitch);
        WritePair(RCS, DevotionYaw);
        WritePair(RCS, LSTARPitch);
        WritePair(RCS, LSTARYaw);
        WritePair(RCS, TripleTakePitch);
        WritePair(RCS, TripleTakeYaw);
        WritePair(RCS, VoltPitch);
        WritePair(RCS, VoltYaw);
        WritePair(RCS, NemesisPitch);
        WritePair(RCS, NemesisYaw);
        //Shotgun
        WritePair(RCS, MozambiquePitch);
        WritePair(RCS, MozambiqueYaw);
        WritePair(RCS, EVA8Pitch);
        WritePair(RCS, EVA8Yaw);
        WritePair(RCS, PeacekeeperPitch);
        WritePair(RCS, PeacekeeperYaw);
        WritePair(RCS, MastiffPitch);
        WritePair(RCS, MastiffYaw);
        //Snipers
        WritePair(RCS, LongbowPitch);
        WritePair(RCS, LongbowYaw);
        WritePair(RCS, ChargeRiflePitch);
        WritePair(RCS, ChargeRifleYaw);
        WritePair(RCS, SentinelPitch);
        WritePair(RCS, SentinelYaw);
        //Legendary
        WritePair(RCS, WingmanPitch);
        WritePair(RCS, WingmanYaw);
        WritePair(RCS, ProwlerPitch);
        WritePair(RCS, ProwlerYaw);
        WritePair(RCS, KraberPitch);
        WritePair(RCS, KraberYaw);
        WriteSectionEnd();

        WriteSection(Glow);
        WritePair(Glow, GlowEnabled); //
        WritePair(Glow, ItemGlow);
        WritePair(Glow, GlowMaxDistance);
        WritePair(Glow, NewGlow);
        WritePair(Glow, GlowColorMode);
        WritePair(Glow, GlowColorShieldMode);
        WritePair(Glow, GlowRadius);
        WritePair(Glow, InsideFunction);
        WritePair(Glow, OutlineFunction);
        WritePair(Glow, BodyStyle);    
        WritePair(Glow, OutlineStyle);
        WritePair(Glow, InvisibleGlowColorR);
        WritePair(Glow, InvisibleGlowColorG);
        WritePair(Glow, InvisibleGlowColorB);
        WritePair(Glow, VisibleGlowColorR);
        WritePair(Glow, VisibleGlowColorG);
        WritePair(Glow, VisibleGlowColorB);
        WritePair(Glow, LowGlowColorR);
        WritePair(Glow, LowGlowColorG);
        WritePair(Glow, LowGlowColorB);
        WritePair(Glow, RedShieldColorR);
        WritePair(Glow, RedShieldColorG);
        WritePair(Glow, RedShieldColorB);
        WritePair(Glow, PurpleShieldColorR);
        WritePair(Glow, PurpleShieldColorG);
        WritePair(Glow, PurpleShieldColorB);
        WritePair(Glow, BlueShieldColorR);
        WritePair(Glow, BlueShieldColorG);
        WritePair(Glow, BlueShieldColorB);
        WritePair(Glow, GreyShieldColorR);
        WritePair(Glow, GreyShieldColorG);
        WritePair(Glow, GreyShieldColorB);

        WriteSection(Sense);
        WritePair(Sense, VisibilityCheck);
        WritePair(Sense, DrawBoxes);
        WritePair(Sense, BoxType);
        WritePair(Sense, BoxStyle);
        WritePair(Sense, BoxThickness);
        WritePair(Sense, Skeleton);
        WritePair(Sense, SkeletonThickness);
        WritePair(Sense, HealthBar);
        WritePair(Sense, ShieldBar);
        WritePair(Sense, drawlvl);
        WritePair(Sense, BarMode);
        WritePair(Sense, BarStyle);
        WritePair(Sense, BarColorMode);
        WritePair(Sense, BarBackground);
        WritePair(Sense, BarThickness);
        WritePair(Sense, BarThickness2);
        WritePair(Sense, BarHeight);
        WritePair(Sense, BarWidth);
        WritePair(Sense, ESPMaxDistance);
        WritePair(Sense, ShowNear);
        WritePair(Sense, DrawSeer);
        WritePair(Sense, DrawStatus);
        WritePair(Sense, DrawWeapon);
        WritePair(Sense, WeaponColorType);
        WritePair(Sense, ShowLegend);
        WritePair(Sense, ShowMaxStatusValues);
        WritePair(Sense, DrawDistance);
        WritePair(Sense, DrawFOVCircle);
        WritePair(Sense, DrawFilledFOVCircle);
        WritePair(Sense, FOVThickness);
        WritePair(Sense, DrawNames);
        WritePair(Sense, TracerPos);
        WritePair(Sense, TracerBone);
        WritePair(Sense, DrawTracers);
        WritePair(Sense, TracerThickness);
        WritePair(Sense, ShowSpectators);
        WritePair(Sense, DrawCrosshair);
        WritePair(Sense, CrosshairSize);
        WritePair(Sense, CrosshairThickness);

        WriteSectionEnd();

        //Colors
        WriteSection(Colors);
        WritePair(Colors, InvisibleBoxColorR);
        WritePair(Colors, InvisibleBoxColorG);
        WritePair(Colors, InvisibleBoxColorB);
        WritePair(Colors, InvisibleBoxColorA);
        WritePair(Colors, VisibleBoxColorR);
        WritePair(Colors, VisibleBoxColorG);
        WritePair(Colors, VisibleBoxColorB);
        WritePair(Colors, VisibleBoxColorA);
        WritePair(Colors, InvisibleFilledBoxColorR);
        WritePair(Colors, InvisibleFilledBoxColorG);
        WritePair(Colors, InvisibleFilledBoxColorB);
        WritePair(Colors, InvisibleFilledBoxColorA);
        WritePair(Colors, VisibleFilledBoxColorR);
        WritePair(Colors, VisibleFilledBoxColorG);
        WritePair(Colors, VisibleFilledBoxColorB);
        WritePair(Colors, VisibleFilledBoxColorA);
        WritePair(Colors, InvisibleTracerColorR);
        WritePair(Colors, InvisibleTracerColorG);
        WritePair(Colors, InvisibleTracerColorB);
        WritePair(Colors, InvisibleTracerColorA);
        WritePair(Colors, VisibleTracerColorR);
        WritePair(Colors, VisibleTracerColorG);
        WritePair(Colors, VisibleTracerColorB);
        WritePair(Colors, VisibleTracerColorA);
        WritePair(Colors, InvisibleSkeletonColorR);
        WritePair(Colors, InvisibleSkeletonColorG);
        WritePair(Colors, InvisibleSkeletonColorB);
        WritePair(Colors, InvisibleSkeletonColorA);
        WritePair(Colors, VisibleSkeletonColorR);
        WritePair(Colors, VisibleSkeletonColorG);
        WritePair(Colors, VisibleSkeletonColorB);
        WritePair(Colors, VisibleSkeletonColorA);
        WritePair(Colors, InvisibleNameColorR);
        WritePair(Colors, InvisibleNameColorG);
        WritePair(Colors, InvisibleNameColorB);
        WritePair(Colors, InvisibleNameColorA);
        WritePair(Colors, VisibleNameColorR);
        WritePair(Colors, VisibleNameColorG);
        WritePair(Colors, VisibleNameColorB);
        WritePair(Colors, VisibleNameColorA);
        WritePair(Colors, InvisibleDistanceColorR);
        WritePair(Colors, InvisibleDistanceColorG);
        WritePair(Colors, InvisibleDistanceColorB);
        WritePair(Colors, InvisibleDistanceColorA);
        WritePair(Colors, VisibleDistanceColorR);
        WritePair(Colors, VisibleDistanceColorG);
        WritePair(Colors, VisibleDistanceColorB);
        WritePair(Colors, VisibleDistanceColorA);
        WritePair(Colors, InvisibleLegendColorR);
        WritePair(Colors, InvisibleLegendColorG);
        WritePair(Colors, InvisibleLegendColorB);
        WritePair(Colors, InvisibleLegendColorA);
        WritePair(Colors, VisibleLegendColorR);
        WritePair(Colors, VisibleLegendColorG);
        WritePair(Colors, VisibleLegendColorB);
        WritePair(Colors, VisibleLegendColorA);
        WritePair(Colors, FOVColorR);
        WritePair(Colors, FOVColorG);
        WritePair(Colors, FOVColorB);
        WritePair(Colors, FOVColorA);
        WritePair(Colors, FilledFOVColorR);
        WritePair(Colors, FilledFOVColorG);
        WritePair(Colors, FilledFOVColorB);
        WritePair(Colors, FilledFOVColorA);
        WritePair(Colors, VisibleWeaponColorR);
        WritePair(Colors, VisibleWeaponColorG);
        WritePair(Colors, VisibleWeaponColorB);
        WritePair(Colors, VisibleWeaponColorA);
        WritePair(Colors, InvisibleWeaponColorR);
        WritePair(Colors, InvisibleWeaponColorG);
        WritePair(Colors, InvisibleWeaponColorB);
        WritePair(Colors, InvisibleWeaponColorA);
        WritePair(Colors, NearColorR);
        WritePair(Colors, NearColorG);
        WritePair(Colors, NearColorB);
        WritePair(Colors, NearColorA);
        WritePair(Colors, TeamColorR);
        WritePair(Colors, TeamColorG);
        WritePair(Colors, TeamColorB);
        WritePair(Colors, TeamColorA);
        WritePair(Colors, TeamNameColorR);
        WritePair(Colors, TeamNameColorG);
        WritePair(Colors, TeamNameColorB);
        WritePair(Colors, TeamNameColorA);
        WritePair(Colors, CrosshairColorR);
        WritePair(Colors, CrosshairColorG);
        WritePair(Colors, CrosshairColorB);
        WritePair(Colors, CrosshairColorA);

        WritePair(Colors, LightWeaponColorR);
        WritePair(Colors, LightWeaponColorG);
        WritePair(Colors, LightWeaponColorB);
        WritePair(Colors, LightWeaponColorA);
        WritePair(Colors, HeavyWeaponColorR);
        WritePair(Colors, HeavyWeaponColorG);
        WritePair(Colors, HeavyWeaponColorB);
        WritePair(Colors, HeavyWeaponColorA);
        WritePair(Colors, EnergyWeaponColorR);
        WritePair(Colors, EnergyWeaponColorG);
        WritePair(Colors, EnergyWeaponColorB);
        WritePair(Colors, EnergyWeaponColorA);
        WritePair(Colors, ShotgunWeaponColorR);
        WritePair(Colors, ShotgunWeaponColorG);
        WritePair(Colors, ShotgunWeaponColorB);
        WritePair(Colors, ShotgunWeaponColorA);
        WritePair(Colors, SniperWeaponColorR);
        WritePair(Colors, SniperWeaponColorG);
        WritePair(Colors, SniperWeaponColorB);
        WritePair(Colors, SniperWeaponColorA);
        WritePair(Colors, LegendaryWeaponColorR);
        WritePair(Colors, LegendaryWeaponColorG);
        WritePair(Colors, LegendaryWeaponColorB);
        WritePair(Colors, LegendaryWeaponColorA);
        WritePair(Colors, MeleeWeaponColorR);
        WritePair(Colors, MeleeWeaponColorG);
        WritePair(Colors, MeleeWeaponColorB);
        WritePair(Colors, MeleeWeaponColorA);
        WritePair(Colors, ThrowableWeaponColorR);
        WritePair(Colors, ThrowableWeaponColorG);
        WritePair(Colors, ThrowableWeaponColorB);
        WritePair(Colors, ThrowableWeaponColorA);

        WriteSectionEnd();

        WriteSection(Triggerbot);
        WritePair(Triggerbot, Enabled);
        WritePair(Triggerbot, OnADS);
        WritePair(Triggerbot, HipfireShotguns);
        WritePair(Triggerbot, Range);
        //Weapons
        //Light
        WritePair(Triggerbot, P2020);
        WritePair(Triggerbot, RE45);
        WritePair(Triggerbot, Alternator);
        WritePair(Triggerbot, R99);
        WritePair(Triggerbot, R301);
        WritePair(Triggerbot, Spitfire);
        WritePair(Triggerbot, G7);
        //Heavy
        WritePair(Triggerbot, Flatline);
        WritePair(Triggerbot, Hemlock);
        WritePair(Triggerbot, Repeater);
        WritePair(Triggerbot, Rampage);
        WritePair(Triggerbot, CARSMG);
        //Energy
        WritePair(Triggerbot, Havoc);
        WritePair(Triggerbot, Devotion);
        WritePair(Triggerbot, LSTAR);
        WritePair(Triggerbot, TripleTake);
        WritePair(Triggerbot, Volt);
        WritePair(Triggerbot, Nemesis);
        //Shotgun
        WritePair(Triggerbot, Mozambique);
        WritePair(Triggerbot, EVA8);
        WritePair(Triggerbot, Peacekeeper);
        WritePair(Triggerbot, Mastiff);
        //Snipers
        WritePair(Triggerbot, Longbow);
        WritePair(Triggerbot, ChargeRifle);
        WritePair(Triggerbot, Sentinel);
        //Legendary
        WritePair(Triggerbot, Wingman); //Emotional damage!
        WritePair(Triggerbot, Prowler);
        WritePair(Triggerbot, Bocek);
        WritePair(Triggerbot, Kraber);
        WritePair(Triggerbot, Knife);
        WriteSectionEnd();

        WriteSection(Radar);
        WritePair(Radar, MiniMap);
        WritePair(Radar, MiniMapRange);
        WritePair(Radar, MiniMapScaleX);
        WritePair(Radar, MiniMapScaleY);
        WritePair(Radar, MiniMapDotSize);
        WritePair(Radar, MiniMapGuides);
        WritePair(Radar, BigMap);
        WriteSectionEnd();

        WriteSection(Misc);
        WritePair(Misc, SkinChanger);
        WritePair(Misc, AutoGrapple);
        WritePair(Misc, SuperGlide);
            //Weapons
        //Light
        WritePair(Misc, SkinP2020);
        WritePair(Misc, SkinRE45);
        WritePair(Misc, SkinALTERNATOR);
        WritePair(Misc, SkinR99);
        WritePair(Misc, SkinR301);
        WritePair(Misc, SkinSPITFIRE);
        WritePair(Misc, SkinG7);
        //Heavy
        WritePair(Misc, SkinFLATLINE);
        WritePair(Misc, SkinHEMLOCK);
        WritePair(Misc, SkinREPEATER);
        WritePair(Misc, SkinRAMPAGE);
        WritePair(Misc, SkinCAR);
        //Energy
        WritePair(Misc, SkinHAVOC);
        WritePair(Misc, SkinDEVOTION);
        WritePair(Misc, SkinLSTAR);
        WritePair(Misc, SkinTRIPLETAKE);
        WritePair(Misc, SkinVOLT);
        WritePair(Misc, SkinNEMESIS);
        //Shotgun
        WritePair(Misc, SkinMOZAMBIQUE);
        WritePair(Misc, SkinEVA8);
        WritePair(Misc, SkinPEACEKEEPER);
        WritePair(Misc, SkinMASTIFF);
        //Snipers
        WritePair(Misc, SkinLONGBOW);
        WritePair(Misc, SkinCHARGE_RIFLE);
        WritePair(Misc, SkinSENTINEL);
        //Legendary
        WritePair(Misc, SkinWINGMAN);
        WritePair(Misc, SkinPROWLER);
        WritePair(Misc, SkinKRABER);
        WritePair(Misc, SkinBOCEK);
        WriteSectionEnd();

        WriteSection(Home);
        WritePair(Home, AsciiArt);
        WritePair(Home, AsciiArtSpeed);
        WritePair(Home, TeamGamemode);
        WritePair(Home, MenuX);
        WritePair(Home, MenuY);
        WritePair(Home, Style);
        WritePair(Home, Color);
        WritePair(Home, ErrorLogging);
        WriteSectionEnd();
        conf.close();
    }
}

bool ReadConfig(const std::string &configFile) {
    INIReader reader(configFile);
    if (reader.ParseError() < 0) {
        UpdateConfig();
        return false;
    }

    ReadBool(Aimbot, Enabled);
    ReadInt(Aimbot, AimbotMode);
    ReadBool(Aimbot, ClosestHitbox);
    ReadInt(Aimbot, HitBox);
    ReadBool(Aimbot, BindMethod);
    ReadBool(Aimbot, OnFire);
    ReadBool(Aimbot, OnADS);
    ReadInt(Aimbot, AimBind);
    ReadInt(Aimbot, ExtraBind);

    ReadBool(Aimbot, VisCheck);
    ReadBool(Aimbot, TeamCheck);
    ReadBool(Aimbot, PredictMovement);
    ReadBool(Aimbot, PredictBulletDrop);
    ReadFloat(Aimbot, Speed);
    ReadFloat(Aimbot, Smooth);
    ReadFloat(Aimbot, HipfireSmooth);
    ReadFloat(Aimbot, ADSSmooth);
    ReadFloat(Aimbot, SmoothDistance);
    ReadBool(Aimbot, Deadzone);
    ReadInt(Aimbot, Delay);
    ReadFloat(Aimbot, FOV);
    ReadFloat(Aimbot, ZoomScale);
    ReadFloat(Aimbot, MinDistance);
    ReadFloat(Aimbot, HipfireDistance);
    ReadFloat(Aimbot, ZoomDistance);
        //Weapons
    //Light
    ReadBool(Aimbot, P2020);
    ReadBool(Aimbot, RE45);
    ReadBool(Aimbot, Alternator);
    ReadBool(Aimbot, R99);
    ReadBool(Aimbot, R301);
    ReadBool(Aimbot, Spitfire);
    ReadBool(Aimbot, G7);
    //Heavy
    ReadBool(Aimbot, Flatline);
    ReadBool(Aimbot, Hemlock);
    ReadBool(Aimbot, Repeater);
    ReadBool(Aimbot, Rampage);
    ReadBool(Aimbot, CARSMG);
    //Energy
    ReadBool(Aimbot, Havoc);
    ReadBool(Aimbot, Devotion);
    ReadBool(Aimbot, LSTAR);
    ReadBool(Aimbot, TripleTake);
    ReadBool(Aimbot, Volt);
    ReadBool(Aimbot, Nemesis);
    //Shotgun
    ReadBool(Aimbot, Mozambique);
    ReadBool(Aimbot, EVA8);
    ReadBool(Aimbot, Peacekeeper);
    ReadBool(Aimbot, Mastiff);
    //Snipers
    ReadBool(Aimbot, Longbow);
    ReadBool(Aimbot, ChargeRifle);
    ReadBool(Aimbot, Sentinel);
    //Legendary
    ReadBool(Aimbot, Wingman);
    ReadBool(Aimbot, Prowler);
    ReadBool(Aimbot, Bocek);
    ReadBool(Aimbot, Kraber);
    ReadBool(Aimbot, Knife);

    //---------------Advanced---------------//
    ReadBool(Aimbot, AdvancedAim);

    //Aimbot Mode 0 - xap-client
    ReadFloat(Aimbot, AdvancedSpeed);
    ReadFloat(Aimbot, AdvancedSmooth);
    ReadFloat(Aimbot, AdvancedHipfireSmooth);
    ReadFloat(Aimbot, AdvancedADSSmooth);
    //Aimbot Mode 1 - Grinder
    ReadFloat(Aimbot, AdvancedHipfireSmooth1);
    ReadFloat(Aimbot, AdvancedADSSmooth1);
    ReadFloat(Aimbot, AdvancedExtraSmooth1);
    ReadFloat(Aimbot, AdvancedDeadzone);
    ReadFloat(Aimbot, AdvancedFOV1);
    ReadFloat(Aimbot, AdvancedMinDistance1);
    ReadFloat(Aimbot, AdvancedMaxDistance1);

    //Aimbot Mode 0 - Weapons && OnADS && OnFire
    ReadBool(Aimbot, P2020Fire);
    ReadBool(Aimbot, P2020ADS);
    ReadBool(Aimbot, RE45Fire);
    ReadBool(Aimbot, RE45ADS);
    ReadBool(Aimbot, AlternatorFire);
    ReadBool(Aimbot, AlternatorADS);
    ReadBool(Aimbot, R99Fire);
    ReadBool(Aimbot, R99ADS);
    ReadBool(Aimbot, R301Fire);
    ReadBool(Aimbot, R301ADS);
    ReadBool(Aimbot, SpitfireFire);
    ReadBool(Aimbot, SpitfireADS);
    ReadBool(Aimbot, G7Fire);
    ReadBool(Aimbot, G7ADS);
    ReadBool(Aimbot, FlatlineFire);
    ReadBool(Aimbot, FlatlineADS);
    ReadBool(Aimbot, HemlockFire);
    ReadBool(Aimbot, HemlockADS);
    ReadBool(Aimbot, RepeaterFire);
    ReadBool(Aimbot, RepeaterADS);
    ReadBool(Aimbot, RampageFire);
    ReadBool(Aimbot, RampageADS);
    ReadBool(Aimbot, CARSMGFire);
    ReadBool(Aimbot, CARSMGADS);
    ReadBool(Aimbot, HavocFire);
    ReadBool(Aimbot, HavocADS);
    ReadBool(Aimbot, DevotionFire);
    ReadBool(Aimbot, DevotionADS);
    ReadBool(Aimbot, LSTARFire);
    ReadBool(Aimbot, LSTARADS);
    ReadBool(Aimbot, TripleTakeFire);
    ReadBool(Aimbot, TripleTakeADS);
    ReadBool(Aimbot, VoltFire);
    ReadBool(Aimbot, VoltADS);
    ReadBool(Aimbot, NemesisFire);
    ReadBool(Aimbot, NemesisADS);
    ReadBool(Aimbot, MozambiqueFire);
    ReadBool(Aimbot, MozambiqueADS);
    ReadBool(Aimbot, EVA8Fire);
    ReadBool(Aimbot, EVA8ADS);
    ReadBool(Aimbot, PeacekeeperFire);
    ReadBool(Aimbot, PeacekeeperADS);
    ReadBool(Aimbot, MastiffFire);
    ReadBool(Aimbot, MastiffADS);
    ReadBool(Aimbot, WingmanFire);
    ReadBool(Aimbot, WingmanADS);
    ReadBool(Aimbot, BocekFire);
    ReadBool(Aimbot, BocekADS);
    ReadBool(Aimbot, ProwlerFire);
    ReadBool(Aimbot, ProwlerADS);
    ReadBool(Aimbot, KraberFire);
    ReadBool(Aimbot, KraberADS);
    ReadBool(Aimbot, ThrowingKnifeFire);
    ReadBool(Aimbot, ThrowingKnifeADS);

    //Advanced Keybinds
    ReadInt(Aimbot, P2020AimBind);
    ReadInt(Aimbot, P2020ExtraBind);
    ReadInt(Aimbot, RE45AimBind);
    ReadInt(Aimbot, RE45ExtraBind);
    ReadInt(Aimbot, AlternatorAimBind);
    ReadInt(Aimbot, AlternatorExtraBind);
    ReadInt(Aimbot, R99AimBind);
    ReadInt(Aimbot, R99ExtraBind);
    ReadInt(Aimbot, R301AimBind);
    ReadInt(Aimbot, R301ExtraBind);
    ReadInt(Aimbot, SpitfireAimBind);
    ReadInt(Aimbot, SpitfireExtraBind);
    ReadInt(Aimbot, G7AimBind);
    ReadInt(Aimbot, G7ExtraBind);
    ReadInt(Aimbot, FlatlineAimBind);
    ReadInt(Aimbot, FlatlineExtraBind);
    ReadInt(Aimbot, HemlockAimBind);
    ReadInt(Aimbot, HemlockExtraBind);
    ReadInt(Aimbot, RepeaterAimBind);
    ReadInt(Aimbot, RepeaterExtraBind);
    ReadInt(Aimbot, RampageAimBind);
    ReadInt(Aimbot, RampageExtraBind);
    ReadInt(Aimbot, CARSMGAimBind);
    ReadInt(Aimbot, CARSMGExtraBind);
    ReadInt(Aimbot, HavocAimBind);
    ReadInt(Aimbot, HavocExtraBind);
    ReadInt(Aimbot, DevotionAimBind);
    ReadInt(Aimbot, DevotionExtraBind);
    ReadInt(Aimbot, LSTARAimBind);
    ReadInt(Aimbot, LSTARExtraBind);
    ReadInt(Aimbot, TripleTakeAimBind);
    ReadInt(Aimbot, TripleTakeExtraBind);
    ReadInt(Aimbot, VoltAimBind);
    ReadInt(Aimbot, VoltExtraBind);
    ReadInt(Aimbot, NemesisAimBind);
    ReadInt(Aimbot, NemesisExtraBind);
    ReadInt(Aimbot, MozambiqueAimBind);
    ReadInt(Aimbot, MozambiqueExtraBind);
    ReadInt(Aimbot, EVA8AimBind);
    ReadInt(Aimbot, EVA8ExtraBind);
    ReadInt(Aimbot, PeacekeeperAimBind);
    ReadInt(Aimbot, PeacekeeperExtraBind);
    ReadInt(Aimbot, MastiffAimBind);
    ReadInt(Aimbot, MastiffExtraBind);
    ReadInt(Aimbot, LongbowAimBind);
    ReadInt(Aimbot, LongbowExtraBind);
    ReadInt(Aimbot, ChargeRifleAimBind);
    ReadInt(Aimbot, ChargeRifleExtraBind);
    ReadInt(Aimbot, SentinelAimBind);
    ReadInt(Aimbot, SentinelExtraBind);
    ReadInt(Aimbot, WingmanAimBind);
    ReadInt(Aimbot, WingmanExtraBind);
    ReadInt(Aimbot, ProwlerAimBind);
    ReadInt(Aimbot, ProwlerExtraBind);
    ReadInt(Aimbot, BocekAimBind);
    ReadInt(Aimbot, BocekExtraBind);
    ReadInt(Aimbot, KraberAimBind);
    ReadInt(Aimbot, KraberExtraBind);
    ReadInt(Aimbot, ThrowingKnifeAimBind);
    ReadInt(Aimbot, ThrowingKnifeExtraBind);

    //Light
    ReadBool(Aimbot, P2020ClosestHitbox);
    ReadInt(Aimbot, P2020Hitbox);
    ReadFloat(Aimbot, P2020Speed);
    ReadFloat(Aimbot, P2020HipfireSmooth);
    ReadFloat(Aimbot, P2020ADSSmooth);

    ReadBool(Aimbot, RE45ClosestHitbox);
    ReadInt(Aimbot, RE45Hitbox);
    ReadFloat(Aimbot, RE45Speed);
    ReadFloat(Aimbot, RE45HipfireSmooth);
    ReadFloat(Aimbot, RE45ADSSmooth);

    ReadBool(Aimbot, AlternatorClosestHitbox);
    ReadInt(Aimbot, AlternatorHitbox);
    ReadFloat(Aimbot, AlternatorSpeed);
    ReadFloat(Aimbot, AlternatorHipfireSmooth);
    ReadFloat(Aimbot, AlternatorADSSmooth);

    ReadBool(Aimbot, R99ClosestHitbox);
    ReadInt(Aimbot, R99Hitbox);
    ReadFloat(Aimbot, R99Speed);
    ReadFloat(Aimbot, R99HipfireSmooth);
    ReadFloat(Aimbot, R99ADSSmooth);

    ReadBool(Aimbot, R301ClosestHitbox);
    ReadInt(Aimbot, R301Hitbox);
    ReadFloat(Aimbot, R301Speed);
    ReadFloat(Aimbot, R301HipfireSmooth);
    ReadFloat(Aimbot, R301ADSSmooth);

    ReadBool(Aimbot, SpitfireClosestHitbox);
    ReadInt(Aimbot, SpitfireHitbox);
    ReadFloat(Aimbot, SpitfireSpeed);
    ReadFloat(Aimbot, SpitfireHipfireSmooth);
    ReadFloat(Aimbot, SpitfireADSSmooth);

    ReadBool(Aimbot, G7ClosestHitbox);
    ReadInt(Aimbot, G7Hitbox);
    ReadFloat(Aimbot, G7Speed);
    ReadFloat(Aimbot, G7HipfireSmooth);
    ReadFloat(Aimbot, G7ADSSmooth);

    //Heavy
    ReadBool(Aimbot, FlatlineClosestHitbox);
    ReadInt(Aimbot, FlatlineHitbox);
    ReadFloat(Aimbot, FlatlineSpeed);
    ReadFloat(Aimbot, FlatlineHipfireSmooth);
    ReadFloat(Aimbot, FlatlineADSSmooth);

    ReadBool(Aimbot, HemlockClosestHitbox);
    ReadInt(Aimbot, HemlockHitbox);
    ReadFloat(Aimbot, HemlockSpeed);
    ReadFloat(Aimbot, HemlockHipfireSmooth);
    ReadFloat(Aimbot, HemlockADSSmooth);

    ReadBool(Aimbot, RepeaterClosestHitbox);
    ReadInt(Aimbot, RepeaterHitbox);
    ReadFloat(Aimbot, RepeaterSpeed);
    ReadFloat(Aimbot, RepeaterHipfireSmooth);
    ReadFloat(Aimbot, RepeaterADSSmooth);

    ReadBool(Aimbot, RampageClosestHitbox);
    ReadInt(Aimbot, RampageHitbox);
    ReadFloat(Aimbot, RampageSpeed);
    ReadFloat(Aimbot, RampageHipfireSmooth);
    ReadFloat(Aimbot, RampageADSSmooth);

    ReadBool(Aimbot, CARSMGClosestHitbox);
    ReadInt(Aimbot, CARSMGHitbox);
    ReadFloat(Aimbot, CARSMGSpeed);
    ReadFloat(Aimbot, CARSMGHipfireSmooth);
    ReadFloat(Aimbot, CARSMGADSSmooth);

    //Energy
    ReadBool(Aimbot, HavocClosestHitbox);
    ReadInt(Aimbot, HavocHitbox);
    ReadFloat(Aimbot, HavocSpeed);
    ReadFloat(Aimbot, HavocHipfireSmooth);
    ReadFloat(Aimbot, HavocADSSmooth);

    ReadBool(Aimbot, DevotionClosestHitbox);
    ReadInt(Aimbot, DevotionHitbox);
    ReadFloat(Aimbot, DevotionSpeed);
    ReadFloat(Aimbot, DevotionHipfireSmooth);
    ReadFloat(Aimbot, DevotionADSSmooth);

    ReadBool(Aimbot, LSTARClosestHitbox);
    ReadInt(Aimbot, LSTARHitbox);
    ReadFloat(Aimbot, LSTARSpeed);
    ReadFloat(Aimbot, LSTARHipfireSmooth);
    ReadFloat(Aimbot, LSTARADSSmooth);

    ReadBool(Aimbot, TripleTakeClosestHitbox);
    ReadInt(Aimbot, TripleTakeHitbox);
    ReadFloat(Aimbot, TripleTakeSpeed);
    ReadFloat(Aimbot, TripleTakeHipfireSmooth);
    ReadFloat(Aimbot, TripleTakeADSSmooth);

    ReadBool(Aimbot, VoltClosestHitbox);
    ReadInt(Aimbot, VoltHitbox);
    ReadFloat(Aimbot, VoltSpeed);
    ReadFloat(Aimbot, VoltHipfireSmooth);
    ReadFloat(Aimbot, VoltADSSmooth);

    ReadBool(Aimbot, NemesisClosestHitbox);
    ReadInt(Aimbot, NemesisHitbox);
    ReadFloat(Aimbot, NemesisSpeed);
    ReadFloat(Aimbot, NemesisHipfireSmooth);
    ReadFloat(Aimbot, NemesisADSSmooth);

    //Shotgun
    ReadBool(Aimbot, MozambiqueClosestHitbox);
    ReadInt(Aimbot, MozambiqueHitbox);
    ReadFloat(Aimbot, MozambiqueSpeed);
    ReadFloat(Aimbot, MozambiqueHipfireSmooth);
    ReadFloat(Aimbot, MozambiqueADSSmooth);

    ReadBool(Aimbot, EVA8ClosestHitbox);
    ReadInt(Aimbot, EVA8Hitbox);
    ReadFloat(Aimbot, EVA8Speed);
    ReadFloat(Aimbot, EVA8HipfireSmooth);
    ReadFloat(Aimbot, EVA8ADSSmooth);

    ReadBool(Aimbot, PeacekeeperClosestHitbox);
    ReadInt(Aimbot, PeacekeeperHitbox);
    ReadFloat(Aimbot, PeacekeeperSpeed);
    ReadFloat(Aimbot, PeacekeeperHipfireSmooth);
    ReadFloat(Aimbot, PeacekeeperADSSmooth);

    ReadBool(Aimbot, MastiffClosestHitbox);
    ReadInt(Aimbot, MastiffHitbox);
    ReadFloat(Aimbot, MastiffSpeed);
    ReadFloat(Aimbot, MastiffHipfireSmooth);
    ReadFloat(Aimbot, MastiffADSSmooth);

    //Snipers
    ReadBool(Aimbot, LongbowClosestHitbox);
    ReadInt(Aimbot, LongbowHitbox);
    ReadFloat(Aimbot, LongbowSpeed);
    ReadFloat(Aimbot, LongbowHipfireSmooth);
    ReadFloat(Aimbot, LongbowADSSmooth);

    ReadBool(Aimbot, ChargeRifleClosestHitbox);
    ReadInt(Aimbot, ChargeRifleHitbox);
    ReadFloat(Aimbot, ChargeRifleSpeed);
    ReadFloat(Aimbot, ChargeRifleHipfireSmooth);
    ReadFloat(Aimbot, ChargeRifleADSSmooth);

    ReadBool(Aimbot, SentinelClosestHitbox);
    ReadInt(Aimbot, SentinelHitbox);
    ReadFloat(Aimbot, SentinelSpeed);
    ReadFloat(Aimbot, SentinelHipfireSmooth);
    ReadFloat(Aimbot, SentinelADSSmooth);

    //Legendary
    ReadBool(Aimbot, WingmanClosestHitbox);
    ReadInt(Aimbot, WingmanHitbox);
    ReadFloat(Aimbot, WingmanSpeed);
    ReadFloat(Aimbot, WingmanHipfireSmooth);
    ReadFloat(Aimbot, WingmanADSSmooth);

    ReadBool(Aimbot, ProwlerClosestHitbox);
    ReadInt(Aimbot, ProwlerHitbox);
    ReadFloat(Aimbot, ProwlerSpeed);
    ReadFloat(Aimbot, ProwlerHipfireSmooth);
    ReadFloat(Aimbot, ProwlerADSSmooth);

    ReadBool(Aimbot, BocekClosestHitbox);
    ReadInt(Aimbot, BocekHitbox);
    ReadFloat(Aimbot, BocekSpeed);
    ReadFloat(Aimbot, BocekHipfireSmooth);
    ReadFloat(Aimbot, BocekADSSmooth);

    ReadBool(Aimbot, KraberClosestHitbox);
    ReadInt(Aimbot, KraberHitbox);
    ReadFloat(Aimbot, KraberSpeed);
    ReadFloat(Aimbot, KraberHipfireSmooth);
    ReadFloat(Aimbot, KraberADSSmooth);

    ReadBool(Aimbot, ThrowingKnifeClosestHitbox);
    ReadInt(Aimbot, ThrowingKnifeHitbox);
    ReadFloat(Aimbot, ThrowingKnifeSpeed);
    ReadFloat(Aimbot, ThrowingKnifeHipfireSmooth);
    ReadFloat(Aimbot, ThrowingKnifeADSSmooth);


    //Aimbot Mode 1 - Grinder
    ReadFloat(Aimbot, P2020HipfireSmooth1);
    ReadFloat(Aimbot, P2020ADSSmooth1);
    ReadFloat(Aimbot, P2020ExtraSmooth1);
    ReadFloat(Aimbot, P2020Deadzone);
    ReadFloat(Aimbot, P2020FOV1);
    ReadFloat(Aimbot, P2020MinDistance1);
    ReadFloat(Aimbot, P2020MaxDistance1);
    ReadFloat(Aimbot, RE45HipfireSmooth1);
    ReadFloat(Aimbot, RE45ADSSmooth1);
    ReadFloat(Aimbot, RE45ExtraSmooth1);
    ReadFloat(Aimbot, RE45Deadzone);
    ReadFloat(Aimbot, RE45FOV1);
    ReadFloat(Aimbot, RE45MinDistance1);
    ReadFloat(Aimbot, RE45MaxDistance1);
    ReadFloat(Aimbot, AlternatorHipfireSmooth1);
    ReadFloat(Aimbot, AlternatorADSSmooth1);
    ReadFloat(Aimbot, AlternatorExtraSmooth1);
    ReadFloat(Aimbot, AlternatorDeadzone);
    ReadFloat(Aimbot, AlternatorFOV1);
    ReadFloat(Aimbot, AlternatorMinDistance1);
    ReadFloat(Aimbot, AlternatorMaxDistance1);
    ReadFloat(Aimbot, R99HipfireSmooth1);
    ReadFloat(Aimbot, R99ADSSmooth1);
    ReadFloat(Aimbot, R99ExtraSmooth1);
    ReadFloat(Aimbot, R99Deadzone);
    ReadFloat(Aimbot, R99FOV1);
    ReadFloat(Aimbot, R99MinDistance1);
    ReadFloat(Aimbot, R99MaxDistance1);
    ReadFloat(Aimbot, R301HipfireSmooth1);
    ReadFloat(Aimbot, R301ADSSmooth1);
    ReadFloat(Aimbot, R301ExtraSmooth1);
    ReadFloat(Aimbot, R301Deadzone);
    ReadFloat(Aimbot, R301FOV1);
    ReadFloat(Aimbot, R301MinDistance1);
    ReadFloat(Aimbot, R301MaxDistance1);
    ReadFloat(Aimbot, SpitfireHipfireSmooth1);
    ReadFloat(Aimbot, SpitfireADSSmooth1);
    ReadFloat(Aimbot, SpitfireExtraSmooth1);
    ReadFloat(Aimbot, SpitfireDeadzone);
    ReadFloat(Aimbot, SpitfireFOV1);
    ReadFloat(Aimbot, SpitfireMinDistance1);
    ReadFloat(Aimbot, SpitfireMaxDistance1);
    ReadFloat(Aimbot, G7HipfireSmooth1);
    ReadFloat(Aimbot, G7ADSSmooth1);
    ReadFloat(Aimbot, G7ExtraSmooth1);
    ReadFloat(Aimbot, G7Deadzone);
    ReadFloat(Aimbot, G7FOV1);
    ReadFloat(Aimbot, G7MinDistance1);
    ReadFloat(Aimbot, G7MaxDistance1);
    ReadFloat(Aimbot, FlatlineHipfireSmooth1);
    ReadFloat(Aimbot, FlatlineADSSmooth1);
    ReadFloat(Aimbot, FlatlineExtraSmooth1);
    ReadFloat(Aimbot, FlatlineDeadzone);
    ReadFloat(Aimbot, FlatlineFOV1);
    ReadFloat(Aimbot, FlatlineMinDistance1);
    ReadFloat(Aimbot, FlatlineMaxDistance1);
    ReadFloat(Aimbot, HemlockHipfireSmooth1);
    ReadFloat(Aimbot, HemlockADSSmooth1);
    ReadFloat(Aimbot, HemlockExtraSmooth1);
    ReadFloat(Aimbot, HemlockDeadzone);
    ReadFloat(Aimbot, HemlockFOV1);
    ReadFloat(Aimbot, HemlockMinDistance1);
    ReadFloat(Aimbot, HemlockMaxDistance1);
    ReadFloat(Aimbot, RepeaterHipfireSmooth1);
    ReadFloat(Aimbot, RepeaterADSSmooth1);
    ReadFloat(Aimbot, RepeaterExtraSmooth1);
    ReadFloat(Aimbot, RepeaterDeadzone);
    ReadFloat(Aimbot, RepeaterFOV1);
    ReadFloat(Aimbot, RepeaterMinDistance1);
    ReadFloat(Aimbot, RepeaterMaxDistance1);
    ReadFloat(Aimbot, RampageHipfireSmooth1);
    ReadFloat(Aimbot, RampageADSSmooth1);
    ReadFloat(Aimbot, RampageExtraSmooth1);
    ReadFloat(Aimbot, RampageDeadzone);
    ReadFloat(Aimbot, RampageFOV1);
    ReadFloat(Aimbot, RampageMinDistance1);
    ReadFloat(Aimbot, RampageMaxDistance1);
    ReadFloat(Aimbot, CARSMGHipfireSmooth1);
    ReadFloat(Aimbot, CARSMGADSSmooth1);
    ReadFloat(Aimbot, CARSMGExtraSmooth1);
    ReadFloat(Aimbot, CARSMGDeadzone);
    ReadFloat(Aimbot, CARSMGFOV1);
    ReadFloat(Aimbot, CARSMGMinDistance1);
    ReadFloat(Aimbot, CARSMGMaxDistance1);
    ReadFloat(Aimbot, HavocHipfireSmooth1);
    ReadFloat(Aimbot, HavocADSSmooth1);
    ReadFloat(Aimbot, HavocExtraSmooth1);
    ReadFloat(Aimbot, HavocDeadzone);
    ReadFloat(Aimbot, HavocFOV1);
    ReadFloat(Aimbot, HavocMinDistance1);
    ReadFloat(Aimbot, HavocMaxDistance1);
    ReadFloat(Aimbot, DevotionHipfireSmooth1);
    ReadFloat(Aimbot, DevotionADSSmooth1);
    ReadFloat(Aimbot, DevotionExtraSmooth1);
    ReadFloat(Aimbot, DevotionDeadzone);
    ReadFloat(Aimbot, DevotionFOV1);
    ReadFloat(Aimbot, DevotionMinDistance1);
    ReadFloat(Aimbot, DevotionMaxDistance1);
    ReadFloat(Aimbot, LSTARHipfireSmooth1);
    ReadFloat(Aimbot, LSTARADSSmooth1);
    ReadFloat(Aimbot, LSTARExtraSmooth1);
    ReadFloat(Aimbot, LSTARDeadzone);
    ReadFloat(Aimbot, LSTARFOV1);
    ReadFloat(Aimbot, LSTARMinDistance1);
    ReadFloat(Aimbot, LSTARMaxDistance1);
    ReadFloat(Aimbot, TripleTakeHipfireSmooth1);
    ReadFloat(Aimbot, TripleTakeADSSmooth1);
    ReadFloat(Aimbot, TripleTakeExtraSmooth1);
    ReadFloat(Aimbot, TripleTakeDeadzone);
    ReadFloat(Aimbot, TripleTakeFOV1);
    ReadFloat(Aimbot, TripleTakeMinDistance1);
    ReadFloat(Aimbot, TripleTakeMaxDistance1);
    ReadFloat(Aimbot, VoltHipfireSmooth1);
    ReadFloat(Aimbot, VoltADSSmooth1);
    ReadFloat(Aimbot, VoltExtraSmooth1);
    ReadFloat(Aimbot, VoltDeadzone);
    ReadFloat(Aimbot, VoltFOV1);
    ReadFloat(Aimbot, VoltMinDistance1);
    ReadFloat(Aimbot, VoltMaxDistance1);
    ReadFloat(Aimbot, NemesisHipfireSmooth1);
    ReadFloat(Aimbot, NemesisADSSmooth1);
    ReadFloat(Aimbot, NemesisExtraSmooth1);
    ReadFloat(Aimbot, NemesisDeadzone);
    ReadFloat(Aimbot, NemesisFOV1);
    ReadFloat(Aimbot, NemesisMinDistance1);
    ReadFloat(Aimbot, NemesisMaxDistance1);
    ReadFloat(Aimbot, MozambiqueHipfireSmooth1);
    ReadFloat(Aimbot, MozambiqueADSSmooth1);
    ReadFloat(Aimbot, MozambiqueExtraSmooth1);
    ReadFloat(Aimbot, MozambiqueDeadzone);
    ReadFloat(Aimbot, MozambiqueFOV1);
    ReadFloat(Aimbot, MozambiqueMinDistance1);
    ReadFloat(Aimbot, MozambiqueMaxDistance1);
    ReadFloat(Aimbot, EVA8HipfireSmooth1);
    ReadFloat(Aimbot, EVA8ADSSmooth1);
    ReadFloat(Aimbot, EVA8ExtraSmooth1);
    ReadFloat(Aimbot, EVA8Deadzone);
    ReadFloat(Aimbot, EVA8FOV1);
    ReadFloat(Aimbot, EVA8MinDistance1);
    ReadFloat(Aimbot, EVA8MaxDistance1);
    ReadFloat(Aimbot, PeacekeeperHipfireSmooth1);
    ReadFloat(Aimbot, PeacekeeperADSSmooth1);
    ReadFloat(Aimbot, PeacekeeperExtraSmooth1);
    ReadFloat(Aimbot, PeacekeeperDeadzone);
    ReadFloat(Aimbot, PeacekeeperFOV1);
    ReadFloat(Aimbot, PeacekeeperMinDistance1);
    ReadFloat(Aimbot, PeacekeeperMaxDistance1);
    ReadFloat(Aimbot, MastiffHipfireSmooth1);
    ReadFloat(Aimbot, MastiffADSSmooth1);
    ReadFloat(Aimbot, MastiffExtraSmooth1);
    ReadFloat(Aimbot, MastiffDeadzone);
    ReadFloat(Aimbot, MastiffFOV1);
    ReadFloat(Aimbot, MastiffMinDistance1);
    ReadFloat(Aimbot, MastiffMaxDistance1);
    ReadFloat(Aimbot, WingmanHipfireSmooth1);
    ReadFloat(Aimbot, WingmanADSSmooth1);
    ReadFloat(Aimbot, WingmanExtraSmooth1);
    ReadFloat(Aimbot, WingmanDeadzone);
    ReadFloat(Aimbot, WingmanFOV1);
    ReadFloat(Aimbot, WingmanMinDistance1);
    ReadFloat(Aimbot, WingmanMaxDistance1);
    ReadFloat(Aimbot, ProwlerHipfireSmooth1);
    ReadFloat(Aimbot, ProwlerADSSmooth1);
    ReadFloat(Aimbot, ProwlerExtraSmooth1);
    ReadFloat(Aimbot, ProwlerDeadzone);
    ReadFloat(Aimbot, ProwlerFOV1);
    ReadFloat(Aimbot, ProwlerMinDistance1);
    ReadFloat(Aimbot, ProwlerMaxDistance1);
    ReadFloat(Aimbot, BocekHipfireSmooth1);
    ReadFloat(Aimbot, BocekADSSmooth1);
    ReadFloat(Aimbot, BocekExtraSmooth1);
    ReadFloat(Aimbot, BocekDeadzone);
    ReadFloat(Aimbot, BocekFOV1);
    ReadFloat(Aimbot, BocekMinDistance1);
    ReadFloat(Aimbot, BocekMaxDistance1);
    ReadFloat(Aimbot, KraberHipfireSmooth1);
    ReadFloat(Aimbot, KraberADSSmooth1);
    ReadFloat(Aimbot, KraberExtraSmooth1);
    ReadFloat(Aimbot, KraberDeadzone);
    ReadFloat(Aimbot, KraberFOV1);
    ReadFloat(Aimbot, KraberMinDistance1);
    ReadFloat(Aimbot, KraberMaxDistance1);
    ReadFloat(Aimbot, ThrowingKnifeHipfireSmooth1);
    ReadFloat(Aimbot, ThrowingKnifeADSSmooth1);
    ReadFloat(Aimbot, ThrowingKnifeExtraSmooth1);
    ReadFloat(Aimbot, ThrowingKnifeDeadzone);
    ReadFloat(Aimbot, ThrowingKnifeFOV1);
    ReadFloat(Aimbot, ThrowingKnifeMinDistance1);
    ReadFloat(Aimbot, ThrowingKnifeMaxDistance1);

    ReadBool(RCS, RCSEnabled);
    ReadBool(RCS, OnADS);
    ReadFloat(RCS, PitchPower);
    ReadFloat(RCS, YawPower);
        //Weapons
    //Light
    ReadBool(RCS, P2020);
    ReadBool(RCS, RE45);
    ReadBool(RCS, Alternator);
    ReadBool(RCS, R99);
    ReadBool(RCS, R301);
    ReadBool(RCS, Spitfire);
    ReadBool(RCS, G7);
    //Heavy
    ReadBool(RCS, Flatline);
    ReadBool(RCS, Hemlock);
    ReadBool(RCS, Repeater);
    ReadBool(RCS, Rampage);
    ReadBool(RCS, CARSMG);
    //Energy
    ReadBool(RCS, Havoc);
    ReadBool(RCS, Devotion);
    ReadBool(RCS, LSTAR);
    ReadBool(RCS, TripleTake);
    ReadBool(RCS, Volt);
    ReadBool(RCS, Nemesis);
    //Shotgun
    ReadBool(RCS, Mozambique);
    ReadBool(RCS, EVA8);
    ReadBool(RCS, Peacekeeper);
    ReadBool(RCS, Mastiff);
    //Snipers
    ReadBool(RCS, Longbow);
    ReadBool(RCS, ChargeRifle);
    ReadBool(RCS, Sentinel);
    //Legendary
    ReadBool(RCS, Wingman); //Emotional damage!
    ReadBool(RCS, Prowler);
    ReadBool(RCS, Kraber);

    //---------------Advanced---------------//
    ReadBool(RCS, AdvancedRCS);
        //Weapons
    //Light
    ReadFloat(RCS, P2020Pitch);
    ReadFloat(RCS, P2020Yaw);
    ReadFloat(RCS, RE45Pitch);
    ReadFloat(RCS, RE45Yaw);
    ReadFloat(RCS, AlternatorPitch);
    ReadFloat(RCS, AlternatorYaw);
    ReadFloat(RCS, R99Pitch);
    ReadFloat(RCS, R99Yaw);
    ReadFloat(RCS, R301Pitch);
    ReadFloat(RCS, R301Yaw);
    ReadFloat(RCS, SpitfirePitch);
    ReadFloat(RCS, SpitfireYaw);
    ReadFloat(RCS, G7Pitch);
    ReadFloat(RCS, G7Yaw);
    //Heavy
    ReadFloat(RCS, FlatlinePitch);
    ReadFloat(RCS, FlatlineYaw);
    ReadFloat(RCS, HemlockPitch);
    ReadFloat(RCS, HemlockYaw);
    ReadFloat(RCS, RepeaterPitch);
    ReadFloat(RCS, RepeaterYaw);
    ReadFloat(RCS, RampagePitch);
    ReadFloat(RCS, RampageYaw);
    ReadFloat(RCS, CARSMGPitch);
    ReadFloat(RCS, CARSMGYaw);
    //Energy
    ReadFloat(RCS, HavocPitch);
    ReadFloat(RCS, HavocYaw);
    ReadFloat(RCS, DevotionPitch);
    ReadFloat(RCS, DevotionYaw);
    ReadFloat(RCS, LSTARPitch);
    ReadFloat(RCS, LSTARYaw);
    ReadFloat(RCS, TripleTakePitch);
    ReadFloat(RCS, TripleTakeYaw);
    ReadFloat(RCS, VoltPitch);
    ReadFloat(RCS, VoltYaw);
    ReadFloat(RCS, NemesisPitch);
    ReadFloat(RCS, NemesisYaw);
    //Shotgun
    ReadFloat(RCS, MozambiquePitch);
    ReadFloat(RCS, MozambiqueYaw);
    ReadFloat(RCS, EVA8Pitch);
    ReadFloat(RCS, EVA8Yaw);
    ReadFloat(RCS, PeacekeeperPitch);
    ReadFloat(RCS, PeacekeeperYaw);
    ReadFloat(RCS, MastiffPitch);
    ReadFloat(RCS, MastiffYaw);
    //Snipers
    ReadFloat(RCS, LongbowPitch);
    ReadFloat(RCS, LongbowYaw);
    ReadFloat(RCS, ChargeRiflePitch);
    ReadFloat(RCS, ChargeRifleYaw);
    ReadFloat(RCS, SentinelPitch);
    ReadFloat(RCS, SentinelYaw);
    //Legendary
    ReadFloat(RCS, WingmanPitch);
    ReadFloat(RCS, WingmanYaw);
    ReadFloat(RCS, ProwlerPitch);
    ReadFloat(RCS, ProwlerYaw);
    ReadFloat(RCS, KraberPitch);
    ReadFloat(RCS, KraberYaw);

    ReadBool(Glow, GlowEnabled);
    ReadBool(Glow, ItemGlow);
    ReadFloat(Glow, GlowMaxDistance);
    ReadBool(Glow, NewGlow);
    ReadInt(Glow, GlowColorMode);
    ReadInt(Glow, GlowColorShieldMode);
    ReadInt(Glow, GlowRadius);
    ReadInt(Glow, InsideFunction);
    ReadInt(Glow, OutlineFunction);
    ReadInt(Glow, BodyStyle);
    ReadInt(Glow, OutlineStyle);
    ReadFloat(Glow, InvisibleGlowColorR);
    ReadFloat(Glow, InvisibleGlowColorG);
    ReadFloat(Glow, InvisibleGlowColorB);
    ReadFloat(Glow, VisibleGlowColorR);
    ReadFloat(Glow, VisibleGlowColorG);
    ReadFloat(Glow, VisibleGlowColorB);
    ReadFloat(Glow, LowGlowColorR);
    ReadFloat(Glow, LowGlowColorG);
    ReadFloat(Glow, LowGlowColorB);
    ReadFloat(Glow, RedShieldColorR);
    ReadFloat(Glow, RedShieldColorG);
    ReadFloat(Glow, RedShieldColorB);
    ReadFloat(Glow, PurpleShieldColorR);
    ReadFloat(Glow, PurpleShieldColorG);
    ReadFloat(Glow, PurpleShieldColorB);
    ReadFloat(Glow, BlueShieldColorR);
    ReadFloat(Glow, BlueShieldColorG);
    ReadFloat(Glow, BlueShieldColorB);
    ReadFloat(Glow, GreyShieldColorR);
    ReadFloat(Glow, GreyShieldColorG);
    ReadFloat(Glow, GreyShieldColorB);

    ReadBool(Sense, VisibilityCheck);
    ReadBool(Sense, DrawBoxes);
    ReadInt(Sense, BoxType);
    ReadInt(Sense, BoxStyle);
    ReadFloat(Sense, BoxThickness);
    ReadBool(Sense, Skeleton);
    ReadFloat(Sense, SkeletonThickness);
    ReadBool(Sense, HealthBar);
    ReadBool(Sense, ShieldBar);
    ReadBool(Sense, drawlvl);

    ReadInt(Sense, BarMode);
    ReadInt(Sense, BarStyle);
    ReadInt(Sense, BarColorMode);
    ReadBool(Sense, BarBackground);
    ReadFloat(Sense, BarThickness);
    ReadFloat(Sense, BarThickness2);
    ReadFloat(Sense, BarHeight);
    ReadFloat(Sense, BarWidth);
    ReadInt(Sense, ESPMaxDistance);
    ReadBool(Sense, ShowNear);
    ReadBool(Sense, DrawSeer);
    ReadBool(Sense, DrawStatus);
    ReadBool(Sense, DrawWeapon);
    ReadInt(Sense, WeaponColorType);
    ReadBool(Sense, ShowLegend);
    ReadBool(Sense, ShowMaxStatusValues);
    ReadBool(Sense, DrawDistance);
    ReadBool(Sense, DrawFOVCircle);
    ReadBool(Sense, DrawFilledFOVCircle);
    ReadFloat(Sense, FOVThickness);
    ReadBool(Sense, DrawNames);
    ReadInt(Sense, TracerPos);
    ReadInt(Sense, TracerBone);
    ReadBool(Sense, DrawTracers);
    ReadFloat(Sense, TracerThickness);
    ReadBool(Sense, ShowSpectators);
    ReadBool(Sense, DrawCrosshair);
    ReadFloat(Sense, CrosshairSize);
    ReadFloat(Sense, CrosshairThickness);

    //Colors
    ReadFloat(Colors, InvisibleBoxColorR);
    ReadFloat(Colors, InvisibleBoxColorG);
    ReadFloat(Colors, InvisibleBoxColorB);
    ReadFloat(Colors, InvisibleBoxColorA);
    ReadFloat(Colors, VisibleBoxColorR);
    ReadFloat(Colors, VisibleBoxColorG);
    ReadFloat(Colors, VisibleBoxColorB);
    ReadFloat(Colors, VisibleBoxColorA);
    ReadFloat(Colors, InvisibleFilledBoxColorR);
    ReadFloat(Colors, InvisibleFilledBoxColorG);
    ReadFloat(Colors, InvisibleFilledBoxColorB);
    ReadFloat(Colors, InvisibleFilledBoxColorA);
    ReadFloat(Colors, VisibleFilledBoxColorR);
    ReadFloat(Colors, VisibleFilledBoxColorG);
    ReadFloat(Colors, VisibleFilledBoxColorB);
    ReadFloat(Colors, VisibleFilledBoxColorA);
    ReadFloat(Colors, InvisibleTracerColorR);
    ReadFloat(Colors, InvisibleTracerColorG);
    ReadFloat(Colors, InvisibleTracerColorB);
    ReadFloat(Colors, InvisibleTracerColorA);
    ReadFloat(Colors, VisibleTracerColorR);
    ReadFloat(Colors, VisibleTracerColorG);
    ReadFloat(Colors, VisibleTracerColorB);
    ReadFloat(Colors, VisibleTracerColorA);
    ReadFloat(Colors, InvisibleSkeletonColorR);
    ReadFloat(Colors, InvisibleSkeletonColorG);
    ReadFloat(Colors, InvisibleSkeletonColorB);
    ReadFloat(Colors, InvisibleSkeletonColorA);
    ReadFloat(Colors, VisibleSkeletonColorR);
    ReadFloat(Colors, VisibleSkeletonColorG);
    ReadFloat(Colors, VisibleSkeletonColorB);
    ReadFloat(Colors, VisibleSkeletonColorA);
    ReadFloat(Colors, InvisibleNameColorR);
    ReadFloat(Colors, InvisibleNameColorG);
    ReadFloat(Colors, InvisibleNameColorB);
    ReadFloat(Colors, InvisibleNameColorA);
    ReadFloat(Colors, VisibleNameColorR);
    ReadFloat(Colors, VisibleNameColorG);
    ReadFloat(Colors, VisibleNameColorB);
    ReadFloat(Colors, VisibleNameColorA);
    ReadFloat(Colors, InvisibleDistanceColorR);
    ReadFloat(Colors, InvisibleDistanceColorG);
    ReadFloat(Colors, InvisibleDistanceColorB);
    ReadFloat(Colors, InvisibleDistanceColorA);
    ReadFloat(Colors, VisibleDistanceColorR);
    ReadFloat(Colors, VisibleDistanceColorG);
    ReadFloat(Colors, VisibleDistanceColorB);
    ReadFloat(Colors, VisibleDistanceColorA);
    ReadFloat(Colors, InvisibleLegendColorR);
    ReadFloat(Colors, InvisibleLegendColorG);
    ReadFloat(Colors, InvisibleLegendColorB);
    ReadFloat(Colors, InvisibleLegendColorA);
    ReadFloat(Colors, VisibleLegendColorR);
    ReadFloat(Colors, VisibleLegendColorG);
    ReadFloat(Colors, VisibleLegendColorB);
    ReadFloat(Colors, VisibleLegendColorA);
    ReadFloat(Colors, FOVColorR);
    ReadFloat(Colors, FOVColorG);
    ReadFloat(Colors, FOVColorB);
    ReadFloat(Colors, FOVColorA);
    ReadFloat(Colors, FilledFOVColorR);
    ReadFloat(Colors, FilledFOVColorG);
    ReadFloat(Colors, FilledFOVColorB);
    ReadFloat(Colors, FilledFOVColorA);
    ReadFloat(Colors, VisibleWeaponColorR);
    ReadFloat(Colors, VisibleWeaponColorG);
    ReadFloat(Colors, VisibleWeaponColorB);
    ReadFloat(Colors, VisibleWeaponColorA);
    ReadFloat(Colors, InvisibleWeaponColorR);
    ReadFloat(Colors, InvisibleWeaponColorG);
    ReadFloat(Colors, InvisibleWeaponColorB);
    ReadFloat(Colors, InvisibleWeaponColorA);
    ReadFloat(Colors, NearColorR);
    ReadFloat(Colors, NearColorG);
    ReadFloat(Colors, NearColorB);
    ReadFloat(Colors, NearColorA);
    ReadFloat(Colors, TeamColorR);
    ReadFloat(Colors, TeamColorG);
    ReadFloat(Colors, TeamColorB);
    ReadFloat(Colors, TeamColorA);
    ReadFloat(Colors, TeamNameColorR);
    ReadFloat(Colors, TeamNameColorG);
    ReadFloat(Colors, TeamNameColorB);
    ReadFloat(Colors, TeamNameColorA);
    ReadFloat(Colors, CrosshairColorR);
    ReadFloat(Colors, CrosshairColorG);
    ReadFloat(Colors, CrosshairColorB);
    ReadFloat(Colors, CrosshairColorA);

    ReadFloat(Colors, LightWeaponColorR);
    ReadFloat(Colors, LightWeaponColorG);
    ReadFloat(Colors, LightWeaponColorB);
    ReadFloat(Colors, LightWeaponColorA);
    ReadFloat(Colors, HeavyWeaponColorR);
    ReadFloat(Colors, HeavyWeaponColorG);
    ReadFloat(Colors, HeavyWeaponColorB);
    ReadFloat(Colors, HeavyWeaponColorA);
    ReadFloat(Colors, EnergyWeaponColorR);
    ReadFloat(Colors, EnergyWeaponColorG);
    ReadFloat(Colors, EnergyWeaponColorB);
    ReadFloat(Colors, EnergyWeaponColorA);
    ReadFloat(Colors, ShotgunWeaponColorR);
    ReadFloat(Colors, ShotgunWeaponColorG);
    ReadFloat(Colors, ShotgunWeaponColorB);
    ReadFloat(Colors, ShotgunWeaponColorA);
    ReadFloat(Colors, SniperWeaponColorR);
    ReadFloat(Colors, SniperWeaponColorG);
    ReadFloat(Colors, SniperWeaponColorB);
    ReadFloat(Colors, SniperWeaponColorA);
    ReadFloat(Colors, LegendaryWeaponColorR);
    ReadFloat(Colors, LegendaryWeaponColorG);
    ReadFloat(Colors, LegendaryWeaponColorB);
    ReadFloat(Colors, LegendaryWeaponColorA);
    ReadFloat(Colors, MeleeWeaponColorR);
    ReadFloat(Colors, MeleeWeaponColorG);
    ReadFloat(Colors, MeleeWeaponColorB);
    ReadFloat(Colors, MeleeWeaponColorA);
    ReadFloat(Colors, ThrowableWeaponColorR);
    ReadFloat(Colors, ThrowableWeaponColorG);
    ReadFloat(Colors, ThrowableWeaponColorB);
    ReadFloat(Colors, ThrowableWeaponColorA);

    ReadBool(Triggerbot, Enabled);
    ReadFloat(Triggerbot, Range);
    ReadBool(Triggerbot, OnADS);
    ReadBool(Triggerbot, HipfireShotguns);
        //Weapons
    //Light
    ReadBool(Triggerbot, P2020);
    ReadBool(Triggerbot, RE45);
    ReadBool(Triggerbot, Alternator);
    ReadBool(Triggerbot, R99);
    ReadBool(Triggerbot, R301);
    ReadBool(Triggerbot, Spitfire);
    ReadBool(Triggerbot, G7);
    //Heavy
    ReadBool(Triggerbot, Flatline);
    ReadBool(Triggerbot, Hemlock);
    ReadBool(Triggerbot, Repeater);
    ReadBool(Triggerbot, Rampage);
    ReadBool(Triggerbot, CARSMG);
    //Energy
    ReadBool(Triggerbot, Havoc);
    ReadBool(Triggerbot, Devotion);
    ReadBool(Triggerbot, LSTAR);
    ReadBool(Triggerbot, TripleTake);
    ReadBool(Triggerbot, Volt);
    ReadBool(Triggerbot, Nemesis);
    //Shotgun
    ReadBool(Triggerbot, Mozambique);
    ReadBool(Triggerbot, EVA8);
    ReadBool(Triggerbot, Peacekeeper);
    ReadBool(Triggerbot, Mastiff);
    //Snipers
    ReadBool(Triggerbot, Longbow);
    ReadBool(Triggerbot, ChargeRifle);
    ReadBool(Triggerbot, Sentinel);
    //Legendary
    ReadBool(Triggerbot, Wingman); //Emotional damage!
    ReadBool(Triggerbot, Prowler);
    ReadBool(Triggerbot, Bocek);
    ReadBool(Triggerbot, Kraber);
    ReadBool(Triggerbot, Knife);

    ReadBool(Radar, MiniMap);
    ReadFloat(Radar, MiniMapRange);
    ReadInt(Radar, MiniMapScaleX);
    ReadInt(Radar, MiniMapScaleY);
    ReadInt(Radar, MiniMapDotSize);
    ReadBool(Radar, MiniMapGuides);
    ReadBool(Radar, BigMap);

    ReadBool(Misc, SkinChanger);
    ReadBool(Misc, AutoGrapple);
    ReadBool(Misc, SuperGlide);
    //Weapons
    //Light
    ReadInt(Misc, SkinP2020);
    ReadInt(Misc, SkinRE45);
    ReadInt(Misc, SkinALTERNATOR);
    ReadInt(Misc, SkinR99);
    ReadInt(Misc, SkinR301);
    ReadInt(Misc, SkinSPITFIRE);
    ReadInt(Misc, SkinG7);
    //Heavy
    ReadInt(Misc, SkinFLATLINE);
    ReadInt(Misc, SkinHEMLOCK);
    ReadInt(Misc, SkinREPEATER);
    ReadInt(Misc, SkinRAMPAGE);
    ReadInt(Misc, SkinCAR);
    //Energy
    ReadInt(Misc, SkinHAVOC);
    ReadInt(Misc, SkinDEVOTION);
    ReadInt(Misc, SkinLSTAR);
    ReadInt(Misc, SkinTRIPLETAKE);
    ReadInt(Misc, SkinVOLT);
    ReadInt(Misc, SkinNEMESIS);
    //Shotgun
    ReadInt(Misc, SkinMOZAMBIQUE);
    ReadInt(Misc, SkinEVA8);
    ReadInt(Misc, SkinPEACEKEEPER);
    ReadInt(Misc, SkinMASTIFF);
    //Snipers
    ReadInt(Misc, SkinLONGBOW);
    ReadInt(Misc, SkinCHARGE_RIFLE);
    ReadInt(Misc, SkinSENTINEL);
    //Legendary
    ReadInt(Misc, SkinWINGMAN);
    ReadInt(Misc, SkinPROWLER);
    ReadInt(Misc, SkinKRABER);
    ReadInt(Misc, SkinBOCEK);

    ReadInt(Home, AsciiArt);
    ReadInt(Home, AsciiArtSpeed);
    ReadBool(Home, TeamGamemode);
    ReadInt(Home, MenuX);
    ReadInt(Home, MenuY);
    ReadInt(Home, Style);
    ReadInt(Home, Color);
    ReadBool(Home, ErrorLogging);

    UpdateConfig();
    return true;
}
