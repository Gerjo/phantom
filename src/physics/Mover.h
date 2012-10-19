#ifndef MOVER_H_
#define MOVER_H_

#include <core/Composite.h>
#include <CompileConfig.h>
#include <vector>

namespace phantom {
    class Entity;

    class LIBEXPORT Mover: public phantom::Composite{
    public:
        Mover();
        void moveTo(Vector3 vector);
        void moveTo(const std::vector<Vector3> *vList);
        virtual void update(const float& elapsed);
        virtual void onAnsestorChanged();
        void stop();
        bool isStopped();
    private:
        std::vector<Vector3>::iterator _it;
        std::vector<Vector3> _targetList;
        Vector3 _target;
        Entity* _parent;
    };

} /* namespace phantom */
#endif /* MOVER_H_ */
