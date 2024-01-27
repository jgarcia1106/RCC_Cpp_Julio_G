/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// User Libraries

// Global Constants

// Function Prototypes

// Execution Begins Here
int main(int argc, char** argv) {
    // Set the formatting for output
    cout << setfill('.'); // Set the fill character for the setw manipulator to '.'

    // Display formatted outputs
    for (int i = 1; i <= 4; ++i) {
        cout << left << setw(9) << i // Display the integer, aligned left
             << setw(5) << static_cast<float>(i) // Display as float with one decimal place
             << setw(9) << setprecision(2) << static_cast<double>(i) // Display as double with two decimal places
             << endl;
    }

    // Exit stage left
    return 0;
}
