/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 3, 2024, 11:00 AM
 * Purpose: Product Table
 * 
 * This program creates a multiplication table, similar to what you might see in a math class.
 * It's designed to help visualize the product (result of multiplication) of numbers 1 through 6.
 */

// Include necessary libraries
#include <iostream> // For input and output
#include <iomanip>  // For manipulating the output (like setting width)

int main() {
    // Introduction to the table
    std::cout << "Think of this as a Product/Muliplication Table\n";
    std::cout << "           C o l u m n s\n"; // This is the top header for columns
    std::cout << "     |   1   2   3   4   5   6\n"; // Numbers of the columns
    std::cout << "----------------------------------\n"; // A line to separate the header from the table

    // Start creating the table row by row
    for (int row = 1; row <= 6; ++row) {
        // Special labeling for each row. 'R', 'O', 'W', 'S' are added for rows 2 to 5.
        if (row == 1) std::cout << "   "; // First row doesn't have a letter
        else if (row == 2) std::cout << "R  "; // Second row starts with 'R'
        else if (row == 3) std::cout << "O  "; // Third row starts with 'O'
        else if (row == 4) std::cout << "W  "; // Fourth row starts with 'W'
        else if (row == 5) std::cout << "S  "; // Fifth row starts with 'S'
        else std::cout << "   "; // Sixth row doesn't have a letter

        std::cout << row << " |"; // This shows the row number and a divider

        // For each row, go through each column to calculate the product
        for (int col = 1; col <= 6; ++col) {
            int product = row * col; // The multiplication happens here
            // Print the product with proper spacing. If it's a single digit, add more space.
            if (product < 10) std::cout << "   " << product;
            else std::cout << "  " << product;
        }
        
        // After finishing a row, move to the next line to start the next row
        std::cout << "\n";
    }

    // Once the table is complete, end the program
    return 0;
}
