#pragma once

#include "Sort.h"

namespace Sort {
	void bubbleSort(sf::RenderWindow& window, std::vector<ArrayElement>& arr, int delay) {
		for (unsigned int i = 0; i < arr.size() - 1; i++) {
			for (unsigned int j = 0; j < arr.size() - 1 - i; j++) {
				if (arr[j].value > arr[j + 1].value) {
					swap(arr[j], arr[j + 1]);
					redElements(arr[j], arr[j + 1]);
					swapEffect(window, arr, arr[j], arr[j + 1]);

					addDelay(delay);
				}
			}
		}

		Helper::cleanArray(arr);
	}
}