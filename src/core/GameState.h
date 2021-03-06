#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Composite.h"
#include <CompileConfig.h>


namespace phantom {
    class Layer;
    class LIBEXPORT GameState : public Composite {
    public:
        bool doUpdate;
        bool doRender;

        GameState();
        virtual ~GameState();
    };

}

#endif /* GAMESTATE_H_ */
