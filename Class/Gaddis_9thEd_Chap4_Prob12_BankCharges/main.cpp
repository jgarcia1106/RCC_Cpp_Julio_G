/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 15, 2024, 7:00 PM
 * Purpose:  Calculate and Display Bank's Service Fees
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //For setting precision
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float bal;    // beginningBalance -> bal
    int checks;   // numChecks -> checks
    const float mFee = 10.00;  // monthlyFee -> mFee
    float cFee = 0.0;  // checkFee -> cFee
    float lbFee = 0.0; // lowBalanceFee -> lbFee
    float newBal;      // newBalance -> newBal

    //Initialize or input i.e. set variable values
    cout << "Monthly Bank Fees" << endl;
    cout << "Input Current Bank Balance and Number of Checks" << endl;
    cin >> bal >> checks;

    // ... [middle part of the code remains unchanged, replace variable names accordingly] ...

    // Determine check fee rate
    if (checks < 20) {
        cFee = 0.10;
    } else if (checks < 40) {
        cFee = 0.08;
    } else if (checks < 60) {
        cFee = 0.06;
    } else {
        cFee = 0.04;
    }

    // Calculate the total check fee
    float totalCFee = checks * cFee; // totalCheckFee -> totalCFee

    // Check for low balance
    if (bal < 400.00) {
        lbFee = 15.00;
    }

    // Calculate the new balance
    newBal = bal - (mFee + totalCFee + lbFee);

    //Display the outputs
    cout << fixed << setprecision(2);
    cout << "Balance     $ " << setw(8) << bal << endl;
    cout << "Check Fee   $ " << setw(8) << totalCFee << endl;
    cout << "Monthly Fee $ " << setw(8) << mFee << endl;
    cout << "Low Balance $ " << setw(8) << lbFee << endl;
    cout << "New Balance $ " << setw(8) << newBal;

    //Exit stage right or left!
    return 0;
}
