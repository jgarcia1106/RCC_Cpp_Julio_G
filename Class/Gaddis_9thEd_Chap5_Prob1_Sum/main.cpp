/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on January 16, 2024, 3:08 PM
 * Purpose:  Sum of Numbers from 1 to N
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
    int number, sum = 0;

    //Initialize or input i.e. set variable values
    //cout << "Enter a positive integer: ";
    cin >> number;

    //Map inputs -> outputs
    // Check if the entered number is positive
    if (number <= 0) {
        cout << "Please enter a positive integer.";
        return 1; // Exit the program with an error code
    }

    // Calculate the sum of all integers from 1 to the entered number
    for (int i = 1; i <= number; i++) {
        sum += i;
    }

    //Display the outputs
    cout << "Sum = " << sum;

    //Exit stage right or left!
    return 0;
}
