#include "Ball.h"
#include "general/externs/Externs.h"

void Ball::RandomizeMovement()
{
	goingToRight = rand() % 2 == 1 ? true : false;
	goingUp = rand() % 2 == 0 ? true : false;
}

Ball::Ball()
{          
	active = true;          
						   
	int rad = 10;
	shape = sf::CircleShape();
	shape.setRadius(rad);
	shape.setPosition(sf::Vector2f(ExternVars::window.x / 2, ExternVars::window.y / 2));

	goingToRight = true;    
	goingUp = true;         

	RandomizeMovement();

}

Ball::~Ball()
{
}

void Ball::SetPosition(sf::Vector2f p)
{
	shape.setPosition(p);
}

void Ball::SetRadius(float r)
{
	shape.setRadius(r);
}

void Ball::SetActive(bool a)
{
	active = a;
}

void Ball::SetSize(BallSize bs)
{
	size = bs;
}

sf::Vector2f Ball::GetPosition()
{
	return shape.getPosition();
}

float Ball::GetRadius()
{
	return shape.getRadius();
}

bool Ball::IsActive()
{
	return active;
}

BallSize Ball::GetBallSize()
{
	return size;
}

void Ball::Move()
{
	MoveInXAxis();
	MoveInYAxis();
}

void Ball::Draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

void Ball::MoveInXAxis()
{
	
	if (shape.getPosition().x > ExternVars::window.x - GetRadius()*2)
	{
		shape.setPosition(sf::Vector2f(ExternVars::window.x - GetRadius()*2,shape.getPosition().y));
		goingToRight = false;
	}
	
	if (shape.getPosition().x < 0)
	{
		shape.setPosition(sf::Vector2f(0, shape.getPosition().y));
		goingToRight = true;
	}
	
	if (goingToRight)
	{
		shape.setPosition(sf::Vector2f(shape.getPosition().x + VELOCITY.x, shape.getPosition().y));
	}
	else
	{
		shape.setPosition(sf::Vector2f(shape.getPosition().x - VELOCITY.x, shape.getPosition().y));
	}

}

void Ball::MoveInYAxis()
{
	if (shape.getPosition().y > ExternVars::window.y - GetRadius()*2)
	{
		shape.setPosition(sf::Vector2f(shape.getPosition().x, ExternVars::window.y - GetRadius()*2));
		goingUp = false;
	}
	if (shape.getPosition().y < 0)
	{
		shape.setPosition(sf::Vector2f(shape.getPosition().x, 0));
		goingUp = true;
	}

	if (goingUp)
	{
		shape.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y+ VELOCITY.y));
	}
	else
	{
		shape.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y- VELOCITY.y));
	}
}