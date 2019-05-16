#pragma once

#include <array>
#include <functional>
#include <SFML/Graphics.hpp>

#include "Utility/Values.h"
#include "Utility/Util.h"
#include "Audio/Audio.h"
#include "Trail.h"
#include "Light.h"
#include "Tree.h"

class Ball
{
private:
	sf::CircleShape ball;
	const float acceleration;
	const float maxSpeed;
	float speed;

	std::array<Trail, TRAILS_NUM> trails;
	int trailIndex;

	Light light;

public:
	int dir;

public:
	Ball(const sf::Color& color);
	
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& pos);
	void move(const sf::Vector2f& offset);
	void lerp(const sf::Vector2f& finalPos);

	void handleEvents(const sf::Event& event, Audio& turnSound);
	void update(float treeSpeed);
	void draw(sf::RenderWindow& window, bool isNightMode);
	void reset(const sf::Color& color);

};

