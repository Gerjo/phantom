#include "PhantomGame.h"
#include <iostream>
#include <ctime>
#include <phantom.h>
#include <core/Driver.h>
#include <graphics/ImageCache.h>
#include <utils/PhantomException.h>

#ifdef WIN32
#   ifdef _DEBUG
#       define _CRTDBG_MAP_ALLOC
#       include <stdlib.h>
#       include <crtdbg.h>
#   endif /* Debug */
#endif /* win32*/

namespace phantom {

    PhantomGame* PhantomGame::INSTANCE = 0;

    PhantomGame::PhantomGame(const char *configfile) : _viewPort(1200, 650, 0), _worldSize(1200, 650, 0), _fps(60) {
        if(PhantomGame::INSTANCE == 0)
            PhantomGame::INSTANCE = this;
        else
            throw PhantomException("You should not create two games...");
    }

    PhantomGame::~PhantomGame() {
#ifdef WIN32
        _CrtDumpMemoryLeaks();
#endif

        delete ImageCache::getInstance();
        delete _driver;
    }

    void PhantomGame::pushGameState(GameState *state) {
        _states.push_back(state);
    }

    void PhantomGame::popGameState() {
        _states.pop_back();
    }

    int PhantomGame::start(int argc, char *argv[]) {
        _running = true;
        double last = Util::getTime();
        double total = 0.0f;
        int fpscount = 0;

        while (_running) {
            double now = Util::getTime();
            double elapsed = now - last;

            _driver->onUpdate(static_cast<float>(elapsed));

            //if (elapsed < (1.0f / this->_fps)) {
            //    Util::sleep(ceil(((1.0f / this->_fps) - elapsed) * 1000.0f));
            //}

            total += elapsed;
            fpscount++;

            if (total >= 1) {
                stringstream stream;
                stream << "Elephantom [Avg FPS: " << fpscount << " Cur FPS: " << 1 / elapsed << "]" << endl;
                getDriver()->setWindowTitle(stream.str());
                fpscount = 0;
                total = 0;
            }

            last = now;
        }
        return 0;
    }

    void PhantomGame::update(float elapsed) {
        Composite::update(elapsed);
        std::deque<GameState*>::reverse_iterator iter;
        iter = this->_states.rbegin();
        while (iter != this->_states.rend()) {
            (*iter)->update(elapsed);
            if (iter == this->_states.rend() || !(*iter)->propegateUpdate)
                break;
            ++iter;
        }
    }

    void PhantomGame::exit(int returncode) {
        onExit(returncode);
    }

    void PhantomGame::onExit(int returncode) {
    }

    Driver* PhantomGame::getDriver() {
        return _driver;
    }

    void PhantomGame::setDriver(Driver* driver) {
        _driver = driver;
        //hacky:
        ImageCache::getInstance()->setRenderer(_driver->getRenderer());
    }

    deque<GameState*>& PhantomGame::getGameStates() {
        return _states;
    }

    Vector3 PhantomGame::getViewPort() const {
        return _viewPort;
    }

    Vector3 PhantomGame::getWorldSize() const {
        return _worldSize;
    }

} /* namespace phantom */
