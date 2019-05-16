#pragma once

#include <SFML/Graphics.hpp>

#include "Utility/Values.h"

class Window
{
private:
	sf::Image icon;

public:
	sf::RenderWindow window;

public:
	Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
};

