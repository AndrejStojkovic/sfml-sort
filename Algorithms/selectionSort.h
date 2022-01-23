#pragma once

#include "Sort.h"

namespace Sort {
	void selectionSort(sf::RenderWindow& window, std::vector<ArrayElement>& arr, int delay) {
		for (unsigned int i = 0; i < arr.size() - 1; i++) {
			int min = i;
			
			for (unsigned int j = i + 1; j < arr.size(); j++) {
				if (arr[j].value < arr[min].value) min = j;
			}
			
			if (min != i) {
				swap(arr[i], arr[min]);
				redElements(arr[i], arr[min]);
				swapEffect(window, arr, arr[i], arr[min]);

				addDelay(delay);
			}
		}

		Helper::cleanArray(arr);
	}
}