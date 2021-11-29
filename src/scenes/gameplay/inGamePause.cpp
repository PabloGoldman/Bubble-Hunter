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

void InGamePause::InPause(sf::RenderWindow* window, sf::Event& event)
{
	Input(window, event);
	Update();
	DrawPauseMenu(window);
}

void InGamePause::SetMenuOption(OPTION _option)
{
	option = _option;
}

void InGamePause::CheckInput(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		switch (option)
		{
		case OPTION::RESUME:
			option = OPTION::QUIT;
			break;
		case OPTION::QUIT:
			option = OPTION::RESUME;
			break;
		default:
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		switch (option)
		{
		case OPTION::RESUME:
			sceneManager->SetSceneManager(Scene::GAME);
			break;
		case OPTION::QUIT:
			sceneManager->SetSceneManager(Scene::MENU);
			break;
		default:
			break;
		}
	}
}

void InGamePause::DrawPauseMenu(sf::RenderWindow* window)
{
	DrawButton(resume, "PLAY AGAIN", window);
	DrawButton(quit, "EXIT", window);
}

void InGamePause::Update()
{
	switch (option)
	{
	case OPTION::RESUME:
		resume->SetActive(true);
		break;
	case OPTION::QUIT:
		quit->SetActive(true);
		break;
	default:
		break;
	}

	for (int i = 0; i < 2; i++)
	{
		if (i != (int)option)
		{
			resume->SetActive(false);
			resume->SetColor(sf::Color::Red);
		}
		else
		{
			quit->SetActive(true);
			quit->SetColor(sf::Color::Blue);
		}
	}
}

void InGamePause::SetButtonsData()
{
	resume->SetRectanglePos(screenWidth / 2 - 120, screenHeight / 2 - 80);
	quit->SetRectanglePos(screenWidth / 2 - 120, screenHeight / 2 + 50);

	quit->SetHeight(65);
	quit->SetWidth(300);

	resume->SetHeight(65);
	resume->SetWidth(300);
}

void InGamePause::InitInPauseData()
{
	SetButtonsData();
}

void InGamePause::Input(sf::RenderWindow* window, sf::Event& event)
{
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			CheckInput(event);
		}
	}
}

void InGamePause::DrawButton(Button _button[], const char text[], sf::RenderWindow* window)
{
	_button->DrawButton(_button->GetRectangle(), text, window);
}


