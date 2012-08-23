/*
 * PhantomGame.h
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */

#ifndef PHANTOMGAME_H_
#define PHANTOMGAME_H_

#include "GameState.h"
#include <core/Composite.h>
#include <vector>

namespace phantom {

class PhantomGame: public Composite {
public:
	PhantomGame( const char *configfile );
	virtual ~PhantomGame();

	void pushGameState( GameState *state );
	void popGameState();

	int main( int argc, char *argv[] );

	void update( float elapsed );
	void render( void *context );

	void exit(int returncode);

    float getHeight() const
    {
        return height;
    }

    float getWidth() const
    {
        return width;
    }

protected:
    virtual void onExit(int returncode);

private:

	unsigned int width;
	unsigned int height;

	unsigned int fps;

	std::vector<GameState*> states;

	double time();

};

} /* namespace phantom */
#endif /* PHANTOMGAME_H_ */
