/* 
 * File:   main.cpp
 * Author: mlehr
 * Created on July 6th, 2023, 10:16 AM
 * Purpose:  Menu with Functions
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();
void prob10();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int option,//Option to choose from menu
        nOpshun;//Number of options
    
    //The Process -> Map Inputs to Outputs
    nOpshun=10;//In this case we have 3 options
    do{
        //Display user choice
        cout<<"Choose from the options displayed"<<endl;
        cout<<"1 -> Question 1"<<endl;
        cout<<"2 -> Question 2"<<endl;
        cout<<"3 -> Question 3"<<endl;
        cout<<"4 -> Question 4"<<endl;
        cout<<"5 -> Question 5"<<endl;
        cout<<"6 -> Question 6"<<endl;
        cout<<"7 -> Question 7"<<endl;
        cout<<"8 -> Question 8"<<endl;
        cout<<"9 -> Question 9"<<endl;
        cout<<"10 -> Question 10"<<endl;
        cout<<"etc....."<<endl;
        cin>>option;//Read in the option
        //Use a switch case to implement
        switch(option){
            case 1:prob1();break;
            case 2:prob2();break;
            case 3:prob3();break;
            case 4:prob4();break;
            case 5:prob5();break;
            case 6:prob6();break;
            case 7:prob7();break;
            case 8:prob8();break;
            case 9:prob9();break;
            case 10:prob10();break;
             default:cout<<endl<<"Exit Program"<<endl<<endl;
        }
    }while (option <= nOpshun && option > 0);
    
    //Exit the Program
    return 0;
}

void prob1(){
    cout<<endl<<"Question 1 Here"<<endl<<endl;
}

void prob2(){
    cout<<endl<<"Question 2 Here"<<endl<<endl;
}

void prob3(){
    cout<<endl<<"Question 3 Here"<<endl<<endl;
}

void prob4(){
    cout<<endl<<"Question 4 Here"<<endl<<endl;
}

void prob5(){
    cout<<endl<<"Question 5 Here"<<endl<<endl;
}

void prob6(){
    cout<<endl<<"Question 6 Here"<<endl<<endl;
}

void prob7(){
    cout<<endl<<"Question 7 Here"<<endl<<endl;
}

void prob8(){
    cout<<endl<<"Question 8 Here"<<endl<<endl;
}

void prob9(){
    cout<<endl<<"Question 9 Here"<<endl<<endl;
}

void prob10(){
    cout<<endl<<"Question 10 Here"<<endl<<endl;
}