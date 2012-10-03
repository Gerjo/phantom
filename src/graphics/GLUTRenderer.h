#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <graphics/Renderer.h>
#include <CompileConfig.h>
#include <core/GameState.h>
#include <core/Composite.h>
#include <deque>

namespace phantom {
	class LIBEXPORT GLUTRenderer : public Renderer
	{
	public:
		GLUTRenderer(int width, int height);
		virtual ~GLUTRenderer();

		virtual void drawLoop(std::vector<Composite*> *components, Eigen::Vector3f offset);
		virtual void renderLoop(std::deque<GameState*> *states);
        virtual void setWindowTitle(std::string title);
	private:
		int _windowID;

        void drawShape(Shape *shape, Composite *composite, float xOffset, float yOffset);
		void setOrtho();
	};
}
#endif // GLUTRENDERER_H

