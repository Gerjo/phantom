#ifndef PHANTOM_H_
#define PHANTOM_H_

#include <Eigen/Geometry>

#include <core/Composite.h>
#include <core/Entity.h>
#include <core/Layer.h>
#include <core/PhantomGame.h>

#include <input/InputState.h>

#include <graphics/Graphics.h>

#include <utils/util.h>

#include <iostream>
#include <vector>

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN 
	#include <Windows.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif

#endif /* PHANTOM_H_ */
