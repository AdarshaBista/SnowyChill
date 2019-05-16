#pragma once

#include <SFML/Graphics.hpp>

class Util
{
public:
	static sf::Color getColor();
	static float getDistanceSq(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);
	static sf::Vector2f getInterpolatedPosition(const sf::Vector2f& currentPos, const sf::Vector2f& finalPos, float step);
};

