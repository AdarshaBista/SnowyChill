#include "Trail.h"


Trail::Trail()
{
	trail.setRadius(TRAIL_RADIUS);
}

void Trail::move(const sf::Vector2f& offset)
{
	trail.move(offset);
}

void Trail::setPosition(const sf::Vector2f& pos)
{
	trail.setPosition(pos);
}

void Trail::setColor(const sf::Color& color)
{
	trail.setFillColor(sf::Color(250 - color.r, 250 - color.g, 250 - color.b, 150));
}

void Trail::draw(sf::RenderWindow& window)
{
	window.draw(trail);
}

void Trail::reset(const sf::Color& color)
{
	setColor(color);
}
