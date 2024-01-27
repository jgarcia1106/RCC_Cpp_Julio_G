/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 26, 2024, 10:00 AM
 * Purpose: M4 ISP Charges
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char packageType;
    double hoursUsed;

    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> packageType;
    cin >> hoursUsed;

    const double PACKAGE_A_RATE = 16.99;
    const double PACKAGE_B_RATE = 26.99;
    const double PACKAGE_C_RATE = 36.99;
    const double ADDITIONAL_HOUR_RATE_A = 0.95;
    const double ADDITIONAL_HOUR_RATE_A_ABOVE_20 = 0.85;
    const double ADDITIONAL_HOUR_RATE_B = 0.74;
    const double ADDITIONAL_HOUR_RATE_B_ABOVE_30 = 0.64;

    packageType = toupper(packageType);

    double totalCost = 0.0;
    double savings = 0.0;
    char bestPackage = packageType;

    cout << fixed << setprecision(2);

    switch (packageType) {
        case 'A':
            totalCost = PACKAGE_A_RATE;
            if (hoursUsed > 10) {
                if (hoursUsed <= 20) {
                    totalCost += (hoursUsed - 10) * ADDITIONAL_HOUR_RATE_A;
                } else {
                    totalCost += 10 * ADDITIONAL_HOUR_RATE_A + (hoursUsed - 20) * ADDITIONAL_HOUR_RATE_A_ABOVE_20;
                }
            }
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
            totalCost = PACKAGE_B_RATE;
            if (hoursUsed > 20) {
                if (hoursUsed <= 30) {
                    totalCost += (hoursUsed - 20) * ADDITIONAL_HOUR_RATE_B;
                } else {
                    totalCost += 10 * ADDITIONAL_HOUR_RATE_B + (hoursUsed - 30) * ADDITIONAL_HOUR_RATE_B_ABOVE_30;
                }
            }
            if (totalCost > PACKAGE_C_RATE) {
                bestPackage = 'C';
                savings = totalCost - PACKAGE_C_RATE;
            }
            break;

        case 'C':
            totalCost = PACKAGE_C_RATE;
            break;

        default:
            cout << "Invalid package type entered." << endl;
            return 1;
    }

    cout << "$" << totalCost << " " << bestPackage << " $" << savings << endl;

    return 0;
}
