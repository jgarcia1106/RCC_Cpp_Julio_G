/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on: February 4, 2024, 2:40 PM
 * Purpose: Calculate Average and Standard Deviation with Specific Input
 */

//System Libraries
#include <iostream>  // Allows program to output data to the console
#include <cmath>     // Includes the math library for mathematical operations
#include <iomanip>   // Used for manipulating the output formatting

using namespace std; // Standard namespace

// Function Prototypes - Declarations of functions before they are used
void init(float [], int); // Initialize the array with specific values
void print(float [], int, int); // Print the array
float avgX(float [], int); // Calculate the Average
float stdX(float [], int); // Calculate the standard deviation

// Main program execution starts here
int main() {
    // Declare Variables
    const int SIZE = 20; // Constant for the size of the array
    float test[SIZE]; // Array to hold the test values
    
    // Initialize array with specific values using the init function
    init(test, SIZE);
    
    // Set the output formatting for floating points to fixed point notation with 7 decimal places
    cout << fixed << setprecision(7); 
    // Output the average of the array
    cout << "The average            = " << avgX(test, SIZE) << endl;
    // Output the standard deviation of the array
    cout << "The standard deviation = " << stdX(test, SIZE) << endl;

    // End of program
    return 0;
}

// Function to initialize the array with values from 0 to 19
void init(float arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i; // Set each element to its index value
    }
}

// Function to print the array elements, formatted to display a certain number per line
void print(float arr[], int size, int perLine) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        cout << setw(10) << arr[i]; // setw(10) sets the width of the next output field
        if (++count % perLine == 0) cout << endl; // New line after every 'perLine' numbers
    }
    if (size % perLine != 0) cout << endl; // Ensure ending with a new line
}

// Function to calculate and return the average of the elements in the array
float avgX(float arr[], int size) {
    float sum = 0; // Initialize sum of elements
    for (int i = 0; i < size; ++i) {
        sum += arr[i]; // Add each element to sum
    }
    return sum / size; // Calculate average
}

// Function to calculate and return the standard deviation of the elements in the array
float stdX(float arr[], int size) {
    float mean = avgX(arr, size); // Calculate the mean first
    float sumOfSquares = 0; // Initialize sum of squared differences
    for (int i = 0; i < size; ++i) {
        // Add the square of the difference from the mean for each element
        sumOfSquares += pow(arr[i] - mean, 2);
    }
    // Calculate and return the standard deviation
    return sqrt(sumOfSquares / (size - 1));
}
