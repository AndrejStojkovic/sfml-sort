#include <iostream>
#include <SFML/Graphics.hpp>
#include "ArrayElement.h"
#include "Text.h"
#include "Helper.h"
#include "algorithms.h"

#define WIDTH 1280
#define HEIGHT 720

int main() {
	bool isSorted = true;
	int arrSize, delay, sortType;

	// Sort Visualizer Settings Prompt
	as:std::cout << "Enter Array Size (Minimum 10 and Maximum 1000): ";
	std::cin >> arrSize;

	if (arrSize < 10 || arrSize > 1000) {
		std::cout << "Invalid Array Size!\n";
		goto as;
	}

	del:std::cout << "Enter Delay (milliseconds) amount: ";
	std::cin >> delay;

	if (delay < 0) {
		std::cout << "Invalid Delay Interval!\n";
		goto del;
	}

	type:std::cout << "Choose Sort Type (0 - Quick, 1 - Bubble, 2 - Insertion, 3 - Selection, 4 - Heap): ";
	std::cin >> sortType;

	if (sortType < 0 || sortType > 4) {
		std::cout << "Invalid Sort Type!\n";
		goto type;
	}

	// Creating the Window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Sort Visualizer", sf::Style::Close);
	window.setFramerateLimit(60);

	// Generate and Shuffle array
	std::vector<ArrayElement> arr = Helper::generateArray(window, arrSize);
	Helper::shuffle(arr, 3);
	Helper::drawArray(window, arr);

	// Setting the UI Text
	std::string algorithmString;

	sortType == 0 ? algorithmString = "Quick" : sortType == 1 ? algorithmString = "Bubble" : sortType == 2 ? algorithmString = "Insertion" : sortType == 3 ? algorithmString = "Selection" : sortType == 4 ? algorithmString = "Heap" : "None";

	Text algorithm(window, "Algorithm: " + algorithmString + " Sort\nDelay: " + std::to_string(delay), 10.0f, 0.0f);
	Text ctrls(window, "R - Reset Array\nT - Sort", window.getSize().x - 200.0f, 0.0f);

	// Program Loop
	while (window.isOpen()) {
		sf::Event e;

		// Events loop
		while (window.pollEvent(e)) {
			switch (e.type) {
				case sf::Event::KeyReleased:
					switch (e.key.code) {
						case sf::Keyboard::R:
							if(isSorted) Helper::shuffle(arr);
							break;
						case sf::Keyboard::T:
							if(isSorted) isSorted = !isSorted;
							break;
						case sf::Keyboard::Escape:
							window.close();
							break;
					}
					break;

				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		window.clear(sf::Color::Black);
	
		// Sorting
		if (!isSorted) {
			switch (sortType) {
				case 0: // Quick
					Sort::quickSort(window, arr, delay, 0, arr.size() - 1);
					break;
				case 1: // Bubble
					Sort::bubbleSort(window, arr, delay);
					break;
				case 2: // Insertion
					Sort::insertionSort(window, arr, delay);
					break;
				case 3: // Selection
					Sort::selectionSort(window, arr, delay);
					break;
				case 4: // Heap
					Sort::heapSort(window, arr, delay);
					break;
			}

			isSorted = true;
		}
			
		// Draw on screen
		Helper::drawArray(window, arr);
		algorithm.update(window);
		ctrls.update(window);

		window.display();
	}

	return 0;
}