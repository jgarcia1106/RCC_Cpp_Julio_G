/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 16, 2024, 8:40 PM
 * Purpose: Menu assignment 3
 */

#include <iostream>
#include <iomanip> // For setprecision and setw
#include <map>
#include <cctype> // For toupper
#include <algorithm> // Library for sort function
using namespace std;

// Function to determine the winner
string determineWinner(char player1, char player2) {
    // ... [determineWinner function code here] ...
}

// Function to display the winning reason
string winningReason(char winner, char loser) {
    // ... [winningReason function code here] ...
}

int main(int argc, char** argv) {
    unsigned char option, nOpshun;

    nOpshun = '8'; // 8 options on the menu

    do {
        cout << "Choose from the options displayed" << endl;
        cout << "1 -> SortNames" << endl;
        cout << "2 -> Book Worm" << endl;
        cout << "3 -> Bank Charges" << endl;
        cout << "4 -> Race" << endl;
        cout << "5 -> ISP" << endl;
        cout << "6 -> RockPaperScissors" << endl;
        cout << "7 -> Roman Conversions" << endl;
        cout << "8 -> CompatibleSigns" << endl;
        cout << "Any other key to exit" << endl;
        cin >> option;

        switch(option) {
            case '1': {
                // Sort Names
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
            case '2': {
                // Book Worm Points
                int booksPurchased; 
                int pointsEarned; 

                cout << "Book Worm Points" << endl;
                cout << "Input the number of books purchased this month." << endl;
                cin >> booksPurchased;

                if (booksPurchased == 0) {
                    pointsEarned = 0;
                } else if (booksPurchased == 1) {
                    pointsEarned = 5;
                } else if (booksPurchased == 2) {
                    pointsEarned = 15;
                } else if (booksPurchased == 3) {
                    pointsEarned = 30;
                } else {
                    pointsEarned = 60;
                }

                cout << "Books purchased =  " << booksPurchased << endl;
                cout << "Points earned   = " << pointsEarned << endl;
                break;
            }
            case '3': {
                // Monthly Bank Fees
                float bal;
                int checks;
                const float mFee = 10.00;
                float cFee = 0.0;
                float lbFee = 0.0;
                float newBal;

                cout << "Monthly Bank Fees" << endl;
                cout << "Input Current Bank Balance and Number of Checks" << endl;
                cin >> bal >> checks;

                if (checks < 20) {
                    cFee = 0.10;
                } else if (checks < 40) {
                    cFee = 0.08;
                } else if (checks < 60) {
                    cFee = 0.06;
                } else {
                    cFee = 0.04;
                }

                float totalCFee = checks * cFee;

                if (bal < 400.00) {
                    lbFee = 15.00;
                }
                newBal = bal - (mFee + totalCFee + lbFee);

                cout << fixed << setprecision(2);
                cout << "Balance     $ " << setw(8) << bal << endl;
                cout << "Check Fee   $ " << setw(8) << totalCFee << endl;
                cout << "Monthly Fee $ " << setw(8) << mFee << endl;
                cout << "Low Balance $ " << setw(8) << lbFee << endl;
                cout << "New Balance $ " << setw(8) << newBal << endl;
                break;
            }
            case '4': {
                // Race Ranking Program
                string runners[3];
                short timings[3];

                cout << "Race Ranking Program" << endl;
                cout << "Input 3 Runners" << endl;
                cout << "Their names, then their times" << endl;
                cin >> runners[0] >> timings[0];
                cin >> runners[1] >> timings[1];
                cin >> runners[2] >> timings[2];

                // Sorting
                if (timings[0] > timings[1]) {
                    swap(timings[0], timings[1]);
                    swap(runners[0], runners[1]);
                }
                if (timings[1] > timings[2]) {
                    swap(timings[1], timings[2]);
                    swap(runners[1], runners[2]);
                }
                if (timings[0] > timings[1]) {
                    swap(timings[0], timings[1]);
                    swap(runners[0], runners[1]);
                }

                // Display the outputs
                cout << runners[0] << "\t" << setw(3) << timings[0] << endl;
                cout << runners[1] << "\t" << setw(3) << timings[1] << endl;
                cout << runners[2] << "\t" << setw(3) << timings[2] << endl;
                break;
            }
            case '5': {
                // ISP Bill
                char package;
                int hours;
                double bill;

                cout << "ISP Bill" << endl;
                cout << "Input Package and Hours" << endl;
                cin >> package >> hours;

                if (package != 'A' && package != 'B' && package != 'C') {
                    cout << "Invalid package! Please enter A, B, or C." << endl;
                    return 1;
                }

                if (hours < 0 || hours > 744) {
                    cout << "Invalid number of hours! Hours must be between 0 and 744." << endl;
                    return 1;
                }

                switch(package) {
                    case 'A':
                        bill = 9.95;
                        if (hours > 10) {
                            bill += (hours - 10) * 2;
                        }
                        break;
                    case 'B':
                        bill = 14.95;
                        if (hours > 20) {
                            bill += (hours - 20) * 1;
                        }
                        break;
                    case 'C':
                        bill = 19.95; // Flat rate for unlimited hours
                        break;
                }

                cout << fixed << setprecision(2);
                cout << "Bill = $ " << bill << endl;
                break;
            }
            case '6': {
                // Rock Paper Scissors 
                char player1, player2;
                cout << "Rock Paper Scissors Game" << endl;
                cout << "Input Player 1 and Player 2 Choices" << endl;
                cin >> player1 >> player2;

                player1 = tolower(player1);
                player2 = tolower(player2);

                string winner = determineWinner(player1, player2);
                cout << winner << endl;
                if (winner != "Nobody wins.") {
                    cout << winningReason(winner[7] == '1' ? player1 : player2, winner[7] == '1' ? player2 : player1) << endl;
                }
                break;
            }
            case '7': {
                // Arabic to Roman Numeral Conversion
                unsigned char n1,//number of 1's
                             n10,//number of 10's
                            n100,//number of 100's
                           n1000;//number of 1000's
                unsigned short x;//4 digit number between 1000, 3000
                string msg;     //Message

                //Initialize all variables
                cin>>x;

                //map inputs -> outputs 
                if(x<1000 || x>3000){
                    msg=" is Out of Range!";
                }else{
                    n1      = (x)%10;                
                    n10     = (x/10)%10;         
                    n100    = (x/100)%10;      
                    n1000   = (x/1000);
                    //Code for outputing Roman Numberal in the 1000's
                    switch(n1000){
                        case 3:msg+="M";
                        case 2:msg+="M";
                        case 1:msg+="M";
                    };
                    //Code for outputting Roman Numberal in the 100's
                    msg += n100==9? "CM":
                           n100==8? "DCCC":
                           n100==7? "DCC":
                           n100==6? "DC":
                           n100==5? "D":
                           n100==4? "CD":
                           n100==3? "CCC":
                           n100==2? "CC":
                           n100==1? "C":"";
                    //Code for outputting Roman Numerals in the 10's
                    if(n10==9)msg+="XC";
                    if(n10==8)msg+="LXXX";
                    if(n10==7)msg+="LXX";
                    if(n10==6)msg+="LX";
                    if(n10==5)msg+="L";
                    if(n10==4)msg+="XL";
                    if(n10==3)msg+="XXX";
                    if(n10==2)msg+="XX";
                    if(n10==1)msg+="X";
                    //code for outputting roman numerals in the 1's
                    if(n1==9)msg+="IX";
                    else if(n1==8)msg+="VIII";
                    else if(n1==7)msg+="VII";
                    else if(n1==6)msg+="VI";
                    else if(n1==5)msg+="V";
                    else if(n1==4)msg+="IV";
                    else if(n1==3)msg+="III";
                    else if(n1==2)msg+="II";
                    else if(n1==1)msg+="I";

                    //Add message wording
                    msg = " is equal to " + msg;

                }

                //display the outputs 
                cout<<"Arabic to Roman numeral conversion."<<endl;
                cout<<"Input the integer to convert."<<endl;
                cout<<x<<msg;
                break;
            }
            case '8': {
                // Horoscope Compatibility
                map<string, string> signToElement;
                string sign1, sign2;

                signToElement = {
                    {"Aries", "Fire"}, {"Leo", "Fire"}, {"Sagittarius", "Fire"},
                    {"Taurus", "Earth"}, {"Virgo", "Earth"}, {"Capricorn", "Earth"},
                    {"Gemini", "Air"}, {"Libra", "Air"}, {"Aquarius", "Air"},
                    {"Cancer", "Water"}, {"Scorpio", "Water"}, {"Pisces", "Water"}
                };

                cout << "Horoscope Program which examines compatible signs." << endl;
                cout << "Input 2 signs." << endl;
                cin >> sign1 >> sign2;

                // Normalize input to capitalize first letter
                sign1[0] = toupper(sign1[0]);
                sign2[0] = toupper(sign2[0]);

                if (signToElement[sign1] == signToElement[sign2]) {
                    cout << sign1 << " and " << sign2 << " are compatible " << signToElement[sign1] << " signs." << endl;
                } else {
                    cout << sign1 << " and " << sign2 << " are not compatible signs." << endl;
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