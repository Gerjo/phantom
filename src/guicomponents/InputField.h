#ifndef INPUTFIELD_H_
#define INPUTFIELD_H_

#include <string>
#include <core/Composite.h>
#include <input/MouseState.h>
#include <graphics/Color.h>
#include <utils/Time.h>
#include <input/KeyboardListener.h>

namespace phantom {
    class LIBEXPORT InputField : public Composite {
    public:
        InputField(float x, float y, float width, float height, phantom::Color color);
        ~InputField();

        /**
        * Gets called when clicked on the textfield.
        *
        * @param mousestate The mousestate when pressed.
        */
        virtual void onClick(MouseState *mousestate);

        /**
        * Gets called when clicked somewhere else.
        *
        * @param mousestate The mousestate when clicked somewhere else.
        */
        virtual void onUnClicked(MouseState *mousestate);

        /**
        * Override this function to draw your own background for the textfield.
        */
        virtual void paint();

        /**
        * Override this function to draw your own text for the textfield.
        */
        virtual void paintText();

        /**
        * This function calls the paint and paintText function. Also listens for keypresses.
        *
        * @param time The time created by PhantomGame.
        */
        virtual void update(const phantom::PhantomTime& time);

        /**
        * Set the keyboard listener so keys can be fetched.
        *
        * @param keyboardListener The keyboad listener.
        */
        void keyboard(KeyboardListener *keyboardListener) { _keyboardListener = keyboardListener; }

        /**
        * Returns a reference to the current text in the textfield.
        * 
        * @return Returns the current text in the field.
        */
        std::string& text();

        /**
        * Set the text to new value.
        *
        * @param value The new value for the textfield.
        */
        void text(const std::string &value);

    private:
        bool                _hasFocus;
        phantom::Color      _color;
        std::string         _text;
        KeyboardListener    *_keyboardListener;

        void mouseClickListener();
    };
}
#endif