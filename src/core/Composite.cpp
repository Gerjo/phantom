#include "Composite.h"
#include <iostream>
#include "PhantomGame.h"
#include <utils/PhantomException.h>
#include <core/Driver.h>
#include <layer/Layer.h>

namespace phantom {

    Composite::Composite() :
    _position(0, 0, 0),
    _remove(false),
    _destroy(false),
    _type("Composite")
    {
        _layer = 0;
        _parent = 0;
        _graphics = new Graphics(this);
        _boundingBox.size = Vector3(10, 10, 10);
    }

    Composite::~Composite() {
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            delete *iter;
        }

        delete _graphics;
    }

    PhantomGame* Composite::getGame(void) {
        if (PhantomGame::INSTANCE == 0) {
            throw PhantomException("Did you forget to create PhantomGame?");
        } else {
            return phantom::PhantomGame::INSTANCE;
        }
    }

    Driver* Composite::getDriver(void) {
        return getGame()->getDriver();
    }

    void Composite::onParentChange(Composite *parent) {
        _parent = parent;
    }

    void Composite::onAnsestorChanged() {
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            (*iter)->onAnsestorChanged();
        }
    }

    void Composite::addComponent(Composite *component) {
        this->_components.push_back(component);
        component->onParentChange(this);
        component->onAnsestorChanged();
    }

    void Composite::update(const float& elapsed) {
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            Composite* composite = *iter;

            composite->update(elapsed);

            if(composite->_remove == true) {
                composite->_remove = false;
                if(composite->_destroy) {
                    delete composite;
                }

                // Nifty little feature, erase returns the next available iterator:
                iter = _components.erase(iter);

                // Ok, we just updated the iterator, let us make sure it's not the
                // end. If we skip this check, "++iter" will yield the most obscure
                // error that'll take hours to discover.
                if(iter == _components.end()) {
                    break;
                }
            }

        }
    }

    void Composite::intergrate(const float& elapsed) {
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            (*iter)->intergrate(elapsed);
        }
    }

    unsigned int Composite::handleMessage(const char *msg, void *data) {
        int result = PHANTOM_MESSAGE_IGNORED;
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            int r = (*iter)->handleMessage(msg, data);
            if (r == PHANTOM_MESSAGE_HANDLED) {
                result = r;
            } else if (r == PHANTOM_MESSAGE_CONSUMED) {
                return PHANTOM_MESSAGE_CONSUMED;
            }
        }
        return result;
    }

    void Composite::onCollision(Composite *other) {

    }

    bool Composite::canCollideWith(Composite *other) {
        return true;
    }

    Vector3 Composite::getPosition() {
        return _position;
    }

    void Composite::setPosition(Vector3& position) {
        _position = position;
    }

    void Composite::addPosition(const Vector3& add) {
        _position += add;
    }

    void Composite::removePosition(const Vector3& subtract) {
        _position -= subtract;
    }

    void Composite::setType(const string& type) {
        _type = type;
    }

    const string& Composite::getType() {
        return _type;
    }

    bool Composite::isType(const string& type) {
        return _type.compare(type) == 0;
    }

    string Composite::toString(void) {
        stringstream ss;

        const int numChildren = _components.size();

        ss << "[class " << _type << "] ";

        if (numChildren == 0) {
            ss << "with no children.";

        } else {
            ss << "children (" << numChildren << "): ";

            auto it = _components.begin();

            for (int i = 0; it != _components.end(); ++it, ++i) {
                ss << (*it)->getType();

                if (i < numChildren - 1) {
                    ss << ", ";
                } else {
                    ss << ".";
                }
            }
        }

        ss << endl;

        return ss.str();
    }

    void Composite::onLayerChanged(Layer* layer) {
        if (layer != _layer) {
            _layer = layer;
            for (auto iter = _components.begin(); iter != _components.end(); ++iter)
                (*iter)->onLayerChanged(layer);
        }
    }

    std::vector<Composite*>& Composite::getComponents() {
        return _components;
    };

    Box3& Composite::getBoundingBox() {
        _boundingBox.origin = getPosition();
        return _boundingBox;
    }

    void Composite::setBoundingBox(const Box3& boundingBox) {
        _boundingBox = boundingBox;
    }

    Graphics& Composite::getGraphics() {
        return *_graphics;
    }

    void Composite::remove(void) {
        _remove  = true;
    }

    void Composite::destroy(void) {
        _remove  = true;
        _destroy = true;
    }
} /* namespace phantom */
