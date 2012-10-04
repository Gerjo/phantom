#ifndef PHANTOMGAME_H_
#define PHANTOMGAME_H_

#include <core/GameState.h>
#include <core/Composite.h>
#include <core/Camera.h>
#include <deque>
#include <core/Renderer.h>
#include <CompileConfig.h>

using namespace std;

namespace phantom {
    class Driver;

    class LIBEXPORT PhantomGame : public Composite {
    public:
        PhantomGame(const char *configfile);
        virtual ~PhantomGame();

        void pushGameState(GameState *state);
        void popGameState();
        int start(int argc, char *argv[]);
        void update(float elapsed);
        void exit(int returncode);

        unsigned int getHeight() const {
            return height;
        }

        unsigned int getWidth() const {
            return width;
        }

        deque<GameState*>& getGameStates();
        Driver* getDriver();
        void setDriver(Driver* driver);
    protected:
        virtual void onExit(int returncode);

    private:

        unsigned int width;
        unsigned int height;

        unsigned int fps;

        Driver* _driver;
        std::deque<GameState*> states;

        double time();
    };

} /* namespace phantom */
#endif /* PHANTOMGAME_H_ */
