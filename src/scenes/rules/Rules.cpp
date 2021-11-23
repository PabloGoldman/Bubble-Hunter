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
