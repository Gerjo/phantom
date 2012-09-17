/*
 * phantom.h
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */
#ifndef PHANTOM_H_
#define PHANTOM_H_

#include <Eigen/Geometry>

#include <core/Composite.h>
#include <core/Entity.h>
#include <core/Layer.h>
#include <core/PhantomGame.h>

#include <graphics/Graphics.h>
#ifdef WIN32
	#include <Windows.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif

void phantom_sleep(float timems){
    #ifndef WIN32
        usleep(timems * 1000);
    #else
        Sleep(timems);
    #endif
}

#endif /* PHANTOM_H_ */
