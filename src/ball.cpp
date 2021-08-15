#include "ball.h"

using namespace sf;

Ball:: Ball() {
    mBall.setRadius(10.f);
    mBall.setPointCount(10);
    mBall.setPosition({1280.f / 2.f, 720.f / 2.f});

    velocity.x = 300;
    velocity.y = 300;
}

void Ball:: update(float dt, Paddle *& player1, Paddle *& player2, GameState & state) {
    if (mBall.getPosition().y >= 720 - mBall.getRadius()) {
        velocity.y = -300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    } else if (mBall.getPosition().x >= 1280) {
        std::cout << "Player left win!" << std::endl;
        state = P_LEFT_WIN;
    } else if (mBall.getPosition().x <= 0) {
        std::cout << "Player right win!" << std::endl;
        state = P_RIGHT_WIN;
    } else if (mBall.getPosition().y <= 0) {
        velocity.y = 300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    } else if (mBall.getGlobalBounds().intersects(player1->getPaddle().getGlobalBounds())) {
        velocity.x = 300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    } else if (mBall.getGlobalBounds().intersects(player2->getPaddle().getGlobalBounds())) {
        velocity.x = -300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    } else {
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    }
}

CircleShape & Ball:: getBall() {
    return mBall;
}