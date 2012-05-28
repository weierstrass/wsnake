
#include "game.hh"

Game::Game(string path){
  cout<<"creating game "<<path<<endl;

  highlighted = false;
  
  //read file
  ifstream file(path.c_str());
  string line;

  //read title
  getline(file, title);
  //get size of game area
  nx = 0;
  ny = 0;
  if(file.is_open()){
    while(file.good()){
      getline(file, line);
      if(line[0] == '#') continue;
      if(nx < line.length()){
	nx = line.length();
      }
      ny++;
    }
    file.close();
  }

  plan = (char*) calloc(nx*ny, sizeof(char));
  if(plan == NULL){
    //error msg!!
    return;
  }

  //read actual contents
  file.open(path.c_str());
  int j = 0;
  if(file.is_open()){
    while(file.good()){
      getline(file, line);
      if(line[0] == '#') continue;
      for(int i = 0; i < line.length(); i++){
	if((char)line[i] == READ_BLOCK){
	  *(plan + i + j*nx) = GAME_BRICK;
	}
      }
      j++;
    }
    file.close();
  }

  //create thumbnail
  createThumbnail();
}

void Game::createThumbnail(){
  thumbnail = createSurface(GAME_THUMBNAIL_WIDTH + 4, 
			    GAME_THUMBNAIL_HEIGHT + 4);
  
  int bw = GAME_THUMBNAIL_WIDTH / nx;
  int bh = GAME_THUMBNAIL_HEIGHT / ny;
  SDL_Surface *smallBrick = createSurface(bw, bh);

  SDL_FillRect(smallBrick, NULL, 
	       SDL_MapRGB(thumbnail->format, 128, 128, 128));
  
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      if(*(plan + i + j*nx) == GAME_BRICK){
	applySurface(2 + i*bw, 2 + j*bh, smallBrick, thumbnail);
      }
    }
  }
}

bool Game::initGame(){
  surf = createSurface(getWindowWidth(), getWindowHeight());
  font = TTF_OpenFont( "fonts/Atarian.ttf", 25);
  SDL_Surface *titleSurf = NULL;
  titleSurf = TTF_RenderText_Blended(font, title.c_str(), 
				     MENU_TITLE_COLOR);
  if(titleSurf == NULL) return false;
  applySurface(10, 10, titleSurf, surf);  


  int bw = getWindowWidth() / nx;
  int bh = (getWindowHeight() - GAME_TOP_PADDING) / ny;
  SDL_Surface *smallBrick = createSurface(bw, bh);

  SDL_FillRect(smallBrick, NULL, 
	       SDL_MapRGB(thumbnail->format, 128, 128, 128));

  //add bricks
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      if(*(plan + i + j*nx) == GAME_BRICK){
	applySurface(i*bw, GAME_TOP_PADDING + j*bh, 
		     smallBrick, surf);
      }      
    }
  }

  update = true;

  return true;
}

void Game::updateSurface(){
  
  update = false;
}

bool Game::needUpdate(){
  return update;
}

SDL_Surface* Game::getSurface(){
  return surf;
}

SDL_Surface* Game::getThumbnail(){
  return thumbnail;
}

void Game::setParentBounds(int x, int y, int w, int h){
  parentBounds.x = x;
  parentBounds.y = y;
  parentBounds.w = w;
  parentBounds.h = h;
}

SDL_Rect Game::getParentBounds(){
  return parentBounds;
}

void Game::setHighlighted(bool b){
  highlighted = b;
}

bool Game::getHighlighted(){
  return highlighted;
}

