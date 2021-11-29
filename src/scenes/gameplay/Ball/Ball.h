#ifndef BALL_H
#define BALL_H

#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#include "../Arrow.h"
#include "scenes/gameplay/Player.h"

const float MAX_HEIGHT_GREAT_BALL = 100;
const float MAX_HEIGHT_MEDIUM_BALL = 80;
const float MAX_HEIGHT_MINOR_BALL = 60;

enum class BallSize
{
	BIG,
	MEDIUM,
	SMALL
};

class Ball
{
private:
	sf::CircleShape shape;

	Player* player;

	Arrow* arrow[2];

	BallSize size;

	sf::Vector2f VELOCITY = sf::Vector2f(0.04f, 0.08f);

	bool active;
	void MoveInXAxis();
	void MoveInYAxis();

	bool goingToRight;
	bool goingUp;

	bool alreadyCollided;

	void RandomizeMovement();



public:
	Ball(BallSize size, Player* player);
	~Ball();

	void SetPosition(sf::Vector2f p);
	void SetRadius(float r);
	void SetActive(bool a);
	void SetSize(BallSize bs);

	void SetArrows(Arrow* arr1, Arrow* arr2);

	sf::Vector2f GetPosition();
	float GetRadius();
	bool IsActive();
	BallSize GetBallSize();
	bool GetIfCollided();
	sf::CircleShape GetShape();
	float GetSpeed();


	void Move();
	void Draw(sf::RenderWindow* window);
	void Collision();
	void ChangeSpeedDirection();
	void SetIfCollided(bool col);
	void SetSpeed(float speed);

};




#endif // !BALL_H
