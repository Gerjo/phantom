/*
 * GameState.h
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Composite.h"

namespace phantom {

class GameState : public Composite {
public:

	bool transparent;
	bool propegateUpdate;

	GameState();
	virtual ~GameState();

private:

	Composite *camera;
};

}

#endif /* GAMESTATE_H_ */
