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

using namespace Eigen;

namespace phantom {
struct phantomVector{
	float x;
	float y;
public:
	phantomVector(float x, float y){
		this->x = x;
		this->y = y;
	}
};
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
	//virtual void drawLine
private:
    PhantomGame *game;
    SDL_Surface *screen;
	std::vector<phantomVector> vectorList;
	float moveOriginX, moveOriginY;
	Uint32 color;
};

} /* namespace phantom */
#endif /* SDLGRAPHICS_H_ */
