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

        Vector3 direction(0, 0, 0);
        float speed         = 0;
        unsigned numPulses  = 0;
        float totalWeight   = 0;
        const float elapsed = static_cast<float> (time.getElapsed());



        for (auto it = _pulses.begin(); it != _pulses.end(); ++it) {
            bool erase   = false;
            Pulse& pulse = *it;

            if (pulse.speed > 0) {
                totalWeight += static_cast<float>(pulse.weight);

                // Accumulate all forces.
                speed     += pulse.weight * pulse.speed * elapsed;
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
        if(_dominant.speed > 0) {
            direction += _dominant.direction;

            if(numPulses > 0) {
                direction /= 2;
                speed += _dominant.speed * _dominant.weight;
                speed /= static_cast<float>(1 + _dominant.weight);
            } else {
                speed += _dominant.speed;
            }
        }

        _velocity  = direction * speed;
        _speed     = speed;
        _direction = direction;
        _direction.normalize();

        getParent()->addPosition(_velocity);
    }

    bool InertiaMover::isMoving(void) const {
        const float epsilon = 0.001f;
        return _speed > epsilon;
    }

    bool InertiaMover::isStopped(void) const {
        return !isMoving();
    }
}
