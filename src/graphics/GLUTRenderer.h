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

		virtual void drawLoop(std::vector<Composite*> *components);
		virtual void renderLoop(std::deque<GameState*> *states);
	private:
		int _windowID;

		void setOrtho();
	};
}
#endif // GLUTRENDERER_H

