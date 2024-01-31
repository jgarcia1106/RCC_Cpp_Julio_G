/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 13, 2024, 12:36 PM
 * Purpose:  Pacheck 
 *           
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float payRate, //Pay rate in $'s/hour
          hrsWrkd, //Hours worked
          grsPay; //Gross pay in $'s 
    //Initialize or input i.e. set variable values
    cin>>payRate>>hrsWrkd;
    //Map inputs -> outputs
    grsPay = payRate*hrsWrkd; //Straight Time
    grsPay += (hrsWrkd>40) ? payRate*(hrsWrkd-40):0; //Overtime hours > 40 get an extra amount 
    
    //Display the outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"This program calculates the gross paycheck."<<endl;
    cout<<"Input the pay rate in $'s/hr and the number of hours."<<endl;
    cout<<"Paycheck = $"<<setw(7)<<grsPay;

    //Exit stage right or left!
    return 0;
}