#ifndef MOVER_H_
#define MOVER_H_

#include <core/Composite.h>
#include <CompileConfig.h>
#include <deque>

namespace phantom {

    class LIBEXPORT Mover: public phantom::Composite{
    public:
        Mover();
        void moveTo(Vector3* vector);
        void moveTo(std::deque<Vector3*> vList);
        virtual void update(const float& elapsed);
    private:
        std::deque<Vector3*>::iterator _it;
        std::deque<Vector3*> _targetList;
        Vector3 _target;
    };

} /* namespace phantom */
#endif /* MOVER_H_ */
