#ifndef BASEDRIVER_H
#define BASEDRIVER_H

#include <string>
#include <core/PhantomGame.h>
#include <CompileConfig.h>
#include <core/Camera.h>
#include <core/Renderer.h>
#include <utils/PhantomException.h>
#include <input/Input.h>
#include <utils/Time.h>

using namespace std;

namespace phantom{
    class FreeTypeLibrary;
    class LIBEXPORT Driver{
    public:
        Driver(PhantomGame* game);
        virtual ~Driver();

        virtual void setWindowTitle(string title);

        virtual void onUpdate(Time time);
        virtual void onRender();

        virtual Camera* createCamera(void) = 0;
        Camera *getActiveCamera();
        void setActiveCamera(Camera *cam);
        
        Input* getInput();
        Renderer *getRenderer();
        FreeTypeLibrary *getFontLibrary();

    protected:
        Renderer* _renderer;
        FreeTypeLibrary* _fontLibrary;
        Input* _input;
        Camera* _camera;
        PhantomGame* _game;
    };
} /* namespace phantom */

#endif /* BASEDRIVER_H */