#ifndef MOVER_H_
#define MOVER_H_

#include <core/Composite.h>
#include <CompileConfig.h>
#include <deque>

namespace phantom {
    class Entity;

    class LIBEXPORT Mover: public phantom::Composite{
    public:
        Mover();
        void moveTo(Vector3 vector);
        void moveTo(const std::deque<Vector3> *vList);
        virtual void update(const Time& time);
        virtual void onAnsestorChanged();
        void stop();
        bool isStopped();
    private:
        std::deque<Vector3>::iterator _it;
        std::deque<Vector3> _targetList;
        Vector3 _target;
        Entity* _parent;
    };

} /* namespace phantom */
#endif /* MOVER_H_ */
