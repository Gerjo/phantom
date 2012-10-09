#include "Mover.h"

namespace phantom {

    Mover::Mover():_target(_position), _targetList(){

    }
    void Mover::moveTo(Vector3* target){
        _targetList.push_back(target);
    }
    void Mover::moveTo(std::deque<Vector3*> targetList){
        _targetList = targetList;
    }
    void Mover::update(const float& elapsed){
        Composite::update(elapsed);
        if(!_targetList.empty()){
            _target = *_targetList.back();
            Vector3 diff = (_target - _position) * 0.4f * elapsed;
            setPosition(_position + diff);
            if(diff.x < 0 || diff.y < 0){
                _targetList.pop_back();
            }
        }
    }


} /* namespace phantom */
