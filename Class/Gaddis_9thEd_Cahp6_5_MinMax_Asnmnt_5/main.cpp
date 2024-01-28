/* 
 * File:   main.cpp
 * Author: Julio G
 * Created on January 27, 2024, 9:00 AM
 * Purpose: MinMax
 */

//System Libraries
#include <iostream> // Includes the Standard Input/Output Stream Library
using namespace std; // This line allows us to use names from the std namespace without prefixing them with "std::"

// Function Prototypes
void minmax(int a, int b, int c, int &min, int &max); // Declaration of minmax function. It calculates min and max from three numbers

int main() {
    // Declare Variables
    int num1, num2, num3; // Variables to store the three numbers entered by the user
    int min, max; // Variables to store the minimum and maximum values

    // Input from user
    cout << "Input 3 numbers" << endl; // Prompting the user to input three numbers
    cin >> num1 >> num2 >> num3; // Reading the three numbers from the user and storing them in num1, num2, num3

    // Process
    minmax(num1, num2, num3, min, max); // Calling the minmax function to find the minimum and maximum of the three numbers

    // Output data
    cout << "Min = " << min << endl; // Displaying the minimum number
    cout << "Max = " << max; // Displaying the maximum number

    return 0; // Signifies successful completion of main function
}

// Function to find the min and max
void minmax(int a, int b, int c, int &min, int &max) {
    min = max = a; // Initialize min and max as the first number (a)

    // Compare second number (b) with current min and max
    if (b < min) min = b; // If b is smaller than current min, update min
    else if (b > max) max = b; // If b is larger than current max, update max

    // Compare third number (c) with current min and max
    if (c < min) min = c; // If c is smaller than current min, update min
    else if (c > max) max = c; // If c is larger than current max, update max
}
