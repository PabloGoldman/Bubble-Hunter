#pragma once
#include "SFML/Window.hpp"
#include <SFML\Graphics\RenderWindow.hpp>

#include "Player.h"
#include "../../general/hud/HUD.h"
#include "inGamePause.h"
#include "../endscreen/EndGameScreen.h"
#include "../../general/audiomanager/AudioManager.h"

#include "Ball/Ball.h"
#include "../Arrow.h"


class Gameplay
{
private:
	EndGameScreen* endGameScreen;
	AudioManager* audioManager;
	SceneManager* scene;
	InGamePause* pause;
	HUD* hud;
	Player* player;


	Ball* ball;
	Ball* mediumBall[2];
	Ball* smallBall[4];

	Arrow* arrow[2];

	bool inPause;

	void Input(sf::RenderWindow* window);
	void Update();
	void Draw(sf::RenderWindow* window);
	void SetPlayerData(Player* player, int posX, int posY);
	void SetPlayerPosition(Player* player, int posX, int posY);
	void DrawPlayer(Player* player, sf::RenderWindow* window);
	void DrawPlayerPoints(Player* player, int x, int y, sf::RenderWindow* window);
	void ResetPlayerData(Player* player);
	void ResetData(Player* player);

	void CheckPause();

public:
	Gameplay();
	~Gameplay();

	bool GetInPause();

	void SetInPause(bool pause);

	void SetEndGameScreen(EndGameScreen* eg);
	void SetInGamePauseData();
	void SetAudioManager(AudioManager* am);
	void SetSceneManager(SceneManager* sc);
	void InGame(sf::RenderWindow* window);
	void InitGameplay();

	void Collision();
	void SpawnBalls();

	void MediumBallCollision(int ball);
	void CheckPlayerBallCollision();

	void ResetGameplay();


	//bool Intersects(Arrow* rec, Ball* circle);

};

