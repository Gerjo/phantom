#ifndef BASEDRIVER_H
#define BASEDRIVER_H

#include <core/PhantomGame.h>
#include <CompileConfig.h>
#include <core/Camera.h>
#include <core/Renderer.h>
#include <input/Input.h>

namespace phantom{
    class LIBEXPORT Driver{
    public:
        Driver(PhantomGame* game) : _game(game) {}
        virtual ~Driver(){}

        virtual void onUpdate(float elapsed) = 0;
        virtual void onRender() = 0;

        Input* getInput() { return _input; }

        virtual Camera* createCamera(void) = 0;

    protected:
        Renderer* _renderer;
        Input* _input;
        PhantomGame* _game;
    };
} /* namespace phantom */

#endif /* BASEDRIVER_H */