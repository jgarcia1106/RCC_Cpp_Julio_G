/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 19, 2024, 10:00 PM
 * Purpose: Fuel Efficiency Problem
 */

//System Libraries
#include <iostream>  // Input-output library for reading and writing data
#include <iomanip>   // Library for manipulating the output (like setting precision)
using namespace std; // Standard namespace. Allows for use of cout, cin, etc.

// Global constant for the number of liters per gallon
const double LITERS_PER_GALLON = 0.264179; // Conversion factor from liters to gallons

// Function to compute miles per gallon
double computeMPG(double liters, double miles) {
    double gallons = liters * LITERS_PER_GALLON; // Convert liters to gallons
    return miles / gallons; // Calculate miles per gallon (MPG)
}

int main() {
    // Variables for storing user input
    double liters1, miles1, liters2, miles2; // Liters and miles for each car
    char choice; // Variable to store user's choice for repeating the calculation

    do {
        // Car 1 Input
        cout << "Car 1" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> liters1; // Read liters for Car 1
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles1; // Read miles for Car 1

        // Calculate and display MPG for Car 1
        double mpg1 = computeMPG(liters1, miles1); // Call function to calculate MPG
        cout << fixed << setprecision(2); // Set decimal precision for output
        cout << "miles per gallon: " << mpg1 << endl << endl; // Display MPG for Car 1

        // Car 2 Input
        cout << "Car 2" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> liters2; // Read liters for Car 2
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles2; // Read miles for Car 2

        // Calculate and display MPG for Car 2
        double mpg2 = computeMPG(liters2, miles2); // Call function to calculate MPG
        cout << "miles per gallon: " << mpg2 << endl << endl; // Display MPG for Car 2

        // Compare MPG and display which car is more fuel efficient
        if (mpg1 > mpg2) {
            cout << "Car 1 is more fuel efficient" << endl << endl;
        } else if (mpg2 > mpg1) {
            cout << "Car 2 is more fuel efficient" << endl << endl;
        } else {
            cout << "Both cars are equally fuel efficient" << endl << endl;
        }

        // Ask if the user wants to perform another calculation
        cout << "Again:" << endl;
        cin >> choice; // Read user's choice
        if (choice == 'y' || choice == 'Y') {
            cout << endl; // Adding a line break before starting the next cycle
        }

    } while (choice == 'y' || choice == 'Y'); // Repeat if user enters 'y' or 'Y'

    return 0; // End of program
}
