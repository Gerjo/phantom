
#include "phantom.h"
#include <graphics/SDLGraphics.h>

#include <iostream>

using namespace std;
using namespace phantom;
using namespace Eigen;

#include <SDL/SDL_draw.h>

int main( int argc, char *argv[] )
{
	PhantomGame *game = new PhantomGame("phantom.yaml");

	Graphics *g = new SDLGraphics();
	game->addComponent(g);
	g->drawCircle(Vector2f(200,200),40);
	g->draw();
	return game->start(argc, argv);
}
