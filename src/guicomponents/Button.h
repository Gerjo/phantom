#ifndef BUTTON_H_
#define BUTTON_H_

#include <phantom.h>
#include <string>

class LIBEXPORT Button : public Composite
{
public:
    Button(float x, float y, float width, float height);
    ~Button();

    /**
    * This function executes the onClickFunction.
    *
    * @param mousestate The location of the mouse.
    */
    void onClick(MouseState *mousestate);

    /**
    * Returns a reference to the text.
    *
    * @return Returns a reference to the text.
    */
    string &text();
    
    /**
    * Set the label of the button.
    *
    * @param text The text you want to set on the button.
    */
    void setText(const std::string &text);
    
    /**
    * Paint gets executed before the label is printed on it.
    * Override this function to create a skin for the button.
    */
    virtual void paint();
    
    /**
    * This function draws the button and checks if it's pressed.
    *
    * @param time The time created by PhantomGame.
    */
    virtual void update(const PhantomTime &time);

    std::function<void()> onClickFunction;

private:
    std::string _text;
    bool _isBusy;

    void mouseListener();
};

#endif // BUTTON_H_
