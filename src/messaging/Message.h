#ifndef MESSAGE_H_PCCS
#define	MESSAGE_H_PCCS

#include <messaging/AbstractMessage.h>


namespace phantom {

    namespace internal {
        struct NoPayload {
            // Using an empty struct instead of void* so we can distinguish an
            // actually void* data from no data at all. Wrapped in a "hidden"
            // namespace since really, you shouldn't be using this yourself.
        };
    }

    template <typename T = internal::NoPayload>
    class Message : public AbstractMessage {
    public:
        Message(std::string type) : AbstractMessage(type) {
            
        }

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
