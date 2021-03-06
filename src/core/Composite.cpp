#include <pch.h>
#include "Composite.h"
#include "PhantomGame.h"
#include <utils/PhantomException.h>
#include <core/Driver.h>
#include <layer/Layer.h>

namespace phantom {

    Composite::Composite() :
        _position(0, 0, 0),
        _direction(0, 0, 0),
        _remove(false),
        _destroy(false),
        _isUpdating(false),
        _type("Composite"),
        isStatic(false),
        _graphics(this)
    {
        _layer = 0;
        _parent = 0;
        _boundingBox.size = Vector3(10, 10, 0);
    }

    Composite::~Composite() {

        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            delete *iter;
            *iter = 0;
        }
    }

    PhantomGame* Composite::getPhantomGame(void) {
        if (PhantomGame::INSTANCE == 0) {
            throw PhantomException("Did you forget to create PhantomGame?");
        } else {
            return phantom::PhantomGame::INSTANCE;
        }
    }

    Composite* Composite::getParent() {
        return _parent;
    }

    Driver* Composite::getDriver(void) {
        return getPhantomGame()->getDriver();
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
        if(_isUpdating) {
            _componentsBuffer.push_back(component);
        } else {
            this->_components.push_back(component);
            component->onParentChange(this);
            component->onAnsestorChanged();
        }
    }

    void Composite::update(const PhantomTime& time) {
        _isUpdating = true;
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            Composite* composite = *iter;

#ifdef _DEBUG
            // GCC will break here, unsure about any other compiler.
            if(*iter == 0) {
                throw PhantomException("Components were modified while iterating over them.");
            }

            // This is where any sane debugger will crash:
            // If your code breaks here, it *probably* means the "_components"
            // collection was modified while we were iterating over it. --Gerjo
            string name = composite->getType();
#endif

            // Let's make sure we're fit for an update:
            if(!composite->_remove && !composite->_destroy) {
                composite->update(time);
            }

            // Check again, since update is potentially state changing.
            if(composite->_remove == true) {
                composite->_remove = false;
                if(composite->_destroy) {
                    getPhantomGame()->dispose(composite);
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

        _isUpdating = false;

        if(!_componentsBuffer.empty()) {
            for(Composite* composite : _componentsBuffer) {
                addComponent(composite);
            }

            _componentsBuffer.clear();
        }
    }

    MessageState Composite::handleMessage(AbstractMessage* message) {
        MessageState state = IGNORED;

        for(Composite* composite : _components) {
            state = composite->handleMessage(message);
            if (state == MessageState::CONSUMED) {
                return state;
            }
        }

        return state;
    }

    void Composite::onCollision(Composite *other, CollisionData& collisionData) {

    }

    bool Composite::canCollideWith(Composite *other) {
        return true;
    }

    const Vector3& Composite::getPosition() {
        return _position;
    }

    void Composite::setPosition(Vector3 position) {
        _position = position;
    }

    void Composite::addPosition(const Vector3& add) {
        _position += add;
    }

    void Composite::setDirection(Vector3 direction) {
        _direction = direction;
    }

    void Composite::setX(float x) {
        _position.x = x;
    }

    void Composite::setY(float y) {
        _position.y = y;
    }

    void Composite::removePosition(const Vector3& subtract) {
        _position -= subtract;
    }

    void Composite::setType(const string& type) {
        _type = type;
    }

    const string& Composite::getType() const {
        return _type;
    }

    bool Composite::isType(const string& type) const {
        return _type.compare(type) == 0;
    }

    bool Composite::isType(const Composite& other) const {
        return isType(other.getType());
    }

    bool Composite::isType(const Composite* other) const {
        return isType(other->getType());
    }

    string Composite::toString(void) {
        stringstream ss;

        const std::vector<Composite*>::size_type numChildren = _components.size();

        ss << "[class " << _type << "] ";

        if (numChildren == 0) {
            ss << "with no children.";

        } else {
            ss << "children (" << numChildren << "): ";

            auto it = _components.begin();

            for (size_t i = 0; it != _components.end(); ++it, ++i) {
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
            for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
                (*iter)->onLayerChanged(layer);
            }
        }
    }

    std::vector<Composite*>& Composite::getComponents() {
        return _components;
    }

    Box3& Composite::getBoundingBox() {
        _boundingBox.origin = getPosition();
        return _boundingBox;
    }

    void Composite::setBoundingBox(const Box3& boundingBox) {
        _boundingBox = boundingBox;
    }

    Graphics& Composite::getGraphics() {
        return _graphics;
    }

    void Composite::removeFromParent(void) {
        if(_parent != 0) {
            if(_parent->_isUpdating) {
                // We're deleting from a collection, we're also iterating over,
                // using these flags, said iteration will also remove this component.
                _parent = 0;
                _layer  = 0;
                _remove = true;
            } else {
                // Actually ask the parent to destroy or remove us. Having the parent
                // destroy its children, permits the parent to clean any references
                // to said child. This actually means that the real deletion may
                // occur later on, and not instantly.
                if(_destroy) {
                    _parent->destroyComponent(this);
                } else {
                    _parent->removeComponent(this);
                }
            }
        } else {
            throw PhantomException("Cannot remove from parent if there is no parent.");
        }
    }

    void Composite::destroy(void) {
        if(_parent == 0) {
            // Called without a parent, save to delete right away.
            getPhantomGame()->dispose(this);
        } else {
            _destroy = true;
            removeFromParent();
        }
    }

    void Composite::destroyComponent(Composite* who) {
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            if(who == *iter) {
                _components.erase(iter);
                getPhantomGame()->dispose(who);
                break;
            }
        }
    }

    void Composite::removeComponent(Composite* who) {
        for (auto iter = _components.begin(); iter != _components.end(); ++iter) {
            if(who == *iter) {
                iter = _components.erase(iter);
                break;
            }
        }
    }

    bool Composite::isDestroyed() {
        return _destroy;
    }

    Layer* Composite::getLayer() {
        return _layer;
    }
} /* namespace phantom */
