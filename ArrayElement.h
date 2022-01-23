#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class ArrayElement : public sf::RectangleShape {
public:
	using sf::RectangleShape::RectangleShape;
	int value;
};

