/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 8, 2024, 10:00 PM
 * Purpose: Sales Tax - Calculate total sales tax on a $95 purchase
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
    double purchse = 95.00;    // This is how much our purchase costs
    double stTax = 0.04;       // State tax is 4%
    double coTax = 0.02;       // County tax is 2%

    //Calculating the taxes
    double stTaxAmt = purchse * stTax; // Calculate state tax
    double coTaxAmt = purchse * coTax; // Calculate county tax
    double totTax = stTaxAmt + coTaxAmt; // Add both taxes for total

    //Display the output
    cout << fixed << setprecision(2); // Makes the output have 2 decimal places
    cout << "Total sales tax on a $95 purchase: $" << totTax << endl;
    
    //Exit the Program
    return 0;
}
