#include "Rectangle.h"
#include <Eigen/Geometry>
namespace phantom{

    Rectangle::Rectangle(float x, float y, float width, float height){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        addVertex(x,y);
        addVertex(x+width, y);
        addVertex(x, y+height);

        addVertex(x, y+height);
        addVertex(x+width, y + height);
        addVertex(x+width, y);
    }
    void Rectangle::addVertex(float x, float y){
        Eigen::Vector2f v(x, y);
        vertices.push_back(v);
    }


}