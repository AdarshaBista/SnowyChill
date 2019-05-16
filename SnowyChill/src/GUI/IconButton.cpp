#include "IconButton.h"


IconButton::IconButton(const std::string& iconPath, Audio* clickSound)
	: onPressed([]() {}), clickSound(clickSound)
{
	// Load and set icon texture
	iconTex.loadFromFile(iconPath);
	iconTex.setSmooth(true);
	icon.setTexture(iconTex);

	// Set center as origin
	icon.setOrigin(icon.getGlobalBounds().width / 2.0f, icon.getGlobalBounds().height / 2.0f);
}

bool IconButton::isClicked(const sf::RenderWindow & window, const sf::Event& event)
{
	return	event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Left &&
			isHovering(window);
}

bool IconButton::isHovering(const sf::RenderWindow& window)
{
	return  icon.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x,
											(float)sf::Mouse::getPosition(window).y);
}

void IconButton::animate(const sf::RenderWindow & window)
{
	if (isHovering(window))
	{
		anim.cover(this);
		anim.enlarge(this);
	}
	else
	{
		anim.resetCover(this);
		anim.resetEnlarge(this);
	}
}

void IconButton::setCallback(std::function<void()> onPressedCallback)
{
	onPressed = onPressedCallback;
}

void IconButton::lerp(const sf::Vector2f& finalPos)
{
	if (icon.getPosition() == finalPos)
		return;

	icon.setPosition(Util::getInterpolatedPosition(icon.getPosition(), finalPos, LERP_STEP));
}

void IconButton::setPosition(const sf::Vector2f& pos)
{
	icon.setPosition(pos);
}

void IconButton::setScale(const sf::Vector2f& factor)
{
	icon.setScale(factor);
}

void IconButton::setColor(const sf::Color& color)
{
	icon.setColor(color);
}


sf::Vector2f IconButton::getPosition()
{
	return icon.getPosition();
}


void IconButton::handleEvents(const sf::RenderWindow & window, const sf::Event& event)
{
	if (isClicked(window, event))
	{
		clickSound->play();
		onPressed();
	}
}

void IconButton::update(const sf::RenderWindow & window)
{
	animate(window);
}

void IconButton::draw(sf::RenderWindow & window)
{
	window.draw(icon);
}