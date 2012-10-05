#ifndef LAYER_H_
#define LAYER_H_

#include <utils/PhantomException.h>
#include <core/GameState.h>
#include <core/Composite.h>
#include <CompileConfig.h>
#include <iostream>

using namespace std;

namespace phantom {

    class LIBEXPORT Layer : public Composite {
    public:
        Layer(void);

    };

} /* namespace phantom */
#endif /* LAYER_H_ */
