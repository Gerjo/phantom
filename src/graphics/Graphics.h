#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <vector>


#include <CompileConfig.h>

#include "shapes/Shape.h"

using namespace std;

namespace phantom {

class LIBEXPORT Graphics {
public:
    Graphics(void);

private:
    vector<Shape> _shapes;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
