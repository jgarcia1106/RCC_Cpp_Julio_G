/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 19, 2024, 11:00 PM
 * Purpose: Maximum of first 2 parameters then Maximum of 3 parameters
 */

//System Libraries
#include <iostream> // Include the IO stream library for input and output operations
#include <iomanip>  // Include the IO manip library for output formatting
using namespace std; // Use the standard namespace

// Function to find the maximum of two floats
float maxOfTwo(float a, float b) {
    // Returns the larger of the two numbers using a ternary operator
    return (a > b) ? a : b;
}

// Function to find the maximum of three floats
float maxOfThree(float a, float b, float c) {
    // Returns the largest of three numbers by first comparing two and then comparing the result with the third
    return max(maxOfTwo(a, b), c);
}

int main() {
    float num1, num2, num3; // Variables to store the user input

    // Set the output format to fixed and precision to one decimal place
    cout << fixed << setprecision(1);

    // Prompt and read the first number
    cout << "Enter first number:" << endl;
    cout << endl;
    cin >> num1;

    // Prompt and read the second number
    cout << "Enter Second number:" << endl;
    cout << endl;
    cin >> num2;

    // Prompt and read the third number
    cout << "Enter third number:" << endl;
    cout << endl;
    cin >> num3;

    // Calculate and display the largest number using the two-parameter function
    cout << "Largest number from two parameter function:" << endl;
    cout << maxOfTwo(num1, num2) << endl << endl;

    // Calculate and display the largest number using the three-parameter function
    cout << "Largest number from three parameter function:" << endl;
    cout << maxOfThree(num1, num2, num3) << endl;

    return 0; // End of the program
}
