#include <iostream>
#include <vector>
#include <utility> // Required for std::swap

// Use the standard namespace to avoid writing std:: prefix
using namespace std;

// Function to print the elements of a vector
void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Bubble Sort function template
// Accepts an integer vector by reference (&) to modify it directly
void bubbleSort(vector<int>& arr) {
    // Get the number of elements in the vector
    int n = arr.size();
    bool swapped; // Optimization: to stop if the array is already sorted

    // Outer loop for each pass
    // It only needs to run n-1 times
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        // Inner loop for comparison and swapping
        // Each pass will "bubble up" the largest element to its correct position
        // That's why the limit is n - 1 - i
        for (int j = 0; j < n - 1 - i; ++j) {
            // Compare the current element with the next one
            if (arr[j] > arr[j + 1]) {
                // If they are in the wrong order, swap them
                swap(arr[j], arr[j + 1]);
                swapped = true; // Mark that a swap has occurred
            }
        }

        // Optimization: If no swaps occurred in a full pass,
        // it means the array is already sorted, and we can stop early.
        if (!swapped) {
            break;
        }
    }
}

int main() {
    // Example usage
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    cout << "Array before sorting: ";
    printVector(data);

    // Call the bubbleSort function to sort the data
    bubbleSort(data);

    cout << "Array after sorting: ";
    printVector(data);

    return 0;
}
