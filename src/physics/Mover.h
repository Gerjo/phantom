#ifndef MOVER_H_
#define MOVER_H_

#include <core/Composite.h>

namespace phantom {

class Mover: public phantom::Composite
{
public:
    Mover();
    virtual ~Mover();
};

} /* namespace phantom */
#endif /* MOVER_H_ */
