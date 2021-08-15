#pragma once

#include "paddle.h"
#include "gamestate.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball {
private:
    CircleShape mBall; 

public:
    Ball();
public:
    CircleShape & getBall();
    
    void move();
    void update(float dt, Paddle *& player1, Paddle *& player2, GameState & state);
public:
    Vector2f velocity;

};