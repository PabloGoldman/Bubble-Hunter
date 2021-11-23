#include "Credits.h"
#include "SFML/Graphics.hpp"

using namespace sf;

void Credits::InCredits(sf::RenderWindow* window)
{
	CheckInput();
	DrawCredits(window);
}

void Credits::DrawCredits(sf::RenderWindow* window)
{

	sf::Font font;
	font.loadFromFile("font/font.ttf");

	sf::Color color = sf::Color::Black;

	sf::Text text;
	text.setFont(font);
	text.setFillColor(color);
	text.setCharacterSize(40);

	text.setString("Credits:");
	text.setPosition(sf::Vector2f(10, 10));
	window->draw(text);
	text.setString("Creator: Pablo Goldman");
	text.setPosition(sf::Vector2f(10, 60));
	window->draw(text);
	text.setString("Logo designer: Fermin Gimpel");
	text.setPosition(sf::Vector2f(10, 110));
	window->draw(text);
	text.setString("Music By: Lautaro Bianco");
	text.setPosition(sf::Vector2f(10, 160));
	window->draw(text);
	text.setString("Library Creator: Raysan");
	text.setPosition(sf::Vector2f(10, 210));
	window->draw(text);
	text.setString("Press enter to continue...");
	text.setPosition(sf::Vector2f(10, 400));
	window->draw(text);

}

void Credits::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Credits::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Credits::CheckInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		ReturnToMenu();
	}
}
