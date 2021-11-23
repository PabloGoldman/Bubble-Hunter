#include "InGamePause.h"
#include <SFML\Window\Keyboard.hpp>

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

using namespace sf;

InGamePause::InGamePause()
{
	resume = new Button();
	quit = new Button();
}

InGamePause::~InGamePause()
{
	delete resume;
	delete quit;
}

OPTION InGamePause::GetMenuOption()
{
	return option;
}

bool InGamePause::GetInPause()
{
	return inPause;
}

void InGamePause::SetInPause(bool _inPause)
{
	inPause = _inPause;
}

void InGamePause::SetSceneManager(SceneManager* sc)
{
	sceneManager = sc;
}

void InGamePause::InPause(sf::RenderWindow* window)
{
	CheckInput();
	Update();
	DrawPauseMenu(window);
}

void InGamePause::SetMenuOption(OPTION _option)
{
	option = _option;
}

void InGamePause::CheckInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (option == OPTION::RESUME)
			option = OPTION::QUIT;
		else
			option = OPTION::RESUME;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (option == OPTION::RESUME)
			SetInPause(false);
		else
		{
			SetInPause(false);
			SetMenuOption(OPTION::RESUME);
			sceneManager->SetSceneManager(Scene::MENU);
		}
	}
}

void InGamePause::DrawPauseMenu(sf::RenderWindow* window)
{
	sf::Font font;

	sf::RectangleShape rec;
	rec.setPosition(sf::Vector2f(screenWidth / 2 - 250, screenHeight / 2 - 100));
	rec.setSize(sf::Vector2f(500, 300));
	rec.setFillColor(sf::Color::Blue);
	window->draw(rec);

	//DrawRectangle(screenWidth / 2 - 250, screenHeight / 2 - 100, 500, 300, sf::Color::Blue);
	resume->DrawButton(resume->GetRectangle(), "RESUME", window);
	quit->DrawButton(resume->GetRectangle(), "QUIT", window);
}

void InGamePause::Update()
{
	switch (option)
	{
	case OPTION::RESUME:
		resume->SetActive(true);
		quit->SetActive(false);
		break;
	case OPTION::QUIT:
		resume->SetActive(false);
		quit->SetActive(true);
		break;
	default:
		break;
	}
}

void InGamePause::SetButtonsData()
{
	resume->SetRectanglePos(screenWidth / 2 - 80, screenHeight / 2 - 10);
	quit->SetRectanglePos(screenWidth / 2 - 80, screenHeight / 2 + 50);

	quit->SetHeight(400);
	quit->SetWidth(400);

	resume->SetHeight(400);
	resume->SetWidth(400);
}

void InGamePause::InitInPauseData()
{
	SetButtonsData();
}
