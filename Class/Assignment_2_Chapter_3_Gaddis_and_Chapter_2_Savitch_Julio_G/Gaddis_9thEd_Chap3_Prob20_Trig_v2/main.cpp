#include <iostream>
#include <math.h> // For sin, cos, tan, and M_PI
#include <iomanip> // For fixed and setprecision
using namespace std;

int main() {
    // Declare variable for angle
   float angle, angFix, sinA, cosA, tanA;

    // Prompt the user for an angle in degrees
    cout << "Calculate trig functions" << endl
         << "Input the angle in degrees." << endl;
    cin >> angle;
    angFix = angle * (M_PI / 180.0);
    
    // Map inputs -> outputs
    sinA = sin(angFix);
    cosA = cos(angFix);
    tanA = tan(angFix);


    // Calculate and display sine, cosine, and tangent of the angle
    cout << "sin(" << angle << ") = " << setprecision(4) << sinA << endl;
    cout << "cos(" << angle << ") = " << cosA << endl;
    cout << "tan(" << angle << ") = " << fixed << setprecision(4) << tanA;

    return 0;
}
