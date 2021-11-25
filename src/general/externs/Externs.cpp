#include "Externs.h"

#include <time.h>

namespace ExternVars
{
	sf::Font font;
	sf::Vector2f window;
	
	void InitExternVars()
	{
		srand(time(NULL));
		window = sf::Vector2f(800, 450);
		font.loadFromFile("res/font/font.ttf");
	}

}