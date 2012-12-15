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
    }

    void InertiaMover::clear() {
        _pulses.clear();
    }

    void InertiaMover::update(const PhantomTime& time) {
        Composite::update(time);

        if (_pulses.empty()) {
            return;
        }

        Vector3 speed(0, 0, 0);
        Vector3 direction(0, 0, 0);
        unsigned numPulses = 0;

        const float elapsed = static_cast<float> (time.getElapsed());

        for (auto it = _pulses.begin(); it != _pulses.end(); ++it) {
            bool erase = false;
            Pulse& pulse = *it;

            if (pulse.speed > 0) {
                // Accumulate all forces.
                speed += pulse.speed * elapsed;
                direction += pulse.direction;
                ++numPulses;

                // Post update removal, this means we can create one-off pulses.
                pulse.speed -= 2 * pulse.friction * pulse.friction * elapsed;
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

        if (numPulses == 0) {
            return;
        }

        // Averages of all:
        speed /= numPulses;
        direction /= numPulses;

        const Vector3 velocity = speed * direction;

        getParent()->addPosition(velocity);
    }
}