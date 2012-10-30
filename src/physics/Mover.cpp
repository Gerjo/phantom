#include "Mover.h"
#include <core/Entity.h>

namespace phantom {

    Mover::Mover():_target(_position), _targetList(){
        _parent = 0;
        setPosition(Vector3(0,0,0));
    }
    void Mover::onAnsestorChanged(){
        Entity* e = dynamic_cast<Entity*>(findAnsestor<Entity>());
        if(e != 0){
            _parent = e;
        }
    }
    void Mover::moveTo(Vector3 target){
        _targetList.push_back(target);
    }
    void Mover::moveTo(const std::vector<Vector3> *targetList){
        _targetList = *targetList;
    }
    void Mover::update(const Time& time){
        Composite::update(time);
        if(!_targetList.empty() && _parent != 0){
            Vector3 target    = _targetList.back();
            Vector3 position  = _parent->getPosition();
            Vector3 direction = target - position;

            direction.normalize();

            Vector3 newPosition = position + (direction * 300 * time.getElapsed());

            float distanceSq = position.distanceToSq(target);
            float threshold = static_cast<float>(pow(8, 2));

            if(distanceSq < threshold) {
                _targetList.pop_back();
            }

            _parent->setPosition(newPosition);
        }
    }

    void Mover::stop() {
        _targetList.clear();
    }

    bool Mover::isStopped() {
        return _targetList.empty();
    }
} /* namespace phantom */
