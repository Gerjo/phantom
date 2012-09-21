/*
 * phantom.h
 *
 *  Created on: Aug 22, 2012
 *      Author: koen
 */
#define DLL_EXPORT

#ifdef _WINDOWS
#	ifdef DLL_EXPORT
#		define LIBEXPORT __declspec(dllexport)
#	else
#		define LIBEXPORT __declspec(dllimport)
#	endif
#endif

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
	#include <Windows.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif

#endif /* PHANTOM_H_ */
