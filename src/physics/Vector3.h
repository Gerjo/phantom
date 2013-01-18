#ifndef VECTOR3_H
#define VECTOR3_H

#include <CompileConfig.h>
#include <sstream>
#include <cmath>

// tmp:
#include <iostream>
using std::cout;
using std::endl;

namespace phantom {

    class LIBEXPORT Vector3 {
    public: //variables
        float x, y, z;

    public:

        // Pass this as the 3rd argument to the std::map ctor.
        struct MapLessComparefunctor {
            bool operator()(const Vector3& a, const Vector3 & b) {
                if (a.x == b.x) {
                    if (a.y == b.y) {
                        return a.z < b.z;
                    }
                    return a.y < b.y;
                }
                return a.x < b.x;
            }
        };

        Vector3();
        Vector3(float x, float y, float z = 0.0f);
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
        Vector3& operator+=(const float& v);
        Vector3& operator-=(const Vector3& v);
        Vector3& operator*=(const Vector3& v);
        Vector3& operator*=(const float& v);
        Vector3& operator/=(const Vector3& v);
        Vector3& operator/=(const float& v);

        bool operator==(const Vector3& v) const;
        bool operator!=(const Vector3& v) const;
        bool isFinite(void) const;
        bool isInfinite(void) const;

        Vector3& absolute();
        Vector3& normalize();
        Vector3& reverse();

        Vector3 directionTo(const Vector3& other) const;
        float distanceTo(const Vector3& other) const;
        float distanceToSq(const Vector3& other) const;
        float distanceToSq(const Vector3* other) const;
        float getLengthSq(void) const;
        float dot(const Vector3& v) const;
        float getAngleXOY() const;

        Vector3 perp(void) const;
        Vector3 cross(const Vector3& b) const;
        Vector3 projectOnto(const Vector3& b) const;

        std::string toString() const;
        std::string toString2() const;

        friend std::ostream& operator<<(std::ostream& o, const Vector3& v) {
            o << "[Vector3] (x: " << std::fixed << v.x << ", y: " << v.y << ", z: " << v.z << ")";
            return o;
        }

    };

} /* namespace phantom */

#endif /* VECTOR3_H */
