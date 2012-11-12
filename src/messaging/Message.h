#ifndef MESSAGE_H_PCCS
#define	MESSAGE_H_PCCS

#include <messaging/AbstractMessage.h>

namespace phantom {

    template <class T>
    class Message : public AbstractMessage {
    public:

        Message(std::string type, T data) : AbstractMessage(type) {
            _data = data;
        }

        T getData(void) {
            return _data;
        }

    private:
        T _data;
    };
}

#endif	/* MESSAGE_H_PCCS */
