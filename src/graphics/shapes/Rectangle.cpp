#include "Rectangle.h"
#include "Line.h"

namespace phantom{

    Rectangle::Rectangle(float x, float y, float width, float height, bool isFilled, float thickness){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->thickness = thickness;

        if(isFilled) drawFilled();
        else drawOutline();
    }

    void Rectangle::drawFilled() {
        addVertex(0.0f, 0.0f);
        addVertex(width, 0.0f);
        addVertex(0.0f, height);

        addVertex(0.0f, height);
        addVertex(width, height);
        addVertex(width, 0.0f);
    }

    void Rectangle::drawOutline() {
        //Top
        addVertex(0.0f, 0.0f);
        addVertex(width, 0.0f);
        addVertex(0.0f, thickness);

        addVertex(0.0f, thickness);
        addVertex(width, thickness);
        addVertex(width, 0.0f);

        //Left
        addVertex(0.0f, thickness);
        addVertex(thickness, thickness);
        addVertex(0.0f, height);

        addVertex(0.0f, height);
        addVertex(thickness, height);
        addVertex(thickness, thickness);

        //Right
        addVertex(width-thickness, thickness);
        addVertex(width, thickness);
        addVertex(width-thickness, height);

        addVertex(width-thickness, height);
        addVertex(width, height);
        addVertex(width, thickness);

        //Bottom
        addVertex(thickness, height-thickness);
        addVertex(thickness, height);
        addVertex(width-thickness, height-thickness);

        addVertex(width-thickness, height-thickness);
        addVertex(width-thickness, height);
        addVertex(thickness, height);
    }

}