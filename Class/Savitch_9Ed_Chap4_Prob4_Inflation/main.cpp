/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 19, 2024, 10:27 PM
 * Purpose: Rate of Inflation
 */

//System Libraries
#include <iostream> // Include the IO stream library for input and output operations
using namespace std; // Use the standard namespace

// Function to compute the rate of inflation
float computeInflationRate(float oldPrice, float currentPrice) {
    // Calculate the rate of inflation: difference in price divided by the old price, then multiplied by 100 to get a percentage
    return ((currentPrice - oldPrice) / oldPrice) * 100.0f;
}

int main() {
    float oldPrice, currentPrice; // Variables to store the old and current prices
    char choice; // Variable to store the user's choice to repeat the calculation

    do {
        // Prompt and read in the current price of the item
        cout << "Enter current price:" << endl;
        cin >> currentPrice;

        // Prompt and read in the price of the item one year ago
        cout << "Enter year-ago price:" << endl;
        cin >> oldPrice;

        // Calculate the inflation rate using the computeInflationRate function
        float inflationRate = computeInflationRate(oldPrice, currentPrice);

        // Set the number of digits to show after the decimal point for floating-point numbers
        cout.precision(2);
        cout << fixed; // Ensure that the precision setting affects the decimal portion only

        // Display the calculated inflation rate
        cout << "Inflation rate: " << inflationRate << "%" << endl << endl; // Display the inflation rate followed by a line break

        // Ask the user if they want to perform the calculation again
        cout << "Again:" << endl;
        cin >> choice; // Read the user's choice

        // Add a line break if the user chooses to continue
        if (choice == 'y' || choice == 'Y') {
            cout << endl;
        }

    } while (choice == 'y' || choice == 'Y'); // Continue looping as long as the user inputs 'y' or 'Y'

    return 0; // End of the program
}
