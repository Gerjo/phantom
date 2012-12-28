#include "InertiaMover.h"

namespace phantom {

    void InertiaMover::addPulse(Pulse pulse) {
        _pulses.push_back(pulse);
    }

    const Vector3& InertiaMover::getDirection(void) {
        return _direction;
    }

    const Vector3& InertiaMover::getDominantDirection(void) {
        return _dominant.direction;
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

        if (message->isType("clear-dominant")) {
            _dominant.speed = 0.0f;
            return CONSUMED;
        }

        if (message->isType("halt")) {
            clear();
            _dominant.speed = 0.0f;
            return CONSUMED;
        }

        if (message->isType("set-dominant-pulse")) {
            _dominant = message->getPayload<Pulse>();
            return CONSUMED;
        }

        return Composite::handleMessage(message);
    }


    void InertiaMover::clear() {
        _pulses.clear();
    }

    void InertiaMover::update(const PhantomTime& time) {
        Composite::update(time);


        float speed = 0;
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
            speed /= static_cast<float>(totalWeight);
            direction /= static_cast<float>(totalWeight);
        }

        // Quite possibly move this to a sub class, it's rather specific for a
        // certain purpose.
        if(_dominant.speed > 0) {

            direction += _dominant.direction;
            direction /= 2;

            if(numPulses > 0) {
                speed += _dominant.speed * _dominant.weight;
                speed /= static_cast<float>(1 + _dominant.weight);
            } else {
                speed += _dominant.speed;
            }
        }

        const Vector3 velocity = direction * speed;

        getParent()->addPosition(velocity);

        _direction = direction;
        _direction.normalize();
    }
}
