#pragma once
#include "../../general/button/Button.h"
#include "../SceneManager.h"

#include "SFML/Graphics.hpp"

enum class ENDGAMEOPTION { PLAY, QUIT };

class EndGameScreen
{
private:
	ENDGAMEOPTION option;

	SceneManager* sceneManager;

	Button* gameFinished;
	Button* replay;
	Button* quit;


	void CheckInput();
	void DrawEndGameScreen(sf::RenderWindow* window);
	void Update();

public:
	EndGameScreen();
	~EndGameScreen();

	ENDGAMEOPTION GetOption();

	bool player1Win;

	void SetWinPlayer(bool player1);
	void SetOption(ENDGAMEOPTION _option);
	void SetSceneManager(SceneManager* sc);
	void SetButtonsData();
	void InitEndGameScreenData();
	void InEndGameScreen(sf::RenderWindow* window);
};
