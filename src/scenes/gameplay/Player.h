#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	Rectangle rectangle;
	sf::Color color;
	int speed;
	int points;

public:
	Player();
	~Player();

	Rectangle GetRectangle();
	sf::Color GetColor();

	int GetSpeed();
	int GetPoints();

	void SetSpeed(int _speed);
	void SetColor(sf::Color _color);
	void SetWidth(int _width);
	void SetHeight(int _height);
	void SetPoints(int _points);
	void SetRectanglePos(int posX, int posY);
	void AddPoints(int _points);
};


