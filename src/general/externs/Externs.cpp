#include "Externs.h"

namespace ExternVars
{
	sf::Font font;
	
	void InitExternVars()
	{
		font.loadFromFile("res/font/font.ttf");
	}

}