#pragma once

#include "ball.h"
#include "paddle.h"
#include "gamestate.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Pong {
public:
    RenderWindow Window;
    Ball Ball;   
    Paddle * player1 = new PlayerLeft;
    Paddle * player2 = new PlayerRight;
    GameState gState;
    Text scoreLeft;
    Text scoreRight;
public:
    Pong();
    ~Pong();
    void input();
    void draw();
    void start();

};