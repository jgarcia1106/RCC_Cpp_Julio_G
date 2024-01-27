/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on January 13, 2024 2:00 PM 
 * Purpose:  Average of 5 test scores 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> // for fixed and setprecision
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables 
    double score1, score2, score3, score4, score5; // Variables for the scores
    double average; // Variable for the average
    
    //Set the random number seed
    
    // Asking for input
    cout << "Input 5 numbers to average.\n";
    cin >> score1 >> score2 >> score3 >> score4 >> score5;
    
    //Initialize or input i.e. set variable values
    average = (score1 + score2 + score3 + score4 + score5) / 5.0;

    //Map inputs -> outputs
    cout << fixed << setprecision(1); // Setting the precision to one decimal place
    
    //Display the outputs
    cout << "The average = " << average;
    //Exit stage right or left!
    return 0;
}