#include "Text.h"


Text::Text()
{
	size = 50;
	//color = sf::Color::Black;
	spaceBetweenLetters = 5;
}

Text::~Text()
{

}

//---------------------------------------------------GETTERS--------------------

int Text::GetSize()
{
	return size;
}

std::string Text::GetText()
{
	return tx;
}


int Text::GetSpaceBetweenLetters()
{
	return spaceBetweenLetters;
}

//---------------------------------------------------SETTERS------------------

void Text::SetSize(int _size)
{
	size = _size;
}

void Text::SetText(std::string txt)
{
	tx = txt;
}

void Text::SetSpaceBetweenLetters(int _space)
{
	spaceBetweenLetters = _space;
}


