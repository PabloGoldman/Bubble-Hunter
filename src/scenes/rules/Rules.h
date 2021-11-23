#pragma once
#include "SFML/Graphics.hpp"
#include "../SceneManager.h"

class Rules
{
private:
	SceneManager* scene;
public:

	void InRules(sf::RenderWindow* window);
	void DrawRules(sf::RenderWindow* rw);
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput();
};

