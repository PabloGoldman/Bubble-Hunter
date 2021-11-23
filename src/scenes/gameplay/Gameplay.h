#pragma once
#include "SFML/Window.hpp"
#include <SFML\Graphics\RenderWindow.hpp>

#include "Player.h"
#include "../../general/hud/HUD.h"
#include "inGamePause.h"
#include "../endscreen/EndGameScreen.h"
#include "../../general/audiomanager/AudioManager.h"


class Gameplay
{
private:
	EndGameScreen* endGameScreen;
	AudioManager* audioManager;
	SceneManager* scene;
	InGamePause* pause;
	HUD* hud;
	Player* player;

	bool inPause;

	void Input();
	void Update();
	void Draw(sf::RenderWindow* window);
	void SetPlayerData(Player* player, int posX, int posY);
	void SetPlayerPosition(Player* player, int posX, int posY);
	void DrawPlayer(Player* player, sf::RenderWindow* window);
	void DrawPlayerPoints(Player* player, int x, int y, sf::RenderWindow* window);
	void ResetPlayerData(Player* player);
	void ResetData(Player* player);

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

};

