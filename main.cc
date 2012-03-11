#include <iostream>
#include <string>

using namespace std;

#include "SDL/SDL_main.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "aux.hh"
#include "menu.hh"
#include "button.hh"
#include "const.hh"
#include "gameplan.hh"

SDL_Surface *init();
bool initMenu(Menu *menu, TTF_Font *retroFont);


int main(int argc, char* args[]){
  printf("running...\n");
  unsigned char mode = 0;
  SDL_Surface* screen = NULL;
  TTF_Font *retroFont = NULL;

  SDL_Event event;
  bool quit = false;
  int fpsTimer;

  //init SDL
  screen = init();
  if(screen == NULL) return 1;

  //load fonts
  retroFont = TTF_OpenFont( "fonts/Atarian.ttf", 35 );
  if(retroFont == NULL) return 1;
  
  //init menu
  Menu *menu = new Menu(retroFont);
  initMenu(menu, retroFont);

  //init gameplan
  GamePlan *gameplan = new GamePlan(retroFont);

  while( quit == false ) {
    fpsTimer = SDL_GetTicks();

    //Draw the right surface depending on game state
    switch(mode){
    case MENU_MODE:
      //update menu surface
      if(menu->needUpdate()){
	cout<<"updating menu"<<endl;
	menu->updateSurface();
	overWriteSurface(menu->getSurface(), screen);
	SDL_Flip(screen);
      }
      
      break;
    case MODE_GAME_PLAN:
      if(gameplan->needUpdate()){
	gameplan->updateSurface();
	overWriteSurface(gameplan->getSurface(), screen);
	SDL_Flip(screen);
      }
      break;
    case GAME_MODE:
      cout<<"in game"<<endl;
      break;
    }

    //handle events
    while( SDL_PollEvent( &event ) ) {
      switch(event.type){
      case SDL_MOUSEBUTTONDOWN:
	   cout<<"mouse clicked at: ("<<
	     event.button.x<<", "<<event.button.y<<")"<<endl;
	 if(mode == MENU_MODE){
	   switch(menu->getPressedButton(event.button.x,
					 event.button.y)){
	   case BUTTON_STORY_MODE:
	     cout<<"story"<<endl;
	     break;
	   case BUTTON_QUICK_GAME:
	     cout<<"quick"<<endl;
	     mode = MODE_GAME_PLAN;
	     break;
	   case BUTTON_SETTINGS:
	     cout<<"settings"<<endl;
	     break;
	   case BUTTON_ABOUT:
	     cout<<"about"<<endl;
	     break;
	   case BUTTON_QUIT:
	     cout<<"quit"<<endl;
	     quit = true;
	     break;
	   }
	}
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

  SDL_Quit();
  return 0;
}

SDL_Surface *init(){
  SDL_Surface *screen;

  if(SDL_Init( SDL_INIT_EVERYTHING ) == -1){
    return false;
  }
  
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 
			     SCREEN_BPP, SDL_SWSURFACE );

  if( TTF_Init() == -1 ) { 
    return NULL; 
  }

  SDL_WM_SetCaption("WSnake", "WSnake");
  return screen;
}

bool initMenu(Menu *menu, TTF_Font *retroFont){
  menu->addButton(new Button(0, 0, 300, 50, "story mode", 
			     retroFont, BUTTON_STORY_MODE));
  menu->addButton(new Button(0, 0, 300, 50, "quick game", 
			     retroFont, BUTTON_QUICK_GAME));
  menu->addButton(new Button(0, 0, 300, 50, "settings", 
			     retroFont, BUTTON_SETTINGS));
  menu->addButton(new Button(0, 0, 300, 50, "about this game", 
			     retroFont, BUTTON_ABOUT));
  menu->addButton(new Button(0, 20, 300, 50, "QUIT", 
			     retroFont, BUTTON_QUIT));
}
