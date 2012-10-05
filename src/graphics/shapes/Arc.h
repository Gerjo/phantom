#ifndef ARC_H
#define ARC_H

#include <cmath>
#include <CompileConfig.h>
#include <graphics/shapes/Line.h>

namespace phantom{
	class LIBEXPORT Arc: public Line{
	public:
		float radius, start, end;
		Arc(float x, float y, float radius, float start, float end);
    private:
        void drawArc();
	};
} /* namespace phantom */

#endif /* ARC_H */