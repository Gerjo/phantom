#ifndef RENDERLAYER_H_
#define RENDERLAYER_H_

#include <core/Layer.h>
#include <CompileConfig.h>

namespace phantom {

class LIBEXPORT RenderLayer: public phantom::Layer
{
public:
    RenderLayer();
    virtual ~RenderLayer();
};

} /* namespace phantom */

#endif /* RENDERLAYER_H_ */
