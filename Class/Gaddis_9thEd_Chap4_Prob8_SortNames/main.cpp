/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on January 15, 2024, 5:00 PM
 * Purpose:  Sort three names entered by the user
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>    //Library for string objects
#include <algorithm> //Library for sort function
#include <array>     //Library for array container
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    array<string, 3> names; // Array to hold three names
    
    //Initialize or input i.e. set variable values
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    for (auto& name : names) {
        getline(cin, name); // Using getline to allow for names with spaces
    }
    
    //Sort the names
    sort(names.begin(), names.end());
    
    //Display the outputs
    for (size_t i = 0; i < names.size(); ++i) {
        cout << names[i];
        if (i < names.size() - 1)
    {
    cout << endl;
    }
    }
    //Exit stage right or left!
    return 0;
}
