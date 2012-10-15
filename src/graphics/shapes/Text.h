#ifndef TEXT_H_
#define TEXT_H_

#include <cmath>
#include <CompileConfig.h>
#include <graphics/shapes/Shape.h>

namespace phantom{
	class LIBEXPORT Text : public Shape {
	public:
        void *font;
        const unsigned char *text;

        Text(float x, float y, void *font, const unsigned char* text);
	};
}

#endif