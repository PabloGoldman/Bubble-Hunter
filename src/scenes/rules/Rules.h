#pragma once
#include "../SceneManager.h"
#include "SFML/Graphics.hpp"

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

