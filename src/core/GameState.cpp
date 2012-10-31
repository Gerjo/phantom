#include "GameState.h"
#include "utils/PhantomException.h"
#include "layer/Layer.h"

namespace phantom {

    GameState::GameState() : doUpdate(true), doRender(true) {
        setType("GameState");
    }

    GameState::~GameState() {

    }

    void GameState::disposeObjects() {
        Layer::disposeObjects();

        for(Composite* composite : getComponents()) {
            Layer* layer = dynamic_cast<Layer*>(composite);
            if(layer != 0) {
                layer->disposeObjects();
            }
        }

    }

    // void GameState::addComponent(Composite* component) {
    //    if(dynamic_cast<Layer*>(component) == 0) {
    //        throw PhantomException("Only layers can be added to a GameState.");
    //    }
    //
    //    Composite::addComponent(component);
    // }

} /* namespace phantom */
