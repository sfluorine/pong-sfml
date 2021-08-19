#include "ball.h"

using namespace sf;

Ball::Ball()
{
    mBall.setRadius(10.f);
    mBall.setPointCount(10);
    mBall.setPosition({1280.f / 2.f, 720.f / 2.f});

    velocity.x = 300;
    velocity.y = 300;
    mScoreLeft = 0;
    mScoreRight = 0;
}

void Ball::playerScore(Text &text)
{
}

void Ball::update(float dt, Paddle *&player1, Paddle *&player2, Text &l, Text &r)
{
    if (mBall.getPosition().y >= 720 - mBall.getRadius())
    {
        velocity.y = -300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    }
    else if (mBall.getPosition().x >= 1280)
    {
        sleep(sf::Time(sf::seconds(1)));
        mBall.setPosition(sf::Vector2f(1280 / 2, 720 / 2));
        mBall.move(Vector2f(velocity.x * dt, 0 * dt));
    }
    else if (mBall.getPosition().x <= 0)
    {
        sleep(sf::Time(sf::seconds(1)));
        mBall.setPosition(sf::Vector2f(1280 / 2, 720 / 2));
        mBall.move(Vector2f(-velocity.x * dt, 0 * dt));
    }
    else if (mBall.getPosition().y <= 0)
    {
        velocity.y = 300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    }
    else if (mBall.getGlobalBounds().intersects(player1->getPaddle().getGlobalBounds()))
    {
        velocity.x = 300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    }
    else if (mBall.getGlobalBounds().intersects(player2->getPaddle().getGlobalBounds()))
    {
        velocity.x = -300;
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    }
    else
    {
        mBall.move(Vector2f(velocity.x * dt, velocity.y * dt));
    }
}

CircleShape &Ball::getBall()
{
    return mBall;
}