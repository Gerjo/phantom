#include <pch.h>
#include "Console.h"
#include <input/KeyboardListener.h>
#include <core/Driver.h>
#include <null/NullDriver.h>

namespace phantom {
    Console* Console::INSTANCE = 0;

    Console::Console() : _doRedraw(true), _logCount(0), _enabled(false) {
        setType("Console");
        Console::INSTANCE = this;

        _width    = getPhantomGame()->getViewPort().x;
        _height   = getPhantomGame()->getViewPort().y / 2;
        _maxLines = 30;

        _keyboard = nullptr;

        setPosition(Vector3(
            0.0f,
            0.0f,
            0.0f)
            );

    }

    void Console::log(string log) {
        if(Console::INSTANCE != 0) {
            std::replace(log.begin(), log.end(), '\n', ' ');
            std::replace(log.begin(), log.end(), '\r', ' ');
            Console::INSTANCE->addLog(log);
        } else {
            cout << log << endl;
        }
    }

    void Console::log(stringstream log) {
        Console::log(log.str());
    }

    void Console::update(const PhantomTime& time) {
        Composite::update(time);

        NullDriver* driver = dynamic_cast<NullDriver*>(getDriver());
        if(driver != nullptr || getDriver()->getActiveCameras()->size() == 0) // Check if the camera is not a NULL driver and if we have a camera we can use.
            return;

        Vector3 campos = getDriver()->getActiveCameras()->at(0)->getPosition();
        setPosition(campos);

        getGraphics().clear();

        if(!_enabled && getDriver()->getInput()->getKeyboardState()->isKeyDown('\\')) {
            _enabled = true;
            _keyboard = KeyboardListener::lock(this);
        }

        if(_keyboard != nullptr) {
            for(char c : *_keyboard->changesUp()) {
                if(c == 27) {
                    _keyboard = KeyboardListener::unlock(this);
                    _enabled = false;
                }
            }
        }

        if(_enabled) {
            draw();
        }
    }

    void Console::renderText(int offset, Color color) {
        Graphics& g = getGraphics().beginPath().setFillStyle(color);

        float lineheight = 40;
        float lineOffset = lineheight + lineheight;

        for(const string& log : _logs) {
            g.text(0.0f, _height - lineOffset, 20, "fonts/arial.ttf", log);
            lineOffset += lineheight;
        }

        g.stroke();
    }

    void Console::mapCommand(string name, function<void(string args)> function) {
        Console::INSTANCE->_commandMap.insert(pair<string, std::function<void(string args)>>(name, function));
    }

    void Console::renderInput() {
        if(_keyboard != nullptr) {
            for(char c : *_keyboard->changes()) {
                if(c == '\b') { // Action for backspace.
                    if(_text.size() > 0) {
                        _text.erase(_text.end() - 1);
                    }
                }
                else if(c == '\n' || c == '\r') {
                    std::string::size_type argumentStart = _text.find(' ');

                    if(_text.substr(0, 4) == "\\pos" && _text.size() > 5) {
                        if(_text.substr(5, _text.size()) == "camera")
                            Console::log("Current position of the camera is: " + getDriver()->getActiveCameras()->at(0)->getPosition().toString());
                        else if(_text.substr(5, _text.size()) == "mouse")
                            Console::log("Current position of the mouse is: " + getDriver()->getInput()->getMouseState()->getPosition().toString());
                    }
                    else if(_commandMap.find(_text.substr(1, argumentStart-1)) != _commandMap.end()) {
                        std::function<void(string args)> &func = _commandMap.at(_text.substr(1, argumentStart-1));
                        string argument = "";
                        if(argumentStart != _text.size())
                            argument = _text.substr(argumentStart+1, _text.size());
                        func(argument);
                    }
                    else {
                        Console::log("Command unknown.");
                    }
                    _text.clear();
                    _text.append(1, '\\');
                } else if(c < 28) { }
                else {
                    _text.append(1, c);
                }
            }

            getGraphics().beginPath().text(0.0f, _height - 40, 20, "fonts/arial.ttf", _text).stroke();
        }
    }

    void Console::draw(void) {
        _doRedraw   = false;

        Graphics& g = getGraphics().clear().beginPath();
        g.setFillStyle(Color(0, 0, 0, 100));
        g.rect(0.0f, 0.0f, _width, _height);
        g.fill();

        renderText( 0, Colors::WHITE);
        renderInput();
    }

    void Console::addLog(string log) {
        stringstream formatted;
        formatted << "[" << _logCount << "] " << log;

        _logs.push_front(formatted.str());

        while(_logs.size() > _maxLines) {
            _logs.pop_back();
        }

        _logCount++;
        _doRedraw = true;
    }
}