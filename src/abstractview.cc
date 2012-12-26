/*
 * abstractview.cc - wsnake
 *
 * Andreas Bülling, 2012
 *
 */

#include "abstractview.hh"

AbstractView::AbstractView(TTF_Font *f) {
	update = true;
	surf = NULL;
	font = f;
	smallfont = TTF_OpenFont( "../fonts/c64.ttf", 11 );
}

SDL_Surface* AbstractView::getSurface(){
	return surf;
}

bool AbstractView::needUpdate(){
	return update;
}

void AbstractView::setDirty(){
	update = true;
}

AbstractView::~AbstractView() {
	delete[] surf;
}

int AbstractView::getPressedButton(int x, int y){
	int ww = getWindowWidth();
	int yo = MENU_TOP_PADDING;
	int xo = 0;

	for(list<Button>::iterator it = buttons.begin();
			it != buttons.end(); it++){

		xo = it->bounds.x;
		yo = it->bounds.y;

		//coord on button!
		if(x > xo && x < (xo + it->bounds.w) &&
				y > yo && y < (yo + it->bounds.h)){
			it->setHighlighted(true);
			return it->getID();
		}
		it->setHighlighted(false);
	}

	return -1;
}

void AbstractView::drawButtons(){
	int ww = getWindowWidth();
	int wh = getWindowHeight();

	for(list<Button>::iterator it = buttons.begin();
			it != buttons.end(); it++ ){
		applySurface(it->bounds.x, it->bounds.y, it->getSurface(), surf);
	}
}

void AbstractView::updateHover(int x, int y){
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

void AbstractView::drawTitle(string title){
	int ww = getWindowWidth();
	int wh = getWindowHeight();

	SDL_Surface *titleSurf = NULL;
	titleSurf = TTF_RenderText_Blended(font, title.c_str(),
			MENU_TITLE_COLOR);
	applySurface((ww - titleSurf->w)*0.5 ,
			MENU_TITLE_TOP_PADDING, titleSurf, surf);
	SDL_FreeSurface(titleSurf);
}
