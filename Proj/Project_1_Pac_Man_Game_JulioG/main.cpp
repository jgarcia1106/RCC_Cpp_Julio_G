/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 20, 2024, 10:30 AM
 * Purpose: Game Development - Pac-Man
 */

//System Libraries
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Include at the top for rand()

// Define global variables and constants
const int BOARD_WIDTH = 20;
const int BOARD_HEIGHT = 10;
std::vector<std::string> gameBoard(BOARD_HEIGHT);
int playerX, playerY; // Player's position
int score, lives;
int ghostX, ghostY; // Ghost's position


// Function declarations
void InitializeGame();
void DisplayBoard();
void GetInput();
void UpdateGame();
void CheckCollision();
void MoveGhosts();
bool CheckWinLose();
void EndGame();

int main() {
    InitializeGame();

    while (true) {
        DisplayBoard();
        GetInput();
        UpdateGame();
        if (CheckWinLose()) {
            break;
        }
    }

    EndGame();
    return 0;
}

// Function definitions
void InitializeGame() {
    // Initialize game variables
    // Fill the game board with spaces and walls
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        gameBoard[i] = std::string(BOARD_WIDTH, ' '); // Empty space
        if (i == 0 || i == BOARD_HEIGHT - 1) {
            gameBoard[i] = std::string(BOARD_WIDTH, '#'); // Top and bottom walls
        } else {
            gameBoard[i][0] = gameBoard[i][BOARD_WIDTH - 1] = '#'; // Side walls
        }
    }

    // Initialize player position
    playerX = BOARD_WIDTH / 2;
    playerY = BOARD_HEIGHT / 2;
    gameBoard[playerY][playerX] = 'P'; // Representing Pac-Man as 'P'

    // Initialize score and lives
    score = 0;
    lives = 3;
    
    // Place pellets
    for (int y = 1; y < BOARD_HEIGHT - 1; ++y) {
        for (int x = 1; x < BOARD_WIDTH - 1; ++x) {
            if (gameBoard[y][x] == ' ') {
                gameBoard[y][x] = '.'; // Representing pellets with dots
            }
        }
    }

    // Make sure the initial position of Pac-Man doesn't have a pellet
    gameBoard[playerY][playerX] = 'P';

    // Initialize ghost position
    ghostX = 1; // Starting position of the ghost
    ghostY = 1;
    gameBoard[ghostY][ghostX] = 'G'; // Representing ghost as 'G'    
    
}

void DisplayBoard() {
    // Display the game board
    system("clear"); // For Linux/MacOS, use "cls" on Windows

    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        std::cout << gameBoard[i] << std::endl;
    }

    // Display score and lives
    std::cout << "Score: " << score << " Lives: " << lives << std::endl;
}

void GetInput() {
    // Get player input
    char input;
    std::cin >> input;

    switch (input) {
        case 'w': // Move up
            playerY = std::max(1, playerY - 1);
            break;
        case 's': // Move down
            playerY = std::min(BOARD_HEIGHT - 2, playerY + 1);
            break;
        case 'a': // Move left
            playerX = std::max(1, playerX - 1);
            break;
        case 'd': // Move right
            playerX = std::min(BOARD_WIDTH - 2, playerX + 1);
            break;
    }
}

void UpdateGame() {
    // Update the game state
    // Clear the previous player position
    for (int y = 1; y < BOARD_HEIGHT - 1; ++y) {
        for (int x = 1; x < BOARD_WIDTH - 1; ++x) {
            if (gameBoard[y][x] == 'P') {
                gameBoard[y][x] = ' '; // Replace with space
            }
        }
    }

    // Update the player's new position
    gameBoard[playerY][playerX] = 'P';
    
    // Check and update for pellet collection
    if (gameBoard[playerY][playerX] == '.') {
        score++; // Increase the score when a pellet is collected
    }

    // Update the player's new position
    gameBoard[playerY][playerX] = 'P';

    // Collision detection
    if (playerX == ghostX && playerY == ghostY) {
        lives--; // Lose a life if Pac-Man collides with a ghost
        if (lives > 0) {
            // Reset positions
            playerX = BOARD_WIDTH / 2;
            playerY = BOARD_HEIGHT / 2;
            ghostX = 1;
            ghostY = 1;
        }
    }
    
    // Move the Ghosts
    MoveGhosts();    

    // Collision detection
    if (playerX == ghostX && playerY == ghostY) {
        lives--; // Lose a life if Pac-Man collides with a ghost
        if (lives > 0) {
            // Reset positions
            playerX = BOARD_WIDTH / 2;
            playerY = BOARD_HEIGHT / 2;
            ghostX = 1;
            ghostY = 1;
        }
    }
}

void CheckCollision() {
    // Check for collisions
}

void MoveGhosts() {
    // Clear the previous ghost position
    gameBoard[ghostY][ghostX] = ' '; 

    // Randomly move the ghost
    int direction = rand() % 4;
    switch (direction) {
        case 0: ghostY = std::max(1, ghostY - 1); break; // Move up
        case 1: ghostY = std::min(BOARD_HEIGHT - 2, ghostY + 1); break; // Move down
        case 2: ghostX = std::max(1, ghostX - 1); break; // Move left
        case 3: ghostX = std::min(BOARD_WIDTH - 2, ghostX + 1); break; // Move right
    }

    // Update the ghost's new position
    if (gameBoard[ghostY][ghostX] == ' ' || gameBoard[ghostY][ghostX] == '.') {
        gameBoard[ghostY][ghostX] = 'G';
    }
}

bool CheckWinLose() {
    // Check if the player wins or loses
    return false;
}

void EndGame() {
    // Display end game message
}

