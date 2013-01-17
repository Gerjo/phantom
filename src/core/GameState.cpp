#include <pch.h>
#include "GameState.h"
#include "utils/PhantomException.h"
#include "layer/Layer.h"

namespace phantom {

    GameState::GameState() : doUpdate(true), doRender(true) {
        setType("GameState");
    }

    GameState::~GameState() {

    }
} /* namespace phantom */
