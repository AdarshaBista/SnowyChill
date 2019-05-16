#include "GameOverState.h"

GameOverState::GameOverState(Game* const game) : game(game), r(game->res)
{
}

void GameOverState::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		sf::Color newColor = Util::getColor();

		// Reset game objects
		r->ball->reset(newColor);
		r->score->reset(newColor);
		for (auto& tree : r->trees)
			tree->reset(newColor, game->isNightMode);

		game->currentState = std::move(std::make_unique<MenuState>(game));
	}
}

void GameOverState::update()
{
	r->labels["wasted"]->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 6.5f));
	r->labels["continue"]->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 4.0f));
	
	r->score->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 1.5f));
}

void GameOverState::draw(sf::RenderWindow& window)
{
	r->ball->draw(window, game->isNightMode);
	for (auto& tree : r->trees)
		tree->draw(window);
	r->menuBackground->draw(window);
	r->score->draw(window);

	r->labels["wasted"]->draw(window);
	r->labels["continue"]->draw(window);
}