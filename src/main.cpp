
#include "phantom.h"

#include <iostream>

using namespace std;
using namespace phantom;

int main( int argc, char *argv[] )
{
	PhantomGame *game = new PhantomGame("phantom.yaml");
	return game->main(argc, argv);
}
