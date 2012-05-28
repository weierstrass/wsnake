
#ifndef _inc_button_
#define _inc_button_

using namespace std;

#include <string>
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "const.hh"
#include "aux.hh"

class Button{
private:
  string text;
  SDL_Surface *surf;
  TTF_Font *font;
  int id;
  bool highlighted;
public:
  SDL_Rect bounds;
  Button(int x, int y, int w, int h, string text, 
	 TTF_Font *f, int id);
  SDL_Surface* getSurface();
  string getText();
  int getID();
  void setHighlighted(bool b);
  bool getHighlighted();
};

#endif
