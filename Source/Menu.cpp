
#include "stdafx.h"
#include "stdafx.h"
#include <experimental/filesystem>
#include <regex>
#include <type_traits>
namespace fs = std::experimental::filesystem;
static char* filter = "";
static bool filterOn = false;
std::vector<std::string> vehModels = {
	"NINEF", "NINEF2", "BLISTA", "ASEA", "ASEA2", "T20", "BRAWLER", "COQUETTE3", "VINDICATOR"
	"COACH", "AIRBUS", "ASTEROPE", "AIRTUG", "AMBULANCE", "BARRACKS", "BARRACKS2", "BALLER", "BALLER2",
	"BJXL", "BANSHEE", "BENSON", "BFINJECTION", "BIFF", "BLAZER", "BLAZER2", "BLAZER3", "BISON", "BISON2",
	"BISON3", "BOXVILLE", "BOXVILLE2", "BOXVILLE3", "BOBCATXL", "BODHI2", "BUCCANEER", "BUFFALO", "BUFFALO2", "BULLDOZER",
	"BULLET", "BURRITO", "BURRITO2", "BURRITO3", "BURRITO4", "BURRITO5", "CAVALCADE", "CAVALCADE2", "POLICET",
	"GBURRITO", "CABLECAR", "CADDY", "CADDY2", "CAMPER", "CARBONIZZARE", "CHEETAH", "COMET2", "COGCABRIO", "COQUETTE",
	"CUTTER", "GRESLEY", "DILETTANTE", "DILETTANTE2", "DUNE", "DUNE2", "HOTKNIFE", "DLOADER", "DUBSTA", "DUBSTA2",
	"DUMP", "RUBBLE", "DOCKTUG", "DOMINATOR", "EMPEROR", "EMPEROR2", "EMPEROR3", "ENTITYXF", "EXEMPLAR", "ELEGY2",
	"F620", "FBI", "FBI2", "FELON", "FELON2", "FELTZER2", "FIRETRUK", "FLATBED", "FORKLIFT", "FQ2",
	"FUSILADE", "FUGITIVE", "FUTO", "GRANGER", "GAUNTLET", "HABANERO", "HAULER", "HANDLER", "INFERNUS", "INGOT",
	"INTRUDER", "ISSI2", "JACKAL", "JOURNEY", "JB700", "KHAMELION", "LANDSTALKER", "LGUARD", "MANANA", "MESA",
	"MESA2", "MESA3", "CRUSADER", "MINIVAN", "MIXER", "MIXER2", "MONROE", "MOWER", "MULE", "MULE2",
	"ORACLE", "ORACLE2", "PACKER", "PATRIOT", "PBUS", "PENUMBRA", "PEYOTE", "PHANTOM", "PHOENIX", "PICADOR",
	"POUNDER", "POLICE", "POLICE4", "POLICE2", "POLICE3", "POLICEOLD1", "POLICEOLD2", "PONY", "PONY2", "PRAIRIE",
	"PRANGER", "PREMIER", "PRIMO", "RANCHERXL", "RANCHERXL2", "RAPIDGT", "RAPIDGT2", "RADI", "RATLOADER",
	"REBEL", "REGINA", "REBEL2", "RENTALBUS", "RUINER", "RUMPO", "RUMPO2", "RHINO", "RIOT", "RIPLEY",
	"ROCOTO", "ROMERO", "SABREGT", "SADLER", "SADLER2", "SANDKING", "SANDKING2", "SCHAFTER2", "SCHWARZER", "SCRAP",
	"SEMINOLE", "SENTINEL", "SENTINEL2", "ZION", "ZION2", "SERRANO", "SHERIFF", "SHERIFF2", "SPEEDO", "SPEEDO2",
	"STANIER", "STINGER", "STINGERGT", "STOCKADE", "STOCKADE3", "STRATUM", "SULTAN", "SUPERD", "SURANO", "SURFER",
	"SURFER2", "SURGE", "TACO", "TAILGATER", "TAXI", "TRASH", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"TIPTRUCK", "TIPTRUCK2", "TORNADO", "TORNADO2", "TORNADO3", "TORNADO4", "TOURBUS", "TOWTRUCK", "TOWTRUCK2",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3", "VOODOO2", "WASHINGTON", "STRETCH", "YOUGA", "ZTYPE", "SANCHEZ", "SANCHEZ2",
	"POLICEB", "AKUMA", "CARBONRS", "HEXER", "NEMESIS", "ADDER", "VOLTIC", "VACCA", "BIFTA",
	"BAGGER", "BATI", "BATI2", "RUFFIAN", "DAEMON", "DOUBLE", "PCJ", "VADER", "VIGERO", "FAGGIO2",
	"PARADISE", "KALAHARI", "JESTER", "TURISMOR", "ALPHA", "HUNTLEY", "THRUST", "MASSACRO",
	"MASSACRO2", "ZENTORNO", "BLADE", "GLENDALE", "PANTO", "PIGALLE", "WARRENER", "RHAPSODY", "DUBSTA3", "MONSTER",
	"SOVEREIGN", "INNOVATION", "HAKUCHOU", "FUROREGT", "COQUETTE2", "BTYPE", "BUFFALO3", "DOMINATOR2", "GAUNTLET2",
	"MARSHALL", "DUKES", "DUKES2", "STALION", "STALION2", "BLISTA2", "BLISTA3", "VIRGO", "WINDSOR",
	"INSURGENT", "INSURGENT2", "TECHNICAL", "KURUMA", "KURUMA2", "JESTER2", "CASCO",
	"GUARDIAN", "ENDURO", "LECTRO", "SLAMVAN", "SLAMVAN2", "RATLOADER2", "FELTZER3", "OSIRIS"
};
bool gifen = false;
int gifi = 1;
float step = 0.0001f;
//std::vector<std::string> filenames;
struct PropPackInfo {
	std::string prop;
	std::string desc;

};
typedef struct 
{
	char* user_friendly;
	char* spritename;
} spritename ;
std::vector<spritename> spriteNames {
	{ "Purple Dragon", "dragon" },
	{ "Bansilon", "gaysilon" },
	{ "Yellow-Red Gradient", "grad" },
	{ "Harry Potter", "potter" },
	{ "Star Wars", "Star-Wars" }
};
std::vector<std::string> spriteStrings{
	"Purple Dragon",
	"Bansilon",
	"Yellow-Red Gradient",
	"Harry Potter",
	"Star Wars"
};





std::vector<gifInfo> gifNames{
	{ "goku", "goku-", 45  },
	{ "light", "light", 64 },
};
std::vector<std::string> gifStrings{
	"Goku",
	"Star Wars"
};
int strings = 1;
struct PropPack {
	//std::string propname;
	//std::string optionname;
	std::vector<std::string> propnames;
	std::vector<std::string> optionnames;
	//PropPackInfo AddonInfo;
	//PropPackInfo k;
	//int size;
};
PropPack  getPropAddon(std::string name) {
	XML file;
	file.open("Sinister/Addons/Props/" + name);
	file.openNode("PropSpawnerInfo");
	int xd = file.getInt("Size");
	std::vector<std::string> propnames;
	std::vector<std::string> optionnames;
	for (int i = 1; i < xd; ++i) {
		std::string Name = file.getChar("PropName" + i);
		std::string Desc = file.getChar("PropOptionLabel" + i);
		propnames.push_back(Name);
		optionnames.push_back(Desc);
	}
	file.closeNode();
	//PropPackInfo
	return{ propnames,optionnames };
}
PropPackInfo getBasicPropAddoninfo(std::string name) {
	XML file;
	file.open("Sinister/Addons/Props/" + name);
	file.openNode("PropBasicInfo");
	std::string Name = file.getChar("PackName");
	std::string Desc = file.getChar("PackInfo");
	file.closeNode();
	return{ Name, Desc };
}
std::vector<std::string> GetFilenames(std::string Path)
{
	fs::path directory(Path);
	fs::directory_iterator iter(directory), end;
	std::vector<std::string> FileNames;
	for (; iter != end; ++iter)
	{
		if (iter->path().extension() == ".sinister")
		{
			std::stringstream temp;
			temp << iter->path().filename();
			FileNames.push_back(temp.str());
		}
	}
	std::vector<std::string>lul = FileNames;
	return lul;
}

// GetFilesInDirectory
//std::string getAllFilesInDirectory;
std::string currentPropPack;
bool spawnVehicleOnPlayer = false;
static char* globalTitleText;
char* redisgay;
bool ClownLoop = 0;
bool fireworkloop = 0;
bool effectgun = 0;
bool alien1 = 0;
bool alien2 = 0;
bool electric = 0;
bool watereffect = 0;
bool bloodeffect = 0;
bool smokeeffect = 0;
bool shootrockets = 0;
bool ant7 = 0;
bool ant8 = 0;
bool ant9 = 0;
bool Tunable_Kick = false;
bool noclip = 0;
int shootmodelpos = 0;
float get_distance2(Vector3* pointA, Vector3* pointB)
{
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;

	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;

	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);

	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;

	return (float)std::sqrt(sum_2 + z_ba);
}

Vector3 add2(Vector3* vectorA, Vector3* vectorB)
{
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;

	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;

	return result;
}
Vector3 multiply2(Vector3* vector, float x)
{
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;

	result.x *= x;
	result.y *= x;
	result.z *= x;

	return result;
}
Vector3 rot_to_direction2(Vector3* rot)
{
	float radiansZ = rot->z * 0.0174532924f;
	float radiansX = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)std::sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radiansZ)) * (double)num);
	dir.z = (float)std::sin((double)radiansX);
	return dir;
}
void shootveh(bool toggle) {
	if (shootveh)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		FLOAT heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		DWORD model = GAMEPLAY::GET_HASH_KEY((char*)vehModels[shootmodelpos].c_str());// should be good now
		Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 dir = rot_to_direction2(&rot);
		Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float spawnDistance = get_distance2(&camPosition, &playerPosition);
		spawnDistance += 5;
		Vector3 spawnPosition = add2(&camPosition, &multiply2(&dir, spawnDistance));

		if (bPlayerExists)
		{
			if (PED::IS_PED_SHOOTING(playerPed))
			{
				Vector3 playerOffset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 5, 0);
				if (PED::IS_PED_ON_FOOT(playerPed))
				{
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					{
						Vehicle veh = VEHICLE::CREATE_VEHICLE(model, spawnPosition.x, spawnPosition.y, spawnPosition.z, heading, 1, 1);
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 120.0);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
						ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
					}

				}
			}
		}
	}
}
float WaveyBro = 0.00f;
int Doomsday = 0;
int Smugglers = 0;
int GunRunning = 0;
int Super = 0;
int Sports = 0;
int SportClassic = 0;
int Offroad = 0;
int Sedans = 0;
int Coupes = 0;
int Muscle = 0;
int Boats = 0;
int Commercial = 0;
int Compacts = 0;
int Cycles = 0;
int Emergency = 0;
int Helicopters = 0;
int Industrial = 0;
int Military = 0;
int Motorcycles = 0;
int Planes = 0;
int Service = 0;
int SUV = 0;
int Trailer = 0;
int Trains = 0;
int Utility = 0;
int Vans = 0;
int lol = 1;
int eclone[1000];
int egcount = 1;
int clone[1000];
int gcount = 1;
int timeer = 0;
int hattex = 0;
int glasstex = 0;
int eartex = 0;
int torsotex = 0;
int legtex = 0;
int handtex = 0;
int watchtex = 0;
int special1tex = 0;
int special2tex = 0;
int special3tex = 0;
int torso2tex = 0;
int mask = 0;
int masktex = 0;
int shoes = 0;
int shoetex = 0;
int Face_ = 0;
int Glasses_ = 0;
int Ears_ = 0;
int Mask_ = 0;
int Hair_ = 0;
int Torso_ = 0;
int Legs_ = 0;
int Hands_ = 0;
int Shoes_ = 0;
int Watches_ = 0;
int Special1_ = 0;
int Special2_ = 0;
int Special3_ = 0;
int Texture_ = 0;
int Torso2_ = 0;
int Spoilers_ = 0;
int Tint_ = 0;
int Interior_ = 0;
int Grill_ = 0;
int Exhaust_ = 0;
int Skirts_ = 0;
int Suspension_ = 0;
int Hoods_ = 0;
int Bumpers_ = 0;
int Transmission_ = 0;
int Brakes_ = 0;
int Armor_ = 0;
int Colour_ = 0;
int Prim_ = 0;
int Green_ = 0;
int horns = 0;
int Sec_ = 0;
int Red_ = 0;
int Blue_ = 0;
int KeyboardIndex = 0;
int selectedModType;
bool g_bKeyBoardDisplayed = false;
bool PTLoopedOBool[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
std::string PlayerName(int Player) {
	if (IsPlayerFriend(Player)) {
		return PLAYER::GET_PLAYER_NAME(Player) + (std::string)"~G~[FRIEND]";
	}
	else {
		return PLAYER::GET_PLAYER_NAME(Player);
	}
}
string name = "";
string pw = "";
Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
Ped playerPed = PLAYER::PLAYER_PED_ID();
Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
Vehicle CurrentVehicle = PLAYER::GET_PLAYERS_LAST_VEHICLE();// waittttt wtf
Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0.0, 5.0, 0.0);
char* keyboard(char* windowName = "", int maxInput = 100, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
void drawfloat(float text, DWORD decimal_places, float X, float Y)
{
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
	UI::ADD_TEXT_COMPONENT_FLOAT(text, decimal_places);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(X, Y);
}

float menuPos = 0, OptionY;
unsigned __int16 printingop = 0;
unsigned __int16 currentop = 0;
string FloatToString(float flt) {
	std::ostringstream ss;
	ss << flt;
	std::string str(ss.str());
	return str;
}
void AddClothingProp(int BodyID, int Part, int &Variation) {
	int null = 0;
	int textureVariations = PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), BodyID, Part) - 2;
	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), BodyID, Part, 0, 2);// try dis kk now login s
}
void AddCloth(int BodyID, int Part, int &Variation) {
	if (Menu::Main::Option(FloatToString(Part)))
	{
		int textureVariations = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), BodyID, Part) - 2;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), BodyID, Part, 0, 2);
	}// try dis kk now login s
}

void PrintStringBottomCentre3(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}


std::vector<std::string> Smugglers1 = {
	"Bombushka",
	"Vigilante",
	"Alpha Z1",
	"Tula",
	"Hunter",
	"Rogue",
	"Pyro",
	"Mogul",
	"Nokota",
	"Molotok",
	"Seabreeze",
	"Havok",
	"Microlight",
	"Howard",
	"Starling",
	"RAPIDGT 3",
	"Retinue",
	"Cyclone",
	"Visione",
};
std::vector<std::string> Doomsday1 = {
	"autarch", "avenger", "barrage", "chernobog", "comet4", "comet5", "deluxo",
	"gt500", "hermes", "hustler", "kamacho",  "khanjali", "neon", "pariah", "raiden",
	"revolter", "riata0", "riot2", "savestra", "sc1", "sentinel3", "streiter", "stromberg",
	"thruster", "viseris", "volatol", "yosemite", "z190",
};


std::vector<std::string> GunRunning1 = {
	"APC", "Ardent", "Caddy3", "Cheetah2", "Dune3", "Halftrack", "Hauler2", "Insurgent3",
	"Nightshark", "Oppressor", "Phantom3", "Tampa3", "Technical13", "Torero", "Trailerlarge",
	"Trailers4", "Trailersma112", "Vagner", "Xa21",
};
std::vector<std::string> Boats1 = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};
std::vector<std::string> Commercial1 = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
};
std::vector<std::string> Compacts1 = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
};
std::vector<std::string> Coupes1 = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
};
std::vector<std::string> Cycles1 = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};
std::vector<std::string> Emergency1 = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
};
std::vector<std::string> Helicopters1 = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
};
std::vector<std::string> Industrial1 = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};
std::vector<std::string> Military1 = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
};
std::vector<std::string> Motorcycles1 = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2"
};
std::vector<std::string> Muscle1 = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
};
std::vector<std::string> OffRoad1 = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5"
};
std::vector<std::string> Planes1 = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
};
std::vector<std::string> Sedans1 = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
};
std::vector<std::string> Service1 = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER",
};
std::vector<std::string> Sports1 = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON"
};
std::vector<std::string> SportsClassics1 = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2",
};

std::vector<std::string> Super1 = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1"
};
std::vector<std::string> SUVs1 = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
};
std::vector<std::string> Trailer1 = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
};
std::vector<std::string> Trains1 = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};
std::vector<std::string> Utility1 = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "REY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};
std::vector<std::string> Vans1 = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};

char* pedModels[] = {
	"A_C_Boar","A_C_Chickenhawk","A_C_Chimp","A_C_Chop","A_C_Cormorant","A_C_Cow","A_C_Coyote","A_C_Crow","A_C_Deer","A_C_Fish","A_C_Hen","A_C_Husky","A_C_MtLion","A_C_Pig","A_C_Pigeon","A_C_Rat","A_C_Retriever",
	"A_C_Rhesus","A_C_Rottweiler","A_C_Seagull","A_C_SharkTiger","A_C_shepherd","A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02",
	"A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Tennis_01","A_F_Y_Topless_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01","A_M_M_ACult_01","A_M_M_AfriAmer_01","A_M_M_Beach_01","A_M_M_Beach_02","A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
	"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
	"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
	"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
	"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
	"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02","A_M_Y_Beach_01","A_M_Y_Beach_02","A_M_Y_Beach_03","A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02","A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03","A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02",
	"A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02","A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01","A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02","A_M_Y_MusclBeac_01",
	"A_M_Y_MusclBeac_02","A_M_Y_Polynesian_01","A_M_Y_RoadCyc_01","A_M_Y_Runner_01","A_M_Y_Runner_02","A_M_Y_Salton_01","A_M_Y_Skater_01","A_M_Y_Skater_02","A_M_Y_SouCent_01","A_M_Y_SouCent_02","A_M_Y_SouCent_03","A_M_Y_SouCent_04",
	"A_M_Y_StBla_01","A_M_Y_StBla_02","A_M_Y_StLat_01","A_M_Y_StWhi_01","A_M_Y_StWhi_02","A_M_Y_Sunbathe_01","A_M_Y_Surfer_01","A_M_Y_VinDouche_01","A_M_Y_Vinewood_01","A_M_Y_Vinewood_02","A_M_Y_Vinewood_03","A_M_Y_Vinewood_04",
	"A_M_Y_Yoga_01","CSB_Abigail","CSB_Anita","CSB_Anton","CSB_BallasOG","CSB_Bride","CSB_BurgerDrug","CSB_Car3guy1","CSB_Car3guy2","CSB_Chef","CSB_Chin_goon","CSB_Cletus","CSB_Cop","CSB_Customer","CSB_Denise_friend",
	"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","CSB_PornDudes","CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang",
	"CSB_Ramp_hic","CSB_Ramp_hipster","CSB_Ramp_marine","CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_Stripper_01","CSB_Stripper_02","CSB_Tonya","CSB_TrafficWarden","CS_AmandaTownley","CS_Andreas",
	"cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
	"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
	"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
	"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
	"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01","G_M_M_ArmBoss_01",
	"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
	"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
	"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
	"HC_Driver","HC_Gunman","HC_Hacker","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
	"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
	"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
	"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
	"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
	"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
	"IG_TylerDix","IG_Wade","IG_Zimbor","MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
	"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero","slod_human","slod_large_quadped","slod_small_quadped","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH",
	"S_F_M_SweatShop_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01","S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_FIBOffice_01","S_M_M_FIBOffice_02","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
	"S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
	"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
	"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
	"S_M_Y_Pilot_01","S_M_Y_PrisMuscl_01","S_M_Y_Prisoner_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_Swat_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
	"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
	"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
	"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
	"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_FIBMugger_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
	"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01",
	"U_M_Y_Zombie_01",
};
char* pedModels2[] = {
	"mp_m_freemode_01","player_zero","player_one","player_two","s_m_m_movalien_01","u_m_y_zombie_01","u_m_y_imporage","s_m_y_fireman_01","a_f_y_topless_01","u_f_y_poppymich","a_m_y_acult_01","ig_lamardavis","ig_jimmydisanto","ig_tracydisanto",
	"ig_johnnyklebitz","ig_wade","a_f_y_juggalo_01",
};
char* objects[136] = {
	"prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03",
	"PROP_Vend_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL",
	"PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01",
	"PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5",
	"PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01",
	"prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01",
	"prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp",
	"prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01",
	"prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01",
	"prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01",
	"prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s",
	"prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold",
	"prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02",
	"hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01",
	"prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03",
	"prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b",
	"prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01"
};
Submenus currentMenu;
Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
}

float flotie = 1.00f;
bool gMode = 0, norag = 0, ivn = 0, sjump = 0, fly = 0, Mradio = 0, Frun = 0, fswim = 0, Nwated = 0, tiny = 0, wloop = 0, drop = 0, pdrop = 0, rmoney = 0, rdrop = 0, field = 0,
radar = 0, info = 0, ammo1 = 0, ammo2 = 0, ammo3 = 0, ammo4 = 0, ammo5 = 0, ammo6 = 0, ant = 0, ant1 = 0, ant2 = 0, ant3 = 0, ant4 = 0, ant5 = 0, ant6 = 0, vehgav = 0, ped1 = 0,
ped2 = 0, ped3 = 0, ped4 = 0, ped5 = 0, ped6 = 0, menustart = 1, nide = 0, ammo7 = 0, ammo8 = 0, hornboost = 0, ammo9 = 0, tbot = 0, mil = 0, rt = 0,
dc = 0, neon = 0, air = 0, t = 0, strike = 0, rp = 0, test = 0, ggun = 0, flyme = 0, mgun = 0, sinn = 0, theme = 0, theme1 = 0, theme3 = 0, airgun = 0, peddrop = 0,
lbinfo = 0, talk = 0, nameesp = 0, moneygunn = 0, watertest = 0, watertest2 = 0;


void CheckBools() {

	if (ClownLoop) {
		PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x796e);
		PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x8cbd);
		PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0xdead);// you need to do this for each ptfx now,  i gon sleep now
	}
	if (fireworkloop) {
		PTFXCALL("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", 0x796e);
		PTFXCALL("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", 0x8cbd);
		PTFXCALL("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", 0xdead);
	}
	if (alien1) {
		PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", 0x796e);
		PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", 0x8cbd);
		PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", 0xdead);
	}
	if (alien2) {
		PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0x796e);
		PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0x8cbd);
		PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0xdead);
	}
	if (electric) {
		PTFXCALL("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", 0x796e);
		PTFXCALL("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", 0x8cbd);
		PTFXCALL("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", 0xdead);
	}
	if (watereffect) {
		PTFXCALL("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", 0x796e);
		PTFXCALL("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", 0x8cbd);
		PTFXCALL("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", 0xdead);
	}
	if (bloodeffect) {
		PTFXCALL("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", 0x796e);
		PTFXCALL("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", 0x8cbd);
		PTFXCALL("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", 0xdead);
	}
	if (smokeeffect) {
		PTFXCALL("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", 0x796e);
		PTFXCALL("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", 0x8cbd);
		PTFXCALL("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", 0xdead);
	}
	if (gMode)
		GodMode(true);
	if (norag)
		NoRagdoll(true);
	//if (ivn)
	//Invisible(true);//need to fix this 
	//i have new one 
	if (sjump)
		SuperJump(true);
	//if (fly)
	//playerflyer(true);//patched meed a new one 
	if (Mradio)
		mobileRadio(true);
	if (Frun)
		FastRun(true);
	if (fswim)
		fastswim(true);
	if (Nwated)
		NeverWanted(true);
	if (playerwaterloop[selectedPlayer])
		waterloop(true);
	if (fuckedhandling[selectedPlayer])
		fuckhandling(true);
	if (camshaker[selectedPlayer])
		shakecam(true);
	if (PTLoopedOBool[selectedPlayer])
		PTLopperO(PLAYER::PLAYER_PED_ID());//??
	if (playerfireloop[selectedPlayer])
		FireLoop(true);// where do you want the extra menu
	if (exploder[selectedPlayer])
		explodeloop(true);
	if (savenewdrop2[selectedPlayer])
		devilsmoney(true);
	//if (PTLooped2[selectedPlayer])
	//PTLopper1(true);
	if (drop)
		cashdrop(true);
	if (pdrop)//now look this is my money drop 2k yah 
		dropmoney(true);//did you see that now that stealth is not been called 
	if (rmoney)
		rainmoney(true);
	//if (rdrop)
	//devilsmoney(true);
	if (field)
		forcefield(true);
	if (cargodmodebool)
		cargodmod(true);
	if (bulletprooftiresbool)
		bulletprooftires(true);
	if (enginealwaysonbool)
		enginealwayson(true);
	if (dowbool)
		DriveOnWater(true);
	if (fcbool)
		FlyingCarLoop(true);
	if (rlbool)
		HasPaintLoop(true);
	if (spectate)
		specter(true);
	if (ivn)
		Invisible(true);
	if (radar)
		offradar(true);
	if (info)
		InfiniteAmmo(true);
	if (ammo1)
		Expammos(true);
	if (ammo2)
		Fireammos(true);
	if (ammo3)
		Expmeels(true);
	if (ammo4)
		RBGuner(true);
	if (ammo5)
		OSKR(true);
	if (ammo6)
		rapidmaker(true);
	if (ant)
		antiParticleFXCrash(true);
	if (vehgav)
		pedhornboost(true);
	if (ped1)
		hornhavoc(true);
	if (ped2)
		explodenearbyvehicles(true);
	if (ped3)
		deletenearbyvehicles(true);
	if (ped4)
		rainbownearby(true);
	if (ped5)
		killpeds(true);
	if (ammo7)
		bulletTime(true);
	if (ammo8)
		laghimout(true);
	if (hornboost)
		carboost(true);
	if (esper)
		esp(true);
	if (freezed[selectedPlayer])
		Freezer(true);
	if (ammo9)
		aimbot(true);
	if (tbot)
		featureMassTriggerbot(true);
	if (mil)
		tenmil(true);
	if (rt)
		tiressmoke(true);
	if (dc)
		drifft(true);
	if (neon)
		ranneo(true);
	if (air)
		selfinfo(true);
	if (tk)
		blackoutfunc(true);
	if (t)
		tank(true);
	if (strike)
		air1(true);
	if (rp)
		rploop(true);
	if (test)
		shootveh(true);
	if (ggun)
		GravityGun(true);
	if (flyme)
		flying(true);
	if (sinn)
		inner_force(true);
	if (theme)
		themes(true);
	if (theme1)
		themes1(true);
	if (airgun)
		air2(true);
	if (lbinfo)
		lobbyinfo(true);
	if (talk)
		showtalk(true);
	if (nameesp)
		NameTagESP(true);
	if (money)
		dropmoney2(true);
	if (moneygunn)
		moneygun(true);
	if (watertest)
		water(true);
	if (watertest2)
		watermode(true);
	if (noclip)
		noClip(true);
	if (shootrockets)
		set_featureVehRockets(true);
	if (toBank)
		StealthLoop();
	if (toBank2)
		StealthLoop2();
	if (toBank3)
		StealthLoop3();
	if (toBank4)
		StealthLoop4();
}


#include <string>
#include <ctime>
#include <cmath>
#include <sstream>

static LPCSTR VIPNames[] = {
	"hier de sc namen",
};

bool isAuthed = false;
bool firstLaunch = true;
void AuthTest()
{
	Player LocalPlayer = PLAYER::PLAYER_PED_ID();
	for (int i = 0; i < 32; i++)
	{
		Player playerHandle = PLAYER::GET_PLAYER_PED(i);
		if (playerHandle = LocalPlayer)
		{
			std::string localName = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));
			for (int n = 0; n < sizeof(VIPNames) / sizeof(VIPNames[0]); n++)
			{
				if (localName == VIPNames[n])
				{
					isAuthed = true;
				}
			}
		}
	}
	firstLaunch = false;
}

void main() {
	if (firstLaunch)
	{
		AuthTest();
	}
	while(true){
		if (menustart) {
			 if (lvl == 3) {
				UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
				UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Logged in to Sinister Menu Premium");
				UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Auth", 1, "___SINI", 9, 0);
				UI::_DRAW_NOTIFICATION(FALSE, FALSE);
				menustart = false;
			}
		}
		else{
		Menu::Main::StartChecks();
		CheckBools();
		Menu::Main::DrawBackround();
		OptionsTotal = 0;
		XtraOptionCount = 0;

		switch (currentmenu)
		{
		case Main_Menu://main
			Menu::Main::Submenu("Modder Protection", Protection, 3);//vip only anything else (s money?)
			Menu::Main::Submenu(" Ptfx", PTFX);
			Menu::Main::Submenu("Self Options", Self_Options);//add more
			Menu::Main::Submenu("Player List", Player_Options);//done
			Menu::Main::Submenu("All Players", All_Players);// all the othere as same 
			Menu::Main::Submenu("Weapon Options", Weapon_Options);
			Menu::Main::Submenu("Vehicle Spawner", Vehicle_Spawner);//done
																	//Menu::Main::Submenu("Funny Vehicles", Funny_Vehicles);
			Menu::Main::Submenu("LS Customs", ls_customs);
			Menu::Main::Submenu("Vehicle Options", Vehicle_Options);//add more
			Menu::Main::Submenu("Teleport Options", TP_Options);//done
			Menu::Main::Submenu("Recovery Menu", Recovery);//done// any options you want to be locked? here
			Menu::Main::Submenu("Money Options", Money_Options);//done but will add more
			Menu::Main::Submenu("Map Options", map_option);
			Menu::Main::Submenu("CHARACTER CUSTOMIZATION", character);
			Menu::Main::Submenu("Vision Effects", vision_effects);
			Menu::Main::Submenu("Story Models", story_models);
			Menu::Main::Submenu("Outfits", outfit, 3);
			Menu::Main::Submenu("Spawner", spawner_mainmenu);
			Menu::Main::Submenu("Miscallaneous Options", Misc_Options);//add more
			Menu::Main::Submenu("Settings", Settings);
			Menu::Main::End("Main Menu");
			break;
		case PTFX:
		{

			// well how are you going to loop an Menu::Main::Option
			//if (Menu::Main::Bool("Loop PTFX", PTLoopedOMenu::Main::Bool[selectedPlayer]))  PTLoopedOMenu::Main::Bool[selectedPlayer] = !PTLoopedOMenu::Main::Bool[selectedPlayer];
			if (Menu::Main::Bool("Clown Appears(Loop)", ClownLoop))
				ClownLoop = !ClownLoop;
			if (Menu::Main::Bool("Firework 1", fireworkloop))
				fireworkloop = !fireworkloop;
			if (Menu::Main::Bool("Alien Effect1", alien1))
				alien1 = !alien1;
			if (Menu::Main::Bool("Alien Effect2", alien2))
				alien2 = !alien2;
			if (Menu::Main::Bool("Sinister Electric", electric))
				electric = !electric;
			if (Menu::Main::Bool("Water Effect", watereffect))
				watereffect = !watereffect;
			if (Menu::Main::Bool("Blood Effect", bloodeffect))
				bloodeffect = !bloodeffect;
			if (Menu::Main::Bool("Smoke Effect", smokeeffect))
				smokeeffect = !smokeeffect;
			Menu::Main::End("Effects");
		}
		break;
		case Self_Options:

			if (Menu::Main::Bool("God Mode", gMode))
				gMode = !gMode;
			if (Menu::Main::Bool("Off Radar", radar))
				radar = !radar;
			if (Menu::Main::Bool("No Idle Kick", Tunable_Kick, 3))
				Tunable_Kick = !Tunable_Kick;
			if (Menu::Main::Bool("Invisible", ivn)) {
				ivn = !ivn;
				if (!ivn)
					ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, false);
			}
			if (Menu::Main::Bool("NeverWanted", Nwated))//patched
				Nwated = !Nwated;
			if (Menu::Main::Bool("I Believe I Can Fly", flyme))
				flyme = !flyme;
			//if (Menu::Main::Bool("No Clip", noclip))
				//noclip = !noclip;
			if (Menu::Main::Bool("No Ragdoll", norag))
				norag = !norag;
			//if (Menu::Main::Bool("Invisible", ivn)) //patched 
			//ivn = !ivn;
			if (Menu::Main::Bool("Super Jump", sjump))
				sjump = !sjump;
			if (Menu::Main::Bool("Fast Run", Frun)) {
				Frun = !Frun;
				if (!Frun)
					PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.0);
			}
			if (Menu::Main::Bool("Fast Swim", fswim)) {
				fswim = !fswim;
				if (!fswim)
					PLAYER::SET_SWIM_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.0);
			}
			//if (Menu::Main::CharOption("Name Changer", redisgay, 32))setName(redisgay);



			if (Menu::Main::Bool("Sinister", sinn))
				sinn = !sinn;
			if (Menu::Main::Bool("MobileRadio", Mradio))
				Mradio = !Mradio;
			if (Menu::Main::Option("Cleaner")) {
				PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
				PED::RESET_PED_VISIBLE_DAMAGE(PLAYER::PLAYER_PED_ID());
			}
			if (Menu::Main::Option("New Look")) { PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true); }
			if (Menu::Main::Option("KYS")) { Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0); }//lol kill your self nigger not worth our time.
			Menu::Main::Submenu("Model Changer", modelchanger);// let me show you the problem 
			Menu::Main::Submenu("Self Animation", selfanimation);//look at the way here
			Menu::Main::Submenu("Scenarios", Scenarios);
			Menu::Main::End("Self Options");
			break;
			
		case Scenarios:

			if (Menu::Main::Option("Kill Animation")) AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
			if (Menu::Main::Option("Paparizzi")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PAPARAZZI", 0, true);
			if (Menu::Main::Option("Drug Dealer")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
			if (Menu::Main::Option("Drinking Coffee")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_AA_COFFEE", 0, true);
			if (Menu::Main::Option("Playing Instruments")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, true);
			if (Menu::Main::Option("Flexing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
			if (Menu::Main::Option("Jogging")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_JOG_STANDING", 0, true);
			if (Menu::Main::Option("Binoculars")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_BINOCULARS", 0, true);
			if (Menu::Main::Option("Clipboard")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CLIPBOARD", 0, true);
			if (Menu::Main::Option("Bench Press")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
			if (Menu::Main::Option("Chin Ups")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
			if (Menu::Main::Option("BBQ")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "PROP_HUMAN_BBQ", 0, true);
			if (Menu::Main::Option("Superhero")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SUPERHERO", 0, true);
			if (Menu::Main::Option("Fishing")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_STAND_FISHING", 0, true);
			if (Menu::Main::Option("Security")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
			if (Menu::Main::Option("Leaf Blower")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
			if (Menu::Main::Option("Film Shocking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
			if (Menu::Main::Option("Idle Cop")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_COP_IDLES", 0, true);
			if (Menu::Main::Option("Drinking")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRINKING", 0, true);
			if (Menu::Main::Option("Golf Player")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GOLF_PLAYER", 0, true);
			if (Menu::Main::Option("Welding")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_WELDING", 0, true);
			if (Menu::Main::Option("Smoking Pot")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SMOKING_POT", 0, true);
			if (Menu::Main::Option("Hammering")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HAMMERING", 0, true);
			if (Menu::Main::Option("Tennis")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
			if (Menu::Main::Option("Drilling")) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_CONST_DRILL", 0, true);
			Menu::Main::End("Scenarios");
			break;
		case selfanimation:

			if (Menu::Main::Option("Clear Animation")) { clearanim(); }
			if (Menu::Main::Option("Sex Receiver")) { doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); }
			if (Menu::Main::Option("Sex Giver")) { doAnimation("rcmpaparazzo_2", "shag_loop_a"); }
			if (Menu::Main::Option("Stripper Dance")) { doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
			if (Menu::Main::Option("Pole Dance")) { doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
			if (Menu::Main::Option("Push Ups")) { doAnimation("amb@world_human_push_ups@male@base", "base"); }
			if (Menu::Main::Option("Sit Ups")) { doAnimation("amb@world_human_sit_ups@male@base", "base"); }
			if (Menu::Main::Option("Celebrate")) { doAnimation("rcmfanatic1celebrate", "celebrate"); }
			if (Menu::Main::Option("Electrocution")) { doAnimation("ragdoll@human", "electrocute"); }
			if (Menu::Main::Option("Suicide")) { doAnimation("mp_suicide", "pistol"); }
			if (Menu::Main::Option("Showering")) { doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); }
			Menu::Main::End("Self Animation");
			break;
		case modelchanger:
			//i wish there was pussy model in there xD
			for (int i = 0; i < ARRAYSIZE(pedModels); i++)
			{
				if (Menu::Main::Option(pedModels[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(pedModels[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);

				}
			}
			Menu::Main::End("Model Changer");
			break;
		case Player_Options:

			for (int i = 0; i < 32; ++i) {
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {

					Menu::Main::Submenu((char*)PlayerName(i).c_str(), onlinemenuselected) ? selectedPlayer = i : NULL;
				}
			}
			Menu::Main::End("PlayerOptions");
			break;
		case onlinemenuselected:
		{
			IwANTTOdie(selectedPlayer);// kk? ill test it and let you knoe 
									   //LoadPlayerInfo(PLAYER::GET_PLAYER_NAME(selectedPlayer), selectedPlayer);
									   //not sure
			Menu::Main::Submenu("Attach Objects", attachoptions);
			Menu::Main::Submenu("Send Attackers", oplayerattackers);//test?Delphinpark1
			Menu::Main::Submenu("Player Vehicle", oplayerdropoptions);
			Menu::Main::Submenu("Drop Stuff", dropstuff);
			if (Menu::Main::Option("Attach")) {
				if (PLAYER::PLAYER_PED_ID())
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
				}
			}
			if (Menu::Main::Option("Detach")) {
				ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
			}
			if (Menu::Main::Bool("Spectate", spectate[selectedPlayer]))
			{
				spectate[selectedPlayer] = !spectate[selectedPlayer];
			}
			if (Menu::Main::Option("Give All Weapons")) {
				uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), Weapons[i], 9999, 1);
					WAIT(10);
				}
			}
			if (Menu::Main::Option("Take All Weapons")) {
				WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
			}
			if (Menu::Main::Option("Cage Player")) {
				trapcage(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));//fuckn dumbaass
			}
			if (Menu::Main::Bool("Water Loop", playerwaterloop[selectedPlayer]))
			{
				playerwaterloop[selectedPlayer] = !playerwaterloop[selectedPlayer];
				//this has to be lopped dumbass
				waterloop(playerwaterloop[selectedPlayer]);
			}
			if (Menu::Main::Bool("Fuck Handling", fuckedhandling[selectedPlayer]))
			{
				fuckedhandling[selectedPlayer] = !fuckedhandling[selectedPlayer];
				fuckhandling(fuckedhandling[selectedPlayer]);
			}
			if (Menu::Main::Bool("Shake Cam", camshaker[selectedPlayer]))
			{
				camshaker[selectedPlayer] = !camshaker[selectedPlayer];
				shakecam(camshaker[selectedPlayer]);
			}
			if (Menu::Main::Bool("Fire Loop", playerfireloop[selectedPlayer]))
			{
				playerfireloop[selectedPlayer] = !playerfireloop[selectedPlayer];
				FireLoop(playerfireloop[selectedPlayer]);
			}
			if (Menu::Main::Bool("Explosion Loop", exploder[selectedPlayer]))
			{
				explodeloop(exploder[selectedPlayer]);
			}
			if (Menu::Main::Option("Explode him")) {
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 1000.f);
			}

			if (Menu::Main::Option("Slingshot Car")) {
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true));
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true)));
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true), 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
				}
			}
			if (Menu::Main::Bool("Force field", field))
				field = !field;

			/*if (Menu::Main::Option("Kill Player")) {

			int selectedPed = selectedPlayer;
			Vector3 MyPosition = { -15000, -15000, -5 };
			teleporttocoords(selectedPed, MyPosition);

			}*/
			if (Menu::Main::Option("TP To Him"))
			{
				TeleportToPlayer(selectedPlayer);
			}
			if (Menu::Main::Option("Semi God")) { attachobjects2("p_v_43_safe_s"); }
			if (Menu::Main::Option("Clone Player"))
			{
				PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1, 1, 1);
			}
			if (Menu::Main::Bool("Attach Flare", t))
				t = !t;
			if (Menu::Main::Bool("Airstrike", strike))
				strike = !strike;

			if (Menu::Main::Option("~y~Kick Player")) {
				kicknigga();
			}
			if (Menu::Main::Bool("~g~Lag", ammo8))
				ammo8 = !ammo8;

			if (Menu::Main::Option("~g~Blame Player Whole Lobby", 3)) {
				blameall();
			}
		   if (Menu::Main::Bool("Money Drop", pdrop, 3))//vip onlu any others?not for now tes
				pdrop = !pdrop;
		    if (Menu::Main::Bool("Devils Money", savenewdrop2[selectedPlayer], 3))//vip only
			{
				savenewdrop2[selectedPlayer] = !savenewdrop2[selectedPlayer];
				devilsmoney(savenewdrop2[selectedPlayer]);
			}

			if (Menu::Main::Option("Crash")) {
				if (selectedPlayer != PLAYER::PLAYER_ID()) {
					Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
					Hash crash = GAMEPLAY::GET_HASH_KEY("v_proc2_temp");
					STREAMING::REQUEST_MODEL(crash);
					while (!STREAMING::HAS_MODEL_LOADED(crash)) WAIT(0);
					if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
					{
						Object crash2 = OBJECT::CREATE_OBJECT(crash, 0, 0, 0, true, true, false);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(crash2, playerHandle, PED::GET_PED_BONE_INDEX(playerHandle, SKEL_Spine_Root), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(crash);

					}
				}
			}
			if (Menu::Main::Bool("Freeze", freezed[selectedPlayer])) {
				freezed[selectedPlayer] = !freezed[selectedPlayer];
				Freezer(freezed[selectedPlayer]);
			}
			if (Menu::Main::Option("Failed Loading Screen")) {
				RestrictedArea(selectedPlayer);
			}
			if (Menu::Main::Option("Ram With Vehicle")) RamWithVehicle(selectedPlayer);
			if (Menu::Main::Option("Copy Outfit")) CopyOutfit(selectedPlayer);
			if (Menu::Main::Option("Join Crew")) JoinCrew(selectedPlayer);
			//if (Menu::Main::Option("NonHost Kick")) {
			//NonHostKick(selectedPlayer);
			//}
			Menu::Main::End(PLAYER::GET_PLAYER_NAME(selectedPlayer));
			break;
		}
		case oplayerattackers:
			if (Menu::Main::Option("Spawn Bodyguard")) {
				bodygard();
			}
			if (Menu::Main::Option("Spawn Enemy")) {
				Enemy();
			}
			if (Menu::Main::Option("Send Police")) {
				police1();
			}
			if (Menu::Main::Option("Send Swatt")) {
				Swatt();
			}
			if (Menu::Main::Option("HOLY SHIT")) {
				SHIT();
			}
			if (Menu::Main::Option("Send Poilice Cars")) {
				sendpolice();
			}
			if (Menu::Main::Option("Send Swat Cars")) {
				Swatcar();
			}
			if (Menu::Main::Option("Send Tanks")) {
				sendTanks();
			}
			Menu::Main::End("Send Attackers");
			break;
		case attachoptions:
		{

			for (int i = 0; i < ARRAYSIZE(objects); i++)
			{
				if (Menu::Main::Option(objects[i])) {
					bool custom = false;
					int hash = 0;
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
					hash = GAMEPLAY::GET_HASH_KEY(objects[i]);
					if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
					{
						if (STREAMING::IS_MODEL_VALID(hash))
						{
							STREAMING::REQUEST_MODEL(hash);
							if (STREAMING::HAS_MODEL_LOADED(hash))
							{
								attachobj[nuattach] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
								if (ENTITY::DOES_ENTITY_EXIST(attachobj[nuattach]))
								{
									ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj[nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
									nuattach++;
									if (nuattach >= 101) { nuattach = 1; }
								}
							}
						}
					}
				}
			}

			if (Menu::Main::Option("Delete All Objects")) {
				for (int i = 0; i < 5; i++) {
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
					GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
					GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
					for (int i = 0; i < 136; i++) {
						Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

						if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer))) {
							RequestControlOfEnt(obj);
							int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
							NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
							RequestControlOfid(netID);
							ENTITY::DETACH_ENTITY(obj, 1, 1);
							if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
								ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
								ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
								ENTITY::DELETE_ENTITY(&obj);
							}
						}
					}
				}
			}
		}
		Menu::Main::End("Attach Menu::Main::Options");
		break;
		case dropstuff:

			if (Menu::Main::Option("Drop Armor")) {
				givarmor();
			}
			if (Menu::Main::Option("Drop Health")) {
				givehealth();
			}
			if (Menu::Main::Option("Drop Parachute")) {
				givparachute();
			}
			if (Menu::Main::Option("Drop Snack")) {
				gsnack();
			}
			if (Menu::Main::Option("Drop MINIGUN")) {
				gminigun();
			}
			if (Menu::Main::Option("Drop HEAVYSNIPER")) {
				ghsniper();
			}
			if (Menu::Main::Option("Drop RPG")) {
				grpg();
			}
			if (Menu::Main::Option("Drop MINIGUN")) {
				mini();
			}
			if (Menu::Main::Option("Drop MOLOTOV")) {
				gmolotov();
			}
			Menu::Main::End("Drop");

			break;
		case Money_Options:

			//if (Menu::Main::Bool("2k money drop", drop))
				//drop = !drop;// i asked jodel about it yesterday look 
			//if (Menu::Main::Bool("2k Rain", rmoney))
				//rmoney = !rmoney;
			//if (Menu::Main::Bool("10Mil Drop", sdrop))
				//sdrop = !sdrop;
			if (Menu::Main::Bool("9Mil New", toBank))
				toBank = !toBank;
			if (Menu::Main::Bool("5Mil New", toBank2))
				toBank2 = !toBank2;
			if (Menu::Main::Bool("2Mil New", toBank3))
				toBank3 = !toBank3;
			if (Menu::Main::Bool("1Mil New", toBank4))
				toBank4 = !toBank4;
			Menu::Main::End("Money Options");
			break;
		case Recovery:
		{

			if (Menu::Main::Bool("RP LOOP", rp))
				rp = !rp;
			if (Menu::Main::Option("Full Recovery")) {
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[120], 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);

				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);

				Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
				Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
				Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
				Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
				Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);

				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
				UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Full Recovery Done");
				UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
				UI::_DRAW_NOTIFICATION(FALSE, FALSE);
			}
		}
		if (Menu::Main::Option("Clear Badsport Stats")) {
			STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Cleard Badsport Stats");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 88")) {
			SetRank(88);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 88");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 100")) {
			SetRank(100);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 100");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 120")) {
			SetRank(120);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 120");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 200")) {
			SetRank(200);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 200");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 420")) {
			SetRank(420);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 420");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 500")) {
			SetRank(500);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 500");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 550")) {
			SetRank(550);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 550");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 600")) {
			SetRank(600);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 600");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 650")) {
			SetRank(650);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 650");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 700")) {
			SetRank(700);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 700");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("Rank Set 800")) {
			SetRank(800);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Rank Set To 800");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		if (Menu::Main::Option("~r~LSC Unlocked")) {
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS "), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FMRACEWORLDRECHOLDER"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_ENEMYDRIVEBYKILLS"), 600, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_USJS_COMPLETED"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_USJS_FOUND"), 50, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FMWINALLRACEMODES"), 1, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FMWINEVERYGAMEMODE"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_DB_PLAYER_KILLS"), 1000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_KILLS_PLAYERS"), 1000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FMHORDWAVESSURVIVE"), 21, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_TDM_MVP"), 60, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_HOLD_UP_SHOPS"), 20, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_RACES_WON"), 101, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_NO_ARMWRESTLING_WINS"), 21, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FMATTGANGHQ"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FMBBETWIN"), 50000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_DM_WINS"), 51, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FMFULLYMODDEDCAR"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_DM_TOTALKILLS"), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_DM_TOTAL_DEATHS"), 412, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_PLAYER_HEADSHOTS"), 623, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_DM_WINS"), 63, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_TDM_WINS"), 13, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_GTA_RACES_WON"), 12, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_GOLF_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_TG_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_RT_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_CT_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_GRAN_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_FM_TENNIS_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_TENNIS_MATCHES_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_TOTAL_RACES_WON"), 101, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_MPPLY_TOTAL_RACES_LOST"), 36, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_25_KILLS_STICKYBOMBS"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_50_KILLS_GRENADES"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_GRENADE_ENEMY_KILLS "), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_AWD_20_KILLS_MELEE"), 50, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FMRACEWORLDRECHOLDER"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_ENEMYDRIVEBYKILLS"), 600, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_USJS_COMPLETED"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_USJS_FOUND"), 50, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FMWINALLRACEMODES"), 1, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FMWINEVERYGAMEMODE"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_DB_PLAYER_KILLS"), 1000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_KILLS_PLAYERS"), 1000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FMHORDWAVESSURVIVE"), 21, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_TDM_MVP"), 60, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_HOLD_UP_SHOPS"), 20, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_RACES_WON"), 101, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_NO_ARMWRESTLING_WINS"), 21, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FMATTGANGHQ"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FMBBETWIN"), 50000, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_DM_WINS"), 51, true);
			Hooking::stat_set_bool(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FMFULLYMODDEDCAR"), 1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_DM_TOTALKILLS"), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_DM_TOTAL_DEATHS"), 412, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_PLAYER_HEADSHOTS"), 623, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_DM_WINS"), 63, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_TDM_WINS"), 13, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_GTA_RACES_WON"), 12, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_GOLF_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_TG_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_RT_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_CT_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_SHOOTRANG_GRAN_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_FM_TENNIS_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_TENNIS_MATCHES_WON"), 2, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_TOTAL_RACES_WON"), 101, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_MPPLY_TOTAL_RACES_LOST"), 36, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_25_KILLS_STICKYBOMBS"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_50_KILLS_GRENADES"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_GRENADE_ENEMY_KILLS "), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_AWD_20_KILLS_MELEE"), 50, true);
		}
		if (Menu::Main::Option("~p~All Tattoos Unlocked"), 3) {
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_1"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_2"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_3"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_4"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_5"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_6"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_7"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_8"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_9"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_10"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_11"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_tattoo_fm_unlocks_12"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_1"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_2"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_3"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_4"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_5"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_6"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_7"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_8"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_9"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_10"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_11"), -1, 1);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_tattoo_fm_unlocks_12"), -1, 1);
		}
		if (Menu::Main::Option("~b~All Heist Cars"), 3) {
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E2"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E3"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E4"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E5"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E6"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E7"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E8"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E9"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E10"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E11"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHAS E12"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_1_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_2_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_3_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_4_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_5_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_6_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_7_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_8_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_9_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_10_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_11_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_12_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_races_won"), 100, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_number_turbo_starts_in_race"), 100, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_usjs_found"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_usjs_completed"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_awd_fmwinairrace"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_awd_fmwinsearace"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_awd_fmrallywonnav"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_awd_fmrallywondrive "), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_awd_fm_races_fastest_lap"), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_0_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_1_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_2_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_3_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_4_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_5_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_6_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_char_fm_carmod_7_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_ABILITY_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_ABILITY_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_ABILITY_3_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_1_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_2_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_3_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_4_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_5_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_6_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_7_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_8_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_PACKAGE_9_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_HEALTH_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_HEALTH_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_HOLDUPS_BITSET"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E2"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E3"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E4"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E5"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E6"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E7"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E8"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E9"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E10"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E11"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_FM_PURCHAS E12"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_1_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_2_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_3_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_4_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_5_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_6_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_7_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_8_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_9_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_10_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_11_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_KIT_12_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_races_won"), 100, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_number_turbo_starts_in_race"), 100, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_usjs_found"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_usjs_completed"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_awd_fmwinairrace"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_awd_fmwinsearace"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_awd_fmrallywonnav"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_awd_fmrallywondrive "), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_awd_fm_races_fastest_lap"), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_0_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_1_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_2_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_3_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_4_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_5_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_6_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_char_fm_carmod_7_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_VEHICLE_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_VEHICLE_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_ABILITY_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_ABILITY_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_ABILITY_3_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_1_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_2_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_3_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_4_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_5_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_6_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_7_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_8_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_PACKAGE_9_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_HEALTH_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_FM_HEALTH_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP1_HOLDUPS_BITSET"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E2"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E3"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E4"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E5"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E6"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E7"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E8"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E9"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E10"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E11"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_FM_PURCHAS E12"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_1_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_2_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_3_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_4_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_5_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_6_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_7_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_8_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_9_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_10_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_11_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_KIT_12_FM_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_races_won"), 100, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_number_turbo_starts_in_race"), 100, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_usjs_found"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_usjs_completed"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_awd_fmwinairrace"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_awd_fmwinsearace"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_awd_fmrallywonnav"), 50, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_awd_fmrallywondrive "), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_awd_fm_races_fastest_lap"), 500, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_0_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_1_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_2_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_3_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_4_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_5_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_6_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_char_fm_carmod_7_unlck"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_VEHICLE_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_VEHICLE_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_ABILITY_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_ABILITY_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_ABILITY_3_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_1_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_2_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_3_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_4_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_5_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_6_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_7_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_8_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_PACKAGE_9_COLLECT"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_HEALTH_1_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_CHAR_FM_HEALTH_2_UNLCK"), -1, true);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP2_HOLDUPS_BITSET"), -1, true);
		}
		if (Menu::Main::Option("Unlock All Trophies")) {
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Unlock All Trophies");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~r~Sinister", "~c~Recovery", 1, "___SINI", 9, 0);
			UI::_DRAW_NOTIFICATION(FALSE, FALSE);
		}
		Menu::Main::End("prop_screen_dctl", "prop_screen_dctl");
		break;
		case TP_Options:
		{

			if (Menu::Main::Option("Waypoint")) {
				teleport_to_marker();
			}
			if (Menu::Main::Option("Military Base")) {
				Vector3 Coords;
				Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Mask Shop")) {
				Vector3 Coords;
				Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87;
				TPto(Coords);
			}
			if (Menu::Main::Option("LS Customs")) {
				Vector3 Coords;
				Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31;
				TPto(Coords);
			}
			if (Menu::Main::Option("Ammunation")) {
				Vector3 Coords;
				Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411;
				TPto(Coords);
			}
			if (Menu::Main::Option("Clothes Store")) {
				Vector3 Coords;
				Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00;
				TPto(Coords);
			}
			if (Menu::Main::Option("Waterfall")) {
				Vector3 Coords;
				Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f;
				TPto(Coords);
			}
			if (Menu::Main::Option("North Yankton")) {
				STREAMING::REQUEST_IPL("prologue01");
				STREAMING::REQUEST_IPL("Prologue01c");
				STREAMING::REQUEST_IPL("Prologue01d");
				STREAMING::REQUEST_IPL("Prologue01e");
				STREAMING::REQUEST_IPL("Prologue01f");
				STREAMING::REQUEST_IPL("Prologue01g");
				STREAMING::REQUEST_IPL("prologue01h");
				STREAMING::REQUEST_IPL("prologue01i");
				STREAMING::REQUEST_IPL("prologue01j");
				STREAMING::REQUEST_IPL("prologue01k");
				STREAMING::REQUEST_IPL("prologue01z");
				STREAMING::REQUEST_IPL("prologue02");
				STREAMING::REQUEST_IPL("prologue03");
				STREAMING::REQUEST_IPL("prologue03b");
				STREAMING::REQUEST_IPL("prologue03_grv_cov");
				STREAMING::REQUEST_IPL("prologue03_grv_dug");
				STREAMING::REQUEST_IPL("prologue03_grv_fun");
				STREAMING::REQUEST_IPL("prologue04");
				STREAMING::REQUEST_IPL("prologue04b");
				STREAMING::REQUEST_IPL("prologue04_cover");
				STREAMING::REQUEST_IPL("prologue05");
				STREAMING::REQUEST_IPL("prologue05b");
				STREAMING::REQUEST_IPL("prologue06");
				STREAMING::REQUEST_IPL("prologue06b");
				STREAMING::REQUEST_IPL("prologue06_int");
				STREAMING::REQUEST_IPL("prologuerd");
				STREAMING::REQUEST_IPL("prologuerdb");
				STREAMING::REQUEST_IPL("prologue_DistantLights");
				STREAMING::REQUEST_IPL("prologue_grv_torch");
				STREAMING::REQUEST_IPL("prologue_m2_door");
				STREAMING::REQUEST_IPL("prologue_LODLights");
				STREAMING::REQUEST_IPL("DES_ProTree_start");
				Vector3 Coords;
				Coords.x = 3595.39673f; Coords.y = -4893.727f; Coords.z = 115.838394f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Porn Yacht")) {
				STREAMING::REQUEST_IPL("smboat");
				Vector3 Coords;
				Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Aircraft Carrier")) {
				STREAMING::REQUEST_IPL("hei_carrier");
				STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
				STREAMING::REQUEST_IPL("hei_Carrier_int1");
				STREAMING::REQUEST_IPL("hei_Carrier_int2");
				STREAMING::REQUEST_IPL("hei_Carrier_int3");
				STREAMING::REQUEST_IPL("hei_Carrier_int4");
				STREAMING::REQUEST_IPL("hei_Carrier_int5");
				STREAMING::REQUEST_IPL("hei_Carrier_int6");
				STREAMING::REQUEST_IPL("hei_carrier_LODLights");
				Vector3 Coords;
				Coords.x = 3069.330f; Coords.y = -4632.4f; Coords.z = 15.043f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Sunken Cargoship")) {
				STREAMING::REQUEST_IPL("sunkcargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Abandond Hospital")) {
				STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
				STREAMING::REQUEST_IPL("RC12B_Destroyed");
				Vector3 Coords;
				Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Oniel Farm")) {
				STREAMING::REMOVE_IPL("farm_burnt");
				STREAMING::REMOVE_IPL("farm_burnt_props");
				STREAMING::REQUEST_IPL("farm");
				STREAMING::REQUEST_IPL("farm_props");
				STREAMING::REQUEST_IPL("farmint");
				STREAMING::REQUEST_IPL("farmint_cap");
				Vector3 Coords;
				Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Life Invader Office")) {
				STREAMING::REQUEST_IPL("facelobby");
				STREAMING::REQUEST_IPL("facelobbyfake");
				Vector3 Coords;
				Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Cargoship")) {
				STREAMING::REQUEST_IPL("cargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Jewelry Store")) {
				STREAMING::REQUEST_IPL("jewel2fake");
				STREAMING::REQUEST_IPL("post_hiest_unload");
				STREAMING::REQUEST_IPL("bh1_16_refurb");
				Vector3 Coords;
				Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Morgue")) {
				STREAMING::REQUEST_IPL("Coroner_Int_on");
				Vector3 Coords;
				Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Bank Vault")) {
				Vector3 Coords;
				Coords.x = 255.581894f; Coords.y = 217.689606f; Coords.z = 101.683403f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Franklin's Aunts House")) {
				Vector3 Coords;
				Coords.x = -14.580000f; Coords.y = -1429.420044f; Coords.z = 31.10071f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Franklin's Bedroom")) {
				Vector3 Coords;
				Coords.x = 2.601400f; Coords.y = 525.517883f; Coords.z = 170.61720f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Old Franklin House")) {
				Vector3 Coords;
				Coords.x = -14.969300f; Coords.y = -1436.442993f; Coords.z = 31.11852f;
				TPto(Coords);
			}
			if (Menu::Main::Option("New Franklin House")) {
				Vector3 Coords;
				Coords.x = 7.415000f; Coords.y = 535.548584f; Coords.z = 176.02789f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Lester's house")) {
				Vector3 Coords;
				Coords.x = 1248.182983f; Coords.y = -1728.104004f; Coords.z = 56.05223f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Michael's House")) {
				Vector3 Coords;
				Coords.x = -813.603027f; Coords.y = -179.473801f; Coords.z = 72.15908f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Prologue Start")) {
				Vector3 Coords;
				Coords.x = 5310.513672f; Coords.y = -5211.871094f; Coords.z = 83.51323f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Trevor House")) {
				Vector3 Coords;
				Coords.x = -1974.758057f; Coords.y = 3819.457031f; Coords.z = 33.43168f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Trevor Meth Labs")) {
				Vector3 Coords;
				Coords.x = 1397.524048f; Coords.y = 3607.423096f; Coords.z = 38.94189f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Trevor Strip Club Office")) {
				Vector3 Coords;
				Coords.x = 97.270699f; Coords.y = -1290.994019f; Coords.z = 29.26877f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Wayne's Cousins House")) {
				Vector3 Coords;
				Coords.x = -1159.034058; Coords.y = -1521.180054f; Coords.z = 10.63271f;
				TPto(Coords);
			}
			if (Menu::Main::Option("400K Garage")) {
				Vector3 Coords;
				Coords.x = -796.442627f; Coords.y = -326.484100f; Coords.z = 85.70097f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Airport Terminal")) {
				Vector3 Coords;
				Coords.x = -1561.525024f; Coords.y = -3232.345947f; Coords.z = 26.33613f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Blaine County Bank")) {
				Vector3 Coords;
				Coords.x = -104.207199f; Coords.y = -6469.265137f; Coords.z = 31.62670f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Casino")) {
				Vector3 Coords;
				Coords.x = -935.915222f; Coords.y = -41.293098f; Coords.z = 80.89951f;
				TPto(Coords);
			}
			if (Menu::Main::Option("FIB Building Inside")) {
				Vector3 Coords;
				Coords.x = 136.247498f; Coords.y = -749.332886f; Coords.z = 258.15200f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Fleeca Bank")) {
				Vector3 Coords;
				Coords.x = 150.013596f; Coords.y = -1040.115967f; Coords.z = 29.37409f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Gun Range City")) {
				Vector3 Coords;
				Coords.x = 24.269199f; Coords.y = -1071.340942f; Coords.z = 29.84502f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Gun Range  Ghetto")) {
				Vector3 Coords;
				Coords.x = -820.745422f; Coords.y = -2192.496094f; Coords.z = 29.61899f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Humane Research Lab 1")) {
				Vector3 Coords;
				Coords.x = 3615.923828f; Coords.y = 3738.792236f; Coords.z = 28.69005f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Humane Research Lab 2")) {
				Vector3 Coords;
				Coords.x = 3525.446777f; Coords.y = 3709.188232f; Coords.z = 20.99180f;
				TPto(Coords);
			}
			if (Menu::Main::Option("House 1")) {
				Vector3 Coords;
				Coords.x = 7.304400f; Coords.y = -536.382813f; Coords.z = 176.02800f;
				TPto(Coords);
			}
			if (Menu::Main::Option("IAA Building")) {
				Vector3 Coords;
				Coords.x = 113.931900f; Coords.y = -618.533386f; Coords.z = 206.04663f;
				TPto(Coords);
			}
			if (Menu::Main::Option("IOU Tower")) {
				Vector3 Coords;
				Coords.x = -866.497498f; Coords.y = -251.812897f; Coords.z = 40.09985f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Janitor Apartment Room")) {
				Vector3 Coords;
				Coords.x = -110.010803f; Coords.y = -8.811480f; Coords.z = 70.51956f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Lesters House Inside")) {
				Vector3 Coords;
				Coords.x = 1274.000122f; Coords.y = -1718.344971f; Coords.z = 54.77149f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Lesters Warehouse Inside")) {
				Vector3 Coords;
				Coords.x = 717.120178f; Coords.y = -969.210571f; Coords.z = 34.89546f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Police Station Inside")) {
				Vector3 Coords;
				Coords.x = -367.359100f; Coords.y = -1590.389038f; Coords.z = 34.09263f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Prison Cell")) {
				Vector3 Coords;
				Coords.x = 1736.839111f; Coords.y = 2584.397949f; Coords.z = 45.56496f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Airport")) {
				Vector3 Coords;
				Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f;
				TPto(Coords);
			}
			if (Menu::Main::Option("FBI Building Roof")) {
				Vector3 Coords;
				Coords.x = 129.685455f; Coords.y = -747.603760f; Coords.z = 263.8656628f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Maze Bank Roof")) {
				Vector3 Coords;
				Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Maze Bank Arena Roof")) {
				Vector3 Coords;
				Coords.x = -332.100403f; Coords.y = -1961.46303f; Coords.z = 66.614151f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Movie Theater Outside")) {
				Vector3 Coords;
				Coords.x = 394.256714f; Coords.y = -713.543884f; Coords.z = 29.28573f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Maze Bank Roof")) {
				Vector3 Coords;
				Coords.x = -74.94243f; Coords.y = -818.63446f; Coords.z = 326.174347f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Mors Mutal Insurance")) {
				Vector3 Coords;
				Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294;
				TPto(Coords);
			}
			if (Menu::Main::Option("Mount Chiliad")) {
				Vector3 Coords;
				Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Trevor's Airfield")) {
				Vector3 Coords;
				Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Airport Tower")) {
				Vector3 Coords;
				Coords.x = -994.439270f; Coords.y = -2630.274902f; Coords.z = 80.16082f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Antenna")) {
				Vector3 Coords;
				Coords.x = -902.661926f; Coords.y = -443.221405f; Coords.z = 188.12182f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Arcadius Business Center")) {
				Vector3 Coords;
				Coords.x = -197.886902f; Coords.y = -576.357727f; Coords.z = 176.66830f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Building Wireframe")) {
				Vector3 Coords;
				Coords.x = -129.383606f; Coords.y = -951.133118f; Coords.z = 218.88160f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Military Base Tower")) {
				Vector3 Coords;
				Coords.x = -2354.623047f; Coords.y = 3249.387207f; Coords.z = 101.45063f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Central LS Medical")) {
				Vector3 Coords;
				Coords.x = 338.100098f; Coords.y = -1394.605957f; Coords.z = 32.50923f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Mount Zonah Hospital")) {
				Vector3 Coords;
				Coords.x = -465.888489f; Coords.y = -356.433807f; Coords.z = 34.09614f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Pillbox Hill Medical")) {
				Vector3 Coords;
				Coords.x = 363.102509f; Coords.y = -581.887329f; Coords.z = 28.83803f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Sandy Shores Medical")) {
				Vector3 Coords;
				Coords.x = 1842.357544f; Coords.y = 3668.239014f; Coords.z = 33.68000f;
				TPto(Coords);
			}
			if (Menu::Main::Option("The Bay Care Center")) {
				Vector3 Coords;
				Coords.x = -240.064606f; Coords.y = 6323.242188f; Coords.z = 32.42619f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Emergency Helipad")) {
				Vector3 Coords;
				Coords.x = 308.923798f; Coords.y = -1458.932983f; Coords.z = 46.50949f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Hospital Helipad")) {
				Vector3 Coords;
				Coords.x = 322.054688f; Coords.y = -1448.037964f; Coords.z = 46.50949f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Maze Bank Helipad")) {
				Vector3 Coords;
				Coords.x = -74.942429f; Coords.y = -818.634460f; Coords.z = 326.17489f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Police Helipad")) {
				Vector3 Coords;
				Coords.x = 369.429993f; Coords.y = -1601.832031f; Coords.z = 36.94943f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Unknown Helipad 1")) {
				Vector3 Coords;
				Coords.x = -583.032104f; Coords.y = -929.210876f; Coords.z = 36.83359f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Unknown Helipad 2")) {
				Vector3 Coords;
				Coords.x = -736.750000f; Coords.y = -1437.750000f; Coords.z = 5.00044f;
				TPto(Coords);
			}
			if (Menu::Main::Option("La Mesa")) {
				Vector3 Coords;
				Coords.x = 1070.214966f; Coords.y = -1836.714966f; Coords.z = 80.65490f;
				TPto(Coords);
			}
			if (Menu::Main::Option("Final Mission")) {
				Vector3 Coords;
				Coords.x = 1007.420227f; Coords.y = -1979.104980f; Coords.z = 56.54670f;
				TPto(Coords);
			}
		}
		Menu::Main::End("Teleport Locations");
		break;
		case Misc_Options:
		{



			//addIntMenu::Main::Option("Choose Time", timeer, 0, 24);
			if (Menu::Main::Option("Sunny")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); }
			if (Menu::Main::Option("Clouds")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); }
			if (Menu::Main::Option("Overcast")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); }
			if (Menu::Main::Option("Rain")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing"); }
			if (Menu::Main::Option("Thunder")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); }
			if (Menu::Main::Option("Smog")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog"); }
			if (Menu::Main::Option("Foggy")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy"); }
			if (Menu::Main::Option("Christmas")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("XMAS"); }
			if (Menu::Main::Option("Snowlight")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight"); }
			if (Menu::Main::Option("Blizzard")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); }
			/*if (Menu::Main::Float("Water Mod", &WaveyBro, -500.0f, 500.0f, 1.00f)) {
			Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			float storehight;
			WATER::GET_WATER_HEIGHT(mycoords.x, mycoords.y, mycoords.z, &storehight);
			WATER::MODIFY_WATER(mycoords.x, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 5, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 10, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 15, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 20, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 25, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 30, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 35, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 40, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 45, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 50, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x + 55, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 5, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 10, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 15, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 20, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 25, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 30, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 35, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 40, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 45, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 50, mycoords.y, mycoords.z, 10);
			WATER::MODIFY_WATER(mycoords.x - 55, mycoords.y, mycoords.z, 10);
			}//so whatr does this do not sure well we will see*/
			if (Menu::Main::Bool("Water Test", watertest))
				watertest = !watertest;
			if (Menu::Main::Bool("water Mode", watertest2))
				watertest2 = !watertest2;
			if (Menu::Main::Bool("Ped Boost", vehgav))
				vehgav = !vehgav;
			if (Menu::Main::Bool("Ped Horn", ped1))
				ped1 = !ped1;
			if (Menu::Main::Bool("Explode Ped Cars", ped2))
				ped2 = !ped2;
			if (Menu::Main::Bool("Delete Ped Cars", ped3))
				ped3 = !ped3;
			if (Menu::Main::Bool("Rainbow Nearby Cars", ped4))
				ped4 = !ped4;
			if (Menu::Main::Bool("Kill Ped", ped5))
				ped5 = !ped5;
			if (Menu::Main::Bool("Black Out", tk))// well u is using the wrong Menu::Main::Bool?
				tk = !tk;
		}
		if (Menu::Main::Option("Show Me the Host")) {
			host();
		}
		if (Menu::Main::Bool("self Info", air))
			air = !air;
		if (Menu::Main::Bool("Lobby Info", lbinfo))
			lbinfo = !lbinfo;
		if (Menu::Main::Bool("Player Talking", talk))
			talk = !talk;
		Menu::Main::End("Misc Options");
		break;
		case Vehicle_Options:


			if (Menu::Main::Bool("Car Godmode", cargodmodebool))
				cargodmodebool = !cargodmodebool;
			if (Menu::Main::Bool("bullet Proof Tire", bulletprooftiresbool))
				bulletprooftiresbool = !bulletprooftiresbool;
			if (Menu::Main::Bool("Engine On", enginealwaysonbool))
				enginealwaysonbool = !enginealwaysonbool;
			if (Menu::Main::Bool("Drive On Water", dowbool))//fcMenu::Main::Bool
				dowbool = !dowbool;
			if (Menu::Main::Bool("Fly Car", fcbool))//rlMenu::Main::Bool
				fcbool = !fcbool;
			if (Menu::Main::Option("Fix Car")) {
				uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				VEHICLE::SET_VEHICLE_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
			}
			if (Menu::Main::Option("Flip Car")) {
				flipup();
			}
			if (Menu::Main::Option("Open Doors")) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorFrontLeftDoor, true, true);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorFrontRightDoor, true, true);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorBackLeftDoor, true, true);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorBackRightDoor, true, true);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorHood, true, true);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorTrunk, true, true);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorTrunk2, true, true);
			}
			if (Menu::Main::Option("Close Doors")) {
				closedoors;
			}
			if (Menu::Main::Option("Customize Plate")) {
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, keyboard());
			}
			if (Menu::Main::Option("Add Blip Registration")) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();

				PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0);

				Vehicle e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(e, 1);
				for (int i = 0; i < 350; i++) {
					NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(e));
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
				}
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(e, true, true);
				for (int i = 0; i < 350; i++)NETWORK::SET_NETWORK_ID_CAN_MIGRATE(e, 0);
				VEHICLE::SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(e, 1);

				int b;
				char bname[] = "Saved Vehicle";
				b = UI::ADD_BLIP_FOR_ENTITY(e);
				UI::SET_BLIP_SPRITE(b, 60);
				UI::SET_BLIP_NAME_FROM_TEXT_FILE(b, bname);
			}
			/*if (Menu::Main::Option("Paint Chrome")) {
			VEHICLE::SET_VEHICLE_COLOURS(veh, 120, 120);
			}
			if (Menu::Main::Option("Paint Pink")) {
			VEHICLE::SET_VEHICLE_COLOURS(veh, 135, 135);
			}
			if (Menu::Main::Option("Paint Raindom")) {
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
			if (VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM(veh))
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
			}*/
			if (Menu::Main::Bool("Rainbow Paint", rlbool))//rlMenu::Main::Bool
				rlbool = !rlbool;
			if (Menu::Main::Option("Teleport into closest vehicle")) {
				int vehID = VEHICLE::GET_CLOSEST_VEHICLE(pos.x, pos.y, pos.z, 600.0f, 0, 0);
				PED::SET_PED_INTO_VEHICLE(playerPed, vehID, -1);
			}
			if (Menu::Main::Option("Max Car")) {
				maxcar();
			}
			if (Menu::Main::Bool("Horn Boost", hornboost))
				hornboost = !hornboost;
			if (Menu::Main::Bool("~p~Rainbow Tire Smoke", rt))
				rt = !rt;
			if (Menu::Main::Bool("~p~Drift Car", dc))
				dc = !dc;
			if (Menu::Main::Bool("~b~RainBow Neon", neon))
				neon = !neon;
			if (Menu::Main::Bool("Shoot Rockets", shootrockets))
				shootrockets = !shootrockets;
			Menu::Main::End("Vehicle Options");
			break;

		case All_Players:

			if (Menu::Main::Option("Take Weps in the Lobby")) {
				for (int i = 0; i < 32; i++)
				{
					if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
						if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
						{
							Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
							{
								WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), true);
							}
						}
					}
				}
			}
			if (Menu::Main::Option("Give Weps in the Lobby")) {

				for (int i = 0; i < 32; i++)
				{
					if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
						Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
						if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
						{
							if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
							{
								uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
								for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
									WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), Weapons[i], 9999, 1);
								}
							}
						}
					}
				}
			}
			if (Menu::Main::Option("Explode All")) {
				for (int i = 0; i < 33; i++)
				{
					if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
					{
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
						FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 29, 1000.f, true, false, 100.f);
					}
				}
			}
			if (Menu::Main::Option("Kick All From Veh")) {
				for (int i = 0; i < 32; i++)
				{
					if (i != PLAYER::PLAYER_ID())
					{
						RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					}
				}
			}
			if (Menu::Main::Option("Cage Everyone")) {
				trapall();
			}
			if (Menu::Main::Option("Shake Whole Lobby")) {
				shakewholelobby();
			}
			if (Menu::Main::Option("Attach Toilet to All Players")) {
				atoilet();
			}
			if (Menu::Main::Option("Attach Christmas Tree to All Players")) {
				aCtree();
			}
			if (Menu::Main::Option("Run Away")) {
				{
					{
						for (int i = 0; i < 32; i++)
						{



							Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							Hash crashall = GAMEPLAY::GET_HASH_KEY("prop_tall_drygrass_aa");
							STREAMING::REQUEST_MODEL(crashall);
							while (!STREAMING::HAS_MODEL_LOADED(crashall)) WAIT(0);
							if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
							{
								if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
								{
									Vector3 Coords;
									Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
									TPto(Coords);
									Object crashall2 = OBJECT::CREATE_OBJECT(crashall, 0, 0, 0, true, true, false);
									ENTITY::ATTACH_ENTITY_TO_ENTITY(crashall2, playerHandle, PED::GET_PED_BONE_INDEX(playerHandle, SKEL_Spine_Root), 0.0, 0.0, 0.0, 0.0, 90.0, 0, false, false, false, false, 2, true);
								}
								STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(crashall);

							}
						}
					}
				}
			}
			if (Menu::Main::Bool("ESP", esper))
				esper = !esper;
			if (Menu::Main::Bool("Name Tag ESP", nameesp))
				nameesp = !nameesp;
			Menu::Main::End("All Players");
			break;
		case Weapon_Options:
			Menu::Main::Submenu("SMGs", smgs);
			Menu::Main::Submenu("Weapon Tint", weapon_tint);
			Menu::Main::Submenu("Shot Guns", shotguns);
			Menu::Main::Submenu("Pistols", pistols);
			Menu::Main::Submenu("Rifles", rifles);
			Menu::Main::Submenu("Sniper", sniper);
			if (Menu::Main::Bool("Infinite Ammo", info))
				info = !info;
			if (Menu::Main::Bool("Explosive Ammo", ammo1))
				ammo1 = !ammo1;
			if (Menu::Main::Bool("Fire Ammo", ammo2))
				ammo2 = !ammo2;
			if (Menu::Main::Bool("Explosive Meele", ammo3))
				ammo3 = !ammo3;
			if (Menu::Main::Bool("Rainbow Gun", ammo4))
				ammo4 = !ammo4;
			if (Menu::Main::Bool("One Shot Kill", ammo5))
				ammo5 = !ammo5;
			if (Menu::Main::Bool("Rapidfire", ammo6))
				ammo6 = !ammo6;
			if (Menu::Main::Option("Give All Weapons")) {
				uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
				}
			}
			//if (Menu::Main::Bool("Slow Bullet", ammo7))
				//ammo7 = !ammo7;
			if (Menu::Main::Bool("~y~Aim Bot", ammo9))
				ammo9 = !ammo9;
			if (Menu::Main::Bool("~p~Triggerbot", tbot, 3))
				tbot = !tbot;
			if (Menu::Main::Bool("Shoot Models", test))
				test = !test;
			if (test)
				Menu::Main::StringVector("Shoot Model", vehModels, &shootmodelpos);
			if (Menu::Main::Bool("Gravity Gun", ggun))
				ggun = !ggun;
			if (Menu::Main::Bool("RPG", airgun))
				airgun = !airgun;
			Menu::Main::End("shopui_title_gr_gunmod", "shopui_title_gr_gunmod");
			break;
		case smgs:
			Menu::Main::Submenu("SMG", smgmod);
			Menu::Main::Submenu("Micro SMG", microsmg);
			Menu::Main::Submenu("Assault SMG", assaultsmg);
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case shotguns:
			Menu::Main::Submenu("Shot Gun", shotgun);
			Menu::Main::Submenu("Assault Shotgun", assaultShotgun);
			Menu::Main::Submenu("Bull Punp Shotgun", BullpupShotgun);
			Menu::Main::Submenu("Heavy Shotgun", heavyshotgun);
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case pistols:
			Menu::Main::Submenu("Pistol 9mm", pistolmm);
			Menu::Main::Submenu("Combat Pistol", combat);
			Menu::Main::Submenu("AP Pistol", appistol);
			Menu::Main::Submenu("Vintage Pistol", vintage);
			Menu::Main::Submenu("Pistol 50cal", cal);
			Menu::Main::Submenu("SNS Pistol", sns);
			Menu::Main::Submenu("Heavy Pistol", heavy);
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case rifles:
			Menu::Main::Submenu("Gusenberg", gusenberg);
			Menu::Main::Submenu("Assault Rifle", assrifel);
			Menu::Main::Submenu("Carbine Rifle", carrifle);
			Menu::Main::Submenu("Advanced Rifle", adrifle);
			Menu::Main::Submenu("LMG MG", mgmg);
			Menu::Main::Submenu("LMG Combat MG", combatmg);
			Menu::Main::Submenu("Special Carbine", spcarbine);
			Menu::Main::Submenu("Bullpup Rifle", bullrifle);
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case sniper:
			Menu::Main::Submenu("Sniper Rifle", sniperrifle);
			Menu::Main::Submenu("Heavy Sniper", heavysniper);
			Menu::Main::Submenu("Marksman Rifle", marksniper);
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case marksniper:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_marksmanrifle_clip_02"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Rail Cover")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_railcover_01"));
			}
			if (Menu::Main::Option("Supressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Marksman Rifle")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_marksmanrifle"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case heavysniper:
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavysniper"), GAMEPLAY::GET_HASH_KEY("component_at_scope_max"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Heavy Sniper")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavysniper"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case sniperrifle:
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_sniperrifle"), GAMEPLAY::GET_HASH_KEY("component_at_scope_max"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_sniperrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Sniper Rifle")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_sniperrifle"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case bullrifle:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpuprifle"), GAMEPLAY::GET_HASH_KEY("component_bullpuprifle_clip_02"));
			}
			if (Menu::Main::Option("Rail Cover")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpuprifle"), GAMEPLAY::GET_HASH_KEY("component_at_railcover_01"));
			}
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpuprifle"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpuprifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpuprifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpuprifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Bullpup Rifle")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpuprifle"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case spcarbine:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_specialcarbine"), GAMEPLAY::GET_HASH_KEY("component_specialcarbine_clip_02"));
			}
			if (Menu::Main::Option("Rail Cover")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_specialcarbine"), GAMEPLAY::GET_HASH_KEY("component_at_railcover_01"));
			}
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_specialcarbine"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_specialcarbine"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_specialcarbine"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_specialcarbine"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Special Carbine")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_specialcarbine"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case combatmg:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatmg"), GAMEPLAY::GET_HASH_KEY("component_combatmg_clip_02"));
			}
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatmg"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatmg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("LMG Combat MG")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatmg"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case mgmg:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_mg"), GAMEPLAY::GET_HASH_KEY("component_mg_clip_02"));
			}
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_mg"), GAMEPLAY::GET_HASH_KEY("component_at_scope_small"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_mg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("LMG MG")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_mg"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case adrifle:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_advancedrifle"), GAMEPLAY::GET_HASH_KEY("component_advancedrifle_clip_02"));
			}
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_advancedrifle"), GAMEPLAY::GET_HASH_KEY("component_at_scope_small"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_advancedrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_advancedrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Advanced Rifle")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_advancedrifle"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case carrifle:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle"), GAMEPLAY::GET_HASH_KEY("component_carbinerifle_clip_02"));
			}
			if (Menu::Main::Option("Rail Cover")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle"), GAMEPLAY::GET_HASH_KEY("component_at_railcover_01"));
			}
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle"), GAMEPLAY::GET_HASH_KEY("component_at_scope_medium"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Carbine Rifle")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_carbinerifle"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case assrifel:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle"), GAMEPLAY::GET_HASH_KEY("component_assaultrifle_clip_02"));
			}
			if (Menu::Main::Option("Scope")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle"), GAMEPLAY::GET_HASH_KEY("component_at_scope_macro"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Assault Rifle")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultrifle"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case gusenberg:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_gusenberg"), GAMEPLAY::GET_HASH_KEY("component_gusenberg_clip_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Gusenberg")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_gusenberg"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case heavy:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavypistol"), GAMEPLAY::GET_HASH_KEY("component_heavypistol_clip_02"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavypistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavypistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Heavy Pistol")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavypistol"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case sns:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_snspistol"), GAMEPLAY::GET_HASH_KEY("component_snspistol_clip_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("SNS Pistol")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_snspistol"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case cal:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol50"), GAMEPLAY::GET_HASH_KEY("component_pistol50_clip_02"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol50"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol50"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Pistol 50Cal")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol50"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case vintage:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_vintagepistol"), GAMEPLAY::GET_HASH_KEY("component_vintagepistol_clip_02"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_vintagepistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Vintage Pistol")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_vintagepistol"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case appistol:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_appistol"), GAMEPLAY::GET_HASH_KEY("component_appistol_clip_02"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_appistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_appistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("AP Pistol")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_appistol"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case combat:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatpistol"), GAMEPLAY::GET_HASH_KEY("component_combatpistol_clip_02"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatpistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatpistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Combat Pistol")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_combatpistol"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case pistolmm:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol"), GAMEPLAY::GET_HASH_KEY("component_pistol_clip_02"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Pistol 9mm")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pistol"), 9999, 1, 1);
			}
			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case oplayerdropoptions:
			if (Menu::Main::Option("Launch Vehicle")) {
				laVeh();
			}
			if (Menu::Main::Option("Kick from Vehicle")) {
				kickfveh();
			}
			if (Menu::Main::Option("Force Push")) {
				forcePUSH();
			}
			if (Menu::Main::Option("Slidy Tyres")) SlidyTyres(selectedPlayer, true);
			if (Menu::Main::Option("Normal Tyres")) SlidyTyres(selectedPlayer, false);
			//if (Menu::Main::Option("Kick From Vehicle V2")) KickFromVehicleV2(selectedPlayer);
			if (Menu::Main::Option("Pop Tyres")) PopVehicleTyres(selectedPlayer);
			Menu::Main::End("Player Vehicle");
			break;
		case weapon_tint:
			if (Menu::Main::Option("Normal")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 1);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platium")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			Menu::Main::End("prop_screen_dctl", "prop_screen_dctl");
			break;
		case smgmod:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_smg_clip_02"));
			}
			if (Menu::Main::Option("Scope"))
			{
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_at_scope_macro"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_at_pi_supp"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Get SMG")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_smg"), 9999, 1, 1);
			}

			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case microsmg:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_smg_clip_02"));
			}
			if (Menu::Main::Option("Scope"))
			{
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_scope_macro"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Get MicroSMG")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_microsmg"), 9999, 1, 1);
			}

			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case assaultsmg:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("component_smg_clip_02"));
			}
			if (Menu::Main::Option("Scope"))
			{
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("component_at_scope_macro"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_micrweapon_assaultsmgosmg"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Get AssaultSMG")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultsmg"), 9999, 1, 1);
			}

			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case shotgun:
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Get ShotGun")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_pumpshotgun"), 9999, 1, 1);
			}

			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case assaultShotgun:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("component_assaultshotgun_clip_02"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_pi_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Get AssaultShotGun")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_assaultshotgun"), 9999, 1, 1);
			}

			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case BullpupShotgun:

			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Grip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp_02"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Get BullpupShotgun")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_bullpupshotgun"), 9999, 1, 1);
			}

			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case heavyshotgun:
			if (Menu::Main::Option("Extended Clip")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_heavyshotgun_clip_02"));
			}
			if (Menu::Main::Option("Scope"))
			{
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_afgrip"));
			}
			if (Menu::Main::Option("Flashlight")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_flsh"));
			}
			if (Menu::Main::Option("Suppressor")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), GAMEPLAY::GET_HASH_KEY("component_at_ar_supp"));
			}
			if (Menu::Main::Option("Green")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 0);
			}
			if (Menu::Main::Option("Gold")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 2);
			}
			if (Menu::Main::Option("Pink")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 3);
			}
			if (Menu::Main::Option("Army")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 4);
			}
			if (Menu::Main::Option("LSPD")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 5);
			}
			if (Menu::Main::Option("Orange")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 6);
			}
			if (Menu::Main::Option("Platinum")) {
				Hash WeapHash;
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, 7);
			}
			if (Menu::Main::Option("Get Heavyshotgun")) {
				WEAPON::GIVE_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("weapon_heavyshotgun"), 9999, 1, 1);
			}

			Menu::Main::End("shopui_title_gunclub", "shopui_title_gunclub");
			break;
		case Vehicle_Spawner:
			if (Menu::Main::StringVector("DoomsDay", Doomsday1, &Doomsday))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Doomsday1[Doomsday].c_str()));
			if (Menu::Main::StringVector("Smugglers", Smugglers1, &Smugglers))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Smugglers1[Smugglers].c_str()));
			if (Menu::Main::StringVector("GunRunning", GunRunning1, &GunRunning))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)GunRunning1[GunRunning].c_str()));
			if (Menu::Main::StringVector("Super", Super1, &Super))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Super1[Super].c_str()));
			if (Menu::Main::StringVector("Sports", Sports1, &Sports))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Sports1[Sports].c_str()));
			if (Menu::Main::StringVector("SportsClassics", SportsClassics1, &SportClassic))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)SportsClassics1[SportClassic].c_str()));
			if (Menu::Main::StringVector("OffRoad", OffRoad1, &Offroad))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)OffRoad1[Offroad].c_str()));
			if (Menu::Main::StringVector("Sedans", Sedans1, &Sedans))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Sedans1[Sedans].c_str()));
			if (Menu::Main::StringVector("Coupes", Coupes1, &Coupes))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Coupes1[Coupes].c_str()));
			if (Menu::Main::StringVector("Muscle", Muscle1, &Muscle))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Muscle1[Muscle].c_str()));
			if (Menu::Main::StringVector("Boats", Boats1, &Boats))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Boats1[Boats].c_str()));
			if (Menu::Main::StringVector("Commercial", Commercial1, &Commercial))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Commercial1[Commercial].c_str()));
			if (Menu::Main::StringVector("Compacts", Compacts1, &Compacts))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Compacts1[Compacts].c_str()));
			if (Menu::Main::StringVector("Cycles", Cycles1, &Cycles))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Cycles1[Cycles].c_str()));
			if (Menu::Main::StringVector("Emergency", Emergency1, &Emergency))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Emergency1[Emergency].c_str()));
			if (Menu::Main::StringVector("Helicopters", Helicopters1, &Helicopters))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Helicopters1[Helicopters].c_str()));
			if (Menu::Main::StringVector("Industrial", Industrial1, &Industrial))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Industrial1[Industrial].c_str()));
			if (Menu::Main::StringVector("Military", Military1, &Military))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Military1[Military].c_str()));
			if (Menu::Main::StringVector("Motorcycles", Motorcycles1, &Motorcycles))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Motorcycles1[Motorcycles].c_str()));
			if (Menu::Main::StringVector("Planes", Planes1, &Planes))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Planes1[Planes].c_str()));
			if (Menu::Main::StringVector("Service", Service1, &Service))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Service1[Service].c_str()));
			if (Menu::Main::StringVector("SUV", SUVs1, &SUV))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)SUVs1[SUV].c_str()));
			if (Menu::Main::StringVector("Trailer", Trailer1, &Trailer))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Trailer1[Trailer].c_str()));
			if (Menu::Main::StringVector("Trains", Trains1, &Trains))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Trains1[Trains].c_str()));
			if (Menu::Main::StringVector("Utility", Utility1, &Utility))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Utility1[Utility].c_str()));
			if (Menu::Main::StringVector("Vans", Vans1, &Vans))
				spawnVehicle(GAMEPLAY::GET_HASH_KEY((char*)Vans1[Vans].c_str()));
			Menu::Main::End("shopui_title_clubhousemod", "shopui_title_clubhousemod");
			break;
			//Menu::Menu::Main::Bool("Spawn in Car", Features::spawnincar);
			//Menu::Menu::Main::Bool("Spawn Maxed", Features::spawnmaxed);
			/*Menu::Main::Submenu("Smugglers", Smugglers);
			Menu::Main::Submenu("GunRunning", GunRunning);
			Menu::Main::Submenu("Super", Super);
			Menu::Main::Submenu("Sports", Sports);
			Menu::Main::Submenu("Sport Classic", SportClassic);
			Menu::Main::Submenu("Offroad", Offroad);
			Menu::Main::Submenu("Sedans", Sedans);
			Menu::Main::Submenu("Coupes", Coupes);
			Menu::Main::Submenu("Muscle", Muscle);
			Menu::Main::Submenu("Boats", Boats);
			Menu::Main::Submenu("Commercial", Commercial);
			Menu::Main::Submenu("Compacts", Compacts);
			Menu::Main::Submenu("Cycles", Cycles);
			Menu::Main::Submenu("Emergency", Emergency);
			Menu::Main::Submenu("Helicopters", Helicopters);
			Menu::Main::Submenu("Industrial", Industrial);
			Menu::Main::Submenu("Military", Military);
			Menu::Main::Submenu("Motorcycles", Motorcycles);
			Menu::Main::Submenu("Planes", Planes);
			Menu::Main::Submenu("Service", Service);
			Menu::Main::Submenu("SUV", SUV);
			Menu::Main::Submenu("Trailer", Trailer);
			Menu::Main::Submenu("Trains", Trains);
			Menu::Main::Submenu("Utility", Utility);
			Menu::Main::Submenu("Vans", Vans);
			Menu::Main::End("shopui_title_ie_modgarage", "shopui_title_ie_modgarage");
			break;
			case Super:

			for (auto car : Super1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Super");
			break;
			case Sports:

			for (auto car : Sports1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Sports");
			break;
			case SportClassic:

			for (auto car : SportsClassics1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Sports Classic");
			break;
			case Offroad:

			for (auto car : OffRoad1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Offroad");
			break;
			case Sedans:

			for (auto car : Sedans1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Sedans");
			break;
			case Coupes:

			for (auto car : Coupes1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Coupes");
			break;
			case Muscle:

			for (auto car : Muscle1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Muscle");
			break;
			case Boats:

			for (auto car : Boats1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Boats");
			break;
			case Commercial:

			for (auto car : Commercial1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Commercial");
			break;
			case Compacts:

			for (auto car : Compacts1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Compacts");
			break;
			case Cycles:

			for (auto car : Cycles1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Cycles");
			break;
			case Emergency:

			for (auto car : Emergency1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Emergency");
			break;
			case Helicopters:

			for (auto car : Helicopters1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Helicopters");
			break;
			case Industrial:

			for (auto car : Industrial1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Industrial");
			break;
			case Military:

			for (auto car : Military1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Military");
			break;
			case Motorcycles:

			for (auto car : Motorcycles1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Motorcycles");
			break;
			case Planes:

			for (auto car : Planes1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Planes");
			break;
			case Service:

			for (auto car : Service1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Service");
			break;
			case SUV:

			for (auto car : SUVs1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("SUV");
			break;
			case Trailer:

			for (auto car : Trailer1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Trailer");
			break;
			case Trains:

			for (auto car : Trains1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Trains");
			break;
			case Utility:

			for (auto car : Utility1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Utility");
			break;
			case Vans:

			for (auto car : Vans1) {
			if (Menu::Main::Option(car))
			spawn_vehicle(car);
			}
			Menu::Main::End("Vans");
			break;*/
		case Protection:

			if (Menu::Main::Bool("Anti crash", ant))
				ant = !ant;
			if (Menu::Main::Bool("Anti Telepot", ant1))
				ant1 = !ant1;
			if (Menu::Main::Bool("Anti freeze", ant2))
				ant2 = !ant2;
			if (Menu::Main::Bool("Anti Pickup", ant3))
				ant3 = !ant3;
			if (Menu::Main::Bool("Anti crash2", ant4))
				ant4 = !ant4;
			if (Menu::Main::Bool("Fire Protection", ant5))
				ant5 = !ant5;
			if (Menu::Main::Bool("Money Protection", ant6))
				ant6 = !ant6;
			if (Menu::Main::Bool("Rp Protection", ant7))
				ant7 = !ant7;
			if (Menu::Main::Bool("Kick Protection", ant8))
				ant8 = !ant8;
			if (Menu::Main::Bool("Anit Blame Protection", ant9))
				ant9 = !ant9;
			Menu::Main::End("Protections");
			break;

		case ls_customs:
		{
			//DRAW_TEXTURE("shopui_title_supermod", "shopui_title_supermod", titlebox, 0.1199f, 0.26f, 0.086f, 0, 255, 255, 255, 255); dont use it it causes problems as it draws under the rect
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			int ModType;
			if (Menu::Main::Int("Armor", &Armor_, 0, 6, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);//this is for armor
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Armor_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 16, Armor_, 0);
			}
			if (Menu::Main::Int("Brakes", &Brakes_, 0, 4, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Brakes_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 12, Brakes_, 0);
			}
			if (Menu::Main::Int("Transmission", &Transmission_, 0, 4, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Transmission_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 13, Transmission_, 0);
			}
			if (Menu::Main::Int("Bumpers", &Bumpers_, 0, 3, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Bumpers_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 2, Bumpers_, 0);
			}
			if (Menu::Main::Int("Hoods", &Hoods_, 0, 5, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Hoods_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 7, Hoods_, 0);
			}
			if (Menu::Main::Int("Suspension", &Suspension_, 0, 5, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Suspension_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 15, Suspension_, 0);
			}
			if (Menu::Main::Int("Spoiler", &Spoilers_, 0, 6, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Spoilers_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 0, Spoilers_, 0);
			}
			if (Menu::Main::Int("SideSkirts", &Skirts_, 0, 6, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Skirts_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 3, Skirts_, 0);
			}
			if (Menu::Main::Int("Exhaust", &Exhaust_, 0, 6, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Exhaust_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 4, Exhaust_, 0);
			}
			if (Menu::Main::Int("Grill", &Grill_, 0, 3, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Grill_);
				VEHICLE::SET_VEHICLE_MOD(VehID, 6, Grill_, 0);
			}
			if (Menu::Main::Int("Interior", &Interior_, 0, 1, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Interior_);
				VEHICLE::REMOVE_VEHICLE_MOD(VehID, Interior_);
			}
			if (Menu::Main::Int("Window Tint", &Tint_, 0, 5, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Tint_);
				VEHICLE::SET_VEHICLE_WINDOW_TINT(VehID, Tint_);
			}
			if (Menu::Main::Int("Horns", &horns, 1, 32, 1)) {
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, horns);
				VEHICLE::SET_VEHICLE_MOD(VehID, 14, horns, 0);
			}
			if (Menu::Main::Option("Turbo")) {
				turbo();
			}
			if (Menu::Main::Int("Both Color", &Colour_, 0, 150, 1))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_COLOURS(VehID, Colour_, Colour_);
			}
			if (Menu::Main::Int("Primary Color", &Prim_, 0, 150, 1))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_COLOURS(VehID, Prim_, Sec_);
			}
			if (Menu::Main::Int("Secondary Color", &Sec_, 0, 150, 1))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_COLOURS(VehID, Prim_, Sec_);
			}
			if (Menu::Main::Int("Vehicle Red", &Red_, 0, 255, 1))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Red_, Green_, Blue_);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, Red_, Green_, Blue_);
			}
			if (Menu::Main::Int("Vehicle Green", &Green_, 0, 255, 1))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Red_, Green_, Blue_);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, Red_, Green_, Blue_);
			}
			if (Menu::Main::Int("Vehicle Blue", &Blue_, 0, 255, 1))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Red_, Green_, Blue_);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, Red_, Green_, Blue_);
			}
			if (Menu::Main::Option("Change Plate")) {
				int vroomCar = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "FMMC_MPM_NA", "", "", "", "", "", 30); // title will be "Name"
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0)
				{
					CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(0);
					WAIT(0);
				}
				if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
				PlateChange(vroomCar);
			}//kk?
			Menu::Main::End("shopui_title_carmod", "shopui_title_carmod");
			/*ModType = VehicleModArmor;
			if (Menu::Main::Submenu("Armor", vehiclemenu_lsc_mods)) selectedModType = VehicleModArmor;
			ModType = VehicleModFrame;
			if (Menu::Main::Submenu("Bodywork", vehiclemenu_lsc_mods)) selectedModType = VehicleModFrame;
			ModType = VehicleModBrakes;//lets see if thoses show up
			if (Menu::Main::Submenu("Brakes", vehiclemenu_lsc_mods)) selectedModType = VehicleModBrakes;
			ModType = VehicleModFrontBumper;
			if (Menu::Main::Submenu("Bumper (Front)", vehiclemenu_lsc_mods)) selectedModType = VehicleModFrontBumper;
			ModType = VehicleModRearBumper;
			if (Menu::Main::Submenu("Bumper (Rear)", vehiclemenu_lsc_mods)) selectedModType = VehicleModRearBumper;
			ModType = VehicleModEngine;
			if (Menu::Main::Submenu("Engine", vehiclemenu_lsc_mods)) selectedModType = VehicleModEngine;
			ModType = VehicleModExhaust;
			if (Menu::Main::Submenu("Exhaust", vehiclemenu_lsc_mods)) selectedModType = VehicleModExhaust;
			ModType = VehicleModSpoilers;
			if (Menu::Main::Submenu("Spoiler", vehiclemenu_lsc_mods)) selectedModType = VehicleModSpoilers;
			ModType = VehicleModSideSkirt;
			if (Menu::Main::Submenu("Side Skirt", vehiclemenu_lsc_mods)) selectedModType = VehicleModSideSkirt;
			ModType = VehicleModGrille;
			if (Menu::Main::Submenu("Grille", vehiclemenu_lsc_mods)) selectedModType = VehicleModGrille;
			ModType = vehicleModHood;
			if (Menu::Main::Submenu("Hood", vehiclemenu_lsc_mods)) selectedModType = vehicleModHood;
			ModType = VehicleModFender;
			if (Menu::Main::Submenu("Fender", vehiclemenu_lsc_mods)) selectedModType = VehicleModFender;
			ModType = VehicleModRightFender;
			if (Menu::Main::Submenu("Right Fender", vehiclemenu_lsc_mods)) selectedModType = VehicleModRightFender;
			ModType = VehicleModRoof;
			if (Menu::Main::Submenu("Roof", vehiclemenu_lsc_mods)) selectedModType = VehicleModRoof;
			ModType = VehicleModTransmission;
			if (Menu::Main::Submenu("Transmission", vehiclemenu_lsc_mods)) selectedModType = VehicleModTransmission;
			ModType = VehicleModHorns;
			if (Menu::Main::Submenu("Horns", vehiclemenu_lsc_mods)) selectedModType = VehicleModHorns;
			ModType = VehicleModSuspension;
			if (Menu::Main::Submenu("Suspension", vehiclemenu_lsc_mods)) selectedModType = VehicleModSuspension;
			ModType = vehicleModUnk_17;
			if (Menu::Main::Submenu("Unk17", vehiclemenu_lsc_mods)) selectedModType = vehicleModUnk_17;
			ModType = vehicleModeTurbo;
			if (Menu::Main::Submenu("Turbo", vehiclemenu_lsc_mods)) selectedModType = vehicleModeTurbo;
			ModType = vehicleModUnk_19;
			if (Menu::Main::Submenu("Unk19", vehiclemenu_lsc_mods)) selectedModType = vehicleModUnk_19;
			ModType = vehicleModTireSmoke;
			if (Menu::Main::Submenu("Tiresmoke", vehiclemenu_lsc_mods)) selectedModType = vehicleModTireSmoke;
			ModType = vehicleModeUnk_21;
			if (Menu::Main::Submenu("Unk21", vehiclemenu_lsc_mods)) selectedModType = vehicleModeUnk_21;
			ModType = vehicleModXenonLights;
			if (Menu::Main::Submenu("Xenon Lights", vehiclemenu_lsc_mods)) selectedModType = vehicleModXenonLights;
			ModType = VehicleModFrontWheels;
			if (Menu::Main::Submenu("Front Wheels", vehiclemenu_lsc_mods)) selectedModType = VehicleModFrontWheels;
			ModType = VehicleModBackWheels;
			if (Menu::Main::Submenu("Back Wheels", vehiclemenu_lsc_mods)) selectedModType = VehicleModBackWheels;//kk?
			Menu::Main::End("shopui_title_supermod", "shopui_title_supermod");*/
		}
		break;
		case vehiclemenu_lsc_mods:
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			switch (selectedModType)
			{
			case VehicleModArmor:
			{

				if (Menu::Main::Int("Armor", &Armor_, 0, 6, 1)); {//tried that didnt work wut u mean? 
					int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);//this is for armor
					VEHICLE::SET_VEHICLE_MOD_KIT(VehID, Armor_);
					VEHICLE::SET_VEHICLE_MOD(VehID, 16, Armor_, 0);
				}
				Menu::Main::End("shopui_title_supermod", "shopui_title_supermod");
			} break;
			case VehicleModFrame:
			{
				int ModType = VehicleModFrame;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Bodywork");
			} break;
			case VehicleModBrakes:
			{
				int ModType = VehicleModBrakes;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				if (Menu::Main::Option("Street Brakes")) changemod(ModType, 0);
				if (Menu::Main::Option("Sport Brakes")) changemod(ModType, 1);
				if (Menu::Main::Option("Race Brakes")) changemod(ModType, 2);
				Menu::Main::End("Brakes");
			} break;
			case VehicleModFrontBumper:
			{
				int ModType = VehicleModFrontBumper;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Front Bumper");
			} break;
			case VehicleModRearBumper:
			{
				int ModType = VehicleModRearBumper;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Rear Bumper");
			} break;
			case VehicleModEngine:
			{
				int ModType = VehicleModEngine;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				if (Menu::Main::Option("Level 1")) changemod(ModType, 0);
				if (Menu::Main::Option("Level 2")) changemod(ModType, 1);
				if (Menu::Main::Option("Level 3")) changemod(ModType, 2);
				if (Menu::Main::Option("Level 4")) changemod(ModType, 3);
				Menu::Main::End("Engine");
			} break;
			case VehicleModExhaust:
			{
				int ModType = VehicleModExhaust;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Exhaust");
			} break;
			case VehicleModSpoilers:
			{
				int ModType = VehicleModSpoilers;// WAIIIIT A SECOND NVM
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Spoiler");
			} break;

			case VehicleModSideSkirt:
			{
				int ModType = VehicleModSideSkirt;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Side Skirt");
			} break;

			case VehicleModGrille:
			{
				int ModType = VehicleModGrille;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Griller");
			} break;
			case vehicleModHood:
			{
				int ModType = vehicleModHood;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Hood");
			} break;
			case VehicleModFender:
			{
				int ModType = VehicleModFender;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Fender");
			} break;
			case VehicleModRightFender:
			{
				int ModType = VehicleModRightFender;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Right Fender");
			} break;
			case VehicleModRoof:
			{
				int ModType = VehicleModRoof;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Roof");
			} break;
			case VehicleModTransmission:
			{
				int ModType = VehicleModTransmission;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option((VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Transmission");
			} break;
			case VehicleModHorns:
			{
				int ModType = VehicleModHorns;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option((VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Horns");
			} break;
			case VehicleModSuspension:
			{
				int ModType = VehicleModSuspension;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option((VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Suspension");
			} break;
			case vehicleModUnk_17:
			{
				int ModType = vehicleModUnk_17;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Unk17");
			} break;
			case vehicleModeTurbo:
			{
				int ModType = vehicleModeTurbo;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Turbo");
			} break;
			case vehicleModUnk_19:
			{
				int ModType = vehicleModUnk_19;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Unk19");
			} break;
			case vehicleModTireSmoke:
			{
				int ModType = vehicleModTireSmoke;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Tire Smoke");
			} break;
			case vehicleModeUnk_21:
			{
				int ModType = vehicleModeUnk_21;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option((VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Unk21");
			} break;
			case vehicleModXenonLights:
			{
				int ModType = vehicleModXenonLights;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Xenon Lights");
			} break;
			case VehicleModFrontWheels:// these are for motorcycles;.......................................dude?
			{
				int ModType = VehicleModFrontWheels;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)// alright lemme see this in game
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Front Wheels");
			} break;
			case VehicleModBackWheels:
			{
				int ModType = VehicleModBackWheels;
				int amount = VEHICLE::GET_NUM_VEHICLE_MODS(veh, ModType);

				if (Menu::Main::Option("None")) changemod(ModType, -1);
				for (int i = 0; i < amount; i++)
				{
					if (Menu::Main::Option(UI::_GET_LABEL_TEXT(VEHICLE::GET_MOD_TEXT_LABEL(veh, ModType, i)))) changemod(ModType, i);
				}
				Menu::Main::End("Back Wheels");
			} break;
			}
		}
		break;
		case map_option:
			Menu::Main::Submenu("Maze Bank Demolition", mod_maze_demo);
			Menu::Main::Submenu("Maze Bank Roof Ramp", mod_maze_ramp);
			Menu::Main::Submenu("Beach Ferris-Ramp", ferris_ramp);
			Menu::Main::Submenu("Mount Chilliad Ramp", chiliad_ramp);
			Menu::Main::Submenu("Airport Mini Ramp", airport_mini);
			Menu::Main::Submenu("Airport Gate Ramp", airport_gate);
			Menu::Main::Submenu("UFO Tower", UFO_Tower);
			Menu::Main::Submenu("Maze Bank Quad Ramp", mod_maze_quad);
			Menu::Main::Submenu("Fort Zancudo Motorcross", zancudo_moto);
			Menu::Main::Submenu("Halfpipe Fun Track", halfpipe);
			Menu::Main::Submenu("Airport Loop", air_loop);// red always need firah xd xd xd xd 
			Menu::Main::Submenu("Maze Bank Ramp", mod_maze_ramp2);
			Menu::Main::End("Map Mods");
			break;
		case mod_maze_demo:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(2475986526, -80.9087, -830.357, 325.097, -14.4264, -8.53774, 152.209, -1, 0);
				PlaceObjectByHash(2475986526, -79.2316, -831.297, 325.108, -14.4054, 4.26887, 164.271, -1, 0);
				PlaceObjectByHash(2475986526, -76.7563, -831.549, 325.123, -14.4263, -0, 171.818, -1, 0);
				PlaceObjectByHash(2475986526, -74.2595, -831.691, 325.09, -14.2059, -1.06722, -176.517, -1, 0);
				PlaceObjectByHash(2475986526, -71.9478, -831.257, 325.113, -14.4264, 2.13443, -166.006, -1, 0);
				PlaceObjectByHash(2475986526, -69.5981, -830.542, 325.066, -14.5918, -4.26887, -155.474, -1, 0);
				PlaceObjectByHash(2475986526, -67.4174, -829.035, 325.097, -14.4263, -4.26887, -140.651, -1, 0);
				PlaceObjectByHash(2475986526, -65.7121, -827.409, 325.068, -14.3048, -1.70755, -130.667, -1, 0);
				PlaceObjectByHash(2475986526, -64.2717, -825.422, 325.112, -14.4263, -0, -121.256, -1, 0);
				PlaceObjectByHash(2475986526, -63.2876, -823.434, 325.114, -14.5345, -0, -111.446, -1, 0);
				PlaceObjectByHash(2475986526, -62.4924, -821.128, 325.082, -14.5467, 2.13443, -102.385, -1, 0);
				PlaceObjectByHash(2475986526, -62.233, -818.528, 325.065, -14.6184, -8.00413, -88.1861, -1, 0);
				PlaceObjectByHash(2475986526, -62.8694, -815.926, 325.118, -14.4265, -6.4033, -76.5979, -1, 0);
				PlaceObjectByHash(2475986526, -63.6142, -813.68, 325.112, -14.3655, 8.53774, -66.7885, -1, 0);
				PlaceObjectByHash(2475986526, -64.9883, -811.439, 325.107, -14.4263, 1.28066, -52.8494, -1, 0);
				PlaceObjectByHash(2475986526, -66.5913, -808.328, 325.238, -12.4517, -0, -40.3246, -1, 0);
				PlaceObjectByHash(2475986526, -68.2603, -807.899, 325.336, -13.8689, -0, -33.062, -1, 0);
				PlaceObjectByHash(2475986526, -71.1526, -807.598, 325.153, -12.0416, 4.26887, -28.0523, -1, 0);
				PlaceObjectByHash(2475986526, -73.2853, -806.628, 325.151, -11.7962, -0, -19.1717, -1, 0);
				PlaceObjectByHash(2475986526, -75.2243, -806.286, 325.164, -12.0419, -0, 1.55726, -1, 0);
				PlaceObjectByHash(2475986526, -77.5757, -806.312, 325.088, -14.1843, -0, 12.6263, -1, 0);
				PlaceObjectByHash(2475986526, -79.8704, -807.22, 325.143, -14.049, -4.26887, 21.4769, -1, 0);
				PlaceObjectByHash(2475986526, -82.0222, -807.83, 325.036, -14.1422, -4.26887, 32.7605, -1, 0);
				PlaceObjectByHash(2475986526, -83.8934, -809.424, 325.073, -14.5264, -8.53774, 46.5132, -1, 0);
				PlaceObjectByHash(2475986526, -85.2523, -810.983, 325.043, -14.859, -0, 53.5324, -1, 0);
				PlaceObjectByHash(2475986526, -86.5177, -813.202, 325.089, -14.5267, 4.26887, 64.6634, -1, 0);
				PlaceObjectByHash(2475986526, -87.6645, -815.707, 325.059, -14.8589, 4.26887, 73.157, -1, 0);
				PlaceObjectByHash(2475986526, -87.7973, -817.987, 325.119, -14.8468, -1.33402, 89.3982, -1, 0);
				PlaceObjectByHash(2475986526, -87.5801, -821.034, 325.059, -14.8593, -0, 95.4435, -1, 0);
				PlaceObjectByHash(2475986526, -87.2815, -822.239, 325.126, -15.6308, -4.26887, 100.311, -1, 0);
				PlaceObjectByHash(2475986526, -86.7602, -824.03, 325.044, -15.9224, -0, 116.957, -1, 0);
				PlaceObjectByHash(2475986526, -85.3743, -826.099, 325.136, -15.7025, 2.56132, 124.307, -1, 0);
				PlaceObjectByHash(2475986526, -83.4737, -828.611, 325.076, -15.0688, -0, 132.538, -1, 0);
				PlaceObjectByHash(2475986526, -87.9554, -832.877, 325.894, -14.1563, 4.26887, 132.995, -1, 0);
				PlaceObjectByHash(2475986526, -89.3865, -831.322, 325.887, -14.1562, -0, 126.154, -1, 0);
				PlaceObjectByHash(2475986526, -86.4247, -834.407, 325.915, -14.2701, 4.26887, 143.277, -1, 0);
				PlaceObjectByHash(2475986526, -85.1736, -833.789, 325.653, -14.4072, -4.26887, 145.777, -1, 0);
				PlaceObjectByHash(2475986526, -83.8118, -835.765, 326.063, -12.243, 4.26887, 151.527, -1, 0);
				PlaceObjectByHash(2475986526, -80.7015, -837.145, 326.059, -12.3172, 2.13443, 162.332, -1, 0);
				PlaceObjectByHash(2475986526, -77.6428, -837.649, 326.163, -10.8391, 3.20165, 171.297, -1, 0);
				PlaceObjectByHash(2475986526, -75.479, -837.909, 326.025, -12.3172, -1.06722, 174.574, -1, 0);
				PlaceObjectByHash(2475986526, -73.861, -837.826, 326.061, -12.3173, 5.33609, -176.632, -1, 0);
				PlaceObjectByHash(2475986526, -70.4799, -837.265, 326.09, -12.3173, -0, -166.182, -1, 0);
				PlaceObjectByHash(2475986526, -67.0415, -836.185, 326.018, -12.3171, -0, -156.039, -1, 0);
				PlaceObjectByHash(2475986526, -64.8504, -834.996, 325.951, -11.5263, -0, -145.834, -1, 0);
				PlaceObjectByHash(2475986526, -63.5702, -833.725, 326.1, -11.2947, -0, -140.961, -1, 0);
				PlaceObjectByHash(2475986526, -60.9992, -831.419, 326.075, -11.5262, -4.26887, -130.963, -1, 0);
				PlaceObjectByHash(2475986526, -58.9923, -828.729, 326.116, -11.5262, 4.26887, -121.973, -1, 0);
				PlaceObjectByHash(2475986526, -57.5045, -825.626, 326.114, -11.5263, -0, -110.959, -1, 0);
				PlaceObjectByHash(2475986526, -56.5533, -822.397, 326.08, -11.1311, -6.4033, -102, -1, 0);
				PlaceObjectByHash(2475986526, -56.0911, -820.05, 326.049, -11.0325, 2.13443, -100.794, -1, 0);
				PlaceObjectByHash(2475986526, -56.0681, -818.32, 326.087, -11.1312, -2.66804, -87.9469, -1, 0);
				PlaceObjectByHash(2475986526, -56.2989, -816.237, 326.048, -11.0324, 2.13443, -83.2139, -1, 0);
				PlaceObjectByHash(2475986526, -56.8952, -814.518, 326.142, -11.0324, -2.13443, -76.5476, -1, 0);
				PlaceObjectByHash(2475986526, -58.1209, -811.23, 326.116, -10.9697, -0, -66.7674, -1, 0);
				PlaceObjectByHash(2475986526, -59.0622, -809.17, 326.095, -11.0574, 4.26887, -62.782, -1, 0);
				PlaceObjectByHash(2475986526, -60.096, -807.639, 326.119, -11.5544, -0, -52.7596, -1, 0);
				PlaceObjectByHash(2475986526, -62.081, -805.317, 326.116, -11.1035, -0, -40.7682, -1, 0);
				PlaceObjectByHash(2475986526, -64.1466, -804.55, 326.283, -11.1035, -0, -30.477, -1, 0);
				PlaceObjectByHash(2475986526, -67.9795, -798.8, 326.717, -10.1561, -0, -29.3495, -1, 0);
				PlaceObjectByHash(2475986526, -67.5734, -802.52, 326.262, -10.471, -8.53774, -31.2185, -1, 0);
				PlaceObjectByHash(2475986526, -70.9341, -800.541, 326.198, -10.5317, -0, -20.0064, -1, 0);
				PlaceObjectByHash(2475986526, -75.3309, -801.285, 325.849, -10.2407, -0, 1.58401, -1, 0);
				PlaceObjectByHash(2475986526, -74.0222, -799.865, 326.177, -10.7327, -0, -5.98314, -1, 0);
				PlaceObjectByHash(2475986526, -76.5167, -797.998, 326.32, -12.4969, -2.66804, 1.58883, -1, 0);
				PlaceObjectByHash(2475986526, -79.2787, -800.531, 326.011, -12.9433, 4.26887, 13.0054, -1, 0);
				PlaceObjectByHash(2475986526, -81.6721, -801.017, 325.9, -12.4601, 2.13443, 17.3792, -1, 0);
				PlaceObjectByHash(2475986526, -83.6027, -801.744, 325.971, -12.9433, -0, 26.3052, -1, 0);
				PlaceObjectByHash(2475986526, -85.6586, -802.789, 325.95, -12.8791, 1.28066, 32.5856, -1, 0);
				PlaceObjectByHash(2475986526, -87.5086, -804.25, 325.978, -12.9432, 4.26887, 42.3279, -1, 0);
				PlaceObjectByHash(2475986526, -88.9923, -805.73, 325.89, -11.9333, -4.26887, 46.0613, -1, 0);
				PlaceObjectByHash(2475986526, -90.167, -807.318, 325.946, -13.0244, -0, 53.178, -1, 0);
				PlaceObjectByHash(2475986526, -93.5987, -807.353, 326.343, -11.5713, 4.26887, 60.8753, -1, 0);
				PlaceObjectByHash(2475986526, -93.5166, -813.963, 325.942, -13.4341, -4.26887, 73.0256, -1, 0);
				PlaceObjectByHash(2475986526, -92.121, -810.584, 325.996, -13.4339, -4.26887, 64.9353, -1, 0);
				PlaceObjectByHash(2475986526, -93.9931, -815.866, 325.924, -13.0519, -0, 79.5966, -1, 0);
				PlaceObjectByHash(2475986526, -93.8716, -817.904, 325.988, -13.4339, -0, 88.8361, -1, 0);
				PlaceObjectByHash(2475986526, -93.7912, -821.777, 325.946, -13.6946, -2.66804, 91.1427, -1, 0);
				PlaceObjectByHash(2475986526, -93.2951, -823.554, 325.966, -13.157, -0, 101.424, -1, 0);
				PlaceObjectByHash(2475986526, -92.5757, -827.033, 325.87, -13.5323, -0, 104.668, -1, 0);
				PlaceObjectByHash(2475986526, -91.53, -828.342, 325.842, -14.1563, 4.26887, 120.328, -1, 0);
				PlaceObjectByHash(2475986526, -90.5203, -829.611, 325.936, -14.1563, -0, 124.573, -1, 0);
				PlaceObjectByHash(2475986526, -95.5355, -833.068, 327.049, -9.63525, 1.70755, 124.512, -1, 0);
				PlaceObjectByHash(2475986526, -94.2445, -835.1, 326.976, -9.27617, -1.28066, 128.396, -1, 0);
				PlaceObjectByHash(2475986526, -92.513, -837.087, 327.008, -9.63523, -4.26887, 132.871, -1, 0);
				PlaceObjectByHash(2475986526, -90.07, -839.341, 327.025, -9.63574, 4.26887, 143.545, -1, 0);
				PlaceObjectByHash(2475986526, -86.7336, -841.135, 327.284, -9.63566, -0, 150.983, -1, 0);
				PlaceObjectByHash(2475986526, -84.8343, -842.167, 327.254, -9.36742, -4.26887, 152.377, -1, 0);
				PlaceObjectByHash(2475986526, -90.0883, -842.661, 327.589, -7.98782, -8.53774, 146.409, -1, 0);
				PlaceObjectByHash(2475986526, -82.595, -843.001, 327.277, -9.6352, -0, 161.654, -1, 0);
				PlaceObjectByHash(2475986526, -80.8027, -843.618, 327.263, -9.36755, -2.13443, 165.215, -1, 0);
				PlaceObjectByHash(2475986526, -78.5619, -843.703, 327.458, -9.63545, -2.13443, 171.015, -1, 0);
				PlaceObjectByHash(2475986526, -76.2479, -844.026, 327.261, -9.36765, 1.06722, 175.986, -1, 0);
				PlaceObjectByHash(2475986526, -73.5382, -843.999, 327.285, -9.6355, -0, -177.212, -1, 0);
				PlaceObjectByHash(2475986526, -71.2047, -843.988, 327.3, -9.36764, -1.06722, -172.013, -1, 0);
				PlaceObjectByHash(2475986526, -69.036, -843.266, 327.309, -9.63525, 4.26887, -166.686, -1, 0);
				PlaceObjectByHash(2475986526, -67.2981, -840.996, 326.756, -9.37509, -2.13443, -159.014, -1, 0);
				PlaceObjectByHash(2475986526, -66.7067, -842.714, 327.222, -9.37501, 2.13443, -159.27, -1, 0);
				PlaceObjectByHash(2475986526, -64.5693, -841.792, 327.24, -9.63515, 4.26887, -156.16, -1, 0);
				PlaceObjectByHash(2475986526, -61.8874, -840.436, 327.231, -9.37483, 4.26887, -146.534, -1, 0);
				PlaceObjectByHash(2475986526, -59.7118, -838.501, 327.384, -9.63533, -0, -141.372, -1, 0);
				PlaceObjectByHash(2475986526, -57.9491, -837.16, 327.309, -9.37471, 4.26887, -135.839, -1, 0);
				PlaceObjectByHash(2475986526, -56.3494, -835.471, 327.34, -9.63578, 4.26887, -131.675, -1, 0);
				PlaceObjectByHash(2475986526, -54.9387, -833.93, 327.334, -9.37482, -0, -127.887, -1, 0);
				PlaceObjectByHash(2475986526, -53.727, -832.032, 327.367, -9.63521, -4.26887, -122.142, -1, 0);
				PlaceObjectByHash(2475986526, -52.5928, -830.077, 327.332, -9.37496, -0, -116.843, -1, 0);
				PlaceObjectByHash(2475986526, -51.7552, -827.819, 327.385, -9.63569, 6.4033, -111.077, -1, 0);
				PlaceObjectByHash(2475986526, -51.0061, -825.839, 327.369, -9.37494, 4.26887, -107.054, -1, 0);
				PlaceObjectByHash(2475986526, -50.5468, -823.622, 327.378, -9.63572, 4.26887, -101.598, -1, 0);
				PlaceObjectByHash(2475986526, -50.0992, -820.896, 327.345, -9.47333, -1.06722, -95.7976, -1, 0);
				PlaceObjectByHash(2475986526, -49.9295, -818.102, 327.381, -9.63531, -8.00413, -88.2146, -1, 0);
				PlaceObjectByHash(2475986526, -50.1895, -815.816, 327.358, -9.4734, -0, -82.8649, -1, 0);
				PlaceObjectByHash(2475986526, -50.9164, -813.132, 327.442, -9.63524, 2.13443, -76.865, -1, 0);
				PlaceObjectByHash(2475986526, -51.1585, -811.568, 327.373, -9.58574, -0, -69.3402, -1, 0);
				PlaceObjectByHash(2475986526, -52.0622, -809.533, 327.354, -9.63541, 2.13443, -65.7624, -1, 0);
				PlaceObjectByHash(2475986526, -53.4048, -806.624, 327.376, -9.63526, 2.13443, -65.3971, -1, 0);
				PlaceObjectByHash(2475986526, -55.2978, -803.815, 327.389, -9.63524, 4.26887, -52.2107, -1, 0);
				PlaceObjectByHash(2475986526, -56.5179, -802.266, 327.366, -9.51013, 4.26887, -50.6537, -1, 0);
				PlaceObjectByHash(2475986526, -57.9995, -800.68, 327.42, -9.6353, 1.28066, -41.7027, -1, 0);
				PlaceObjectByHash(2475986526, -61.0278, -799.404, 327.549, -9.63516, 8.53774, -31.016, -1, 0);
				PlaceObjectByHash(2475986526, -64.37, -797.284, 327.603, -9.6351, -0, -31.6732, -1, 0);
				PlaceObjectByHash(2475986526, -66.3998, -795.965, 327.526, -9.42422, 8.53773, -29.018, -1, 0);
				PlaceObjectByHash(2475986526, -68.8079, -794.744, 327.535, -9.63558, -2.13443, -20.0341, -1, 0);
				PlaceObjectByHash(2475986526, -72.1225, -793.825, 327.497, -9.57894, -2.13443, -12.2336, -1, 0);
				PlaceObjectByHash(2475986526, -75.6415, -795.169, 327.2, -9.63555, -1.60083, 2.8097, -1, 0);
				PlaceObjectByHash(2475986526, -77.9613, -794.235, 327.223, -8.9769, -5.33608, 4.53814, -1, 0);
				PlaceObjectByHash(2475986526, -75.3695, -789.507, 328.306, -8.84722, -8.33763, -0.0879073, -1, 0);
				PlaceObjectByHash(2475986526, -80.6908, -794.505, 327.217, -9.63537, 4.26887, 13.0745, -1, 0);
				PlaceObjectByHash(2475986526, -83.5673, -795.148, 327.101, -9.92985, 2.13443, 17.5819, -1, 0);
				PlaceObjectByHash(2475986526, -86.3087, -796.203, 327.177, -9.63542, -4.26887, 25.9296, -1, 0);
				PlaceObjectByHash(2475986526, -88.9655, -797.634, 327.118, -9.92994, -4.26887, 33.0571, -1, 0);
				PlaceObjectByHash(2475986526, -91.6251, -799.702, 327.176, -9.63539, -0, 42.2513, -1, 0);
				PlaceObjectByHash(2475986526, -93.414, -801.299, 327.124, -9.92995, -0, 48.7085, -1, 0);
				PlaceObjectByHash(2475986526, -95.1453, -803.637, 327.147, -9.63537, -8.53774, 53.6544, -1, 0);
				PlaceObjectByHash(2475986526, -96.5885, -805.701, 327.144, -9.8947, -0, 60.5096, -1, 0);
				PlaceObjectByHash(2475986526, -97.6945, -807.971, 327.174, -9.63569, 4.26887, 64.7568, -1, 0);
				PlaceObjectByHash(2475986526, -98.7075, -809.885, 327.026, -8.13758, -0, 67.8881, -1, 0);
				PlaceObjectByHash(2475986526, -99.394, -812.176, 327.105, -9.63525, -4.26887, 73.0223, -1, 0);
				PlaceObjectByHash(2475986526, -100.025, -814.868, 327.097, -9.97277, 2.13443, 83.1537, -1, 0);
				PlaceObjectByHash(2475986526, -100.012, -817.789, 327.15, -9.63535, -1.33402, 88.8234, -1, 0);
				PlaceObjectByHash(2475986526, -100.069, -819.76, 327.099, -9.95297, -1.33402, 90.8729, -1, 0);
				PlaceObjectByHash(2475986526, -99.969, -821.91, 327.11, -9.63541, -2.66804, 91.5501, -1, 0);
				PlaceObjectByHash(2475986526, -99.3358, -824.801, 327.138, -9.63539, 2.13443, 101.678, -1, 0);
				PlaceObjectByHash(2475986526, -98.5443, -828.598, 327.033, -9.63553, -0, 104.64, -1, 0);
				PlaceObjectByHash(2475986526, -97.0896, -831.054, 326.937, -10.0741, 4.26887, 118.72, -1, 0);
				PlaceObjectByHash(2475986526, -102.435, -833.952, 328.506, -5.26399, -0, 118.502, -1, 0);
				PlaceObjectByHash(2475986526, -103.536, -831.932, 328.513, -5.42142, 4.26887, 111.099, -1, 0);
				PlaceObjectByHash(2475986526, -100.644, -836.571, 328.636, -5.26398, -0, 124.006, -1, 0);
				PlaceObjectByHash(2475986526, -99.0448, -838.912, 328.589, -5.26395, -2.13443, 128.175, -1, 0);
				PlaceObjectByHash(2475986526, -96.9401, -841.184, 328.589, -5.26384, -2.13443, 132.615, -1, 0);
				PlaceObjectByHash(2475986526, -95.4409, -842.718, 328.551, -5.01006, -2.13443, 136.57, -1, 0);
				PlaceObjectByHash(2475986526, -93.6584, -844.231, 328.606, -5.26388, -0, 143.429, -1, 0);
				PlaceObjectByHash(2475986526, -92.1044, -845.82, 328.655, -5.01307, -2.13443, 147.428, -1, 0);
				PlaceObjectByHash(2475986526, -89.6061, -846.328, 328.851, -5.26389, -0, 150.62, -1, 0);
				PlaceObjectByHash(2475986526, -87.5884, -847.552, 328.829, -5.6777, -0, 153.36, -1, 0);
				PlaceObjectByHash(2475986526, -84.5215, -848.802, 328.867, -5.26405, 5.33608, 161.164, -1, 0);
				PlaceObjectByHash(2475986526, -81.9779, -849.605, 328.821, -5.67769, 1.06722, 166.961, -1, 0);
				PlaceObjectByHash(2475986526, -79.5282, -849.717, 329.046, -5.26392, 1.06722, 170.517, -1, 0);
				PlaceObjectByHash(2475986526, -76.7555, -850.113, 328.885, -4.93224, 2.66804, 175.995, -1, 0);
				PlaceObjectByHash(2475986526, -73.2336, -850.06, 328.883, -5.26397, -0, -177.431, -1, 0);
				PlaceObjectByHash(2475986526, -70.4067, -849.836, 328.854, -4.82287, -5.33608, -172.2, -1, 0);
				PlaceObjectByHash(2475986526, -67.6252, -849.166, 328.911, -5.26394, -0, -166.741, -1, 0);
				PlaceObjectByHash(2475986526, -64.6525, -848.331, 328.792, -4.82267, -2.13443, -160.74, -1, 0);
				PlaceObjectByHash(2475986526, -62.1086, -847.355, 328.837, -5.26389, 2.13443, -156.346, -1, 0);
				PlaceObjectByHash(2475986526, -60.2755, -846.895, 328.808, -5.97307, -2.13443, -151.031, -1, 0);
				PlaceObjectByHash(2475986526, -58.5152, -845.543, 328.833, -5.26392, 1.06722, -147.129, -1, 0);
				PlaceObjectByHash(2475986526, -55.9339, -843.258, 328.987, -5.26394, 2.13443, -141.8, -1, 0);
				PlaceObjectByHash(2475986526, -53.6636, -841.564, 328.905, -5.18348, -0, -136.192, -1, 0);
				PlaceObjectByHash(2475986526, -51.8013, -839.526, 328.926, -5.26393, -2.13443, -131.788, -1, 0);
				PlaceObjectByHash(2475986526, -49.9112, -837.51, 328.916, -5.18352, -8.53774, -125.894, -1, 0);
				PlaceObjectByHash(2475986526, -48.5833, -835.261, 328.968, -5.26388, 2.13443, -122.598, -1, 0);
				PlaceObjectByHash(2475986526, -47.1369, -832.806, 328.936, -5.18352, -0, -117.146, -1, 0);
				PlaceObjectByHash(2475986526, -46.1092, -830.019, 328.985, -5.26389, -0, -111.097, -1, 0);
				PlaceObjectByHash(2475986526, -45.2549, -827.659, 328.957, -5.18353, -1.06722, -105.915, -1, 0);
				PlaceObjectByHash(2475986526, -44.5598, -824.856, 328.973, -5.26387, -0, -101.582, -1, 0);
				PlaceObjectByHash(2475986526, -44.0346, -821.522, 328.953, -5.26387, 5.33608, -95.978, -1, 0);
				PlaceObjectByHash(2475986526, -43.8673, -817.92, 328.98, -5.26387, -4.00206, -88.1556, -1, 0);
				PlaceObjectByHash(2475986526, -44.1983, -815.072, 328.956, -5.26387, -0, -82.8806, -1, 0);
				PlaceObjectByHash(2475986526, -45.0463, -811.788, 329.021, -5.26392, -0, -77.2513, -1, 0);
				PlaceObjectByHash(2475986526, -45.6154, -809.566, 328.95, -5.25705, -2.13443, -72.2094, -1, 0);
				PlaceObjectByHash(2475986526, -46.5685, -807.149, 328.929, -5.26395, -2.13443, -66.9958, -1, 0);
				PlaceObjectByHash(2475986526, -47.9752, -804.122, 328.959, -5.26398, -0, -65.1505, -1, 0);
				PlaceObjectByHash(2475986526, -49.0785, -802.078, 328.914, -5.31539, 4.26887, -57.7224, -1, 0);
				PlaceObjectByHash(2475986526, -50.5092, -800.141, 328.99, -5.26406, -0, -52.4683, -1, 0);
				PlaceObjectByHash(2475986526, -52.041, -798.134, 329.001, -5.31536, -2.13443, -49.2493, -1, 0);
				PlaceObjectByHash(2475986526, -53.8808, -796.134, 329.041, -5.26389, -0, -42.3308, -1, 0);
				PlaceObjectByHash(2475986526, -55.4375, -794.682, 329.045, -5.32055, 2.13443, -37.3601, -1, 0);
				PlaceObjectByHash(2475986526, -57.7537, -794.2, 329.16, -5.26393, 2.13443, -32.2267, -1, 0);
				PlaceObjectByHash(2475986526, -61.0299, -792.042, 329.172, -5.26389, -2.13443, -32.1174, -1, 0);
				PlaceObjectByHash(2475986526, -63.5163, -790.736, 329.085, -5.04535, -4.26887, -29.2933, -1, 0);
				PlaceObjectByHash(2475986526, -64.7324, -789.882, 329.081, -4.987, -2.13443, -27.7917, -1, 0);
				PlaceObjectByHash(2475986526, -66.7775, -788.94, 329.155, -5.04558, 1.06722, -19.5666, -1, 0);
				PlaceObjectByHash(2475986526, -68.6555, -788.272, 329.103, -5.30654, 3.20165, -16.9146, -1, 0);
				PlaceObjectByHash(2475986526, -70.8259, -787.837, 329.128, -5.04546, 1.06722, -12.2941, -1, 0);
				PlaceObjectByHash(2475986526, -74.5572, -787.022, 329.08, -4.61724, 1.06722, -10.7316, -1, 0);
				PlaceObjectByHash(2475986526, -75.8754, -788.646, 328.671, -6.78921, -0, 2.98721, -1, 0);
				PlaceObjectByHash(2475986526, -78.4, -788.132, 328.83, -5.91899, 2.66804, 3.75875, -1, 0);
				PlaceObjectByHash(2475986526, -80.5351, -788.179, 328.782, -5.80051, -0, 7.26539, -1, 0);
				PlaceObjectByHash(2475986526, -82.1189, -788.558, 328.793, -5.9192, 1.06722, 12.7168, -1, 0);
				PlaceObjectByHash(2475986526, -85.4054, -789.317, 328.666, -5.79433, -0, 17.1877, -1, 0);
				PlaceObjectByHash(2475986526, -87.4651, -789.98, 328.647, -5.63204, -0, 20.2315, -1, 0);
				PlaceObjectByHash(2475986526, -88.9795, -790.697, 328.76, -5.79416, -0, 25.9501, -1, 0);
				PlaceObjectByHash(2475986526, -90.9922, -791.487, 328.684, -6.26149, -0, 27.0819, -1, 0);
				PlaceObjectByHash(2475986526, -92.3298, -792.474, 328.677, -5.79412, -0, 33.3113, -1, 0);
				PlaceObjectByHash(2475986526, -94.2322, -793.73, 328.669, -5.58479, -2.13443, 37.4974, -1, 0);
				PlaceObjectByHash(2475986526, -95.7282, -795.2, 328.764, -5.79431, -0, 41.8672, -1, 0);
				PlaceObjectByHash(2475986526, -97.9782, -797.316, 328.695, -5.58488, -0, 48.9171, -1, 0);
				PlaceObjectByHash(2475986526, -100.042, -800.063, 328.731, -5.79425, 2.13443, 53.7039, -1, 0);
				PlaceObjectByHash(2475986526, -101.884, -802.718, 328.706, -5.5848, 2.13443, 60.3613, -1, 0);
				PlaceObjectByHash(2475986526, -103.09, -805.421, 328.718, -5.79425, -0, 64.506, -1, 0);
				PlaceObjectByHash(2475986526, -104.284, -807.711, 328.691, -5.58488, -2.13443, 65.966, -1, 0);
				PlaceObjectByHash(2475986526, -105.262, -810.369, 328.729, -5.26384, 1.06722, 73.2414, -1, 0);
				PlaceObjectByHash(2475986526, -105.769, -812.146, 328.645, -5.25205, -1.06722, 75.8091, -1, 0);
				PlaceObjectByHash(2475986526, -106.155, -814.128, 328.687, -5.26388, -1.06722, 82.8157, -1, 0);
				PlaceObjectByHash(2475986526, -106.062, -817.685, 328.758, -5.26388, 2.66804, 88.7458, -1, 0);
				PlaceObjectByHash(2475986526, -106.154, -819.723, 328.716, -5.25204, -0, 90.1628, -1, 0);
				PlaceObjectByHash(2475986526, -106.082, -822.072, 328.729, -5.26387, -1.33402, 91.2972, -1, 0);
				PlaceObjectByHash(2475986526, -105.911, -823.815, 328.7, -5.52135, 5.33608, 99.4393, -1, 0);
				PlaceObjectByHash(2475986526, -105.28, -826.029, 328.734, -5.26391, 1.06722, 101.615, -1, 0);
				PlaceObjectByHash(2475986526, -105.06, -827.904, 328.644, -5.29978, 1.06722, 102.515, -1, 0);
				PlaceObjectByHash(2475986526, -104.327, -830.112, 328.614, -5.26391, -2.13443, 104.719, -1, 0);
				PlaceObjectByHash(3291218330, -108.551, -853.416, 327.387, 2.94456, 89.1111, -166.155, -1, 0);
				PlaceObjectByHash(3291218330, -80.2509, -866.418, 327.301, 3.7405, 89.3, 146.641, -1, 0);
				PlaceObjectByHash(3291218330, -55.8513, -863.921, 327.333, 6.87468, 89.6184, 149.776, -1, 0);
				PlaceObjectByHash(3291218330, -37.3907, -848.122, 327.717, 2.33633, 88.8797, -16.2595, -1, 0);
				PlaceObjectByHash(3291218330, -26.1908, -818.332, 328.76, 0.490556, 84.6598, -18.107, -1, 0);
				PlaceObjectByHash(3291218330, -37.891, -789.138, 328.134, 1.11673, 87.6571, 42.7186, -1, 0);
				PlaceObjectByHash(3291218330, -63.492, -772.044, 327.866, 3.09962, 89.1556, 44.702, -1, 0);
				PlaceObjectByHash(3291218330, -93.4916, -774.848, 327.398, 2.73771, 89.0443, 122.539, -1, 0);
				PlaceObjectByHash(3291218330, -115.991, -795.259, 327.27, 3.28432, 89.2033, 123.086, -1, 0);
				PlaceObjectByHash(3291218330, -122.551, -825.074, 327.213, 173.37, 89.6048, 4.27077, -1, 0);
				PlaceObjectByHash(118627012, -74.8438, -819.617, 323.685, 0, 0, -3.37511, -1, 0);
				PlaceObjectByHash(2475986526, -67.6253, -820.244, 323.793, -14.4263, -8.53774, -100.02, -1, 0);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}
			Menu::Main::End("Maze Bank Demolition");
			break;
		case mod_maze_ramp:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(1600026313, -78.4864, -807.943, 323.202, 109.364, -89.9209, 0, -1, 1);
				PlaceObjectByHash(1600026313, -79.2766, -805.701, 323.204, 109.364, -89.9209, 0, -1, 1);
				PlaceObjectByHash(1600026313, -79.8373, -803.709, 323.205, 109.364, -89.9209, 0, -1, 1);
				PlaceObjectByHash(1600026313, -80.4295, -801.947, 323.207, 109.364, -89.9209, 0, -1, 1);
				PlaceObjectByHash(4143853297, -97.4731, -778.557, 308.877, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(1087520462, -84.2429, -793.182, 321.08, -63.5625, -0, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -83.5429, -795.106, 322.073, -63.5625, -0, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -84.9429, -791.108, 319.956, -62.6673, 8.53774e-007, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -85.8122, -788.585, 318.638, -63.5625, -0, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -89.1589, -779.487, 313.336, -59.5389, 0.0405551, -160.567, -1, 1);
				PlaceObjectByHash(1087520462, -90.7065, -774.863, 310.09, -57.4959, 0.322988, -160.758, -1, 1);
				PlaceObjectByHash(1087520462, -91.4887, -772.564, 308.403, -55.1692, 0.383369, -161.049, -1, 1);
				PlaceObjectByHash(1087520462, -91.7565, -771.74, 307.844, -56.4466, 0.0442451, -160.565, -1, 1);
				PlaceObjectByHash(1087520462, -93.6941, -766.245, 302.736, -45.9996, 0.0556114, -160.556, -1, 1);
				PlaceObjectByHash(1087520462, -94.2969, -764.648, 301.067, -44.7623, -1.70755e-006, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -94.2969, -764.648, 301.067, -44.7623, -1.70755e-006, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -94.886, -762.996, 298.741, -36.7051, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -95.4855, -761.334, 296.406, -36.7051, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -95.4855, -761.334, 296.406, -36.7051, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -96.1606, -759.499, 294.259, -42.0766, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.709, -36.7051, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.709, -36.7051, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -96.0707, -759.689, 293.46, -36.7051, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -96.8807, -757.391, 292.506, -51.0291, -8.53774e-007, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -96.8807, -757.391, 292.506, -51.0291, -8.53774e-007, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -97.3203, -756.159, 291.688, -57.2958, -0, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -97.9597, -754.358, 290.78, -62.6673, 8.53774e-007, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -97.9597, -754.358, 290.78, -62.6673, 8.53774e-007, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -98.7192, -752.356, 290.042, -69.9278, 3.20165e-005, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -99.0244, -751.684, 290.499, -90, -8.46346e-007, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -99.3223, -750.534, 290.479, -90, -8.46346e-007, -160.249, -1, 1);
				PlaceObjectByHash(1087520462, -100.348, -747.881, 290.452, -89.5256, -1.33402e-008, -159.354, -1, 1);
				PlaceObjectByHash(1087520462, -100.26, -748.154, 290.462, -76.096, 4.26887e-007, 19.6954, -1, 1);
				PlaceObjectByHash(1087520462, -100.687, -747.053, 290.731, -62.6673, -8.53774e-007, 20.5907, -1, 1);
				PlaceObjectByHash(1087520462, -101.346, -745.387, 291.611, -58.191, 1.70755e-006, 19.6954, -1, 1);
				PlaceObjectByHash(1087520462, -102.234, -743.119, 293.091, -52.2249, 0.00051141, 21.3426, -1, 1);
				PlaceObjectByHash(2475986526, -102.154, -739.285, 294.83, 9.80014, 0.295618, 18.7802, -1, 1);
				PlaceObjectByHash(2475986526, -105.054, -740.282, 294.827, 9.80014, 0.295618, 18.7802, -1, 1);
				PlaceObjectByHash(1087520462, -103.071, -741.047, 294.832, -48.0666, 0.000519094, 21.3419, -1, 1);
				PlaceObjectByHash(1087520462, -103.75, -739.405, 296.413, -45.1472, 0.000547269, 21.3416, -1, 1);
				PlaceObjectByHash(4143853297, -90.3515, -798.112, 319.893, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -93.2293, -790.348, 317.189, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -95.3479, -784.483, 313.696, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -100.01, -771.31, 304.367, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -101.829, -766.277, 299.666, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -103.318, -762.175, 293.966, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -104.948, -757.681, 288.866, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -108.146, -748.798, 288.866, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -108.146, -748.798, 295.608, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -108.225, -748.694, 302.608, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(3167053133, -103.451, -740.541, 307.317, -0.900199, -1.19985, 20.9076, -1, 1);
				PlaceObjectByHash(2375650849, -102.454, -742.6, 309.309, 0, 0, 20.9393, -1, 1);
				PlaceObjectByHash(4143853297, -101.483, -746.044, 305.602, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -94.7458, -743.402, 295.608, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -94.7566, -743.406, 288.866, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -94.7426, -743.595, 302.651, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(1157292806, -99.7732, -750.516, 309.575, 0, 0, 24.1761, -1, 1);
				PlaceObjectByHash(4143853297, -89.9785, -756.476, 293.966, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -91.5378, -752.285, 288.866, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -87.9094, -762.07, 299.666, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -86.2094, -766.939, 304.367, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -84.0215, -772.971, 309.575, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -81.6733, -779.348, 313.696, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -79.5187, -785.083, 317.189, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(4143853297, -76.5616, -793.191, 319.493, 0, -0, -159.831, -1, 1);
				PlaceObjectByHash(1998517203, -81.0993, -790.139, 326.57, 0, 0, -82.6177, -1, 1);
				PlaceObjectByHash(1998517203, -88.8988, -792.911, 326.95, 0, 0, -82.6177, -1, 1);
				PlaceObjectByHash(803874239, -88.3376, -794.173, 327.042, 0, 0, 31.5501, -1, 1);
				PlaceObjectByHash(803874239, -90.0376, -795.174, 327.262, 0, 0, 31.5501, -1, 1);
				PlaceObjectByHash(803874239, -91.6375, -796.175, 327.482, 0, 0, 31.5501, -1, 1);
				PlaceObjectByHash(803874239, -79.0283, -791.31, 326.763, 0, -0, 100.953, -1, 1);
				PlaceObjectByHash(803874239, -76.8377, -790.87, 326.823, 0, -0, 100.953, -1, 1);
				PlaceObjectByHash(803874239, -81.0088, -791.22, 326.713, 0, -0, 100.953, -1, 1);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}
			Menu::Main::End("Maze Bank Roof Ramp");
			break;
		case ferris_ramp:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(1952396163, -1497.76, -1113.84, -3.08, -90, 6.14715e-007, 165.792, -1, 2);
				PlaceObjectByHash(2475986526, -1461.92, -1216.88, 2.5836, -2.3048, -0, -154.878, -1, 2);
				PlaceObjectByHash(3291218330, -1465.62, -1217.64, 18, 166.516, -5.12264e-006, 24.1717, -1, 2);
				PlaceObjectByHash(3291218330, -1458.89, -1214.4, 18, -38.4956, 8.53774e-007, -153.982, -1, 2);
				PlaceObjectByHash(2475986526, -1460.32, -1219.97, 4.3801, 12.6953, -0, -154.878, -1, 2);
				PlaceObjectByHash(2475986526, -1457, -1226.67, 11.8772, 31.7229, -0, -154.382, -1, 2);
				PlaceObjectByHash(2475986526, -1458.4, -1223.77, 7.9937, 23.6001, -0.0916355, -154.918, -1, 2);
				PlaceObjectByHash(2475986526, -1456.4, -1228.27, 14.9608, 48.674, -0, -153.982, -1, 2);
				PlaceObjectByHash(2475986526, -1456, -1229.07, 19.7441, 68.6628, -0, -153.982, -1, 2);
				PlaceObjectByHash(2475986526, -1456.2, -1228.47, 24.8276, 82.6252, 3.80938, -152.828, -1, 2);
				PlaceObjectByHash(2475986526, -1456.9, -1226.47, 28.9111, 108.498, -8.51368, -157.244, -1, 2);
				PlaceObjectByHash(2475986526, -1458.59, -1223.37, 31.5945, 130.616, -4.72983, -155.087, -1, 2);
				PlaceObjectByHash(2475986526, -1460.59, -1218.38, 33.5779, 143.744, -3.95611, -152.581, -1, 2);
				PlaceObjectByHash(2475986526, -1462.79, -1214.28, 34.161, 163.63, -2.68302, -155.763, -1, 2);
				PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, 4.69576e-006, -152.192, -1, 2);
				PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, 4.69576e-006, -152.192, -1, 2);
				PlaceObjectByHash(2475986526, -1466.9, -1205.68, 29.0062, -155.178, 9.47689e-005, -153.087, -1, 2);
				PlaceObjectByHash(2475986526, -1468.3, -1202.98, 24.1897, -131.11, 6.74481e-005, -153.088, -1, 2);
				PlaceObjectByHash(2475986526, -1468.59, -1202.68, 19.3732, -107.429, 3.07358e-005, -153.087, -1, 2);
				PlaceObjectByHash(2475986526, -1467.99, -1203.88, 13.5732, -89.6528, -0.153235, -155.853, -1, 2);
				PlaceObjectByHash(2475986526, -1467.11, -1205.68, 10.7072, -63.5491, 8.53774e-007, -156.504, -1, 2);
				PlaceObjectByHash(4109455646, -1465.05, -1210.03, 7.9503, 9.53319, 1.38057, 24.2606, -1, 2);
				PlaceObjectByHash(2975320548, -1460.95, -1218.79, 7.66, -29.9323, -0.173323, 24.7221, -1, 2);
				PlaceObjectByHash(2975320548, -1463.05, -1214.19, 6.7879, -6.50192, 1.391, 24.2651, -1, 2);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1513.0f, -1192.0f, 1.0f, 1, 0, 0, 1);
			}
			Menu::Main::End("Beach Ferris-Ramp");
			break;
		case chiliad_ramp:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(1952396163, -1497.76, -1113.84, -3.08, -90, -0, 165.792, 90, 3);
				PlaceObjectByHash(2475986526, -1461.92, -1216.88, 2.5836, -2.3048, 0, -154.878, 205.14, 3);
				PlaceObjectByHash(3291218330, -1458.89, -1214.4, 18, -38.4956, 0, -153.982, 211.95, 3);
				PlaceObjectByHash(2475986526, -1460.32, -1219.97, 4.3801, 12.6953, 0, -154.878, 205.672, 3);
				PlaceObjectByHash(2975320548, -1463.05, -1214.19, 6.7879, -6.5, -1.391, 24.2651, 24.4244, 3);
				PlaceObjectByHash(3291218330, -1465.62, -1217.64, 18, 166.516, 180, 24.1717, 155.224, 3);
				PlaceObjectByHash(4109455646, -1465.05, -1210.03, 7.9503, 9.5304, -1.3806, 24.2606, 24.5148, 3);
				PlaceObjectByHash(2975320548, -1460.95, -1218.79, 7.66, -29.9322, 0.1733, 24.7221, 27.9617, 3);
				PlaceObjectByHash(2475986526, -1458.4, -1223.77, 7.9937, 23.6001, 0.0916, -154.918, 207.065, 3);
				PlaceObjectByHash(2475986526, -1467.11, -1205.68, 10.7072, -63.5491, 0, -156.505, 224.303, 3);
				PlaceObjectByHash(2475986526, -1457, -1226.67, 11.8772, 31.7229, 0, -154.382, 209.411, 3);
				PlaceObjectByHash(2475986526, -1456.4, -1228.27, 14.9608, 48.674, 0, -153.982, 216.471, 3);
				PlaceObjectByHash(2475986526, -1456, -1229.07, 19.7441, 68.6628, 0, -153.982, 233.298, 3);
				PlaceObjectByHash(2475986526, -1456.2, -1228.47, 24.8276, 81.7043, -3.8094, -152.828, 252.429, 3);
				PlaceObjectByHash(2475986526, -1456.9, -1226.47, 28.9111, 110.301, 171.486, -157.244, 312.201, 3);
				PlaceObjectByHash(2475986526, -1458.59, -1223.37, 31.5945, 130.843, 175.27, -155.087, 325.759, 3);
				PlaceObjectByHash(2475986526, -1460.59, -1218.38, 33.5779, 143.844, 176.044, -152.581, 327.979, 3);
				PlaceObjectByHash(2475986526, -1462.79, -1214.28, 34.161, 163.648, 177.317, -155.763, 335.024, 3);
				PlaceObjectByHash(2475986526, -1465.3, -1209.78, 32.5228, -172.187, -180, -152.192, 331.971, 3);
				PlaceObjectByHash(2475986526, -1466.9, -1205.68, 29.0062, -155.178, -180, -153.087, 330.783, 3);
				PlaceObjectByHash(2475986526, -1468.3, -1202.98, 24.1897, -131.11, -180, -153.088, 322.332, 3);
				PlaceObjectByHash(2475986526, -1468.59, -1202.68, 19.3732, -107.429, -180, -153.087, 300.544, 3);
				PlaceObjectByHash(2475986526, -1467.99, -1203.88, 13.5732, -89.6205, 0.1532, -155.853, 269.072, 3);
				PlaceObjectByHash(3966705493, 509.842, 5589.24, 791.066, 0.141, 0, 65.3998, 65.3999, 3);
				PlaceObjectByHash(3966705493, 520.5, 5584.38, 790.503, 5.441, 0, 65.3998, 65.4976, 3);
				PlaceObjectByHash(3966705493, 531.057, 5579.54, 788.691, 12.441, 0, 65.3998, 65.9111, 3);
				PlaceObjectByHash(3966705493, 568.672, 5562.32, 767.428, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 576.972, 5558.53, 759.566, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 560.174, 5566.2, 774.698, 35.0403, 0, 65.3998, 69.4512, 3);
				PlaceObjectByHash(3966705493, 541.325, 5574.84, 785.49, 19.4409, 0, 65.3998, 66.6484, 3);
				PlaceObjectByHash(3966705493, 551.066, 5570.37, 780.799, 27.5407, 0, 65.3998, 67.9049, 3);
				PlaceObjectByHash(3966705493, 585.249, 5554.75, 751.745, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 618.334, 5539.62, 720.386, 40.7936, 0, 65.3998, 70.8829, 3);
				PlaceObjectByHash(3966705493, 626.602, 5535.85, 712.547, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 610.065, 5543.4, 728.217, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 601.777, 5547.19, 736.076, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 593.507, 5550.97, 743.917, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 634.862, 5532.07, 704.725, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 643.121, 5528.29, 696.894, 40.7936, 0, 65.3998, 70.8829, 3);
				PlaceObjectByHash(3966705493, 651.391, 5524.51, 689.053, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 659.651, 5520.73, 681.221, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 667.911, 5516.94, 673.389, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 676.171, 5513.17, 665.558, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 684.431, 5509.38, 657.727, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 692.691, 5505.61, 649.905, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 700.95, 5501.83, 642.074, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 709.22, 5498.05, 634.243, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 717.46, 5494.28, 626.431, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 725.72, 5490.5, 618.6, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 733.98, 5486.72, 610.778, 40.7396, 0, 65.3998, 70.8685, 3);
				PlaceObjectByHash(3966705493, 742.6, 5482.78, 603.167, 36.9395, 0, 65.3998, 69.9005, 3);
				PlaceObjectByHash(3966705493, 751.83, 5478.55, 596.335, 31.0392, 0, 65.3998, 68.5807, 3);
				PlaceObjectByHash(3966705493, 761.71, 5474.02, 590.613, 24.5989, 0, 65.3998, 67.3986, 3);
				PlaceObjectByHash(3966705493, 772.07, 5469.28, 586.08, 18.9288, 0, 65.3998, 66.5835, 3);
				PlaceObjectByHash(3966705493, 782.84, 5464.34, 582.86, 11.5788, 0, 65.3998, 65.8427, 3);
				PlaceObjectByHash(3966705493, 793.89, 5459.28, 581.117, 5.0787, 0, 65.3998, 65.485, 3);
				PlaceObjectByHash(3966705493, 805.1, 5454.15, 580.876, -2.5212, 0, 65.3998, 65.4208, 3);
				PlaceObjectByHash(3966705493, 816.17, 5449.08, 581.975, -7.6213, 0, 65.3998, 65.5917, 3);
				PlaceObjectByHash(3966705493, 827.191, 5444.04, 584.582, -16.6212, 0, 65.3998, 66.3125, 3);
				PlaceObjectByHash(3966705493, 837.681, 5439.24, 588.899, -24.421, 0, 65.3998, 67.3698, 3);
				PlaceObjectByHash(2580877897, 522.61, 5584.49, 779.214, 79.7153, -9.2252, 55.7018, 77.7612, 3);
				PlaceObjectByHash(3862788492, 522.445, 5583.69, 779.551, -0.9197, -69.229, -167.468, 184.555, 3);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 500, 5593, 795, 1, 0, 0, 1);
			}
			Menu::Main::End("Mount Chilliad Ramp");
			break;
		case airport_mini:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(2475986526, -1242.08, -2931.15, 12.9924, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				PlaceObjectByHash(2475986526, -1247.11, -2928.46, 15.013, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				PlaceObjectByHash(2475986526, -1251.58, -2926.05, 16.7865, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				PlaceObjectByHash(2475986526, -1254.69, -2924.35, 18.25, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				PlaceObjectByHash(3966705493, -1276.69, -2912.99, 23.0019, 0, 0.05, 60.9705, -1, 4);
				PlaceObjectByHash(2475986526, -1258.35, -2922.28, 20.2135, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				PlaceObjectByHash(3966705493, -1270.89, -2916.22, 23.0123, 0, 0, 60.8909, -1, 4);
				PlaceObjectByHash(3966705493, -1270.25, -2914.99, 23.0137, 0, 0, 60.8909, -1, 4);
				PlaceObjectByHash(3966705493, -1274.87, -2909.4, 23.0049, 0, 0.05, 60.9705, -1, 4);
				PlaceObjectByHash(3966705493, -1269.01, -2912.64, 22.9993, 0, 0.05, 60.9705, -1, 4);
				PlaceObjectByHash(3966705493, -1267.87, -2915.44, 28.3632, 0, -0, 147.299, -1, 4);
				PlaceObjectByHash(3966705493, -1272.13, -2918.33, 28.4791, 0, 0.05, 60.9705, -1, 4);
				PlaceObjectByHash(3966705493, -1272.11, -2918.35, 25.6708, -0.48, 0.0499982, 60.9701, -1, 4);
				PlaceObjectByHash(3966705493, -1277.93, -2915.14, 25.604, 0, 0.05, 60.9705, -1, 4);
				PlaceObjectByHash(3966705493, -1279.69, -2909.85, 25.6358, 0, -0, -151.239, -1, 4);
				PlaceObjectByHash(3966705493, -1279.69, -2909.85, 28.4844, 0, -0, -151.239, -1, 4);
				PlaceObjectByHash(2475986526, -1261.82, -2920.38, 21.767, -0.1046, -3.33505e-009, 61.0607, -1, 4);
				PlaceObjectByHash(3966705493, -1273.65, -2907.11, 22.9763, 0, 0.05, 60.9705, -1, 4);
				PlaceObjectByHash(3966705493, -1267.77, -2910.37, 22.9978, 0, 0.05, 60.9705, -1, 4);
				PlaceObjectByHash(3966705493, -1266.49, -2908.08, 22.9987, 0, -0, -119.462, -1, 4);
				PlaceObjectByHash(3966705493, -1265.15, -2905.8, 23.0042, 0, -0, -119.462, -1, 4);
				PlaceObjectByHash(3966705493, -1266.44, -2905.21, 25.6255, 0, -0, -118.761, -1, 4);
				PlaceObjectByHash(3966705493, -1265.66, -2911.99, 25.6968, 0, 0, -30.9603, -1, 4);
				PlaceObjectByHash(3966705493, -1264.88, -2910.66, 25.6982, 0, 0, -30.9603, -1, 4);
				PlaceObjectByHash(3966705493, -1264.84, -2905.14, 25.624, 0, -0, -118.761, -1, 4);
				PlaceObjectByHash(3966705493, -1272.37, -2900.96, 25.6199, 0, -0, -118.761, -1, 4);
				PlaceObjectByHash(3966705493, -1276.35, -2903.91, 25.6214, 0, -0, -151.239, -1, 4);
				PlaceObjectByHash(3966705493, -1276.35, -2903.91, 28.4329, 0, -0, -151.239, -1, 4);
				PlaceObjectByHash(3966705493, -1272.37, -2900.96, 28.4385, 0, -0, -118.761, -1, 4);
				PlaceObjectByHash(3966705493, -1266.44, -2905.21, 28.437, 0, -0, -118.761, -1, 4);
				PlaceObjectByHash(3966705493, -1265.17, -2905.14, 28.3426, 0, -0, -118.861, -1, 4);
				PlaceObjectByHash(3966705493, -1271.09, -2902.58, 23.0057, 0, -0, -119.462, -1, 4);
				PlaceObjectByHash(3966705493, -1272.37, -2904.83, 22.9972, 0, -0, -119.462, -1, 4);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1208, -2950, 13, 1, 0, 0, 1);
			}
			Menu::Main::End("Airport Mini Ramp");
			break;
		case airport_gate:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(2475986526, -1098.36, -2631.17, 19, 0, -0, 152.671, -1, 5);
				PlaceObjectByHash(2475986526, -1100.26, -2634.64, 21.1976, 16.2002, 0.192059, 150.427, -1, 5);
				PlaceObjectByHash(2475986526, -1102.26, -2638.02, 25.01, 26.7003, 0.178675, 149.261, -1, 5);
				PlaceObjectByHash(2475986526, -1103.96, -2640.91, 29.04, 28.3717, -0, 146.82, -1, 5);
				PlaceObjectByHash(1952396163, -1119.61, -2670.96, -5.125, 0, -0, 150.514, -1, 5);
				PlaceObjectByHash(1952396163, -1119.61, -2670.96, -5.125, 0, -0, 150.401, -1, 5);
				PlaceObjectByHash(3137065507, -1044.69, -2530.08, 20.4011, 94.8962, 4.26887e-007, 147.716, -1, 5);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1046, -2538, 20, 1, 0, 0, 1);
			}
			Menu::Main::End("Airport Gate Ramp");
			break;
		case UFO_Tower:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 654.365, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 646.186, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 638.008, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 629.829, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 621.65, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 613.471, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 605.292, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 597.114, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 588.935, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 580.756, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 572.577, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 564.399, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 556.22, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 662.544, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 548.041, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 539.862, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 531.683, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 523.505, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 515.326, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 507.147, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 498.968, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 490.79, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 482.611, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 474.432, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 466.253, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 458.074, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 449.896, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 441.717, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 433.538, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 425.359, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 417.18, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 409.001, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 400.823, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 392.644, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 384.465, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 376.286, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 368.107, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 359.929, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 351.75, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 343.571, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 335.392, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 327.213, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 319.035, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 310.856, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 302.677, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 294.498, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 286.319, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 278.141, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 269.962, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 261.783, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 253.604, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 245.425, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 237.247, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 229.068, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 220.889, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 212.71, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 204.531, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 196.353, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 188.174, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 179.995, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 171.816, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 163.637, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 155.459, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 147.28, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 139.101, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 130.922, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 122.743, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 114.565, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 106.386, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 98.207, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 90.0282, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 81.8494, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 73.6706, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 65.4918, 0.660085, -0.919939, -109.32, -1, 6);
				PlaceObjectByHash(3026699584, 70.2592, -674.044, 57.313, 0.660085, -0.919939, -109.32, -1, 6);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 70, -674, 680, 1, 0, 0, 1);
			}
			Menu::Main::End("UFO Tower");
			break;
		case mod_maze_quad:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(3522933110, -81.3886, -814.648, 325.169, 0, -0, 180, -1, 7);
				PlaceObjectByHash(3681122061, -81.7456, -809.064, 324.799, 0.500021, 2.66804, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -86.1333, -802.279, 321.92, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -89.7406, -796.701, 316.539, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -93.601, -790.725, 310.777, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -97.4741, -784.73, 304.997, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -101.373, -778.696, 299.179, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -105.233, -772.72, 293.417, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -109.106, -766.725, 287.637, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -112.954, -760.769, 281.894, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -116.827, -754.773, 276.113, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -120.687, -748.798, 270.352, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -124.518, -742.868, 264.636, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -128.358, -736.925, 258.909, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -132.22, -730.949, 253.151, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -136.081, -724.974, 247.394, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -139.943, -718.998, 241.636, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -143.826, -712.99, 235.846, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -147.667, -707.047, 230.12, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -151.508, -701.104, 224.394, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -155.369, -695.128, 218.636, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -159.252, -689.12, 212.846, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -163.072, -683.209, 207.152, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -166.976, -677.168, 201.331, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -170.838, -671.193, 195.573, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -174.7, -665.217, 189.815, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -178.583, -659.209, 184.026, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -182.444, -653.233, 178.268, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -186.327, -647.225, 172.479, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -190.189, -641.249, 166.721, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -194.03, -635.306, 160.994, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -197.871, -629.363, 155.268, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -201.711, -623.42, 149.542, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -205.552, -617.477, 143.815, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -209.393, -611.534, 138.089, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -213.255, -605.559, 132.331, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -217.095, -599.616, 126.605, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -220.957, -593.64, 120.847, -38.9999, -1.45141, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -222.245, -591.648, 118.928, -33.8999, 1.02453, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -223.349, -589.94, 117.561, -29.31, 1.79292, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -224.58, -588.036, 116.288, -26.25, 5.12264, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -225.869, -586.04, 115.116, -24.7199, -1.10991, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -227.127, -584.095, 114.05, -21.6599, 1.8783, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -228.615, -581.794, 112.961, -19.6199, 1.02453, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -230.201, -579.341, 111.92, -17.0699, -0, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -232.121, -576.369, 110.833, -12.9899, 4.26887, 32.8808, -1, 7);
				PlaceObjectByHash(3681122061, -234.105, -573.302, 109.991, -9.9299, -2.98821, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -236.628, -569.396, 109.329, -7.3799, -4.26887, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -239.81, -564.475, 108.721, -4.3199, 1.28066, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -241.76, -561.459, 108.549, -0.7499, -1.12058, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -244.04, -557.932, 108.494, 2.82011, -2.77476, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -246.372, -554.326, 108.705, 5.8801, -2.77476, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -248.668, -550.777, 109.14, 10.4701, 8.96462, 32.8806, -1, 7);
				PlaceObjectByHash(3681122061, -251.664, -546.138, 110.313, 13.5301, 1.15259, 32.8806, -1, 7);
				PlaceObjectByHash(3681122061, -254.537, -541.694, 111.791, 16.5901, 4.26887, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -256.28, -538.999, 112.748, 19.6501, -1.19528, 32.8807, -1, 7);
				PlaceObjectByHash(3681122061, -65.9078, -814.752, 326.106, 19.89, 4.26887, -53.8105, -1, 7);
				PlaceObjectByHash(3681122061, -58.6541, -809.444, 327.336, -4.08004, -2.13443, -53.8103, -1, 7);
				PlaceObjectByHash(3681122061, -52.4476, -804.909, 323.715, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -47.2332, -801.09, 317.168, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -42.0187, -797.272, 310.621, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -36.8326, -793.474, 304.109, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -31.5898, -789.635, 297.526, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -26.4037, -785.838, 291.014, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -21.1893, -782.019, 284.467, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -15.9748, -778.201, 277.919, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -10.7604, -774.383, 271.372, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -5.57426, -770.585, 264.86, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, -0.359839, -766.767, 258.313, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 4.82623, -762.969, 251.799, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 10.0123, -759.171, 245.285, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 15.2268, -755.353, 238.735, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 20.4412, -751.535, 232.184, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 25.6273, -747.737, 225.67, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 30.8135, -743.939, 219.155, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 36.0279, -740.121, 212.605, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 41.214, -736.323, 206.091, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 46.4285, -732.505, 199.54, -45.3899, 2.56132, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 48.4122, -731.052, 197.049, -41.8198, 1.62217, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 49.5549, -730.218, 195.782, -38.2499, 3.24434, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 51.171, -729.035, 194.203, -36.2098, 2.39057, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 52.8966, -727.773, 192.637, -33.1499, -6.83019, -53.8101, -1, 7);
				PlaceObjectByHash(3681122061, 54.586, -726.537, 191.27, -30.0898, 8.70849, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 56.5413, -725.105, 189.866, -25.4998, 7.59859, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 58.8359, -723.425, 188.509, -22.4398, 4.26887, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 60.738, -722.033, 187.536, -18.3599, 1.10991, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 63.1509, -720.268, 186.544, -15.8098, 5.03727, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 65.131, -718.821, 185.849, -12.7498, 5.07995, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 67.1384, -717.352, 185.286, -9.17981, 4.78113, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 69.2894, -715.776, 184.855, -4.5898, 4.18349, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 71.7831, -713.952, 184.607, 0.000193536, 4.16213, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 74.0832, -712.268, 184.607, 3.06019, 3.7566, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 76.0175, -710.853, 184.736, 8.1602, 4.35424, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 77.7752, -709.567, 185.048, 13.2602, 5.50684, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 79.6997, -708.158, 185.61, 17.3402, 3.7566, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 81.3947, -706.918, 186.266, 21.9302, 4.26887, -53.81, -1, 7);
				PlaceObjectByHash(3681122061, 83.3036, -705.52, 187.219, 26.0102, 9.39151, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 85.6244, -703.821, 188.622, 29.0702, 1.96368, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 87.3526, -702.556, 189.812, 33.1501, 2.90283, -53.8098, -1, 7);
				PlaceObjectByHash(3681122061, 89.2107, -701.196, 191.316, 37.2301, 4.86651, -53.8098, -1, 7);
				PlaceObjectByHash(3681122061, 90.8492, -699.998, 192.859, 41.82, -2.56132, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 92.6236, -698.701, 194.826, 46.41, 8.2816, -53.8099, -1, 7);
				PlaceObjectByHash(3681122061, 94.2096, -697.539, 196.89, 52.0199, 6.57406, -53.8098, -1, 7);
				PlaceObjectByHash(3681122061, 95.6251, -696.503, 199.137, 56.61, 9.22075, -53.8097, -1, 7);
				PlaceObjectByHash(3681122061, 96.9799, -695.512, 201.683, 61.7098, 8.53774, -53.8097, -1, 7);
				PlaceObjectByHash(3681122061, 98.1658, -694.646, 204.413, 65.7899, 5.03726, -53.8096, -1, 7);
				PlaceObjectByHash(3681122061, -69.0186, -829.452, 324.775, 0, -0, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -65.276, -836.288, 321.491, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -62.2554, -842.061, 315, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -59.2515, -847.802, 308.544, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -56.2313, -853.574, 302.053, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -53.1945, -859.378, 295.526, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -50.2071, -865.088, 289.106, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -47.2032, -870.829, 282.65, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -44.1829, -876.602, 276.159, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -41.1626, -882.374, 269.667, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -38.1751, -888.084, 263.247, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -35.1713, -893.825, 256.791, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -32.1674, -899.566, 250.335, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -29.1635, -905.307, 243.879, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -26.1432, -911.079, 237.388, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -23.1393, -916.821, 230.932, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -20.119, -922.593, 224.44, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -17.1152, -928.334, 217.985, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -14.1112, -934.075, 211.529, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -11.1235, -939.785, 205.108, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -8.13589, -945.495, 198.687, -44.8796, 3.24434, -152.398, -1, 7);
				PlaceObjectByHash(3681122061, -5.28891, -951.101, 192.102, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, -2.35757, -956.552, 185.364, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 0.589775, -962.033, 178.59, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 3.5211, -967.483, 171.852, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 9.3998, -978.414, 158.339, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 6.46847, -972.964, 165.077, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 12.3311, -983.865, 151.601, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 15.2944, -989.375, 144.789, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 21.1569, -1000.28, 131.313, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 18.2417, -994.856, 138.014, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 24.0722, -1005.7, 124.612, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 27.0355, -1011.21, 117.801, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 29.9828, -1016.69, 111.026, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 35.8294, -1027.56, 97.5867, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 37.2241, -1030.15, 94.4555, -44.3698, -1.70754, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 38.7475, -1032.99, 91.3086, -39.7798, -4.26887, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 39.7483, -1034.85, 89.5491, -36.7197, 3.4151, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 40.9818, -1037.14, 87.6062, -33.6597, -2.21981, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 42.1248, -1039.27, 85.999, -30.0898, -1.96368, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 32.9141, -1022.14, 104.288, -47.4298, -1.79292, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 43.3132, -1041.47, 84.5449, -26.5197, -1.79293, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 44.7115, -1044.08, 83.0715, -23.4597, -2.39056, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 45.9496, -1046.38, 81.937, -20.3997, -2.47594, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 47.0815, -1048.48, 81.0483, -17.3397, -2.09174, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 48.302, -1050.75, 80.2436, -14.7897, -8.96462, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 50.0647, -1054.03, 79.2608, -13.2597, -2.77476, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 52.0238, -1057.67, 78.2861, -11.7297, -1.45141, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 53.7395, -1060.86, 77.5341, -9.17973, -1.1099, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 55.7265, -1064.56, 76.8558, -6.11973, -6.61674, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 57.3746, -1067.62, 76.4825, -3.56972, -9.60496, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 59.3125, -1071.23, 76.2272, 0.000276446, -9.05818, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 61.112, -1074.58, 76.2272, 4.08028, -8.00412, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 62.529, -1077.21, 76.4405, 7.65027, -7.04364, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 64.0779, -1080.1, 76.8796, 10.7103, -1.28066, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 65.9388, -1083.55, 77.623, 14.2802, -1.70755, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 67.4076, -1086.29, 78.4126, 17.3403, -1.57948, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, 68.7639, -1088.81, 79.3066, 21.4202, 1.36604, -151.734, -1, 7);
				PlaceObjectByHash(3681122061, -86.0915, -825.576, 324.775, 0, -0, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -99.1939, -833.684, 315.911, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -105.248, -837.511, 310.056, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -93.1729, -829.876, 321.734, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -111.268, -841.319, 304.233, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -123.245, -848.891, 292.651, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -147.333, -864.12, 269.359, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -141.278, -860.292, 275.213, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -135.256, -856.485, 281.036, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -129.266, -852.699, 286.828, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -117.224, -845.084, 298.474, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -165.367, -875.521, 251.921, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -213.415, -905.895, 205.464, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -207.426, -902.108, 211.255, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -201.403, -898.301, 217.078, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -195.414, -894.515, 222.87, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -183.434, -886.942, 234.452, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -177.445, -883.156, 240.244, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -171.422, -879.348, 246.067, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -159.378, -871.734, 257.713, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -153.355, -867.927, 263.536, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -189.424, -890.728, 228.661, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -231.449, -917.296, 188.027, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -225.46, -913.509, 193.818, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -219.47, -909.723, 199.609, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -237.439, -921.082, 182.235, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -284.806, -951.016, 167.673, 28.5601, -7.5132, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -289.048, -953.697, 170.578, 34.1701, -3.41509, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -290.727, -954.757, 171.926, 37.23, 3.41509, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -286.998, -952.399, 169.084, 31.62, -1.36604, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -282.375, -949.481, 166.27, 26.0101, 3.50047, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -280.014, -947.991, 165.174, 21.4201, -6.83019, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -277.4, -946.336, 164.178, 17.8501, -3.15896, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -270.266, -941.827, 162.896, 4.59013, -1.79292, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -266.683, -939.562, 163.103, -6.11989, -1.38738, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -259.328, -934.913, 165.339, -17.8499, -4.69576, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -253.478, -931.22, 168.474, -26.01, -4.18349, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -248.103, -927.823, 172.247, -33.66, -5.97642, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -243.429, -924.868, 176.444, -39.27, -2.30519, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -256.593, -933.187, 166.676, -22.4399, -5.97641, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -262.183, -936.72, 164.252, -14.2799, -3.20165, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -268.321, -940.597, 162.896, 0.000125527, -1.95033, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -272.668, -943.344, 163.123, 8.67012, -2.86014, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -275.091, -944.877, 163.561, 12.7501, -5.1226, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -249.757, -928.867, 170.944, -31.11, -6.0617, 122.286, -1, 7);
				PlaceObjectByHash(3681122061, -251.566, -930.012, 169.653, -27.54, -3.58585, 122.286, -1, 7);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}
			Menu::Main::End("Maze Bank Quad Ramp");
			break;
		case zancudo_moto:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(3213433054, -2661.22, 3209.43, 32.7118, 0, -0, -120.437, -1, 8);
				PlaceObjectByHash(3213433054, -2657.86, 3207.56, 32.7118, 0, 0, 59.6808, -1, 8);
				PlaceObjectByHash(3213433054, -2659.52, 3212.33, 32.7118, 0, -0, -120.437, -1, 8);
				PlaceObjectByHash(3213433054, -2656.2, 3210.41, 32.7118, 0, 0, 59.6808, -1, 8);
				PlaceObjectByHash(3213433054, -2654.54, 3213.26, 32.7118, 0, 0, 59.6808, -1, 8);
				PlaceObjectByHash(3213433054, -2657.84, 3215.18, 32.7118, 0, -0, -120.437, -1, 8);
				PlaceObjectByHash(3213433054, -2615.14, 3183, 32.8118, 0, -0, -120.45, -1, 8);
				PlaceObjectByHash(3213433054, -2611.82, 3181.02, 32.8118, 0, 0, 58.529, -1, 8);
				PlaceObjectByHash(3213433054, -2613.47, 3185.85, 32.8118, 0, -0, -120.45, -1, 8);
				PlaceObjectByHash(3213433054, -2610.11, 3183.91, 32.8118, 0, 0, 59.589, -1, 8);
				PlaceObjectByHash(3213433054, -2611.79, 3188.7, 32.8118, 0, -0, -120.45, -1, 8);
				PlaceObjectByHash(3213433054, -2608.46, 3186.71, 32.8118, 0, 0, 58.529, -1, 8);
				PlaceObjectByHash(3213433054, -2550.83, 3162.65, 32.7702, 0, -0, -117.989, -1, 8);
				PlaceObjectByHash(4109455646, -2547.01, 3160.66, 34.9496, 11.66, -2.56132e-006, -118.95, -1, 8);
				PlaceObjectByHash(3213433054, -2476.76, 3120.72, 32.7718, 0, -0, -119.612, -1, 8);
				PlaceObjectByHash(4109455646, -2473.51, 3118.83, 34.5672, 8.47412, -0.0223369, -120.965, -1, 8);
				PlaceObjectByHash(2975320548, -2442.43, 3105.7, 35.6224, -7.42001, -5.12265e-006, 150.074, -1, 8);
				PlaceObjectByHash(2975320548, -2443.67, 3101.83, 35.8732, -11.66, 3.84198e-006, 59.738, -1, 8);
				PlaceObjectByHash(2975320548, -2438.8, 3099, 36.0155, -11.66, -6.40331e-006, 59.7379, -1, 8);
				PlaceObjectByHash(2975320548, -2434.05, 3096.22, 36.6871, -22.26, -1.45141e-005, 59.7379, -1, 8);
				PlaceObjectByHash(2975320548, -2446.85, 3098.2, 35.6088, -7.42, 3.20165e-006, -31.8463, -1, 8);
				PlaceObjectByHash(2402097066, -2448.77, 3097.65, 35.4732, 0, -0, -120.616, -1, 8);
				PlaceObjectByHash(2402097066, -2442.95, 3108.08, 35.4832, 0, -0, -117.436, -1, 8);
				PlaceObjectByHash(2402097066, -2442.95, 3108.08, 35.4832, 0, -0, -117.436, -1, 8);
				PlaceObjectByHash(3681122061, -2389.55, 3069.11, 36.5952, 179.801, -3.76861e-006, -117.806, -1, 8);
				PlaceObjectByHash(1982829832, -2363.33, 3056.01, 31.8257, 0, -0, -119.219, -1, 8);
				PlaceObjectByHash(3681122061, -2389.55, 3069.11, 36.5952, 179.801, -3.76861e-006, -117.806, -1, 8);
				PlaceObjectByHash(2609922146, -2358.79, 3060.59, 31.8217, 0, -0, -119.371, -1, 8);
				PlaceObjectByHash(2975320548, -2325.93, 3034.99, 33.3214, 19.8, 3.41509e-006, -120.09, -1, 8);
				PlaceObjectByHash(2975320548, -2321.78, 3032.58, 36.3899, 25.7399, -8.62311e-005, -120.09, -1, 8);
				PlaceObjectByHash(2975320548, -2317.79, 3030.29, 39.6222, 25.0799, -6.23256e-005, -120.09, -1, 8);
				PlaceObjectByHash(2975320548, -2313.74, 3027.94, 42.9228, 25.7399, -8.62311e-005, -120.09, -1, 8);
				PlaceObjectByHash(2975320548, -2309.83, 3025.69, 46.2289, 27.06, -8.2816e-005, -120.09, -1, 8);
				PlaceObjectByHash(2975320548, -2306.07, 3023.49, 49.5919, 29.0399, -0.000116113, -120.09, -1, 8);
				PlaceObjectByHash(2975320548, -2283.14, 3009.97, 44.7284, 14.12, -2.04906e-005, 60.0397, -1, 8);
				PlaceObjectByHash(2975320548, -2287.5, 3012.47, 46.9591, 13.6, 0.680011, 60.0397, -1, 8);
				PlaceObjectByHash(2975320548, -2302.26, 3021.28, 53.174, 29.6999, -0.000100745, -120.09, -1, 8);
				PlaceObjectByHash(2975320548, -2292.06, 3015.11, 49.2546, 13.6, 1.53679e-005, 60.0397, -1, 8);
				PlaceObjectByHash(2975320548, -2298.56, 3019.12, 56.7472, 30.36, -8.79386e-005, -120.09, -1, 8);
				PlaceObjectByHash(2052512905, -2294.52, 3015.08, 58.6366, 82.6616, 0.00430302, -31.2919, -1, 8);
				PlaceObjectByHash(2052512905, -2293.13, 3017.4, 58.6822, 80.9428, 0.00560716, 149.187, -1, 8);
				PlaceObjectByHash(2787492567, -2293.66, 3016.58, 31.8318, -90, 0.0833042, 109.919, -1, 8);
				PlaceObjectByHash(3213433054, -2202.78, 2963.39, 32.8003, 0, -0, -120.04, -1, 8);
				PlaceObjectByHash(3213433054, -2199.53, 2961.53, 34.17, -40.5599, -2.56132e-006, 59.8803, -1, 8);
				PlaceObjectByHash(3681122061, -2137.1, 2904.97, 32.8327, 16.8, -1.10991e-005, -141.061, -1, 8);
				PlaceObjectByHash(3681122061, -2132.27, 2897.94, 34.4465, 16.8, -14, -141.061, -1, 8);
				PlaceObjectByHash(3681122061, -2127.12, 2890.88, 36.4432, 17.92, -29.68, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2119.98, 2885.33, 38.8379, 17.92, -29.68, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2113.02, 2880, 41.2705, 17.92, -29.68, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2085.18, 2857.71, 49.9177, 19.04, -43.12, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2078.1, 2852.44, 51.662, 19.0399, -50.4001, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2092.05, 2863.54, 48.2285, 17.92, -34.16, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2098.91, 2869.18, 46.2053, 17.92, -29.68, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2105.97, 2874.59, 43.7379, 17.92, -29.68, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2070.42, 2847.69, 53.5814, 19.0399, -50.4001, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2062.85, 2843.01, 55.4739, 19.0399, -50.4001, -136.581, -1, 8);
				PlaceObjectByHash(3681122061, -2055.32, 2838.69, 56.5097, 17.7868, -43.8868, -131.905, -1, 8);
				PlaceObjectByHash(3681122061, -2047.61, 2834.88, 58.9097, 26.1867, -43.8868, -131.905, -1, 8);
				PlaceObjectByHash(3681122061, -2039.74, 2832.2, 62.2769, 38.5067, -45.5668, -131.905, -1, 8);
				PlaceObjectByHash(3681122061, -1996.98, 2830.2, 48.384, 0.202822, -14.4337, -105.503, -1, 8);
				PlaceObjectByHash(3681122061, -1996.42, 2832.89, 59.0601, -179.433, 12.3451, 76.9258, -1, 8);
				PlaceObjectByHash(3213433054, -1951.86, 2849.63, 34.5146, -47.5199, -7.59859e-005, 59.6261, -1, 8);
				PlaceObjectByHash(3213433054, -1950.16, 2852.52, 34.5146, -47.5199, -7.59859e-005, 59.6261, -1, 8);
				PlaceObjectByHash(3213433054, -1953.57, 2854.49, 32.8004, 0, -0, -120.091, -1, 8);
				PlaceObjectByHash(3213433054, -1955.25, 2851.59, 32.8004, 0, -0, -120.091, -1, 8);
				PlaceObjectByHash(4111834409, -1960.72, 2857.38, 31.7305, 0, -0, -118.505, -1, 8);
				PlaceObjectByHash(4109455646, -2144, 2967.21, 36.0606, 9.35852, -0.00134085, 59.8371, -1, 8);
				PlaceObjectByHash(4109455646, -2139.63, 2964.67, 33.9985, 5.84852, -0.0013321, 59.8371, -1, 8);
				PlaceObjectByHash(4109455646, -2135.45, 2962.3, 32.4604, 0, 0, 60.4792, -1, 8);
				PlaceObjectByHash(2975320548, -2193.23, 2995.21, 35.0684, 11.6996, -0.00262322, -119.238, -1, 8);
				PlaceObjectByHash(2975320548, -2197.74, 2997.74, 32.8074, 15.2099, 2.04906e-005, -119.328, -1, 8);
				PlaceObjectByHash(3213433054, -2246.82, 3026.19, 33.0318, 0.0331696, 0.0056356, 58.6423, -1, 8);
				PlaceObjectByHash(3213433054, -2256.38, 3032.02, 35.4343, 6.5707, 0.0279573, 58.7685, -1, 8);
				PlaceObjectByHash(3213433054, -2265.19, 3037.37, 38.408, 10.1262, 0.0254109, 58.7585, -1, 8);
				PlaceObjectByHash(3213433054, -2273.45, 3042.38, 40.214, 8.95404, -0.00182451, 58.7729, -1, 8);
				PlaceObjectByHash(3213433054, -2281.36, 3047.19, 42.7382, 8.89319, 0.151422, 58.8279, -1, 8);
				PlaceObjectByHash(3213433054, -2289.41, 3052.05, 46.2871, 13.2, 0.000150264, 58.7642, -1, 8);
				PlaceObjectByHash(3213433054, -2397.86, 3114.2, 32.8449, 0, 0, 60.2049, -1, 8);
				PlaceObjectByHash(3213433054, -2402.38, 3116.77, 34.7648, 0, 0, 60.2049, -1, 8);
				PlaceObjectByHash(2475986526, -2394.65, 3118.07, 32.5452, 0, 0, 56.6241, -1, 8);
				PlaceObjectByHash(2475986526, -2397.73, 3120.09, 34.1452, 2.04, -1.38738e-006, 56.6241, -1, 8);
				PlaceObjectByHash(2475986526, -2401.78, 3122.77, 36.6227, 8.16, 1.28066e-006, 56.6239, -1, 8);
				PlaceObjectByHash(2475986526, -2405.48, 3125.2, 39.5571, 14.28, 1.02453e-005, 56.6239, -1, 8);
				PlaceObjectByHash(2475986526, -2409.12, 3127.6, 43.2064, 20.4, -2.39057e-005, 56.6239, -1, 8);
				PlaceObjectByHash(2475986526, -2412.29, 3129.71, 46.9494, 24.4781, -1.43125, 56.2632, -1, 8);
				PlaceObjectByHash(2475986526, -2415.18, 3131.49, 51.529, 38.3931, -3.70399, 55.299, -1, 8);
				PlaceObjectByHash(2475986526, -2416.96, 3132.28, 56.2986, 54.0331, -3.70398, 53.2589, -1, 8);
				PlaceObjectByHash(2475986526, -2417.37, 3132.16, 61.6124, 73.753, -3.70394, 53.2588, -1, 8);
				PlaceObjectByHash(2475986526, -2416.48, 3131.04, 66.996, 90.9129, -3.70395, 53.2587, -1, 8);
				PlaceObjectByHash(2475986526, -2414.88, 3129.5, 70.998, 104.113, -3.70383, 50.6186, -1, 8);
				PlaceObjectByHash(2475986526, -2412.46, 3127.2, 74.61, 116.653, -3.70392, 50.6185, -1, 8);
				PlaceObjectByHash(2475986526, -2409.58, 3124.71, 77.6119, 121.273, -3.70395, 50.6185, -1, 8);
				PlaceObjectByHash(2475986526, -2406.75, 3122.18, 80.0586, 127.213, -3.70391, 50.6184, -1, 8);
				PlaceObjectByHash(2475986526, -2403.38, 3119.23, 82.2502, 135.793, -3.70396, 50.6185, -1, 8);
				PlaceObjectByHash(2475986526, -2369.71, 3092.81, 68.2807, -146.327, -3.7039, 50.6183, -1, 8);
				PlaceObjectByHash(2475986526, -2367.45, 3091.4, 63.3347, -134.447, -3.70392, 50.6182, -1, 8);
				PlaceObjectByHash(2475986526, -2366, 3090.66, 58.0814, -123.887, -3.7039, 50.6182, -1, 8);
				PlaceObjectByHash(2475986526, -2365.38, 3090.57, 53.1623, -112.007, -3.70391, 50.6182, -1, 8);
				PlaceObjectByHash(2475986526, -2365.62, 3091.18, 48.0172, -99.4666, -3.70393, 50.6181, -1, 8);
				PlaceObjectByHash(2475986526, -2366.77, 3092.54, 43.04, -86.2661, -3.70399, 50.6181, -1, 8);
				PlaceObjectByHash(2475986526, -2368.73, 3094.52, 38.5669, -74.386, -3.70392, 50.6181, -1, 8);
				PlaceObjectByHash(2475986526, -2371.25, 3096.8, 35.0692, -59.206, -3.70384, 55.2379, -1, 8);
				PlaceObjectByHash(2475986526, -2375.18, 3099.61, 32.3997, -42.0459, -3.70387, 57.2179, -1, 8);
				PlaceObjectByHash(2475986526, -2395.69, 3112.77, 84.6355, 152.292, -3.70389, 50.6184, -1, 8);
				PlaceObjectByHash(2475986526, -2391.54, 3109.37, 84.6603, 162.192, -3.70393, 50.6184, -1, 8);
				PlaceObjectByHash(2475986526, -2387.13, 3105.84, 83.6595, 172.752, -3.70391, 50.6184, -1, 8);
				PlaceObjectByHash(2475986526, -2382.97, 3102.56, 81.8101, -179.988, -3.70391, 50.6184, -1, 8);
				PlaceObjectByHash(2475986526, -2372.52, 3094.76, 72.6855, -154.907, -3.70391, 50.6183, -1, 8);
				PlaceObjectByHash(2475986526, -2379.11, 3099.59, 79.371, -172.728, -3.70391, 50.6183, -1, 8);
				PlaceObjectByHash(2475986526, -2375.46, 3096.85, 76.1692, -162.168, -3.70388, 50.6182, -1, 8);
				PlaceObjectByHash(2475986526, -2399.8, 3116.19, 83.7512, 143.712, -3.70387, 50.6184, -1, 8);
				PlaceObjectByHash(3213433054, -2510.73, 3180.4, 32.8111, 0, 0, 59.4291, -1, 8);
				PlaceObjectByHash(209943352, -2302.92, 3059.95, 50.2208, 76.8397, -0.679965, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2298.84, 3057.5, 48.7042, 71.3997, -0.679954, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2290.6, 3052.58, 47.3498, 84.3198, -0.679946, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2290.6, 3052.58, 47.3498, 84.3198, -0.679946, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2294.73, 3055.05, 47.6692, 76.8398, -0.680059, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2533.2, 3193.91, 37.3948, 0, -0, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2533.2, 3193.91, 37.3948, 0, -0, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2425.58, 3091.36, 36.493, 0, -0, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2425.58, 3091.36, 36.493, 0, -0, -120.716, -1, 8);
				PlaceObjectByHash(209943352, -2293.7, 3012.65, 55.3685, -89.7587, -0.659716, -30.2946, -1, 8);
				PlaceObjectByHash(209943352, -2293.7, 3012.65, 55.3685, -89.7587, -0.659716, -30.2946, -1, 8);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -2731, 3259, 32, 1, 0, 0, 1);
			}
			Menu::Main::End("Fort Zancudo Motorcross");
			break;
		case halfpipe:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(3681122061, -1018.78, -2937.26, 12.9646, 0, 0, -30.3132, -1, 9);
				PlaceObjectByHash(3681122061, -1023.38, -2945.17, 12.9646, 0, 0, -30.3132, -1, 9);
				PlaceObjectByHash(3681122061, -1028.02, -2953.13, 12.9646, 0, 0, -30.3132, -1, 9);
				PlaceObjectByHash(3681122061, -1032.66, -2961.06, 12.9646, 0, 0, -30.3132, -1, 9);
				PlaceObjectByHash(3681122061, -1037.32, -2969.04, 12.9646, 0, 0, -30.3132, -1, 9);
				PlaceObjectByHash(3681122061, -1041.95, -2976.96, 12.9646, 0, 0, -30.3132, -1, 9);
				PlaceObjectByHash(3681122061, -1046.18, -2984.19, 12.9646, 0, 0, -30.3132, -1, 9);
				PlaceObjectByHash(3681122061, -1050.78, -2992.12, 12.9646, 0, 0, -29.8732, -1, 9);
				PlaceObjectByHash(3681122061, -1053.22, -2998.13, 12.9646, 0, 0, -14.2534, -1, 9);
				PlaceObjectByHash(3681122061, -1054.14, -3005.28, 12.9646, 0, 0, -0.613478, -1, 9);
				PlaceObjectByHash(3681122061, -1053.45, -3012.85, 12.9646, 0, 0, 11.4866, -1, 9);
				PlaceObjectByHash(3681122061, -1051.19, -3020.08, 12.9646, 0, 0, 23.3667, -1, 9);
				PlaceObjectByHash(3681122061, -1047.43, -3026.73, 12.9646, 0, 0, 35.2469, -1, 9);
				PlaceObjectByHash(3681122061, -1042.42, -3032.37, 12.9646, 0, 0, 47.7871, -1, 9);
				PlaceObjectByHash(3681122061, -1037.1, -3038.16, 12.9646, 0, 0, 37.2273, -1, 9);
				PlaceObjectByHash(3681122061, -1033.11, -3044.75, 12.9646, 0, 0, 25.5675, -1, 9);
				PlaceObjectByHash(3681122061, -1030.43, -3052.11, 12.9646, 0, 0, 14.5676, -1, 9);
				PlaceObjectByHash(3681122061, -1029.18, -3059.85, 12.9646, 0, 0, 4.00757, -1, 9);
				PlaceObjectByHash(3681122061, -1029.37, -3067.7, 12.9646, 0, 0, -6.55247, -1, 9);
				PlaceObjectByHash(3681122061, -1031, -3075.33, 12.9646, 0, 0, -17.5525, -1, 9);
				PlaceObjectByHash(3681122061, -1034.09, -3082.35, 12.9646, 0, 0, -29.6525, -1, 9);
				PlaceObjectByHash(3681122061, -1038.6, -3088.77, 12.9646, 0, 0, -40.2127, -1, 9);
				PlaceObjectByHash(3681122061, -1044.19, -3094.15, 12.9646, 0, 0, -51.653, -1, 9);
				PlaceObjectByHash(3681122061, -1050.65, -3098.2, 12.9646, 0, 0, -63.7531, -1, 9);
				PlaceObjectByHash(3681122061, -1057.89, -3100.91, 12.9646, 0, 0, -75.1935, -1, 9);
				PlaceObjectByHash(3681122061, -1065.18, -3101.87, 12.9646, 0, 0, -89.7139, -1, 9);
				PlaceObjectByHash(3681122061, -1073.03, -3101.2, 12.9646, 0, -0, -100.054, -1, 9);
				PlaceObjectByHash(3681122061, -1080.63, -3099.11, 12.9646, 0, -0, -110.615, -1, 9);
				PlaceObjectByHash(3681122061, -1087.92, -3095.65, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1095.95, -3091.03, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1104.01, -3086.4, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1112.04, -3081.79, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1120.04, -3077.19, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1128.1, -3072.56, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1136.15, -3067.93, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1144.2, -3063.31, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1152.22, -3058.7, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1160.24, -3054.09, 12.9646, 0, -0, -119.855, -1, 9);
				PlaceObjectByHash(3681122061, -1168.22, -3049.48, 12.9646, 0, -0, -120.295, -1, 9);
				PlaceObjectByHash(3681122061, -1176.21, -3044.8, 12.9646, 0, -0, -120.295, -1, 9);
				PlaceObjectByHash(3681122061, -1183.28, -3040.14, 12.9646, 0, -0, -126.455, -1, 9);
				PlaceObjectByHash(3681122061, -1189.23, -3034.89, 12.9646, 0, -0, -136.356, -1, 9);
				PlaceObjectByHash(3681122061, -1193.86, -3028.84, 12.9646, 0, -0, -148.677, -1, 9);
				PlaceObjectByHash(3681122061, -1197.2, -3021.86, 12.9646, 0, -0, -159.898, -1, 9);
				PlaceObjectByHash(3681122061, -1198.78, -3014.77, 12.9646, 0, -0, -174.639, -1, 9);
				PlaceObjectByHash(3681122061, -1198.72, -3007.04, 12.9646, 0, -0, 173.701, -1, 9);
				PlaceObjectByHash(3681122061, -1197, -2999.97, 12.9646, 0, -0, 158.962, -1, 9);
				PlaceObjectByHash(3681122061, -1193.5, -2993.3, 12.9646, 0, -0, 145.982, -1, 9);
				PlaceObjectByHash(3681122061, -1188.51, -2987.1, 12.9646, 0, -0, 136.083, -1, 9);
				PlaceObjectByHash(3681122061, -1182.5, -2981.85, 12.9646, 0, -0, 126.183, -1, 9);
				PlaceObjectByHash(3681122061, -1175.98, -2978.23, 12.9646, 0, -0, 112.104, -1, 9);
				PlaceObjectByHash(3681122061, -1168.67, -2976.15, 12.9646, 0, -0, 99.7843, -1, 9);
				PlaceObjectByHash(3681122061, -1160.82, -2975.53, 12.9646, 0, 0, 89.4449, -1, 9);
				PlaceObjectByHash(3681122061, -1152.93, -2976.29, 12.9646, 0, 0, 79.5455, -1, 9);
				PlaceObjectByHash(3681122061, -1145.21, -2978.39, 12.9646, 0, 0, 70.0859, -1, 9);
				PlaceObjectByHash(3681122061, -1138.14, -2981.75, 12.9646, 0, 0, 59.0863, -1, 9);
				PlaceObjectByHash(3681122061, -1130.27, -2986.43, 12.9646, 0, 0, 59.0863, -1, 9);
				PlaceObjectByHash(3681122061, -1122.46, -2991.09, 12.9646, 0, 0, 59.0863, -1, 9);
				PlaceObjectByHash(3681122061, -1115.12, -2994.75, 12.9646, 0, 0, 67.1435, -1, 9);
				PlaceObjectByHash(3681122061, -1107.63, -2997.13, 12.9646, 0, 0, 76.9913, -1, 9);
				PlaceObjectByHash(3681122061, -1099.8, -2998.14, 12.9646, 0, 0, 86.8389, -1, 9);
				PlaceObjectByHash(3681122061, -1091.94, -2997.76, 12.9646, 0, -0, 97.5819, -1, 9);
				PlaceObjectByHash(3681122061, -1084.47, -2995.95, 12.9646, 0, -0, 108.325, -1, 9);
				PlaceObjectByHash(3681122061, -1077.64, -2992.78, 12.9646, 0, -0, 119.963, -1, 9);
				PlaceObjectByHash(3681122061, -1077.64, -2992.78, 12.9646, 0, -0, 119.963, -1, 9);
				PlaceObjectByHash(3681122061, -1071.68, -2988.3, 12.9646, 0, -0, 132.496, -1, 9);
				PlaceObjectByHash(3681122061, -1066.33, -2982.53, 12.9646, 0, -0, 141.449, -1, 9);
				PlaceObjectByHash(3681122061, -1053.01, -2960.01, 12.9646, 0, 0, -28.5532, -1, 9);
				PlaceObjectByHash(3681122061, -1048.58, -2951.88, 12.9646, 0, 0, -28.5532, -1, 9);
				PlaceObjectByHash(3681122061, -1044.16, -2943.76, 12.9646, 0, 0, -28.5532, -1, 9);
				PlaceObjectByHash(3681122061, -1039.74, -2935.64, 12.9646, 0, 0, -28.5532, -1, 9);
				PlaceObjectByHash(3681122061, -1035.5, -2927.86, 12.9646, 0, 0, -28.5532, -1, 9);
				PlaceObjectByHash(3608473212, -1063.23, -2993.67, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1067.37, -2998.06, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1063.7, -2994.67, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1064.21, -2995.73, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1064.71, -2996.8, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1065.21, -2997.84, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1067.1, -2999.45, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1065.43, -3000.24, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1068.29, -3000.06, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1065.92, -3001.18, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1066.44, -3002.28, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1065.35, -3002.77, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1065.6, -3003.96, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1066.11, -3005.04, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1064.21, -2999.56, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1069.53, -3000.82, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1070.75, -3001.52, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1068.76, -3002.46, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1069.29, -3003.54, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1068.44, -3005.23, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1071.58, -3003.74, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(2475986526, -1072.98, -3006.81, 16.0846, 0, 0, -26.0348, -1, 9);
				PlaceObjectByHash(3608473212, -1072.44, -3002.05, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(3608473212, -1073.73, -3002.72, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(2475986526, -1076.54, -3005.07, 16.0846, 0, 0, -26.0348, -1, 9);
				PlaceObjectByHash(2475986526, -1078.92, -3009.92, 13.7046, 0, 0, -26.0348, -1, 9);
				PlaceObjectByHash(2475986526, -1075.31, -3011.69, 13.7046, 0, 0, -26.0348, -1, 9);
				PlaceObjectByHash(2475986526, -1069.34, -3008.59, 16.0846, 0, 0, -26.0348, -1, 9);
				PlaceObjectByHash(2475986526, -1071.71, -3013.45, 13.7046, 0, 0, -26.0348, -1, 9);
				PlaceObjectByHash(2475986526, -1068.14, -3015.2, 13.7046, 0, 0, -26.0348, -1, 9);
				PlaceObjectByHash(3608473212, -1065.36, -3006.66, 15.3449, 0, 0, -25.1145, -1, 9);
				PlaceObjectByHash(2475986526, -1065.75, -3010.35, 16.0846, 0, 0, -26.0348, -1, 9);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1003, -2916, 14, 1, 0, 0, 1);
			}
			Menu::Main::End("Halfpipe Fun Track");
			break;
		case air_loop:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(3966705493, -1041.89, -3219.51, 10.1797, -2.43331, 5.32208, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1037.79, -3221.47, 10.3641, -2.43331, 5.32208, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1034.16, -3223.3, 10.5366, -2.43331, 5.32208, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1036.76, -3219.45, 10.1526, -2.43331, 5.32208, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1033.12, -3221.28, 10.3251, -2.43331, 5.32208, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1029.37, -3225.6, 11.1956, -11.6033, 5.32207, 62.9335, -1, 10);
				PlaceObjectByHash(3966705493, -1028.33, -3223.58, 10.9842, -11.6033, 5.32207, 62.9335, -1, 10);
				PlaceObjectByHash(3966705493, -1024.27, -3225.54, 12.1104, -18.1533, 5.32205, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1025.44, -3227.83, 12.3497, -18.1533, 5.32205, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1020.36, -3230.06, 15.7972, -40.4234, 5.32214, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1019.22, -3227.83, 15.5634, -40.4234, 5.32214, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1014.85, -3229.56, 20.4393, -50.9034, 5.3221, 62.9337, -1, 10);
				PlaceObjectByHash(3966705493, -1016.07, -3231.95, 20.6898, -50.9034, 5.3221, 62.9337, -1, 10);
				PlaceObjectByHash(3966705493, -1012.88, -3232.96, 26.0664, -64.0034, 5.32209, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1011.63, -3230.51, 25.8104, -64.0034, 5.32209, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1009.27, -3231.06, 32.0819, -73.1735, 5.32204, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1010.52, -3233.51, 32.3379, -73.1735, 5.32214, 62.9337, -1, 10);
				PlaceObjectByHash(3966705493, -1009.36, -3233.48, 38.2311, -83.6535, 5.32208, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1008.09, -3230.98, 37.9695, -83.6535, 5.32208, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1007.71, -3230.43, 44.185, -92.8235, 6.63212, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1009.05, -3228.93, 49.9682, -119.024, 6.63217, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1008.93, -3232.81, 44.4969, -92.8235, 6.63212, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1010.27, -3231.31, 50.2801, -119.024, 6.63217, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1011.96, -3226.91, 54.0691, -142.604, 6.6321, 62.9337, -1, 10);
				PlaceObjectByHash(3966705493, -1013.1, -3229.14, 54.3602, -142.604, 6.6321, 62.9337, -1, 10);
				PlaceObjectByHash(3966705493, -1017.49, -3226.51, 57.2125, -159.634, 6.63211, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1022.14, -3223.91, 58.9186, -168.804, 6.63213, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1035.97, -3216.05, 58.7162, 155.826, 1.39214, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1031.37, -3218.71, 60.1775, 176.786, 6.63213, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1026.33, -3221.63, 59.8766, -168.804, 6.63212, 60.3136, -1, 10);
				PlaceObjectByHash(3966705493, -1020.98, -3221.63, 58.6206, -168.804, 6.63213, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1024.97, -3219.25, 59.5578, -168.804, 6.63212, 60.3136, -1, 10);
				PlaceObjectByHash(3966705493, -1016.33, -3224.24, 56.9145, -159.634, 6.63211, 62.9336, -1, 10);
				PlaceObjectByHash(3966705493, -1029.99, -3216.28, 59.8517, 176.786, 6.63213, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1029.99, -3216.28, 59.8517, 176.786, 6.63213, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1034.73, -3213.86, 58.655, 155.826, 1.39214, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1039.18, -3211.42, 55.2255, 138.796, 1.39206, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1039.18, -3211.42, 55.2255, 138.796, 1.39206, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1040.42, -3213.61, 55.2867, 138.796, 1.39206, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1044.34, -3211.51, 50.6082, 128.316, 1.39213, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1043.09, -3209.33, 50.547, 128.316, 1.39213, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1046.16, -3207.74, 45.1535, 117.837, 1.39215, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1048.17, -3206.74, 39.6252, 104.737, 1.39214, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1048.92, -3206.44, 33.1586, 87.6005, 0.0914728, 60.6227, -1, 10);
				PlaceObjectByHash(3966705493, -1048.18, -3206.88, 26.5446, 77.3408, 0.0913896, 60.6229, -1, 10);
				PlaceObjectByHash(3966705493, -1049.44, -3209.13, 26.5487, 77.3407, 0.0913427, 60.6228, -1, 10);
				PlaceObjectByHash(3966705493, -1047.3, -3210.37, 21.3947, 56.6411, 0.0914017, 58.823, -1, 10);
				PlaceObjectByHash(3966705493, -1047.3, -3210.37, 21.3947, 56.6411, 0.0914017, 58.823, -1, 10);
				PlaceObjectByHash(3966705493, -1045.93, -3208.12, 21.3905, 56.6411, 0.0914017, 58.823, -1, 10);
				PlaceObjectByHash(3966705493, -1042.61, -3210.12, 16.8766, 42.1517, 0.0913785, 58.8231, -1, 10);
				PlaceObjectByHash(3966705493, -1038.64, -3212.63, 13.6141, 28.2018, 0.0914187, 58.8231, -1, 10);
				PlaceObjectByHash(3966705493, -1039.97, -3214.83, 13.6182, 28.2018, 0.0914187, 58.8231, -1, 10);
				PlaceObjectByHash(3966705493, -1034.82, -3217.71, 11.1985, 16.4116, 0.0913871, 69.303, -1, 10);
				PlaceObjectByHash(3966705493, -1033.53, -3215.55, 11.1081, 16.4117, 0.0913619, 66.683, -1, 10);
				PlaceObjectByHash(3966705493, -1043.97, -3212.37, 16.8808, 42.1517, 0.0913785, 58.8231, -1, 10);
				PlaceObjectByHash(3966705493, -1050.19, -3208.69, 33.1627, 87.6005, 0.0914728, 60.6227, -1, 10);
				PlaceObjectByHash(3966705493, -1049.45, -3208.98, 39.6879, 104.737, 1.39214, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1047.44, -3209.98, 45.2161, 117.837, 1.39215, 60.3137, -1, 10);
				PlaceObjectByHash(3966705493, -1047.44, -3209.98, 45.2161, 117.837, 1.39215, 60.3137, -1, 10);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -1074, -3201, 13, 1, 0, 0, 1);
			}
			Menu::Main::End("Airport Loop");
			break;
		case mod_maze_ramp2:

			if (Menu::Main::Option("Load")) {
				PlaceObjectByHash(3681122061, -82.9657, -818.944, 325.175, 0, -0, 91.03, -1, 11);
				PlaceObjectByHash(3681122061, -91.0941, -819.089, 322.355, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -98.36, -819.224, 316.632, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -105.626, -819.358, 310.91, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -112.892, -819.492, 305.187, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -120.158, -819.626, 299.464, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -127.424, -819.761, 293.741, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -134.69, -819.895, 288.018, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -141.956, -820.029, 282.296, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -149.222, -820.163, 276.573, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -156.487, -820.298, 270.85, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -163.753, -820.432, 265.127, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -171.019, -820.566, 259.404, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -178.285, -820.701, 253.682, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -185.551, -820.835, 247.959, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -192.817, -820.969, 242.236, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -200.083, -821.103, 236.513, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -207.349, -821.238, 230.79, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -214.615, -821.372, 225.068, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -221.881, -821.506, 219.345, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -229.147, -821.641, 213.622, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -236.413, -821.775, 207.899, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -243.679, -821.909, 202.176, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -250.945, -822.043, 196.453, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -258.21, -822.178, 190.731, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -265.476, -822.312, 185.008, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -287.274, -822.715, 167.839, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -280.008, -822.58, 173.562, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -272.742, -822.446, 179.285, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -294.54, -822.849, 162.117, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -301.806, -822.983, 156.394, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -309.072, -823.118, 150.671, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -316.338, -823.252, 144.948, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -323.604, -823.386, 139.225, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -330.87, -823.52, 133.503, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -338.136, -823.655, 127.78, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -345.402, -823.789, 122.057, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -352.668, -823.923, 116.334, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -359.934, -824.057, 110.611, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -367.199, -824.192, 104.889, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -374.465, -824.326, 99.1657, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -381.731, -824.46, 93.4429, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -388.997, -824.595, 87.7201, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -396.263, -824.729, 81.9973, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -403.529, -824.863, 76.2745, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -411.479, -825.022, 68.7971, -19.78, -3.43377e-005, 91.1094, -1, 11);
				PlaceObjectByHash(3681122061, -410.795, -824.997, 70.5517, -38.2199, 0.00787841, 91.0529, -1, 11);
				PlaceObjectByHash(3681122061, -411.96, -825.029, 69.097, -27.6, 1.15259e-005, 91.1095, -1, 11);
				PlaceObjectByHash(3681122061, -412.719, -825.046, 67.8516, -10.58, -2.92151e-006, 91.1095, -1, 11);
				PlaceObjectByHash(3681122061, -413.903, -825.068, 67.2075, -3.21999, 5.66959e-007, 91.1095, -1, 11);
				PlaceObjectByHash(3681122061, -415.378, -825.099, 66.7734, 3.68002, -4.58236e-006, 91.1095, -1, 11);
				PlaceObjectByHash(3681122061, -416.883, -825.126, 66.57, 9.66002, -8.44435e-006, 91.1096, -1, 11);
				PlaceObjectByHash(3681122061, -418.526, -825.157, 66.5571, 15.64, -1.80093e-005, 91.1095, -1, 11);
				PlaceObjectByHash(3681122061, -419.945, -825.184, 66.6727, 20.7001, 8.69782e-006, 91.1094, -1, 11);
				PlaceObjectByHash(3681122061, -421.727, -825.218, 67.0936, 25.7601, -2.09975e-005, 91.1095, -1, 11);
				PlaceObjectByHash(3681122061, -422.006, -825.234, 66.966, 30.8199, 0.114757, 90.6829, -1, 11);
				PlaceObjectByHash(3681122061, -429.913, -825.328, 71.6856, 30.8199, 0.114757, 90.6829, -1, 11);
			}
			if (Menu::Main::Option("Teleport")) {
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), -74.94243f, -818.63446f, 326.174347f, 1, 0, 0, 1);
			}
			Menu::Main::End("Maze Bank Ramp");
			break;
		case Settings:
			Menu::Main::Submenu("Border", BorderMenu);
			Menu::Main::Submenu("Backround", BackMenu);
			Menu::Main::Submenu("Scroller", ScrollerMenu);
			Menu::Main::Submenu("Header", header);
			Menu::Main::End("shopui_title_ie_modgarage", "shopui_title_ie_modgarage");
			break;
		case header:
			if(Menu::Main::StringVector("Header", spriteStrings, &strings))
			{
				texturexdhsh = spriteNames[strings].spritename;
			}

			if(Menu::Main::Bool("Gif", gifen))
				gifen = !gifen;
			if (gifen)
				if(Menu::Main::StringVector("Gif", gifStrings, &gifi))
				{
					gifinfo = gifNames[gifi];
				}
			Menu::Main::End("Header");
			break;
		case BorderMenu:
			Menu::Main::Int("R", &BorderR, 0, 255, 1);
			Menu::Main::Int("G", &BorderG, 0, 255, 1);
			Menu::Main::Int("B", &BorderB, 0, 255, 1);
			Menu::Main::Int("A", &BorderA, 0, 255, 1);
			Menu::Main::End("Border");
			break;
		case BackMenu:
			Menu::Main::Int("R", &BackroundR, 0, 255, 1);
			Menu::Main::Int("G", &BackroundG, 0, 255, 1);
			Menu::Main::Int("B", &BackroundB, 0, 255, 1);
			Menu::Main::Int("A", &BackroundA, 0, 255, 1);
			Menu::Main::End("Backround");
			break;
		case ScrollerMenu:
			Menu::Main::Int("R", &ScrollerCornersR, 0, 255, 1);
			Menu::Main::Int("G", &ScrollerCornersG, 0, 255, 1);
			Menu::Main::Int("B", &ScrollerCornersB, 0, 255, 1);
			Menu::Main::Int("A", &ScrollerCornersA, 0, 255, 1);
			Menu::Main::End("Scroller");
			break;
		case character:

			int Hats[81];
			/*
			if (Menu::Main::Option("Police Outfit")) {
			police();
			}


			if (Menu::Main::Int("Hat", &Hats[81], 0, PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 0), 1))
			{
			int textureVariations = PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 0, Hats[81]) - 2;
			PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, Hats[81], 0, 2);// try dis kk now login s
			}
			{
			int Glasses[81];
			//variables


			// Menu::Main::Options' text here:

			if (Menu::Main::Int("Hat", &Glasses[81], 0, PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 0), 1)) {
			int textureVariations = PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 0, Glasses[81]) - 2;
			PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, Glasses[81], 0, 2);// try dis kk now login s do you stilll have the authority source authority no i never had that
			}
			} //PROP
			/*if (Menu::Main::Submenu("Customize Hats", hats));
			if (Menu::Main::Submenu("Customize Glasses", glasses));
			if (Menu::Main::Submenu("Customize Masks", masks));
			if (Menu::Main::Submenu("Customize Hair", hair));
			if (Menu::Main::Submenu("Customize Tops", tops));
			if (Menu::Main::Submenu("Customize Legs", leg));
			if (Menu::Main::Submenu("Customize Shoes", shoes));
			if (Menu::Main::Submenu("Customize Accesories", acc));
			if (Menu::Main::Submenu("~b~Customize Accesories", accc));
			if (Menu::Main::Submenu("Customize Top Body", body));
			if (Menu::Main::Submenu("Customize Tops Mis", mis));
			if (Menu::Main::Submenu("Customize Armor", armor));*/
			Menu::Main::Submenu("Clothing", Clothing);
			Menu::Main::Submenu("Clothing Textures", Textures);
			Menu::Main::End("Charecter Customizer");
			break;
		case Clothing:
			if (Menu::Main::Int("Hats", &Face_, 0, 100, 1))
				PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, Face_, 0, 1);// brb gotta shit
			if (Menu::Main::Int("Masks", &mask, 0, 100, 1))
				changeAppearance("MASK", mask, 0);
			if (Menu::Main::Int("Glasses", &Glasses_, 0, 100, 1))
				PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, Glasses_, 0, 1);
			if (Menu::Main::Int("Torso", &Torso_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, Torso_, 0, 1);
			if (Menu::Main::Int("Legs", &Legs_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, Legs_, 0, 1);
			if (Menu::Main::Int("Hands", &Hands_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, Hands_, 0, 1);
			if (Menu::Main::Int("Watches", &Watches_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, Watches_, 0, 1);
			if (Menu::Main::Int("Special1", &Special1_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 7, Special1_, 0, 1);
			if (Menu::Main::Int("Special2", &Special2_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 8, Special2_, 0, 1);
			if (Menu::Main::Int("Special3", &Special3_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, Special3_, 0, 1);
			if (Menu::Main::Int("Torso2", &Torso2_, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, Torso2_, 0, 1);
			if (Menu::Main::Int("Shoes", &shoes, 0, 100, 1))
				changeAppearance("SHOES", shoes, 0);

			Menu::Main::End("shopui_title_midfashion", "shopui_title_midfashion");
			break;
		case Textures:
			if (Menu::Main::Int("Hats", &hattex, 0, 100, 1))
				PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, Face_, hattex, 1);
			if (Menu::Main::Int("Masks", &masktex, 0, 100, 1))
				changeAppearance("MASK", mask, masktex);
			if (Menu::Main::Int("Glasses", &glasstex, 0, 100, 1))
				PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, Glasses_, glasstex, 1);
			if (Menu::Main::Int("Torso", &torsotex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, Torso_, torsotex, 1);
			if (Menu::Main::Int("Legs", &legtex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, Legs_, legtex, 1);
			if (Menu::Main::Int("Hands", &handtex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, Hands_, handtex, 1);
			if (Menu::Main::Int("Watches", &watchtex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, Watches_, watchtex, 1);
			if (Menu::Main::Int("Special1", &special1tex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 7, Special1_, special1tex, 1);
			if (Menu::Main::Int("Special2", &special2tex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 8, Special2_, special2tex, 1);
			if (Menu::Main::Int("Special3", &special3tex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, Special3_, special3tex, 1);
			if (Menu::Main::Int("Torso2", &torso2tex, 0, 100, 1))
				PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, Torso2_, torso2tex, 1);
			if (Menu::Main::Int("Shoes", &shoetex, 0, 100, 1))
				changeAppearance("SHOES", shoes, shoetex);
			Menu::Main::End("shopui_title_midfashion", "shopui_title_midfashion");
			break;
		case story_models:

			for (int i = 0; i < ARRAYSIZE(pedModels2); i++)
			{
				if (Menu::Main::Option(pedModels2[i]))
				{
					DWORD model = GAMEPLAY::GET_HASH_KEY(pedModels2[i]);
					STREAMING::REQUEST_MODEL(model);
					while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
					PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
					PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
					WAIT(10);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
					WAIT(10);
				}
			}
			Menu::Main::End("Story Models");
			break;
		case outfit:

			if (Menu::Main::Option("Rockstar Logo")) {
				rlogo();
			}
			if (Menu::Main::Option("BiG GHOST")) {
				ghost();
			}
			if (Menu::Main::Option("Penguin Outfit")) {
				Penguin();
			}
			if (Menu::Main::Option("Splinter")) {
				Splinter();
			}
			if (Menu::Main::Option("Pilot")) {
				Pilot();
			}
			if (Menu::Main::Option("Special Ops")) {
				Special();
			}
			if (Menu::Main::Option("Special Ops 2")) {
				Special2();
			}
			if (Menu::Main::Option("Balla Gang")) {
				Balla();
			}
			if (Menu::Main::Option("Elf")) {
				Elf();
			}
			if (Menu::Main::Option("Thug")) {
				Thug();
			}
			if (Menu::Main::Option("Santa")) {
				Santa();
			}
			if (Menu::Main::Option("Snowman")) {
				Snowman();
			}
			if (Menu::Main::Option("Swat")) {
				Swat();
			}
			Menu::Main::End("Outfits");
			break;
		case vision_effects:
			if (Menu::Main::Option("Default")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("DEFAULT");
			}
			if (Menu::Main::Option("Heat Vision On")) {
				GRAPHICS::SET_SEETHROUGH(true);
			}
			if (Menu::Main::Option("Heat Vision Off")) {
				GRAPHICS::SET_SEETHROUGH(false);
			}
			if (Menu::Main::Option("Night Vision On")) {
				GRAPHICS::SET_NIGHTVISION(true);
			}
			if (Menu::Main::Option("Night Vision Off")) {
				GRAPHICS::SET_NIGHTVISION(false);
			}
			if (Menu::Main::Option("Stoned")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("stoned");
			}
			if (Menu::Main::Option("Orange")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("REDMIST");
			}
			if (Menu::Main::Option("Red")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("DEATH");
			}
			if (Menu::Main::Option("Cocaine")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_flying_base");
			}
			if (Menu::Main::Option("Huffin Gas")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("DRUG_gas_huffin");
			}
			if (Menu::Main::Option("Wobbly")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_wobbly");
			}
			if (Menu::Main::Option("Drunk")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("Drunk");
			}
			if (Menu::Main::Option("Heaven")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("Bloom");
			}
			if (Menu::Main::Option("3D")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("PlayerSwitchPulse");
			}
			if (Menu::Main::Option("Killstreak")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("MP_Killstreak");
			}
			if (Menu::Main::Option("Hallucinations")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("player_transition");
			}
			if (Menu::Main::Option("Low Quality")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("cinema_001");
			}
			if (Menu::Main::Option("Blurry")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("CHOP");
			}
			if (Menu::Main::Option("Fucked Up Screen")) {
				GRAPHICS::SET_TIMECYCLE_MODIFIER("BarryFadeOut");
			}
			Menu::Main::End("vision effects");
			break;
		case spawner_mainmenu:
			Menu::Main::Submenu("Spawn Entity", spawner_spawncategorymenu);
			Menu::Main::Submenu("Spawner DB", spawner_dbmenu);
			Menu::Main::End("Spawner");
			break;
		case spawner_spawncategorymenu:
			Menu::Main::Submenu("Props", spawner_objectcategorymenu);
			if (Menu::Main::Submenu("Vehicles", vehiclespawner_mainmenu)) {
				globalTitleText = "Spawner";
				spawnVehicleOnPlayer = false;
			}
			Menu::Main::Submenu("Peds", spawner_pedmenu);
			Menu::Main::End("Spawner");
			break;
		case spawner_objectcategorymenu:
			Menu::Main::Submenu("Stunt Props", spawner_objectcategory_stuntprops);
			Menu::Main::Submenu("Christmas Props", spawner_objectcategory_christmasprops);
			Menu::Main::Submenu("Vegetation", spawner_objectcategory_vegetation);
			Menu::Main::Submenu("Buildings", spawner_objectcategory_buildings);
			Menu::Main::Submenu("Vehicle Props", spawner_objectcategory_vehicles);
			Menu::Main::Submenu("Drug Props", spawner_objectcategory_drugs);
			Menu::Main::Submenu("Multiplay Props", spawner_objectcategory_multiplayer);
			Menu::Main::Submenu("Airport Props", spawner_objectcategory_airport);
			Menu::Main::Submenu("Airconditioners", spawner_objectcategory_airconditioners);
			Menu::Main::Submenu("Trailers", spawner_objectcategory_trailers);
			for each(std::string file in GetFilenames("Sinister/Addons/Props/")) {
				std::string fileName = file;
				PropPackInfo basicInfo = getBasicPropAddoninfo(fileName);
				if (Menu::Main::Submenu((char*)basicInfo.prop.c_str(), spawner_objectcategory_addon, 2)) currentPropPack = file;
			}
			Menu::Main::Submenu("All Props", spawner_objectcategory_allprops);
			Menu::Main::End("Prop");
			break;
		case spawner_objectcategory_allprops:
			if (Menu::Main::CharOption("Filter", filter, 25)) filterOn = true;
			if (filterOn) {
				if (Menu::Main::Option("Clear Filter")) filterOn = false;
			}
			for (int i = 0; i < sizeof(propList) / sizeof(*propList); i++){
				if (std::string(propList[i]).find(filter) != std::string::npos || !filterOn) {
					Menu::Main::Object(propList[i], propList[i], 3);
				}
			}
			Menu::Main::End("All Props");
			break;
		case spawner_objectcategory_addon:
			PropPack pack = getPropAddon(currentPropPack);
			for (int i = 1; i < pack.optionnames.size(); i++) {
				Menu::Main::Object(pack.optionnames[i], pack.propnames[i], 3);
			}
			Menu::Main::End("Spawner");
			break;
			}
		}
		WAIT(0);
		
	}
	
}



void ScriptMain() {
	srand(GetTickCount());
		main();
}