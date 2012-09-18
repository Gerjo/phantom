
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

    g->strokeColor = Vector4f(0, 0, 1, 1);
    g->fillColor = Vector4f(1, 0, 0, 1);
    g->moveTo(10, 10);
    g->lineTo(10, 50);
    g->lineTo(50, 50);
    g->lineTo(50, 10);
    g->fill();
    g->stroke();

	return game->start(argc, argv);
}
