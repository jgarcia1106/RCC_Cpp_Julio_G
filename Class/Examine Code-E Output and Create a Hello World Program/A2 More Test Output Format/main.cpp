/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 10, 2024, 10:30 PM
 * Purpose: Testing output
 */


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Declare variables
    int val1, val2, val3, val4;

    // Input data
    cin >> val1 >> val2 >> val3 >> val4;

    // Set up the formatting tools
    cout << fixed << showpoint;

    // Print the values as per the format in the expected output
    cout << setfill('.') << setw(9) << val1 << setw(10) << setprecision(1) << static_cast<float>(val1) << setw(10) << setprecision(2) << static_cast<double>(val1) << endl;
    cout << setfill('.') << setw(9) << val2 << setw(10) << setprecision(1) << static_cast<float>(val2) << setw(10) << setprecision(2) << static_cast<double>(val2) << endl;
    cout << setfill('.') << setw(9) << val3 << setw(10) << setprecision(1) << static_cast<float>(val3) << setw(10) << setprecision(2) << static_cast<double>(val3) << endl;
    cout << setfill('.') << setw(9) << val4 << setw(10) << setprecision(1) << static_cast<float>(val4) << setw(10) << setprecision(2) << static_cast<double>(val4);

    return 0;
}
