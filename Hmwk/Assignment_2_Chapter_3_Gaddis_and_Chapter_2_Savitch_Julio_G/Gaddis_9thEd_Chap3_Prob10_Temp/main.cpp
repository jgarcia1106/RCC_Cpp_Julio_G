/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on 1/14/2024, 10:00 AM
 * Purpose:  Temperature Converter - Convert Fahrenheit to Celsius
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Input/Output Manipulation Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float fahr;    // Fahrenheit temperature
    float cels;    // Celsius temperature

    //Initialize or input i.e. set variable values
    cout << "Temperature Converter" << endl;
    cout << "Input Degrees Fahrenheit" << endl;
    cin >> fahr;

    //Map inputs -> outputs
    cels = (fahr - 32.0f) * 5.0f / 9.0f;

    //Display the outputs
    cout << fixed << setprecision(1);
    cout << fahr << " Degrees Fahrenheit = " << cels << " Degrees Centigrade";

    //Exit stage right or left!
    return 0;
}
