#include "Player.h"

Player::Player()
{
	rectangle.width = 10;
	rectangle.height = 100;
	color = sf::Color::Black;
	speed = 300;
	points = 0;
}

Player::~Player()
{

}

Rectangle Player::GetRectangle()
{
	return rectangle;
}

sf::Color Player::GetColor()
{
	return color;
}

int Player::GetSpeed()
{
	return speed;
}

int Player::GetPoints()
{
	return points;
}

void Player::SetSpeed(int _speed)
{
	speed = _speed;
}

void Player::SetColor(sf::Color _color)
{
	color = _color;
}

void Player::SetWidth(int _width)
{
	rectangle.width = _width;
}

void Player::SetHeight(int _height)
{
	rectangle.height = _height;
}

void Player::SetPoints(int _points)
{
	points = _points;
}

void Player::SetRectanglePos(int posX, int posY)
{
	rectangle.x = posX;
	rectangle.y = posY;
}

void Player::AddPoints(int _points)
{
	points += _points;
}