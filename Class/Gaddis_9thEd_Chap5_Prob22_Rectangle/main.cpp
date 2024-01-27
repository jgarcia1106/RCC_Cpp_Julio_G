/* 
 * File:   main.cpp
 * Author: Ninja G.
 * Created on January 17, 2024, 9:40 AM
 * Purpose: Retangle with same number of rows as columns 
 */

//System Libraries
#include <iostream>
using namespace std;

int main() {
    int size;
    char rectangleChar;

    // Ask user for the size of the rectangle and the character to use
    //cout << "Enter a positive integer no greater than 15: "; // I'm having to comment out this input
    cin >> size;
    //cout << "Enter the character for the rectangle (X or Y): "; // I'm having to comment out this input 
    cin >> rectangleChar;

    // Check if size is within the valid range
    if (size > 0 && size <= 15) {
        // Using nested loops to create rows and columns
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                cout << rectangleChar;
            }
            // Print newline for all but the last row
            if (row < size - 1) {
                cout << endl;
            }
        }
    } else {
        cout << "Invalid input. Size must be a positive integer no greater than 15." << endl;
    }

    return 0;
}

