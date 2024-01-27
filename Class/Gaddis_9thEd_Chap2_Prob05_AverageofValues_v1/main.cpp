/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 5, 2024, 12:00 PM
 * Purpose: Average of Values - Calculate the average of five numbers
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
    double num1 = 28; // First number
    double num2 = 32; // Second number
    double num3 = 37; // Third number
    double num4 = 24; // Fourth number
    double num5 = 33; // Fifth number

    //Calculating the sum
    double sum = num1 + num2 + num3 + num4 + num5; // Sum of all numbers

    //Calculating the average
    double average = sum / 5; // Average of the numbers

    //Display the output
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "The average of the 5 numbers is: " << average << endl;
    
    //Exit the Program
    return 0;
}
