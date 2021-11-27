#include "Arrow.h"

const int screenWidth = 800;
const int screenHeight = 450;

Arrow::Arrow()
{
	speed = 0.1;

	_width = 5;
	_height = 1000;

	color = sf::Color::Red;

	rectangle.setSize(sf::Vector2f(_width, _height));

	rectangle.setPosition({ 0,screenHeight });

	isActive = false;

}

Arrow::~Arrow()
{

}

sf::RectangleShape Arrow::GetRectangle()
{
	return rectangle;
}

sf::Color Arrow::GetColor()
{
	return color;
}

bool Arrow::GetIsActive()
{
	return isActive;
}

void Arrow::Update()
{
	Movement();

	if (rectangle.getPosition().y < 0)
	{
 		isActive = false;
	}
}

int Arrow::GetSpeed()
{
	return speed;
}

void Arrow::Movement()
{
	if (isActive)
	{
		rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y - speed);
	}
	else
	{
		rectangle.setPosition(rectangle.getPosition().x, screenHeight);
	}
}

void Arrow::UseArrow(float posX)
{
	isActive = true;
	rectangle.setPosition(posX, rectangle.getPosition().y);
}

void Arrow::SetActive(bool active)
{
	isActive = active;
}

void Arrow::Draw(sf::RenderWindow* window)
{
	window->draw(rectangle);
}

