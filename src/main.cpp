
#include "phantom.h"
#include <SDL/SDL_draw.h>
#include <graphics/SDLGraphics.h>
#include <input/SDLInputState.h>
#include <core/SDLEventManager.h>

using namespace std;
using namespace phantom;
using namespace Eigen;

int main( int argc, char *argv[] )
{
	PhantomGame *game = new PhantomGame("phantom.yaml");

	Graphics *g = new SDLGraphics();
	InputState *s = new SDLInputState();
	EventManager *e = new SDLEventManager();

	game->addComponent(g);
	game->addComponent(e);
	g->draw();

	return game->start(argc, argv);
	delete g; delete s; delete e;
}
