#ifndef GLUTINPUTSTATE_H_
#define GLUTINPUTSTATE_H_

#include <phantom.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT GLUTInputState : public InputState {
	public:
		virtual void setup();
		virtual void handleEvent(void *event){ }

	private:
		static void keyboardListener			(unsigned char keycode, int mouseX, int mouseY);
		static void keyboardUpListener			(unsigned char keycode, int mouseX, int mouseY);
		static void keyboardSpecialListener		(int code, int mouseX, int mouseY);
		static void keyboardSpecialUpListener	(int code, int mouseX, int mouseY);
		static void mouseListener				(int button, int state, int mouseX, int mouseY);
		static void mouseMotionListener			(int mouseX, int mouseY);
	};
}

#endif // GLUTINPUTSTATE_H_