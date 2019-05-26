#include "Score.h"


Score::Score(const sf::Color& color)
	: shouldDrawPopUp(false), score(0.0f), treeCount(0), popUpMoveOffset(0.0f)
{
	scoreLabel = std::make_unique<Label>("0", 40);
	scoreLabel->setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT + 100.0f));
	
	popUpLabel = std::make_unique<Label>("0", 30);
	popUpLabel->setPosition(sf::Vector2f(WIDTH / 2.0f, -100.0f));

	reset(color);
}

void Score::addNearMissBonus()
{
	treeCount++;
	score += (float)treeCount;
}

void Score::setupPopUp(const sf::Vector2f& treePosition)
{
	popUpLabel->setLabel(std::to_string(treeCount));
	popUpLabel->setPosition(sf::Vector2f(treePosition.x , treePosition.y - 100.0f));
	
	popUpMoveOffset = 0.0f;
	popUpAnimClock.restart();
	shouldDrawPopUp = true;
}

void Score::setPosition(const sf::Vector2f& pos)
{
	scoreLabel->setPosition(pos);
}

void Score::lerp(const sf::Vector2f& finalPos)
{
	if (scoreLabel->getPosition() == finalPos)
		return;

	scoreLabel->setPosition(Util::getInterpolatedPosition(scoreLabel->getPosition(), finalPos, LERP_STEP));
}

sf::Vector2f Score::getPosition()
{
	return scoreLabel->getPosition();
}

void Score::update()
{
	score += 0.1f;
	scoreLabel->setLabel(std::to_string((int)score));
}

void Score::draw(sf::RenderWindow& window)
{
	scoreLabel->draw(window);

	if (shouldDrawPopUp)
	{
		popUpElapsed = popUpAnimClock.getElapsedTime();
		if (popUpElapsed.asMilliseconds() < 300)
		{
			popUpMoveOffset += 0.5f;
			popUpLabel->move(sf::Vector2f(0.0f, -popUpMoveOffset));
			popUpLabel->draw(window);
		}
		else
			shouldDrawPopUp = false;
	}
}

void Score::reset(const sf::Color& color)
{
	scoreLabel->setColor(sf::Color(300 - color.r, 300 - color.g, 300 - color.b));
	popUpLabel->setColor(sf::Color(300 - color.r, 300 - color.g, 300 - color.b));

	score = 0.0f;
	treeCount = 0;
}