/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 9, 2024, 2:00 AM
 * Purpose: Ocean Levels - Predict the rise in ocean levels after 5, 7, and 10 years
 */

//System Libraries
#include <iostream>  //Input-Output Library
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes

//Program-Execution Begins Here

int main(int argc, char** argv) {
    //Declare all variables
    double riseRate = 1.5; // Ocean level rise per year in millimeters

    //Calculating the rise in ocean levels
    double riseIn5Yrs = riseRate * 5;  // Rise in 5 years
    double riseIn7Yrs = riseRate * 7;  // Rise in 7 years
    double riseIn10Yrs = riseRate * 10; // Rise in 10 years

    //Display the output
    cout << "Rise in ocean level after 5 years: " << riseIn5Yrs << " millimeters" << endl;
    cout << "Rise in ocean level after 7 years: " << riseIn7Yrs << " millimeters" << endl;
    cout << "Rise in ocean level after 10 years: " << riseIn10Yrs << " millimeters" << endl;
    
    //Exit the Program
    return 0;
}
