/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 3, 2024, 11:00 AM
 * Purpose: Product Table
 * 
 * This program creates a multiplication table, similar to what you might see in a math class.
 * It's designed to help visualize the product (result of multiplication) of numbers 1 through 6.
 */

// Include necessary libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   // Srand for random number generation
#include <ctime>     // Time to set the random number seed
using namespace std;

// Function Prototypes
void init(int [], int); // Initialize the array with random values
void print(int [], int, int); // Print the array
void revrse(int [], int); // Reverse the contents of the array

int main() {
    // Set the random number seed to ensure different random numbers each run
    srand(static_cast<unsigned>(time(0)));
    
    // Declare Variables
    const int SIZE = 50; // Size of the array
    int test[SIZE]; // The array itself
    
    // Initialize or input i.e. set variable values
    init(test, SIZE);
    
    // Display the original array
    cout << "Original array:" << endl;
    print(test, SIZE, 10);
    
    // Reverse the values in the array
    revrse(test, SIZE);
    
    // Display the reversed array
    cout << "\nReversed array:" << endl;
    print(test, SIZE, 10);

    return 0;
}

void init(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Fill the array with random numbers between 0 and 99
    }
}

void print(int arr[], int size, int perLine) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if ((i + 1) % perLine == 0) // After printing 'perLine' elements, insert a newline
            cout << endl;
        else if (i < size - 1) // Ensure no extra space is added at the end of the array
            cout << " "; // Use a space as the separator
    }
}

void revrse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp; // Swap the elements
    }
}