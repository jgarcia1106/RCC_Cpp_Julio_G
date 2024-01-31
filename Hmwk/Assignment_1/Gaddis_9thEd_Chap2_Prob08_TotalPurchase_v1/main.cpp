/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 9, 2024, 3:00 AM
 * Purpose: Total Purchase - Calculate the total cost of five items including sales tax
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
    double item1 = 15.95; // Price of item 1
    double item2 = 24.95; // Price of item 2
    double item3 = 6.95;  // Price of item 3
    double item4 = 12.95; // Price of item 4
    double item5 = 3.95;  // Price of item 5
    double taxRate = 0.07; // Sales tax rate (7%)

    //Calculating subtotal and total
    double subtotal = item1 + item2 + item3 + item4 + item5; // Sum of all item prices
    double salesTax = subtotal * taxRate; // Calculate sales tax
    double total = subtotal + salesTax; // Total amount after adding sales tax

    //Display the output
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "Price of item 1: $" << item1 << endl;
    cout << "Price of item 2: $" << item2 << endl;
    cout << "Price of item 3: $" << item3 << endl;
    cout << "Price of item 4: $" << item4 << endl;
    cout << "Price of item 5: $" << item5 << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Total: $" << total << endl;
    
    //Exit the Program
    return 0;
}
