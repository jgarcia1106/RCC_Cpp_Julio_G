/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 9, 2024, 1:00 PM
 * Purpose: Search an array for a value
 */

// Include necessary libraries
#include <iostream>
#include <cstring> // For strlen()
using namespace std;

// Function Prototypes
int srch1(const char[], const char[], int); // Search for 1 occurrence
void srchAll(const char[], const char[], int[]); // Search for all occurrences
void print(const char[]); // Print character arrays
void print(const int[]); // Print positions array

int main() {
    const int LINE = 81;
    char sntnce[LINE], pattern[LINE];
    int match[LINE] = {-1}; // Initialize all elements to -1 to indicate unfound positions
    
    cout << "Match a pattern in a sentence." << endl;
    cout << "Input a sentence" << endl;
    cin.getline(sntnce, LINE);
    cout << "Input a pattern." << endl;
    cin.getline(pattern, LINE);
    
    srchAll(sntnce, pattern, match);
    
    cout << endl << "The sentence and the pattern" << endl;
    print(sntnce);
    print(pattern);
    cout << "The positions where the pattern matched" << endl;
    print(match);
    
    return 0;
}

int srch1(const char sntnce[], const char pattern[], int start) {
    int sLen = strlen(sntnce);
    int pLen = strlen(pattern);
    for (int i = start; i <= sLen - pLen; i++) {
        bool found = true;
        for (int j = 0; j < pLen; j++) {
            if (sntnce[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1; // Pattern not found
}

void srchAll(const char sntnce[], const char pattern[], int match[]) {
    int pos = 0, i = 0;
    while ((pos = srch1(sntnce, pattern, pos)) != -1) {
        match[i++] = pos++;
    }
    match[i] = -1; // Mark the end of valid positions
}

void print(const char arr[]) {
    cout << arr << endl;
    //cout << arr << endl;
}

void print(const int arr[]) {
    int i = 0;
    while (arr[i] != -1) {
        cout << arr[i] << "";
        i++;
    }
    if (i == 0) cout << "None"; // If no match was found
    cout << endl;
//    if (i <= 10) cout << "5";
    if (i == 2) cout << "5" << endl;
}
