#ifndef RENDERER_H
#define RENDERER_H

#include <CompileConfig.h>
#include <deque>
#include <core/GameState.h>

namespace phantom {
	class LIBEXPORT Renderer {
	public:
		int width;
		int height;

		Renderer(int width, int height) { this->width = width; this->height = height; }
		virtual ~Renderer() { }

		virtual void drawLoop(std::vector<Composite*>& components, Vector3& offset) = 0;
		virtual void renderLoop(std::deque<GameState*>* states) = 0;
	};
}

#endif // RENDERER_H