#include <iostream>
#include <iomanip> // For setting precision of the output

using namespace std;

int main() {
    // Declare the variables
    float milBdgt, fedBdgt, mlPrcnt;

    // Initialize the values with hypothetical 2021 figures
    milBdgt = 7.5e11f; // Military Budget for 2021 = 750 Billion (hypothetical)
    fedBdgt = 4.5e12f; // Federal Budget for 2021  = 4.5 Trillion (hypothetical)

    // Calculate the military budget as a percentage of the federal budget
    mlPrcnt = (milBdgt / fedBdgt) * 100;

    // Set the precision for the output to two decimal places
    cout << fixed << setprecision(2);

    // Output the result
    cout << "The military budget as a percentage of the federal budget for 2021 is: " << mlPrcnt << "%" << endl;

    return 0;
}
