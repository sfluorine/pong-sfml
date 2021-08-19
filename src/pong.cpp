#include "pong.h"

using namespace sf;

Pong:: Pong() {
    Window.create(VideoMode(1280, 720), "Pong");
    gState = RUNNING;
}

Pong:: ~Pong() {
    if (player1 != nullptr) {
        delete player1;
    }
    if (player2 != nullptr) {
        delete player2;
    }
}

void Pong:: input() {
    Event event;

    while (Window.pollEvent(event)) {
        if (event.type == Event::Closed) Window.close();
    }
}

void Pong:: draw() {
    Window.clear();
    Window.draw(Ball.getBall());
    Window.draw(player1->getPaddle());
    Window.draw(player2->getPaddle());
    Window.draw(scoreLeft);
    Window.draw(scoreRight);
    Window.display();
}

void Pong:: start() {
    Font font;
    font.loadFromFile("res/Peepo.ttf");
    scoreLeft.setFont(font);
    scoreLeft.setString("0");
    scoreLeft.setPosition(Vector2f((Window.getSize().x / 2) - 40, 30));
    scoreRight.setFont(font);
    scoreRight.setString("0");
    scoreRight.setPosition(Vector2f((Window.getSize().x / 2) + 30, 30));

    Clock clock;

    while (Window.isOpen() && gState == RUNNING) {
        input(); 
        draw();

        float dt = clock.restart().asSeconds();

        Ball.update(dt, player1, player2, scoreLeft, scoreRight);
        player1->update(dt);
        player2->update(dt);
    }
}