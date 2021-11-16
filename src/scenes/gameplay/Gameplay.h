#pragma once
#include "Player.h"
#include "../../general/hud/HUD.h"
#include "inGamePause.h"
#include "../SceneManager.h"
#include "../endscreen/EndGameScreen.h"
#include "../../general/audiomanager/AudioManager.h"

#include "SFML/Window.hpp"
#include <SFML\Graphics\RenderWindow.hpp>

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
	void Draw();
	void SetPlayerData(Player* player, int posX, int posY);
	void SetPlayerPosition(Player* player, int posX, int posY);
	void DrawPlayer(Player* player);
	void DrawPlayerPoints(Player* player, int x, int y);
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
	void InGame();
	void InitGameplay();

};

