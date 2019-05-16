#pragma once

#include "Utility/Util.h"

#include "Game/ResourceHolder.h"
#include "GameState.h"
#include "ShakeScreenState.h"

class Game;
class ResourceHolder;

class RunningState : public GameState
{
private:
	Game* game;
	std::shared_ptr<ResourceHolder> r;

private:
	bool hasCollided(const float distanceSq);
	void calculateNearMiss(const float distanceSq, Tree& tree);

public:
	RunningState(Game* const game);

	virtual void handleEvents(const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;

};

