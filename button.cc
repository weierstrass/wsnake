/* Button*/

#include "button.hh"

Button::Button(int x, int y, int w, int h, string text, 
	       TTF_Font *f, int id){
  bounds.x = x;
  bounds.y = y;
  bounds.w = w;
  bounds.h = h;
  Button::text = text;
  Button::id = id;
  surf = NULL;
  font = f;
  highlighted = false;
}

string Button::getText(){
  return text;
}

SDL_Surface* Button::getSurface(){
  SDL_Surface *buttonText = NULL;

  if(surf == NULL){
    surf = SDL_CreateRGBSurface(SDL_SWSURFACE, 
				bounds.w, bounds.h, 
				32,
				0xff000000,0x00ff0000,
				0x0000ff00,0x00000000);
    SDL_FillRect(surf, NULL, 0x88000ff);

    buttonText = TTF_RenderText_Blended(font, text.c_str(), 
				       BUTTON_TEXT_COLOR);
    if(buttonText == NULL) return NULL;

    //center text on button.
    int xo = (bounds.w - buttonText->w) * 0.5;
    int yo = (bounds.h - buttonText->h) * 0.5;
    applySurface(xo, yo, buttonText, surf);
  }
  return surf;
}

int Button::getID(){
  return id;
}

void Button::setHighlighted(bool b){
  highlighted = b;
}

