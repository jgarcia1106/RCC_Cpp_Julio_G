/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 9, 2024, 2:00 PM
 * Purpose: Fill even/odd vectors and transfer to 2-D array
 */

// Include necessary libraries
#include <iostream> //cin, cout
#include <vector>   //vectors<>
#include <iomanip>  //Format setw(), right
using namespace std;

const int COLMAX = 2; // Only 2 columns needed, even and odd

// Function Prototypes
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>, int[][COLMAX]);
void prntVec(vector<int>, vector<int>, int); // int n is the format setw(n)
void prntAry(const int[][COLMAX], int, int, int);

int main(int argc, char **argv) {
    const int ROW = 80;            // No more than 80 rows
    int array[ROW][COLMAX] = {};   // Really, just an 80x2 array, even vs. odd
    vector<int> even, odd;         // Declare even, odd vectors

    // Input data and place even in one vector odd in the other
    read(even, odd);

    // Now output the content of the vectors
    prntVec(even, odd, 10); // Input even, odd vectors with setw(10);

    // Copy the vectors into the 2-dimensional array
    copy(even, odd, array);

    // Now output the content of the array
    prntAry(array, even.size(), odd.size(), 10); // Same format as even/odd vectors

    return 0;
}

void read(vector<int> &even, vector<int> &odd) {
    int n, val;
    cout << "Input the number of integers to input." << endl;
    cin >> n;
    cout << "Input each number." << endl;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (val % 2 == 0) even.push_back(val); // Even values
        else odd.push_back(val); // Odd values
    }
}

void copy(vector<int> even, vector<int> odd, int arr[][COLMAX]) {
    int size = max(even.size(), odd.size());
    for (int i = 0; i < size; ++i) {
        arr[i][0] = i < even.size() ? even[i] : 0; // Fill even numbers or 0
        arr[i][1] = i < odd.size() ? odd[i] : 0;   // Fill odd numbers or 0
    }
}

void prntVec(vector<int> even, vector<int> odd, int n) {
    cout << "    Vector      Even       Odd" << endl;
    int size = max(even.size(), odd.size());
    for (int i = 0; i < size; ++i) {
        cout << setw(10) << " " // Adjusted to 19 spaces
             << setw(n) << (i < even.size() ? to_string(even[i]) : "")
             << setw(n+0) << (i < odd.size() ? to_string(odd[i]) : "") << endl;
    }
}

void prntAry(const int arr[][COLMAX], int evenSize, int oddSize, int n) {
    cout << "     Array      Even       Odd" << endl;
    for (int i = 0; i < max(evenSize, oddSize); ++i) {
        cout << setw(10) << " " // Adjusted to 19 spaces
             << setw(n) << (arr[i][0] != 0 ? to_string(arr[i][0]) : "")
             << setw(n+0) << (arr[i][1] != 0 ? to_string(arr[i][1]) : "") << endl;
    }
}
