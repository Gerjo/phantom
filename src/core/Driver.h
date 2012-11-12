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
    class KeyboardListener;

    class LIBEXPORT Driver{
    public:
        Driver(PhantomGame* game);
        virtual ~Driver();

        virtual void setWindowTitle(string title);

        virtual void onUpdate(Time time);
        virtual void onRender();

        virtual Camera* createCamera() = 0;
        vector<Camera*> *getActiveCameras();
        void enableCamera(Camera *cam);
        void disableCamera(Camera *cam);
        
        Input* getInput();
        Renderer *getRenderer();
        FreeTypeLibrary *getFontLibrary();

    protected:
        Renderer* _renderer;
        FreeTypeLibrary* _fontLibrary;
        Input* _input;
        vector<Camera*> _cameras;
        vector<Camera*> _activeCameras;
        KeyboardListener *_keyboard;
        
        PhantomGame* _game;

        void addCamToList(Camera *cam);

    };
} /* namespace phantom */

#endif /* BASEDRIVER_H */