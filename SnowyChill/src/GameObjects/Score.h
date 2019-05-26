#pragma once

#include <memory>

#include "Utility/Values.h"
#include "Utility/Util.h"
#include "GUI/Label.h"

class Score
{
private:
	std::unique_ptr<Label> scoreLabel;
	std::unique_ptr<Label> popUpLabel;

	float score;
	int treeCount;

	bool shouldDrawPopUp;
	float popUpMoveOffset;
	sf::Clock popUpAnimClock;
	sf::Time popUpElapsed;

public:
	Score(const sf::Color& color);

	void addNearMissBonus();
	void setupPopUp(const sf::Vector2f& treePosition);

	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& pos);
	void lerp(const sf::Vector2f& finalPos);

	void update();
	void draw(sf::RenderWindow& window);
	void reset(const sf::Color& color);

};

