/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 15, 2024, 10:00 AM
 * Purpose: Book Worm Program - Calculates points earned by customers
 *          of Serendipity Booksellers based on the number of books purchased.
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    int booksPurchased; // To store the number of books purchased
    int pointsEarned; // To store the number of points earned 
    
    // Prompt user for input
    cout << "Book Worm Points" << endl;
    cout << "Input the number of books purchased this month." << endl;
    cin >> booksPurchased; // Read the number of books from the user
    
     // Calculate points based on the number of books purchased
    if (booksPurchased == 0) {
        pointsEarned = 0; // No points for 0 books
    } else if (booksPurchased == 1) {
        pointsEarned = 5; // 5 points for 1 book
    } else if (booksPurchased == 2) {
        pointsEarned = 15; // 15 points for 2 books
    } else if (booksPurchased == 3) {
        pointsEarned = 30; // 30 points for 3 books
    } else {
        pointsEarned = 60;  // 60 points for 4 or more books
    }
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Books purchased =  " << booksPurchased << endl;
    cout << "Points earned   = " << pointsEarned;

    //Exit stage right or left!
    return 0;
}