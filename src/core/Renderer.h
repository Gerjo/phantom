#ifndef RENDERER_H
#define RENDERER_H

#include <CompileConfig.h>
#include <deque>
#include <core/GameState.h>
#include <core/PhantomGame.h>

namespace phantom {
    class ImageCacheItem;

	class LIBEXPORT Renderer {
	public:
		Renderer(PhantomGame *game) { 
            _game = game;
        }

		virtual ~Renderer() { }

        /**
        * This is called every loop by the Driver class.
        */
		virtual void renderLoop() = 0;
        
        /**
        * This gets called by the Graphics class. This makes it possible to build VBO's for example.
        * 
        * @param shape The shape you want to build.
        */
        virtual void buildShape(Shape *shape) = 0;
        
        /**
        * This gets called by the Graphics class. This makes it possible to destroy VBO's for example.
        * 
        * @param shape The shape you want to destroy.
        */
        virtual void destroyShape(Shape *shape) = 0;

        /**
        * This gets called when a texture has to be added to the graphics pipeline.
        *
        * @param item The imache cache item that has to be created.
        * @param isText The fonts are converted to images as well. Set this to true to have an optimization for font rendering.
        */
        virtual void addTexture(ImageCacheItem *item, bool isText = false) = 0;

        /**
        * This gets called when the texture has to be removed from the graphics pipeline.
        *
        * @param item The item you want to remove from the cache.
        */
        virtual void removeTexture(ImageCacheItem *item) = 0;
    protected:
        PhantomGame *_game;
	};
}

#endif // RENDERER_H