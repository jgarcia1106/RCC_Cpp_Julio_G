/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 25, 2024, 6:30 PM
 * Purpose: Histogram
 */

//System Libraries
#include <iostream>
#include <cctype>  // Include the cctype library for the isdigit function
using namespace std;

int main(int argc, char** argv) {
    // Declare all Variables Here
    // Four variables to store each digit entered by the user
    char digit1, digit2, digit3, digit4;

    // Prompt the user for input
    // Displaying instructions to the user
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    // Reading four characters as input from the user
    cin >> digit1 >> digit2 >> digit3 >> digit4;

    // Process each digit starting from the units place to the thousands place
    // For digit4 (units)
    if (isdigit(digit4)) {  // Check if digit4 is a number
        cout << digit4 << " ";
        for (int i = 0; i < digit4 - '0'; i++) {  // Loop to print the histogram
            cout << "*";
        }
        cout << endl;  // End the line after printing the histogram
    } else {
        cout << digit4 << " ?" << endl;  // If not a number, print a question mark
    }

    // For digit3 (tens)
    // The logic is similar to digit4
    if (isdigit(digit3)) {
        cout << digit3 << " ";
        for (int i = 0; i < digit3 - '0'; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        cout << digit3 << " ?" << endl;
    }

    // For digit2 (hundreds)
    // The logic is similar to digit4
    if (isdigit(digit2)) {
        cout << digit2 << " ";
        for (int i = 0; i < digit2 - '0'; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        cout << digit2 << " ?" << endl;
    }

    // For digit1 (thousands)
    // The logic is similar to digit4
    if (isdigit(digit1)) {
        cout << digit1 << " ";
        for (int i = 0; i < digit1 - '0'; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        cout << digit1 << " ?" << endl;
    }

    // Exit the program
    return 0;
}
