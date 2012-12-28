#include <limits>

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

    Vector3 Vector3::operator+(const Vector3& v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3 Vector3::operator-(const Vector3& v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    Vector3 Vector3::operator%(const Vector3& b) const{
        return this->cross(b);
    }

    float Vector3::dot(const Vector3& v) const{
        float dotx = x * v.x;
        float doty = y * v.y;
        float dotz = z * v.z;

        return dotx + doty + dotz;
    }

    float Vector3::getAngleXOY() const {
        // NB: y and x are intentionally flipped.
        return atan2(y, x) * 180 / 3.14159f;
    }

    Vector3 Vector3::operator*(float f) const {
        return Vector3(x * f, y * f, z * f);
    }

    Vector3 Vector3::operator*(const Vector3& v) const {
        Vector3 multiplied(
                x * v.x,
                y * v.y,
                z * v.z
        );

        return multiplied;
    }

    Vector3 Vector3::operator/(const Vector3& v) const {
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

    bool Vector3::isFinite(void) const {
        return abs(x) != std::numeric_limits<float>::infinity()
                 &&
               abs(y) != std::numeric_limits<float>::infinity()
                 &&
               abs(y) != std::numeric_limits<float>::infinity();
    }

    bool Vector3::isInfinite(void) const{
        return !isFinite();
    }

    Vector3& Vector3::operator+=(const Vector3& v) {
        x += v.x;
        y += v.y;
        z += v.z;

        return *this;
    }

    Vector3& Vector3::operator+=(const float& v) {
        x += v;
        y += v;
        z += v;

        return *this;
    }

    Vector3& Vector3::operator-=(const Vector3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;

        return *this;
    }

    Vector3& Vector3::operator*=(const Vector3& v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;

        return *this;
    }

    Vector3& Vector3::operator*=(const float& v) {
        x *= v;
        y *= v;
        z *= v;

        return *this;
    }

    Vector3& Vector3::operator/=(const Vector3& v) {
        x /= v.x;
        y /= v.y;
        z /= v.z;

        return *this;
    }

    Vector3& Vector3::operator/=(const float& v) {
        x /= v;
        y /= v;
        z /= v;

        return *this;
    }

    Vector3& Vector3::normalize() {
        float len = sqrt(x*x + y*y + z*z);

        // It's OK to do nothing here. In fact, things such as project will
        // break if you pull random gimmicks here, EG: it fine to project
        // a line onto a 0,0 ray - we actually rely on this behavior.

        if(len == 0) {
            return *this;
        }

        if(len == 1) {
            return *this;
        }

        x /= len;
        y /= len;
        z /= len;

        return *this;
    }

    Vector3& Vector3::absolute() {
        x = abs(x);
        y = abs(y);
        z = abs(z);

        return *this;
    }

    Vector3& Vector3::reverse() {
        // TODO: does this play OK with zero?
        x = -x;
        y = -y;
        z = -z;

        return *this;
    }

    Vector3 Vector3::directionTo(const Vector3& other) const {
        Vector3 direction(
            other.x - x,
            other.y - y,
            other.z - z
        );

        direction.normalize();

        return direction;
    }

    float Vector3::distanceTo(const Vector3& other) const {
        float diffX = other.x - x;
        float diffY = other.y - y;
        float diffZ = other.z - z;

        return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
    }

    float Vector3::distanceToSq(const Vector3& other) const {
        float diffX = other.x - x;
        float diffY = other.y - y;
        float diffZ = other.z - z;

        return diffX * diffX + diffY * diffY + diffZ * diffZ;
    }

    float Vector3::getLengthSq(void) const {
        return x*x + y*y + z*z;
    }

    std::string Vector3::toString() const {
        stringstream ss;

        ss << "phantom::Vector3 (x: " << std::fixed << x << ", y: " << y << ", z: " << z << ")";

        return ss.str();
    }

    std::string Vector3::toString2() const {
        stringstream ss;

        ss << "vector(" << x << ", " << y << ")";

        return ss.str();
    }

    Vector3 Vector3::perp(void)const {
        if(this->z != 0) {
            throw PhantomException(
                    "Vector3::perp: The perpendicular method only works"
                    " on 2D vectors. Use the cross product with a pane"
                    " instead for 3D operations. In addition to that, it"
                    " might also be possible that you're trying to calculate"
                    " the perp of a nullptr Vector3, GCC let's you do that."
            );
        }

        // Left hand side, right hand side... does it really matter?
        Vector3 perp(
            -y,
             x,
             0.0f
        );

        return perp;
    }

    Vector3 Vector3::projectOnto(const Vector3& b) const {
        const float dp  = dot(b);
        const float len = b.getLengthSq();

        Vector3 projection(
            dp / len * b.x,
            dp / len * b.y,
            dp / len * b.z
        );

        return projection;
    }

    Vector3 Vector3::cross(const Vector3& b) const {

        const Vector3& a = *this;

        Vector3 cross(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );

        return cross;
    }
}
