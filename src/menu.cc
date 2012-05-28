/*Class representing the menu mode. */

#include "menu.hh"


Menu::Menu(TTF_Font *f){
  update = true;
  surf = NULL;
  font = f;
}

SDL_Surface* Menu::getSurface(){
  return surf;
}

void Menu::addButton(Button* button){
  Menu::buttons.push_back(*button);
}

bool Menu::needUpdate(){
  return update;
}

void Menu::updateSurface(){
  int ww = getWindowWidth();
  int wh = getWindowHeight();

  //create surface if not done before
  if(surf == NULL){
    SDL_Surface* curSurface = SDL_GetVideoSurface();
    surf = SDL_CreateRGBSurface(SDL_SWSURFACE, 
				ww, wh, 32,
				0xff000000,0x00ff0000,
				0x0000ff00,0x00000000);
  }else{
    clearSurface(surf);
  }

  //draw title
  SDL_Surface *titleSurf = NULL;  
  titleSurf = TTF_RenderText_Blended(font, MENU_TITLE.c_str(), 
				       MENU_TITLE_COLOR);
  applySurface((ww - titleSurf->w)*0.5 , 
	       MENU_TITLE_TOP_PADDING, titleSurf, surf);

  //draw buttons
  int yOffset = MENU_TOP_PADDING;
  int xOffset = 0;
  for(list<Button>::iterator it = buttons.begin(); 
      it != buttons.end(); it++ ){
    SDL_Surface *temp = it->getSurface();
    xOffset = (ww - it->bounds.w)*0.5;
    //yOffset += it->bounds.y;
    (*it).bounds.x = xOffset;
    (*it).bounds.y = yOffset;
    applySurface(xOffset, yOffset, temp, surf);
    yOffset += it->bounds.h + MENU_VERTICAL_SPACING;
  }
  
  update = false;
}

void Menu::updateHover(int x, int y){
  SDL_Rect r;
  for(list<Button>::iterator it = buttons.begin(); 
      it != buttons.end(); it++ ){
    r = (*it).bounds;
    if(isInside(r, x, y)){
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

int Menu::getPressedButton(int x, int y){
  int ww = getWindowWidth();  
  int yo = MENU_TOP_PADDING;
  int xo = 0;

  for(list<Button>::iterator it = buttons.begin(); 
      it != buttons.end(); it++){
    
    xo = (ww - it->bounds.w)*0.5;
    //yo += it->bounds.y;
    
    //coord on button!
    if(x > xo && x < (xo + it->bounds.w) && 
       y > yo && y < (yo + it->bounds.h)){
      it->setHighlighted(true);
      return it->getID();
    }
    it->setHighlighted(false);
    yo += it->bounds.h + MENU_VERTICAL_SPACING;
  }

  return -1;
}
