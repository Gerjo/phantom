#include <pch.h>
#include "Arc.h"

namespace phantom{
    Arc::Arc(float x, float y, float radius, float start, float end) : Line(0.0f, 0.0f, 0.0f, 0.0f) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->start = start;
        this->end = end;
        drawArc();
    }

    void Arc::drawArc(){
		float stepsize = static_cast<float>(3.14159f/13);
        float vx, vy, vx1,vy1;
        float angle, ang0, ang1;

        ang0 = start;
        ang1 = end;

        for(angle = ang0; angle <= ang1; angle+= stepsize) {
            vx = radius*cos(angle);
            vy = radius*sin(angle);
            vx1 = radius*cos(angle + stepsize);
            vy1 = radius*sin(angle + stepsize);

			Line::drawLine(vx1, vy1, vx, vy, vx1, vy1);
        }
    }
} /* namespace Phantom */