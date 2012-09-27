#ifndef LAYER_H_
#define LAYER_H_

#include <core/GameState.h>
#include <core/Composite.h>
#include <CompileConfig.h>

namespace phantom {

class LIBEXPORT Layer: public phantom::Composite
{
public:
    Layer(float width=0, float height=0);
    virtual ~Layer();

    virtual void onAdd( Composite *parent );
    virtual void onAnsestorChanged();

protected:
    GameState *state;
    float width;
    float height;
};

} /* namespace phantom */
#endif /* LAYER_H_ */
