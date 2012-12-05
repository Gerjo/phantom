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

    class LIBEXPORT Entity : public Composite {
    public:
        Entity();
        virtual void addComponent(Composite *component);
        virtual void update(const PhantomTime& time);

        // BSP and pathfinding experimental gimmicks:
        unsigned solidState;
        unsigned solidType;

        float distanceTo(Entity* gob);
        float distanceToSq(Entity* gob);
        Vector3 directionTo(Entity* gob);
    protected:
        Mover* mover;

    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
