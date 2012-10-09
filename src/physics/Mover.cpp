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
        cout << "BAH" << endl;
    }
    void Mover::moveTo(std::vector<Vector3*> targetList){
        _targetList = targetList;
        cout << "congrats" << endl;
    }
    void Mover::update(const float& elapsed){
        Composite::update(elapsed);
        if(!_targetList.empty() && _parent != 0){
            _target = *_targetList.back();
            Vector3 diff = (_target - _parent->getPosition());// * 0.4f * elapsed;

            if(abs(diff.x) < 2 || abs(diff.y) < 2) {
                _targetList.pop_back();

                cout << "pop route" << endl;
            }

            diff.x = diff.x / 10;
            diff.y = diff.y / 10;

            //cout << endl;
            //cout << _target.toString();
            //cout << _parent->getPosition().toString();
            //cout << diff.toString() << endl;

            diff.z = 0;

            _parent->setPosition(_parent->getPosition() + diff);


        }
    }


} /* namespace phantom */
