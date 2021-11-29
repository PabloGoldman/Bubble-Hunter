#include "Gameplay.h"
#include <iostream>
#include <string>

#include "general/externs/Externs.h"

#include <SFML\Window\Window.hpp>
#include <SFML\Window\Keyboard.hpp>

const int screenWidth = 800;
const int screenHeight = 450;
const int fontSize = 40;
const int pointsToWin = 10;

const int totalBalls = 7;

const int bigBalls = 1;
const int mediumBalls = 2;
const int smallBalls = 4;

float initialSpeed = 0.04;

int pointsAux = 0;

float multiplier = 2;

//const int totalArrows = 2;

using namespace sf;

Gameplay::Gameplay()
{

	for (int i = 0; i < 2; i++)
	{
		arrow[i] = new Arrow();
	}

	player = new Player(arrow);

	ball = new Ball(BallSize::BIG, player);
	ball->SetArrows(arrow[0], arrow[1]);

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i] = new Ball(BallSize::MEDIUM, player);
		mediumBall[i]->SetActive(false);
		mediumBall[i]->SetArrows(arrow[0], arrow[1]);
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i] = new Ball(BallSize::SMALL, player);
		smallBall[i]->SetActive(false);
		smallBall[i]->SetArrows(arrow[0], arrow[1]);
	}

	hud = new HUD();
	pause = new InGamePause();

	inPause = false;
}

Gameplay::~Gameplay()
{
	delete player;
	delete hud;
	delete pause;

	for (int i = 0; i < totalArrows; i++)
	{
		delete arrow[i];
	}

	delete ball;

	for (int i = 0; i < mediumBalls; i++)
	{
		delete mediumBall[i];
	}

	for (int i = 0; i < smallBalls; i++)
	{
		delete smallBall[i];
	}
}

void Gameplay::InGame(sf::RenderWindow* window)
{
	Input(window);

	if (!pause->GetInPause())
	{
		Update();
	}
	else
	{
		pause->InPause(window);
		if (scene->GetScene() == Scene::MENU)
		{
			ResetData(player);
		}
	}
	audioManager->PlayGameMusic();
	Draw(window);
}

bool Gameplay::GetInPause()
{
	return inPause;
}

void Gameplay::SetInPause(bool pause)
{
	inPause = pause;
}

void Gameplay::Input(sf::RenderWindow* window)
{
	sf::Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			CheckPause();
			if (!pause->GetInPause())
			{
				player->Input(window);
			}
		}
	}
}

void Gameplay::Update()
{
	CheckWinGame();
	Collision();
	SpawnBalls();

	ball->Move();

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i]->Move();
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i]->Move();
	}

	player->Update();

	for (int i = 0; i < 2; i++)
	{
		arrow[i]->Update();
	}
}

void Gameplay::Draw(sf::RenderWindow* window)
{
	DrawPlayer(player, window);

	ball->Draw(window);

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i]->Draw(window);
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i]->Draw(window);
	}

	for (int i = 0; i < 2; i++)
	{
		arrow[i]->Draw(window);
	}

	DrawPlayerPoints(player, screenWidth / 2 - 15, 50, window);
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::DrawPlayerPoints(Player* player, int x, int y, sf::RenderWindow* window)
{
	hud->DrawPoints(player->GetPoints(), x, y, fontSize, sf::Color::White, window);
}


void Gameplay::ResetData(Player* player)
{
	ResetPlayerData(player);
}

void Gameplay::CheckPause()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		pause->SetInPause(!pause->GetInPause());
	}
}

void Gameplay::ResetPlayerData(Player* player)
{
	player->SetPoints(0);
	player->SetHeight(100);
}

void Gameplay::InitGameplay()
{
	SetPlayerData(player, screenWidth / 2 - 70, screenHeight - player->GetRectangle().getSize().y);

	SetInGamePauseData();

	pause->SetSceneManager(scene);
}

void Gameplay::Collision()
{
	ball->Collision();

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i]->Collision();
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i]->Collision();
	}

	CheckPlayerBallCollision();
	ChangeBallsDirection();
}

void Gameplay::CheckPlayerBallCollision()
{
	if (ball->GetShape().getGlobalBounds().intersects(player->GetRectangle().getGlobalBounds()) 
		&& ball->IsActive())
	{
		ResetGameplay();
	}

	for (int i = 0; i < mediumBalls; i++)
	{
		if(mediumBall[i]->GetShape().getGlobalBounds().intersects(player->GetRectangle().getGlobalBounds()) 
			&& mediumBall[i]->IsActive())
		{
			ResetGameplay();
		}
	}

	for (int i = 0; i < smallBalls; i++)
	{
		if (smallBall[i]->GetShape().getGlobalBounds().intersects(player->GetRectangle().getGlobalBounds()) 
			&& smallBall[i]->IsActive())
		{
			ResetGameplay();
		}
	}
	
}

void Gameplay::ResetGameplay()
{
	player->SetPoints(0);
	pointsAux = 0;
	ResetBallsData();
	RespawnBalls();
	scene->SetSceneManager(Scene::ENDGAME);
}

void Gameplay::ChangeBallsDirection()
{
	if (mediumBall[0]->GetSpeed() > 0 && mediumBall[0]->IsActive())
	{
		mediumBall[1]->ChangeSpeedDirection();
	}

	if (smallBall[0]->GetSpeed() > 0 && smallBall[0]->IsActive())
	{
		smallBall[1]->ChangeSpeedDirection();
	}

	if (smallBall[2]->GetSpeed() > 0 && smallBall[2]->IsActive())
	{
		smallBall[3]->ChangeSpeedDirection();
	}

}

void Gameplay::CheckWinGame()
{
	if (player->GetPoints() > pointsAux)
	{
		if (player->GetPoints() % totalBalls == 0)
		{
			pointsAux = player->GetPoints();
			AddBallsSpeed();
			RespawnBalls();
		}
	}
}

void Gameplay::RespawnBalls()
{
	ball->SetActive(true);
	ball->SetIfCollided(false);
	ball->SetPosition(sf::Vector2f(ExternVars::window.x / 2 - 20, ExternVars::window.y / 2));

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i]->SetActive(false);
		mediumBall[i]->SetIfCollided(false);
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i]->SetActive(false);
		smallBall[i]->SetIfCollided(false);
	}
}

void Gameplay::AddBallsSpeed()
{
	ball->SetSpeed(ball->GetSpeed() * multiplier);

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i]->SetSpeed(mediumBall[i]->GetSpeed() * multiplier);
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i]->SetSpeed(smallBall[i]->GetSpeed() * multiplier);
	}
}

void Gameplay::ResetBallsData()
{
	ball->SetSpeed(initialSpeed);

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i]->SetSpeed(initialSpeed);
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i]->SetSpeed(initialSpeed);
	}
}

void Gameplay::SpawnBalls()
{
	if (ball->GetIfCollided())
	{
		for (int i = 0; i < mediumBalls; i++)
		{
			if (!mediumBall[i]->IsActive() && !mediumBall[i]->GetIfCollided()) 
			{
				mediumBall[i]->SetPosition({ ball->GetPosition() });
				mediumBall[i]->SetActive(true);
			}
		}
	}
	//Spawneo de las bolas chiquitas

	//Si despawnea la primera medium ball
	MediumBallCollision(0);

	//Si despawnea la segunda medium ball
	MediumBallCollision(1);

}

void Gameplay::MediumBallCollision(int ball)
{
	if (mediumBall[ball]->GetIfCollided()) //Si colisiona la medium ball
	{
		for (int i = ball * 2; i < (ball + 1) * 2; i++)
		{
			if (!smallBall[i]->IsActive() && !smallBall[i]->GetIfCollided())
			{
				smallBall[i]->SetPosition({ mediumBall[ball]->GetPosition() });
				smallBall[i]->SetActive(true);

				if (i == ball * 2)
				{
					smallBall[i]->ChangeSpeedDirection();
				}
			}
		}
	}
	
}

void Gameplay::SetEndGameScreen(EndGameScreen* eg)
{
	endGameScreen = eg;
}

void Gameplay::SetInGamePauseData()
{
	pause->InitInPauseData();
	pause->SetSceneManager(scene);
}

void Gameplay::SetAudioManager(AudioManager* am)
{
	audioManager = am;
}

void Gameplay::SetPlayerData(Player* player, int posX, int posY)
{
	SetPlayerPosition(player, posX, posY);
}

void Gameplay::SetPlayerPosition(Player* player, int posX, int posY)
{
	player->SetRectanglePos(posX, posY);
}

void Gameplay::DrawPlayer(Player* player, sf::RenderWindow* window)
{
	window->draw(player->GetRectangle());
}


