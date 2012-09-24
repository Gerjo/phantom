#ifndef RENDERER_H
#define RENDERER_H

#include <CompileConfig.h>
#include <vector>
#include <core/GameState.h>

namespace phantom {
	class LIBEXPORT Renderer {
	public:
		int width;
		int height;

		Renderer(int width, int height) { this->width = width; this->height = height; }
		virtual ~Renderer() { }

		virtual void drawLoop(std::vector<Composite*> *components) { }
		virtual void renderLoop(std::vector<GameState*> *states) { }
	};
}

#endif // RENDERER_H