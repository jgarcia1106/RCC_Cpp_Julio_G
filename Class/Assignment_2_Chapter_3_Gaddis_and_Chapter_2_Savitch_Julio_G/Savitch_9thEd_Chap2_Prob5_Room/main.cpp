/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on January 14, 2024, 2:36 PM
 * Purpose:  Check room capacity against fire law regulations
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int maxCap;  // Maximum room capacity
    int numPpl;  // Number of people attending
    int diff;    // Difference in capacity and attendees

    //Initialize or input i.e. set variable values
    cout << "Input the maximum room capacity and the number of people" << endl;
    cin >> maxCap >> numPpl;

    //Map inputs -> outputs
    diff = maxCap - numPpl;

    //Display the outputs
    if (numPpl <= maxCap) {
        cout << "Meeting can be held." << endl;
        cout << "Increase number of people by " << diff << " to meet fire regulations.";
    } else {
        cout << "Meeting cannot be held." << endl;
        cout << "Reduce number of people by " << -diff << " to avoid fire violation.";
    }

    //Exit stage right or left!
    return 0;
}
