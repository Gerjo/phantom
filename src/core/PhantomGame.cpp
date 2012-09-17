/*
 * PhantomGame.cpp
 *
 *  Created on: Aug 22, 2012
 *      Author: koen & nico & sander & gerjo
 */

#include "PhantomGame.h"
#include <iostream>
#include <ctime>
#include <phantom.h>

namespace phantom {

PhantomGame::PhantomGame(const char *configfile) : width(640), height(480), fps(60){
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
		double elapsed = now-last;
		std::cout << elapsed << std::endl;

		this->update(elapsed);
		this->render(NULL);

		last = now;
		elapsed = this->time()-last;
		if( elapsed < (1.0/this->fps))
			phantom_sleep(((1.0/this->fps) - elapsed) * 1000.0f);
	}
	return 0;
}

void PhantomGame::update( float elapsed )
{
    Composite::update( elapsed );
    std::vector<GameState*>::reverse_iterator iter;
    iter = this->states.rend();
    while( iter != this->states.rbegin() )
    {
        (*iter)->update(elapsed);
        if( iter == this->states.rbegin() || !(*iter)->propegateUpdate )
            break;
        --iter;
    }
}

void PhantomGame::render( void *context )
{
    std::vector<GameState*>::reverse_iterator iter;
    iter = this->states.rend();
    while( iter != this->states.rbegin() && (*iter)->transparent)
        --iter;
    while( iter != this->states.rend() )
    {
        (*iter)->render(NULL);
        ++iter;
    }
}

void PhantomGame::exit( int returncode )
{
    this->onExit( returncode );
    exit( returncode );
}

void PhantomGame::onExit( int returncode )
{
}

double PhantomGame::time()
{
#ifndef WIN32
	struct timeval tv;
	gettimeofday(&tv, NULL);

	double total = tv.tv_sec;
	total += tv.tv_usec / 1000000.0;
#else
	SYSTEMTIME *lpSystemTime = new SYSTEMTIME();
	GetLocalTime(lpSystemTime);

	double total = lpSystemTime->wSecond;
	total += lpSystemTime->wMilliseconds / 1000.0;
#endif
	return total;
}


} /* namespace phantom */
