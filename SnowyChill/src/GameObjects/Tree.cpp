#include "Tree.h"


Tree::Tree(const sf::Color& color, const sf::Texture& treeTexture) : hasPassed(false)
{
	tree.setTexture(treeTexture);

	// Set tree origin to the root of tree
	tree.setOrigin(tree.getLocalBounds().width / 5.0f, tree.getLocalBounds().height / 1.1f);
	tree.setPosition(WIDTH / 2.0f, HEIGHT + 200.0f);

	reset(color, false);
}

sf::Vector2f Tree::getPosition()
{
	return tree.getPosition();
}

void Tree::setPosition(const sf::Vector2f& pos)
{
	tree.setPosition(pos);
}

void Tree::setColor(const sf::Color& color)
{
	tree.setColor(color);
}

void Tree::move(const sf::Vector2f& offset)
{
	tree.move(offset);
}

void Tree::lerp(const sf::Vector2f& finalPos)
{
	if (tree.getPosition() == finalPos)
		return;

	tree.setPosition(Util::getInterpolatedPosition(tree.getPosition(), finalPos, LERP_STEP));
}

void Tree::update()
{
	speed += (speed < 3.0f) ? 0.001f : 0.00001f;

	if (speed > maxSpeed)
		speed = maxSpeed;

	tree.move(0.0f, -speed);

	// Wrap Trees
	if (tree.getPosition().y < 0.0f)
	{
		int randomX = rand() % WIDTH;
		tree.setPosition((float)randomX, HEIGHT + 80.0f);
		hasPassed = false;
	}
}

void Tree::draw(sf::RenderWindow& window)
{
	window.draw(tree);
}

void Tree::reset(const sf::Color& color, bool isNightMode)
{
	speed = 0.0f;

	if (!isNightMode)
		tree.setColor(color);

	float scale = ((rand() % 6) + 8) / 10.0f;
	tree.setScale(scale, scale);

	int randomX = rand() % WIDTH;
	int randomY = rand() % HEIGHT;
	position = sf::Vector2f((float)randomX, HEIGHT / 1.5f + randomY);
}

const float Tree::maxSpeed = 7.0f;
float Tree::speed = 0.0f;
