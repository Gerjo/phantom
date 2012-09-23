#ifndef RENDERER_H
#define RENDERER_H

#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT Renderer {
	public:
		Renderer() { };
		virtual ~Renderer() { };

		virtual void renderLoop() { };
	};
}

#endif // RENDERER_H