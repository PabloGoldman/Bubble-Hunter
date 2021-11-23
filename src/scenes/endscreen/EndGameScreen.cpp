#include "EndGameScreen.h"
#include <SFML\Window\Keyboard.hpp>

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

using namespace sf;

EndGameScreen::EndGameScreen()
{
	gameFinished = new Button();
	replay = new Button();
	quit = new Button();

	player1Win = false;
}

EndGameScreen::~EndGameScreen()
{
	delete replay;
	delete quit;
	delete gameFinished;
}

ENDGAMEOPTION EndGameScreen::GetOption()
{
	return option;
}

void EndGameScreen::InEndGameScreen(sf::RenderWindow* window)
{
	CheckInput();
	Update();
	DrawEndGameScreen(window);
}

void EndGameScreen::SetOption(ENDGAMEOPTION _option)
{
	option = _option;
}

void EndGameScreen::CheckInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (option == ENDGAMEOPTION::PLAY)
			option = ENDGAMEOPTION::QUIT;
		else
			option = ENDGAMEOPTION::PLAY;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if (option == ENDGAMEOPTION::PLAY)
			sceneManager->SetSceneManager(Scene::GAME);

		else
			sceneManager->SetSceneManager(Scene::MENU);
	}
}

void EndGameScreen::DrawEndGameScreen(sf::RenderWindow* window)
{
	sf::Font font;

	sf::RectangleShape rec;
	rec.setPosition(sf::Vector2f(screenWidth / 2 - 220, 20));
	rec.setSize(sf::Vector2f(500, 400));
	rec.setFillColor(sf::Color::Blue);
	window->draw(rec);

	//DrawRectangle(screenWidth / 2 - 220, 20, 500, 400, sf::Color::Blue); //Fondo

	if (player1Win)
		gameFinished->DrawButton(gameFinished->GetRectangle(), "PLAYER 1 WINS", window);
	else
		gameFinished->DrawButton(gameFinished->GetRectangle(), "PLAYER 2 WINS", window);


	replay->DrawButton(replay->GetRectangle(), "PLAY AGAIN", window);
	quit->DrawButton(quit->GetRectangle(), "QUIT", window);
}

void EndGameScreen::Update()
{
	switch (option)
	{
	case ENDGAMEOPTION::PLAY:
		replay->SetActive(true);
		quit->SetActive(false);
		break;
	case ENDGAMEOPTION::QUIT:
		replay->SetActive(false);
		quit->SetActive(true);
		break;
	default:
		break;
	}
}

void EndGameScreen::SetButtonsData()
{
	gameFinished->SetRectanglePos(screenWidth / 2 - 160, 50);
	replay->SetRectanglePos(screenWidth / 2 - 100, screenHeight / 2 - 50);
	quit->SetRectanglePos(screenWidth / 2 - 100, screenHeight / 2 + 50);

	gameFinished->SetHeight(400);
	gameFinished->SetWidth(700);

	replay->SetHeight(400);
	replay->SetWidth(700);

	quit->SetHeight(400);
	quit->SetWidth(400);
}

void EndGameScreen::SetWinPlayer(bool player1)
{
	player1Win = player1;
}

void EndGameScreen::SetSceneManager(SceneManager* sc)
{
	sceneManager = sc;
}

void EndGameScreen::InitEndGameScreenData()
{
	SetButtonsData();
}
