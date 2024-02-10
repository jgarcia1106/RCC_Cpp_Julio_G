/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 9, 2024, 1:00 PM
 * Purpose: Search an array for a value
 */

// Include necessary libraries
#include <iostream>
#include <cstring>
using namespace std;

const int COLMAX = 80;

int read(char array[][COLMAX], int& rowDet);
void sort(char array[][COLMAX], int rowDet, int colDet, const char replace[], const char with[]);
void print(const char array[][COLMAX], int rowDet, int colDet);
int strcmp(char str1[], char str2[], const char replace[], const char with[]);

int main(int argc, char** argv) {
    const int ROW = 30;
    char array[ROW][COLMAX];
    int colIn, colDet, rowIn, rowDet;
    char replace[COLMAX], with[COLMAX];

    cout << "Modify the sort order by swapping these characters." << endl;
    cin >> replace;
    cout << "With the following characters" << endl;
    cin >> with;
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn;

    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array, rowDet);

    sort(array, rowDet, colDet, replace, with);
    cout << "The Sorted Array" << endl;
    print(array, rowDet, colDet);

    return 0;
}

int read(char array[][COLMAX], int& rowDet) {
    int colDet = 0;
    for (int i = 0; i < rowDet; i++) {
        cin >> array[i];
        int len = strlen(array[i]);
        if (len > colDet) {
            colDet = len;
        }
    }
    return colDet;
}

void sort(char array[][COLMAX], int rowDet, int colDet, const char replace[], const char with[]) {
    for (int i = 0; i < rowDet - 1; i++) {
        for (int j = 0; j < rowDet - i - 1; j++) {
            if (strcmp(array[j], array[j + 1], replace, with) > 0) {
                char temp[COLMAX];
                strcpy(temp, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], temp);
            }
        }
    }
}

void print(const char array[][COLMAX], int rowDet, int colDet) {
    for (int i = 0; i < rowDet; i++) {
        cout << array[i] << endl;
    }
}

int strcmp(char str1[], char str2[], const char replace[], const char with[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = str1[i], c2 = str2[i];
        for (int j = 0; replace[j] != '\0'; j++) {
            if (c1 == replace[j]) {
                c1 = with[j];
            }
            if (c2 == replace[j]) {
                c2 = with[j];
            }
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        i++;
    }
    return 0;
}
