/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on 1/14/2024, 11:00 AM
 * Purpose:  Calculate trigonometric functions for a given angle
 */

//System Libraries
#include <iostream>  // Input/Output Library for standard I/O
#include <cmath>     // Library for mathematical functions like sin, cos, tan
#include <iomanip>   // Library for output formatting (setprecision)

using namespace std;

// No Global Constants or Global Variables

// Function Prototypes - not used in this program

// Execution of program begins here
int main(int argc, char** argv) {
    // Variables
    float angDeg;  // Variable to store the angle in degrees
    float angRad;  // Variable to store the angle in radians

    // Asking the user to input an angle in degrees
    cout << "Calculate trig functions" << endl;
    cout << "Input the angle in degrees." << endl;
    cin >> angDeg; // Reading the angle from user input

    // Convert the angle from degrees to radians
    // M_PI is the constant representing pi, and radians = degrees * (pi/180)
    angRad = angDeg * (static_cast<float>(M_PI) / 180.0f);

    // Output formatting: set the decimal precision for the output to 4 places

    // Calculating and displaying the sine of the angle
    cout << "sin(" << angDeg << ") = ";
    cout << fixed << setprecision(4) << sin(angRad) << endl;
    
    // Reset to default formatting for the next input/output
    cout.unsetf(ios_base::fixed);
    cout << setprecision(6); // Default precision for scientific notation
    
    // Calculating and displaying the cosine of the angle
    cout << "cos(" << angDeg << ") = ";
    cout << fixed << setprecision(4) << cos(angRad) << endl;
    
    // Reset to default formatting for the next input/output
    cout.unsetf(ios_base::fixed);
    cout << setprecision(6); // Default precision for scientific notation
    
    // Calculating and displaying the tangent of the angle
    cout << "tan(" << angDeg << ") = ";
    cout << fixed << setprecision(4) << tan(angRad);


    // End of the program
    return 0;
}
