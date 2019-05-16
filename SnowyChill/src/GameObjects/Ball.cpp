#include "Ball.h"


Ball::Ball(const sf::Color& color)
	: acceleration(0.4f), maxSpeed(5.0f), dir(1), speed(0.0f), trailIndex(0)
{
	ball.setRadius(BALL_RADIUS);
	ball.setOrigin(ball.getLocalBounds().width / 2.0f, ball.getLocalBounds().height / 2.0f);
	ball.setPosition(WIDTH / 2.0f, -100.0f);
	light.setPosition(ball.getPosition());

	reset(color);
}

sf::Vector2f Ball::getPosition()
{
	return ball.getPosition();
}

void Ball::setPosition(const sf::Vector2f& pos)
{
	ball.setPosition(pos);
	light.setPosition(pos);
}

void Ball::move(const sf::Vector2f& offset)
{
	ball.move(offset);
	for (Trail& trail : trails)
		trail.move(offset);
}

void Ball::lerp(const sf::Vector2f& finalPos)
{
	if (ball.getPosition() == finalPos)
		return;

	ball.setPosition(Util::getInterpolatedPosition(ball.getPosition(), finalPos, LERP_STEP));
	light.setPosition(ball.getPosition());
}

void Ball::handleEvents(const sf::Event& event, Audio& turnSound)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		dir = -dir;
		turnSound.play();
	}
}

void Ball::update(float treeSpeed)
{
	speed += acceleration * dir;
	if (speed > maxSpeed || speed < -maxSpeed)
		speed = maxSpeed * dir;

	ball.move(speed, 0.0f);
	light.setPosition(ball.getPosition());

	// Wrap Trails
	trailIndex++;
	if (trailIndex == TRAILS_NUM - 1)
		trailIndex = 0;

	trails[trailIndex].setPosition(ball.getPosition());
	for (unsigned int i = 0; i < TRAILS_NUM; i++)
		trails[i].move(sf::Vector2f(0.0f, -treeSpeed));
}

void Ball::draw(sf::RenderWindow& window, bool isNightMode)
{
	if (isNightMode)
		light.draw(window);

	for (Trail& trail : trails)
		trail.draw(window);

	window.draw(ball);
}

void Ball::reset(const sf::Color& color)
{
	speed = 0.0f;
	dir = 1;
	trailIndex = 0;

	ball.setFillColor(sf::Color(300 - color.r, 300 - color.g, 300 - color.b));
	light.setColor(ball.getFillColor());

	for (int i = 0; i < TRAILS_NUM; ++i)
	{
		trails[i].reset(color);
		trails[i].setPosition(sf::Vector2f(ball.getPosition().x, -10.0f));
	}
}