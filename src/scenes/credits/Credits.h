#pragma once
#include "../SceneManager.h"

#include "SFML/Graphics.hpp"

class Credits
{
private:
	SceneManager* scene;
public:

	void InCredits(sf::RenderWindow* window);
	void DrawCredits(sf::RenderWindow* window);
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput();
};

