#pragma once
#include "../scenes/menu/Menu.h"
#include "../scenes/SceneManager.h"
#include "../scenes/gameplay/Gameplay.h"
#include "../scenes/credits/Credits.h"
#include "../scenes/rules/Rules.h"
#include "../scenes/gameplay/inGamePause.h"
#include "../scenes/endscreen/EndGameScreen.h"
#include "../general/audiomanager/AudioManager.h"

class GameManager
{
private:
	int screenWidth;
	int screenHeight;
	int fontSize;

	AudioManager* _audioManager;
	EndGameScreen* _endGameScreen;
	Rules* _rules;
	Credits* _credits;
	SceneManager* _sceneManager;
	Menu* _menu;
	Gameplay* _gameplay;

	bool isPlaying;
	bool rulesInited;
	bool gameplayInited;
	bool menuInited;
	bool creditsInited;
	bool modeScreenInited;
	bool endGameScreenInited;

public:
	GameManager();
	~GameManager();

	void RunGame();
	void InitAllGameData();
	void InitAllMenuData();
	void InitAllCreditsData();
	//void InitAllChooseModeData();
	void InitAllRulesData();
	void InitAllEndGameScreenData();
	void PlayMusicInMenu();
};

