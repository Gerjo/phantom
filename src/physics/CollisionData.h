#ifndef COLLISIONDATA_H
#define	COLLISIONDATA_H

namespace phantom {
    struct CollisionData {
        CollisionData() : wasHandled(false) {

        }

        bool wasHandled;
    };
}
#endif	/* COLLISIONDATA_H */

