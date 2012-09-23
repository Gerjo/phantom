#ifndef RENDERER_H
#define RENDERER_H

#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT Renderer {
	public:
		int width;
		int height;

		Renderer(int width, int height) { this->width = width; this->height = height; }
		virtual ~Renderer() { }

		virtual void renderLoop() { }
	};
}

#endif // RENDERER_H