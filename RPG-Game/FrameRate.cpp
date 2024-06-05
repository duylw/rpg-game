#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() :
	timer{}
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
	frameRateText.setString("0");
}

void FrameRate::Load()
{
	if (font.loadFromFile("Assets/fonts/Arial.ttf"))
	{
		std::cout << "Font loaded!\n";
		frameRateText.setFont(font);
	}
	else
	{
		std::cout << "Font load failed\n";
	}
}

void FrameRate::Update(double deltaTime)
{
	timer += deltaTime;
	
	if (timer >= 150.0) {
		std::string fps = std::to_string((int)(1000/deltaTime));
		frameRateText.setString(fps);
		timer = 0;
	}
}

void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}
