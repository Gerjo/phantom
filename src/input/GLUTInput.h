#ifndef GLUTINPUT_H
#define	GLUTINPUT_H

#include <input/Input.h>

namespace phantom {

    class LIBEXPORT GLUTInput : public Input {
    public:
        GLUTInput(PhantomGame *game);
        virtual ~GLUTInput();

    private:
		static void keyboardListener			(unsigned char keycode, int mouseX, int mouseY);
		static void keyboardUpListener			(unsigned char keycode, int mouseX, int mouseY);
		static void keyboardSpecialListener		(int code, int mouseX, int mouseY);
		static void keyboardSpecialUpListener	(int code, int mouseX, int mouseY);
		static void mouseListener				(int button, int state, int mouseX, int mouseY);
		static void mouseMotionListener			(int mouseX, int mouseY);

        static GLUTInput* INSTANCE;
    };
}

#endif	/* GLUTINPUT_H */

