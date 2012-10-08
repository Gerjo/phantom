#include "Mover.h"

namespace phantom {

    Mover::Mover(){

    }
    void Mover::moveTo(Vector3* target){
        setPosition(*target);
    }
    void Mover::moveTo(std::vector<Vector3*> targetList){
        _it = targetList.begin();
        while(_it != targetList.end()){
            moveTo((*_it));
            ++_it;
        }
    }

} /* namespace phantom */
