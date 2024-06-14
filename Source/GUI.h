typedef struct Vector2 {
	float x, y;
};
typedef struct RGBA {
	int r, g, b, a;
};

typedef struct Sprite {
	char* dict;
	char* name;
};
typedef struct
{
	std::string dict;
	std::string texture;
	int framecount;
} gifInfo;
extern int BackroundR;
extern int BackroundG;
extern int BackroundB;
extern int BackroundA;
extern int BorderR;
extern int BorderG;
extern int BorderB;
extern int BorderA;
extern int ScrollerCornersR;
extern int ScrollerCornersG;
extern int ScrollerCornersB;
extern int ScrollerCornersA;
extern int ScrollerMainA;
enum Submenus
{
	Closed,
	Main_Menu,
	Protection,
	PTFX,
	Self_Options,
	selfanimation,
	Scenarios,
	modelchanger,
	vehiclemenu_lsc_mods,
	Player_Options,
	onlinemenuselected,
	attachoptions,
	oplayerattackers,
	oplayerdropoptions,
	dropstuff,
	next,
	onlinemenuselected2,
	ptfx_x,
	PlayerOptions,
	All_Players,
	Weapon_Options,
	Vehicle_Spawner,// c
	smgs,
	pistolmm,
	combat,
	appistol,
	vintage,
	cal,
	sns,
	heavy,
	shotguns,
	pistols,
	rifles,
	sniper,
	weapon_tint,
	microsmg,
	smgmod,
	assaultsmg,
	shotgun,
	assaultShotgun,
	BullpupShotgun,
	heavyshotgun,
	gusenberg,
	assrifel,
	carrifle,
	adrifle,
	mgmg,
	combatmg,
	spcarbine,
	bullrifle,
	sniperrifle,
	heavysniper,
	marksniper,
	Funny_Vehicles,
	ls_customs,
	Vehicle_Options,
	TP_Options,
	Money_Options,
	Recovery,
	character,
	vision_effects,
	hats,
	glasses,
	masks,
	hair,
	tops,
	leg,
	acc,
	accc,
	body,
	mis,
	armor,
	story_models,
	outfit,
	Misc_Options,
	map_option,
	mod_maze_demo,
	mod_maze_ramp,
	ferris_ramp,
	chiliad_ramp,
	airport_mini,
	airport_gate,
	UFO_Tower,
	mod_maze_quad,
	zancudo_moto,
	halfpipe,
	air_loop,
	mod_maze_ramp2,
	spawner_mainmenu,
	spawner_spawncategorymenu,
	spawner_dbmenu,
	spawner_objectcategorymenu,
	vehiclespawner_mainmenu,
	spawner_pedmenu,
	spawner_objectcategory_stuntprops,
	spawner_objectcategory_christmasprops,
	spawner_objectcategory_vegetation,
	spawner_objectcategory_buildings,
	spawner_objectcategory_vehicles,
	spawner_objectcategory_drugs,
	spawner_objectcategory_multiplayer,
	spawner_objectcategory_airport,
	spawner_objectcategory_airconditioners,
	spawner_objectcategory_trailers,
	spawner_objectcategory_addon,
	spawner_objectcategory_allprops,
	Settings,

	BorderMenu,
	ScrollerMenu,
	BackMenu,
	Clothing,
	Textures,
	header
};
extern char* texturexdhsh;
extern gifInfo gifinfo;
extern int currentmenu;
extern int OptionsTotal;
extern int MenuLvl;
extern int XtraOptionCount;
extern float x;
extern float y;
extern float w;
extern float h;
extern int lvl;
class Menu
{
public:

	class Drawing {
	public:

		static float conv360(float base, const float min, const float max);
		static void render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g,
		                  const int b);
		static void DRAW_STRING(std::string text, int font, RGBA textColor, Vector2 Pos, Vector2 Scale, bool Outline, bool Shadow, bool Center, bool RightJustify);
		static void DRAW_RECT(Vector2 Pos, Vector2 Scale, RGBA Rect);
		static void DRAW_SPRITE(Sprite sprite, Vector2 Pos, Vector2 ScaleAndRot, RGBA Color);
		static void DRAW_GRADIENT(Vector2 Pos, Vector2 ScaleAndRot, RGBA Color);
		static void PLAY_SOUND(char * sound);
		static void SET_SCALEFORM_ENTRY(std::string text);
		static void SETUP_INSTRUCTIONS();
		static void END_INSTRUCTION();
	};
	class Main {
	public:
		static void Title(std::string title);
		static void Title(char * dict, char * texture);
		static void MenuName(std::string Name);
		static void DrawBackround();
		static void End(std::string MenuName);
		static void End(char * dict, char * texture);
		static bool CharOption(std::string option, char *& output, int maxChars, int Lock = 2);
		static bool Object(std::string label, std::string object, int Lock);

		static bool Ped(std::string label, std::string ped, int Lock);

		static bool BoolNew(std::string OptionText, bool * b00l, int Lock);
		static bool Bool(std::string OptionText, bool b00l, int Lock = 2);
		static bool Float(std::string OptionText, float * var, float min, float max, float step, int Lock = 2);
		static bool Int(std::string OptionText, int * var, int min, int max, int step, int Lock = 2);
		static void ChangeSubMenu(Submenus newSubmenu);
		static bool Submenu(char * option, Submenus newSubmenu, int Lock = 2);
		//static void Player(std::string name, int playerNumber, int * selecterPlayer, std::string holdName);
		static bool StringVector(std::string option, std::vector<std::string> Vector, int * position, int Lock = 2);
		static void Instruction(char * text, int button, int instructCount);
		static void ExtraTitle(std::string title);
		static void ExtraOption(std::string title);
		static void nasty_scroll(float inc, int* prev, const int cur);
		static bool Login();
		static void StartChecks();
		static bool Option(std::string OptionText, int Lock = 2);
		
		static void set_sprite_tex(char* set)
		{
			texturexdhsh = set;
		}
	private:
	  
	};

	class Loops {
	public:
	};
};