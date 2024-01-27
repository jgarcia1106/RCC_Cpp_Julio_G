/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 19, 2024, 06:00 PM
 * Purpose:  Creation of pattern with user-defined size using nested loops
 */

#include <iostream>
using namespace std;

int main() {
    int n;  // Variable to store the maximum number of '+' to display

    // Ask the user to input the value of n
    //cout << "Enter the number of '+' symbols in the largest line: ";
    cin >> n;

    // Check if the input is valid
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;  // Exit the program if the input is invalid
    }

    // First part: increasing pattern
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "+";
        }
        // Double line break after each line
        cout << endl << endl;
    }

    // Second part: decreasing pattern
    // Start from n again to ensure the correct pattern
    for (int i = n; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            cout << "+";
        }
        // Double line break after each line except the last one
        if (i != 1) {
            cout << endl << endl;
        }
    }

    return 0;
}
