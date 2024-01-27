/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 11, 2024, 12:30 PM
 * Purpose: 
 */

//System Libraries
#include <iostream> //Input-Output Library
using namespace std;

//User Libraries

//Global Constants - Math,Physics,Chemistry,Conversions7

//Function Prototypes

//Program-Execution Begins Here

int main(int argc, char** argv) {
    //Set a random seed
    srand(static_cast<unsigned int>(time(0)));
    
    
    //Declare all variables
    char grade;//Letter Grade
    char score;//0-100
    
    //Initialize all variables
    score=rand()%51+50;//[50-100]
    
    
    //Process or Map solutions
    grade=score>=90?'A':
          score>=80?'B':
          score>70?'C': 
          score>60?'D':'F';
    
    //Display the output
    cout<<"Score = "<<static_cast<int>(score)
            <<" gives Grade = "<<grade<<endl;
    //Exit the Program
    return 0;
}

