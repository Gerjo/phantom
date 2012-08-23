/*
 * Composite.h
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#define PHANTOM_MESSAGE_IGNORED  0
#define PHANTOM_MESSAGE_HANDLED  1
#define PHANTOM_MESSAGE_CONSUMED 2

#include <sstream>
#include <vector>

namespace phantom {

class Composite {
public:

	unsigned int flags;
	bool destroyed;

	Composite();
	virtual ~Composite();

	virtual void onAdd( Composite *parent );
	virtual void onAnsestorChanged();

	virtual void addComponent( Composite *component );
	virtual bool removeComponent( Composite *component );
	virtual bool destroyComponent( Composite *component );
	virtual bool destroyComponentAt( size_t index );

	virtual unsigned int handleMessage( const char *message, void *data );

	virtual void update( float elapsed );
	virtual void intergrate( float elapsed );
	virtual void render( void* context );

	virtual bool canCollideWith( Composite *other );
	virtual void afterCollision( Composite *other );

    friend std::ostream& operator<<(std::ostream &s, const Composite *c) {
        return s << "Composite(" << c->components.size() << ")";
    }
private:
	Composite* parent;
	std::vector<Composite*> components;

};

}

#endif /* COMPOSITE_H_ */
