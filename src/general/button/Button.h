#pragma once
#include "../text/Text.h"
#include <iostream>

class Button
{
private:
	Text* text;

	sf::Color color;
	sf::RectangleShape rectangle;
	bool isActive = false;

public:
	Button();
	~Button();

	sf::RectangleShape GetRectangle();
	sf::Color GetColor();

	int GetFontSize();

	sf::Font GetFont();

	std::string GetText();

	int GetSpaceBetweenLetters();

	int GetWidth();
	int GetHeight();
	bool GetActive();

	void SetActive(bool _isActive);
	void SetText(std::string txt);
	void SetColor(sf::Color _color);
	void SetWidth(int _width);
	void SetHeight(int _height);
	void SetRectanglePos(int posX, int posY);

	void DrawButton(sf::RectangleShape rectangle, const char text[]);

};

