
#include "phantom.h"

using namespace std;
using namespace phantom;
using namespace Eigen;

int main( int argc, char *argv[] )
{
	PhantomGame *game = new PhantomGame("phantom.yaml");

	Graphics *g;
	InputState *s;
	EventManager *e;

	game->addComponent(g);
	game->addComponent(e);
	g->draw();

	return game->start(argc, argv);
	delete g; delete s; delete e;
}
