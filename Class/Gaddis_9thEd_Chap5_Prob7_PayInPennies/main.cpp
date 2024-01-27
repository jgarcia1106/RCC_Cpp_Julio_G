/* 
 * File:   main.cpp
 * Author: Ninja G.
 * Created on January 17, 2024, 9:50 AM
 * Purpose: Template used to start all projects
 */

//System Libraries
#include <iostream>
#include <iomanip> // for setprecision and fixed
using namespace std;

int main() {
    int days;
    double dailySalary = 0.01; // Salary for the first day in dollars
    double totalEarnings = 0.0;

    // Ask user for the number of days
    // cout << "Enter the number of days: "; // I'm having to comment this out. 
    cin >> days;

    // Input Validation
    if (days < 1) {
        cout << "Number of days cannot be less than 1." << endl;
    } else {
        // Calculate total earnings
        for (int day = 1; day <= days; day++) {
            totalEarnings += dailySalary;
            dailySalary *= 2; // Double the salary for the next day
        }

        // Display the total earnings in dollars
        cout << fixed << setprecision(2); // format output to 2 decimal places
        cout << "Pay = $" << totalEarnings;
    }

    return 0;
}
