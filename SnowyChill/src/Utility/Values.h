#pragma once

#include <string>

// Window
constexpr int FRAMERATE = 60;
constexpr int WIDTH = 500;
constexpr int HEIGHT = 800;

// Icon
constexpr auto ICON_PATH = "assets/icon/icon.png";

// Font
constexpr auto FONT_PATH = "assets/fonts/JosefinSans.ttf";

// Menu
constexpr auto MENU_BACKGROUND_PATH = "assets/sprites/menu/menuBackground.png";
constexpr auto PLAY_BUTTON_PATH = "assets/sprites/buttons/play.png";
constexpr auto EXIT_BUTTON_PATH = "assets/sprites/buttons/exit.png";
constexpr auto NIGHT_BUTTON_PATH = "assets/sprites/buttons/night.png";

// Sounds
constexpr auto THEME_SOUND_PATH = "assets/sounds/theme.ogg";
constexpr auto WIND_SOUND_PATH = "assets/sounds/wind.ogg";
constexpr auto CLICK_SOUND_PATH = "assets/sounds/click.ogg";
constexpr auto TURN_SOUND_PATH = "assets/sounds/turn.ogg";
constexpr auto NEAR_MISS_SOUND_PATH = "assets/sounds/nearMiss.ogg";
constexpr auto HIT_SOUND_PATH = "assets/sounds/hit.ogg";

// Ball
constexpr float BALL_RADIUS = 6.0f;

// Near Miss
constexpr float NEAR_MISS_RADIUS = BALL_RADIUS * 6.0f;

// Light
constexpr auto LIGHT_PATH = "assets/sprites/light/light.png";

// Trails
constexpr float TRAIL_RADIUS = 2.0f;
constexpr int TRAILS_NUM = 150;

// Tree
constexpr int TREE_NUM = 30;
constexpr auto TREE_PATH = "assets/sprites/tree/tree.png";

// Lerp
constexpr float LERP_STEP = 0.08f;
