#include "Credits.h"
#include "SFML/Graphics.hpp"

using namespace sf;

void Credits::InCredits()
{
	CheckInput();
	DrawCredits();
}

void Credits::DrawCredits()
{
	Font font;
	DrawText("Credits:", 10, 10, 40, sf::Color::Black);
	DrawText("Creator: Pablo Goldman", 10, 60, 40, sf::Color::Black);
	DrawText("Logo designer: Fermin Gimpel", 10, 110, 40, sf::Color::Black);
	DrawText("Music By: Lautaro Bianco", 10, 160, 40, sf::Color::Black);
	DrawText("Library Creator: Raysan", 10, 210, 40, sf::Color::Black);
	DrawText("Press enter to continue...", 10, 400, 40, sf::Color::Black);
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
	if (sf::Keyboard::isKeyPressed(Keyboard::Enter))
	{
		ReturnToMenu();
	}
}
