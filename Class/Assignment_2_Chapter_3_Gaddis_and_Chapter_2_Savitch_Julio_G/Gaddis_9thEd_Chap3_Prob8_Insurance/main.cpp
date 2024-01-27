/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on 1/14/2024, 9:00 AM
 * Purpose:  Insurance Calculator - Calculate the insurance needed based on house value
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float hseVal;   // House value
    float insNeed;  // Insurance Needed

    //Initialize or input i.e. set variable values
    cout << "Insurance Calculator\n";
    cout << "How much is your house worth?\n";
    cin >> hseVal; // Get house value from user

    //Map inputs -> outputs
    insNeed = hseVal * 0.8; // Calculate 80% of the house value

    //Display the outputs
    cout << "You need $" << insNeed << " of insurance.";

    //Exit stage right or left!
    return 0;
}
