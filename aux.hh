#ifndef _inc_aux_ 
#define _inc_aux_ 

using namespace std;

#include <string>
#include "SDL/SDL.h"
#include "const.hh"


SDL_Surface *loadImage(string filename);
void applySurface(int x, int y, SDL_Surface *fromS, SDL_Surface *toS);
SDL_Surface *createSurface(int w, int h);
int getWindowWidth();
int getWindowHeight();
#endif
