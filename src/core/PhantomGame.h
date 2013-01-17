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

using namespace std;

namespace phantom {
    class Driver;

    class LIBEXPORT PhantomGame : public Composite {
    public:
        friend class Composite;
        friend class Graphics;

        bool fullscreen;
        bool mousecursor;
        float soundvol;
        float musicvol;

        PhantomGame(const char *configfile);
        virtual ~PhantomGame();

        /**
        * Parse the configuration file and set all the game parameters.
        *
        * @param configfile The location of the configuration file.
        */
        void parseConfigurationFile(const char *configfile);

        /**
        * Push a gamestate.
        *
        * @param state The gamestate you want to push on the stack.
        */
        void pushGameState(GameState *state);

        /**
        * Pop the top most gamestate.
        */
        void popGameState();

        /**
        * After initializing all your initial data, call this function to actually start the game.
        * In this function is a while loop located. To break out of it, call the exit function somewhere in the update loops of your game.
        */
        int start(int argc, char *argv[]);

        /**
        * This function gets called every loop.
        *
        * @param time The time generated in the start function.
        */
        virtual void update(const PhantomTime& time);
        
        /**
        * Call this function when you want to exit the game.
        *
        * @param returncode If everything went fine, give the returncode 0. If not enter a custom return code so you can identify where the exit call is comming from.
        */
        void exit(int returncode);

        /**
        * Returns the current viewport of the game.
        * 
        * @return Returns the current viewport of the game.
        */
        Vector3 getViewPort() const;

        /**
        * Returns the current screensize (resolution) of the game.
        *
        * @return Returns the current screensize (resolution) of the game.
        */
        Vector3 getScreenSize() const;
        
        /**
        * Returns the current worldsize of the game.
        *
        * @return Returns the current worldsize of the game.
        */
        Vector3 getWorldSize() const;

        /**
        * Change the current worldsize of the game.
        *
        * @param width The width of the playing field.
        * @param height The height of the playing field.
        */
        void setWorldSize(float width, float height);

        /**
        * Returns the list of currently pushed gamestates.
        *
        * @return Returns the list of currently pushed gamestates.
        */
        deque<GameState*>& getGameStates();
        
        /**
        * Returns the driver this game is using.
        *
        * @return Returns the driver this game is using.
        */
        Driver* getDriver();

        /**
        * In case you need the actual console pointer, this will return it.
        *
        * @return Returns the console instance.
        */
        Console* getConsole() { return _console; }
        
        /**
        * Sets the driver of the game.
        * 
        * @param driver The new driver you want to set.
        */
        void setDriver(Driver* driver);

        /**
        * Send a message across the system
        *
        * @param message The message you want to send.
        */
        virtual MessageState handleMessage(AbstractMessage* message);
    protected:
        virtual void onExit(int returncode);

        bool _running;
    private:
        static PhantomGame* INSTANCE;
        vector<Composite*> _disposables;
        Vector3 _viewPort;
        Vector3 _screenSize;
        Vector3 _worldSize;

        double _fps;

        Driver* _driver;
        Console* _console;
        std::deque<GameState*> _states;

        void mapConsoleFunctions();

        void clearDisposables();
        void dispose(Composite* composite);
    };

} /* namespace phantom */
#endif /* PHANTOMGAME_H_ */
