
#include "gameplan.hh"

GamePlan::GamePlan(TTF_Font *f){
  surf = createSurface(getWindowWidth(), getWindowHeight());
  update = true;
  font = f;
  //readMaps();
}

bool GamePlan::needUpdate(){
  return update;
}

void GamePlan::updateSurface(){
  //clear old contents
  clearSurface(surf);

  //draw title
  SDL_Surface *titleSurf = NULL;  
  titleSurf = TTF_RenderText_Blended(font, MENU_TITLE.c_str(), 
				       MENU_TITLE_COLOR);
  applySurface((getWindowWidth() - titleSurf->w)*0.5 , 
	       MENU_TITLE_TOP_PADDING, titleSurf, surf);
  
  SDL_FreeSurface(titleSurf);
}

SDL_Surface* GamePlan::getSurface(){
  return surf;
}
