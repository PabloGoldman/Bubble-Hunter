#include "Rules.h"

#include <string>

#include <SFML\Window\Keyboard.hpp>
#include "general/externs/Externs.h"

const int fontSize = 28;

using namespace sf;

void Rules::InitRules()
{

	actualIndex = 0;

	background = RectangleShape();
	background.setFillColor(Color::Black);
	background.setSize(Vector2f(ExternVars::window.x, ExternVars::window.y));
	background.setPosition(Vector2f(0, 0));

	title = Text();
	title.setFont(ExternVars::font);
	title.setCharacterSize(40);
	title.setFillColor(Color::White);
	title.setPosition(Vector2f(ExternVars::window.x * 25 / 60, ExternVars::window.y / 30));
	title.setString("RULES");

	index = Text();
	index.setFont(ExternVars::font);
	index.setCharacterSize(30);
	index.setFillColor(Color::White);
	index.setPosition(Vector2f(ExternVars::window.x * 58 / 60, ExternVars::window.y / 60));
	index.setString("1");

	for (short i = 0; i < ARROW_COUNT; i++)
	{
		arrow[i] = Text();
		arrow[i].setFont(ExternVars::font);
		arrow[i].setCharacterSize(50);
		arrow[i].setFillColor(Color::White);
		if (i == 0)
		{
			arrow[i].setPosition(Vector2f(ExternVars::window.x *  3 / 60, ExternVars::window.y * 24 / 30));
			arrow[i].setString("<");
		}
		else
		{
			arrow[i].setPosition(Vector2f(ExternVars::window.x * 56 / 60, ExternVars::window.y * 24 / 30));
			arrow[i].setString(">");
		}
	}

	for (short i = 0; i < RULE_TABS; i++)
	{
		line1[i] = Text();
		line1[i].setFont(ExternVars::font);
		line1[i].setCharacterSize(23);
		line1[i].setFillColor(Color::White);
		line1[i].setPosition(Vector2f(ExternVars::window.x * 1 / 30, ExternVars::window.y * 5 / 30));

		line2[i] = Text();
		line2[i].setFont(ExternVars::font);
		line2[i].setCharacterSize(23);
		line2[i].setFillColor(Color::White);
		line2[i].setPosition(Vector2f(ExternVars::window.x * 1 / 30, ExternVars::window.y * 8 / 30));

		line3[i] = Text();
		line3[i].setFont(ExternVars::font);
		line3[i].setCharacterSize(23);
		line3[i].setFillColor(Color::White);
		line3[i].setPosition(Vector2f(ExternVars::window.x * 1 / 30, ExternVars::window.y * 11 / 30));
	}
	//     TAMAÑO     ("-------------------------------------------------------------------------------")
	line1[0].setString("Bubble Hunter is a game which objetive is clean different rooms out of bubbles.");
	line2[0].setString("For this objetive, you have to move to left/right with the keyboard ARROWS.");
	line3[0].setString("You can shoot an arrow too with the SPACE bar.");

	line1[1].setString("There are 3 sizes of Bubbles.");
	line2[1].setString("Every ball is smaller than the previous one.");
	line3[1].setString("When the character hits one bubble with an arrow, it will split in two.");

	line1[2].setString("You can pause the game with 'P'.");
	line2[2].setString("Everytime it collides with a bubble, will restart the game.");
	line3[2].setString("When all lifes are gone, the game will be lost.");

	line1[3].setString("When all bubbles are hunted, you will win the room.");
	line2[3].setString("Another room will spawn but with augmented speed to prove your skills.");
	line3[3].setString("Have fun hunting bubbles :)");

}

void Rules::InRules(sf::RenderWindow* window)
{
	if (!inited)
	{
		InitRules();
		inited = true;
	}

	CheckInput(window);
	DrawRules(window);
}

void Rules::DrawRules(sf::RenderWindow* window)
{
	window->draw(background);
	window->draw(title);
	window->draw(index);
	window->draw(line1[actualIndex]);
	window->draw(line2[actualIndex]);
	window->draw(line3[actualIndex]);
	for (short i = 0; i < ARROW_COUNT; i++)
	{
		window->draw(arrow[i]);
	}
}

void Rules::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Rules::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Rules::CheckInput(RenderWindow* window)
{
	sf::Event event;

	while (window->pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) 
		{
			window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				ReturnToMenu();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				actualIndex--;
				if (actualIndex < 0)
					actualIndex = RULE_TABS - 1;
				index.setString(std::to_string(actualIndex+1));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				actualIndex++;
				if (actualIndex >= RULE_TABS)
					actualIndex = 0;
				index.setString(std::to_string(actualIndex+1));
			}
		}
	}
}
