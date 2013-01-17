#include <pch.h>
#include "InputField.h"
#include <physics/Box3.h>
#include <core/Driver.h>

using namespace phantom;
using namespace std;

InputField::InputField(float x, float y, float width, float height, Color color) : _hasFocus(false), _text("") {
    setPosition(Vector3(x, y));
    _color = color;

    this->setBoundingBox(Box3(x, y, width, height));
}

InputField::~InputField() {

}

void InputField::onClick(MouseState* mouseState) {
    if(KeyboardListener::lock(this))
        _hasFocus = true;
}

void InputField::onUnClicked(MouseState* mouseState) {
    _hasFocus = false;
    KeyboardListener::unlock(this);
}

string& InputField::text() {
    return _text;
}

void InputField::text(const string &value) {
    _text = value;
}

void InputField::paint() {
    getGraphics().clear();

    Box3 *bb = &this->getBoundingBox();
    getGraphics().beginPath().rect(0.0f, 0.0f, bb->size.x, bb->size.y, false).fill();
}

void InputField::paintText() {
    getGraphics().beginPath().setFillStyle(_color).
        text(0.0f, 0.0f, static_cast<int>(getBoundingBox().size.y / 2), "fonts/DejaVuSansMono-Bold.ttf", text()).
        fill();
}

void InputField::update(const PhantomTime& time) {
    Composite::update(time);

    // Resize
    Box3 *bb = &this->getBoundingBox();
    bb->size.x = (bb->size.x > bb->size.y / 2.5f * _text.length()) ? bb->size.x : bb->size.y / 2.5f * _text.length();

    paint();
    paintText();
    mouseClickListener();

    if(_hasFocus) {
        std::vector<char> *chars = getDriver()->getInput()->getKeyboardState()->changes();
        for(char c : *chars) {
            if(c == '\b') { // Action for backspace.
                if(_text.size() > 0) {
                    _text.erase(_text.end() - 1);
                }
            }
            else if(c == '\n' || c == '\r') {
                onUnClicked(getDriver()->getInput()->getMouseState());
            }
            else {
                _text.append(1, c);
            }
        }
    }
}

void InputField::mouseClickListener() {
    MouseState* mouseState = getDriver()->getInput()->getMouseState();
    Box3 bb = getBoundingBox();
    Vector3 campos;
    if(getDriver()->getActiveCameras()->at(0) == nullptr)
        campos = Vector3();
    else
        campos = getDriver()->getActiveCameras()->at(0)->getPosition();

    if(bb.contains(mouseState->getPosition() + campos) && mouseState->isButtonDown(Buttons::LEFT_MOUSE)) {
        onClick(mouseState);
        mouseState->handleEvent(Buttons::LEFT_MOUSE, 0);
    } else if(mouseState->isButtonDown(Buttons::LEFT_MOUSE)) {
        onUnClicked(mouseState);
    }
}