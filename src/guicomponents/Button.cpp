#include <pch.h>
#include "Button.h"

Button::Button(float x, float y, float width, float height) : _isBusy(false) {
    setPosition(Vector3(x, y));
    setBoundingBox(Box3(0, 0, width, height));
}

Button::~Button() {
}

string &Button::text() {
    return _text;
}

void Button::setText(const std::string &text) {
    _text = text;
}

void Button::paint() {
    int fontSize = 48;

    getGraphics().clear().beginPath().setFillStyle(phantom::Colors::WHITE).
        rect(0.0f, 0.0f, getBoundingBox().size.x, getBoundingBox().size.y, false).
        fill().
        setFillStyle(phantom::Colors::BLACK).
        text((getBoundingBox().size.x / 2) - ((_text.size() * fontSize) / 3), (getBoundingBox().size.y / 2) - fontSize, fontSize, "fonts/waree.ttf", _text).
        fill();
}

void Button::update(const PhantomTime &time) {
    Composite::update(time);
    mouseListener();
}

void Button::onClick(MouseState *mousestate) {
    onClickFunction();
}

void Button::mouseListener() {
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
        // No action on unclick.
    }
}