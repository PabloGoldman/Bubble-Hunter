#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"

//using namespace sf;
   //NO AGREGAR EL NAMESPACE PORQUE CHOCA CON EL NOMBRE DE LA CLASE "TEXT"
class Text
{
private:
	std::string tx = "";
	int size;
	int spaceBetweenLetters;
public:
	Text();
	~Text();

	int GetSize();
	int GetSpaceBetweenLetters();
	std::string GetText();


	void SetText(std::string txt);
	void SetSize(int _size);
	void SetFont(sf::Font _font);
	void SetSpaceBetweenLetters(int _space);
};

