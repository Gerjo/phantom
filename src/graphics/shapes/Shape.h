#ifndef SHAPE_H_
#define SHAPE_H_
#include <Eigen/Geometry>
#include <graphics/Color.h>
#include <CompileConfig.h>
#include <vector>

namespace phantom {

    class LIBEXPORT Shape {
    public:
        std::vector<Eigen::Vector2f> vertices;

        float x;
        float y;

        Color lineColor;
        Color fillColor;

        Shape();
        virtual ~Shape();

        void setFillColor(Color color);
        void setLineColor(Color color);

        virtual void addVertex(float x, float y);

    };
} /* namespace phantom */
#endif /* SHAPE_H_ */
