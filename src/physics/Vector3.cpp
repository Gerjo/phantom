#include "Vector3.h"
#include "utils/PhantomException.h"
namespace phantom{
    Vector3::Vector3(int x, int y, int z): x(static_cast<float>(x)), y(static_cast<float>(y)), z(static_cast<float>(z)){

    }

    Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z){

    }

    Vector3::Vector3(const Vector3& origin) {
        x = origin.x;
        y = origin.y;
        z = origin.z;
    }

    Vector3 Vector3::operator+(const Vector3& v){
        return Vector3(v.x + x, v.y + y, v.z + z);
    }

    Vector3 Vector3::operator-(const Vector3& v){
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    Vector3 Vector3::operator%(const Vector3& v){
        throw PhantomException("We're too lazy to implement this.");
        return Vector3(0,0,0);
    }

    float Vector3::operator*(const Vector3& v){
        float dotx = x * v.x;
        float doty = y * v.y;
        float dotz = z * v.z;

        return dotx + doty + dotz;
    }
    Vector3 Vector3::operator*(float f){
        return Vector3(x * f, y * f, z * f);
    }

    bool operator== (const Vector3& a, const Vector3& b) {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }

    bool operator!= (const Vector3& a, const Vector3& b) {
        return !(a == b);
    }

    //bool operator== (Vector3* a, Vector3* b) {
    //    return a->x == b->x && a->y == b->y && a->z == b->z;
    //}

    //bool operator!= (Vector3* a, Vector3* b) {
    //    return !(a == b);
    //}

    Vector3& Vector3::operator+=(const Vector3& v) {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    Vector3& Vector3::operator-=(const Vector3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;

        return *this;
    }

    std::string Vector3::toString() {
        stringstream ss;

        ss << "phantom::Vector3 (x: " << x << ", y: " << y << ", z: " << z << ".)";

        return ss.str();
    }
}