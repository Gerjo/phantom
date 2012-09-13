/*
 * PhantomGame.cpp
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */

#include "PhantomGame.h"

#include <iostream>
#include <ctime>
#ifndef WIN32
#include <sys/time.h>
#include <unistd.h>
#else
#include <Windows.h>
#endif

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
#ifndef WIN32
		usleep( 9000 );
#else
		Sleep( 9 );
#endif
		last = now;

		diff = this->time()-last;
		if( diff < (1.0/this->fps))
#ifndef WIN32
			usleep( ((1.0/this->fps) - diff) * 1000000 );
#else
			Sleep( ((1.0/this->fps) - diff) * 1000.0f );
#endif
	}
	return 0;
}

double PhantomGame::time()
{
#ifndef WIN32
	struct timeval tv;
	gettimeofday(&tv, NULL);

	double total = tv.tv_sec;
	total += tv.tv_usec / 1000000.0;

	return total;
#else
	SYSTEMTIME *lpSystemTime;
	GetLocalTime(lpSystemTime);

	double total = lpSystemTime->wSecond;
	total += lpSystemTime->wMilliseconds / 1000.0;

	return total;
#endif
}


} /* namespace phantom */
