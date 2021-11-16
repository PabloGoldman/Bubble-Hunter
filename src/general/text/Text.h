#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

//using namespace sf;
   //NO AGREGAR EL NAMESPACE PORQUE CHOCA CON EL NOMBRE DE LA CLASE "TEXT"
class Text
{
private:
	std::string tx = "";
	//Vector2 pos = { 0,0 };
	int size;
	sf::Color color;
	sf::Font font;
	int spaceBetweenLetters;
public:
	Text();
	~Text();

	int GetSize();
	sf::Color GetColor();
	sf::Font GetTextFont();
	int GetSpaceBetweenLetters();
	std::string GetText();


	void SetText(std::string txt);
	void SetSize(int _size);
	void SetColor(sf::Color _color);
	void SetFont(sf::Font _font);
	void SetSpaceBetweenLetters(int _space);
};

