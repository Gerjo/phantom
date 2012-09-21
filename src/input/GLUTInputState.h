#ifndef GLUTINPUTSTATE_H_
#define GLUTINPUTSTATE_H_

#include <phantom.h>
#include <GL/glu.h>
#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT GLUTInputState : public InputState {
	public:
		virtual void setup();
		virtual void handleEvent(void *event){ }

	private:
		static void __cdecl keyboardListener			(unsigned char keycode, int mouseX, int mouseY);
		static void __cdecl keyboardUpListener			(unsigned char keycode, int mouseX, int mouseY);
		static void __cdecl keyboardSpecialListener		(int code, int mouseX, int mouseY);
		static void __cdecl keyboardSpecialUpListener	(int code, int mouseX, int mouseY);
		static void __cdecl mouseListener				(int button, int state, int mouseX, int mouseY);
		static void __cdecl mouseMotionListener			(int mouseX, int mouseY);
	};
}

#endif // GLUTINPUTSTATE_H_