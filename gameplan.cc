
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
  cout<<"updating game plan"<<endl;
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
  SDL_Rect r;
  Uint32 color;
  for(list<Game>::iterator it = games.begin();
      it != games.end(); it++){
    tbn = it->getThumbnail();
    r = it->getParentBounds();
    //draw border
    if(it->getHighlighted()){
      color =  SDL_MapRGB(tbn->format, 0, 255, 0);
    }else{
      color =  SDL_MapRGB(tbn->format, 255, 255, 255);
    }
    drawBorder(tbn, 1, color);

    applySurface(r.x, r.y, tbn, surf);
  }

  update = false;
}

SDL_Surface* GamePlan::getSurface(){
  return surf;
}

bool GamePlan::loadMaps(){
  cout<<"loading maps"<<endl;
  stringstream ss;
  int xo = GAME_PLAN_LEFT_PADDING;
  int yo = GAME_PLAN_TOP_PADDING;
  int col = 1;

  for(int i = 1; i < 100; i++, col++){
    ss<<"maps/"<<i<<"/map.wsm";
    //check if file exists
    if(SDL_RWFromFile(ss.str().c_str(), "r") == NULL){
      break;
    }
    Game *g = new Game(ss.str());
    
    g->setParentBounds(xo, yo, 
		       GAME_THUMBNAIL_WIDTH,
		       GAME_THUMBNAIL_HEIGHT);
    xo += GAME_THUMBNAIL_WIDTH + GAME_PLAN_TB_MARGIN;
    if(col % 4 == 0){
      yo += GAME_THUMBNAIL_HEIGHT + GAME_PLAN_TB_MARGIN;
      xo = GAME_PLAN_LEFT_PADDING;
    }
    
    GamePlan::games.push_back(*g);
    ss.str("");
  }

  return true;
}

void GamePlan::updateHover(int x, int y){
  SDL_Rect r;

  for(list<Game>::iterator it = games.begin();
      it != games.end(); it++){
    r = it->getParentBounds();
    
    //check if mouse is over one thumbnail
    if(x > r.x && x < (r.x + r.w) && 
       y > r.y && y < (r.y + r.h)){
      if(!it->getHighlighted()){
	it->setHighlighted(true);
	update = true;
      }
    }else if(it->getHighlighted()){
      it->setHighlighted(false);
      update = true;
    }
  }
}

Game* GamePlan::getPressedGame(int x, int y){
  SDL_Rect r;

  for(list<Game>::iterator it = games.begin();
      it != games.end(); it++){
    r = it->getParentBounds();
    
    //check if mouse is over one thumbnail
    if(x > r.x && x < (r.x + r.w) && 
       y > r.y && y < (r.y + r.h)){
      //Game &g = *it;
      return &(*it);
    }
  }
  return NULL;
}

Game* GamePlan::readMap(string path){

}
