/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on 1/14/2024, 12:00 PM
 * Purpose:  Dieters beware - Calculate the limit of Soda Pop Consumption
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float CNVLBSG = 45359.2f / 100; // Conversion lbs to grams

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float diWt,     // Desired Weight in lbs
          moMass,   // Mass of the Mouse in grams
          kiMass,   // Mass of sweetener that kills the mouse in grams
          coMass,   // Mass of a can of diet coke in grams
          swConc,   // Concentration of Sweetener in Coke Can
          wtKill,   // Calculated weight to kill a person in lbs
          gmKill,   // Same calculation converted to grams
          swCan;    // Amount of Sweetener in 1 Can of coke in grams
    int   nCans;    // Number of cans of coke required to kill the dieter

    //Initialize or input i.e. set variable values
    cout << "Program to calculate the limit of Soda Pop Consumption." << endl;
    cout << "Input the desired dieters weight in lbs." << endl;
    cin >> diWt;
    moMass = 35;
    kiMass = 5;
    coMass = 350;
    swConc = 0.001f;

    //Map inputs -> outputs
    wtKill = kiMass / moMass * diWt;  // Simple ratio, proportionality
    gmKill = wtKill * CNVLBSG;        // Conversion to mass
    swCan = coMass * swConc;          // Calculating the mass of sweetener in a Can
    nCans = static_cast<int>(gmKill / swCan);  // How many cans of coke to cause possible death
    
    //Display the outputs
    cout << "The maximum number of soda pop cans" << endl;
    cout << "which can be consumed is " << nCans << " cans";

    //Exit stage right or left!
    return 0;
}
