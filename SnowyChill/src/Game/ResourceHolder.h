#pragma once

#include <map>
#include <vector>
#include <memory>

#include "Game.h"

#include "Utility/Values.h"
#include "Utility/Util.h"

#include "Audio/Audio.h"
#include "Audio/Music.h"
#include "Audio/Sound.h"

#include "GUI/Widget.h"
#include "GUI/IconButton.h"
#include "GUI/Label.h"

#include "GameObjects/MenuBackground.h"
#include "GameObjects/Score.h"
#include "GameObjects/Tree.h"
#include "GameObjects/Ball.h"

#include "States/RunningState.h"

class Game;

class ResourceHolder
{
private:
	Game* game;
	sf::Texture treeTexture;

public:
	std::map<std::string, std::unique_ptr<Audio>> audio;
	std::map<std::string, std::unique_ptr<IconButton>> buttons;
	std::map<std::string, std::unique_ptr<Label>> labels;

	std::unique_ptr<MenuBackground> menuBackground;
	std::unique_ptr<Score> score;
	std::unique_ptr<Ball> ball;
	std::vector<std::unique_ptr<Tree>> trees;

private:
	void addAudio();
	void addWidgets();
	void addgameObjects();

public:
	ResourceHolder(Game* game);

	ResourceHolder(const ResourceHolder&) = delete;
	ResourceHolder& operator=(const ResourceHolder&) = delete;
};

