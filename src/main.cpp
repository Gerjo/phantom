
#include "phantom.h"
#include <graphics/SDLGraphics.h>
#include <input/InputState.h>
#include <input/SDLInputState.h>

#include <iostream>

using namespace std;
using namespace phantom;
using namespace Eigen;

#include <SDL/SDL_draw.h>

int main( int argc, char *argv[] )
{
	PhantomGame *game = new PhantomGame("phantom.yaml");

	Graphics *g = new SDLGraphics();

	InputState *s = new SDLInputState();
	game->addComponent(g);
	g->draw();
	return game->start(argc, argv);
}
