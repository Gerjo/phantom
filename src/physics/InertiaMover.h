#ifndef INERTIAMOVER_H
#define	INERTIAMOVER_H

#include <physics/Vector3.h>
#include <core/Composite.h>
#include <utils/Time.h>
#include <deque>
#include <functional>
#include <physics/Pulse.h>

namespace phantom {
    class InertiaMover : public Composite  {
    public:
        virtual void addPulse(Pulse pulse);
        virtual MessageState handleMessage(AbstractMessage* message);
        void clear();
        virtual void update(const PhantomTime& time);

    private:
        std::deque<Pulse> _pulses;

    };
}

#endif	/* INERTIAMOVER_H */

