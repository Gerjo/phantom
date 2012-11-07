#ifndef COLOR_H
#define COLOR_H

#include "CompileConfig.h"

namespace phantom{
    struct LIBEXPORT Color {
    public:
        Color() : r(0), g(0), b(0), a(127) {

        }

        Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b), a(127) {

        }

        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a)  {

        }

        unsigned char r, g ,b, a;
    };

    namespace Colors {
        static Color RED(127, 0, 0);
        static Color GREEN(0, 127, 0);
        static Color BLUE(0, 0, 127);
        static Color WHITE(127, 127, 127);
        static Color BLACK(0, 0, 0);
        static Color CORNFLOWER(-27, 22, 110);
        static Color BROWN(32, 12, -15);
        static Color HOTPINK(127, -107, 20);
        static Color MIDNIGHTBLUE(25, 25, 112);
    }
}

#endif