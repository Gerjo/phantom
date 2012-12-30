#ifndef INPUTFIELD_H_
#define INPUTFIELD_H_

#include <string>
#include <core/Composite.h>
#include <input/MouseState.h>
#include <graphics/Color.h>
#include <utils/Time.h>
#include <input/KeyboardListener.h>

class LIBEXPORT InputField : public Composite {
public:
    InputField(float x, float y, float width, float height, phantom::Color color);
    ~InputField();

    virtual void onClick(MouseState *mousestate);
    virtual void onUnClicked(MouseState *mousestate);
    virtual void paint();
    virtual void paintText();
    virtual void update(const phantom::PhantomTime& time);

    void keyboard(KeyboardListener *keyboardListener) { _keyboardListener = keyboardListener; }

    std::string& text();
    void text(std::string value);

private:
    bool                _hasFocus;
    phantom::Color      _color;
    std::string         _text;
    KeyboardListener    *_keyboardListener;

    void mouseClickListener();
};

#endif