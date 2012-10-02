#ifndef SHAPE_H_
#define SHAPE_H_
#include <Eigen/Geometry>
#include <graphics/Color.h>
#include <CompileConfig.h>
#include <vector>
#include <graphics/VerticeData.h>

namespace phantom {

    class LIBEXPORT Shape {
    public:
		std::vector<VerticeData> vertices;
        unsigned char* imageData;

        float x;
        float y;

        Color lineColor;
        Color fillColor;

        Shape();
        virtual ~Shape();

        void setFillColor(Color color);
        void setLineColor(Color color);

        virtual void addVertex(float x, float y, float texX = 0.0f, float texY = 0.0f);

        bool hasFillColor(void);
        bool hasLineColor(void);

    private:
        bool _hasFillColor;
        bool _hasLineColor;
    };
} /* namespace phantom */
#endif /* SHAPE_H_ */
