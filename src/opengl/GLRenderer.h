#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <deque>
#include <string>
#include <GL/freeglut.h>
#include <GL/glext.h>
#include <CompileConfig.h>
#include <core/Renderer.h>
#include <core/GameState.h>
#include <core/Composite.h>
#include <physics/Vector3.h>
#include <graphics/FreeTypeLibrary.h>

#ifndef _WINDOWS
#   include <GL/glx.h>
#endif

using std::string;

namespace phantom {
    class Image;
    class Text;
    class Particles;

    class LIBEXPORT GLRenderer : public Renderer
    {
    public:
        GLRenderer(PhantomGame *game);
        virtual ~GLRenderer();

        /**
        * This is called every loop by the Driver class.
        */
        virtual void renderLoop();

        /**
        * This gets called by the Graphics class. This makes it possible to build VBO's for example.
        * 
        * @param shape The shape you want to build.
        */
        virtual void buildShape(Shape *shape);

        /**
        * This gets called by the Graphics class. This makes it possible to destroy VBO's for example.
        * 
        * @param shape The shape you want to destroy.
        */
        virtual void destroyShape(Shape *shape);

        /**
        * This gets called when a texture has to be added to the graphics pipeline.
        *
        * @param item The imache cache item that has to be created.
        * @param isText The fonts are converted to images as well. Set this to true to have an optimization for font rendering.
        */
        virtual void addTexture(ImageCacheItem *item, bool isText = false);

        /**
        * This gets called when the texture has to be removed from the graphics pipeline.
        *
        * @param item The item you want to remove from the cache.
        */
        virtual void removeTexture(ImageCacheItem *item);

    private:
        int _windowID;
        bool _vboSupport;
        bool _shaderSupport;
        GLint _programscount;
        GLint _activeprogram;
        GLint _programs[1];

        bool IsExtensionSupported(string szTargetExtensionString);
        void createVBO(GLuint *buffer, GLuint size, GLvoid *data);
        void destroyVBO(GLuint *buffer);
        void drawLoop(std::vector<Composite*>& components, Vector3& offset);
        void drawShapes(Composite *composite, const Box3 &cameraBox, float xOffset, float yOffset);
        void drawText(Text *shape, Composite *composite, float xOffset, float yOffset);
        void drawImage(Image *image, Composite *composite, float xOffset, float yOffset);
        void drawPrime(Shape *shape, Composite *composite, float xOffset, float yOffset);
        void drawParticles(Particles *particles, float xOffset, float yOffset);
        void applyColor(const Color &color, float hasTex = 1.0f);
        void translateShape(float x, float y, float z);
        void insertShader(const string& vertex, const string& fragment);
    };
}
#endif // GLUTRENDERER_H

