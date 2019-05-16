#pragma once

#include <SFML/Graphics.hpp>

#include "Utility/Values.h"
#include "Utility/Util.h"
#include "Widget.h"

class Label : public Widget
{
private:
	sf::Font font;
	sf::Text label;

public:
	Label(const std::string& labelStr, int charSize);
	
	void setLabel(const std::string& newLabel);
	void move(const sf::Vector2f& offset);
	void lerp(const sf::Vector2f& finalPos);

	virtual void setPosition(const sf::Vector2f& pos) override;
	virtual void setScale(const sf::Vector2f& factor) override;
	virtual void setColor(const sf::Color& color) override;
	virtual sf::Vector2f getPosition() override;

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& event) override;
	virtual void update(const sf::RenderWindow& window) override;
	virtual void draw(sf::RenderWindow& window) override;

};

