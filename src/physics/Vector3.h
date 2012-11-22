#ifndef VECTOR3_H
#define VECTOR3_H

#include <CompileConfig.h>
#include <sstream>
#include <cmath>

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

        Vector3 operator+(const Vector3& v) const;
        Vector3 operator-(const Vector3& v) const;
        Vector3 operator%(const Vector3& b) const;
        Vector3 operator/(const Vector3& v) const;
        Vector3 operator*(const Vector3& v) const;
        Vector3 operator*(float f) const;
        
        Vector3& operator+=(const Vector3& v);
        Vector3& operator-=(const Vector3& v);
        Vector3& operator*=(const Vector3& v);
        Vector3& operator*=(const float& v);

        bool operator== (const Vector3& v) const;
        bool operator!= (const Vector3& v) const;

        Vector3& absolute();
        Vector3& normalize();

        float distanceTo(const Vector3& other) const;
        float distanceToSq(const Vector3& other) const;
        float getLengthSq(void) const;
        float dot(const Vector3& v) const;
        
        Vector3 perp(void) const;
        Vector3 cross(const Vector3& b) const;
        Vector3 projectOnto(const Vector3& b) const;
        
        std::string toString();

        friend std::ostream& operator<<(std::ostream& o, const Vector3& v){
            o << "[Vector3] (x: " << v.x << ", y: " << v.y << ", z: " << v.z;
            return o;
        }
    };

} /* namespace phantom */

#endif /* VECTOR3_H */
