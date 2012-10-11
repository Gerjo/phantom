#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <GL/freeglut.h>
#include <GL/glext.h>
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

        virtual void buildVBO(Shape *shape);
    private:
        int _windowID;
        bool IsExtensionSupported(std::string szTargetExtensionString);
        void drawShape(Shape *shape, Composite *composite, float xOffset, float yOffset);
    };
}
#endif // GLUTRENDERER_H

