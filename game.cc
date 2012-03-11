
#include "game.hh"

Game::Game(string path){
  cout<<"creating game "<<path<<endl;

  //read file
  ifstream file(path.c_str());
  string line;

  //get size of game area
  nx = 0;
  ny = 0;
  if(file.is_open()){
    while(file.good()){
      getline(file, line);
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
  cout<<"bw: "<<bw<<", bh: "<<bh<<endl;
  cout<<"nx: "<<nx<<", ny: "<<ny<<endl;
  SDL_Surface *smallBrick = createSurface(bw, bh);

  SDL_FillRect(smallBrick, NULL, SDL_MapRGB(thumbnail->format, 255, 0, 0));
  
  //draw border
  drawBorder(thumbnail, 1, SDL_MapRGB(thumbnail->format, 255, 255, 255));
  
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      if(*(plan + i + j*nx) == GAME_BRICK){
	//cout<<"brick on: ("<<i*bw<<", "<<j*bh<<endl;
	applySurface(2 + i*bw, 2 + j*bh, smallBrick, thumbnail);
      }
    }
  }
}

SDL_Surface* Game::getThumbnail(){
  return thumbnail;
}
