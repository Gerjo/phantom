#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <graphics/Renderer.h>
#include <CompileConfig.h>
#include <core/GameState.h>
#include <core/Composite.h>

namespace phantom {
	class LIBEXPORT GLUTRenderer : public Renderer
	{
	public:
		GLUTRenderer(int width, int height);
		virtual ~GLUTRenderer();
		
		virtual void drawLoop(std::vector<Composite*> *components);
		virtual void renderLoop(std::vector<GameState*> *states);
	private:
		int _windowID;
	};
}
#endif // GLUTRENDERER_H

