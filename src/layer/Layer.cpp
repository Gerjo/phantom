#include "Layer.h"

#include <core/PhantomGame.h>

namespace phantom {

    Layer::Layer(void) {
        setType("Layer");
    }

    void Layer::disposeObjects() {
        if(!_disposables.empty()) {
            for(Composite* composite : _disposables) {
                delete composite;
                composite = 0;
            }

            _disposables.clear();
        }
    }

    void Layer::addComponent(Composite* component) {
        component->onLayerChanged(this);
        Composite::addComponent(component);
    }

    void Layer::dispose(Composite* composite) {
        _disposables.push_back(composite);
    }

} /* namespace phantom */
