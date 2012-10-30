#ifndef TEXT_H_
#define TEXT_H_

#include <cmath>
#include <CompileConfig.h>
#include <graphics/shapes/Shape.h>
#include <graphics/FreeTypeFont.h>
#include <string>

namespace phantom{
	class LIBEXPORT Text : public Shape {
	public:
        const char *text;
        const char *font;
        FreeTypeFont *ftfont;

        unsigned int size;
        Text(float x, float y, unsigned int size, const char *font, const char *text);

        void genVertices(const char *text, FreeTypeFont *font);
	};
}

#endif