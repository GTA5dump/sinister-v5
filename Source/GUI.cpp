#include "stdafx.h"
enum ICONTYPE {
	ICON_NOTHING = 4,
	ICON_CHAT_BOX = 1,
	ICON_EMAIL,
	ICON_ADD_FRIEND_REQUEST = 3,
	ICON_RIGHT_JUMPING_ARROW = 7,
	ICON_RP_ICON = 8,
	ICON_CASH_ICON = 9
};

//EDIT VER HERE

std::string MenuVer = "1.45";


float Menu::Drawing::conv360(float base, const float min, const float max)
{
	if (min == max) return min;
	const auto f_var0 = max - min;
	base -= round(base - min / f_var0) * f_var0;
	if (base < min) base += f_var0;
	return base;
}

void Menu::Drawing::render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g,
	const int b)
{
	float g_glare_dir = 0;
	const auto g_glare_handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE(static_cast<char*>("MP_MENU_GLARE"));
	const auto rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);
	const auto dir = conv360(rot.z, 0, 360);
	if ((g_glare_dir == 0 || g_glare_dir - dir > 0.5) || g_glare_dir - dir < -0.5)
	{
		g_glare_dir = dir;
		GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(g_glare_handle, static_cast<char*>("SET_DATA_SLOT"));
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_FLOAT(g_glare_dir);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	}
	GRAPHICS::DRAW_SCALEFORM_MOVIE(g_glare_handle, x, y, sx, sy, r, g, b, 20, 0);
	GRAPHICS::_SCREEN_DRAW_POSITION_END();
}
int BackroundR = 20;
int BackroundG = 20;
int BackroundB = 20;
int BackroundA = 150;
int BorderR = 0;
int BorderG = 0;
int BorderB = 0;
int BorderA = 255;
int ScrollerCornersR = 255;
int ScrollerCornersG = 255;
int ScrollerCornersB = 255;
int ScrollerCornersA = 180;
int ScrollerMainA = 19;

//menu functions:
char *infoText, *scriptToLoad, *SoundToPlay, *SoundSetToPlay;

int currentmenu = Closed, MenuLvl, FinalSubmenu[20], OptionsTotal, pIndex, FinalOption[20], NetworkHandle, SelectedOption;
int prevoption = 0;
bool newTimerTick = true;
int maxTimerCount;
bool newTimerTick2 = true;
int maxTimerCount2;
bool menuSounds = true, rightPress = false, leftPress = false, optionPress = false, PlaySounds;
bool LeftRightInstruct = 0;

void Menu::Drawing::DRAW_STRING(std::string text, int font, RGBA textColor, Vector2 Pos, Vector2 Scale, bool Outline = 1, bool Shadow = 1, bool Center = 1, bool RightJustify = 0)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(Scale.x, Scale.y);
	UI::SET_TEXT_COLOUR(textColor.r, textColor.b, textColor.b, textColor.a);
	if (Outline)
		UI::SET_TEXT_OUTLINE();
	if (Shadow)
		UI::SET_TEXT_DROP_SHADOW();
	if (Center)
		UI::SET_TEXT_CENTRE(1);
	if (RightJustify)
		UI::SET_TEXT_RIGHT_JUSTIFY(1);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	char* drawingText = (char*)text.c_str();
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(drawingText);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(Pos.x, Pos.y);
}
void Menu::Drawing::DRAW_RECT(Vector2 Pos, Vector2 Scale, RGBA Rect)
{
	GRAPHICS::DRAW_RECT(Pos.x, Pos.y, Scale.x, Scale.y, Rect.r, Rect.g, Rect.b, Rect.a);
}
void Menu::Drawing::DRAW_SPRITE(Sprite sprite, Vector2 Pos, Vector2 ScaleAndRot, RGBA Color) {
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(sprite.dict))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(sprite.dict, false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE(sprite.dict, sprite.name, Pos.x, Pos.y, ScaleAndRot.x, ScaleAndRot.y, 0.00f, Color.r, Color.g, Color.b, Color.a);
	}
}
void Menu::Drawing::DRAW_GRADIENT(Vector2 Pos, Vector2 ScaleAndRot, RGBA Color) {
	DRAW_SPRITE({ "CommonMenu", "interaction_bgd" }, Pos, ScaleAndRot, Color);
}
void Menu::Drawing::PLAY_SOUND(char* sound)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET", 1);
}
float menux = 0.8f;
float titlescaley = 0.154f;
float titley = 0.205f;
float customtitleys = .1535f;
float y22 = 0.2038;
char* texturexdhsh = "Star-Wars";

int titleticker = GetCurrentTime();
int gifdelay = 0;

void resettitleticker()
{
	titleticker = GetCurrentTime();
}
bool gif = false;
bool dd = false;
std::string zxd;
char* string2;
gifInfo gifinfo = { "goku", "goku", 46 };
int current_frame = 1;
void Menu::Main::Title(std::string title) {
	
	Drawing::DRAW_STRING(title, 4, { 255,0,0,255 }, { menux, 0.15f }, { 1.0f, 1.0f }, 1, 1, 1, 0);
	//Drawing::DRAW_RECT({ menux, titley }, { 0.2f, titlescaley }, { 20, 20, 20,255 });
	if (!gif)
		Drawing::DRAW_SPRITE({ "Booster", texturexdhsh }, { menux, y22 }, { 0.2f, customtitleys }, { 255, 255, 255,255 });
	else
	{
		if (static_cast<int>(GetCurrentTime()) - titleticker >= gifdelay) {
			if (current_frame == gifinfo.framecount)
				current_frame = 1;
			if (current_frame <= 9)
			{
				zxd = gifinfo.texture + "0" + to_string(current_frame);
			}
			else
			{
				zxd = gifinfo.texture + to_string(current_frame);
			}
			string2 = const_cast<char*>(zxd.c_str());
			Drawing::DRAW_SPRITE({ const_cast<char*>(gifinfo.dict.c_str()) , string2 }, { menux, y22 }, { 0.2f, customtitleys }, { 255, 255, 255,255 });
			current_frame++;
			resettitleticker();
		}
	}

}

void Menu::Main::Title(char*dict, char*texture) {

	Drawing::DRAW_SPRITE({ dict, texture }, { menux, y22 }, { 0.2f, customtitleys }, { 255, 255, 255,255 });

}
float subtitley = 0.222f;
float subtitley2 = 0.393f;
float subtitlex2 = 0.245f;
void Menu::Main::MenuName(std::string Name) {
	Drawing::DRAW_STRING(Name, 4, { 255,255,255,255 }, { menux, subtitley }, { subtitlex2, subtitley2 }, 1, 1, 1, 0);
}


float plusrect = 0.2825;
float xscalerect = 0.2f;
float corner1x = menux - 0.056999f;
float corner1y = 0.1635f;
float corner2x = menux - 0.047999f;
float corner2y = 0.1525f;
float corner3x = menux + 0.050999f;
float corner3y = 0.2105f;
float corner4x = menux + 0.058999f;
float corner4y = 0.1975f;
float subtitlelinex = menux + .003f;
float subtitleliney = 0.220500f;
float subtitlelinescalex = 0.081000f;
float subtitlelinescaley = 0.001250f;
float titleliney = 0.283f;
float titlelinescalex = 0.2f;
float titlelinex = 0.003f;
float optioncounty = 0.254f;
float xscaleleftbar = 0.004f;
float yscalebottombar = 0.008f;
float plusbottomrect = 0.535f;
float xscalebottombar = 0.208f;
float bottomrecttimes = 1.531003f;
float debugbottomrecttimes = 1.5f;
float itemcount = 0.1f;
float topbary = 0.081f;
float leftandrighttoptitlebarx = 0.102f;
float bary = 0.206f;
float barscaley = 0.16f;
float bottombary = 0.2855f;
float bottomtexty = 0.287f;
float cornerselectedx1 = 0.098498f;
float cornerselectedx2 = 0.089999f;
float cornerselectedx3 = 0.0925f;
float cornerselectedx4 = 0.0995f;
float cornerselectedy3 = 0.2895f;
float cornerselectedy4 = 0.276f;
float bottomlinexplus = 0.0015f;
float bottombary2 = 0.295f;
float footeryscale = 0.0185f;
float plusrect2 = 0.2945f;
float plusscale = 0.005f;
float bottombar2y = 0.3082f;
float SinisterTeamPlus = 0.2818f;
float SinisterTeamMinus = 0.1007f;
float VersionMinus = 0.0847f;
float MenuVersionVIP = 0.075f;
float MenuVersionPremium = 0.06f;
float footerborder = footeryscale + subtitlelinescaley + plusscale;
void Menu::Main::DrawBackround() {
	if (currentmenu != Closed) {
		UI::HIDE_HELP_TEXT_THIS_FRAME();
		CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 19, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 20, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 21, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 27, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 54, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 123, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 124, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 125, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 126, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 138, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 139, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 140, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 177, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 178, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 179, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, 207, 1);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 166);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 167);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 177);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 178);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 202);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 204);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 205);
		CONTROLS::DISABLE_CONTROL_ACTION(0, ControlFrontendPause, 1);
		CONTROLS::DISABLE_CONTROL_ACTION(0, ControlPhone, true);
		CONTROLS::DISABLE_CONTROL_ACTION(1, ControlPhone, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlPhone, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_FRANKLIN, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MICHAEL, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_TREVOR, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MULTIPLAYER, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);// i know its there but its not disabling it i think it need to be in base.cpp try dat
		nasty_scroll(0.005f, &prevoption, SelectedOption);
		/*
		Main::Instruction("Select", 30, 0);
		Main::Instruction("Back", 31, 1);
		Main::Instruction("Scroll", 10, 3);
		Main::Instruction("Slider", 11, 2);
		Drawing::END_INSTRUCTION();
		*/
	}
}


float x = 1.095f;
float y = 0.89;
float w = 0.865;
float h = 1.692f;



void Menu::Main::End(std::string MenuName) {
	Title("~italic~Booster");
	Main::MenuName(MenuName);
	optionPress = false;
	rightPress = false;
	leftPress = false;
	infoText = NULL;

	Drawing::DRAW_RECT({ corner1x, corner1y }, { 0.001000f, 0.023000f }, { 250,250,250,255 });
	Drawing::DRAW_RECT({ corner2x, corner2y }, { 0.016000f, 0.001250f }, { 250,250,250,255 });
	Drawing::DRAW_RECT({ corner3x, corner3y }, { 0.015000f, 0.001000f }, { 250,250,250,255 });
	Drawing::DRAW_RECT({ corner4x, corner4y }, { 0.001000f, 0.028000f }, { 250,250,250,255 });
	//Drawing::DRAW_STRING("Sinister Dev Team", 4, { 255,0,0,255 }, { menux, OptionsTotal * 0.035f + bottomtexty }, { 0.05f,0.15f }, 1, 1, 1, 0);
	GRAPHICS::DRAW_RECT(subtitlelinex, subtitleliney, subtitlelinescalex, subtitlelinescaley, 255, 255, 255, 255);
	GRAPHICS::DRAW_RECT(subtitlelinex - titlelinex, titleliney, titlelinescalex, subtitlelinescaley, 255, 255, 255, 255);
	Drawing::DRAW_RECT({ menux, titley - topbary }, { xscalebottombar, yscalebottombar }, { BorderR, BorderG, BorderB, BorderA });
	Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, bary }, { xscaleleftbar, barscaley }, { BorderR, BorderG, BorderB, BorderA });
	Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx,bary }, { xscaleleftbar, barscaley }, { BorderR, BorderG, BorderB, BorderA });
	std::ostringstream str1;
	std::ostringstream str2;
	str1 << SelectedOption;
	str2 << OptionsTotal;

	Drawing::DRAW_STRING("Item " + str1.str() + "/" + str2.str(), 4, { 255,0,0, 255 }, { menux - itemcount, optioncounty }, { 0.00f, 0.35f }, 1, 1, 0);
	if (lvl == 3)
		Drawing::DRAW_STRING("VIP " + MenuVer, 4, { 255,0,0, 255 }, { menux + MenuVersionVIP, optioncounty }, { 0.00f, 0.35f }, 1, 1, 0);
	else if (lvl == 2)
		Drawing::DRAW_STRING("Premium " + MenuVer, 4, { 255,0,0, 255 }, { menux + MenuVersionPremium, optioncounty }, { 0.00f, 0.35f }, 1, 1, 0);
	if (OptionsTotal >= 16)
	{
		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, (((16 * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (16 * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });//Left Border Options
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, (((16 * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (16 * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });// Right Border Options
		Drawing::DRAW_RECT({ menux, 16 * 0.035f + bottombary }, { titlelinescalex + bottomlinexplus, subtitlelinescaley }, { 255, 255, 255,255 });// Footer Separator
		Drawing::DRAW_RECT({ menux, 16 * 0.035f + bottombary2 }, { titlelinescalex + bottomlinexplus, footeryscale }, { BackroundR,BackroundG,BackroundB,BackroundA });//Footer Main
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, 16 * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Left
		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, 16 * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Right
		Drawing::DRAW_RECT({ menux, 16 * 0.035f + bottombar2y }, { xscalebottombar, yscalebottombar }, { BorderR, BorderG, BorderB, BorderA });// Footer Bottom Border
		Drawing::DRAW_STRING("~italic~1.46", 4, { 255,0,0,255 }, { menux + VersionMinus , 16 * 0.035f + SinisterTeamPlus }, { 0, 0.4f }, 1, 1, 0);// Footer Text 2
																																				  //Drawing::DRAW_RECT({ menux, ((16 * 0.035f)*bottomrecttimes) }, { xscalebottombar, yscalebottom }, { 0,0,0,255 });
	}
	else {


		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, (((OptionsTotal * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (OptionsTotal * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });//Left Border Options
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, (((OptionsTotal * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (OptionsTotal * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });// Right Border Options
		Drawing::DRAW_RECT({ menux, OptionsTotal * 0.035f + bottombary }, { titlelinescalex + bottomlinexplus, subtitlelinescaley }, { 255, 255, 255,255 });// Footer Separator
		Drawing::DRAW_RECT({ menux, OptionsTotal * 0.035f + bottombary2 }, { titlelinescalex + bottomlinexplus, footeryscale }, { BackroundR,BackroundG,BackroundB,BackroundA });//Footer Main
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, OptionsTotal * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Left
		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, OptionsTotal * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Right
		Drawing::DRAW_RECT({ menux, OptionsTotal * 0.035f + bottombar2y }, { xscalebottombar, yscalebottombar }, { BorderR, BorderG, BorderB, BorderA });// Footer Bottom Border
		Drawing::DRAW_STRING("~italic~1.46", 4, { 255,0,0,255 }, { menux + VersionMinus , OptionsTotal * 0.035f + SinisterTeamPlus }, { 0, 0.4f }, 1, 1, 0);// Footer Text 2
	}
	Drawing::render_globe(x, y, w, h, 255, 255, 255);
}
void Menu::Main::End(char*dict, char*texture) {
	Title(dict, texture);
	optionPress = false;
	rightPress = false;
	leftPress = false;
	infoText = NULL;

	/*Drawing::DRAW_RECT({ corner1x, corner1y }, { 0.001000f, 0.023000f }, { 250,250,250,255 });
	Drawing::DRAW_RECT({ corner2x, corner2y }, { 0.016000f, 0.001250f }, { 250,250,250,255 });
	Drawing::DRAW_RECT({ corner3x, corner3y }, { 0.015000f, 0.001000f }, { 250,250,250,255 });
	Drawing::DRAW_RECT({ corner4x, corner4y }, { 0.001000f, 0.028000f }, { 250,250,250,255 });
	//Drawing::DRAW_STRING("Sinister Dev Team", 4, { 255,0,0,255 }, { menux, OptionsTotal * 0.035f + bottomtexty }, { 0.05f,0.15f }, 1, 1, 1, 0);
	GRAPHICS::DRAW_RECT(subtitlelinex, subtitleliney, subtitlelinescalex, subtitlelinescaley, 255, 255, 255, 255);*/
	GRAPHICS::DRAW_RECT(subtitlelinex - titlelinex, titleliney, titlelinescalex, subtitlelinescaley, 255, 255, 255, 255);
	Drawing::DRAW_RECT({ menux, titley - topbary }, { xscalebottombar, yscalebottombar }, { BorderR, BorderG, BorderB, BorderA });
	Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, bary }, { xscaleleftbar, barscaley }, { BorderR, BorderG, BorderB, BorderA });
	Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx,bary }, { xscaleleftbar, barscaley }, { BorderR, BorderG, BorderB, BorderA });
	std::ostringstream str1;
	std::ostringstream str2;
	str1 << SelectedOption;
	str2 << OptionsTotal;

	Drawing::DRAW_STRING("Item " + str1.str() + "/" + str2.str(), 4, { 255,0,0, 255 }, { menux - itemcount, optioncounty }, { 0.00f, 0.35f }, 1, 1, 0);
	if (lvl == 3)
		Drawing::DRAW_STRING("VIP " + MenuVer, 4, { 255,0,0, 255 }, { menux + MenuVersionVIP, optioncounty }, { 0.00f, 0.35f }, 1, 1, 0);
	else if (lvl == 2)
		Drawing::DRAW_STRING("Premium " + MenuVer, 4, { 255,0,0, 255 }, { menux + MenuVersionPremium, optioncounty }, { 0.00f, 0.35f }, 1, 1, 0);
	if (OptionsTotal >= 16)
	{
		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, (((16 * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (16 * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });//Left Border Options
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, (((16 * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (16 * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });// Right Border Options
		Drawing::DRAW_RECT({ menux, 16 * 0.035f + bottombary }, { titlelinescalex + bottomlinexplus, subtitlelinescaley }, { 255, 255, 255,255 });// Footer Separator
		Drawing::DRAW_RECT({ menux, 16 * 0.035f + bottombary2 }, { titlelinescalex + bottomlinexplus, footeryscale }, { BackroundR,BackroundG,BackroundB,BackroundA });//Footer Main
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, 16 * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Left
		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, 16 * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Right
		Drawing::DRAW_RECT({ menux, 16 * 0.035f + bottombar2y }, { xscalebottombar, yscalebottombar }, { BorderR, BorderG, BorderB, BorderA });// Footer Bottom Border
		Drawing::DRAW_STRING("~italic~1.46", 4, { 255,0,0,255 }, { menux + VersionMinus , 16 * 0.035f + SinisterTeamPlus }, { 0, 0.4f }, 1, 1, 0);// Footer Text 2
																																				  //Drawing::DRAW_RECT({ menux, ((16 * 0.035f)*bottomrecttimes) }, { xscalebottombar, yscalebottom }, { 0,0,0,255 });
	}
	else {


		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, (((OptionsTotal * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (OptionsTotal * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });//Left Border Options
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, (((OptionsTotal * 0.035f) / 2) + plusrect) }, { xscaleleftbar, (OptionsTotal * 0.035f) }, { BorderR, BorderG, BorderB, BorderA });// Right Border Options
		Drawing::DRAW_RECT({ menux, OptionsTotal * 0.035f + bottombary }, { titlelinescalex + bottomlinexplus, subtitlelinescaley }, { 255, 255, 255,255 });// Footer Separator
		Drawing::DRAW_RECT({ menux, OptionsTotal * 0.035f + bottombary2 }, { titlelinescalex + bottomlinexplus, footeryscale }, { BackroundR,BackroundG,BackroundB,BackroundA });//Footer Main
		Drawing::DRAW_RECT({ menux + leftandrighttoptitlebarx, OptionsTotal * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Left
		Drawing::DRAW_RECT({ menux - leftandrighttoptitlebarx, OptionsTotal * 0.035f + plusrect2 }, { xscaleleftbar, footerborder }, { BorderR, BorderG, BorderB, BorderA });// Footer Border Right
		Drawing::DRAW_RECT({ menux, OptionsTotal * 0.035f + bottombar2y }, { xscalebottombar, yscalebottombar }, { BorderR, BorderG, BorderB, BorderA });// Footer Bottom Border
		Drawing::DRAW_STRING("~italic~1.46", 4, { 255,0,0,255 }, { menux + VersionMinus , OptionsTotal * 0.035f + SinisterTeamPlus }, { 0, 0.4f }, 1, 1, 0);// Footer Text 2
	}
}
int keyPressDelay = 500;
int keyPressPreviousTick = GetTickCount();
void Menu::Main::StartChecks() {
	if (GetTickCount() - keyPressPreviousTick >= 150) {
		if (currentmenu == Closed)
		{

			if (CONTROLS::IS_CONTROL_PRESSED(0, ControlPhoneRight) && CONTROLS::IS_CONTROL_JUST_PRESSED(0, ControlJump) || GetAsyncKeyState(VK_MULTIPLY))
			{
				currentmenu = !currentmenu;
				MenuLvl = 1;
				SelectedOption = 1;
				prevoption = 1;
				Drawing::PLAY_SOUND("NO");
				keyPressPreviousTick = GetTickCount();
			}
		}
		else
		{

			if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, ControlFrontendCancel) || GetAsyncKeyState(VK_NUMPAD0))
			{
				if (currentmenu == 1)
				{
					currentmenu = 0;
				}
				else {
					currentmenu = FinalSubmenu[MenuLvl - 1];
					SelectedOption = FinalOption[MenuLvl - 1];
					prevoption = 1;
					MenuLvl--;
				}
				SoundToPlay = "BACK";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = 1;
				keyPressPreviousTick = GetTickCount();
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, ControlFrontendAccept) || GetAsyncKeyState(VK_NUMPAD5))
			{
				optionPress = true;
				SoundToPlay = "SELECT";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = 1;
				keyPressPreviousTick = GetTickCount();
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, ControlPhoneUp) || GetAsyncKeyState(VK_NUMPAD8))
			{


				SelectedOption > 1 ? SelectedOption-- : SelectedOption = OptionsTotal;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = 1;
				keyPressPreviousTick = GetTickCount();
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, ControlPhoneDown) || GetAsyncKeyState(VK_NUMPAD2))
			{
				SelectedOption < OptionsTotal ? SelectedOption++ : SelectedOption = 1;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = 1;
				keyPressPreviousTick = GetTickCount();
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, ControlPhoneRight) || GetAsyncKeyState(VK_NUMPAD6))
			{
				rightPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
				keyPressPreviousTick = GetTickCount();
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, ControlPhoneLeft) || GetAsyncKeyState(VK_NUMPAD4))
			{
				leftPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
				keyPressPreviousTick = GetTickCount();
			}
		}
	}
}
float optionplus = 0.2445f;
bool Menu::Main::Option(std::string OptionText, int Lock) {
	if ((Lock == 2) && (lvl == 2 || 3)) {
		OptionsTotal++;
		if (SelectedOption <= 16 && OptionsTotal <= 16) {
			Drawing::DRAW_STRING(OptionText, 6, { SelectedOption == OptionsTotal ? 255 : ScrollerCornersR, SelectedOption == OptionsTotal ? 0 : ScrollerCornersG, SelectedOption == OptionsTotal ? 0 : ScrollerCornersB, ScrollerCornersA },
			{ menux - 0.0975f, (OptionsTotal * 0.035f + optionplus) }, { 0.085000f, 0.555000f }, true, true, false);
		}
		else if ((OptionsTotal > (SelectedOption - 16)) && OptionsTotal <= SelectedOption) {
			Drawing::DRAW_STRING(OptionText, 6, { SelectedOption == OptionsTotal ? 255 : ScrollerCornersR, SelectedOption == OptionsTotal ? 0 : ScrollerCornersG, SelectedOption == OptionsTotal ? 0 : ScrollerCornersB, ScrollerCornersA },
			{ menux - 0.0975f, ((OptionsTotal - (SelectedOption - 16)) * 0.035f + 0.245f) }, { 0.085000f, 0.555000f }, true, true, false);
		}
		if (SelectedOption == OptionsTotal && optionPress) {
			return true;
		}
	}
	else if ((Lock == 3) && (lvl == 3)) {
		OptionsTotal++;
		if (SelectedOption <= 16 && OptionsTotal <= 16) {
			Drawing::DRAW_STRING(OptionText, 6, { SelectedOption == OptionsTotal ? 255 : ScrollerCornersR, SelectedOption == OptionsTotal ? 0 : ScrollerCornersG, SelectedOption == OptionsTotal ? 0 : ScrollerCornersB, ScrollerCornersA },
			{ menux - 0.0975f, (OptionsTotal * 0.035f + optionplus) }, { 0.085000f, 0.555000f }, true, true, false);
		}
		else if ((OptionsTotal > (SelectedOption - 16)) && OptionsTotal <= SelectedOption) {
			Drawing::DRAW_STRING(OptionText, 6, { SelectedOption == OptionsTotal ? 255 : ScrollerCornersR, SelectedOption == OptionsTotal ? 0 : ScrollerCornersG, SelectedOption == OptionsTotal ? 0 : ScrollerCornersB, ScrollerCornersA },
			{ menux - 0.0975f, ((OptionsTotal - (SelectedOption - 16)) * 0.035f + 0.245f) }, { 0.085000f, 0.555000f }, true, true, false);
		}
		if (SelectedOption == OptionsTotal && optionPress) {
			return true;
		}
	}
	return false;

}
float rect1x = 0.8706f;
float rect1y = 0.2624f;
float string1x1 = 0.8575f;
float string1x2 = 0.8825f;
float string1y = 0.2506f;
float rect2x1 = 0.882f;
float rect2x2 = 0.8607f;
float rect2y = 0.2619f;
char* StringToChar(std::string string) {
	return _strdup(string.c_str());
}
std::string GetKeyboardInput(char* title_id, char* prepopulated_text, int maxChars)
{
	DWORD time = GetTickCount() + 400;
	while (GetTickCount() < time)
		WAIT(0);

	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, title_id, "tmp", prepopulated_text, "", "", "", maxChars);

	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0)
		WAIT(0);

	std::stringstream ss;
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT() || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() != 1)
	{
		return std::string("");
	}
	else
	{
		return std::string(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
	}
}
bool Menu::Main::CharOption(std::string option, char* &output, int maxChars, int Lock)
{
	bool toggled = Option(option + (std::string)"_>", Lock);
	if (toggled) {
		char* prevOutput = output;
		output = StringToChar(GetKeyboardInput("FMMC_KEY_TIP", StringToChar(std::string("Input")), maxChars));

		if (strlen(output) > 0 && std::string(output).compare(prevOutput) != 0)
			return true;
	}
	return false;
}
bool Menu::Main::Object(std::string label, std::string object, int Lock)
{
    bool toggle = Option(label, Lock);




    if (toggle) {
        Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(),  0.f, 5.f, 0.f);
        Spawner::spawnEntity((char*)object.c_str(), 0, coords, players[selfPlayer].heading, false);
        return true;// this why spawner wasnt working 
    }

    return false;
}
bool Menu::Main::Ped(std::string label, std::string ped, int Lock)
{
	bool toggle = Option(label, Lock);




	if (toggle) {
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(players[selfPlayer].ped, 0.f, 2.f, 0.f);
		Spawner::spawnEntity((char*)ped.c_str(), 2, coords, players[selfPlayer].heading, false);
		return true;// this why spawner wasnt working 
	}

	return false;
}
bool Menu::Main::BoolNew(std::string OptionText, bool* b00l, int Lock) {
	bool ToggleBool = Option(OptionText, Lock);
	if ((Lock == 2) && (lvl == 2 || 3)) {
		if (SelectedOption <= 16 && OptionsTotal <= 16) {
			//GRAPHICS::DRAW_RECT(0.896999f, (optionCount * 0.035f + 0.273499f /* 0.503500f */), 0.049000f, booloption1, 29, 29, 29, 255);
			Drawing::DRAW_RECT({ rect1x, (OptionsTotal * 0.035f + rect1y) }, { .049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((*b00l ? "~italic~On" : "~italic~Off"), 7, { (*b00l ? 250 : 107), (*b00l ? 0 : 107), (*b00l ? 0 : 107), (*b00l ? 107 : 87) },
			{ (*b00l ? string1x1 : string1x2), (OptionsTotal * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (*b00l ? rect2x1 : rect2x2), (OptionsTotal * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });

		}
		else if ((OptionsTotal > (SelectedOption - 16)) && OptionsTotal <= SelectedOption) {
			Drawing::DRAW_RECT({ rect1x, ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect1y) }, { 0.049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((*b00l ? "~italic~On" : "~italic~Off"), 7, { (*b00l ? 250 : 107), (*b00l ? 0 : 107), (*b00l ? 0 : 107), (*b00l ? 107 : 87) },
			{ (*b00l ? string1x1 : string1x2),  ((OptionsTotal - (SelectedOption - 16)) * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (*b00l ? rect2x1 : rect2x2), ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });
		}
	}
	else if ((Lock == 3) && (lvl == 3)) {
		if (SelectedOption <= 16 && OptionsTotal <= 16) {
			//GRAPHICS::DRAW_RECT(0.896999f, (optionCount * 0.035f + 0.273499f /* 0.503500f */), 0.049000f, booloption1, 29, 29, 29, 255);
			Drawing::DRAW_RECT({ rect1x, (OptionsTotal * 0.035f + rect1y) }, { .049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((*b00l ? "~italic~On" : "~italic~Off"), 7, { (*b00l ? 250 : 107), (*b00l ? 0 : 107), (*b00l ? 0 : 107), (*b00l ? 107 : 87) },
			{ (b00l ? string1x1 : string1x2), (OptionsTotal * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (*b00l ? rect2x1 : rect2x2), (OptionsTotal * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });

		}
		else if ((OptionsTotal > (SelectedOption - 16)) && OptionsTotal <= SelectedOption) {
			Drawing::DRAW_RECT({ rect1x, ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect1y) }, { 0.049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((*b00l ? "~italic~On" : "~italic~Off"), 7, { (*b00l ? 250 : 107), (*b00l ? 0 : 107), (*b00l ? 0 : 107), (*b00l ? 107 : 87) },
			{ (*b00l ? string1x1 : string1x2),  ((OptionsTotal - (SelectedOption - 16)) * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (*b00l ? rect2x1 : rect2x2), ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });
		}
	}
	if (ToggleBool) {
		if (*b00l)
			*b00l = false;
		else if (!*b00l)
			*b00l = true;
		return true;
	}
	return false;
}
bool Menu::Main::Bool(std::string OptionText, bool b00l, int Lock) {
	bool ToggleBool = Option(OptionText, Lock);
	if ((Lock == 2) && (lvl == 2 || 3)) {
		if (SelectedOption <= 16 && OptionsTotal <= 16) {
			//GRAPHICS::DRAW_RECT(0.896999f, (optionCount * 0.035f + 0.273499f /* 0.503500f */), 0.049000f, booloption1, 29, 29, 29, 255);
			Drawing::DRAW_RECT({ rect1x, (OptionsTotal * 0.035f + rect1y) }, { .049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((b00l ? "~italic~On" : "~italic~Off"), 7, { (b00l ? 250 : 107), (b00l ? 0 : 107), (b00l ? 0 : 107), (b00l ? 107 : 87) },
			{ (b00l ? string1x1 : string1x2), (OptionsTotal * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (b00l ? rect2x1 : rect2x2), (OptionsTotal * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });

		}
		else if ((OptionsTotal > (SelectedOption - 16)) && OptionsTotal <= SelectedOption) {
			Drawing::DRAW_RECT({ rect1x, ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect1y) }, { 0.049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((b00l ? "~italic~On" : "~italic~Off"), 7, { (b00l ? 250 : 107), (b00l ? 0 : 107), (b00l ? 0 : 107), (b00l ? 107 : 87) },
			{ (b00l ? string1x1 : string1x2),  ((OptionsTotal - (SelectedOption - 16)) * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (b00l ? rect2x1 : rect2x2), ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });
		}
	}
	else if ((Lock == 3) && (lvl == 3)) {
		if (SelectedOption <= 16 && OptionsTotal <= 16) {
			//GRAPHICS::DRAW_RECT(0.896999f, (optionCount * 0.035f + 0.273499f /* 0.503500f */), 0.049000f, booloption1, 29, 29, 29, 255);
			Drawing::DRAW_RECT({ rect1x, (OptionsTotal * 0.035f + rect1y) }, { .049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((b00l ? "~italic~On" : "~italic~Off"), 7, { (b00l ? 250 : 107), (b00l ? 0 : 107), (b00l ? 0 : 107), (b00l ? 107 : 87) },
			{ (b00l ? string1x1 : string1x2), (OptionsTotal * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (b00l ? rect2x1 : rect2x2), (OptionsTotal * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });

		}
		else if ((OptionsTotal > (SelectedOption - 16)) && OptionsTotal <= SelectedOption) {
			Drawing::DRAW_RECT({ rect1x, ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect1y) }, { 0.049000f, 0.025000f }, { 29,29,29,255 });
			Drawing::DRAW_STRING((b00l ? "~italic~On" : "~italic~Off"), 7, { (b00l ? 250 : 107), (b00l ? 0 : 107), (b00l ? 0 : 107), (b00l ? 107 : 87) },
			{ (b00l ? string1x1 : string1x2),  ((OptionsTotal - (SelectedOption - 16)) * 0.035f + string1y) }, { 0.085000f , 0.361999f });
			Drawing::DRAW_RECT({ (b00l ? rect2x1 : rect2x2), ((OptionsTotal - (SelectedOption - 16)) * 0.035f + rect2y /* 0.503500f */) }, { 0.022000f, 0.020000f }, { 60, 60, 60, 255 });
		}
	}
	if (ToggleBool) {
		return true;
	}
	return false;
}
bool Menu::Main::Float(std::string OptionText, float*var, float min = 0.0f, float max = 1.0f, float step = 0.1f, int Lock) {
	char buff[40];

	_snprintf_s(buff, sizeof(buff), "%s < %f >", OptionText, *var);
	if (Option(buff, Lock)) {
		return true;
	}
	if (SelectedOption == OptionsTotal)
	{
		LeftRightInstruct = 1;
		if (rightPress) {
			if (*var >= max)
				*var = min;
			else
				*var = *var + step;
			rightPress = false;
		}

		if (leftPress) {
			if (*var <= min)
				*var = max;
			else
				*var = *var - step;
			leftPress = false;
		}
	}
	return false;
}
bool Menu::Main::Int(std::string OptionText, int*var, int min = 0, int max = 100, int step = 1, int Lock) {
	char buff[40];
	_snprintf_s(buff, sizeof(buff), "%s < %i >", OptionText, *var);
	if (Option(buff, Lock)) {
		return true;
	}
	if (SelectedOption == OptionsTotal)
	{
		LeftRightInstruct = 1;
		if (rightPress) {
			if (*var >= max)
				*var = min;
			else
				*var = *var + step;
			rightPress = false;
		}

		if (leftPress) {
			if (*var <= min)
				*var = max;
			else
				*var = *var - step;
			leftPress = false;
		}
	}
	return false;
}
void Menu::Main::ChangeSubMenu(Submenus newSubmenu)
{
	FinalSubmenu[MenuLvl] = currentmenu;
	FinalOption[MenuLvl] = SelectedOption;
	SelectedOption = 1;
	currentmenu = newSubmenu;
	MenuLvl++;
}
bool Menu::Main::Submenu(char *option, Submenus newSubmenu, int Lock) {
	char bufsub[30];
	_snprintf(bufsub, sizeof(bufsub), "%s ->", option);
	Option(bufsub, Lock);
	if (SelectedOption == OptionsTotal)
	{
		if (optionPress) {
			ChangeSubMenu(newSubmenu);
			return true;
		}

	}
	return false;
}
/*void Menu::Main::Player(std::string name, int playerNumber, int* selecterPlayer, std::string holdName) {
char buff[38];
_snprintf_s(buff, sizeof(buff), "%s ->", name);
if (Option(buff)) {
*selecterPlayer = playerNumber;
holdName = name;
ChangeSubMenu(OnlinePlayerOptions);
}
}*/
bool Menu::Main::StringVector(std::string option, std::vector<std::string> Vector, int*position, int Lock)
{
	bool pressed = Option(option + " < " + Vector[*position] + " >", Lock);
	if (SelectedOption == OptionsTotal)
	{
		LeftRightInstruct = 1;
		size_t max = Vector.size() - 1;
		int min = 0;
		if (rightPress) {
			if (*position >= max)
				*position = min;
			else
				*position = *position + 1;
			rightPress = false;
		}

		if (leftPress) {
			if (*position <= min)
				*position = max;
			else
				*position = *position - 1;
			leftPress = false;
		}
	}
	if (pressed) return true;
	return false;
}

void Menu::Drawing::SET_SCALEFORM_ENTRY(std::string text)
{
	GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text.c_str());
	GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();
}

/*
void Menu::Drawing::SETUP_INSTRUCTIONS()
{
int movie = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(movie, 255, 255, 255, 0, 0);
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "CLEAR_ALL");
GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "SET_CLEAR_SPACE");
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(200);
GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
}
void Menu::Main::Instruction(char * text, int button, int instructCount)
{
int movie = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "SET_DATA_SLOT");
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(instructCount);
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(button);
Drawing::SET_SCALEFORM_ENTRY(text);
GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
}
void Menu::Drawing::END_INSTRUCTION()
{
int movie = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "DRAW_INSTRUCTIONAL_BUTTONS");
GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(movie, "SET_BACKGROUND_COLOUR");
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(80);
GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
}
*/
float LoginX = 0.50f;
float LoginY = 0.50f;
float LoginXS = 1.00f;
float LoginYS = 1.00f;
float extratitlex = 0.6055f;
float extratitley = 0.1155f;
float extratitlescaley = 1.0f;
float extratitlescalex = 1.0f;
float extratitlebx = 0.6045f;
float extratitleby = 0.3095f;
float extratitlebscalex = 0.379f;
float extratitlebscaley = 0.174f;
float optioncounttimes = 0.029;
float optioncounttimesplus = 0.1337f;
float scale1 = 1.0f;
float scale2 = 0.555f;
float extraoptionx = 0.605f;
int XtraOptionCount = 0;
void Menu::Main::ExtraTitle(std::string title) {
	Drawing::DRAW_SPRITE({ "CommonMenu", "interaction_bgd" }, { extratitlebx, extratitleby }, { extratitlebscaley, extratitlebscalex }, { 255, 0, 0, 210 });
	Drawing::DRAW_STRING(title, 4, { 255, 0, 0, 255 }, { extratitlex, extratitley }, { extratitlescaley, extratitlescalex }, 1, 1, 1);
}
void Menu::Main::ExtraOption(std::string title) {
	XtraOptionCount++;
	Drawing::DRAW_STRING(title, 4, { 255, 255, 255, 255 }, { extraoptionx, XtraOptionCount * optioncounttimes + optioncounttimesplus }, { scale1, scale2 });

}
#define URL L"http://167.99.84.244/auth/auth.php"
int lvl = 3;
float prevf;
void Menu::Main::nasty_scroll(const float inc, int * prev, const int cur)
{
	if (prevf == NULL)
		prevf = *prev * 0.035f + 0.2635f;
	const auto curf = cur * 0.035f + 0.2635f;
	if (SelectedOption <= 16) {
		if (*prev != cur)
		{
			if (*prev == SelectedOption && cur == 0)
			{
				prevf = prevf - inc;
				const auto leftcorner1 = prevf - 0.001f;
				const auto leftcorner2 = prevf - 0.013f;
				const auto rightcorner1 = prevf + 0.026f;
				const auto rightcorner2 = prevf + 0.0125f;
				Drawing::DRAW_RECT({ menux, prevf }, { 0.193000f, 0.037000f }, { ScrollerCornersR,ScrollerCornersG, ScrollerCornersB, ScrollerMainA });// Scroller Main Rect
				Drawing::DRAW_RECT({ menux - cornerselectedx1, leftcorner1 }, { 0.001000f, 0.025000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 1
				Drawing::DRAW_RECT({ menux - cornerselectedx2, leftcorner2 }, { 0.016000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 2
				Drawing::DRAW_RECT({ menux + cornerselectedx3, rightcorner1 }, { 0.015000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 1
				Drawing::DRAW_RECT({ menux + cornerselectedx4, rightcorner2 }, { 0.001000f, 0.028000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 2
				if (prevf <= curf)
				{
					prevf = curf;
					*prev = cur;
				}
			}
			if (prevf < curf)
			{
				prevf = prevf + inc;
				const auto leftcorner1 = prevf - 0.001f;
				const auto leftcorner2 = prevf - 0.013f;
				const auto rightcorner1 = prevf + 0.026f;
				const auto rightcorner2 = prevf + 0.0125f;
				Drawing::DRAW_RECT({ menux, prevf }, { 0.193000f, 0.037000f }, { ScrollerCornersR,ScrollerCornersG, ScrollerCornersB, ScrollerMainA });// Scroller Main Rect
				Drawing::DRAW_RECT({ menux - cornerselectedx1, leftcorner1 }, { 0.001000f, 0.025000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 1
				Drawing::DRAW_RECT({ menux - cornerselectedx2, leftcorner2 }, { 0.016000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 2
				Drawing::DRAW_RECT({ menux + cornerselectedx3, rightcorner1 }, { 0.015000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 1
				Drawing::DRAW_RECT({ menux + cornerselectedx4, rightcorner2 }, { 0.001000f, 0.028000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 2
				if (prevf >= curf)
				{
					prevf = curf;
					*prev = cur;
				}
			}
			if (prevf > curf)
			{
				prevf = prevf - inc;
				const auto leftcorner1 = prevf - 0.001f;
				const auto leftcorner2 = prevf - 0.013f;
				const auto rightcorner1 = prevf + 0.026f;
				const auto rightcorner2 = prevf + 0.0125f;
				Drawing::DRAW_RECT({ menux, prevf }, { 0.193000f, 0.037000f }, { ScrollerCornersR,ScrollerCornersG, ScrollerCornersB, ScrollerMainA });// Scroller Main Rect
				Drawing::DRAW_RECT({ menux - cornerselectedx1, leftcorner1 }, { 0.001000f, 0.025000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 1
				Drawing::DRAW_RECT({ menux - cornerselectedx2, leftcorner2 }, { 0.016000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 2
				Drawing::DRAW_RECT({ menux + cornerselectedx3, rightcorner1 }, { 0.015000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 1
				Drawing::DRAW_RECT({ menux + cornerselectedx4, rightcorner2 }, { 0.001000f, 0.028000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 2
				if (prevf >= curf)
				{
					prevf = curf;
					*prev = cur;
				}
			}
		}
		else
		{
			*prev = cur;
			Drawing::DRAW_RECT({ menux, ((SelectedOption * 0.035f) + 0.2635f) }, { 0.193000f, 0.037000f }, { ScrollerCornersR,ScrollerCornersG, ScrollerCornersB, ScrollerMainA });// Scroller Main Rect
			Drawing::DRAW_RECT({ menux - cornerselectedx1, ((SelectedOption * 0.035f) + 0.262500f) }, { 0.001000f, 0.025000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 1
			Drawing::DRAW_RECT({ menux - cornerselectedx2, ((SelectedOption * 0.035f) + 0.250500f) }, { 0.016000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 2
			Drawing::DRAW_RECT({ menux + cornerselectedx3, ((SelectedOption * 0.035f) + cornerselectedy3) }, { 0.015000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 1
			Drawing::DRAW_RECT({ menux + cornerselectedx4, ((SelectedOption * 0.035f) + cornerselectedy4) }, { 0.001000f, 0.028000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 2
		}
	}
	else
	{
		Drawing::DRAW_RECT({ menux, ((16 * 0.035f) + 0.2635f) }, { 0.193000f, 0.037000f }, { ScrollerCornersR,ScrollerCornersG, ScrollerCornersB, ScrollerMainA });// Scroller Main Rect
		Drawing::DRAW_RECT({ menux - cornerselectedx1, ((16 * 0.035f) + 0.262500f) }, { 0.001000f, 0.025000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 1
		Drawing::DRAW_RECT({ menux - cornerselectedx2, ((16 * 0.035f) + 0.250500f) }, { 0.016000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Left Corner 2
		Drawing::DRAW_RECT({ menux + cornerselectedx3, ((16 * 0.035f) + cornerselectedy3) }, { 0.015000f, 0.002000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 1
		Drawing::DRAW_RECT({ menux + cornerselectedx4, ((16 * 0.035f) + cornerselectedy4) }, { 0.001000f, 0.028000f }, { ScrollerCornersR, ScrollerCornersG, ScrollerCornersB, ScrollerCornersA });//Right Corner 2
	}
}
std::string user = "";
std::string pass = "";
float UserX = 0.458f;
float UserY = 0.4566f;
float UserYS = 0.7184f;
float PassY = 0.0964f;
bool userisselected = 0;
/*
bool Menu::Main::Login() {
	Drawing::DRAW_SPRITE({ "prop_screen_gr_login", "prop_screen_gr_login" }, { LoginX, LoginY }, { LoginXS, LoginYS }, { 255,255,255, 255 });
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 19, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 20, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 21, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 27, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 54, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 123, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 124, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 125, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 126, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 138, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 139, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 140, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 177, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 178, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 179, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 207, 1);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 166);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 167);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 177);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 178);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 202);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 204);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 205);
	CONTROLS::DISABLE_CONTROL_ACTION(0, ControlFrontendPause, 1);
	CONTROLS::DISABLE_CONTROL_ACTION(0, ControlPhone, true);
	CONTROLS::DISABLE_CONTROL_ACTION(1, ControlPhone, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, ControlPhone, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_FRANKLIN, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MICHAEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_TREVOR, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MULTIPLAYER, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);// i know its there but its not disabling it i think it need to be in base.cpp


	if (GetAsyncKeyState(VK_RETURN)) {
	}
	if (GetTickCount() - keyPressPreviousTick >= 100) {
		keyPressPreviousTick = GetTickCount();

		if (userisselected) {

			if (GetAsyncKeyState(VK_DOWN)) {
				userisselected = false;
			}
			if (GetAsyncKeyState(VK_BACK)) {
				if (!user.empty())
					user = user.substr(0, user.length() - 1);
			}


			if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) && (!GetAsyncKeyState(VK_SHIFT))) {
				if (GetAsyncKeyState(0x41))
					user.append("A");
				if (GetAsyncKeyState(0x42))
					user.append("B");
				if (GetAsyncKeyState(0x43))
					user.append("C");
				if (GetAsyncKeyState(0x44))
					user.append("D");
				if (GetAsyncKeyState(0x45))
					user.append("E");
				if (GetAsyncKeyState(0x46))
					user.append("F");
				if (GetAsyncKeyState(0x47))
					user.append("G");
				if (GetAsyncKeyState(0x48))
					user.append("H");
				if (GetAsyncKeyState(0x49))
					user.append("I");
				if (GetAsyncKeyState(0x4A))
					user.append("J");
				if (GetAsyncKeyState(0x4B))
					user.append("K");
				if (GetAsyncKeyState(0x4C))
					user.append("L");
				if (GetAsyncKeyState(0x4D))
					user.append("M");
				if (GetAsyncKeyState(0x4E))
					user.append("N");
				if (GetAsyncKeyState(0x4F))
					user.append("O");
				if (GetAsyncKeyState(0x50))
					user.append("P");
				if (GetAsyncKeyState(0x51))
					user.append("Q");
				if (GetAsyncKeyState(0x52))
					user.append("R");
				if (GetAsyncKeyState(0x53))
					user.append("S");
				if (GetAsyncKeyState(0x54))
					user.append("T");
				if (GetAsyncKeyState(0x55))
					user.append("U");
				if (GetAsyncKeyState(0x56))
					user.append("V");
				if (GetAsyncKeyState(0x57))
					user.append("W");
				if (GetAsyncKeyState(0x58))
					user.append("X");
				if (GetAsyncKeyState(0x59))
					user.append("Y");
				if (GetAsyncKeyState(0x5A))
					user.append("Z");
				if (GetAsyncKeyState(0x30))
					user.append("0");
				if (GetAsyncKeyState(0x31))
					user.append("1");
				if (GetAsyncKeyState(0x32))
					user.append("2");
				if (GetAsyncKeyState(0x33))
					user.append("3");
				if (GetAsyncKeyState(0x34))
					user.append("4");
				if (GetAsyncKeyState(0x35))
					user.append("5");
				if (GetAsyncKeyState(0x36))
					user.append("6");
				if (GetAsyncKeyState(0x37))
					user.append("7");
				if (GetAsyncKeyState(0x38))
					user.append("8");
				if (GetAsyncKeyState(0x39))
					user.append("9");



			}
			else if (GetAsyncKeyState(VK_SHIFT)) {
				if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) {
					if (GetAsyncKeyState(0x41))
						user.append("a");
					if (GetAsyncKeyState(0x42))
						user.append("b");
					if (GetAsyncKeyState(0x43))
						user.append("c");
					if (GetAsyncKeyState(0x44))
						user.append("d");
					if (GetAsyncKeyState(0x45))
						user.append("e");
					if (GetAsyncKeyState(0x46))
						user.append("f");
					if (GetAsyncKeyState(0x47))
						user.append("g");
					if (GetAsyncKeyState(0x48))
						user.append("h");
					if (GetAsyncKeyState(0x49))
						user.append("i");
					if (GetAsyncKeyState(0x4A))
						user.append("j");
					if (GetAsyncKeyState(0x4B))
						user.append("k");
					if (GetAsyncKeyState(0x4C))
						user.append("l");
					if (GetAsyncKeyState(0x4D))
						user.append("m");
					if (GetAsyncKeyState(0x4E))
						user.append("n");
					if (GetAsyncKeyState(0x4F))
						user.append("o");
					if (GetAsyncKeyState(0x50))
						user.append("p");
					if (GetAsyncKeyState(0x51))
						user.append("q");
					if (GetAsyncKeyState(0x52))
						user.append("r");
					if (GetAsyncKeyState(0x53))
						user.append("s");
					if (GetAsyncKeyState(0x54))
						user.append("t");
					if (GetAsyncKeyState(0x55))
						user.append("u");
					if (GetAsyncKeyState(0x56))
						user.append("v");
					if (GetAsyncKeyState(0x57))
						user.append("w");
					if (GetAsyncKeyState(0x58))
						user.append("x");
					if (GetAsyncKeyState(0x59))
						user.append("y");
					if (GetAsyncKeyState(0x5A))
						user.append("z");
					if (GetAsyncKeyState(0x30))
						user.append(")");
					if (GetAsyncKeyState(0x31))
						user.append("!");
					if (GetAsyncKeyState(0x32))
						user.append("@");
					if (GetAsyncKeyState(0x33))
						user.append("#");
					if (GetAsyncKeyState(0x34))
						user.append("$");
					if (GetAsyncKeyState(0x35))
						user.append("%");
					if (GetAsyncKeyState(0x36))
						user.append("^");
					if (GetAsyncKeyState(0x37))
						user.append("&");
					if (GetAsyncKeyState(0x38))
						user.append("*");
					if (GetAsyncKeyState(0x39))
						user.append("(");
				}
				else {
					if (GetAsyncKeyState(0x41))
						user.append("A");
					if (GetAsyncKeyState(0x42))
						user.append("B");
					if (GetAsyncKeyState(0x43))
						user.append("C");
					if (GetAsyncKeyState(0x44))
						user.append("D");
					if (GetAsyncKeyState(0x45))
						user.append("E");
					if (GetAsyncKeyState(0x46))
						user.append("F");
					if (GetAsyncKeyState(0x47))
						user.append("G");
					if (GetAsyncKeyState(0x48))
						user.append("H");
					if (GetAsyncKeyState(0x49))
						user.append("I");
					if (GetAsyncKeyState(0x4A))
						user.append("J");
					if (GetAsyncKeyState(0x4B))
						user.append("K");
					if (GetAsyncKeyState(0x4C))
						user.append("L");
					if (GetAsyncKeyState(0x4D))
						user.append("M");
					if (GetAsyncKeyState(0x4E))
						user.append("N");
					if (GetAsyncKeyState(0x4F))
						user.append("O");
					if (GetAsyncKeyState(0x50))
						user.append("P");
					if (GetAsyncKeyState(0x51))
						user.append("Q");
					if (GetAsyncKeyState(0x52))
						user.append("R");
					if (GetAsyncKeyState(0x53))
						user.append("S");
					if (GetAsyncKeyState(0x54))
						user.append("T");
					if (GetAsyncKeyState(0x55))
						user.append("U");
					if (GetAsyncKeyState(0x56))
						user.append("V");
					if (GetAsyncKeyState(0x57))
						user.append("W");
					if (GetAsyncKeyState(0x58))
						user.append("X");
					if (GetAsyncKeyState(0x59))
						user.append("Y");
					if (GetAsyncKeyState(0x5A))
						user.append("Z");
					if (GetAsyncKeyState(0x30))
						user.append(")");
					if (GetAsyncKeyState(0x31))
						user.append("!");
					if (GetAsyncKeyState(0x32))
						user.append("@");
					if (GetAsyncKeyState(0x33))
						user.append("#");
					if (GetAsyncKeyState(0x34))
						user.append("$");
					if (GetAsyncKeyState(0x35))
						user.append("%");
					if (GetAsyncKeyState(0x36))
						user.append("^");
					if (GetAsyncKeyState(0x37))
						user.append("&");
					if (GetAsyncKeyState(0x38))
						user.append("*");
					if (GetAsyncKeyState(0x39))
						user.append("(");
				}
			}
			else {
				if (GetAsyncKeyState(0x41))
					user.append("a");
				if (GetAsyncKeyState(0x42))
					user.append("b");
				if (GetAsyncKeyState(0x43))
					user.append("c");
				if (GetAsyncKeyState(0x44))
					user.append("d");
				if (GetAsyncKeyState(0x45))
					user.append("e");
				if (GetAsyncKeyState(0x46))
					user.append("f");
				if (GetAsyncKeyState(0x47))
					user.append("g");
				if (GetAsyncKeyState(0x48))
					user.append("h");
				if (GetAsyncKeyState(0x49))
					user.append("i");
				if (GetAsyncKeyState(0x4A))
					user.append("j");
				if (GetAsyncKeyState(0x4B))
					user.append("k");
				if (GetAsyncKeyState(0x4C))
					user.append("l");
				if (GetAsyncKeyState(0x4D))
					user.append("m");
				if (GetAsyncKeyState(0x4E))
					user.append("n");
				if (GetAsyncKeyState(0x4F))
					user.append("o");
				if (GetAsyncKeyState(0x50))
					user.append("p");
				if (GetAsyncKeyState(0x51))
					user.append("q");
				if (GetAsyncKeyState(0x52))
					user.append("r");
				if (GetAsyncKeyState(0x53))
					user.append("s");
				if (GetAsyncKeyState(0x54))
					user.append("t");
				if (GetAsyncKeyState(0x55))
					user.append("u");
				if (GetAsyncKeyState(0x56))
					user.append("v");
				if (GetAsyncKeyState(0x57))
					user.append("w");
				if (GetAsyncKeyState(0x58))
					user.append("x");
				if (GetAsyncKeyState(0x59))
					user.append("y");
				if (GetAsyncKeyState(0x5A))
					user.append("z");
				if (GetAsyncKeyState(0x30))
					user.append("0");
				if (GetAsyncKeyState(0x31))
					user.append("1");
				if (GetAsyncKeyState(0x32))
					user.append("2");
				if (GetAsyncKeyState(0x33))
					user.append("3");
				if (GetAsyncKeyState(0x34))
					user.append("4");
				if (GetAsyncKeyState(0x35))
					user.append("5");
				if (GetAsyncKeyState(0x36))
					user.append("6");
				if (GetAsyncKeyState(0x37))
					user.append("7");
				if (GetAsyncKeyState(0x38))
					user.append("8");
				if (GetAsyncKeyState(0x39))
					user.append("9");
			}
		}
		else {
			if (GetAsyncKeyState(VK_UP))
				userisselected = true;
			if (GetAsyncKeyState(VK_BACK)) {
				if (!pass.empty())
					pass = pass.substr(0, pass.length() - 1);
			}
			if (((GetKeyState(VK_CAPITAL) & 0x0001) != 0) && (!GetAsyncKeyState(VK_SHIFT))) {
				if (GetAsyncKeyState(0x41))
					pass.append("A");
				if (GetAsyncKeyState(0x42))
					pass.append("B");
				if (GetAsyncKeyState(0x43))
					pass.append("C");
				if (GetAsyncKeyState(0x44))
					pass.append("D");
				if (GetAsyncKeyState(0x45))
					pass.append("E");
				if (GetAsyncKeyState(0x46))
					pass.append("F");
				if (GetAsyncKeyState(0x47))
					pass.append("G");
				if (GetAsyncKeyState(0x48))
					pass.append("H");
				if (GetAsyncKeyState(0x49))
					pass.append("I");
				if (GetAsyncKeyState(0x4A))
					pass.append("J");
				if (GetAsyncKeyState(0x4B))
					pass.append("K");
				if (GetAsyncKeyState(0x4C))
					pass.append("L");
				if (GetAsyncKeyState(0x4D))
					pass.append("M");
				if (GetAsyncKeyState(0x4E))
					pass.append("N");
				if (GetAsyncKeyState(0x4F))
					pass.append("O");
				if (GetAsyncKeyState(0x50))
					pass.append("P");
				if (GetAsyncKeyState(0x51))
					pass.append("Q");
				if (GetAsyncKeyState(0x52))
					pass.append("R");
				if (GetAsyncKeyState(0x53))
					pass.append("S");
				if (GetAsyncKeyState(0x54))
					pass.append("T");
				if (GetAsyncKeyState(0x55))
					pass.append("U");
				if (GetAsyncKeyState(0x56))
					pass.append("V");
				if (GetAsyncKeyState(0x57))
					pass.append("W");
				if (GetAsyncKeyState(0x58))
					pass.append("X");
				if (GetAsyncKeyState(0x59))
					pass.append("Y");
				if (GetAsyncKeyState(0x5A))
					pass.append("Z");
				if (GetAsyncKeyState(0x30))
					pass.append("0");
				if (GetAsyncKeyState(0x31))
					pass.append("1");
				if (GetAsyncKeyState(0x32))
					pass.append("2");
				if (GetAsyncKeyState(0x33))
					pass.append("3");
				if (GetAsyncKeyState(0x34))
					pass.append("4");
				if (GetAsyncKeyState(0x35))
					pass.append("5");
				if (GetAsyncKeyState(0x36))
					pass.append("6");
				if (GetAsyncKeyState(0x37))
					pass.append("7");
				if (GetAsyncKeyState(0x38))
					pass.append("8");
				if (GetAsyncKeyState(0x39))
					pass.append("9");
			}
			else if (GetAsyncKeyState(VK_SHIFT)) {
				if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) {
					if (GetAsyncKeyState(0x41))
						pass.append("a");
					if (GetAsyncKeyState(0x42))
						pass.append("b");
					if (GetAsyncKeyState(0x43))
						pass.append("c");
					if (GetAsyncKeyState(0x44))
						pass.append("d");
					if (GetAsyncKeyState(0x45))
						pass.append("e");
					if (GetAsyncKeyState(0x46))
						pass.append("f");
					if (GetAsyncKeyState(0x47))
						pass.append("g");
					if (GetAsyncKeyState(0x48))
						pass.append("h");
					if (GetAsyncKeyState(0x49))
						pass.append("i");
					if (GetAsyncKeyState(0x4A))
						pass.append("j");
					if (GetAsyncKeyState(0x4B))
						pass.append("k");
					if (GetAsyncKeyState(0x4C))
						pass.append("l");
					if (GetAsyncKeyState(0x4D))
						pass.append("m");
					if (GetAsyncKeyState(0x4E))
						pass.append("n");
					if (GetAsyncKeyState(0x4F))
						pass.append("o");
					if (GetAsyncKeyState(0x50))
						pass.append("p");
					if (GetAsyncKeyState(0x51))
						pass.append("q");
					if (GetAsyncKeyState(0x52))
						pass.append("r");
					if (GetAsyncKeyState(0x53))
						pass.append("s");
					if (GetAsyncKeyState(0x54))
						pass.append("t");
					if (GetAsyncKeyState(0x55))
						pass.append("u");
					if (GetAsyncKeyState(0x56))
						pass.append("v");
					if (GetAsyncKeyState(0x57))
						pass.append("w");
					if (GetAsyncKeyState(0x58))
						pass.append("x");
					if (GetAsyncKeyState(0x59))
						pass.append("y");
					if (GetAsyncKeyState(0x5A))
						pass.append("z");
					if (GetAsyncKeyState(0x30))
						pass.append(")");
					if (GetAsyncKeyState(0x31))
						pass.append("!");
					if (GetAsyncKeyState(0x32))
						pass.append("@");
					if (GetAsyncKeyState(0x33))
						pass.append("#");
					if (GetAsyncKeyState(0x34))
						pass.append("$");
					if (GetAsyncKeyState(0x35))
						pass.append("%");
					if (GetAsyncKeyState(0x36))
						pass.append("^");
					if (GetAsyncKeyState(0x37))
						pass.append("&");
					if (GetAsyncKeyState(0x38))
						pass.append("*");
					if (GetAsyncKeyState(0x39))
						pass.append("(");
				}
				else {
					if (GetAsyncKeyState(0x41))
						pass.append("A");
					if (GetAsyncKeyState(0x42))
						pass.append("B");
					if (GetAsyncKeyState(0x43))
						pass.append("C");
					if (GetAsyncKeyState(0x44))
						pass.append("D");
					if (GetAsyncKeyState(0x45))
						pass.append("E");
					if (GetAsyncKeyState(0x46))
						pass.append("F");
					if (GetAsyncKeyState(0x47))
						pass.append("G");
					if (GetAsyncKeyState(0x48))
						pass.append("H");
					if (GetAsyncKeyState(0x49))
						pass.append("I");
					if (GetAsyncKeyState(0x4A))
						pass.append("J");
					if (GetAsyncKeyState(0x4B))
						pass.append("K");
					if (GetAsyncKeyState(0x4C))
						pass.append("L");
					if (GetAsyncKeyState(0x4D))
						pass.append("M");
					if (GetAsyncKeyState(0x4E))
						pass.append("N");
					if (GetAsyncKeyState(0x4F))
						pass.append("O");
					if (GetAsyncKeyState(0x50))
						pass.append("P");
					if (GetAsyncKeyState(0x51))
						pass.append("Q");
					if (GetAsyncKeyState(0x52))
						pass.append("R");
					if (GetAsyncKeyState(0x53))
						pass.append("S");
					if (GetAsyncKeyState(0x54))
						pass.append("T");
					if (GetAsyncKeyState(0x55))
						pass.append("U");
					if (GetAsyncKeyState(0x56))
						pass.append("V");
					if (GetAsyncKeyState(0x57))
						pass.append("W");
					if (GetAsyncKeyState(0x58))
						pass.append("X");
					if (GetAsyncKeyState(0x59))
						pass.append("Y");
					if (GetAsyncKeyState(0x5A))
						pass.append("Z");
					if (GetAsyncKeyState(0x30))
						pass.append(")");
					if (GetAsyncKeyState(0x31))
						pass.append("!");
					if (GetAsyncKeyState(0x32))
						pass.append("@");
					if (GetAsyncKeyState(0x33))
						pass.append("#");
					if (GetAsyncKeyState(0x34))
						pass.append("$");
					if (GetAsyncKeyState(0x35))
						pass.append("%");
					if (GetAsyncKeyState(0x36))
						pass.append("^");
					if (GetAsyncKeyState(0x37))
						pass.append("&");
					if (GetAsyncKeyState(0x38))
						pass.append("*");
					if (GetAsyncKeyState(0x39))
						pass.append("(");
				}
			}
			else {
				if (GetAsyncKeyState(0x41))
					pass.append("a");
				if (GetAsyncKeyState(0x42))
					pass.append("b");
				if (GetAsyncKeyState(0x43))
					pass.append("c");
				if (GetAsyncKeyState(0x44))
					pass.append("d");
				if (GetAsyncKeyState(0x45))
					pass.append("e");
				if (GetAsyncKeyState(0x46))
					pass.append("f");
				if (GetAsyncKeyState(0x47))
					pass.append("g");
				if (GetAsyncKeyState(0x48))
					pass.append("h");
				if (GetAsyncKeyState(0x49))
					pass.append("i");
				if (GetAsyncKeyState(0x4A))
					pass.append("j");
				if (GetAsyncKeyState(0x4B))
					pass.append("k");
				if (GetAsyncKeyState(0x4C))
					pass.append("l");
				if (GetAsyncKeyState(0x4D))
					pass.append("m");
				if (GetAsyncKeyState(0x4E))
					pass.append("n");
				if (GetAsyncKeyState(0x4F))
					pass.append("o");
				if (GetAsyncKeyState(0x50))
					pass.append("p");
				if (GetAsyncKeyState(0x51))
					pass.append("q");
				if (GetAsyncKeyState(0x52))
					pass.append("r");
				if (GetAsyncKeyState(0x53))
					pass.append("s");
				if (GetAsyncKeyState(0x54))
					pass.append("t");
				if (GetAsyncKeyState(0x55))
					pass.append("u");
				if (GetAsyncKeyState(0x56))
					pass.append("v");
				if (GetAsyncKeyState(0x57))
					pass.append("w");
				if (GetAsyncKeyState(0x58))
					pass.append("x");
				if (GetAsyncKeyState(0x59))
					pass.append("y");
				if (GetAsyncKeyState(0x5A))
					pass.append("z");
				if (GetAsyncKeyState(0x30))
					pass.append("0");
				if (GetAsyncKeyState(0x31))
					pass.append("1");
				if (GetAsyncKeyState(0x32))
					pass.append("2");
				if (GetAsyncKeyState(0x33))
					pass.append("3");
				if (GetAsyncKeyState(0x34))
					pass.append("4");
				if (GetAsyncKeyState(0x35))
					pass.append("5");
				if (GetAsyncKeyState(0x36))
					pass.append("6");
				if (GetAsyncKeyState(0x37))
					pass.append("7");
				if (GetAsyncKeyState(0x38))
					pass.append("8");
				if (GetAsyncKeyState(0x39))
					pass.append("9");
			}
		}
	}
	Drawing::DRAW_STRING(user, 4, { 255,255,255,255 }, { UserX , UserY }, { 0.1f, UserYS }, 1, 1, 0);
	Drawing::DRAW_STRING(pass, 4, { 255,255,255,255 }, { UserX , UserY + PassY }, { 0.1f, UserYS }, 1, 1, 0);
	
}
*/