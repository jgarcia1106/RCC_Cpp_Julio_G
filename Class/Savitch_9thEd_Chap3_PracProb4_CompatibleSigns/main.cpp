/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on January 15, 2024, 8:00 PM
 * Purpose:  Horoscope Program - Examines compatible astrological signs
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <map>       // Map library
#include <string>    // String library
#include <cctype>    // Character handling library
using namespace std;

//User Libraries - None

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - None

//Function Prototypes - None

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed - None needed for this program
    
    //Declare Variables
    map<string, string> signToElement; // Map of astrological signs to their elements
    string sign1, sign2;               // Astrological signs

    //Initialize or input i.e. set variable values
    signToElement = {
        {"Aries", "Fire"}, {"Leo", "Fire"}, {"Sagittarius", "Fire"},
        {"Taurus", "Earth"}, {"Virgo", "Earth"}, {"Capricorn", "Earth"},
        {"Gemini", "Air"}, {"Libra", "Air"}, {"Aquarius", "Air"},
        {"Cancer", "Water"}, {"Scorpio", "Water"}, {"Pisces", "Water"}
    };

    // Display instructions
    cout << "Horoscope Program which examines compatible signs." << endl;
    cout << "Input 2 signs." << endl;

    // Input two signs
    cin >> sign1 >> sign2;

    //Map inputs -> outputs
    // Normalize input to capitalize first letter (assuming the rest of the letters are lowercase)
    sign1[0] = toupper(sign1[0]);
    sign2[0] = toupper(sign2[0]);

    //Display the outputs
    if (signToElement[sign1] == signToElement[sign2]) {
        cout << sign1 << " and " << sign2 << " are compatible " << signToElement[sign1] << " signs.";
    } else {
        cout << sign1 << " and " << sign2 << " are not compatible signs.";
    }

    //Exit stage right or left!
    return 0;
}
