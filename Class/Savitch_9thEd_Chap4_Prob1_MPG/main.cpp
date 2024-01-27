/* 
 * File:   main.cpp
 * Author: Ninja G.
 * Created on January 19, 2024, 8:00 PM
 * Purpose: MPG conversion Problem
 */

#include <iostream>
#include <iomanip> // For setting precision
using namespace std;

// Global constant for the number of liters per gallon
const double LITERS_PER_GALLON = 0.264179;

// Function to compute miles per gallon
double computeMPG(double liters, double miles) {
    double gallons = liters * LITERS_PER_GALLON;
    return miles / gallons;
}

int main() {
    double liters, miles;
    char choice;

    do {
        // User inputs
        cout << "Enter number of liters of gasoline:" << endl;
        cout << endl;
        cin >> liters;
        cout << "Enter number of miles traveled:" << endl;
        cout << endl;
        cin >> miles;

        // Calculate and display MPG
        double mpg = computeMPG(liters, miles);
        cout << fixed << setprecision(2); // Set precision for decimal places
        cout << "miles per gallon:" << endl;
        cout << mpg << endl;

        // Check if the user wants to perform another calculation
        cout << "Again:" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << endl; // Adding a line break only if continuing
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

