#ifndef BUTTON_H_
#define BUTTON_H_

#include <phantom.h>
#include <string>

class LIBEXPORT Button : public Composite
{
public:
    Button(float x, float y, float width, float height);
    ~Button();

    void onClick(MouseState *mousestate);

    string &text();
    void setText(std::string text);
    
    virtual void paint();
    virtual void update(const PhantomTime &time);

    std::function<void()> onClickFunction;

private:
    std::string _text;
    bool _isBusy;

    void mouseListener();
};

#endif // BUTTON_H_
