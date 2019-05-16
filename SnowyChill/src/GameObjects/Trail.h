#pragma once

#include <SFML/Graphics.hpp>

#include "Utility/Values.h"

class Trail
{
private:
	sf::CircleShape trail;

public:
	Trail();

	void move(const sf::Vector2f& offset);
	void setPosition(const sf::Vector2f& pos);
	void setColor(const sf::Color& color);

	void draw(sf::RenderWindow& window);
	void reset(const sf::Color& color);
};

