#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <core/Renderer.h>
#include <CompileConfig.h>
#include <core/GameState.h>
#include <core/Composite.h>
#include <deque>
#include <physics/Vector3.h>
#include <string>
#include <graphics/FreeTypeLibrary.h>
#include <GL/freeglut.h>
#include <GL/glext.h>

#ifndef _WINDOWS
#   include <GL/glx.h>
#endif


namespace phantom {
    class Image;
    class Text;
    class Particles;

    class LIBEXPORT GLRenderer : public Renderer
    {
    public:
        GLRenderer(PhantomGame *game);
        virtual ~GLRenderer();

        virtual void drawLoop(std::vector<Composite*>& components, Vector3& offset);
        virtual void renderLoop(std::deque<GameState*>* states);

        virtual void buildShape(Shape *shape);
        virtual void destroyShape(Shape *shape);

        virtual void addTexture(ImageCacheItem *item, bool isText = false);
        virtual void removeTexture(ImageCacheItem *item);

    private:
        int _windowID;
        bool _vboSupport;
        bool IsExtensionSupported(std::string szTargetExtensionString);
        void drawShapes(Composite *composite, const Box3 &cameraBox, float xOffset, float yOffset);
        void drawText(Text *shape, Composite *composite, float xOffset, float yOffset);
        void drawImage(Image *image, Composite *composite, float xOffset, float yOffset);
        void drawPrime(Shape *shape, Composite *composite, float xOffset, float yOffset);
        void drawParticles(Particles *particles, float xOffset, float yOffset);
    };
}
#endif // GLUTRENDERER_H

