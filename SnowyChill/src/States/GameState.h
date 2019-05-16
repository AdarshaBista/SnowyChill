#pragma once

#include <SFML/Graphics.hpp>

class GameState
{
public:
	virtual void handleEvents(const sf::Event& event) = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

};