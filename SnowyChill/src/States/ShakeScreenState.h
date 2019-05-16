#pragma once

#include "Game/ResourceHolder.h"
#include "GameState.h"
#include "GameOverState.h"

class Game;
class ResourceHolder;

class ShakeScreenState : public GameState
{
private:
	sf::Clock shakeClock;
	sf::Time shakeElapsed;

	Game* game;
	std::shared_ptr<ResourceHolder> r;

public:
	ShakeScreenState(Game* const game);

	virtual void handleEvents(const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;

};

