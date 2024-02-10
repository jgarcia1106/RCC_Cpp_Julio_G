/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 8, 2024, 5:00 PM
 * Purpose: Find the Max, Min, and Sum of an integer array.
 */

// Include necessary libraries
#include <iostream>

int findMax(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(const int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    const int SIZE = 20; // Maximum array size
    int array[SIZE]; // Array to hold integers
    int size;

    std::cout << "Read in a 1 dimensional array of integers find sum/min/max" << std::endl;
    std::cout << "Input the array size where size <= 20" << std::endl;
    std::cin >> size;

    // Validate array size
    if (size < 1 || size > SIZE) {
        std::cout << "Invalid size. Please input a size between 1 and " << SIZE << "." << std::endl;
        return 1; // Exit if input size is not within the valid range
    }

    std::cout << "Now read the Array" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "a[" << i << "] = ";
        std::cin >> array[i];
        std::cout << array[i] << std::endl; // Display the input right after it's entered
    }

    int sum = findSum(array, size);
    int min = findMin(array, size);
    int max = findMax(array, size);

    std::cout << "Min  = " << min << std::endl;
    std::cout << "Max  = " << max << std::endl;
    std::cout << "Sum  = " << sum << std::endl;

    return 0;
}
