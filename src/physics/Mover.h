#ifndef MOVER_H_
#define MOVER_H_

#include <core/Composite.h>
#include <CompileConfig.h>
#include <deque>
#include <utils/Timer.h>
#include <iostream>

namespace phantom {
    class Entity;

    class LIBEXPORT Mover: public phantom::Composite{
    public:
        Mover();
        void setMovementSpeed(float value);
        void moveTo(Vector3 vector);
        void moveTo(const std::deque<Vector3> vList);
        virtual void update(const PhantomTime& time);
        virtual void onAnsestorChanged();
        void stop();
        bool isStopped();
        Vector3 getTarget();
        void pause(double delay);
        bool isPaused();

    private:
        std::deque<Vector3>::iterator _it;
        std::deque<Vector3> _targetList;
        Vector3 _target;
        Entity* _parent;
        Timer _pauseTimer;
        float _movementSpeed;
    };

} /* namespace phantom */
#endif /* MOVER_H_ */
