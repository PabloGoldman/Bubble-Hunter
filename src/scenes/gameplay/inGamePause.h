#pragma once
#include "../SceneManager.h"
#include "../../general/button/Button.h"	


enum class OPTION { RESUME, QUIT };

class InGamePause
{
private:
	OPTION option;

	SceneManager* sceneManager;
	Button* resume;
	Button* quit;

	bool inPause;

	void CheckInput(sf::Event& event);
	void DrawPauseMenu(sf::RenderWindow* window);
	void Update();

public:
	InGamePause();
	~InGamePause();

	OPTION GetMenuOption();

	bool GetInPause();

	void SetInPause(bool _inPause);
	void SetSceneManager(SceneManager* sc);
	void InPause(sf::RenderWindow* window, sf::Event& event);
	void SetMenuOption(OPTION _option);
	void SetButtonsData();
	void InitInPauseData();
	void Input(sf::RenderWindow* window, sf::Event& event);
	void DrawButton(Button _button[], const char text[], sf::RenderWindow* window);
};

