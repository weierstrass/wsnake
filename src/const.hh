#ifndef _inc_const_
#define _inc_const_

using namespace std;

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>

const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480; 
const int SCREEN_BPP = 32;
const int FPS = 20;

const int MENU_VERTICAL_SPACING = 20;
const int MENU_TOP_PADDING = 100;
const int MENU_TITLE_TOP_PADDING = 30;
const string MENU_TITLE = "WSNAKE";

const SDL_Color MENU_TITLE_COLOR = {255, 255, 255};
const SDL_Color MENU_BORDER_COLOR = {255, 255, 255};
const SDL_Color BUTTON_TEXT_COLOR = {255, 255, 255};

const unsigned char MENU_MODE = 0; //old to be removed
const unsigned char MODE_MENU = 0;
const unsigned char GAME_MODE = 1; //old to be removed
const unsigned char MODE_GAME = 1;
const unsigned char MODE_GAME_PLAN = 2;
const unsigned char MODE_ABOUT = 3;

const int BUTTON_STORY_MODE = 0;
const int BUTTON_QUICK_GAME = 1;
const int BUTTON_SETTINGS = 2;
const int BUTTON_ABOUT = 3;
const int BUTTON_QUIT = 4;
const int BUTTON_GAME_PLAN_BACK = 10;
const int BUTTON_ABOUT_BACK = 11;

const int BUTTON_DEF_HEIGHT = 50;
const int BUTTON_DEF_WIDTH = 300;
const int BUTTON_DEF_MARGIN = 20;

const unsigned char READ_BLOCK = 'x';
const unsigned char GAME_BRICK = 'x';

const int GAME_THUMBNAIL_WIDTH = 128;
const int GAME_THUMBNAIL_HEIGHT = 86;

const int GAME_PLAN_TOP_PADDING = 150;
const int GAME_PLAN_LEFT_PADDING = 50;
const int GAME_PLAN_TB_MARGIN = 10;

const int GAME_TOP_PADDING = 50;

#endif
