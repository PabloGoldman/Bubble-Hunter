#include "Player.h"

const int screenWidth = 800;
const int screenHeight = 450;


Player::Player()
{
	rectangle.setSize(sf::Vector2f(100, 100));
	rectangle.setFillColor(sf::Color::Green);
	speed = 10;
	points = 0;
}

Player::~Player()
{

}

sf::RectangleShape Player::GetRectangle()
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

void Player::Input(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && rectangle.getPosition().x < screenWidth - rectangle.getSize().x)
	{
		rectangle.setPosition(rectangle.getPosition().x + speed, rectangle.getPosition().y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && rectangle.getPosition().x > 0)
	{
		rectangle.setPosition(rectangle.getPosition().x - speed, rectangle.getPosition().y);
	}
}


void Player::Update()
{

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
	sf::Vector2f aux = sf::Vector2f(_width, rectangle.getSize().y);
	rectangle.setSize(aux);
}

void Player::SetHeight(int _height)
{
	sf::Vector2f aux = sf::Vector2f(rectangle.getSize().x, _height);
	rectangle.setSize(aux);
}

void Player::SetPoints(int _points)
{
	points = _points;
}

void Player::SetRectanglePos(int posX, int posY)
{
	rectangle.setPosition(sf::Vector2f(posX, posY));
}

void Player::AddPoints(int _points)
{
	points += _points;
}