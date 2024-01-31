/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on 1/14/2024, 1:00 PM
 * Purpose:  Calculate new compensation following a pay increase
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Input/Output Manipulation Library
using namespace std;

//Global Constants, no Global Variables are allowed
const float PAY_INC = 0.076f; // Pay increase rate (7.6%)

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float oldSal;    // Old annual salary
    float retro;     // Retroactive pay for 6 months
    float newSal;    // New annual salary
    float newMon;    // New monthly salary

    //Initialize or input i.e. set variable values
    cout << "Input previous annual salary." << endl;
    cin >> oldSal;

    //Map inputs -> outputs
    retro = oldSal * PAY_INC / 2;  // Calculate retroactive pay for 6 months
    newSal = oldSal * (1 + PAY_INC);  // Calculate new annual salary
    newMon = newSal / 12;            // Calculate new monthly salary

    //Display the outputs with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Retroactive pay    = $  " << retro << endl;
    cout << "New annual salary  = $" << newSal << endl;
    cout << "New monthly salary = $ " << newMon;

    //Exit stage right or left!
    return 0;
}
