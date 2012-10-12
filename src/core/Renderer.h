#ifndef RENDERER_H
#define RENDERER_H

#include <CompileConfig.h>
#include <deque>
#include <core/GameState.h>
#include <core/PhantomGame.h>

namespace phantom {
	class LIBEXPORT Renderer {
	public:
		Renderer(PhantomGame *game) { 
            _game = game;
        }

		virtual ~Renderer() { }

		virtual void drawLoop(std::vector<Composite*>& components, Vector3& offset) = 0;
		virtual void renderLoop(std::deque<GameState*>* states) = 0;
        virtual void buildShape(Shape *shape) = 0;
        virtual void destroyShape(Shape *shape) = 0;
    protected:
        PhantomGame *_game;
	};
}

#endif // RENDERER_H