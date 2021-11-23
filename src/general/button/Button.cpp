#include "Button.h"

static int correctionX = 40;
static int correctionY = 16;
static int optionButtonHeight = 15;
static int optionButtonWidth = 15;

Button::Button()
{
	text = new Text();

	rectangle.setSize(sf::Vector2f(200, 200));

	color = sf::Color::Black;
}

Button::~Button()
{
	delete text;
}

//-------------------------------------------GETTERS------------------------------

sf::RectangleShape Button::GetRectangle()
{
	return rectangle;
}

sf::Color Button::GetColor()
{
	return color;
}

int Button::GetWidth()
{
	return rectangle.getSize().x;
}

int Button::GetHeight()
{
	return rectangle.getSize().y;
}

bool Button::GetActive()
{
	return isActive;
}

std::string Button::GetText()
{
	return text->GetText();
}

sf::Font Button::GetFont()
{
	return text->GetTextFont();
}

int Button::GetFontSize()
{
	return text->GetSize();
}

int Button::GetSpaceBetweenLetters()
{
	return text->GetSpaceBetweenLetters();
}

//--------------------------------------------SETTERS---------------------------------

void Button::SetText(std::string txt)
{
	text->SetText(txt);
}

void Button::SetActive(bool _isActive)
{
	isActive = _isActive;
}

void Button::SetWidth(int _width)
{
	sf::Vector2f aux = sf::Vector2f(_width, rectangle.getSize().y);
	rectangle.setSize(aux);
}

void Button::SetHeight(int _height)
{
	sf::Vector2f aux = sf::Vector2f(rectangle.getSize().x, _height);
	rectangle.setSize(aux);
}

void Button::SetRectanglePos(int posX, int posY)
{
	rectangle.setPosition(posX, posY);
}

void Button::SetColor(sf::Color _color)
{
	color = _color;
}

//-------------------------------------------FUNCIONES---------------------------------

void Button::DrawButton(sf::RectangleShape rectangle, const char text[], sf::RenderWindow* window)
{

	sf::Font font;
	font.loadFromFile("font/font.ttf");

	sf::Text txt;
	txt.setString(text);

	txt.setPosition(GetRectangle().getPosition());
	
	window->draw(rectangle);
	window->draw(txt);

	//DrawTextRec(font, text, GetRectangle(), GetFontSize(), GetSpaceBetweenLetters(), false, GetColor());

	if (isActive) //Dibuja el boton de la izquierda, el que muestra la seleccion
	{
		sf::RectangleShape rec;
		rec.setPosition(sf::Vector2f(rectangle.getSize().x - correctionX, rectangle.getSize().y + correctionY));
		rec.setSize(sf::Vector2f(optionButtonHeight, optionButtonWidth));
		rec.setFillColor(GetColor());
		window->draw(rec);
		//DrawRectangle(rectangle.getSize().x - correctionX, rectangle.getSize().y + correctionY, optionButtonHeight, optionButtonWidth, GetColor());
	}
}
