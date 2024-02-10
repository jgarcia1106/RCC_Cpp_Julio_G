/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 8, 2024, 4:00 PM
 * Purpose: Sort an array of characters
 */

// System Libraries
#include <iostream> // For cout, cin
#include <cstring>  // For strlen(), to get string length
using namespace std;

// Function to read characters into an array and return its actual size
int read(char arr[]) {
    cin >> arr; // Reads user input into the array
    return strlen(arr); // Calculates and returns the length of the array
}

// Function to sort the array of characters in ascending order
void sort(char arr[], int n) {
    // Using bubble sort algorithm for sorting
    for(int i = 0; i < n-1; i++) { // Loop over the array
        for(int j = 0; j < n-i-1; j++) { // Compare elements in pairs and swap if out of order
            if(arr[j] > arr[j+1]) {
                // Swapping elements if they're in the wrong order
                char temp = arr[j]; // Temporary variable for swapping
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print the sorted array of characters
void print(const char arr[], int n) {
    for(int i = 0; i < n; i++) { // Loop over the array
        cout << arr[i]; // Print each character
    }
    cout << endl; // New line after printing all characters
}

int main() {
    const int SIZE = 80; // Array size, larger than needed
    char array[SIZE]; // Character array
    int sizeIn, sizeDet; // Size input by user, Size detected in array
    
    // Introduction and input instructions
    cout << "Read in a 1 dimensional array of characters and sort" << endl;
    cout << "Input the array size where size <= 20" << endl;
    cin >> sizeIn; // User inputs the size of the array
    
    // Reading array and detecting its size
    cout << "Now read the Array" << endl;
    sizeDet = read(array); // Read the array and get its actual size
    
    // Compare input size vs. detected size and sort/print if they match
    if(sizeDet == sizeIn) {
        sort(array, sizeIn); // Sort the array if sizes match
        print(array, sizeIn); // Print the sorted array
    } else {
        // Output message if input size doesn't match the size of the array provided
        cout << (sizeDet < sizeIn ? "Input size less than specified." : "Input size greater than specified.") << endl;
    }
    
    // Exit the program
    return 0;
}
