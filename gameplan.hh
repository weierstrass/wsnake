#ifndef _inc_gameplan_
#define _inc_gameplan_

#include <iostream>
#include <list>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "game.hh"
#include "aux.hh"

class GamePlan{
private:
  bool update;
  void readMaps();
  list<Game> games;
  SDL_Surface *surf;
  TTF_Font *font;
public:
  GamePlan(TTF_Font *f);
  SDL_Surface *getSurface();
  void updateSurface();
  bool needUpdate();
};

#endif
