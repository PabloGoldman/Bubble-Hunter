#include "HUD.h"
using namespace sf;

void HUD::DrawPoints(int points, int posX, int posY, int fontSize, Color color)
{
	DrawText(TextFormat("%i", points), posX, posY, fontSize, color);
}
