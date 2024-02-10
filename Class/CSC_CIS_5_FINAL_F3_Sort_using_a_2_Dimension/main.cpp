/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 8, 2024, 10:00 AM
 * Purpose: Sort a 2D array of character strings by row.
 */

// Include necessary libraries
#include <iostream> // Handles input and output
#include <cstring>  // Provides functions for handling strings (arrays of characters)
using namespace std;

const int COLMAX = 80; // Maximum number of columns in our 2D array, including space for the null terminator

// Function to read input into our 2D array and determine the actual number of columns
int read(char arr[][COLMAX], int &rowIn) {
    int maxCol = 0; // Track the maximum number of columns (characters in the longest row)
    for(int i = 0; i < rowIn; i++) {
        cin >> arr[i]; // Read each row of characters
        int currentLength = strlen(arr[i]); // Find the length of the current row
        if(currentLength > maxCol) maxCol = currentLength; // Update maxCol if the current row is longer
    }
    return maxCol; // Return the length of the longest row
}

// Function to sort the rows of the array alphabetically
void sort(char arr[][COLMAX], int row, int col) {
    // We use a simple bubble sort algorithm, comparing rows with strcmp
    for(int i = 0; i < row - 1; i++) { // Go through each row
        for(int j = 0; j < row - i - 1; j++) { // Compare the current row with the next row
            if(strcmp(arr[j], arr[j + 1]) > 0) { // If the current row should come after the next row
                char temp[COLMAX]; // Temporary storage for swapping rows
                strcpy(temp, arr[j]); // Copy the current row to temp
                strcpy(arr[j], arr[j + 1]); // Copy the next row to the current row
                strcpy(arr[j + 1], temp); // Copy temp (original current row) to the next row
            }
        }
    }
}

// Function to print the sorted 2D array
void print(const char arr[][COLMAX], int row, int col) {
    for(int i = 0; i < row; i++) { // Loop through each row
        cout << arr[i] << endl; // Print the row followed by a new line
    }
}

// Main function where the program execution begins
int main() {
    const int ROW = 30; // Maximum number of rows we can have
    char array[ROW][COLMAX]; // Our 2D array where each row is a string
    int colIn, colDet, rowIn, rowDet; // Variables to store input and detected sizes

    // Prompt user for input sizes
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn; // User inputs desired number of rows
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn; // User inputs maximum number of columns

    // Read the array
    cout << "Now input the array." << endl;
    rowDet = rowIn; // Assume detected rows is the same as input initially
    colDet = read(array, rowDet); // Read array and get actual column size

    // Compare input sizes to actual sizes and sort/print if they match
    if(rowDet == rowIn && colDet == colIn) {
        sort(array, rowIn, colIn); // Sort the array
        cout << "The Sorted Array" << endl;
        print(array, rowIn, colIn); // Print the sorted array
    } else {
        // Handle mismatch in input vs detected sizes
        if(rowDet != rowIn)
            cout << (rowDet < rowIn ? "Row Input size less than specified." : "Row Input size greater than specified.") << endl;
        if(colDet != colIn)
            cout << (colDet < colIn ? "Column Input size less than specified." : "Column Input size greater than specified.") << endl;
    }
    return 0; // End of program
}
