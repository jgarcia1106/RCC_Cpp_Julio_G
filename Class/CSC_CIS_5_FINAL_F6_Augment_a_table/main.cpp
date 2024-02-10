/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 8, 2024, 8:00 PM
 * Purpose:  Augment a table with row/column/grand sums
 */

// Include necessary libraries
#include <iostream>
#include <iomanip>
using namespace std;

const int COLMAX = 20;  // Adjusted as per requirement

void read(int arr[][COLMAX], int &rows, int &cols) {
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> rows >> cols;
    cout << "Now input the table." << endl;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }
}

void sum(const int arr[][COLMAX], int rows, int cols, int augArr[][COLMAX+1]) {
    for(int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for(int j = 0; j < cols; ++j) {
            augArr[i][j] = arr[i][j];
            rowSum += arr[i][j];
            augArr[rows][j] += arr[i][j];
        }
        augArr[i][cols] = rowSum;
        augArr[rows][cols] += rowSum;
    }
}

void print(const int (*arr)[COLMAX+1], int rows, int cols, int width, bool isAugmented) {
    for(int i = 0; i < rows + isAugmented; ++i) {
        for(int j = 0; j < cols + isAugmented; ++j) {
            cout << setw(width) << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    const int ROW = 20;
    int array[ROW][COLMAX] = {};
    int augArray[ROW+1][COLMAX+1] = {};
    int rows, cols;

    read(array, rows, cols);
    sum(array, rows, cols, augArray);

    cout << endl << "The Original Array" << endl;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << setw(10) << array[i][j];
        }
        cout << endl;
    }

    cout << endl << "The Augmented Array" << endl;
    print(augArray, rows, cols, 10, true);

    return 0;
}
