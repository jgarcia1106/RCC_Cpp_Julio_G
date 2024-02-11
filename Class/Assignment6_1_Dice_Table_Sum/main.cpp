/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 2, 2024, 10 AM
 * Purpose: Dice Table Sum
 * 
 * This program generates and displays a table representing the sums
 * of dice rolls, simulating two dice that can each roll a value from 1 to 6.
 * It displays these sums in a 6x6 grid format, with row and column headings.
 */

// Include directives for input-output stream and set width manipulator
#include <iostream>
#include <iomanip> // Included for std::setw, which sets the width of the output

int main() {
    // Display the table header explaining the purpose of the table
    std::cout << "Think of this as the Sum of Dice Table\n";
    std::cout << "           C o l u m n s\n"; // Column heading
    std::cout << "     |   1   2   3   4   5   6\n"; // Numbers represent possible dice rolls
    std::cout << "----------------------------------\n"; // Separates headings from the table body

    // Loop through each row of the table
    for (int row = 1; row <= 6; ++row) {
        // Conditional statements to print special row labels 'R', 'O', 'W', 'S' for rows 2 to 5
        if (row == 1) std::cout << "   "; // Aligns with the first row without a label
        else if (row == 2) std::cout << "R  "; // Label for the second row
        else if (row == 3) std::cout << "O  "; // Label for the third row
        else if (row == 4) std::cout << "W  "; // Label for the fourth row
        else if (row == 5) std::cout << "S  "; // Label for the fifth row
        else std::cout << "   "; // Aligns with the last row without a label

        std::cout << row << " |"; // Prints the row number and starts the table row

        // Inner loop to fill each column in the current row
        for (int col = 1; col <= 6; ++col) {
            // Calculate and print the sum of the current row and column values
            // std::setw(4) ensures that each output is aligned by setting a field width of 4
            std::cout << std::setw(4) << row + col;
        }
        std::cout << "\n"; // End the current row and move to the next line
    }

    return 0; // Indicates successful completion of the program
}
