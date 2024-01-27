#include <iostream>
#include <map>
#include <cctype> // For toupper
#include <array>
#include <algorithm> // For sort
using namespace std;

int main(int argc, char** argv) {
    unsigned char option, nOpshun;

    nOpshun = '8'; // 8 options now

    do {
        cout << "Choose from the options displayed" << endl;
        cout << "1 -> Simple Calculator" << endl;
        cout << "2 -> Check Even/Odd" << endl;
        cout << "3 -> Factorial Calculator" << endl;
        cout << "4 -> Horoscope Compatibility" << endl;
        cout << "5 -> Question 1" << endl;
        cout << "6 -> Question 2" << endl;
        cout << "7 -> Question 3" << endl;
        cout << "8 -> Sort Names" << endl;
        cout << "Any other key to exit" << endl;
        cin >> option;

        switch(option) {
            case '1': {
                // Simple Calculator Code Here
                break;
            }
            case '2': {
                // Check Even/Odd Code Here
                break;
            }
            case '3': {
                // Factorial Calculator Code Here
                break;
            }
            case '4': {
                // Horoscope Compatibility Code Here
                // [Horoscope Compatibility code goes here]
                break;
            }
            case '5': {
                // Question 1 Code Here
                break;
            }
            case '6': {
                // Question 2 Code Here
                break;
            }
            case '7': {
                // Question 3 Code Here
                break;
            }
            case '8': {
                // Sort Names Code Here
                array<string, 3> names; // Array to hold three names

                cout << "Sorting Names" << endl;
                cout << "Input 3 names" << endl;
                cin.ignore(); // Clearing buffer before reading names
                for (auto& name : names) {
                    getline(cin, name); // Using getline to allow for names with spaces
                }

                // Sort the names
                sort(names.begin(), names.end());

                // Display the outputs
                for (size_t i = 0; i < names.size(); ++i) {
                    cout << names[i];
                    if (i < names.size() - 1) {
                        cout << endl;
                    }
                }
                break;
            }
            default: 
                cout << endl << "Exit Program" << endl << endl; 
                return 0;
        }
    } while (option <= nOpshun);

    return 0;
}
