/*
 * PhantomGame.h
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */

#ifndef PHANTOMGAME_H_
#define PHANTOMGAME_H_

#include "GameState.h"
#include <vector>

namespace phantom {

class PhantomGame {
public:
	PhantomGame( const char *configfile );
	virtual ~PhantomGame();

	void pushGameState( GameState *state );
	void popGameState();

	int main( int argc, char *argv[] );

private:

	unsigned int width;
	unsigned int height;

	unsigned int fps;

	std::vector<GameState*> states;

	double time();

};

} /* namespace phantom */
#endif /* PHANTOMGAME_H_ */
