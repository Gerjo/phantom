/*
* SDLGraphics.cpp
*
*  Created on: Aug 23, 2012
*      Author: koen
*/

#include "SDLGraphics.h"
#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>
#include <iostream>
#include <SDL/SDL_draw.h>
namespace phantom {

	SDLGraphics::SDLGraphics()
	{
	}

	SDLGraphics::~SDLGraphics()
	{
		SDL_Quit();
	}

	void SDLGraphics::setup( PhantomGame *game )
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		this->game = game;
		this->screen = SDL_SetVideoMode(game->getWidth(), game->getHeight(),8,SDL_HWSURFACE);
		if ( screen == NULL ) {
			std::cerr << "Unable to set " << game->getWidth() << "x" << game->getHeight() << " video:" << SDL_GetError() << std::endl;
			std::cin.get();
			exit(1);
		}
		color = SDL_MapRGB(screen->format, 255,0,0);
	}

	void SDLGraphics::update( float elapsed )
	{
		Composite::update(elapsed);

		SDL_Event event;
		while( SDL_PollEvent(&event) )
		{
			switch( event.type )
			{
			case SDL_QUIT:
				this->game->exit(0);
				break;
			}
		}
	}

	void SDLGraphics::save()
	{
	}
	void SDLGraphics::restore(){

	}
	void SDLGraphics::drawLine(Eigen::Vector2f from, Eigen::Vector2f to){
		Draw_Line(screen,
			static_cast<Sint16>(from.x()),
			static_cast<Sint16>(from.y()),
			static_cast<Sint16>(to.x()),
			static_cast<Sint16>(to.y()),
			color);
	}
	void SDLGraphics::drawRect(Eigen::Vector2f xy, Eigen::Vector2f wh){
		Draw_Rect(screen,
			static_cast<Sint16>(xy.x()),
			static_cast<Sint16>(xy.y()),
			static_cast<Sint16>(wh.x()),
			static_cast<Sint16>(wh.y()),
			color);
	}
	void SDLGraphics::drawCircle(Eigen::Vector2f xy, float radius){
		Draw_Circle(screen,
			static_cast<Sint16>(xy.x()),
			static_cast<Sint16>(xy.y()),
			static_cast<Sint16>(radius),
			color);
	}
	void SDLGraphics::fill()
	{
		SDL_UpdateRect(screen,0,0,0,0);
	}
	void SDLGraphics::stroke()
	{

	}

	void SDLGraphics::moveTo(float x, float y)
	{

	}
	void SDLGraphics::lineTo(float x, float y)
	{

	}

} /* namespace phantom */
