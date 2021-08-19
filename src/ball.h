#pragma once

#include "paddle.h"
#include "gamestate.h"

#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
    CircleShape mBall;
    unsigned int mScoreLeft;
    unsigned int mScoreRight;

public:
    Ball();

public:
    CircleShape &getBall();

    void playerScore(Text &text);
    void update(float dt, Paddle *&player1, Paddle *&player2, Text &l, Text &r);

public:
    Vector2f velocity;
};