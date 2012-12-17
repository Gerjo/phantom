#include "InertiaMover.h"

namespace phantom {

    void InertiaMover::addPulse(Pulse pulse) {
        _pulses.push_back(pulse);
    }

    MessageState InertiaMover::handleMessage(AbstractMessage* message) {
        if (message->isType("add-pulse")) {
            Pulse pulse = message->getPayload<Pulse > ();
            addPulse(pulse);

            return CONSUMED;
        }

        if (message->isType("clear-pulses")) {
            clear();

            return CONSUMED;
        }

        if (message->isType("set-dominant-pulse")) {
            dominant = message->getPayload<Pulse>();
            //cout << "set-dominant-pulse: " << dominant.toString() << endl;
            return CONSUMED;
        }
    }


    void InertiaMover::clear() {
        _pulses.clear();
    }

    void InertiaMover::update(const PhantomTime& time) {
        Composite::update(time);


        Vector3 speed(0, 0, 0);
        Vector3 direction(0, 0, 0);
        unsigned numPulses = 0;

        const float elapsed = static_cast<float> (time.getElapsed());

        unsigned totalWeight = 0;

        for (auto it = _pulses.begin(); it != _pulses.end(); ++it) {
            bool erase = false;
            Pulse& pulse = *it;

            if (pulse.speed > 0) {
                totalWeight += pulse.weight;

                // Accumulate all forces.
                speed += pulse.weight * pulse.speed * elapsed;
                direction += pulse.direction;
                ++numPulses;

                // Post update removal, this means we can create one-off pulses.
                pulse.speed -= pulse.weight * 2 * pulse.friction * pulse.friction * elapsed;
            } else {
                erase = true;
            }

            if (erase) {
                it = _pulses.erase(it);
                if (it == _pulses.end()) {
                    break;
                }
            }
        }

        if (numPulses > 0) {
            // We're using a weighted average:
            speed /= totalWeight;
            direction /= totalWeight;
        }

        // Quite possibly move this to a sub class, it's rather specific for a
        // certain purpose.
        if(dominant.speed > 0) {

            direction += dominant.direction;
            direction /= 2;

            if(numPulses > 0) {
                speed += dominant.speed * dominant.weight;
                speed /= 1 + dominant.weight;
            } else {
                speed += dominant.speed;
            }

        }

        const Vector3 velocity = direction * speed;

        getParent()->addPosition(velocity);
    }
}
