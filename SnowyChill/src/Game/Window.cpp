#include "Window.h"

Window::Window()
{
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Snowy Chill", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(FRAMERATE);
	window.setKeyRepeatEnabled(false);

	icon.loadFromFile(ICON_PATH);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}