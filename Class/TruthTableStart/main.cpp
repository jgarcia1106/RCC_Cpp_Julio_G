/* 
 * File:   main.cpp
 * Author: Ninja G.
 * Created on January 3, 2024, 7:39 PM
 * Purpose: Template used to start all projects
 */

//System Libraries
#include <iostream> //Input-Output Library
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions7

//Function Prototypes

//Program-Execution Begins Here

#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned char option,//Option to choose from menu
                  nOpshun;//Number of options

    //The Process -> Map Inputs to Outputs
    nOpshun='8';//In this case we have 8 options
    do{
        //Display user choice
        cout<<"Choose from the options displayed"<<endl;
        cout<<"1 -> Question 1"<<endl;
        cout<<"2 -> Question 2"<<endl;
        cout<<"3 -> Question 3"<<endl;
        cout<<"etc....."<<endl;
        cin>>option;//Read in the option
        //Use a switch case to implement
        switch(option){
            case '1': { insert your problem here}cout<<endl<<endl;break;
            case '2': { insert your problem here}cout<<endl<<endl;break;
            case '3': { insert your problem here}cout<<endl<<endl;break;
             default:cout<<endl<<"Exit Program"<<endl<<endl;
        }
    }while(option<=nOpshun);

    //Exit the Program
    return 0;
}