
#include "gameplan.hh"

GamePlan::GamePlan(TTF_Font *f){
  surf = createSurface(getWindowWidth(), getWindowHeight());
  update = true;
  font = f;
  if(!loadMaps()){
    //error msg here
  }
}

bool GamePlan::needUpdate(){
  return update;
}

void GamePlan::updateSurface(){
  //clear old contents
  clearSurface(surf);

  //draw title
  SDL_Surface *titleSurf = NULL;  
  titleSurf = TTF_RenderText_Blended(font, "QUICK GAME", 
				       MENU_TITLE_COLOR);
  applySurface((getWindowWidth() - titleSurf->w)*0.5 , 
	       MENU_TITLE_TOP_PADDING, titleSurf, surf);
  
  SDL_FreeSurface(titleSurf);

  //draw thumbnails of maps
  SDL_Surface *tbn;
  int xo = GAME_PLAN_LEFT_PADDING;
  int yo = GAME_PLAN_TOP_PADDING;
  int col = 1;
  for(list<Game>::iterator it = games.begin();
      it != games.end(); it++, col++){
    tbn = it->getThumbnail();
    applySurface(xo, yo, tbn, surf);
    xo += tbn->w + GAME_PLAN_TB_MARGIN;
    if(col % 4 == 0){
      yo += tbn->h + GAME_PLAN_TB_MARGIN;
      xo = GAME_PLAN_LEFT_PADDING;
    }
  }

  update = false;
}

SDL_Surface* GamePlan::getSurface(){
  return surf;
}

bool GamePlan::loadMaps(){
  cout<<"loading maps"<<endl;
  stringstream ss;

  for(int i = 1; i < 100; i++){
    ss<<"maps/"<<i<<"/map.wsm";
    //check if file exists
    if(SDL_RWFromFile(ss.str().c_str(), "r") == NULL){
      break;
    }
    Game *g = new Game(ss.str());
    GamePlan::games.push_back(*g);
    ss.str("");
  }

  return true;
}

Game* GamePlan::readMap(string path){

}
