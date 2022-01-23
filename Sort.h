#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include "ArrayElement.h"

namespace Sort {
	void swap(ArrayElement& arr1, ArrayElement& arr2) {
		sf::Vector2f firstPosition = arr1.getPosition();
		int valueOne = arr1.value;

		sf::Vector2f secondPosition = arr2.getPosition();
		int valueTwo = arr2.value;

		arr1.setPosition(secondPosition);
		arr1.value = valueTwo;

		arr2.setPosition(firstPosition);
		arr2.value = valueOne;
	}

	void redElements(ArrayElement& arr1, ArrayElement& arr2) {
		arr1.setFillColor(sf::Color::Red);
		arr2.setFillColor(sf::Color::Red);
	}

	void clearElements(ArrayElement& arr1, ArrayElement& arr2) {
		arr1.setFillColor(sf::Color::White);
		arr2.setFillColor(sf::Color::White);
	}

	void swapEffect(sf::RenderWindow& window, std::vector<ArrayElement> arr, ArrayElement& arr1, ArrayElement& arr2) {
		window.clear(sf::Color::Black);
		for (unsigned int i = 0; i < arr.size(); i++) {
			window.draw(arr[i]);
		}
		window.display();

		clearElements(arr1, arr2);
	}

	void addDelay(int delay) {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}