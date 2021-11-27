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

	/*bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec)
	{
		int recCenterX = (int)(rec.x + rec.width / 2.0f);
		int recCenterY = (int)(rec.y + rec.height / 2.0f);
		float dx = fabsf(center.x - (float)recCenterX);
		float dy = fabsf(center.y - (float)recCenterY);
		if (dx > (rec.width / 2.0f + radius)) { return false; }
		if (dy > (rec.height / 2.0f + radius)) { return false; }
		if (dx <= (rec.width / 2.0f)) { return true; }
		if (dy <= (rec.height / 2.0f)) { return true; }
		float cornerDistanceSq = (dx - rec.width / 2.0f) * (dx - rec.width / 2.0f) +
			(dy - rec.height / 2.0f) * (dy - rec.height / 2.0f);
		return (cornerDistanceSq <= (radius * radius));
	}*/

}