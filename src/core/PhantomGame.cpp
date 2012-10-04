#include "PhantomGame.h"
#include <iostream>
#include <ctime>
#include <phantom.h>
#include <core/Driver.h>

namespace phantom {

    PhantomGame::PhantomGame(const char *configfile) : _width(800), _height(450), _fps(63) {

    }

    PhantomGame::~PhantomGame() {
        delete _driver;
    }

    void PhantomGame::pushGameState(GameState *state) {
        _states.push_back(state);
    }

    void PhantomGame::popGameState() {
        _states.pop_back();
    }

    int PhantomGame::start(int argc, char *argv[]) {

        double last = this->time();
        float total = 0.0f;
        float fpscount = 0.0f;

        while (1) {
            double now = this->time();
            double elapsed = now - last;

            _driver->onUpdate(elapsed);

            if (elapsed < (1.0f / this->_fps)) {
                Util::sleep(ceil(((1.0f / this->_fps) - elapsed) * 1000.0f));
            }

            total += elapsed;
            fpscount++;

            if (total >= 1) {
                stringstream stream;
                stream << "Phantom [Avg FPS: " << fpscount << " Cur FPS: " << 1 / elapsed << "]" << endl;
                //renderer->setWindowTitle(stream.str());
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

    double PhantomGame::time() {
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

    Driver* PhantomGame::getDriver() {
        return _driver;
    }

    void PhantomGame::setDriver(Driver* driver) {
        _driver = driver;
    }

    deque<GameState*>& PhantomGame::getGameStates() {
        return _states;
    }

    unsigned int PhantomGame::getHeight() const {
        return _height;
    }

    unsigned int PhantomGame::getWidth() const {
        return _width;
    }

} /* namespace phantom */
