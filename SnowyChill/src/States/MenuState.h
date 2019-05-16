#pragma once

#include "Game/ResourceHolder.h"
#include "GameState.h"

class Game;
class ResourceHolder;

class MenuState : public GameState
{
private:
	Game* game;
	std::shared_ptr<ResourceHolder> r;

public:
	MenuState(Game* const game);

	virtual void handleEvents(const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;

};

