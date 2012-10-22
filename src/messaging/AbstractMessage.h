#ifndef ABSTRACTMESSAGE_H
#define	ABSTRACTMESSAGE_H

#include "Message.h"


template <class T>
class Message;

class AbstractMessage {
public:
    AbstractMessage(std::string type) : _type(type) {

    }

    template <class T3>
    T3 getPayload() {
        return static_cast<Message<T3>*>(this)->getData();
    }

    bool isType(const std::string& otherType) {
        return _type.compare(otherType) == 0;
    }

    const std::string& getType() {
        return _type;
    }

private:
    std::string _type;
};


#endif	/* ABSTRACTMESSAGE_H */

