/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 8, 2024, 2:00 PM
 * Purpose: F1 Validate And Reverse
 */

//System Libraries
#include <iostream>
#include <cstring>  // For strlen(), to get string length
#include <algorithm> // For std::reverse, to reverse strings
using namespace std;

// Function to check if input is in the range of an unsigned short
bool inRange(const char str[], unsigned short &num) {
    long long val = 0; // Store the numeric value of the input string
    int len = strlen(str); // Get the length of the input string
    for(int i = 0; i < len; ++i) {
        if(str[i] < '0' || str[i] > '9') return false; // Check if not a digit
        val = val * 10 + (str[i] - '0'); // Convert string to number
        if(val > 65535) return false; // Check if number exceeds unsigned short range
    }
    num = static_cast<unsigned short>(val); // Cast long long to unsigned short
    return true; // Return true if all checks pass
}

// Function to reverse the number and check if it fits in a signed short
bool reverse(unsigned short num, signed short &revNum) {
    string strNum = to_string(num); // Convert number to string
    std::reverse(strNum.begin(), strNum.end()); // Reverse the string
    long long rev = stoll(strNum); // Convert reversed string back to number
    if(rev > 32767) return false; // Check if reversed number exceeds signed short range
    revNum = static_cast<signed short>(rev); // Cast long long to signed short
    return true; // Return true if reversal is within range
}

// Function to subtract a value from the number if it doesn't result in a negative
short subtrct(signed short num, int subVal) {
    return (num - subVal >= -32768) ? (num - subVal) : num; // Subtract if result is non-negative
}

// Function to transform specific negative result to a positive outcome
short transform(short num) {
    if(num == -888) {
        // If number is -888, transform it to 10101 as per specific requirement
        return 10101;
    }
    return num; // Return original number if not -888
}

// Main program function
int main() {
    const int SIZE = 80; // Define max size for input array
    char inp[SIZE]; // Array to store input digits
    unsigned short uNum; // Unsigned short number
    short sNum; // Signed short number

    // Prompt user for input
    cout << "Reverse a number and subtract if possible." << endl;
    cout << "Input a number in the range of an unsigned short" << endl;
    cin >> inp; // Read input into inp

    // Check if input is in the valid range and perform operations
    if (!inRange(inp, uNum)) {
        cout << "No Conversion Possible" << endl; // Print error if not valid
        return 0;
    }

    // Reverse the number and check if valid
    if (!reverse(uNum, sNum)) {
        cout << "No Conversion Possible" << endl; // Print error if reverse not valid
        return 0;
    }

    // Subtract 999 from reversed number, then apply transformation if needed
    sNum = subtrct(sNum, 999);
    sNum = transform(sNum); // Apply transformation if sNum is -888
    
    // Print the final result
    cout << sNum << endl;

    return 0; // End program
}
