#include "pong.h"

using namespace sf;

Pong:: Pong() {
    Window.create(VideoMode(1280, 720), "Pong");
    Window.setFramerateLimit(0);
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
        if (event.type == Event::Closed) {
            Window.close();
        }
    }
}

void Pong:: draw() {
    Window.clear();
    Window.draw(Ball.getBall());
    Window.draw(player1->getPaddle());
    Window.draw(player2->getPaddle());
    Window.display();
}

void Pong:: start() {
    Clock clock;

    while (Window.isOpen() && gState == RUNNING) {
        input(); 
        draw();

        float dt = clock.restart().asSeconds();

        Ball.update(dt, player1, player2, gState);
        player1->update(dt);
        player2->update(dt);
    }
}