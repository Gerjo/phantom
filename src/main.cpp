#include "phantom.h"
#include <graphics\GLGraphics.h>
#include <iostream>
#include <input\GLUTInputState.h>

using namespace std;
using namespace phantom;
using namespace Eigen;

int main( int argc, char *argv[] )
{
	PhantomGame *game = new PhantomGame("phantom.yaml");

	Graphics *g = new GLGraphics();

	InputState::createMe(&GLUTInputState());

	EventManager *e;

	game->addComponent(g);


	
	return game->start(argc, argv);
	delete g; delete e;
}
