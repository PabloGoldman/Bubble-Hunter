#include "Rules.h"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\Font.hpp>

const int fontSize = 28;

using namespace sf;

void Rules::InRules()
{
	CheckInput();
	DrawRules();
}

void Rules::DrawRules()
{
	Font font;
	DrawText("Left player controls are  | W , S |", 10, 10, fontSize, sf::Color::Black);
	DrawText("Right player controls are |Up arrow , Down arrow| ", 10, 60, fontSize, sf::Color::Black);
	DrawText("First player to reach 10 points win the game", 10, 110, fontSize, sf::Color::Black);
	DrawText("If a player hits 7 points, the other player will get a buff!", 10, 160, fontSize, sf::Color::Black);
	DrawText("Take care if both players reach 7 points!", 10, 210, fontSize, sf::Color::Black);
	DrawText("Press |P| to pause the game while playing", 10, 260, fontSize, sf::Color::Black);
	DrawText("Press enter to continue...", 10, 400, fontSize, sf::Color::Black);
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
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		ReturnToMenu();
	}
}
