#ifndef PHANTOMGAME_H_
#define PHANTOMGAME_H_

#include <core/GameState.h>
#include <core/Composite.h>
#include <vector>
#include <graphics/Renderer.h>
#include <CompileConfig.h>



namespace phantom {
    class BaseDriver;
class LIBEXPORT PhantomGame : public Composite {
public:
	PhantomGame( const char *configfile );
	virtual ~PhantomGame();

	void pushGameState( GameState *state );
	void popGameState();

    int start( int argc, char *argv[], BaseDriver* driver );

	void update( float elapsed );

	void exit(int returncode);

    unsigned int getHeight() const
    {
        return height;
    }

    unsigned int getWidth() const
    {
        return width;
    }

	void setRenderer(Renderer *renderer)
	{
		this->renderer = renderer;
	}

protected:
    virtual void onExit(int returncode);

private:

	unsigned int width;
	unsigned int height;

	unsigned int fps;

	Renderer *renderer;
    BaseDriver *driver;
	std::vector<GameState*> states;

	double time();
};

} /* namespace phantom */
#endif /* PHANTOMGAME_H_ */
