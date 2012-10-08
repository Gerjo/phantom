#ifndef RENDERER_H
#define RENDERER_H

#include <CompileConfig.h>
#include <deque>
#include <core/GameState.h>

namespace phantom {
	class LIBEXPORT Renderer {
	public:
		Renderer(Vector3* viewPort, Vector3* worldSize) { 
            this->_viewPort = viewPort;
            this->_worldSize = worldSize;
        }
		virtual ~Renderer() { }

		virtual void drawLoop(std::vector<Composite*>& components, Vector3& offset) = 0;
		virtual void renderLoop(std::deque<GameState*>* states) = 0;
    
    protected:
        Vector3 *_viewPort;
        Vector3 *_worldSize;
	};
}

#endif // RENDERER_H