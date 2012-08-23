/*
 * SDLGraphics.h
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#ifndef SDLGRAPHICS_H_
#define SDLGRAPHICS_H_

#include <graphics/Graphics.h>
#include <SDL/SDL.h>

namespace phantom {

class SDLGraphics: public Graphics
{
public:
    SDLGraphics();
    virtual ~SDLGraphics();

    void setup(PhantomGame *game);

    void update( float elapsed );

    virtual void save();
    virtual void restore();

    virtual void fill();
    virtual void stroke();

    virtual void moveTo(float x, float y);
    virtual void lineTo(float x, float y);
private:
    PhantomGame *game;
    SDL_Surface *screen;
};

} /* namespace phantom */
#endif /* SDLGRAPHICS_H_ */
