#ifndef LINE_H
#define LINE_h

#include "Shape.h"
#include <stdio.h>
#include <CompileConfig.h>

namespace phantom{
	class LIBEXPORT Line : public Shape{
		float toX, toY;
    public:
		Line(float x, float y, float toX, float toY);

		virtual void drawLine(float x, float y, float toX, float toY, float offsetX, float offsetY);
	};
} /* namespace phantom */

#endif /* LINE_H */