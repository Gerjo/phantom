#ifndef BASEDRIVER_H
#define BASEDRIVER_H

#include <core/PhantomGame.h>
#include <CompileConfig.h>
#include <core/Camera.h>
#include <input/InputState.h>
#include <core/Renderer.h>

namespace phantom{
    class InputState;
    class LIBEXPORT Driver{
    public:
        Driver(PhantomGame* game) : _game(game) {}
        virtual ~Driver(){}

        virtual void onUpdate(float elapsed) = 0;
        virtual void onRender() = 0;

        InputState* getInput() { return _inputState; }

        Camera* camera;
        Renderer* renderer;

    protected:
        PhantomGame* _game;
        InputState* _inputState;
    };
} /* namespace phantom */

#endif /* BASEDRIVER_H */