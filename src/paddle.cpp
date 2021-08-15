#include "paddle.h"

using namespace sf;

RectangleShape & Paddle:: getPaddle() {
    return mPaddle;
}

PlayerLeft:: PlayerLeft() {
    mPaddle.setPosition(Vector2f(40.f, (720.f / 2.f) - (mPaddle.getSize().y / 2)));
    mPaddle.setSize(Vector2f(20.f, 120.f));
}

void PlayerLeft:: update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (mPaddle.getPosition().y >= 0) {
            mPaddle.move(Vector2f(0.f, -400.f * deltaTime));
        }
    } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        if (mPaddle.getPosition().y <= 720 - 120) {
            mPaddle.move(Vector2f(0.f, 400.f * deltaTime));
        }
    }
}

PlayerRight:: PlayerRight() {
    mPaddle.setPosition(Vector2f(1280.f - 60.f, (720.f / 2.f) - (mPaddle.getSize().y / 2)));
    mPaddle.setSize(Vector2f(20.f, 120.f));
}

void PlayerRight:: update(float deltaTime) {
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        if (mPaddle.getPosition().y >= 0) {
            mPaddle.move(Vector2f(0.f, -400.f * deltaTime));
        } 
    } else if (Keyboard::isKeyPressed(Keyboard::S)) {
        if (mPaddle.getPosition().y <= 720 - 120) {
            mPaddle.move(Vector2f(0.f, 400.f * deltaTime));
        }
    }
}