#ifndef ENTITY_H_
#define ENTITY_H_

#include <core/Composite.h>
#include <physics/Box3.h>

namespace phantom {

    enum SolidStateBits {
        NOT_SOLID     = 0,
        PLAYER        = 1,
        ALT_A         = 2,
        ALT_B         = 4,
        ALT_C         = 8,
        ALT_D         = 16,
        ALT_E         = 32,
        SOLID_FOR_ALL = 0xffffff
    };


    class EntityLayer;
    class Mover;
    class InertiaMover;

    class LIBEXPORT Entity : public Composite {
    public:
        Entity();
        
        /**
        * All components that get added to the Entity component are checked if they are of the Mover or InertiaMover type. They can only exist once for every class.
        *
        * @param component The component you want to add.
        */
        virtual void addComponent(Composite *component);

        // BSP and pathfinding experimental gimmicks:
        unsigned solidState;
        unsigned solidType;

        /**
        * Calculate the distance to another entity. Please consider using distanceToSq, since it's faster.
        *
        * @return Returns the distance to another entity.
        * @param gob The entity you want to measure the distance to.
        */
        float distanceTo(Entity* gob);

        /**
        * Calculate the distance to another entity squared. This is faster than distanceTo, because it's not calling the heavy sqrt function.
        *
        * @return Returns the distance squared to the other entity.
        * @param gob The entity you want to measure the distance squared to.
        */
        float distanceToSq(Entity* gob);
        
        /**
        * Get the normalized direction vector to another entity.
        *
        * @return Returns the direction vector to another entity.
        * @param gob The entity you want calculate the direction to.
        */
        Vector3 directionTo(Entity* gob);

        // To be renamed to "mover" once it works.
        InertiaMover* inertia;
    protected:
        Mover* mover;

    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
