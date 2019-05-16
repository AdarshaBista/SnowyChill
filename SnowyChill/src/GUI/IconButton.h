#pragma once

#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>

#include "Audio/Audio.h"
#include "Utility/Values.h"
#include "Utility/Util.h"
#include "Widget.h"

class IconButton : public Widget
{
private:
	sf::Texture iconTex;
	sf::Sprite icon;
	
	std::function<void()> onPressed;
	Audio* clickSound;

private:
	bool isClicked(const sf::RenderWindow& window, const sf::Event& event);
	bool isHovering(const sf::RenderWindow& window);
	void animate(const sf::RenderWindow& window);

public:
	IconButton(const std::string& iconPath, Audio* clickSound);

	void setCallback(std::function<void()> onPressedCallback);
	void lerp(const sf::Vector2f& finalPos);

	virtual void setPosition(const sf::Vector2f& pos) override;
	virtual void setScale(const sf::Vector2f& factor) override;
	virtual void setColor(const sf::Color& color) override;
	virtual sf::Vector2f getPosition() override;

	virtual void handleEvents(const sf::RenderWindow& window, const sf::Event& event) override;
	virtual void update(const sf::RenderWindow& window) override;
	virtual void draw(sf::RenderWindow& window) override;

};

