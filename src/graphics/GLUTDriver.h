#ifndef GLUTDRIVER_H
#define GLUTDRIVER_H

#include "BaseDriver.h"
#include <core\PhantomGame.h>

namespace phantom{
    
    class LIBEXPORT GLUTDriver: public BaseDriver{
	public:
		GLUTDriver();
		virtual ~GLUTDriver();
		
		virtual void setGame(PhantomGame* game);
		virtual void onUpdate(float elapsed);
		virtual void onRender();
	};
     
} /* namespace phantom */

#endif /* GLUTDRIVER_H */ 