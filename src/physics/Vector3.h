#ifndef VECTOR3_H
#define VECTOR3_H

#include <CompileConfig.h>

namespace phantom{

    class LIBEXPORT Vector3{
    public: //variables
        float x,y,z;
    public:
        Vector3(float x, float y, float z);

        Vector3& operator+(const Vector3& v);
        Vector3& operator-(const Vector3& v);
        Vector3& operator%(const Vector3& v);
        float operator*(const Vector3& v);

        Vector3& operator*(float f);
        
    };

} /* namespace phantom */

#endif /* VECTOR3_H */