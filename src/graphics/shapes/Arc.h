#ifndef ARC_H
#define ARC_H

#include "Shape.h"

namespace phantom{
	class LIBEXPORT Arc: public Shape{
	public:
		float radius, start, end;
		Arc(float x, float y, float radius, float start, float end);
    private:
        void drawArc();
	};
} /* namespace phantom */

#endif /* ARC_H */