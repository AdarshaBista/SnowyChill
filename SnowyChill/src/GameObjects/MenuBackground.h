#pragma once

#include <SFML/Graphics.hpp>

#include "Utility/Values.h"

class MenuBackground
{
private:
	sf::Texture bgTexture;
	sf::Sprite background;

public:
	MenuBackground();

	void setColor(const sf::Color& color);
	void draw(sf::RenderWindow& window);

};
