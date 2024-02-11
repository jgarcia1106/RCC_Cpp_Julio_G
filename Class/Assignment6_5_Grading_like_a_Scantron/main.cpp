/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 6, 2024, 5:00 PM
 * Purpose: Grading like a Scantron
 */

// Include directives tell the compiler to include information from the standard input/output library and the vector library.
#include <iostream> // Used for input/output operations.
#include <vector>   // Used for working with vectors, which are like dynamic arrays.

// This line makes it so we don't have to write "std::" before common commands like cout.
using namespace std;

// Function prototypes - these lines tell the compiler that we have some functions we'll define later.
// They describe how the functions look but not what they do (that comes later in the code).
void printResults(const vector<char>&, const string&);
int compareAnswers(const vector<char>& key, const vector<char>& answers, vector<char>& results);

// The main function - this is where our program starts running.
int main() {
    // Here, we're creating a list (vector) of correct answers (key) and student's answers (answers).
    // We also prepare a results vector to store whether each answer is correct (C) or wrong (W).
    vector<char> key = {'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'C', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D'};
    vector<char> answers = {'A', 'A', 'C', 'A', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B', 'B', 'D', 'A', 'B', 'C', 'D'};
    vector<char> results(key.size()); // We make sure the results vector is as long as the key to have a spot for each question's result.
    
    // Now, we compare the student's answers against the key to see how many are correct.
    // This function also fills in the results vector with 'C' for correct and 'W' for wrong.
    int correctAnswers = compareAnswers(key, answers, results);
    
    // Calculate the percentage of correct answers.
    // We multiply the number of correct answers by 100.0f (to get a percentage)
    // and divide by the total number of questions (size of the key vector).
    float percentageCorrect = 100.0f * correctAnswers / key.size();
    
    // Printing the results.
    // We print 'C' or 'W' for each question and the total percentage of correct answers.
    cout << "C/W     "; printResults(results, "");
    cout << "Percentage Correct = " << percentageCorrect << "%" << endl;

    // End of the main function.
    return 0;
}

// This function prints the results.
// It takes a list (vector) and a separator (we're not using it here, but you could put a space or comma between each character).
void printResults(const vector<char>& array, const string& separator) {
    for (char ch : array) { // Go through each character in the list.
        cout << ch << separator << ' '; // Print the character and the separator.
    }
    cout << endl; // End the line after printing all characters.
}

// This function compares the student's answers against the key.
// For each answer, it checks if it matches the key. If it does, 'C' is added to the results; if not, 'W' is.
// It also counts the number of correct answers to calculate the percentage later.
int compareAnswers(const vector<char>& key, const vector<char>& answers, vector<char>& results) {
    int correctCount = 0; // Start with zero correct answers.
    for (size_t i = 0; i < key.size(); ++i) { // Check each answer against the key.
        if (key[i] == answers[i]) { // If the answer matches the key...
            results[i] = 'C'; // Mark as Correct.
            ++correctCount; // Increase the count of correct answers.
        } else {
            results[i] = 'W'; // Mark as Wrong if it doesn't match.
        }
    }
    return correctCount; // Return the total number of correct answers.
}
