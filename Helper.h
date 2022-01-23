#pragma once

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "ArrayElement.h"
#include "Sort.h"

namespace Helper {
	std::vector<ArrayElement> generateArray(sf::RenderWindow& window, int arrSize) {
		float width = window.getSize().x;
		float height = window.getSize().y;
		float offset = 150.0f;

		std::vector<ArrayElement> arr;

		for (int i = 0; i < arrSize; i++) {
			ArrayElement element;

			float sizeX = width / arrSize;
			float sizeY = ((height - offset) / arrSize) * (i + 1);
			element.setSize(sf::Vector2f(sizeX, -sizeY));

			float posX = (width / arrSize) * i;
			float posY = height;
			element.setPosition(sf::Vector2f(posX, posY));

			element.setFillColor(sf::Color::White);
			element.value = i;

			arr.push_back(element);
		}

		return arr;
	}

	void shuffle(std::vector<ArrayElement>& arr) {
		int arrSize = arr.size();
		srand((unsigned int)time(0));

		for (int i = 0; i < arrSize; i++) {
			int index = rand() % arrSize;

			Sort::swap(arr[i], arr[index]);
		}
	}

	void shuffle(std::vector<ArrayElement>& arr, int n) {
		for (int i = 0; i < n; i++) {
			shuffle(arr);
		}
	}

	void drawArray(sf::RenderWindow& window, std::vector<ArrayElement> arr) {
		for (unsigned int i = 0; i < arr.size(); i++) {
			window.draw(arr[i]);
		}
	}
	
	void cleanArray(std::vector<ArrayElement> arr) {
		int arrSize = arr.size();

		for (int i = 0; i < arrSize; i++) {
			arr[i].setFillColor(sf::Color(69, 69, 69));
		}
	}
}