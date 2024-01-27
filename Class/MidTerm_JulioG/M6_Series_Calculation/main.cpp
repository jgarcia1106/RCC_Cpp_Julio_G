/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 26, 2024, 11:30 AM
 * Purpose: Series Calculation
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Define variables
    double x, fx = 0, term; // x: input value, fx: calculated value of the series, term: individual term in the series
    int nterms; // nterms: number of terms in the series to calculate

    // Display purpose of the program
    cout << "Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!+.......\n";
    cout << "Input x and the number of terms, output f(x)\n";
    // Get user input for x and nterms
    cin >> x >> nterms;

    // Loop to calculate the sum of the series
    for (int i = 0; i < nterms; i++) {
        // Initialize xPower to calculate x raised to the power of (2i + 1)
        double xPower = 1; 
        for (int j = 1; j <= 2 * i + 1; j++) {
            xPower *= x; // Multiply x by itself j times
        }

        // Initialize factorial to calculate the factorial of (2i + 1)
        double factorial = 1;
        for (int j = 1; j <= 2 * i + 1; j++) {
            factorial *= j; // Multiply j by itself up to (2i + 1) times
        }

        // Calculate the term of the series and add/subtract it from fx
        term = xPower / factorial; // Calculate current term
        if (i % 2 == 1) {
            fx -= term; // Subtract the term from fx if i is odd
        } else {
            fx += term; // Add the term to fx if i is even
        }
    }

    // Output the final result of the series calculation
    cout << fixed << setprecision(6); // Set the precision of the output to 6 decimal places
    cout << fx << endl; // Display the calculated value of fx

    return 0; // End program
}