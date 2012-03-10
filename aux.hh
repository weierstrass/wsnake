#ifndef _inc_aux_ 
#define _inc_aux_ 

#include <string>
#include "SDL/SDL.h"

using namespace std;

SDL_Surface *loadImage(string filename);
void applySurface(int x, int y, SDL_Surface *fromS, SDL_Surface *toS);
int getWindowWidth();
int getWindowHeight();
#endif
