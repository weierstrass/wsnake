/*Auxilary routines*/

#include "aux.hh"

/*Loads image from file and convert it to proper format*/
SDL_Surface *loadImage(string filename){
  SDL_Surface *newImage = NULL;
  SDL_Surface *retImage = NULL;

  newImage = SDL_LoadBMP(filename.c_str());

  if(newImage != NULL){
    retImage = SDL_DisplayFormat(newImage);
    SDL_FreeSurface(newImage);
  }

  return retImage;
}

/*Creates a new RGB surface, note: alpha mask = 0*/
SDL_Surface *createSurface(int w, int h){
  SDL_Surface *retSurface = NULL;
  retSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, 
				    w, h, SCREEN_BPP,
				    0xff000000,0x00ff0000,
				    0x0000ff00,0x00000000);
  return retSurface;
}

/*Blits the surface to the destination surface at pos (x,y)*/
void applySurface(int x, int y, SDL_Surface *fromS, SDL_Surface *toS){
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface(fromS, NULL, toS, &offset);
}

/*Overwrite surface with new one*/

void overWriteSurface(SDL_Surface *fromS, SDL_Surface *toS){
  clearSurface(toS);
  applySurface(0, 0, fromS, toS);
}

void clearSurface(SDL_Surface *surf){
  SDL_FillRect(surf, NULL,
	       SDL_MapRGB(surf->format, 0, 0, 0));  
}

/*returns the width of the current window*/
int getWindowWidth(){
  if(SDL_GetVideoSurface() == NULL){
    return -1;
  }
  return SDL_GetVideoSurface()->w;
}

/*returns the height of the current window*/
int getWindowHeight(){
  if(SDL_GetVideoSurface() == NULL){
    return -1;
  }
  return SDL_GetVideoSurface()->h;
}
