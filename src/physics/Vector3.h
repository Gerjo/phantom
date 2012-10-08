#ifndef VECTOR3_H
#define VECTOR3_H

#include <CompileConfig.h>
#include <sstream>

namespace phantom{

    class LIBEXPORT Vector3{
    public: //variables
        float x,y,z;
    public:
        Vector3();
        Vector3(float x, float y, float z= 0.0f);
        Vector3(int x, int y, int z = 0);
        Vector3(double x, double y, double z = 0.0);

        Vector3(const Vector3& origin);

        Vector3 operator+(const Vector3& v);
        Vector3 operator-(const Vector3& v);
        Vector3 operator%(const Vector3& v);
        Vector3 operator/(const Vector3& v);
        Vector3& operator+=(const Vector3& v);
        Vector3& operator-=(const Vector3& v);
        float operator*(const Vector3& v);

        Vector3 operator*(float f);

        bool operator== (const Vector3& v) const;
        bool operator!= (const Vector3& v) const;

        //friend bool operator== (Vector3* a, Vector3* b);
        //friend bool operator!= (Vector3* a, Vector3* b);

        std::string toString();
    };

} /* namespace phantom */

#endif /* VECTOR3_H */