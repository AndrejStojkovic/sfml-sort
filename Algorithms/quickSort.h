#pragma once

#include "Sort.h"

namespace Sort {
	int partition(sf::RenderWindow& window, std::vector<ArrayElement>& arr, int delay, int low, int high) {
		int i = low;
		ArrayElement pivot = arr[high];

		for (int j = low; j < high; j++) {
			if (arr[j].value <= pivot.value) {
				swap(arr[i], arr[j]);
				redElements(arr[i], arr[j]);
				swapEffect(window, arr, arr[i], arr[j]);

				i++;
				addDelay(delay);
			}
		}

		swap(arr[i], arr[high]);
		redElements(arr[i], arr[high]);
		swapEffect(window, arr, arr[i], arr[high]);

		addDelay(delay);

		return i;
	}

	void quickSort(sf::RenderWindow& window, std::vector<ArrayElement>& arr, int delay, int low, int high) {
		if (low < high) {
			int pi = partition(window, arr, delay, low, high);

			quickSort(window, arr, delay, low, pi - 1);
			quickSort(window, arr, delay, pi + 1, high);
		}

		Helper::cleanArray(arr);
	}
}