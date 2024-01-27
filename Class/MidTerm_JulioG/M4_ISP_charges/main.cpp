#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables for package type and hours used
    char packageType;
    double hoursUsed;

    // Prompt user for input
    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> packageType; // Read package type
    cin >> hoursUsed;   // Read hours used

    // Constants for package rates and additional hour rates
    const double PACKAGE_A_RATE = 16.99;
    const double PACKAGE_B_RATE = 26.99;
    const double PACKAGE_C_RATE = 36.99;
    const double ADDITIONAL_HOUR_RATE_A = 0.95;
    const double ADDITIONAL_HOUR_RATE_A_ABOVE_20 = 0.85;
    const double ADDITIONAL_HOUR_RATE_B = 0.74;
    const double ADDITIONAL_HOUR_RATE_B_ABOVE_30 = 0.64;

    // Convert package type to uppercase for consistency
    packageType = toupper(packageType);

    // Initialize variables for total cost and savings
    double totalCost = 0.0;
    double savings = 0.0;
    char bestPackage = packageType; // To track the best package for savings

    cout << fixed << setprecision(2); // Set decimal precision for output

    // Calculate total cost based on package type and hours used
    switch (packageType) {
        case 'A':
            totalCost = PACKAGE_A_RATE; // Base rate for package A
            // Calculate additional cost if hours exceed the base limit
            if (hoursUsed > 10) {
                if (hoursUsed <= 20) {
                    totalCost += (hoursUsed - 10) * ADDITIONAL_HOUR_RATE_A;
                } else {
                    totalCost += 10 * ADDITIONAL_HOUR_RATE_A + (hoursUsed - 20) * ADDITIONAL_HOUR_RATE_A_ABOVE_20;
                }
            }
            // Determine if switching to package B or C is cheaper
            if (totalCost > PACKAGE_B_RATE) {
                bestPackage = 'B';
                savings = totalCost - PACKAGE_B_RATE;
            }
            if (totalCost > PACKAGE_C_RATE) {
                bestPackage = 'C';
                savings = totalCost - PACKAGE_C_RATE;
            }
            break;

        case 'B':
            totalCost = PACKAGE_B_RATE; // Base rate for package B
            // Calculate additional cost for hours above base limit
            if (hoursUsed > 20) {
                if (hoursUsed <= 30) {
                    totalCost += (hoursUsed - 20) * ADDITIONAL_HOUR_RATE_B;
                } else {
                    totalCost += 10 * ADDITIONAL_HOUR_RATE_B + (hoursUsed - 30) * ADDITIONAL_HOUR_RATE_B_ABOVE_30;
                }
            }
            // Check if package C is a cheaper option
            if (totalCost > PACKAGE_C_RATE) {
                bestPackage = 'C';
                savings = totalCost - PACKAGE_C_RATE;
            }
            break;

        case 'C':
            totalCost = PACKAGE_C_RATE; // Fixed rate for unlimited package C
            break;

        default:
            cout << "Invalid package type entered." << endl;
            return 1; // Exit program with an error code
    }

    // Output the total cost, best package for savings, and the amount saved
    cout << "$" << totalCost << " " << bestPackage << " $" << savings << endl;

    return 0;
}
