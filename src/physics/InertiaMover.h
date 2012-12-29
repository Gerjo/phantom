#ifndef INERTIAMOVER_H
#define	INERTIAMOVER_H

#include <physics/Vector3.h>
#include <core/Composite.h>
#include <utils/Time.h>
#include <deque>
#include <functional>
#include <physics/Pulse.h>
#include <CompileConfig.h>

namespace phantom {
    class LIBEXPORT InertiaMover : public Composite  {
    public:
        InertiaMover(void);

        void addPulse(Pulse pulse);
        void clear();
        virtual void update(const PhantomTime& time);
        virtual MessageState handleMessage(AbstractMessage* message);
        const Vector3& getDirection(void);
        const Vector3& getDominantDirection(void);

        bool isMoving(void) const;
        bool isStopped(void) const;

    private:
        std::deque<Pulse> _pulses;
        Vector3 _direction;
        Vector3 _velocity;
        float _speed;
        Pulse _dominant;

        Vector3 _maxVelocity;
    };
}

#endif	/* INERTIAMOVER_H */

