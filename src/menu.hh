
#ifndef _inc_menu_
#define _inc_menu_

using namespace std;

#include <iostream>
#include <list>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "button.hh"
#include "aux.hh"
#include "const.hh"

class Menu{
private:
  SDL_Surface *surf;
  list<Button> buttons;
  int bgcolor;
  bool update;
  TTF_Font *font;
public:
  Menu(TTF_Font *f);
  SDL_Surface* getSurface();
  void addButton(Button *button);
  bool needUpdate();
  void setDirty();
  void updateSurface();
  void updateHover(int x, int y);
  int getPressedButton(int x, int y);
};

#endif
