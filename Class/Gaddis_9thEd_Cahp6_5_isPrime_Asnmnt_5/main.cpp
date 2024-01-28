/* 
 * File:   main.cpp
 * Author: Julio G
 * Created on January 27, 2024, 10:00 AM
 * Purpose: isPrime
 */

#include <iostream>
using namespace std;

// Function Prototypes
bool isPrime(int number); // Declares a function that checks if a number is prime

int main() {
    // Declare Variables
    int num; // Variable to store the number input by the user

    // Output initial message and Input from user
    cout << "Input a number to test if Prime." << endl; // Ask the user to input a number
    cin >> num; // Read the number from the user

    // Process and Output data
    if (isPrime(num)) { // Check if the number is prime using isPrime function
        cout << num << " is prime."; // If isPrime returns true, print that the number is prime
    } else {
        cout << num << " is not prime."; // If isPrime returns false, print that the number is not prime
    }

    // Exit stage right!
    return 0; // End of main function
}

// Function to determine if the input number is prime
bool isPrime(int number) {
    if (number <= 1) return false; // Return false for numbers less than or equal to 1, as they are not prime
    for (int i = 2; i < number; i++) { // Loop from 2 to one less than the number
        if (number % i == 0) return false; // If number is divisible by any number other than 1 and itself, it's not prime
    }
    return true; // If not divisible by any numbers other than 1 and itself, it is prime
}
