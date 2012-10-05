#include "Composite.h"
#include <iostream>
#include "Entity.h"
#include "PhantomGame.h"
#include <utils/PhantomException.h>
#include <core/Driver.h>

namespace phantom {


    Composite::Composite() : flags(0), destroyed(false), parent(0), _position(0, 0, 0) {
    }

    Composite::~Composite() {
        std::vector<Composite*>::iterator iter;
        for( iter = this->_components.begin(); iter != this->_components.end(); ++iter )
            delete *iter;
    }

    PhantomGame* Composite::getGame(void) {
        if(PhantomGame::INSTANCE == 0) { 
            throw PhantomException("Did you forget to create PhantomGame?");
            return 0;
        }
        else {
            return phantom::PhantomGame::INSTANCE;
        }
    }

    Driver* Composite::getDriver(void) {
        return getGame()->getDriver();
    }

    void Composite::onAdd( Composite *parent )
    {
        this->parent = parent;
    }

    void Composite::onAnsestorChanged()
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->_components.begin(); iter != this->_components.end(); ++iter )
            (*iter)->onAnsestorChanged();
    }

    void Composite::addComponent( Composite *component )
    {
        this->_components.push_back(component);
        component->onAdd( this );
        component->onAnsestorChanged();
    }

    bool Composite::destroyComponent( Composite *component )
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->_components.begin(); iter != this->_components.end(); ++iter )
        {
            if( *iter == component )
            {
                delete *iter;
                this->_components.erase(iter);
                return true;
            }
        }
        return false;
    }
    bool Composite::destroyComponentAt( size_t index )
    {
        if( index < 0 || index >= this->_components.size() )
            return false;
        std::vector<Composite*>::iterator iter;
        iter = this->_components.begin() + index;
        delete *iter;
        this->_components.erase( iter );
        return true;
    }

    bool Composite::removeComponent( Composite *component )
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->_components.begin(); iter != this->_components.end(); ++iter )
        {
            if( *iter == component )
            {
                this->_components.erase(iter);
                return true;
            }
        }
        return false;
    }

    void Composite::update(const float& elapsed)
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->_components.begin(); iter != this->_components.end(); ++iter )
            (*iter)->update(elapsed);

        // Remove destroyed components:
        for( int i = this->_components.size()-1; i >= 0; --i )
        {
            if( this->_components[i]->destroyed )
            {
                this->destroyComponentAt(i);
            }
        }
    }

    void Composite::intergrate(const float& elapsed)
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->_components.begin(); iter != this->_components.end(); ++iter )
            (*iter)->intergrate(elapsed);
    }

    unsigned int Composite::handleMessage(const char *msg, void *data)
    {
        int r;
        int result = PHANTOM_MESSAGE_IGNORED;
        std::vector<Composite*>::iterator iter;
        for( iter = this->_components.begin(); iter != this->_components.end(); ++iter )
        {
            r = (*iter)->handleMessage(msg, data);
            if( r == PHANTOM_MESSAGE_HANDLED)
                result = r;
            else if( r == PHANTOM_MESSAGE_CONSUMED )
                return PHANTOM_MESSAGE_CONSUMED;
        }
        return result;
    }

    void Composite::onCollision( Composite *other )
    {

    }

    bool Composite::canCollideWith( Composite *other )
    {
        return true;
    }

    const Vector3& Composite::getPosition() {
        return this->_position;
    }

} /* namespace phantom */
