#pragma once
#include "../SceneManager.h"

#include "SFML/Graphics.hpp"

class Credits
{
private:
	SceneManager* scene;
	sf::Text title;
	sf::Text programmer1;
	sf::Text programmer2;
	sf::RectangleShape background;

	bool inited = false;

public:

	void InitCredits();
	void InCredits(sf::RenderWindow* window);
	void DrawCredits(sf::RenderWindow* window);
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput(sf::RenderWindow* window);
};

