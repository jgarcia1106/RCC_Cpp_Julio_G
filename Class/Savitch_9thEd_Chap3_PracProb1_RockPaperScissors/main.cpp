#include <iostream>
#include <cctype>  // For tolower or toupper functions
using namespace std;

// Function to determine the winner
string determineWinner(char player1, char player2) {
    if (player1 == player2) {
        return "Nobody wins.";
    }

    if ((player1 == 'r' && player2 == 's') || (player1 == 's' && player2 == 'p') || (player1 == 'p' && player2 == 'r')) {
        return "Player 1 wins!";
    } else {
        return "Player 2 wins!";
    }
}

// Function to display the winning reason
string winningReason(char winner, char loser) {
    if (winner == 'r' && loser == 's') return "Rock breaks scissors.";
    if (winner == 's' && loser == 'p') return "Scissors cut paper.";
    if (winner == 'p' && loser == 'r') return "Paper covers rock.";
    return "";
}

int main() {
    char player1, player2;

    // Display game instructions
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;

    // Input choices
    cin >> player1 >> player2;

    // Normalize inputs to lowercase
    player1 = tolower(player1);
    player2 = tolower(player2);

    // Determine and display the winner
    string winner = determineWinner(player1, player2);
    //cout << winner << endl;

    // Display the reason for the winning, if there's a winner
    if (winner != "Nobody wins.") {
        cout << winningReason(winner[7] == '1' ? player1 : player2, winner[7] == '1' ? player2 : player1);
    }

    return 0;
}
