#ifndef GLUTDRIVER_H
#define GLUTDRIVER_H

#include <core/Driver.h>
#include <core/PhantomGame.h>

namespace phantom{

    class LIBEXPORT GLUTDriver: public Driver {
	public:
		GLUTDriver(PhantomGame& game);
		virtual ~GLUTDriver();

		virtual void setGame(PhantomGame* game);
		virtual void onUpdate(float elapsed);
		virtual void onRender();
	};

} /* namespace phantom */

#endif /* GLUTDRIVER_H */