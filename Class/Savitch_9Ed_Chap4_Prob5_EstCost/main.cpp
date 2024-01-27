/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 19, 2024, 10:50 PM
 * Purpose: Estimated Cost
 */

//System Libraries
#include <iostream> // Include the IO stream library for input and output operations
using namespace std; // Use the standard namespace

// Function to compute the rate of inflation
float computeInflationRate(float oldPrice, float currentPrice) {
    // Calculation: ((currentPrice - oldPrice) / oldPrice) * 100.0f
    // This formula computes the percentage increase from the old price to the current price
    return ((currentPrice - oldPrice) / oldPrice) * 100.0f;
}

// Function to estimate the future cost of an item
float estimateFutureCost(float currentPrice, float inflationRate, int years) {
    // Loop over the number of years, incrementing the current price by the inflation rate each year
    for (int i = 0; i < years; ++i) {
        currentPrice *= (1 + inflationRate / 100.0f); // Apply inflation rate to current price
    }
    return currentPrice; // Return the estimated future cost after the specified number of years
}

int main() {
    // Variables to store the old price, current price, and user's choice
    float oldPrice, currentPrice;
    char choice;

    do {
        // Prompt user to enter the current price of the item
        cout << "Enter current price:" << endl;
        cin >> currentPrice;

        // Prompt user to enter the price of the item one year ago
        cout << "Enter year-ago price:" << endl;
        cin >> oldPrice;

        // Calculate the inflation rate using the computeInflationRate function
        float inflationRate = computeInflationRate(oldPrice, currentPrice);
        cout.precision(2); // Set the number of decimal places for output
        cout << fixed; // Use fixed-point notation for floating-point output
        cout << "Inflation rate: " << inflationRate << "%" << endl << endl; // Display the inflation rate

        // Calculate and display the estimated future cost in one year
        float costInOneYear = estimateFutureCost(currentPrice, inflationRate, 1);
        cout << "Price in one year: $" << costInOneYear << endl;

        // Calculate and display the estimated future cost in two years
        float costInTwoYears = estimateFutureCost(currentPrice, inflationRate, 2);
        cout << "Price in two year: $" << costInTwoYears << endl << endl;

        // Ask the user if they want to perform the calculation again
        cout << "Again:" << endl;
        cin >> choice; // Read the user's choice

        // Add a line break if the user chooses to continue //This is the magic sauce :) 
        if (choice ==  'y' || choice == 'Y') {
            cout << endl;
        }

    } while (choice == 'y' || choice == 'Y'); // Repeat the loop if the user inputs 'y' or 'Y'

    return 0; // End of the program
}
