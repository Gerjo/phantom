#include "Composite.h"
#include <iostream>

namespace phantom {


Composite::Composite() : flags(0), destroyed(0), parent(0) {
    this->components = std::vector<Composite*>();
}

Composite::~Composite() {
	std::vector<Composite*>::iterator iter;
	for( iter = this->components.begin(); iter != this->components.end(); ++iter )
		delete *iter;
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

void Composite::update(float elapsed)
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

void Composite::intergrate(float elapsed)
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

} /* namespace phantom */
