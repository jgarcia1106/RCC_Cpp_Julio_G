/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 15, 2024, 7:30 PM
 * Purpose:  Calculate ISP Bill with Input Validation
 */

#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    char package;
    int hours;
    double bill;

    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;
    cin >> package >> hours;

    // Input validation for package
    if (package != 'A' && package != 'B' && package != 'C') {
        cout << "Invalid package! Please enter A, B, or C." << endl;
        return 1;
    }

    // Input validation for hours
    if (hours < 0 || hours > 744) {
        cout << "Invalid number of hours! Hours must be between 0 and 744." << endl;
        return 1;
    }

    switch(package) {
        case 'A':
            bill = 9.95;
            if (hours > 10) {
                bill += (hours - 10) * 2; // Additional rate per hour over 10 hours
            }
            break;
        case 'B':
            bill = 14.95;
            if (hours > 20) {
                bill += (hours - 20) * 1; // Additional rate per hour over 20 hours
            }
            break;
        case 'C':
            bill = 19.95; // Flat rate for unlimited hours
            break;
    }

    cout << fixed << setprecision(2); // Formatting output to two decimal places
    cout << "Bill = $ " << bill;

    return 0;
}
