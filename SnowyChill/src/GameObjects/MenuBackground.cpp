#include "MenuBackground.h"

MenuBackground::MenuBackground()
{
	bgTexture.loadFromFile(MENU_BACKGROUND_PATH);
	background.setTexture(bgTexture);
	background.setPosition(0.0f, 0.0f);
}

void MenuBackground::setColor(const sf::Color& color)
{
	background.setColor(color);
}

void MenuBackground::draw(sf::RenderWindow& window)
{
	window.draw(background);
}