/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 14, 2024, 2:00 PM
 * Purpose:  Positive and Negative Sums - Calculate the sum of positive and negative numbers separately
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Global Constants, no Global Variables are allowed
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int num;       // Input number
    int posSum,    // Sum of positive numbers
        negSum;    // Sum of negative numbers
    
    //Initialize Variables
    cout << "Input 10 numbers, any order, positive or negative" << endl;
    posSum = negSum = 0;
    
    //Map/Process the Inputs -> Outputs
    for (int i = 0; i < 10; ++i) {
        cin >> num;
        posSum += num > 0 ? num : 0;
        negSum += num < 0 ? num : 0;
    }
    
    //Display Inputs/Outputs
    cout << "Negative sum = " << negSum << endl;
    cout << "Positive sum =  " << posSum << endl;
    cout << "Total sum    =   " << posSum + negSum;
    
    //Exit the Program
    return 0;
}
