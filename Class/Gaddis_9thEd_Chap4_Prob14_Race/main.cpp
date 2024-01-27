/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 15, 2024, 10:00 PM
 * Purpose:  Race
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Input/Output Manipulation Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string runners[3];  // Runners' names
    short timings[3];   // Runners' times

    //Initialize or input i.e. set variable values
    cin >> runners[0] >> timings[0];
    cin >> runners[1] >> timings[1];
    cin >> runners[2] >> timings[2];

    //Map inputs -> outputs
    if (timings[0] > timings[1]) {
        swap(timings[0], timings[1]);
        swap(runners[0], runners[1]);
    }
    if (timings[1] > timings[2]) {
        swap(timings[1], timings[2]);
        swap(runners[1], runners[2]);
    }
    if (timings[0] > timings[1]) {
        swap(timings[0], timings[1]);
        swap(runners[0], runners[1]);
    }

    //Display the outputs
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    cout << runners[0] << "\t" << setw(3) << timings[0] << endl;
    cout << runners[1] << "\t" << setw(3) << timings[1] << endl;
    cout << runners[2] << "\t" << setw(3) << timings[2];

    //Exit stage right or left!
    return 0;
}
