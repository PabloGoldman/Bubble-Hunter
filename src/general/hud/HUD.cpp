#include "HUD.h"
#include "general/externs/Externs.h"

#include <string>

void HUD::DrawPoints(int points, int posX, int posY, int fontSize, sf::Color color, sf::RenderWindow* window)
{
	sf::Text t;

	t.setFont(ExternVars::font);

	t.setCharacterSize(fontSize);

	t.setString(std::to_string(points));

	t.setPosition(sf::Vector2f(posX, posY));

	t.setFillColor(color);

	window->draw(t);
}
