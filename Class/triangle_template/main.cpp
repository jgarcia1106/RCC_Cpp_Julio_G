#include <iostream>

int main() {
    int rows = 4; // The pattern shows 4 rows
    
    // Calculate the maximum width of the triangle base
    int base_width = 2 * rows - 1;

    for(int i = 0; i < rows; ++i) {
        // Calculate the number of stars for the current row: 1, 3, 5, 7, ...
        int numStars = 2 * i + 1;
        
        // Calculate the number of spaces on each side of the stars
        int numSpaces = (base_width - numStars) / 2;
        
        // Print leading spaces
        for(int j = 0; j < numSpaces; ++j) {
            std::cout << " ";
        }
        
        // Print the stars for the current row
        for(int j = 0; j < numStars; ++j) {
            std::cout << "*";
        }
        
        // End the current row
        std::cout << std::endl;
    }

    return 0;
}
