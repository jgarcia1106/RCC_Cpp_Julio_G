/* 
 * File:   main.cpp
 * Author: Julio G. 
 * Created on: February 4, 2024, 2:40 PM
 * Purpose: Calculate Average and Standard Deviation with Specific Input
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//Function Prototypes
void init(float [], int); //Initialize the array with specific values
void print(float [], int, int); //Print the array
float avgX(float [], int); //Calculate the Average
float stdX(float [], int); //Calculate the standard deviation

//Execution Begins Here!
int main() {
    //Declare Variables
    const int SIZE = 20;
    float test[SIZE];
    
    //Initialize with specific values
    init(test, SIZE);
    
    //Display the outputs
   // print(test, SIZE, 5);
    cout << fixed << setprecision(7); // Format output for floating point precision
    cout << "The average            = " << avgX(test, SIZE) << endl;
    cout << "The standard deviation = " << stdX(test, SIZE) << endl;

    //Exit stage right or left!
    return 0;
}

//Initialize the array with values from 0 to 19
void init(float arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
}

//Print the array elements
void print(float arr[], int size, int perLine) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        cout << setw(10) << arr[i];
        if (++count % perLine == 0) cout << endl;
    }
    if (size % perLine != 0) cout << endl;
}

//Calculate the Average of the elements in the array
float avgX(float arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

//Calculate the standard deviation of the elements in the array
float stdX(float arr[], int size) {
    float mean = avgX(arr, size);
    float sumOfSquares = 0;
    for (int i = 0; i < size; ++i) {
        sumOfSquares += pow(arr[i] - mean, 2);
    }
    return sqrt(sumOfSquares / (size - 1));
}
