#ifndef PHANTOM_H_
#define PHANTOM_H_

#define _NO_DEBUG_HEAP 1

#include <core/Composite.h>
#include <core/Entity.h>
#include <core/PhantomGame.h>
#include <core/Driver.h>

#include <messaging/Message.h>
#include <messaging/MessageState.h>
#include <messaging/AbstractMessage.h>

#include <graphics/Graphics.h>
#include <graphics/Color.h>
#include <utils/util.h>

#include <layer/EntityLayer.h>
#include <layer/Layer.h>

#include <physics/Vector3.h>
#include <physics/Box3.h>
#include <physics/Mover.h>

#ifdef WIN32

#else
    #include <sys/time.h>
    #include <unistd.h>
#endif

#endif /* PHANTOM_H_ */
