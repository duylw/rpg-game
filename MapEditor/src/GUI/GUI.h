#pragma once
#include <SFML/Graphics.hpp>


namespace GUI {

	class Button {
	private:
		sf::Sprite sprite;
		sf::Texture texture;

		sf::Vector2f position;
		sf::Vector2f scale;
		sf::Vector2f* mousePosition;

		bool isMousePressed;
		bool isMouseReleased;
	public:
		Button(const sf::Vector2f &ini_position, const sf::Vector2f &ini_scale);
		~Button();

		void Initialize();
		void Load();
		void Update(float deltaTime, sf::Vector2f& mousePosition);
		void Draw(sf::RenderWindow &window);

		bool isPressed() const;
	};

}

