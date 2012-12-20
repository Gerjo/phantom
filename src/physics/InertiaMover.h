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
        Pulse dominant;
        
        void addPulse(Pulse pulse);
        void clear();
        virtual void update(const PhantomTime& time);
        virtual MessageState handleMessage(AbstractMessage* message);

    private:
        std::deque<Pulse> _pulses;
    };
}

#endif	/* INERTIAMOVER_H */

