#ifndef VECTOR3_H
#define VECTOR3_H

#include <CompileConfig.h>

namespace phantom{

    class LIBEXPORT Vector3{
    public: //variables
        float x,y,z;
    public:
        Vector3(float x, float y, float z);
    };

} /* namespace phantom */

#endif /* VECTOR3_H */