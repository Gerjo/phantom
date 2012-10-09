#include "Mover.h"
#include <core/Entity.h>

namespace phantom {

    Mover::Mover():_target(_position), _targetList(){
        _parent = 0;
        setPosition(Vector3(0,0,0));
    }
    void Mover::onAnsestorChanged(){
        Entity* e = dynamic_cast<Entity*>(findAnsestor<Entity>());
        if(e != NULL){
            _parent = e;
        }
    }
    void Mover::moveTo(Vector3* target){
        _targetList.push_back(target);
    }
    void Mover::moveTo(std::vector<Vector3*> targetList){
        _targetList = targetList;
    }
    void Mover::update(const float& elapsed){
        Composite::update(elapsed);
        if(!_targetList.empty() && _parent != 0){
            _target = *_targetList.back();
            Vector3 diff = (_target - _parent->getPosition()) * 0.4f * elapsed;
            cout << diff.toString() << endl;
            _parent->setPosition(_parent->getPosition() + diff);
            if(diff.x < 0 || diff.y < 0){
                _targetList.pop_back();
            }
        }
    }


} /* namespace phantom */
