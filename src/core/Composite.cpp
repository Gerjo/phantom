#include "Composite.h"
#include <iostream>
#include "Entity.h"
#include "PhantomGame.h"
#include <utils/PhantomException.h>
#include <core/Driver.h>

namespace phantom {


    Composite::Composite() : flags(0), destroyed(false), parent(0), _position(0, 0, 0) {

        if(phantom::PhantomGame::INSTANCE == 0) {
            if(phantom::PhantomGame::GERJO_HACK_NEEDS_REFACTOR == 0) {
                phantom::PhantomGame::GERJO_HACK_NEEDS_REFACTOR++;
                cout << "Applied hack, see: composite constructor." << endl;
                return;
            }

            throw PhantomException(
                        "Due to some (arguable) worthless coding (written by "
                        "gerjo), composites cannot be constructed prior to the "
                        "game being initialized. Yes we use global statics. Yes "
                        "I feel guilty, and so should you."
                    );
        }
    }

    Composite::~Composite() {
        std::vector<Composite*>::iterator iter;
        for( iter = this->components.begin(); iter != this->components.end(); ++iter )
            delete *iter;
    }

    PhantomGame* Composite::getGame(void) {
        return phantom::PhantomGame::INSTANCE;
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
        for( iter = this->components.begin(); iter != this->components.end(); ++iter )
            (*iter)->onAnsestorChanged();
    }

    void Composite::addComponent( Composite *component )
    {
        this->components.push_back(component);
        component->onAdd( this );
        component->onAnsestorChanged();
    }

    bool Composite::destroyComponent( Composite *component )
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->components.begin(); iter != this->components.end(); ++iter )
        {
            if( *iter == component )
            {
                delete *iter;
                this->components.erase(iter);
                return true;
            }
        }
        return false;
    }
    bool Composite::destroyComponentAt( size_t index )
    {
        if( index < 0 || index >= this->components.size() )
            return false;
        std::vector<Composite*>::iterator iter;
        iter = this->components.begin() + index;
        delete *iter;
        this->components.erase( iter );
        return true;
    }

    bool Composite::removeComponent( Composite *component )
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->components.begin(); iter != this->components.end(); ++iter )
        {
            if( *iter == component )
            {
                this->components.erase(iter);
                return true;
            }
        }
        return false;
    }

    void Composite::update(const float& elapsed)
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->components.begin(); iter != this->components.end(); ++iter )
            (*iter)->update(elapsed);

        // Remove destroyed components:
        for( int i = this->components.size()-1; i >= 0; --i )
        {
            if( this->components[i]->destroyed )
            {
                this->destroyComponentAt(i);
            }
        }
    }

    void Composite::intergrate(const float& elapsed)
    {
        std::vector<Composite*>::iterator iter;
        for( iter = this->components.begin(); iter != this->components.end(); ++iter )
            (*iter)->intergrate(elapsed);
    }

    unsigned int Composite::handleMessage(const char *msg, void *data)
    {
        int r;
        int result = PHANTOM_MESSAGE_IGNORED;
        std::vector<Composite*>::iterator iter;
        for( iter = this->components.begin(); iter != this->components.end(); ++iter )
        {
            r = (*iter)->handleMessage(msg, data);
            if( r == PHANTOM_MESSAGE_HANDLED)
                result = r;
            else if( r == PHANTOM_MESSAGE_CONSUMED )
                return PHANTOM_MESSAGE_CONSUMED;
        }
        return result;
    }

    void Composite::afterCollision( Composite *other )
    {
    }

    bool Composite::canCollideWith( Composite *other )
    {
        return true;
    }

    const Eigen::Vector3f& Composite::getPosition() {
        return this->_position;
    }

} /* namespace phantom */
