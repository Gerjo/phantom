/*
 * SDLGraphics.cpp
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#include "SDLGraphics.h"
#include <SDL/SDL.h>
#include <iostream>

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
    this->screen = SDL_SetVideoMode(game->getWidth(), game->getHeight(), 16, SDL_HWSURFACE);
    if ( screen == NULL ) {
        std::cerr << "Unable to set " << game->getWidth() << "x" << game->getHeight() << " video:" << SDL_GetError() << std::endl;
        exit(1);
    }
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
