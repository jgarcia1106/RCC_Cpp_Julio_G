/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 25, 2024, 7:39 PM
 * Purpose: Convert numeric dollars to English equivalent
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

// Function to convert a number less than 1000 to words
string convertToHundreds(int number) {
    // Arrays representing the words for ones and tens places
    string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                     "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string result = "";
    if (number >= 100) {  // Handle hundreds place
        result += ones[number / 100] + " Hundred ";
        number %= 100;  // Reduce the number to two digits
    }
    if (number >= 20) {  // Handle tens place for numbers 20 and above
        result += tens[number / 10] + " ";
        number %= 10;  // Reduce the number to one digit
    }
    if (number > 0) {  // Handle ones place (including numbers from 1 to 19)
        result += ones[number] + " ";
    }
    return result;
}

// Function to convert any number up to 3000 to words
string numberToWords(int number) {
    if (number == 0) return "Zero";

    string result = "";
    if (number >= 1000) {  // Handle thousands place
        result += convertToHundreds(number / 1000) + "Thousand ";
        number %= 1000;  // Reduce the number to three digits
    }
    result += convertToHundreds(number);  // Convert the remaining number
    return result;
}

int main() {
    // Prompt user for input
    cout << "Input an integer [1-3000] convert to an English Check value." << endl;
    
    int number;
    cin >> number;  // Read the input number

    // Check if the number is within the valid range
    if (number < 1 || number > 3000) {
        cout << "Number out of range. Please enter a number between 1 and 3000." << endl;
        return 1;  // Exit if number is out of range
    }

    // Convert the number to words
    string englishValue = numberToWords(number);
    // Output the English equivalent
    cout << englishValue << "and no/100's Dollars" << endl;

    return 0;  // End of the program
}
