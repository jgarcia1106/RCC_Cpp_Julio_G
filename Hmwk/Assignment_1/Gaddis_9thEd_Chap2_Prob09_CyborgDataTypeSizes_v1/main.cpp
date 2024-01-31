/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 9, 2024, 5:00 AM
 * Purpose: Miles per Gallon - Calculate a car's fuel efficiency
 */

//System Libraries
#include <iostream>  //Input-Output Library
#include <iomanip>   // For setprecision
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes

//Program-Execution Begins Here

int main(int argc, char** argv) {
    //Declare all variables
    double miles = 375;    // Miles the car can travel
    double gallons = 15;   // Gallons of gas used

    //Calculating miles per gallon
    double mpg = miles / gallons; // MPG calculation

    //Display the output
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "The car gets " << mpg << " miles per gallon." << endl;
    
    //Exit the Program
    return 0;
}
