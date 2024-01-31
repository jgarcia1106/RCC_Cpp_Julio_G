/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 19, 2024, 3:00 PM
 * Purpose: Menu with Loops, Functions, and Problems. Assignment 4
 */

//System Libraries
#include <iostream>
#include <iomanip> // Include for setprecision
#include <limits> // For numeric limits
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only
const double LITERS_PER_GALLON = 0.264179;

// Function to compute miles per gallon
double computeMPG(double liters, double miles) {
    double gallons = liters * LITERS_PER_GALLON;
    return miles / gallons;
}

// Function to compute the rate of inflation
float computeInflationRate(float oldPrice, float currentPrice) {
    return ((currentPrice - oldPrice) / oldPrice) * 100.0f;
}

float estimateFutureCost(float currentPrice, float inflationRate, int years) {
    for (int i = 0; i < years; ++i) {
        currentPrice *= (1 + inflationRate / 100.0f);
    }
    return currentPrice;
}

float maxOfTwo(float a, float b) {
    return (a > b) ? a : b;
}

float maxOfThree(float a, float b, float c) {
    return max(maxOfTwo(a, b), c);
}

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
    nOpshun=10;//In this case we have 10 options
    do{
        //Display user choice
        cout<<"This is Assignment 4 Menu Program"<<endl;
        cout<<"Input the Problem Number to Run"<<endl;
        cout<<"1 -> Sum the Sequence"<<endl;
        cout<<"2 -> Payment in Pennies"<<endl;
        cout<<"3 -> Display the Largest and Smallest"<<endl;
        cout<<"4 -> Rectangle with same number of rows as columns"<<endl;
        cout<<"5 -> Display Diamond Pattern"<<endl;
        cout<<"6 -> MPG conversion Problem"<<endl;
        cout<<"7 -> Fuel Efficiency Problem"<<endl;
        cout<<"8 -> Rate of Inflation"<<endl;
        cout<<"9 -> Estimated Cost"<<endl;
        cout<<"10 -> Max of 2, then 3 parameters"<<endl;
        cout << "Any other key to exit" << endl;
        cin>>option;//Read in the option
         // Check if the input is within the valid range
        if (option < 1 || option > nOpshun) {
            cout << endl << "Exit Program" << endl << endl;
            break; // Exit the loop if the option is outside 1-10
        }
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
    }while(option<=nOpshun);
    
    //Exit the Program
    return 0;
}

void prob1(){
    // Sum the Sequence
    //Declare Variables
    int number, sum = 0;

    //Prompt for and Read in the number
    cout << "Enter a positive integer: ";
    cin >> number;

    //Map inputs -> outputs
    if (number <= 0) {
        cout << "Please enter a positive integer." << endl;
        return; // Exit the function
    }

    //Calculate the sum
    for (int i = 1; i <= number; i++) {
        sum += i;
    }

    //Display the outputs
    cout << "Sum = " << sum << endl;
}


void prob2(){
    //Payment in Pennies
    int days;
    double dailySalary = 0.01; // Salary for the first day in dollars
    double totalEarnings = 0.0;

    //Prompt for and Read in the number of days
    cout << "Enter the number of days: ";
    cin >> days;

    //Input Validation
    if (days < 1) {
        cout << "Number of days cannot be less than 1." << endl;
    } else {
        //Calculate total earnings
        for (int day = 1; day <= days; day++) {
            totalEarnings += dailySalary;
            dailySalary *= 2; // Double the salary for the next day
        }

        //Display the total earnings in dollars
        cout << fixed << setprecision(2); // format output to 2 decimal places
        cout << "Pay = $" << totalEarnings << endl;
    }
}

void prob3(){
    // Display the Largest and Smallest
    int num, largest, smallest;

    // Initialize largest and smallest
    largest = numeric_limits<int>::min(); // Smallest possible integer
    smallest = numeric_limits<int>::max(); // Largest possible integer

    cout << "Enter a series of integers (enter -99 to end):" << endl;
    while (true) {
        cin >> num;
        if (num == -99) break;

        if (num > largest) {
            largest = num;
        }

        if (num < smallest) {
            smallest = num;
        }
    }

    cout << "Smallest number in the series is " << smallest << endl;
    cout << "Largest  number in the series is " << largest << endl;
}

void prob4(){
    //Rectangle with same number of rows as columns
    int size;
    char rectangleChar;

    cout << "Enter a positive integer no greater than 15 for the size: ";
    cin >> size;
    cout << "Enter the character for the rectangle (e.g., X or Y): ";
    cin >> rectangleChar;

    if (size > 0 && size <= 15) {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                cout << rectangleChar;
            }
            if (row < size - 1) {
                cout << endl;
            }
        }
    } else {
        cout << "Invalid input. Size must be a positive integer no greater than 15." << endl;
    }
}

void prob5(){
    //Display the following pattern
    int n; // Variable to store the maximum number of '+' to display

    cout << "Enter the number of '+' symbols in the largest line: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                cout << "+";
            }
            cout << endl << endl;
        }

        for (int i = n; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                cout << "+";
            }
            if (i != 1) {
                cout << endl << endl;
            }
        }
    }
}

void prob6(){
    //MPG conversion Problem
    double liters, miles;
    char choice;

    do {
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> liters;
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles;

        double mpg = computeMPG(liters, miles);
        cout << fixed << setprecision(2);
        cout << "miles per gallon:" << endl;
        cout << mpg << endl;

        cout << "Again:" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << endl; // Adding a line break only if continuing
        }

    } while (choice == 'y' || choice == 'Y');
}


void prob7(){
    //Fuel Efficiency Problem
    double liters1, miles1, liters2, miles2;
    char choice;

    do {
        cout << "Car 1" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> liters1;
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles1;

        double mpg1 = computeMPG(liters1, miles1);
        cout << fixed << setprecision(2);
        cout << "miles per gallon: " << mpg1 << endl << endl;

        cout << "Car 2" << endl;
        cout << "Enter number of liters of gasoline:" << endl;
        cin >> liters2;
        cout << "Enter number of miles traveled:" << endl;
        cin >> miles2;

        double mpg2 = computeMPG(liters2, miles2);
        cout << "miles per gallon: " << mpg2 << endl << endl;

        if (mpg1 > mpg2) {
            cout << "Car 1 is more fuel efficient" << endl << endl;
        } else if (mpg2 > mpg1) {
            cout << "Car 2 is more fuel efficient" << endl << endl;
        } else {
            cout << "Both cars are equally fuel efficient" << endl << endl;
        }

        cout << "Again:" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << endl;
        }

    } while (choice == 'y' || choice == 'Y');
}

void prob8(){
    float oldPrice, currentPrice; 
    char choice;

    do {
        cout << "Enter current price:" << endl;
        cin >> currentPrice;
        cout << "Enter year-ago price:" << endl;
        cin >> oldPrice;

        float inflationRate = computeInflationRate(oldPrice, currentPrice);
        cout.precision(2);
        cout << fixed;
        cout << "Inflation rate: " << inflationRate << "%" << endl << endl;

        cout << "Again:" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << endl;
        }

    } while (choice == 'y' || choice == 'Y');
}

void prob9(){
    //Estimated Cost
    float oldPrice, currentPrice;
    char choice;

    do {
        cout << "Enter current price:" << endl;
        cin >> currentPrice;

        cout << "Enter year-ago price:" << endl;
        cin >> oldPrice;

        float inflationRate = computeInflationRate(oldPrice, currentPrice);
        cout.precision(2);
        cout << fixed;
        cout << "Inflation rate: " << inflationRate << "%" << endl << endl;

        float costInOneYear = estimateFutureCost(currentPrice, inflationRate, 1);
        cout << "Price in one year: $" << costInOneYear << endl;

        float costInTwoYears = estimateFutureCost(currentPrice, inflationRate, 2);
        cout << "Price in two year: $" << costInTwoYears << endl << endl;

        cout << "Again:" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << endl;
        }

    } while (choice == 'y' || choice == 'Y');
}

void prob10(){
    //Maximum of first 2 parameters then Maximum of 3 parameters
    float num1, num2, num3;

    cout << fixed << setprecision(1);

    cout << "Enter first number:" << endl;
    cin >> num1;

    cout << "Enter Second number:" << endl;
    cin >> num2;

    cout << "Enter third number:" << endl;
    cin >> num3;

    cout << "Largest number from two parameter function:" << endl;
    cout << maxOfTwo(num1, num2) << endl << endl;

    cout << "Largest number from three parameter function:" << endl;
    cout << maxOfThree(num1, num2, num3) << endl;
}