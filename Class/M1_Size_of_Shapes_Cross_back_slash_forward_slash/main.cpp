/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 25, 2024, 6:30 PM
 * Purpose: Size of Shapes
 */

#include <iostream>
using namespace std;

void drawCross(unsigned short x) {
    for (int row = 0; row < x; ++row) {
        for (int col = 0; col < x; ++col) {
            if (row == col || col == (x - row - 1)) {
                cout << x - abs(x / 2 - row);
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void drawBackwardSlash(unsigned short x) {
    for (int row = 0; row < x; ++row) {
        for (int col = 0; col < x; ++col) {
            if (col == (x - row - 1)) {
                cout << x - row;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void drawForwardSlash(unsigned short x) {
    for (int row = 0; row < x; ++row) {
        for (int col = 0; col < x; ++col) {
            if (row == col) {
                cout << row + 1;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {
    unsigned short x;
    char shape; // f-> forward b->backward x->cross

    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> x >> shape;
    
    switch (shape) {
        case 'x':
            drawCross(x);
            break;
        case 'b':
            drawBackwardSlash(x);
            break;
        case 'f':
            drawForwardSlash(x);
            break;
        default:
            cout << "Invalid shape character!" << endl;
            break;
    }

    return 0;
}
