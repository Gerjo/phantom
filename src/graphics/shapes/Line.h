#ifndef LINE_H
#define LINE_h

#include "Shape.h"
#include <stdio.h>
namespace phantom{
	class LIBEXPORT Line: public Shape{
		float toX, toY;
    public:
		Line(float x, float y, float toX, float toY);
	};
} /* namespace phantom */

#endif /* LINE_H */