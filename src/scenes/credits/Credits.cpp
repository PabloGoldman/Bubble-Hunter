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
