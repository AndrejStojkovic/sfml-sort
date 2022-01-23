#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Text {
public:
	Text(sf::RenderWindow& window, std::string textString, float posX, float posY) {
		if (!font.loadFromFile("arial.ttf")) std::cout << "Error loading font!\n";
		txt.setFont(font);
		txt.setString(textString);
		txt.setCharacterSize(28);
		txt.setFillColor(sf::Color::White);
		txt.setPosition(posX, posY);
	}

	void update(sf::RenderWindow& window) {
		window.draw(txt);
	}
private:
	sf::Text txt;
	sf::Font font;
};