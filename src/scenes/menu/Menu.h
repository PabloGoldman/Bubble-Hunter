#pragma once
#include "../../general/button/Button.h"
#include "../SceneManager.h"
#include "../../general/audiomanager/AudioManager.h"

enum class MenuScene { PLAY, OPTIONS, CREDITS, EXIT, MENUOPTION };

const int totalButtons = 4;

class Menu
{
private:

	MenuScene menuScene;
	AudioManager* audioManager;
	SceneManager* sceneManager;
	Button* _button[totalButtons];
	sf::Image* logo;

	void Input(sf::RenderWindow* window);
	void Update();
	void Draw(sf::RenderWindow* window);
	void SetMenuOption();
	void CheckInput(sf::Event& event);
	void CheckOptionState(sf::Event& event);
	void SetButtonsData(Button _button[], int posX, int posY, int height, int width);
	void DrawButton(Button _button[], const char text[], sf::RenderWindow* window);
	void SetButtonsToFalse();
	void LoadTextures();
	void UnloadTextures();
	void DrawLogo();

public:
	Menu();
	~Menu();
	void InMenu(sf::RenderWindow* window);
	void InitMenuData();
	void SetSceneManager(SceneManager* sm);
	void SetAudioManager(AudioManager* am);
};

