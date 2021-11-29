#include "EndGameScreen.h"
#include <SFML\Window\Keyboard.hpp>

#include "general/externs/Externs.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

using namespace sf;

EndGameScreen::EndGameScreen()
{
	for (int i = 0; i < 2; i++)
	{
		_button[i] = new Button();
	}
}

EndGameScreen::~EndGameScreen()
{
	for (int i = 0; i < 2; i++)
	{
		delete _button[i];
	}
}

ENDGAMEOPTION EndGameScreen::GetOption()
{
	return option;
}

void EndGameScreen::InEndGameScreen(sf::RenderWindow* window)
{
	Input(window);
	Update();
	DrawEndGameScreen(window);
}

void EndGameScreen::DrawButton(Button _button[], const char text[], sf::RenderWindow* window)
{
	_button->DrawButton(_button->GetRectangle(), text, window);
}

void EndGameScreen::Input(sf::RenderWindow* window)
{
	sf::Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			EndGameScreen::CheckInput(event);
		}
	}
}

void EndGameScreen::SetOption(ENDGAMEOPTION _option)
{
	option = _option;
}

void EndGameScreen::CheckInput(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		switch (option)
		{
		case ENDGAMEOPTION::PLAY:
			option = ENDGAMEOPTION::QUIT;
			break;
		case ENDGAMEOPTION::QUIT:
			option = ENDGAMEOPTION::PLAY;
			break;
		default:
			break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		switch (option)
		{
		case ENDGAMEOPTION::PLAY:
			sceneManager->SetSceneManager(Scene::GAME);
			break;
		case ENDGAMEOPTION::QUIT:
			option = ENDGAMEOPTION::PLAY;
			sceneManager->SetSceneManager(Scene::MENU);
			break;
		default:
			break;
		}
	}
}

void EndGameScreen::DrawEndGameScreen(sf::RenderWindow* window)
{
	DrawButton(_button[0], "PLAY AGAIN", window);
	DrawButton(_button[1], "EXIT", window);
}

void EndGameScreen::Update()
{
	switch (option)
	{
	case ENDGAMEOPTION::PLAY:
		_button[(int)ENDGAMEOPTION::PLAY]->SetActive(true);
		break;
	case ENDGAMEOPTION::QUIT:
		_button[(int)ENDGAMEOPTION::QUIT]->SetActive(true);
		break;
	}

	for (int i = 0; i < 2; i++)
	{
		if (i != (int)option)
		{
			_button[i]->SetActive(false);
			_button[i]->SetColor(sf::Color::Blue);
		}
		else
		{
			_button[i]->SetActive(true);
			_button[i]->SetColor(sf::Color::Red);
		}
	}
}

void EndGameScreen::SetButtonsData(Button _button[], int posX, int posY, int height, int width)
{
	_button->SetRectanglePos(posX, posY);

	_button->SetHeight(height);
	_button->SetWidth(width);
}

void EndGameScreen::SetPlayerPoints(int p)
{
	points = p;
}

void EndGameScreen::SetSceneManager(SceneManager* sc)
{
	sceneManager = sc;
}

void EndGameScreen::InitEndGameScreenData()
{
	SetButtonsData(_button[0],screenWidth / 2 - 120, screenHeight / 2 - 80, 65, 300);
	SetButtonsData(_button[1], screenWidth / 2 - 120, screenHeight / 2 + 50, 65, 300);
}
