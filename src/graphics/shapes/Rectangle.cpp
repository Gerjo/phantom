#include "Rectangle.h"
#include <Eigen/Geometry>
namespace phantom{

    Rectangle::Rectangle(float x, float y, float width, float height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        addVertex(0.0f, 0.0f);
        addVertex(width, 0.0f);
        addVertex(0.0f, height);

        addVertex(0.0f, height);
        addVertex(width, height);
        addVertex(width, 0.0f);
    }
    void Rectangle::addVertex(float x, float y){
        Eigen::Vector2f v(x, y);
        vertices.push_back(v);
    }


}