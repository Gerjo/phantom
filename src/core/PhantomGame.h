#ifndef PHANTOMGAME_H_
#define PHANTOMGAME_H_

#include <core/GameState.h>
#include <core/Composite.h>
#include <core/Camera.h>
#include <core/Console.h>
#include <deque>
#include <core/Renderer.h>
#include <CompileConfig.h>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

namespace phantom {
    class Driver;

    class LIBEXPORT PhantomGame : public Composite {
    public:
        bool fullscreen;
        bool mousecursor;
        float soundvol;
        float musicvol;

        PhantomGame(const char *configfile);
        void parseConfigurationFile(const char *configfile);
        virtual ~PhantomGame();

        void pushGameState(GameState *state);
        void popGameState();
        int start(int argc, char *argv[]);
        virtual void update(const PhantomTime& time);
        void exit(int returncode);

        Vector3 getViewPort() const;
        Vector3 getScreenSize() const;
        Vector3 getWorldSize() const;
        void setWorldSize(float x, float y);

        deque<GameState*>& getGameStates();
        Driver* getDriver();
        Console* getConsole() { return _console; }
        void setDriver(Driver* driver);

        virtual MessageState handleMessage(AbstractMessage* message);

        friend class Composite;
        friend class Graphics;

    protected:
        virtual void onExit(int returncode);

        bool _running;
    private:
        static PhantomGame* INSTANCE;
        vector<Composite*> _disposables;
        Vector3 _viewPort;
        Vector3 _screenSize;
        Vector3 _worldSize;

        float _fps;

        Driver* _driver;
        Console* _console;
        std::deque<GameState*> _states;

        void clearDisposables();
        void dispose(Composite* composite);
    };

} /* namespace phantom */
#endif /* PHANTOMGAME_H_ */
