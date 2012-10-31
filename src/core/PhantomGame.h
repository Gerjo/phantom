#ifndef PHANTOMGAME_H_
#define PHANTOMGAME_H_

#include <core/GameState.h>
#include <core/Composite.h>
#include <core/Camera.h>
#include <deque>
#include <core/Renderer.h>
#include <CompileConfig.h>
#include <cstdlib>

using namespace std;

namespace phantom {
    class Driver;

    class LIBEXPORT PhantomGame : public Composite {
    public:
        bool fullscreen;
        bool mousecursor;

        PhantomGame(const char *configfile);
        virtual ~PhantomGame();

        void pushGameState(GameState *state);
        void popGameState();
        int start(int argc, char *argv[]);
        virtual void update(const Time& time);
        void exit(int returncode);

        Vector3 getViewPort() const;
        Vector3 getWorldSize() const;

        deque<GameState*>& getGameStates();
        Driver* getDriver();
        void setDriver(Driver* driver);

        virtual MessageState handleMessage(AbstractMessage* message);

        friend class Graphics;
        friend class Composite;
    protected:
        virtual void onExit(int returncode);

        bool _running;
    private:
        static PhantomGame* INSTANCE;
        Vector3 _viewPort;
        Vector3 _worldSize;

        unsigned int _fps;

        Driver* _driver;
        std::deque<GameState*> _states;

        void parseConfigurationFile(const char *configfile);


    };

} /* namespace phantom */
#endif /* PHANTOMGAME_H_ */
