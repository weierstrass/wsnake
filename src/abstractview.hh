/*
 * abstractview.hh - wsnake
 *
 * Andreas Bülling, 2012
 *
 */

#ifndef ABSTRACTVIEW_HH_
#define ABSTRACTVIEW_HH_

using namespace std;

#include <iostream>
#include <list>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "aux.hh"
#include "const.hh"
#include "button.hh"


class AbstractView{
protected:
	bool update;
	SDL_Surface *surf;
	TTF_Font *font;
	TTF_Font *smallfont;
	list<Button> buttons;
	void drawButtons();
	void drawTitle(string title);
public:
	AbstractView(TTF_Font *f);
	virtual ~AbstractView();
	SDL_Surface* getSurface();
	bool needUpdate();
	void setDirty();
	virtual void updateSurface() = 0;
	int getPressedButton(int x, int y);
	void updateHover(int x, int y);
};

#endif /* ABSTRACTVIEW_HH_ */
