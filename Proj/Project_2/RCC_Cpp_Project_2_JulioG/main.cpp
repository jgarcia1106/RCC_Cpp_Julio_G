/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 9, 2024, 4:30 AM
 * Purpose: Game Development - Pac-Man v1.2
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For random number generation

// Global variables and constants
const int brdWdth = 20; // Width of the game board
const int brdHght = 10; // Height of the game board
std::vector<std::string> gmBoard(brdHght); // Game board represented as a 2D character vector
int plyrX, plyrY; // Player's position (x, y)
int score, lives; // Player's score and lives
int ghstX, ghstY; // Ghost's position (x, y)

// Function declarations
void InitGame(); // Initializes the game by setting up the board, player, and ghost
void DispBoard(); // Displays the current state of the game board
void GetInput(); // Gets player input to move Pac-Man
void UpdGame(); // Updates the game state based on player input and game logic
void ChkColl(); // Checks for collisions (currently unused)
void MvGhosts(); // Moves the ghost to a new position
bool ChkWL(); // Checks if the player has won or lost (currently stubbed out)
void EndGame(); // Ends the game and displays a message

int main() {
    InitGame(); // Start the game setup

    while (true) {
        DispBoard(); // show the current board
        GetInput(); // Get the player's move
        UpdGame(); // Update game state (move player and ghosts, check for win/loss)
        if (ChkWL()) { // Check if the game has ended
            break; // Properly exits the loop when lives are 0 
        }
    }

    EndGame();
    return 0;
}


void InitGame() {
    // Initialize the game board with walls and dots
    for (int i = 0; i < brdHght; ++i) {
        gmBoard[i] = std::string(brdWdth, ' '); // Fill the middle of the board with spaces
        if (i == 0 || i == brdHght - 1) {
            gmBoard[i] = std::string(brdWdth, '#'); // Create top and bottom walls
        } else {
            gmBoard[i][0] = gmBoard[i][brdWdth - 1] = '#'; // Create side walls
        }
    }

    // Place the player and ghost in initial positions
    plyrX = brdWdth / 2;
    plyrY = brdHght / 2;
    gmBoard[plyrY][plyrX] = 'P'; // 'P' represents the player

    score = 0; // Initialize score
    lives = 3; // Initialize lives
    
    // Fill the board with dots representing food
    for (int y = 1; y < brdHght - 1; ++y) {
        for (int x = 1; x < brdWdth - 1; ++x) {
            if (gmBoard[y][x] == ' ') {
                gmBoard[y][x] = '.'; // '.' represents food
            }
        }
    }

    // Place the ghost in its initial position
    ghstX = 1;
    ghstY = 1;
    gmBoard[ghstY][ghstX] = 'G'; // 'G' represents the ghost   
}

void DispBoard() {
    system("clear"); // Clear the console screen (use "cls" on Windows)

    // Print the game board
    for (int i = 0; i < brdHght; ++i) {
        std::cout << gmBoard[i] << std::endl;
    }

    // Display score and lives
    std::cout << "Score: " << score << " Lives: " << lives << std::endl;
}

void GetInput() {
    char input;
    std::cin >> input; // Read a character from the user

    // Move the player based on input (w,a,s,d)
    switch (input) {
        case 'w': plyrY = std::max(1, plyrY - 1); break; // Move up
        case 's': plyrY = std::min(brdHght - 2, plyrY + 1); break; // Move down
        case 'a': plyrX = std::max(1, plyrX - 1); break; // Move left
        case 'd': plyrX = std::min(brdWdth - 2, plyrX + 1); break; // Move right
    }
}

void UpdGame() {
    // Erase the player's previous position on the board
    for (int y = 1; y < brdHght - 1; ++y) {
        for (int x = 1; x < brdWdth - 1; ++x) {
            if (gmBoard[y][x] == 'P') {
                gmBoard[y][x] = ' ';
            }
        }
    }

    // Update score if the player collects a dot
    if (gmBoard[plyrY][plyrX] == '.') {
        score++;
    }

    // Place the player in the new position
    gmBoard[plyrY][plyrX] = 'P';

    // Check for collision with the ghost and update lives
    if (plyrX == ghstX && plyrY == ghstY) {
        lives--;
        // Reset player and ghost positions if lives are remaining
        if (lives > 0) {
            plyrX = brdWdth / 2;
            plyrY = brdHght / 2;
            ghstX = 1;
            ghstY = 1;
        }
    }

    // Move the ghost to a new position
    MvGhosts();

    // Check again for collision with the ghost after it moves
    if (plyrX == ghstX && plyrY == ghstY) {
        lives--;
        if (lives > 0) {
            plyrX = brdWdth / 2;
            plyrY = brdHght / 2;
            ghstX = 1;
            ghstY = 1;
        }
    }
}

void ChkColl() {
    // This function is intended for checking collisions, but it's currently unused.
    // You could implement detailed collision logic here, such as wall collision or special item collection.
}

void MvGhosts() {
    // Remove the ghost from its current position
    gmBoard[ghstY][ghstX] = ' ';

    // Randomly choose a direction for the ghost to move
    int direction = rand() % 4; // Generates a random number between 0 and 3
    switch (direction) {
        case 0: ghstY = std::max(1, ghstY - 1); break; // Move up
        case 1: ghstY = std::min(brdHght - 2, ghstY + 1); break; // Move down
        case 2: ghstX = std::max(1, ghstX - 1); break; // Move left
        case 3: ghstX = std::min(brdWdth - 2, ghstX + 1); break; // Move right
    }

    // Place the ghost in the new position, ensuring it doesn't overlap with walls
    if (gmBoard[ghstY][ghstX] == ' ' || gmBoard[ghstY][ghstX] == '.') {
        gmBoard[ghstY][ghstX] = 'G';
    }
}

bool ChkWL() {
    // Check for win/lose conditions
    if (lives <= 0) {
        return true; // Player has lost the game
    }
    // Additional conditions can be added here (e.g., all dots collected)

    return false; // Game continues
}

void EndGame() {
    // Display a message at the end of the game
    // This could include the player's final score and a message about winning or losing
    std::cout << "Game Over! Your score: " << score << std::endl;
    // Additional logic could be added here for high score tracking or replay prompt
}