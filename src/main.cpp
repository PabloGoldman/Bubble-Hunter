#include "SFML/Graphics.hpp"

#include "manager/GameManager.h"
void main()
{
    GameManager* gameManager = new GameManager();

    gameManager->RunGame();

    delete gameManager;
}