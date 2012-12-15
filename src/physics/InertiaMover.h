#ifndef INERTIAMOVER_H
#define	INERTIAMOVER_H

#include <physics/Vector3.h>
#include <core/Composite.h>
#include <utils/Time.h>
#include <deque>
#include <functional>

namespace phantom {

    struct Pulse {
        static const int FOREVER = -1;

        Pulse() : direction(0, 0, 0), speed(0), friction(0) {

        }

        Pulse(Vector3 _direction, float _speed, float _friction = 0.0)
        : direction(_direction), speed(_speed), friction(_friction) {

        }

        Vector3 direction;
        float speed;
        float friction;
    };




    class IntertiaMover : public Composite  {
    public:

        virtual void addPulse(Pulse pulse) {
            _pulses.push_back(pulse);
        }

        virtual MessageState handleMessage(AbstractMessage* message) {
            if(message->isType("add-pulse")) {
                Pulse pulse = message->getPayload<Pulse>();
                addPulse(pulse);

                return CONSUMED;
            }

            if(message->isType("clear-pulses")) {
                clear();

                return CONSUMED;
            }
        }

        void clear() {
            _pulses.clear();
        }

        virtual void update(const PhantomTime& time) {
            Composite::update(time);

            if(_pulses.empty()) {
                return;
            }

            Vector3 speed(0, 0, 0);
            Vector3 direction(0, 0, 0);
            unsigned numPulses = 0;

            const float elapsed = static_cast<float>(time.getElapsed());

            for(auto it = _pulses.begin(); it != _pulses.end(); ++it) {
                bool erase = false;
                Pulse& pulse = *it;

                if(pulse.speed > 0) {
                    // Accumulate all forces.
                    speed       += pulse.speed * elapsed;
                    direction   += pulse.direction;
                    ++numPulses;
                } else {
                    erase    = true;
                }

                // Post update removal, this means we can create one-off pulses.
                pulse.speed -= 2 * pulse.friction * pulse.friction * elapsed;

                if(erase) {
                    it = _pulses.erase(it);
                    if(it == _pulses.end()) {
                        break;
                    }
                }
            }

            if(numPulses == 0) {
                return;
            }

            // Averages of all:
            speed     /= numPulses;
            direction /= numPulses;

            const Vector3 velocity = speed * direction;

            getParent()->addPosition(velocity);
        }

    private:
        std::deque<Pulse> _pulses;

    };
}

#endif	/* INERTIAMOVER_H */

