#include "Light.h"


Light::Light()
{
	lightTexture.loadFromFile(LIGHT_PATH);
	light.setTexture(lightTexture);

	light.setOrigin(light.getLocalBounds().width / 2.0f, light.getLocalBounds().height / 2.0f);
	light.setScale(1.5f, 1.0f);
}

void Light::setPosition(const sf::Vector2f& pos)
{
	light.setPosition(pos);
}

void Light::setColor(const sf::Color& color)
{
	light.setColor(color);
}

void Light::draw(sf::RenderWindow& window)
{
	window.draw(light);
}
