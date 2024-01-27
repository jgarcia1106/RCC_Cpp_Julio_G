/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 26, 2024, 11:40 AM
 * Purpose: Overtime
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables for pay rate and hours worked
    float payRate;
    unsigned short hrsWrkd;
    
    // Display instructions for the user
    cout << "Paycheck Calculation." << endl;
    cout << "Input payRate in $'s/hour and hours worked" << endl;
    
    // Read input values for pay rate and hours worked from the user
    cin >> payRate >> hrsWrkd;

    // Variable to store the calculated gross pay
    float grossPay = 0.0;

    // Check if hours worked are 20 or less (straight-time)
    if (hrsWrkd <= 20) {
        grossPay = hrsWrkd * payRate; // Calculate pay without overtime
    } 
    // Check if hours worked are between 21 and 40 (time and a half)
    else if (hrsWrkd <= 40) {
        grossPay = 20 * payRate; // Pay for first 20 hours at regular rate
        grossPay += (hrsWrkd - 20) * payRate * 1.5; // Pay for remaining hours at 1.5x rate
    } 
    // Hours worked are more than 40 (double time)
    else {
        grossPay = 20 * payRate; // Pay for first 20 hours at regular rate
        grossPay += 20 * payRate * 1.5; // Next 20 hours at 1.5x rate
        grossPay += (hrsWrkd - 40) * payRate * 2; // Hours over 40 at double rate
    }

    // Output the calculated gross pay
    cout << fixed << setprecision(2); // Set decimal precision for the output
    cout << "$" << grossPay << endl; // Display the gross pay

    return 0; // End of program
}