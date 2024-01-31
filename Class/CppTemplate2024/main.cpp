/* 
 * File:   main.cpp
 * Author: Ninja G.
 * Created on January 3, 2024, 7:39 PM
 * Purpose: Template used to start all projects
 */

//System Libraries
#include <iostream>
#include <cmath> 
#include <iomanip> 

using namespace std;

// Function to calculate present value
float psntVal(float futureValue, float interestRate, int years) {
    return futureValue / pow((1 + interestRate), years);
}

int main() {
    float futureValue, interestRate;
    int years;

    cout << "This is a Present Value Computation" << endl;
    
    cout << "Input the Future Value in Dollars" << endl;
    cin >> futureValue;
    
    cout << "Input the Number of Years" << endl;
    cin >> years;

    cout << "Input the Interest Rate %/yr" << endl;
    cin >> interestRate;
    interestRate /= 100; // Convert percentage to decimal

    // Calculate present value
    float presentValue = psntVal(futureValue, interestRate, years);

    // Display the result
    cout << fixed << setprecision(2);
    cout << "The Present Value = $" << presentValue;

    return 0;
}

