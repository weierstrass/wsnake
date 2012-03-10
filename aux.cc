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

/*Blits the surface to the destination surface at pos (x,y)*/
void applySurface(int x, int y, SDL_Surface *fromS, SDL_Surface *toS){
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface(fromS, NULL, toS, &offset);
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
