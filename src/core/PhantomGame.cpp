/*
* PhantomGame.cpp
*
*  Created on: Aug 22, 2012
*      Author: koen & nico & sander & gerjo
*/

#include "PhantomGame.h"
#include <graphics\GLUTDriver.h>
#include <iostream>
#include <ctime>
#include <phantom.h>


namespace phantom {

    PhantomGame::PhantomGame(const char *configfile) : width(1280), height(800), fps(60){
        
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

    int PhantomGame::start(int argc, char *argv[], BaseDriver *driver )
    {
        driver->setGame(this);
        double last = this->time();
        while(1)
        {
            double now = this->time();
            double elapsed = now-last;

            //std::cout << elapsed << std::endl;

            //this->update(static_cast<float>(elapsed));
            driver->onUpdate(static_cast<float>(elapsed));
            renderer->renderLoop(&states);

            last = now;
            elapsed = this->time()-last;
            if(elapsed < (1.0f/this->fps))
                phantom::Util::sleep(((1.0f/this->fps) - static_cast<float>(elapsed)) * 1000.0f);
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

    void PhantomGame::exit( int returncode )
    {
        this->onExit( returncode );
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

        delete lpSystemTime;
#endif
        return total;
    }


} /* namespace phantom */
