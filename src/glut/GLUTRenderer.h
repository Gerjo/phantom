#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <core/Renderer.h>
#include <CompileConfig.h>
#include <core/GameState.h>
#include <core/Composite.h>
#include <deque>
#include <physics/Vector3.h>
#include <string>

namespace phantom {

    class LIBEXPORT GLUTRenderer : public Renderer
    {
    public:
        GLUTRenderer(PhantomGame *game);
        virtual ~GLUTRenderer();

        virtual void drawLoop(std::vector<Composite*>& components, Vector3& offset);
        virtual void renderLoop(std::deque<GameState*>* states);
        
        
        virtual void buildShape(Shape *shape);
        virtual void destroyShape(Shape *shape);

        virtual void addTexture(ImageCacheItem *item);
        virtual void removeTexture(ImageCacheItem *item);

    private:
        int _windowID;
        bool _vboSupport;
        bool IsExtensionSupported(std::string szTargetExtensionString);
        void drawShape(Shape *shape, Composite *composite, float xOffset, float yOffset);
    };
}
#endif // GLUTRENDERER_H

