#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle {
protected:
    RectangleShape mPaddle;
public:
    virtual ~Paddle() { }
    RectangleShape & getPaddle();

    virtual void update(float deltaTime) = 0;
};

class PlayerLeft : public Paddle {
public:
    PlayerLeft();
public:
    void update(float deltaTime) override;
};

class PlayerRight : public Paddle {
public:
    PlayerRight();
public:
    void update(float deltaTime) override;
};