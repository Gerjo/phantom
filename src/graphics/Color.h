#ifndef COLOR_H
#define COLOR_H

#include "CompileConfig.h"

namespace phantom{

    // NB: using local typedef, makes the code readable.
    typedef unsigned char byte;

	struct LIBEXPORT Color {
    public:
        Color() : r(0), g(0), b(0), a(127) {

        }

        Color(byte r, byte g, byte b) : r(r), g(g), b(b), a(127) {

        }

        Color(byte r, byte g, byte b, byte a) : r(r), g(g), b(b), a(a)  {

        }

		byte r, g ,b, a;

        static Color RED;
        static Color GREEN;
        static Color BLUE;
        static Color WHITE;
        static Color BLACK;
        static Color CORNFLOWER;
        static Color BROWN;
        static Color HOTPINK;
	};
}

#endif