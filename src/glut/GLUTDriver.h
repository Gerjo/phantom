#ifndef GLUTDRIVER_H
#define GLUTDRIVER_H

#include <core/Driver.h>
#include <core/PhantomGame.h>

namespace phantom{

    class LIBEXPORT GLUTDriver: public Driver {
	public:
		GLUTDriver(PhantomGame* game);
		virtual ~GLUTDriver();

        virtual void setWindowTitle(string title);
        virtual Camera* createCamera(void);
    private:
        static PhantomGame *_staticgame;
        static void closeListener();
    };

} /* namespace phantom */

#endif /* GLUTDRIVER_H */