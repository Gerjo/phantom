#ifndef ENTITY_H_
#define ENTITY_H_

#include <core/Composite.h>
#include <physics/Box3.h>

namespace phantom {
    class EntityLayer;
    class Mover;

    class LIBEXPORT Entity : public Composite {
    public:
        Entity();
        virtual void addComponent(Composite *component);

    protected:
        Mover* mover;
        
    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
