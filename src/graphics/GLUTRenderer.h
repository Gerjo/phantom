#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <graphics/Renderer.h>
#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT GLUTRenderer : public Renderer
	{
	public:
		GLUTRenderer();
		virtual ~GLUTRenderer();
		
		virtual void renderLoop();
	};
}
#endif // GLUTRENDERER_H

