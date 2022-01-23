#pragma once

#include "Sort.h"

namespace Sort {
	void heapify(sf::RenderWindow& window, std::vector<ArrayElement>& arr, int delay, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l].value > arr[largest].value)
            largest = l;

        if (r < n && arr[r].value > arr[largest].value)
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            redElements(arr[i], arr[largest]);
            swapEffect(window, arr, arr[i], arr[largest]);
            addDelay(delay);

            heapify(window, arr, delay, n, largest);
        }
	}

	void heapSort(sf::RenderWindow& window, std::vector<ArrayElement>& arr, int delay) {
        int arrSize = arr.size();
        for (int i = arrSize / 2 - 1; i >= 0; i--) {
            heapify(window, arr, delay, arrSize, i);
            addDelay(delay);
        }

        for (int i = arrSize - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            clearElements(arr[0], arr[i]);
            heapify(window, arr, delay, i, 0);
            addDelay(delay);
        }

        Helper::cleanArray(arr);
	}
}