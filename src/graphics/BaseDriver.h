#ifndef BASEDRIVER_H
#define BASEDRIVER_H

#include <core/PhantomGame.h>
#include <CompileConfig.h>
#include <input/InputState.h>
#include "Renderer.h"

namespace phantom{

    class LIBEXPORT BaseDriver{
    public:
        BaseDriver(){}
        virtual ~BaseDriver(){}

        virtual void setGame(PhantomGame* game) = 0;
        virtual void onUpdate(float elapsed) = 0;
        virtual void onRender() = 0;

        PhantomGame* game;
        Renderer* renderer;
        InputState* inputState;
    protected: 

    };
} /* namespace phantom */

#endif /* BASEDRIVER_H */