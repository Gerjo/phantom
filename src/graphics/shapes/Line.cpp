#include "Line.h"

namespace phantom{
    Line::Line(float x, float y, float toX, float toY){
        this->x = x;
        this->y = y;
        this->toX = toX;
        this->toY = toY;
        float yOffset, xOffset;
        if(x <= 0){
            xOffset = 4.0f;
            yOffset = 0.0f;
        }else{
            xOffset = 0.0f;
            yOffset = 4.0f;
        }
        addVertex(0.0f,0.0f);
        addVertex(toX,toY);
        addVertex(xOffset,yOffset);

        addVertex(xOffset, yOffset);
        addVertex(toX+xOffset,toY+yOffset);
        addVertex(toX,toY);
    }
} /* namespace phantom */