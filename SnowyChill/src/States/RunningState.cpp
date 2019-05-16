#include "RunningState.h"


RunningState::RunningState(Game* const game) : game(game), r(game->res)
{
}

void RunningState::handleEvents(const sf::Event& event)
{
	r->ball->handleEvents(event, *r->audio["turn"]);
}

void RunningState::update()
{
	r->buttons["play"]->lerp(sf::Vector2f(0.34f * WIDTH, HEIGHT + 100.0f));
	r->buttons["night"]->lerp(sf::Vector2f(0.5f * WIDTH, HEIGHT + 100.0f));
	r->buttons["exit"]->lerp(sf::Vector2f(0.66f * WIDTH, HEIGHT + 100.0f));

	r->labels["snowy"]->lerp(sf::Vector2f(WIDTH / 2.0f, -100.0f));
	r->labels["chill"]->lerp(sf::Vector2f(WIDTH / 2.0f, -100.0f));

	r->score->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 20.0f));

	r->ball->update(Tree::speed);
	r->score->update();
	for (auto& tree : r->trees)
		tree->update();

	for (auto& tree : r->trees)
	{
		float distanceSq = Util::getDistanceSq(tree->getPosition(), r->ball->getPosition());

		calculateNearMiss(distanceSq, *tree);
		if (hasCollided(distanceSq))
		{
			r->audio["hit"]->play();
			game->currentState = std::move(std::make_unique<ShakeScreenState>(game));
			break;
		}
	}
}

void RunningState::draw(sf::RenderWindow& window)
{
	r->ball->draw(window, game->isNightMode);
	for (auto& tree : r->trees)
		tree->draw(window);
	r->score->draw(window);

	r->labels["snowy"]->draw(window);
	r->labels["chill"]->draw(window);

	for (auto& button : r->buttons)
		button.second->draw(window);
}

void RunningState::calculateNearMiss(const float distanceSq, Tree& tree)
{
	if (!tree.hasPassed)
	{
		if (distanceSq < NEAR_MISS_RADIUS * NEAR_MISS_RADIUS)
		{
			tree.hasPassed = true;

			r->audio["nearMiss"]->play();
			r->score->addNearMissBonus();
			r->score->setupPopUp(tree.getPosition());
		}
	}
}

bool RunningState::hasCollided(const float distanceSq)
{
	return (distanceSq < BALL_RADIUS * BALL_RADIUS ||
			r->ball->getPosition().x < 0.0f || 
			r->ball->getPosition().x > WIDTH);
}