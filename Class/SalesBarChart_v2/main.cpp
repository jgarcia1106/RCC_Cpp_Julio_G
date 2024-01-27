/* 
 * File:   main.cpp
 * Author:  Julio G.
 * Created on January 18, 2024, 7:40s PM
 * Purpose: Template used to start all projects
 */

//System Libraries
#include <iostream>
#include <string>

int main() {
    const int STORES = 5;
    int sales[STORES];

    // Getting sales data from the user
    for (int i = 0; i < STORES; ++i) {
        std::cout << "Enter today's sales for store " << (i + 1) << ": ";
        std::cin >> sales[i];
    }

    std::cout << "\nSALES BAR CHART (Each * = $100)\n";

    // Generating and displaying the bar chart
    for (int i = 0; i < STORES; ++i) {
        std::cout << "Store " << (i + 1) << ": ";
        int numberOfAsterisks = sales[i] / 100;
        for (int j = 0; j < numberOfAsterisks; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
