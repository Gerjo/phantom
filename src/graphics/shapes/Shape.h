#ifndef SHAPE_H_
#define SHAPE_H_

#include <graphics/Color.h>
#include <CompileConfig.h>
namespace phantom {

	class LIBEXPORT Shape {
	public:
		float x, y;
		Color lineColor;
		Color fillColor;

		Shape();
		virtual ~Shape();

        void setFillColor(Color color);
        void setLineColor(Color color);

	};
} /* namespace phantom */
#endif /* SHAPE_H_ */
