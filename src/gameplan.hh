#ifndef _inc_gameplan_
#define _inc_gameplan_

using namespace std;

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "game.hh"
#include "aux.hh"
#include "button.hh"

class GamePlan{
private:
  bool update;
  bool loadMaps();
  Game *readMap(string path);
  list<Game> games;
  SDL_Surface *surf;
  TTF_Font *font;
  Button *backButton;
public:
  GamePlan(TTF_Font *f);
  SDL_Surface *getSurface();
  void updateSurface();
  bool needUpdate();
  void updateHover(int x, int y);
  void setDirty();
  Game *getPressedGame(int x, int y);
  int getPressedButton(int x, int y);
};

#endif
