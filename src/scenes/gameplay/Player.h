#pragma once
#include <SFML/Graphics.hpp>
#include "../Arrow.h"

const int totalArrows = 2;

class Player
{
private:
	Arrow* arrow[2];

	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape rectangle;
	sf::Color color;
	int speed;
	int points;

	bool hasPowerUp;

public:
	Player(Arrow* arr[totalArrows]);
	~Player();

	sf::RectangleShape GetRectangle();
	sf::Color GetColor();

	int GetSpeed();
	int GetPoints();

	void Input(sf::RenderWindow* window);

	void Update();
	void SetSpeed(int _speed);
	void SetColor(sf::Color _color);
	void SetWidth(int _width);
	void SetHeight(int _height);
	void SetPoints(int _points);
	void SetRectanglePos(int posX, int posY);
	void AddPoints(int _points);
	sf::Sprite GetSprite();
};


