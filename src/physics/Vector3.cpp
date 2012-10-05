#include "Vector3.h"
#include "utils/PhantomException.h"
namespace phantom{
    Vector3::Vector3(int x, int y, int z): x(static_cast<float>(x)), y(static_cast<float>(y)), z(static_cast<float>(z)){

    }

    Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z){

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
}