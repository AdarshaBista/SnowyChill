#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Window.h"
#include "ResourceHolder.h"

#include "States/GameState.h"
#include "States/MenuState.h"

class ResourceHolder;
class GameState;

class Game
{
public:
	Window app;
	std::shared_ptr<ResourceHolder> res;
	std::unique_ptr<GameState> currentState;
	
	bool isNightMode;
	sf::Color clearColor;

public:
	Game();
	
	void run();
	void toggleNightMode();

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
};

