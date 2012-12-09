#ifndef IHANDLEMESSAGE_H
#define	IHANDLEMESSAGE_H

#include "AbstractMessage.h"
#include "MessageState.h"
#include "Message.h"

namespace phantom {
    class IHandleMessage {
    public:
        virtual MessageState handleMessage(AbstractMessage* message) = 0;
    };
}
#endif	/* IHANDLEMESSAGE_H */

