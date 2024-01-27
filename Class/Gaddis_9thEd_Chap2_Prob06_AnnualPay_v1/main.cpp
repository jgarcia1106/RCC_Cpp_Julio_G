/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 9, 2024, 1:00 AM
 * Purpose: Annual Pay - Calculate the annual pay of an employee
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
    double payAmount = 5000.0; // Pay each period
    int payPeriods = 26;       // Number of pay periods in a year

    //Calculating annual pay
    double annualPay = payAmount * payPeriods; // Calculate total annual pay

    //Display the output
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "The total annual pay is: $" << annualPay << endl;
    
    //Exit the Program
    return 0;
}
