#ifndef PULSE_H
#define	PULSE_H

#include <sstream>
#include <string>
using std::stringstream;
using std::string;

namespace phantom {
    struct Pulse {
        static const int FOREVER = -1;

        Pulse() : direction(0, 0, 0), speed(0), friction(0), weight(1) {

        }

        Pulse(Vector3 _direction, float _speed, float _friction = 0.0)
        : direction(_direction), speed(_speed), friction(_friction) {

        }

        Vector3 direction;
        float speed;
        float friction;
        char weight;

        string toString(void) {
            stringstream ss;
            ss << "Direction: " << std::fixed << direction.x << " " << direction.y << " " << direction.z;
            ss << " speed: " << speed << " friction: " << friction;

            return ss.str();
        }
    };
}

#endif	/* PULSE_H */

