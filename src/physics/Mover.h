#ifndef MOVER_H_
#define MOVER_H_

#include <core/Composite.h>

namespace phantom {

    class Mover: public phantom::Composite{
    public:
        Mover();
        void moveTo(Vector3* vector);
        void moveTo(std::vector<Vector3*> vList);
        virtual void update(const float& elapsed);
    private:
        std::vector<Vector3*>::iterator _it;
        std::vector<Vector3*> _targetList;
        Vector3 _target;
    };

} /* namespace phantom */
#endif /* MOVER_H_ */
