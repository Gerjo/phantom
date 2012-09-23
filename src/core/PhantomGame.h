/*
 * PhantomGame.h
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */

#ifndef PHANTOMGAME_H_
#define PHANTOMGAME_H_

#include <core/GameState.h>
#include <core/Composite.h>
#include <vector>
#include <CompileConfig.h>

namespace phantom {

class LIBEXPORT PhantomGame : public Composite {
public:
	PhantomGame( const char *configfile );
	virtual ~PhantomGame();

	void pushGameState( GameState *state );
	void popGameState();

	int start( int argc, char *argv[] );

	void update( float elapsed );
	void render( void *context );

	void exit(int returncode);

    unsigned int getHeight() const
    {
        return height;
    }

    unsigned int getWidth() const
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
