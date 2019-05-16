#include "Util.h"


sf::Color Util::getColor()
{
	uint8_t r = (rand() % 5 + 4) * 25;;
	uint8_t g = (rand() % 5 + 4) * 25;;
	uint8_t b = (rand() % 5 + 4) * 25;;

	return sf::Color(r, g, b);
}

float Util::getDistanceSq(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint)
{
	float x2 = secondPoint.x;
	float x1 = firstPoint.x;
	float y2 = secondPoint.y;
	float y1 = firstPoint.y;

	return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

sf::Vector2f Util::getInterpolatedPosition(const sf::Vector2f& currentPos, const sf::Vector2f& finalPos, float step)
{
	sf::Vector2f pos;
	pos.x = (1 - step) * (currentPos.x) + step * (finalPos.x);
	pos.y = (1 - step) * (currentPos.y) + step * (finalPos.y);
	return pos;
}