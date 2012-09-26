#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Composite.h"
#include <CompileConfig.h>
namespace phantom {

    class LIBEXPORT GameState : public Composite {
    public:

        bool transparent;
        bool propegateUpdate;

        GameState();
        virtual ~GameState();

    private:

        Composite *camera;
    };

}

#endif /* GAMESTATE_H_ */
