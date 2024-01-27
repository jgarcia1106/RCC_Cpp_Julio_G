/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on 1/14/2024, 8:00 AM
 * Purpose:  Calorie Counter - Calculate calories based on cookies eaten
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
const float calPrCok = 75.0f; // Calories per cookie

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int ckEaten;     // Cookies eaten
    float totCal;    // Total calories

    //Initialize or input i.e. set variable values
    cout << "Calorie Counter\n";
    cout << "How many cookies did you eat?" << endl;
    cin >> ckEaten;

    //Map inputs -> outputs
    totCal = ckEaten * calPrCok;

    //Display the outputs
    cout << "You consumed " << static_cast<int>(totCal) << " calories.";

    //Exit stage right or left!
    return 0;
}
