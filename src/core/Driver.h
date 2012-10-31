#ifndef BASEDRIVER_H
#define BASEDRIVER_H

#include <string>
#include <core/PhantomGame.h>
#include <CompileConfig.h>
#include <core/Camera.h>
#include <core/Renderer.h>
#include <utils/PhantomException.h>
#include <input/Input.h>
#include <utils/Time.h>

using namespace std;

namespace phantom{
    class FreeTypeLibrary;
    class LIBEXPORT Driver{
    public:
        Driver(PhantomGame* game) : _game(game) {
            _camera = 0;
            _renderer = 0;
            _fontLibrary = 0;
        }
        virtual ~Driver(){}

        virtual void setWindowTitle(string title) = 0;
        virtual void onUpdate(Time time) {
            _game->update(time);
            _renderer->renderLoop(&_game->getGameStates());
            _input->getKeyboardState()->changes()->clear();
        }
        virtual void onRender() = 0;

        Input* getInput() { return _input; }

        virtual Camera* createCamera(void) = 0;

        Camera *getActiveCamera() {
            if(_camera != 0)
                return _camera;
            else
                throw PhantomException("There is no active camera set yet.");
        }

        void setActiveCamera(Camera *cam) {
            if(_camera != 0)
                _camera->setActive(false);
            _camera = cam;
            _camera->setActive(true);
        }

        Renderer *getRenderer() {
            return _renderer;
        }

        FreeTypeLibrary *getFontLibrary() {
            return _fontLibrary;
        }

    protected:
        Renderer* _renderer;
        FreeTypeLibrary* _fontLibrary;
        Input* _input;
        Camera* _camera;
        PhantomGame* _game;
    };
} /* namespace phantom */

#endif /* BASEDRIVER_H */