#include "Vector3.h"
#include "utils/PhantomException.h"
namespace phantom{
    Vector3::Vector3() : x(0), y(0), z(0) {
    }

    Vector3::Vector3(int x, int y, int z): x(static_cast<float>(x)), y(static_cast<float>(y)), z(static_cast<float>(z)){
    }

    Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z){
    }

    Vector3::Vector3(double x, double y, double z): x(static_cast<float>(x)), y(static_cast<float>(y)), z(static_cast<float>(z)) {
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

    Vector3 Vector3::operator/(const Vector3& v) {
        Vector3 lol = Vector3(0, 0, 0);
        if(v.x != 0 && x != 0) lol.x = x / v.x;
        if(v.y != 0 && y != 0) lol.y = y / v.y;
        if(v.z != 0 && z != 0) lol.z = x / v.z;

        return lol;
    }

    bool Vector3::operator== (const Vector3& v) const {
        return this->x == v.x && this->y == v.y && this->z == v.z;
    }

    bool Vector3::operator!= (const Vector3& v) const {
        return !(*this == v);
    }

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

    void Vector3::normalize() {
        float len = sqrt(x*x + y*y + z*z);

        // What do we do here?
        if(len == 0) {
            return;
        }

        x /= len;
        y /= len;
        z /= len;
    }

    void Vector3::absolute() {
        x = abs(x);
        y = abs(y);
        z = abs(z);
    }

    float Vector3::distanceToSq(const Vector3& other) {
        float diffX = other.x - x;
        float diffY = other.y - y;
        float diffZ = other.z - z;

        return diffX * diffX + diffY * diffY + diffZ * diffZ;
    }

    float Vector3::getLengthSq(void) {
        return x*x + y*y + z*z;
    }

    std::string Vector3::toString() {
        stringstream ss;

        ss << "phantom::Vector3 (x: " << x << ", y: " << y << ", z: " << z << ".)\n";

        return ss.str();
    }
}