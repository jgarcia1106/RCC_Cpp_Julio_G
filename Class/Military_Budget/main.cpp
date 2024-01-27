#include <iostream>
#include <iomanip> // For setting precision of the output

using namespace std;

int main() {
    // Declare the variables
    float milBdgt, fedBdgt, mlPrcnt;

    // Initialize the values
    milBdgt = 7.0e11f; // Military Budget = 700 Billion
    fedBdgt = 4.1e12f; // Federal Budget  = 4.1 Trillion

    // Calculate the military budget as a percentage of the federal budget
    mlPrcnt = (milBdgt / fedBdgt) * 100;

    // Set the precision for the output to two decimal places
    cout << fixed << setprecision(2);

    // Output the result
    cout << "The military budget as a percentage of the federal budget is: " << mlPrcnt << "%" << endl;

    return 0;
}
