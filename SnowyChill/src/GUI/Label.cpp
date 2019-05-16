#include "Label.h"


Label::Label(const std::string& labelStr, int charSize)
{
	// Load text
	font.loadFromFile(FONT_PATH);
	label.setFont(font);
	label.setCharacterSize(charSize);
	label.setFillColor(sf::Color::White);
	label.setString(labelStr);
	label.setFillColor(sf::Color::Black);

	label.setOrigin(label.getGlobalBounds().width / 2.0f + label.getGlobalBounds().left,
		label.getGlobalBounds().height / 2.0f + label.getGlobalBounds().top);
}

void Label::setLabel(const std::string& newLabel)
{
	label.setString(newLabel);
	label.setOrigin(label.getLocalBounds().width / 2.0f + label.getLocalBounds().left,
		label.getLocalBounds().height / 2.0f + label.getLocalBounds().top);
}

void Label::move(const sf::Vector2f& offset)
{
	label.move(offset);
}

void Label::lerp(const sf::Vector2f& finalPos)
{
	if (label.getPosition() == finalPos)
		return;

	label.setPosition(Util::getInterpolatedPosition(label.getPosition(), finalPos, LERP_STEP));
}

sf::Vector2f Label::getPosition()
{
	return label.getPosition();
}

void Label::setPosition(const sf::Vector2f& pos)
{
	label.setPosition(pos);
}

void Label::setScale(const sf::Vector2f& factor)
{
	label.setScale(factor);
}

void Label::setColor(const sf::Color& color)
{
	label.setFillColor(color);
}

void Label::handleEvents(const sf::RenderWindow& window, const sf::Event& event)
{
}

void Label::update(const sf::RenderWindow& window)
{
}

void Label::draw(sf::RenderWindow& window)
{
	window.draw(label);
}
