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
        Shape();
        virtual ~Shape();


		std::vector<VerticeData> vertices;
        unsigned char* imageData;

        float x;
        float y;

        void setFillColor(Color color);
        void setLineColor(Color color);

        virtual void addVertex(float x, float y, float texX = 0.0f, float texY = 0.0f);

        bool hasFillColor(void);
        bool hasLineColor(void);

        const Color& getLineColor();
        const Color& getFillColor();

    private:
        bool _hasFillColor;
        bool _hasLineColor;
        Color _lineColor;
        Color _fillColor;
    };
} /* namespace phantom */
#endif /* SHAPE_H_ */
