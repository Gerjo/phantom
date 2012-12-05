#include "Mover.h"
#include <core/Entity.h>


namespace phantom {

    Mover::Mover():_target(_position), _targetList(), _pauseTimer(0.0) {
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

    void Mover::moveTo(const std::deque<Vector3> targetList){
        _targetList = targetList;
    }

    void Mover::update(const PhantomTime& time){
        Composite::update(time);

        if(_pauseTimer.hasExpired(time)) {
            if(!_targetList.empty() && _parent != 0){
                const Vector3& target    = _targetList.front();
                const Vector3& position  = _parent->getPosition();
                Vector3 direction        = target - position;
                const bool wasXpositive  = direction.x >= 0;
                const bool wasYpositive  = direction.y >= 0;

                direction.normalize();

                Vector3 newPosition  = position + (direction * 300 * time.getElapsed());
                Vector3 newDirection = target - newPosition;

                const bool isXpositive  = newDirection.x >= 0;
                const bool isYpositive  = newDirection.y >= 0;

                if(isXpositive != wasXpositive) {
                    newPosition.x = target.x;
                }

                if(isYpositive != wasYpositive) {
                    newPosition.y = target.y;
                }

                float distanceSq = newPosition.distanceToSq(target);
                float threshold  = 64.0f;

                if(distanceSq < threshold) {
                    _targetList.pop_front();
                }

                _parent->setDirection(direction);
                _parent->setPosition(newPosition);
            }
        }
    }

    void Mover::stop() {
        _targetList.clear();
    }

    bool Mover::isStopped() {
        return _targetList.empty();
    }

    void Mover::pause(double delay) {
        _pauseTimer.setDelay(delay).restart();
    }

    bool Mover::isPaused() {
        return !_pauseTimer.hasExpired();
    }
} /* namespace phantom */
