#ifndef COLOR_H
#define COLOR_H

#include "CompileConfig.h"

namespace phantom{

	struct LIBEXPORT Color {
        Color() : a(0), r(0), g(0), b(0) {

        }

		unsigned char a, r, g ,b;
	};
}

#endif