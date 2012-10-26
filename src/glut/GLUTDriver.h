#ifndef GLUTDRIVER_H
#define GLUTDRIVER_H

#include <core/Driver.h>
#include <core/PhantomGame.h>

namespace phantom{

    class LIBEXPORT GLUTDriver: public Driver {
	public:
		GLUTDriver(PhantomGame* game);
		virtual ~GLUTDriver();

		virtual void onUpdate(Time time);
		virtual void onRender();
        virtual void setWindowTitle(string title);
        virtual Camera* createCamera(void);
	};

} /* namespace phantom */

#endif /* GLUTDRIVER_H */