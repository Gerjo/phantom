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
        virtual void removeHealth(float amount);
        virtual void update(const Time& time);

    protected:
        Mover* mover;
        float _health;
        float _totalHealth;

        virtual void setHealth(float value);
    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
