#include "PhantomGame.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <phantom.h>
#include <core/Driver.h>
#include <graphics/ImageCache.h>
#include <utils/PhantomException.h>
#include <utils/Time.h>

namespace phantom {

    PhantomGame* PhantomGame::INSTANCE = 0;

    PhantomGame::PhantomGame(const char *configfile) : _viewPort(1280, 720, 0), _worldSize(1920, 1080, 0), _fps(60), fullscreen(false) {
        if(PhantomGame::INSTANCE == 0)
            PhantomGame::INSTANCE = this;
        else
            throw PhantomException("You should not create two games...");

        parseConfigurationFile(configfile);
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
        _running = true;
        double last = Util::getTime();
        double total = 0.0f;
        int fpscount = 0;

        while (_running) {
            double now = Util::getTime();
            double elapsed = now - last;
            total += elapsed;

            Time time(static_cast<float>(elapsed), static_cast<float>(total), now);

            _driver->onUpdate(time);
            _driver->onRender();
            //if (elapsed < (1.0f / this->_fps)) {
            //    Util::sleep(ceil(((1.0f / this->_fps) - elapsed) * 1000.0f));
            //}

            fpscount++;

            if (total >= 1) {
                stringstream stream;
                stream << "Elephantom [Avg FPS: " << fpscount << " Cur FPS: " << 1.0 / elapsed << "]" << endl;
                getDriver()->setWindowTitle(stream.str());
                fpscount = 0;
                total = 0;
            }

            last = now;
        }
        return 0;
    }

    void PhantomGame::update(const Time& time) {
        Composite::update(time);

        for(GameState* gameState : _states) {
            if(gameState->doUpdate) {
                gameState->update(time);
            }
        }

        if(!_disposables.empty()) {
            for(Composite* composite : _disposables) {
                delete composite;
                composite = 0;
            }

            _disposables.clear();
        }
    }

    void PhantomGame::exit(int returncode) {
        onExit(returncode);
        _running = false;
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

    void PhantomGame::parseConfigurationFile(const char *configfile) {
        if(strlen(configfile) == 0) return;
        std::ifstream configuration(configfile);
        configuration.seekg(0, ios::end);
        std::streamoff length = configuration.tellg();
        configuration.seekg(0, ios::beg);
        char *buffer = new char[static_cast<unsigned int>(length)];

        configuration.read(buffer, length);

        string propertyname;
        string propertyvalue;
        bool readingValue = false;
        for(unsigned int i = 0; i < length; ++i) {
            if(buffer[i] != ' ' && buffer[i] != '\n') {
                if(readingValue)
                    propertyvalue += buffer[i];
                else if(!readingValue)
                    propertyname += buffer[i];
            }
            else if(buffer[i] == 32) {
                readingValue = true;
            }

            if(buffer[i] == '\n' || buffer[i] == '\0' || i == (length - 1)) {
                readingValue = false;

                if(propertyname.compare("screenWidth") == 0) {
                    _viewPort.x = static_cast<float>(atoi(propertyvalue.c_str()));
                }
                else if(propertyname.compare("screenHeight") == 0) {
                    _viewPort.y = static_cast<float>(atoi(propertyvalue.c_str()));
                }
                else if(propertyname.compare("fullscreen") == 0) {
                    if(atoi(propertyvalue.c_str()) == 0)
                        fullscreen = false;
                    else
                        fullscreen = true;
                }
                else if(propertyname.compare("mousecursor") == 0) {
                    if(atoi(propertyvalue.c_str()) == 0)
                        mousecursor = false;
                    else
                        mousecursor = true;
                }

                propertyname.clear();
                propertyvalue.clear();
            }
        }
    }

    // Since gamestates are not added as child, messages must be manually moved
    // into each state.
    MessageState PhantomGame::handleMessage(AbstractMessage* message) {
        MessageState messageState = IGNORED;

        for(GameState* gameState : _states) {
            MessageState r = gameState->handleMessage(message);

            if(r == CONSUMED) {
                return r;
            }

            messageState = r;
        }

        return messageState;
    }

    void PhantomGame::dispose(Composite* composite) {
        _disposables.push_back(composite);
    }

} /* namespace phantom */
