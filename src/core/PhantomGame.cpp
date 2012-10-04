#include "PhantomGame.h"
#include <iostream>
#include <ctime>
#include <phantom.h>
#include <core/Driver.h>

namespace phantom {

    PhantomGame::PhantomGame(const char *configfile) : width(800), height(450), fps(63){

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

    int PhantomGame::start(int argc, char *argv[], Driver *driver )
    {
        driver->setGame(this);
        double last = this->time();
        float total = 0.0f;
        float fpscount = 0.0f;

        while(1) {
            double now     = this->time();
            double elapsed = now - last;

            driver->onUpdate(elapsed);
            camera->update(elapsed);
            renderer->renderLoop(&states);

            if(elapsed < (1.0f/this->fps)) {
                phantom::Util::sleep(ceil(((1.0f/this->fps) - elapsed) * 1000.0f));
            }

            total += elapsed;
            fpscount++;

            if(total >= 1) {
                stringstream stream;
                stream << "Phantom [Avg FPS: " << fpscount << " Cur FPS: " << 1/elapsed << "]" << endl;
                renderer->setWindowTitle(stream.str());
                fpscount = 0;
                total = 0;
            }

            last = now;
        }
        return 0;
    }

    void PhantomGame::update( float elapsed )
    {
        Composite::update( elapsed );
        std::deque<GameState*>::reverse_iterator iter;
        iter = this->states.rbegin();
        while( iter != this->states.rend() )
        {
            (*iter)->update(elapsed);
            if( iter == this->states.rend() || !(*iter)->propegateUpdate )
                break;
            ++iter;
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
        timeval tv;
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
