#include "Gameplay.h"
#include <iostream>
#include <string>

#include <SFML\Window\Window.hpp>
#include <SFML\Window\Keyboard.hpp>

const int screenWidth = 800;
const int screenHeight = 450;
const int fontSize = 40;
const int pointsToWin = 10;

const int bigBalls = 1;
const int mediumBalls = 2;
const int smallBalls = 4;

//const int totalArrows = 2;

using namespace sf;

Gameplay::Gameplay()
{
	for (int i = 0; i < 2; i++)
	{
		arrow[i] = new Arrow();
	}

	player = new Player(arrow);

	ball = new Ball(BallSize::BIG);
	ball->SetArrows(arrow[0], arrow[1]);

	for (int i = 0; i < mediumBalls; i++)
	{
		mediumBall[i] = new Ball(BallSize::MEDIUM);
		mediumBall[i]->SetActive(false);
		mediumBall[i]->SetArrows(arrow[0], arrow[1]);
	}

	for (int i = 0; i < smallBalls; i++)
	{
		smallBall[i] = new Ball(BallSize::SMALL);
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
			player->Input(window);
		}
	}
}

void Gameplay::Update()
{
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

	DrawPlayerPoints(player, 300, 50, window);
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
	SetPlayerData(player, screenWidth / 2 - 70, screenHeight / 2 + 100);

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
}

void Gameplay::SpawnBalls()
{
	//Hace que aparezcan a los costados de la flecha, pero que no la choquen

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


