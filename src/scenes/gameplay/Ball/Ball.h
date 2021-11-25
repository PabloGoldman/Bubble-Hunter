#ifndef BALL_H
#define BALL_H

#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

const float MAX_HEIGHT_GREAT_BALL = 100;
const float MAX_HEIGHT_MEDIUM_BALL = 80;
const float MAX_HEIGHT_MINOR_BALL = 60;

const sf::Vector2f VELOCITY = sf::Vector2f(0.04f, 0.08f);

enum class BallSize
{
	GREAT,
	MEDIUM,
	MINOR
};

class Ball
{
private:
	sf::CircleShape shape;

	BallSize size;

	bool active;
	void MoveInXAxis();
	void MoveInYAxis();

	bool goingToRight;
	bool goingUp;

	void RandomizeMovement();

public:
	Ball();
	~Ball();

	void SetPosition(sf::Vector2f p);
	void SetRadius(float r);
	void SetActive(bool a);
	void SetSize(BallSize bs);

	sf::Vector2f GetPosition();
	float GetRadius();
	bool IsActive();
	BallSize GetBallSize();

	void Move();
	void Draw(sf::RenderWindow* window);

};




#endif // !BALL_H
