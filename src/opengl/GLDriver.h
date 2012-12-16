#ifndef GLUTDRIVER_H
#define GLUTDRIVER_H

#include <core/Driver.h>
#include <core/PhantomGame.h>

namespace phantom{

    class LIBEXPORT GLDriver: public Driver {
	public:
		GLDriver(PhantomGame* game);
		virtual ~GLDriver();

        virtual void setWindowTitle(string title);
        virtual Camera* createCamera(void);
    private:
        static PhantomGame *_staticgame;
        static void closeListener();
    };

} /* namespace phantom */

#endif /* GLUTDRIVER_H */