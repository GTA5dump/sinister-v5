#pragma once

//=================
// PED FUNCTIONS
//=================
extern int TimePD2;
extern int TimePD3;
extern int TimePD4;
extern int TimePD5;
extern int TimePD6;
extern int TimePD7;

Ped ClonePed(Ped ped);
Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle);

//Animations
void LoadAnim(char * dict);
void playAnimation(Ped ped, bool loop, char * dict, char * anim);

//SKINS
bool applyChosenSkin(std::string skinName);

//CONTROL
void RequestControlOfEnt(Entity entity);

//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z);

//playerflyer
//void playerflyer(bool toggle);

//fastrun
void FastRun(bool toggle);

//tinyplayer
//void TinyPlayer(bool toggle);

//neverwanted
void NeverWanted(bool toggle);

//fastswim
void fastswim(bool toggle);

//superjump
void SuperJump(bool toggle);

//mobileRadio
void mobileRadio(bool toggle);

//Invisible
//void  Invisible(bool toggle);//its out now 

//noragdoll
void NoRagdoll(bool toggle);

//GOD MODE
void GodMode(bool toggle);

//void FastRun(bool toggle);



//void ExplosiveAmmo(bool toggle, char* name, Player p);

//CALM PEDS
void set_all_nearby_peds_to_calm();

//NEARBY PEDS
std::set<Ped> getNearbyPeds();
void update_nearby_peds(Ped playerPed, int count);

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str);

//Converts Radians to Degrees
float degToRad(float degs);

//quick function to get-coords-of-entity:
Vector3 coordsOf(Entity entity);

//quick function to get distance between 2 points:
float distanceBetween(Vector3 A, Vector3 B);

//quick "get random int in range 0-x" function:
int rndInt(int start, int end);

//TELEPORTATION
Vector3 get_blip_marker();
void teleport_to_marker();
void teleport_to_coords(Entity e, Vector3 coords);

//KEYBOARD
std::string show_keyboard(char* title_id, char* prepopulated_text);

//NOTIFICATION
void notifyMap(std::string msg, BOOL blink);

//self animation
void doAnimation(char* anim, char* animid);

//clear self animation
void clearanim();

extern int selectedPlayer;
//cage player
void trapcage(Ped ped);

//Waterloop
void waterloop(Player selectedPlayer);
extern bool playerwaterloop[35];

//fuckhandling
extern bool fuckedhandling[32];
void fuckhandling(Player Ped);

//shakecam
extern bool camshaker[32];
void shakecam(Player selectedPlayer);

//fireloop
extern bool playerfireloop[35];
void FireLoop(Player selectedPlayer);

//explodeloop
extern bool exploder[32];
void explodeloop(Player selectedPlayer);

//
void teleporttocoords(Player Ped, Vector3 selectedPlayer);

//spectate
extern bool spectate[32];
void specter(Player Ped);

//sami god mod
extern int attachobj[100];
extern int nuattach;
void attachobjects2(char* objects);

//money drop
void cashdrop(bool toggle);
void rainmoney(bool toggle);

//stealth money
void dropmoney1(bool toggle);

//attach
void RequestControlOfid(Entity netid);

//set rank
void SetRank(int rpvalue);
extern int Levels[8000];

//2k othere player
void dropmoney(bool toggle);

//tptoplayer
void TeleportToPlayer(Player player);

//online rain money
void devilsmoney(Player selectedPlayer);
extern bool savenewdrop2[35];

//force field
void forcefield(bool toggle);

//cargod mod
extern bool cargodmodebool;
void cargodmod(bool toggle);

//bulletprooftires
extern bool bulletprooftiresbool;
void bulletprooftires(bool toggle);

//enginealwayson
extern bool enginealwaysonbool;
void enginealwayson(bool toggle);

//drive on water
extern bool dowbool;
void DriveOnWater(bool toggle);

//fly car
extern bool fcbool;
void FlyingCarLoop(bool toggle);

//flip car 
void flipup();

//rainbowcar
extern bool rlbool;
void HasPaintLoop(bool toggle);

//max car 
void maxcar();

//Invisible
void Invisible(bool toggle);

//off radar
void offradar(bool toggle);

//i dont know
bool cstrcmp(const char* s1, const char* s2);

//cageall
void trapall();

//Infinite Ammo
void InfiniteAmmo(bool toggle);

//exposammo
void Expammos(bool toggle);
void Fireammos(bool toggle);
void Expmeels(bool toggle);
void OSKR(bool toggle);

//rainbow gun
void RBGuner(bool toggle);

//rapid fire
void rapidmaker(bool toggle);

//player veh options
void laVeh();
void kickfveh();
void forcePUSH();

//
void spawn_vehicle(char* toSpawn);

void BypassOnlineVehicleKick(Vehicle vehicle);
void spawnVehicle(Hash vehicle);
Vehicle spawn_vehicle2(char* toSpawn);
//ALL PLAYER VOIDS
void shakewholelobby();
void atoilet();
void aCtree();

//PROTECTIONS
void antiParticleFXCrash(bool toggle);

//ped boost
void pedhornboost(bool toggle);
void hornhavoc(bool toggle);
void explodenearbyvehicles(bool toggle);
void deletenearbyvehicles(bool toggle);
void rainbownearby(bool toggle);
void killpeds(bool toggle);
void opendoors();
void closedoors();

//ls_customs
void changemod(int type, int index);

//ptfx
void PTFXCALL(char *call1, char *call2, char *name, int bone);
void PTLopperO(Player selectedPlayer);

extern float accelerationfloat;
extern float brakeforcefloat;
extern float tractionfloat;


//bulletTime
void bulletTime(bool toggle);
void blameall();
void kicknigga();
void laghimout(Player selectedPlayer);

//horn boost
void carboost(bool toggle);

extern bool esper;
void esp(bool toggle);

void Freezer(Player ped);
extern bool freezed[35];
void IwANTTOdie(int p);

void aimbot(bool toggle);
void featureMassTriggerbot(bool toggle);

void tenmil(bool toggle);
//car
void tiressmoke(bool toggle);

void drifft(bool toggle);

void ranneo(bool toggle);

void selfinfo(bool toggle);
void PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id);
void blackoutfunc(bool toggle);
void host();
extern bool tk;
void AddClothingProp(int BodyID, int Part, int &Variation);
void drawfloat(float text, DWORD decimal_places, float X, float Y);
void AddCloth(int BodyID, int Part, int &Variation);
void police();
void rlogo();
void ghost();
void Penguin();
void Splinter();
void Pilot();
void Special();
void Special2();
void Balla();
void Elf();
void Thug();
void Santa();
void Snowman();
void Swat();
void ResetAppearance();
void changeAppearance(char* family, int model, int texture);
void tank(bool toggle);
Vehicle CREATE_VEHICLEB(Hash model, float x, float y, float z, float heading, bool NetHandle, bool VehicleHandle);
void air1(bool toggle);
void rploop(bool toggle);
//float Get3DDistance1(Vector3 a, Vector3 b);
void sendpolice();
void givarmor();
void givehealth();
void givparachute();
void gsnack();
void gminigun();
void ghsniper();
void grpg();
void mini();
void gmolotov();
void bodygard();
void Enemy();
void police1();
void Swatt();
void SHIT();
void Swatcar();
void sendTanks();
void shootveh(bool toggle);
void GravityGun(bool toggle);
void RequestControl(Entity input);
void flying(bool toggle);
void namechnager();
void SetName(char* name);
void inner_force(bool toggle);
void themes(bool toggle);
void themes1(bool toggle);
void themes2(bool toggle);
void air2(bool toggle);
void lobbyinfo(bool toggle);
void showtalk(bool toggle);
void drawTalker(char* Text, int Index);
bool IsPlayerFriend(Player player);
void NameTagESP(bool toggle);
extern bool money;
void stealth(int* transID, int p1, int p2, int p3, int p4, int p5);
void dropmoney2(bool toggle);
void spawnVehicle(Hash vehicle);
void turbo();
void PlateChange(uint veh);
void moneygun(bool toggle);
void water(bool toggle);
void watermode(bool toggle);
void ShootPTFXDos();
void testgun(bool toggle);
void kick(bool toggle);
void noClip(bool toggle);
void set_featureVehRockets(bool toggle);
extern bool toBank;
void StealthLoop();
extern bool toBank2;
void StealthLoop2();
extern bool toBank3;
void StealthLoop3();
extern bool toBank4;
void StealthLoop4();
void setName(char* name);
void RestrictedArea(Player Ped);
void NonHostKick(Player Ped);
void KickFromVehicleV2(Player Ped);
void PopVehicleTyres(Player Ped);
void SlidyTyres(Player player, bool enable);
void UpdatePlayers();
void RamWithVehicle(Player player);
void CopyOutfit(Player player);
void JoinCrew(Player player);