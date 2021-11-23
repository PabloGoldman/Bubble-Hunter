#include "Gameplay.h"
#include <iostream>
#include <string>

#include <SFML\Window\Window.hpp>
#include <SFML\Window\Keyboard.hpp>

const int screenWidth = 800;
const int screenHeight = 450;
const int fontSize = 40;
const int pointsToWin = 10;

using namespace sf;

Gameplay::Gameplay()
{
	player = new Player();
	hud = new HUD();
	pause = new InGamePause();

	inPause = false;
}

Gameplay::~Gameplay()
{
	delete player;
	delete hud;
	delete pause;
}

void Gameplay::InGame(sf::RenderWindow* window)
{
	Input();
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

void Gameplay::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		pause->SetInPause(!pause->GetInPause());
	}
}

void Gameplay::Update()
{

}

void Gameplay::Draw(sf::RenderWindow* window)
{
	DrawPlayer(player, window);

	DrawPlayerPoints(player, 300, 50, window);
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::DrawPlayerPoints(Player* player, int x, int y, sf::RenderWindow* window)
{
	//hud->DrawPoints(player->GetPoints(), x, y, fontSize, sf::Color::Black, window);
}


void Gameplay::ResetData(Player* player)
{
	ResetPlayerData(player);
}

void Gameplay::ResetPlayerData(Player* player)
{
	player->SetPoints(0);
	player->SetHeight(100);
}

void Gameplay::InitGameplay()
{
	SetPlayerData(player, 0, screenHeight / 2);

	SetInGamePauseData();

	pause->SetSceneManager(scene);
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
	
}


