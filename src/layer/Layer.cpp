#include "Layer.h"

#include <core/PhantomGame.h>

namespace phantom {

    Layer::Layer(void) {

    }

    void Layer::addComponent(Composite* component) {
        component->onLayerChanged(this);
        Composite::addComponent(component);
    }
} /* namespace phantom */
