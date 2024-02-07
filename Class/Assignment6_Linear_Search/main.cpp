/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 6, 2024, 6:00 PM
 * Purpose: Linear Search
 */

//System Libraries
// Including header files for input/output operations and to use vectors
#include <iostream> // Provides basic input and output services
#include <vector>   // Includes the vector container from the Standard Template Library (STL)

using namespace std; // This line allows us to use standard library objects without specifying the std:: prefix

// Function that performs a linear search on an array
// The function takes a vector of integers and an integer value to find as its parameters
int linearSearch(const vector<int>& arr, int value) {
    // Loop through each element in the array
    for (int i = 0; i < arr.size(); ++i) {
        // If the current element matches the value we're looking for...
        if (arr[i] == value) {
            // ...then return the index of that element.
            return i;
        }
    }
    // If we finish the loop without finding the value, return -1 to indicate it was not found
    return -1;
}

// The main function - starting point of the program
int main() {
    // A predefined array (vector) for demonstration purposes
    // This array will be searched to find a specific value
    vector<int> arr = {34, 45, 56, 67, 78, 89, 90, 23, 45, 56, 67, 78, 89, 50, 91, 92, 93, 94, 95, 96};
    int value = 50; // The value we're looking for in the array

    // Perform the linear search by calling the linearSearch function
    // The function returns the index of the found value, or -1 if not found
    int index = linearSearch(arr, value);

    // Check the result of the search
    if (index != -1) {
        // If the index is not -1, the value was found
        // Print the value and its index in the array
        cout << value << " was found at indx = " << index << endl;
    } else {
        // If the index is -1, the value was not found in the array
        cout << value << " was not found in the array." << endl;
    }

    // End of the program
    return 0;
}
