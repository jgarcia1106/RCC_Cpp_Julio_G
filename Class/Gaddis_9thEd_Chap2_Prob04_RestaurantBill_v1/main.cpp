/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 8, 2024, 11:00 PM
 * Purpose: Restaurant Bill - Calculate tax, tip, and total for a meal
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
    double mealCst = 88.67; // Cost of the meal
    double taxRate = 0.0675; // Tax rate (6.75%)
    double tipRate = 0.20; // Tip rate (20%)

    //Calculating tax and tip
    double taxAmt = mealCst * taxRate; // Calculate tax amount
    double totalIncTax = mealCst + taxAmt; // Total including tax
    double tipAmt = totalIncTax * tipRate; // Calculate tip amount
    double totalBill = totalIncTax + tipAmt; // Total bill amount

    //Display the output
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "Meal Cost: $" << mealCst << endl;
    cout << "Tax Amount: $" << taxAmt << endl;
    cout << "Tip Amount: $" << tipAmt << endl;
    cout << "Total Bill: $" << totalBill << endl;
    
    //Exit the Program
    return 0;
}
