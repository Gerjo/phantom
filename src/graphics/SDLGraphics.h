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
#include <SDL/SDL_draw.h>
#include <iostream>

using namespace Eigen;

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
	virtual void draw();

	virtual void moveTo(float x, float y);
    virtual void lineTo(float x, float y);
	virtual void drawLine(Vector2f from, Vector2f to);
	virtual void drawRect(Vector2f xy, Vector2f wh);
	virtual void drawCircle(Vector2f xy, float radius);

	virtual void checkBounds(Sint16 x, Sint16 y);
private:
    PhantomGame *game;
    SDL_Surface *screen;

	float moveOriginX, moveOriginY;
	Uint32 color;
};

} /* namespace phantom */
#endif /* SDLGRAPHICS_H_ */
