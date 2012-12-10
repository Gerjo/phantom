#ifndef CONSOLE_H
#define	CONSOLE_H

#include <deque>
#include <map>
#include <sstream>
#include <functional>
#include <core/Composite.h>
#include <CompileConfig.h>

using namespace std;
namespace phantom {
    class Driver;
    class KeyboardState;

    class LIBEXPORT Console : public Composite {
    public:
        Console();

        void addLog(string log);

        static void log(string log);
        static void log(stringstream log);

        static void mapCommand(string name, function<void(string args)> function);

        template<class mType>
        static void log(Message<mType> log){
            Console::log(log.getType());
            Console::log(log.getData());
        }

        virtual void update(const PhantomTime& time);
    private:
        static Console* INSTANCE;
        deque<string> _logs;
        map<string, function<void(string args)>> _commandMap;

        bool _doRedraw;
        bool _enabled;
        KeyboardState *_keyboard;

        void draw(void);
        void renderText(int offset, Color color);
        void renderInput();

        float _width;
        float _height;
        unsigned int _maxLines;
        int _logCount;
        string _text;
    };
}

#endif	/* CONSOLE_H */

