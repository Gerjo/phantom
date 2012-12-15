#ifndef PULSE_H
#define	PULSE_H

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
}

#endif	/* PULSE_H */

