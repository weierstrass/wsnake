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
				0x0000ff00,0x000000ff);
  }

  //draw buttons
  int yOffset = MENU_TOP_PADDING;
  int xOffset = 0;
  for(list<Button>::iterator it = buttons.begin(); 
      it != buttons.end(); it++ ){
    SDL_Surface *temp = it->getSurface();
    xOffset = (ww - it->bounds.w)*0.5;
    yOffset += it->bounds.y;
    applySurface(xOffset, yOffset, temp, surf);
    yOffset += it->bounds.h + MENU_VERTICAL_SPACING;
  }
  
  update = false;
}

int Menu::getPressedButton(int x, int y){
  int ww = getWindowWidth();  
  int yo = MENU_TOP_PADDING;
  int xo = 0;

  for(list<Button>::iterator it = buttons.begin(); 
      it != buttons.end(); it++){
    
    xo = (ww - it->bounds.w)*0.5;
    yo += it->bounds.y;
    
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
