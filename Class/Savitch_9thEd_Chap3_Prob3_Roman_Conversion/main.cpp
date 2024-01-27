/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on January 15, 2024, 11:00 PM
 * Purpose: Roman Conversions
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
    
    //Declare all variables
    unsigned char n1,//number of 1's
                 n10,//number of 10's
                n100,//number of 100's
               n1000;//number of 1000's
    unsigned short x;//4 digit number between 1000, 3000
    string msg;     //Message
    
    //Initialize all variables
    cin>>x;


    //map inputs -> outputs 
    if(x<1000 || x>3000){
        msg=" is Out of Range!";
    }else{
        n1      = (x)%10;                
        n10     = (x/10)%10;         
        n100    = (x/100)%10;      
        n1000   = (x/1000);
        //Code for outputing Roman Numberal in the 1000's
        switch(n1000){
            case 3:msg+="M";
            case 2:msg+="M";
            case 1:msg+="M";
        };
        //Code for outputting Roman Numberal in the 100's
        msg += n100==9? "CM":
               n100==8? "DCCC":
               n100==7? "DCC":
               n100==6? "DC":
               n100==5? "D":
               n100==4? "CD":
               n100==3? "CCC":
               n100==2? "CC":
               n100==1? "C":"";
        //Code for outputting Roman Numerals in the 10's
        if(n10==9)msg+="XC";
        if(n10==8)msg+="LXXX";
        if(n10==7)msg+="LXX";
        if(n10==6)msg+="LX";
        if(n10==5)msg+="L";
        if(n10==4)msg+="XL";
        if(n10==3)msg+="XXX";
        if(n10==2)msg+="XX";
        if(n10==1)msg+="X";
        //code for outputting roman numerals in the 1's
        if(n1==9)msg+="IX";
        else if(n1==8)msg+="VIII";
        else if(n1==7)msg+="VII";
        else if(n1==6)msg+="VI";
        else if(n1==5)msg+="V";
        else if(n1==4)msg+="IV";
        else if(n1==3)msg+="III";
        else if(n1==2)msg+="II";
        else if(n1==1)msg+="I";
        
        //Add message wording
        msg = " is equal to " + msg;
               
    }
    
    
    
    //display the outputs 
    cout<<"Arabic to Roman numeral conversion."<<endl;
    cout<<"Input the integer to convert."<<endl;
    cout<<x<<msg;
    
    //Exit the Program
    return 0;
}

