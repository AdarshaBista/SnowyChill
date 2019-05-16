#include "Widget.h"


Widget::Widget()
{
}


// Animations
Widget::Animation::Animation()
{
	scaleFactor = { 0.8f, 0.8f };
	maxScale = 0.9f;
	speed = 0.01f;
	coverColor = sf::Color(150, 150, 150);
}

void Widget::Animation::enlarge(Widget* widget)
{
	scaleFactor += {speed, speed};

	if (scaleFactor.x > maxScale)
		scaleFactor = { maxScale, maxScale };

	widget->setScale(scaleFactor);
}

void Widget::Animation::cover(Widget* widget)
{
	widget->setColor(coverColor);
}

void Widget::Animation::resetEnlarge(Widget* widget)
{
	scaleFactor -= {speed, speed};

	if (scaleFactor.x < 0.8f)
		scaleFactor = { 0.8f, 0.8f };

	widget->setScale(scaleFactor);
}

void Widget::Animation::resetCover(Widget* widget)
{
	widget->setColor(sf::Color::White);
}
