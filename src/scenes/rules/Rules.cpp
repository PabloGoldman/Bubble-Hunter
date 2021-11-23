#include "Rules.h"
#include <SFML\Window\Keyboard.hpp>

const int fontSize = 28;

void Rules::InRules(sf::RenderWindow* window)
{
	CheckInput();
	DrawRules(window);
}

void Rules::DrawRules(sf::RenderWindow* window)
{
	sf::Font font;
	font.loadFromFile("font/font.ttf");
	
	sf::Color color = sf::Color::Black;

	sf::Text text;
	text.setFont(font);
	text.setFillColor(color);

	text.setString("Left player controls are  | W , S |");
	text.setPosition(sf::Vector2f(10, 10));
	window->draw(text);

	text.setString("Right player controls are |Up arrow , Down arrow| ");
	text.setPosition(sf::Vector2f(10, 60));
	window->draw(text);

	text.setString("First player to reach 10 points win the game");
	text.setPosition(sf::Vector2f(10, 110));
	window->draw(text);

	text.setString("If a player hits 7 points, the other player will get a buff!");
	text.setPosition(sf::Vector2f(10, 160));
	window->draw(text);

	text.setString("Take care if both players reach 7 points!");
	text.setPosition(sf::Vector2f(10, 210));
	window->draw(text);

	text.setString("Press |P| to pause the game while playing");
	text.setPosition(sf::Vector2f(10, 260));
	window->draw(text);

	text.setString("Press enter to continue...");
	text.setPosition(sf::Vector2f(10, 400));
	window->draw(text);
}

void Rules::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Rules::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Rules::CheckInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		ReturnToMenu();
	}
}
