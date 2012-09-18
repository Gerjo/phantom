/*
 * SDLGraphics.cpp
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#include "SDLGraphics.h"
#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>
#include <stdlib.h>
#include <Windows.h>
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
	Draw_FillCircle(screen, 150,150, 100, SDL_MapRGB(screen->format, 255,0,0));
	SDL_UpdateRect(screen, 0, 0, 0, 0);
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
    
     Draw_Circle(screen, 10, 10, 10, SDL_MapRGB(screen->format, 255, 100, 100));
     std::cout << "draw" << std::endl;
}

void SDLGraphics::save()
{
}
void SDLGraphics::restore()
{
}

void SDLGraphics::fill()
{
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
