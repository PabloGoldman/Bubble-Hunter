#include "Credits.h"
#include "SFML/Graphics.hpp"
#include "general/externs/Externs.h"


using namespace sf;

void Credits::InitCredits()
{
	title = Text();
	programmer1 = Text();
	programmer2 = Text();

	background = RectangleShape();
	
	background.setFillColor(Color::Black);
	background.setSize(Vector2f(ExternVars::window.x, ExternVars::window.y));
	background.setPosition(Vector2f(0, 0));

	title.setFont(ExternVars::font);
	programmer1.setFont(ExternVars::font);
	programmer2.setFont(ExternVars::font);

	title.setString("CREDITS");
	programmer1.setString("Programmer: GOLDMAN, Pablo");
	programmer2.setString("Programmer: TELLO, Guido");

	title.setCharacterSize(60);
	programmer1.setCharacterSize(40);
	programmer2.setCharacterSize(40);

	title.setFillColor(Color::White);
	programmer1.setFillColor(Color::White);
	programmer2.setFillColor(Color::White);

	title.setPosition(Vector2f(ExternVars::window.x *11/30, ExternVars::window.y / 11));
	programmer1.setPosition(Vector2f(ExternVars::window.x / 5, ExternVars::window.y * 2 / 5));
	programmer2.setPosition(Vector2f(ExternVars::window.x / 5, ExternVars::window.y * 3 / 5));

}

void Credits::InCredits(sf::RenderWindow* window)
{
	if (!inited)
	{
		InitCredits();
		inited = true;
	}
	CheckInput(window);
	DrawCredits(window);

}

void Credits::DrawCredits(sf::RenderWindow* window)
{
	window->draw(background);
	window->draw(title);
	window->draw(programmer1);
	window->draw(programmer2);
}

void Credits::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Credits::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Credits::CheckInput(sf::RenderWindow* window)
{
	sf::Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				ReturnToMenu();
			}
		}
	}
	
}
