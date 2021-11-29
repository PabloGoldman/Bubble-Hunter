#pragma once
#include "SFML/Graphics.hpp"
#include "../SceneManager.h"

const int RULE_TABS = 4;
const int ARROW_COUNT = 2;

class Rules
{
private:
	SceneManager* scene;
	sf::Text title;
	sf::Text arrow[ARROW_COUNT];
	sf::Text line1[RULE_TABS];
	sf::Text line2[RULE_TABS];
	sf::Text line3[RULE_TABS];
	sf::Text index;
	sf::RectangleShape background;

	int actualIndex;

	bool inited = false;

public:

	void InitRules();

	void InRules(sf::RenderWindow* window);
	void DrawRules(sf::RenderWindow* rw);
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput(sf::RenderWindow* window);
};

