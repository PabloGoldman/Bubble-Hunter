#include "HUD.h"

#include <string>

void HUD::DrawPoints(int points, int posX, int posY, int fontSize, sf::Color color, sf::RenderWindow* window)
{
	sf::Font f;
	f.loadFromFile("font/font.ttf");

	sf::Text t;
	t.setFont(f);

	t.setString(std::to_string(points));

	t.setFillColor(color);

	t.setPosition(sf::Vector2f(posX, posY));

	window->draw(t);
}
