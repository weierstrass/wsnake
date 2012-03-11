#ifndef _inc_game_
#define _inc_game_

#include <iostream>
#include <List>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "aux.hh"

class Game{
private:
  bool update;
  SDL_Surface *surf;
public:
  Game();
  SDL_Surface *getSurface();
  bool needUpdate();
};

#endif
