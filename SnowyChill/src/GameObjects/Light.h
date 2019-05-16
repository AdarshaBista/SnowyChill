#pragma once

#include <SFML/Graphics.hpp>

#include "Utility/Values.h"

class Light
{
private:
	sf::Texture lightTexture;
	sf::Sprite light;

public:
	Light();

	void setPosition(const sf::Vector2f& pos);
	void setColor(const sf::Color& color);

	void draw(sf::RenderWindow& window);

};

