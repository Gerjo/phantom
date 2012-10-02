#ifndef MOVER_H_
#define MOVER_H_

#include <Eigen/Geometry>
#include <core/Composite.h>

namespace phantom {

class Mover: public phantom::Composite
{
public:
    Mover();
    virtual ~Mover();
    void moveTo(Eigen::Vector3f){

    }
};

} /* namespace phantom */
#endif /* MOVER_H_ */
