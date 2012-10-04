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
        Driver(){}
        virtual ~Driver(){}

        virtual void setGame(PhantomGame* game) = 0;
        virtual void onUpdate(float elapsed) = 0;
        virtual void onRender() = 0;

        InputState* getInput() { return inputState; }

        PhantomGame* game;
        Camera* camera;
        Renderer* renderer;
        InputState* inputState;
    protected:

    };
} /* namespace phantom */

#endif /* BASEDRIVER_H */