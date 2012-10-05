#ifndef BOX3_H
#define BOX3_H

#include "Vector3.h"
#include <CompileConfig.h>

namespace phantom{
    class LIBEXPORT Box3{
    public: //variables
        Vector3 min;
        Vector3 max;
    public:
        Box3(Vector3 min, Vector3 max);
        bool intersect(Box3& other){

        }
    };

} /* namespace phantom */

#endif /* BOX3_H */