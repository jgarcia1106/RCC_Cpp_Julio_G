/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 2, 2024, 10 AM
 * Purpose: Dice Table Sum
 */

//System Libraries
#include <iostream>
#include <iomanip> // For std::setw to set the width of the output

int main() {
    // Display the table header
    std::cout << "Think of this as the Sum of Dice Table\n";
    std::cout << "           C o l u m n s\n";
    std::cout << "     |   1   2   3   4   5   6\n";
    std::cout << "----------------------------------\n";

    // Generate and display the table
    for (int row = 1; row <= 6; ++row) {
        // Handle the special row labels for 'ROWS'
        if (row == 1) std::cout << "   ";
        else if (row == 2) std::cout << "R  ";
        else if (row == 3) std::cout << "O  ";
        else if (row == 4) std::cout << "W  ";
        else if (row == 5) std::cout << "S  ";
        else std::cout << "   ";

        std::cout << row << " |";

        // Fill the table using nested loops
        for (int col = 1; col <= 6; ++col) {
            std::cout << std::setw(4) << row + col;
        }
        std::cout << "\n";
    }

    return 0;
}
