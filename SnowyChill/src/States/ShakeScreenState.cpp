#include "ShakeScreenState.h"

ShakeScreenState::ShakeScreenState(Game* const game) : game(game), r(game->res)
{
	shakeClock.restart();
}

void ShakeScreenState::handleEvents(const sf::Event& event)
{
}

void ShakeScreenState::update()
{
	shakeElapsed = shakeClock.getElapsedTime();
	float shakeAmt = sin(shakeElapsed.asMilliseconds() / 20.0f) * 8.0f;

	// Shake objects
	r->ball->move(sf::Vector2f(shakeAmt, 0.0f));
	for (auto& tree : r->trees)
		tree->move(sf::Vector2f(shakeAmt, 0.0f));

	if (shakeElapsed.asMilliseconds() > 600)
		game->currentState = std::move(std::make_unique<GameOverState>(game));
}

void ShakeScreenState::draw(sf::RenderWindow& window)
{
	r->ball->draw(window, game->isNightMode);
	for (auto& tree : r->trees)
		tree->draw(window);
	r->score->draw(window);
}