/*
 * about.cc - wsnake
 *
 *  Created on: Dec 26, 2012
 *      Author: andreas
 */

#include "about.hh"

const string TITLE_ABOUT  = "ABOUT";

About::About(TTF_Font *f) : AbstractView(f) {
	Button *backButton = new Button((getWindowWidth() - BUTTON_DEF_WIDTH)*0.5,
			getWindowHeight() - BUTTON_DEF_HEIGHT - BUTTON_DEF_MARGIN,
			BUTTON_DEF_WIDTH, BUTTON_DEF_HEIGHT, "<< Back to main menu",
			font, BUTTON_ABOUT_BACK);
	buttons.push_back(*backButton);
}

About::~About() {
	// TODO Auto-generated destructor stub
}

void About::updateSurface(){
	cout<<"updating about"<<endl;

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
	drawTitle(TITLE_ABOUT);

	//draw text
	SDL_Surface *textSurf = NULL;
	getTextSurf(textSurf, smallfont, "Created by Andreas Bulling\n"\
			"andreas.bulling[at]gmail.com\n\n"\
			"System requirements:\n"\
			"300 MHz CPU"\
			"16 MB RAM");
	applySurface(100, 100, textSurf, surf);
	SDL_FreeSurface(textSurf);

	drawButtons();

	update = false;
}

