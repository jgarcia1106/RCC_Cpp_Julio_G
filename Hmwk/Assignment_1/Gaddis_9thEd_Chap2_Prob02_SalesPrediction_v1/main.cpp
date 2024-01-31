/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 8, 2024, 9:00 PM
 * Purpose: Sales Prediction
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
    //Set a random seed
    
    //Declare all variables
    double totSale = 8.6e6; // East Coast Company's total sales in dollars
    double ecPerc = 0.58;   // East Coast division's percentage of total sales

    //Initialize all variables
    
    //Process or Map solutions
    double ecSale = totSale * ecPerc; // Calculation for East Coast sales
    
    //Display the output
    cout << fixed << setprecision(2); // Formatting the output to two decimal places
    cout << "The East Coast division will generate $";
    cout << ecSale << " in sales this year." << endl;
    
    //Exit the Program
    return 0;
}
