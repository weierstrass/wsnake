#include <iostream>
#include <string>

using namespace std;

#include "SDL/SDL_main.h"
#include "SDL/SDL.h"
#include "aux.hh"

const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480; 
const int SCREEN_BPP = 32;
const int FPS = 20;

const unsigned char MENU_MODE = 0;
const unsigned char GAME_MODE = 1;

bool init(SDL_Surface *screen);

int main(int argc, char* args[]){
  printf("tjena grabbar\n");
  unsigned char mode = 0;
  SDL_Surface* screen = NULL;
  SDL_Surface* bg = NULL;
  SDL_Surface* fg = NULL;
  
  SDL_Event event;
  bool quit = false;
  int fpsTimer;
  
  //if(init(screen) == false) return 1;
  if(SDL_Init( SDL_INIT_EVERYTHING ) == -1){
    return false;
  }
  
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 
			     SCREEN_BPP, SDL_SWSURFACE );
  if(screen == NULL) return false;

  SDL_WM_SetCaption("WSnake", "WSnake");

  //end init

  // cout<<"screen"<<screen<<endl;
//   if(screen == NULL) cout<<"null"<<endl;
//   cout<<"bb"<<endl;
  fg = loadImage("img/apple.bmp");
  applySurface(0, 0, fg, screen);
  SDL_Flip( screen );

  while( quit == false ) {
    fpsTimer = SDL_GetTicks();

    //Draw the right surface depending on in 
    //which state the game is.
    switch(mode){
    case MENU_MODE:
      cout<<"in menu"<<endl;
      break;
    case GAME_MODE:
      cout<<"in game"<<endl;
      break;
    }

    while( SDL_PollEvent( &event ) ) {
      switch(event.type){
      case SDL_MOUSEBUTTONDOWN:
	cout<<"mouse clicked at: ("<<event.button.x<<", "<<event.button.y<<")"<<endl;
	break;
      }
    }

    //Did the user close the window?
    if( event.type == SDL_QUIT ) {
      quit = true; 
    }
    
    //Regulate frame rate to FPS const.
    if((SDL_GetTicks() - fpsTimer) < 1000 / FPS){ 
      SDL_Delay( ( 1000 / FPS ) - 
		 (SDL_GetTicks() - fpsTimer) ); 
    }
  }
  
  SDL_FreeSurface( fg );
  SDL_FreeSurface( bg );
  SDL_Quit();
  return 0;
}

bool init(SDL_Surface *screen){
  if(SDL_Init( SDL_INIT_EVERYTHING ) == -1){
    return false;
  }
  
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 
			     SCREEN_BPP, SDL_SWSURFACE );
  if(screen == NULL) return false;

  SDL_WM_SetCaption( "WSnake", "WSnake" );

  return true;
}
