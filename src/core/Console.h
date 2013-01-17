#ifndef CONSOLE_H
#define	CONSOLE_H

#include <pch.h>
#include <core/Composite.h>
#include <CompileConfig.h>

using namespace std;
namespace phantom {
    class Driver;
    class KeyboardState;

    class LIBEXPORT Console : public Composite {
    public:
        Console();

        /**
        * Add a log message to the console.
        *
        * @param log The message in string format.
        */
        void addLog(string log);
        
        /**
        * Add a log message to the console.
        *
        * @param log The message in string format.
        */
        static void log(string log);

        /**
        * Add a log message to the console.
        *
        * @param log The message in stringstream format.
        */
        static void log(stringstream log);


        /**
        * Add a console command to the console.
        * 
        * @param name The name of the command you have to call.
        * @param function The function that gets executed once the command is called.
        */
        static void mapCommand(string name, function<void(string args)> function);

        /**
        * An easy way to log the phantom Message class.
        *
        * @param log The message you want to send to the logger.
        */
        template<class mType>
        static void log(Message<mType> log){
            Console::log(log.getType());
            Console::log(log.getData());
        }

        /**
        * This function is called every loop automaticly since the console is a Composite that's added to the PhantomGame.
        *
        * @param time PhantomTime generated by PhantomGame.
        */
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

