#include "Game.h"


Game::Game() : isNightMode(false), clearColor(sf::Color::White)
{
	res = std::make_shared<ResourceHolder>(this);
	currentState = std::make_unique<MenuState>(this);
}

void Game::run()
{
	res->audio["theme"]->play();
	res->audio["wind"]->play();

	while (app.window.isOpen())
	{
		sf::Event event;
		while (app.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				app.window.close();

			currentState->handleEvents(event);
		}

		currentState->update();
		app.window.clear(clearColor);
		currentState->draw(app.window);
		app.window.display();
	}
}

void Game::toggleNightMode()
{
	isNightMode = !isNightMode;

	if (isNightMode)
	{
		clearColor = sf::Color(10, 10, 35);
		res->menuBackground->setColor(sf::Color::Black);

		for (auto& label : res->labels)
			label.second->setColor(sf::Color::White);

		for (auto& tree : res->trees)
			tree->setColor(sf::Color::Black);
	}

	if (!isNightMode)
	{
		clearColor = sf::Color::White;
		res->menuBackground->setColor(sf::Color::White);

		for (auto& label : res->labels)
			label.second->setColor(sf::Color::Black);

		sf::Color treeColor = Util::getColor();
		for (auto& tree : res->trees)
			tree->setColor(treeColor);
	}
}
