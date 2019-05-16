#include "ResourceHolder.h"

ResourceHolder::ResourceHolder(Game* game) : game(game)
{
	addAudio();
	addWidgets();
	addgameObjects();
}

void ResourceHolder::addAudio()
{
	audio["theme"] = std::make_unique<Music>(THEME_SOUND_PATH);
	audio["wind"] = std::make_unique<Music>(WIND_SOUND_PATH);
	audio["click"] = std::make_unique<Sound>(CLICK_SOUND_PATH);
	audio["turn"] = std::make_unique<Sound>(TURN_SOUND_PATH);
	audio["nearMiss"] = std::make_unique<Sound>(NEAR_MISS_SOUND_PATH);
	audio["hit"] = std::make_unique<Sound>(HIT_SOUND_PATH);
}

void ResourceHolder::addWidgets()
{
	// Buttons
	buttons["play"] = std::make_unique<IconButton>(PLAY_BUTTON_PATH, audio["click"].get());
	buttons["night"] = std::make_unique<IconButton>(NIGHT_BUTTON_PATH, audio["click"].get());
	buttons["exit"] = std::make_unique<IconButton>(EXIT_BUTTON_PATH, audio["click"].get());

	buttons["play"]->setCallback([&]() { game->currentState = std::move(std::make_unique<RunningState>(game)); });
	buttons["night"]->setCallback([&]() { game->toggleNightMode(); });
	buttons["exit"]->setCallback([&]() { game->app.window.close(); });

	// Labels
	labels["snowy"] = std::make_unique<Label>("SNOWY", 60);
	labels["chill"] = std::make_unique<Label>("CHILL", 70);
	labels["wasted"] = std::make_unique<Label>("WASTED", 60);
	labels["continue"] = std::make_unique<Label>("Click to continue", 40);
}

void ResourceHolder::addgameObjects()
{
	sf::Color gameObjectColor = Util::getColor();

	menuBackground = std::make_unique<MenuBackground>();
	score = std::make_unique<Score>(gameObjectColor);
	ball = std::make_unique<Ball>(gameObjectColor);

	treeTexture.loadFromFile(TREE_PATH);
	treeTexture.setSmooth(true);
	
	trees.reserve(TREE_NUM);
	for (int i = 0; i < TREE_NUM; ++i)
		trees.emplace_back(std::make_unique<Tree>(gameObjectColor, treeTexture));
}