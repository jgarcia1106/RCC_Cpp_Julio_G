/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 6, 2024, 6:00 PM
 * Purpose: Linear Search
 */

//System Libraries
// Including header files for input/output operations and to use vectors
#include <iostream>
#include <vector>

using namespace std;

void fillArray(vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

// Updated print function to match the expected output format
void printArray(const vector<int>& arr, int perLine) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << "·"; // Separator as per the expected output
        }
        if ((i + 1) % perLine == 0 && (i + 1) < arr.size()) {
            cout << "↵\n"; // Line break with special character
        }
    }
    cout << "↵\n"; // End with the special character and newline
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

bool binarySearch(const vector<int>& arr, int value, int& index) {
    int low = 0, high = arr.size() - 1;
    index = -1; // Initialize index to -1 to indicate not found by default
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            index = mid; // Value found
            return true;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false; // Value not found
}

int main() {
    int n, value;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> array(n);

    cout << "Enter " << n << " elements: ";
    fillArray(array, n);

    selectionSort(array);

    cout << "Sorted array: " << endl;
    printArray(array, 10);

    cout << "Input the value to find in the array: ";
    cin >> value;

    int index;
    if (binarySearch(array, value, index)) {
        cout << value << " was found at indx = " << index << "↵\n";
    } else {
        cout << value << " was not found in the array.↵\n";
    }

    return 0;
}
