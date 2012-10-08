#ifndef GLUTRENDERER_H
#define GLUTRENDERER_H

#include <core/Renderer.h>
#include <CompileConfig.h>
#include <core/GameState.h>
#include <core/Composite.h>
#include <deque>
#include <physics/Vector3.h>

namespace phantom {
	class LIBEXPORT GLUTRenderer : public Renderer
	{
	public:
		GLUTRenderer(Vector3* viewPort, Vector3* worldSize);
		virtual ~GLUTRenderer();

		virtual void drawLoop(std::vector<Composite*>& components, Vector3& offset);
		virtual void renderLoop(std::deque<GameState*>* states);
	private:
		int _windowID;

        void drawShape(Shape *shape, Composite *composite, float xOffset, float yOffset);
	};
}
#endif // GLUTRENDERER_H

