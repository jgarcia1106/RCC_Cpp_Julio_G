/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 26, 2024, 6:30 PM
 * Purpose: Menu for Exam
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants Only!

//Function Prototypes
void Menu();
int  getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

// Function to convert a number less than 1000 to words
string convertToHundreds(int number) {
    // Arrays representing the words for ones and tens places
    string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                     "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string result = "";
    if (number >= 100) {  // Handle hundreds place
        result += ones[number / 100] + " Hundred ";
        number %= 100;  // Reduce the number to two digits
    }
    if (number >= 20) {  // Handle tens place for numbers 20 and above
        result += tens[number / 10] + " ";
        number %= 10;  // Reduce the number to one digit
    }
    if (number > 0) {  // Handle ones place (including numbers from 1 to 19)
        result += ones[number] + " ";
    }
    return result;
}

// Function to convert any number up to 3000 to words
string numberToWords(int number) {
    if (number == 0) return "Zero";

    string result = "";
    if (number >= 1000) {  // Handle thousands place
        result += convertToHundreds(number / 1000) + "Thousand ";
        number %= 1000;  // Reduce the number to three digits
    }
    result += convertToHundreds(number);  // Convert the remaining number
    return result;
}

void drawCross(unsigned short x) {
    for (int row = 0; row < x; ++row) {
        for (int col = 0; col < x; ++col) {
            if (row == col || col == (x - row - 1)) {
                cout << x - abs(x / 2 - row);
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void drawBackwardSlash(unsigned short x) {
    for (int row = 0; row < x; ++row) {
        for (int col = 0; col < x; ++col) {
            if (col == (x - row - 1)) {
                cout << x - row;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void drawForwardSlash(unsigned short x) {
    for (int row = 0; row < x; ++row) {
        for (int col = 0; col < x; ++col) {
            if (row == col) {
                cout << row + 1;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set a Random number seed here.
    
    //Declare Main variables here.
    int inN;
    
    //Loop on each problem
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
             default:cout<<endl<<"Typing 10 exits the program."<<endl;
	}
    }while(inN<7);

    //Exit Stage Right Here!
    return 0;
}

void Menu(){
    cout<<endl;
    cout<<"Type 1 to execute Problem 1"<<endl;
    cout<<"Type 2 to execute Problem 2"<<endl;
    cout<<"Type 3 to execute Problem 3"<<endl;
    cout<<"Type 4 to execute Problem 4"<<endl;
    cout<<"Type 5 to execute Problem 5"<<endl;
    cout<<"Type 6 to execute Problem 6"<<endl;
    cout<<"Type anything else to exit."<<endl<<endl;
}

int  getN(){
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN){
    cout<<endl<<"Typing "<<inN<<" exits the program."<<endl;
}

void problem1(){
    unsigned short x;
    char shape; // f-> forward b->backward x->cross

    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> x >> shape;
    
    switch (shape) {
        case 'x':
            drawCross(x);
            break;
        case 'b':
            drawBackwardSlash(x);
            break;
        case 'f':
            drawForwardSlash(x);
            break;
        default:
            cout << "Invalid shape character!" << endl;
            break;
    }    
}

void problem2(){
    // Declare all Variables Here
    char digit1, digit2, digit3, digit4;

    // Prompt the user for input
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> digit1 >> digit2 >> digit3 >> digit4;

    // Process each digit starting from the units place to the thousands place
    // For digit4 (units)
    if (isdigit(digit4)) {
        cout << digit4 << " ";
        for (int i = 0; i < digit4 - '0'; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        cout << digit4 << " ?" << endl;
    }

    // For digit3 (tens)
    if (isdigit(digit3)) {
        cout << digit3 << " ";
        for (int i = 0; i < digit3 - '0'; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        cout << digit3 << " ?" << endl;
    }

    // For digit2 (hundreds)
    if (isdigit(digit2)) {
        cout << digit2 << " ";
        for (int i = 0; i < digit2 - '0'; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        cout << digit2 << " ?" << endl;
    }

    // For digit1 (thousands)
    if (isdigit(digit1)) {
        cout << digit1 << " ";
        for (int i = 0; i < digit1 - '0'; i++) {
            cout << "*";
        }
        cout << endl;
    } else {
        cout << digit1 << " ?" << endl;
    }    
}

void problem3(){
    // Prompt user for input
    cout << "Input an integer [1-3000] convert to an English Check value." << endl;
    
    int number;
    cin >> number;  // Read the input number

    // Check if the number is within the valid range
    if (number < 1 || number > 3000) {
        cout << "Number out of range. Please enter a number between 1 and 3000." << endl;
   //     return 1;  // Exit if number is out of range
    }

    // Convert the number to words
    string englishValue = numberToWords(number);
    // Output the English equivalent
    cout << englishValue << "and no/100's Dollars" << endl;
}

void problem4(){
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
           // return 1; // Exit program with an error code
    }

    // Output the total cost, best package for savings, and the amount saved
    cout << "$" << totalCost << " " << bestPackage << " $" << savings << endl;
}

void problem5(){
    // Declare variables for pay rate and hours worked
    float payRate;
    unsigned short hrsWrkd;
    
    // Display instructions for the user
    cout << "Paycheck Calculation." << endl;
    cout << "Input payRate in $'s/hour and hours worked" << endl;
    
    // Read input values for pay rate and hours worked from the user
    cin >> payRate >> hrsWrkd;

    // Variable to store the calculated gross pay
    float grossPay = 0.0;

    // Check if hours worked are 20 or less (straight-time)
    if (hrsWrkd <= 20) {
        grossPay = hrsWrkd * payRate; // Calculate pay without overtime
    } 
    // Check if hours worked are between 21 and 40 (time and a half)
    else if (hrsWrkd <= 40) {
        grossPay = 20 * payRate; // Pay for first 20 hours at regular rate
        grossPay += (hrsWrkd - 20) * payRate * 1.5; // Pay for remaining hours at 1.5x rate
    } 
    // Hours worked are more than 40 (double time)
    else {
        grossPay = 20 * payRate; // Pay for first 20 hours at regular rate
        grossPay += 20 * payRate * 1.5; // Next 20 hours at 1.5x rate
        grossPay += (hrsWrkd - 40) * payRate * 2; // Hours over 40 at double rate
    }

    // Output the calculated gross pay
    cout << fixed << setprecision(2); // Set decimal precision for the output
    cout << "$" << grossPay << endl; // Display the gross pay
}

void problem6(){
    // Define variables
    double x, fx = 0, term; // x: input value, fx: calculated value of the series, term: individual term in the series
    int nterms; // nterms: number of terms in the series to calculate

    // Display purpose of the program
    cout << "Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!+.......\n";
    cout << "Input x and the number of terms, output f(x)\n";
    // Get user input for x and nterms
    cin >> x >> nterms;

    // Loop to calculate the sum of the series
    for (int i = 0; i < nterms; i++) {
        // Initialize xPower to calculate x raised to the power of (2i + 1)
        double xPower = 1; 
        for (int j = 1; j <= 2 * i + 1; j++) {
            xPower *= x; // Multiply x by itself j times
        }

        // Initialize factorial to calculate the factorial of (2i + 1)
        double factorial = 1;
        for (int j = 1; j <= 2 * i + 1; j++) {
            factorial *= j; // Multiply j by itself up to (2i + 1) times
        }

        // Calculate the term of the series and add/subtract it from fx
        term = xPower / factorial; // Calculate current term
        if (i % 2 == 1) {
            fx -= term; // Subtract the term from fx if i is odd
        } else {
            fx += term; // Add the term to fx if i is even
        }
    }

    // Output the final result of the series calculation
    cout << fixed << setprecision(6); // Set the precision of the output to 6 decimal places
    cout << fx << endl; // Display the calculated value of fx
}