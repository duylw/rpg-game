#include "GUI.h"
#include <iostream>

using namespace GUI;

Button::Button(const sf::Vector2f& ini_position, const sf::Vector2f& ini_scale):
	mousePosition{NULL}, position{ini_position}, scale{ini_scale}, 
	isMousePressed{false}, isMouseReleased{true}
{}																   

Button::~Button()
{
	
}

void Button::Initialize()
{}

void Button::Load()
{
	if (texture.loadFromFile("assets/gui/button.png"))
	{
		sprite.setTexture(texture);
		sprite.setPosition(position);
		sprite.setScale(scale);
	}
	else
	{
	}
}

void Button::Update(float deltaTime, sf::Vector2f& mousePosition)
{
	this->mousePosition = &mousePosition;

	isMousePressed = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (isMouseReleased)
		{
			isMousePressed = true;
		}	

		isMouseReleased = false;
	}
	else
	{
		isMouseReleased = true;
		
	}
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

bool Button::isPressed() const
{
	if (isMousePressed)
	{
		const sf::Vector2u& size = sprite.getTexture()->getSize();

		if (
			mousePosition->x >= position.x && mousePosition->x < position.x + size.x &&
			mousePosition->y >= position.y && mousePosition->y < position.y + size.y)
		{
			std::cout << "Button pressed\n";
			return true;
		}

	}
	return false;
}