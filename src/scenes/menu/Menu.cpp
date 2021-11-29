#include "Menu.h"
#include "SFML/Window/Keyboard.hpp"

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

int rectangleWidth = 250;
int rectangleHeight = 250;

int txtSize = 50;

int PlayButtonPosition = 50;
int OptionsButtonPosition = 150;
int CreditsButtonPosition = 250;
int ExitButtonPosition = 350;

int optionButtonHeight = 20;
int optionButtonWidth = 20;

Menu::Menu()
{
	menuScene = MenuScene::PLAY;

	logo = new sf::Image();

	for (int i = 0; i < totalButtons; i++)
		_button[i] = new Button();
}

Menu::~Menu()
{
	for (int i = 0; i < totalButtons; i++)
		delete _button[i];
	UnloadTextures();
}

void Menu::SetAudioManager(AudioManager* am)
{
	audioManager = am;
}

void Menu::SetSceneManager(SceneManager* sm)
{
	sceneManager = sm;
}

void Menu::InMenu(sf::RenderWindow* window)
{
	Input(window);
	Update();
	Draw(window);
}

void Menu::Input(sf::RenderWindow* window)
{
	sf::Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed) 
		{
			Menu::CheckInput(event);
			Menu::CheckOptionState(event);
		}
	}
	
}

void Menu::Update()
{
	audioManager->PlayMenuMusic();
	Menu::SetMenuOption();
}

void Menu::Draw(sf::RenderWindow* window)
{
	DrawButton(_button[0], "PLAY", window);
	DrawButton(_button[1], "CONTROLS", window);
	DrawButton(_button[2], "CREDITS", window);
	DrawButton(_button[3], "EXIT", window);

	DrawLogo();
}

void Menu::InitMenuData()
{
	LoadTextures();

	SetButtonsData(_button[0], screenWidth * 0.5 - 100, PlayButtonPosition, 65, 300);
	SetButtonsData(_button[1], screenWidth * 0.5 - 100, OptionsButtonPosition, 65, 300);
	SetButtonsData(_button[2], screenWidth * 0.5 - 100, CreditsButtonPosition, 65, 300);
	SetButtonsData(_button[3], screenWidth * 0.5 - 100, ExitButtonPosition, 65, 300);
	_button[1]->SetColor(sf::Color::Red);
}

void Menu::DrawLogo()
{
	//DrawTextureEx(logo, { screenWidth - 200,screenHeight - 170 }, 0, 0.4, sf::Color::White);
}

void Menu::SetButtonsData(Button _button[], int posX, int posY, int height, int width)
{
	_button->SetRectanglePos(posX, posY);

	_button->SetHeight(height);
	_button->SetWidth(width);
}

void Menu::LoadTextures()
{
	if(logo)
		logo->loadFromFile("res/assets/logo.png");
}

void Menu::UnloadTextures()
{
	if (logo)
	{
		delete logo;
		logo = nullptr;
	}
}

void Menu::DrawButton(Button _button[], const char text[], sf::RenderWindow* window)
{
	_button->DrawButton(_button->GetRectangle(), text, window);
}

void Menu::CheckOptionState(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "APRETASTE FLECHITA ABAJO\n";
		switch (menuScene)
		{
		case MenuScene::PLAY:
			std::cout << "ESTAS EN PLAY\n";
			menuScene = MenuScene::OPTIONS;
			break;
		case MenuScene::OPTIONS:
			std::cout << "ESTAS EN OPTIONS\n";
			menuScene = MenuScene::CREDITS;
			break;
		case MenuScene::CREDITS:
			std::cout << "ESTAS EN CREDITS\n";
			menuScene = MenuScene::EXIT;
			break;
		case MenuScene::EXIT:
			std::cout << "ESTAS EN EXIT\n";
			menuScene = MenuScene::PLAY;
			break;
		default:
			break;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		std::cout << "APRETASTE FLECHITA ARRIBA\n";
		switch (menuScene)
		{
		case MenuScene::PLAY:
			menuScene = MenuScene::EXIT;
			std::cout << "ESTAS EN PLAY\n";
			break;
		case MenuScene::OPTIONS:
			std::cout << "ESTAS EN OCIO\n";
			menuScene = MenuScene::PLAY;
			break;
		case MenuScene::CREDITS:
			std::cout << "ESTAS EN CREDS\n";
			menuScene = MenuScene::OPTIONS;
			break;
		case MenuScene::EXIT:
			std::cout << "ESTAS EN EXIT\n";
			menuScene = MenuScene::CREDITS;
			break;
		default:
			break;
		}
	}
}

void Menu::CheckInput(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		std::cout << "APRETASTE ENTER\n";
		switch (menuScene)
		{
		case MenuScene::PLAY:
			sceneManager->SetSceneManager(Scene::GAME);
			break;
		case MenuScene::OPTIONS:
			sceneManager->SetSceneManager(Scene::RULES);
			break;
		case MenuScene::CREDITS:
			sceneManager->SetSceneManager(Scene::CREDITS);
			break;
		case MenuScene::EXIT:
			sceneManager->SetSceneManager(Scene::EXIT);
			break;
		default:
			break;
		}
		audioManager->PlayOptionSound();
	}
}

void Menu::SetMenuOption()
{
	switch (menuScene)
	{
	case MenuScene::PLAY:
		_button[(int)MenuScene::PLAY]->SetActive(true);
		break;
	case MenuScene::OPTIONS:
		_button[(int)MenuScene::OPTIONS]->SetActive(true);
		break;
	case MenuScene::CREDITS:
		_button[(int)MenuScene::CREDITS]->SetActive(true);
		break;
	case MenuScene::EXIT:
		_button[(int)MenuScene::EXIT]->SetActive(true);
		break;
	default:
		break;
	}
	SetButtonsToFalse();
}

void Menu::SetButtonsToFalse()
{
	for (int i = 0; i < totalButtons; i++)
	{
		if (i != (int)menuScene)
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

