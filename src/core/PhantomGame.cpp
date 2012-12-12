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

    PhantomGame::PhantomGame(const char *configfile) : _driver(nullptr), _screenSize(1280, 720, 0), _viewPort(1920, 1080, 0), _worldSize(5000, 5000), _fps(62.5), fullscreen(false) {
        if(PhantomGame::INSTANCE == 0) {
            PhantomGame::INSTANCE = this;
            _console = new Console();
            addComponent(_console);
        }
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

        std::function<void(string args)> function = [this] (string args) {
            this->exit(0);
        };

        Console::mapCommand("quit", function);

        double last = Util::getTime();
        double total = 0.0f;
        Timer timer(1);

        unsigned int framecount = 0;
        unsigned int lastframecount = 0;

        while (_running) {
            double now = Util::getTime();
            double elapsed = now - last;
            total += elapsed;

            PhantomTime time(static_cast<float>(elapsed), static_cast<float>(total), now);

            update(time);

            _driver->onUpdate(time);
            _driver->onRender();

            if (timer.hasExpired(time)) {
                timer.restart();

                stringstream stream;
                stream << "Elephantom [Current FPS: " << (int)(1 / elapsed) << " Avarage FPS: " << framecount - lastframecount << "]" << endl;
                getDriver()->setWindowTitle(stream.str());

                lastframecount = framecount;
            }

#ifndef _WIN32
            long sleepDuration = static_cast<long>(((1.0 / this->_fps) - elapsed) * 1000000000);
            std::this_thread::sleep_for(std::chrono::nanoseconds(sleepDuration));
#else
            while(1) {
                if((Util::getTime() - last) + elapsed > 1.0 / _fps)
                    break;
            }
#endif
            ++framecount;
            last = now;
        }

        return 0;
    }

    void PhantomGame::update(const PhantomTime& time) {
        Composite::update(time);

        // We make a copy since the states can change during the component updates.
        deque<GameState*> states = _states;

        for(GameState* gameState : states) {
            if(gameState->doUpdate) {
                gameState->update(time);
            }
        }

        clearDisposables();
    }

    void PhantomGame::clearDisposables() {
        if(!_disposables.empty()) {
            for(Composite* composite : _disposables) {
                delete composite;
                composite = nullptr;
            }

            _disposables.clear();
        }
    }

    void PhantomGame::exit(int returncode) {
        _running = false;
        vector<Composite*> components = getComponents();
        for(auto component = components.begin(); component != components.end();) {
            (*component)->destroy();
            component = components.erase(component);
        }

        clearDisposables();

        onExit(returncode);
    }

    void PhantomGame::onExit(int returncode) {

    }

    Driver* PhantomGame::getDriver() {
        return _driver;
    }

    void PhantomGame::setDriver(Driver* driver) {
        _driver = driver;
        ImageCache::getInstance()->setRenderer(_driver->getRenderer());
    }

    deque<GameState*>& PhantomGame::getGameStates() {
        return _states;
    }

    Vector3 PhantomGame::getViewPort() const {
        return _viewPort;
    }

    Vector3 PhantomGame::getScreenSize() const {
        return _screenSize;
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
                    _screenSize.x = static_cast<float>(atoi(propertyvalue.c_str()));
                }
                else if(propertyname.compare("screenHeight") == 0) {
                    _screenSize.y = static_cast<float>(atoi(propertyvalue.c_str()));
                }
                else if(propertyname.compare("fullscreen") == 0) {
                    if(atoi(propertyvalue.c_str()) == 0)
                        fullscreen = false;
                    else
                        fullscreen = true;
                }
                else if(propertyname.compare("soundvol") == 0) {
                    soundvol = static_cast<float>(atof(propertyvalue.c_str()));
                }
                else if(propertyname.compare("musicvol") == 0) {
                    musicvol = static_cast<float>(atof(propertyvalue.c_str()));
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

        delete[] buffer;
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
