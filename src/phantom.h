#ifndef PHANTOM_H_
#define PHANTOM_H_

#include <Eigen/Geometry>

#include <core/Composite.h>
#include <core/Entity.h>
#include <layer/Layer.h>
#include <core/PhantomGame.h>
#include <core/Driver.h>

#include <graphics/Graphics.h>
#include <graphics/Color.h>
#include <utils/util.h>

#include <layer/RenderLayer.h>
#include <layer/ObjectLayer.h>

#include <physics/Vector3.h>
#include <physics/Box3.h>

#ifdef WIN32
#   ifndef WIN32_LEAN_AND_MEAN
#       define WIN32_LEAN_AND_MEAN
#   endif
#   include <Windows.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif

#endif /* PHANTOM_H_ */
