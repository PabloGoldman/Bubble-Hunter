#include "Ball.h"
#include "general/externs/Externs.h"

void Ball::RandomizeMovement()
{
	goingToRight = rand() % 2 == 1 ? true : false;
	goingUp = rand() % 2 == 0 ? true : false;
}

Ball::Ball(BallSize size, Player* player)
{   
	int rad = 0;

	this->player = player;

	switch (size)
	{
	case BallSize::BIG:
		rad = 10;
		break;
	case BallSize::MEDIUM:
		rad = 5;
		break;
	case BallSize::SMALL:
		rad = 2;
		break;
	default:
		break;
	}


	active = true;   
	alreadyCollided = false;
						   
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

void Ball::SetArrows(Arrow* arr1, Arrow* arr2)
{
	arrow[0] = arr1;
	arrow[1] = arr2;
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

bool Ball::GetIfCollided()
{
	return alreadyCollided;
}

sf::CircleShape Ball::GetShape()
{
	return shape;
}

void Ball::Move()
{
	if (active)
	{
		MoveInXAxis();
		MoveInYAxis();
	}
}

void Ball::Draw(sf::RenderWindow* window)
{
	if (active)
	{
		window->draw(shape);
	}
}

void Ball::Collision()
{
	for (int i = 0; i < 2; i++)
	{
		if (shape.getGlobalBounds().intersects(arrow[i]->GetRectangle().getGlobalBounds()))
		{
			if (active)
			{
				arrow[i]->SetActive(false);
				active = false;
				alreadyCollided = true;
				player->SetPoints(player->GetPoints() + 1);
			}
		}
	}
}

void Ball::ChangeSpeedDirection()
{
	VELOCITY.x *= -1;
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