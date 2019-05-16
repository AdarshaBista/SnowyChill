#include "MenuState.h"


MenuState::MenuState(Game* const game) : game(game), r(game->res)
{
	r->buttons["play"]->setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT + 100.0f));
	r->buttons["night"]->setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT + 100.0f));
	r->buttons["exit"]->setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT + 100.0f));
	
	r->labels["snowy"]->setPosition(sf::Vector2f(WIDTH / 2.0f, -100.0f));
	r->labels["chill"]->setPosition(sf::Vector2f(WIDTH / 2.0f, -100.0f));
}

void MenuState::handleEvents(const sf::Event& event)
{
	for (auto& button : r->buttons)
		button.second->handleEvents(game->app.window, event);
}

void MenuState::update()
{
	r->buttons["play"]->lerp(sf::Vector2f(0.34f * WIDTH, HEIGHT / 1.4f));
	r->buttons["night"]->lerp(sf::Vector2f(0.5f * WIDTH, HEIGHT / 1.4f));
	r->buttons["exit"]->lerp(sf::Vector2f(0.66f * WIDTH, HEIGHT / 1.4f));

	r->labels["snowy"]->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 6.5f));
	r->labels["chill"]->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 4.0f));

	r->labels["wasted"]->lerp(sf::Vector2f(WIDTH / 2.0f, -100.0f));
	r->labels["continue"]->lerp(sf::Vector2f(WIDTH / 2.0f, -100.0f));

	r->score->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT + 100.0f));
	r->ball->lerp(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 3.0f));

	for (auto& tree : r->trees)
		tree->lerp(tree->position);

	for (auto& button : r->buttons)
		button.second->update(game->app.window);
}

void MenuState::draw(sf::RenderWindow& window)
{
	r->ball->draw(window, game->isNightMode);
	for (auto& tree : r->trees)
		tree->draw(window);
	r->menuBackground->draw(window);
	r->score->draw(window);

	r->labels["snowy"]->draw(window);
	r->labels["chill"]->draw(window);

	r->labels["wasted"]->draw(window);
	r->labels["continue"]->draw(window);

	for (auto& button : r->buttons)
		button.second->draw(window);
}