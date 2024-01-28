/* 
 * File:   main.cpp
 * Author: Julio G
 * Created on January 27, 2024, 9:40 AM
 * Purpose: Factorial
 */

#include <iostream>
using namespace std;

// Function Prototypes
int fctrl(int n); // Prototype for the factorial function

int main() {
    // Declare Variables
    int number, result; // 'number' will hold the user input, 'result' will store the factorial

    // Output initial message
    cout << "This program calculates the factorial using a function prototype found in the template for this problem." << endl;
    cout << "Input the number for the function." << endl;
    
    // Input from user
    cin >> number; // Read the number from the user

    // Process
    result = fctrl(number); // Calculate the factorial of 'number' by calling the fctrl function

    // Output data
    cout << number << "! = " << result; // Display the result, which is the factorial of 'number'

    return 0; // Return 0 to indicate successful completion
}

// Function to calculate factorial
int fctrl(int n) {
    // The function uses recursion to calculate the factorial
    if (n <= 1) return 1; // Base case: factorial of 0 or 1 is 1
    else return n * fctrl(n - 1); // Keep calling fctrl with decremented value of n
}
