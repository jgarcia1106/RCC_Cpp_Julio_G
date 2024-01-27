/* 
 * File:   main.cpp
 * Author: Ninja G.
 * Created on January 17, 2024, 9:00 AM
 * Purpose: Template used to start all projects
 */

//System Libraries
#include <iostream>
#include <limits> // For numeric limits
using namespace std;

int main() {
    int num, largest, smallest;

    // Initialize largest and smallest
    largest = numeric_limits<int>::min(); // Smallest possible integer
    smallest = numeric_limits<int>::max(); // Largest possible integer

    //cout << "Enter a series of integers "<<endl;
    while (true) {
        cin >> num;
        if (num == -99) break;

        if (num > largest) {
            largest = num;
        }

        if (num < smallest) {
            smallest = num;
        }
    }

    cout << "Smallest number in the series is " << smallest << endl;
    cout << "Largest  number in the series is " << largest;

    return 0;
}