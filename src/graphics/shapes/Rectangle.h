#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

namespace phantom{
    class LIBEXPORT Rectangle : public Shape {
    public:
        float width, height, thickness;
        Rectangle(float x, float y, float width, float height, bool isFilled, float thickness);
    private:
        void drawFilled();
        void drawOutline();
    };
}

#endif