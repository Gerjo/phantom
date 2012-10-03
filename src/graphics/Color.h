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
    }
}

#endif