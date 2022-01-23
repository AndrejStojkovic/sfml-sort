#pragma once

#include "Sort.h"

namespace Sort {
	void insertionSort(sf::RenderWindow& window, std::vector<ArrayElement>& arr, int delay) {
		for (unsigned int i = 0; i < arr.size(); i++) {
			for (unsigned int j = i; j > 0; j--) {
				if (arr[j - 1].value > arr[j].value) {
					swap(arr[j - 1], arr[j]);
					redElements(arr[j - 1], arr[j]);
					swapEffect(window, arr, arr[j - 1], arr[j]);
					addDelay(delay);
				}
			}
		}

		Helper::cleanArray(arr);
	}
}