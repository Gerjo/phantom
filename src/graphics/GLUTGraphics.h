#ifndef GLUTGRAPHICS_H
#define GLUTGRAPHICS_H

#include <graphics/Graphics.h>
#include <CompileConfig.h>
namespace phantom {
	class LIBEXPORT GLUTGraphics : public Graphics
	{
	public:
		GLUTGraphics(void);
		virtual ~GLUTGraphics(void);
	};
}
#endif

