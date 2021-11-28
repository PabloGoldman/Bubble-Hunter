#pragma once
#include <SFML/Graphics.hpp>
#include <SFML\Window\Window.hpp>

class Arrow
{
	private:

		sf::RectangleShape rectangle;
		sf::Color color;
		float speed;

		float _width;
		float _height;

		bool isActive;

	public:
		Arrow();
		~Arrow();

		sf::RectangleShape GetRectangle();
		sf::Color GetColor();

		bool GetIsActive();

		void Update();
		int GetSpeed();
		void Movement();
		void UseArrow(float x);

		void SetActive(bool active);

		void Draw(sf::RenderWindow* window);
};

