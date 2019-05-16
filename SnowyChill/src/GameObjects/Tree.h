#pragma once

#include <SFML/Graphics.hpp>

#include "Utility/Values.h"
#include "Utility/Util.h"

class Tree
{
private:
	sf::Sprite tree;
	static const float maxSpeed;

public:
	sf::Vector2f position;
	static float speed;
	bool hasPassed;

public:
	Tree(const sf::Color& color, const sf::Texture& treeTexture);

	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& pos);
	void setColor(const sf::Color& color);
	void move(const sf::Vector2f& offset);
	void lerp(const sf::Vector2f& finalPos);

	void update();
	void draw(sf::RenderWindow& window);
	void reset(const sf::Color& color, bool isNightMode);

};

