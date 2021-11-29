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

	Button* _button[2];

	sf::RectangleShape background;


	void CheckInput(sf::Event& event);
	void DrawEndGameScreen(sf::RenderWindow* window);
	void Update();

public:
	EndGameScreen();
	~EndGameScreen();

	ENDGAMEOPTION GetOption();

	int points;

	void SetPlayerPoints(int points);
	void SetOption(ENDGAMEOPTION _option);
	void SetSceneManager(SceneManager* sc);
	void SetButtonsData(Button _button[], int posX, int posY, int height, int width);
	void InitEndGameScreenData();
	void InEndGameScreen(sf::RenderWindow* window);
	void DrawButton(Button _button[], const char text[], sf::RenderWindow* window);
	void Input(sf::RenderWindow* window);
};
