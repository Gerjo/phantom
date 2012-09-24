#include "Arc.h"
#define STEPSIZE M_PI/ 45

namespace phantom{
    Arc::Arc(float x, float y, float radius, float start, float end){
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->start = start;
        this->end = end;
        drawArc();
    }
    void Arc::drawArc(){
        double vx, vy, vx1,vy1;
        double angle, ang0, ang1;

        ang0 = start * (M_PI/180.0);
        ang1 = end * (M_PI/180.0);

        for(angle = ang0; angle <= ang1+STEPSIZE; angle+= STEPSIZE){
            vx = x + radius*cos(angle);
            vy = y + radius*sin(angle);
            vx1 = x + (radius - 1.0f)*cos(angle + STEPSIZE);
            vy1 =  y + (radius - 1.0f)*sin(angle + STEPSIZE);

            addVertex(vx,vy);
            addVertex(vx1,vy);
            addVertex(vx,vy1);
            
            addVertex(vx,vx1);
            addVertex(vx1,vy1);
            addVertex(vx,vy);
        }
    }
} /* namespace Phantom */ 