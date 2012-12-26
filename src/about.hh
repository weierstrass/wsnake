/*
 * about.hh
 *
 *  Created on: Dec 26, 2012
 *      Author: andreas
 */

#ifndef ABOUT_HH_
#define ABOUT_HH_

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "aux.hh"
#include "const.hh"
#include "abstractview.hh"

class About : public AbstractView{
public:
	About(TTF_Font *f);
	virtual ~About();
	void updateSurface();
};

#endif /* ABOUT_HH_ */
