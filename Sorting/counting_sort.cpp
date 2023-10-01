#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;  // Nothing to sort
    }

    // Find the maximum and minimum values in the array
    int max_val = arr[0];
    int min_val = arr[0];
    for (int num : arr) {
        max_val = std::max(max_val, num);
        min_val = std::min(min_val, num);
    }

    // Determine the range of values
    int range = max_val - min_val + 1;

    // Create a counting array and initialize it to zero
    std::vector<int> count(range, 0);

    // Count the occurrences of each element
    for (int num : arr) {
        count[num - min_val]++;
    }

    // Update the count array to store the cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary output array
    std::vector<int> output(arr.size());

    // Build the output array using the count array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
