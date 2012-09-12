/*
 * PhantomGame.cpp
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */

#include "PhantomGame.h"

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

namespace phantom {

PhantomGame::PhantomGame(const char *configfile) {
	this->fps = 60;
}

PhantomGame::~PhantomGame() {
}

void PhantomGame::pushGameState(GameState *state)
{
	this->states.push_back(state);
}
void PhantomGame::popGameState()
{
	this->states.pop_back();
}

int PhantomGame::main(int argc, char *argv[] )
{
	double last = this->time();
	while(1)
	{
		double now = this->time();
		double diff = now-last;
		std::cout << diff << std::endl;
		std::vector<GameState*>::reverse_iterator iter;
		iter = this->states.rend();
		while( iter != this->states.rbegin() )
		{
			(*iter)->update(diff);
			if( iter == this->states.rbegin() || !(*iter)->propegateUpdate )
				break;
			--iter;
		}
		iter = this->states.rend();
		while( iter != this->states.rbegin() && (*iter)->transparent)
			--iter;
		while( iter != this->states.rend() )
		{
			(*iter)->render(NULL);
			++iter;
		}

		usleep( 9000 );
		last = now;

		diff = this->time()-last;
		if( diff < (1.0/this->fps))
			usleep( ((1.0/this->fps) - diff) * 1000000 );
	}
	return 0;
}

double PhantomGame::time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	double total = tv.tv_sec;
	total += tv.tv_usec / 1000000.0;

	return total;
}


} /* namespace phantom */
