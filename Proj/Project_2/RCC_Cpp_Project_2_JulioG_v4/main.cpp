/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on February 9, 2024, 4:30 AM
 * Purpose: Game Development - Pac-Man v1.5
 */

#include <iostream> // For input and output
#include <vector> // For using dynamic arrays
#include <string> // For using text strings
#include <cstdlib> // For system clear
#include <fstream> // For file operations
#include <algorithm> // For sort

// Define a class for game configuration settings
class GameConfig {
public:
    static const int maxLives; // Static variable for maximum lives
    // Function to display game configuration
    static void displayConfig() {
        std::cout << "Maximum Lives: " << maxLives << std::endl;
    }
};

// Initialize static member of GameConfig to store maximum lives
const int GameConfig::maxLives = 3;
// Define the main game class
class Game {
private:
    // Game board dimensions
    const int brdWdth = 20;
    const int brdHght = 10;
    // The game board, represented as a vector of strings
    std::vector<std::string> gmBoard;
    int plyrX, plyrY;
    int score, lives;
    int ghstX, ghstY;
    // Static vector to store top 3 scores and file name for score
    static std::vector<int> topScores; // Static vector to store top 3 scores
    static const std::string scoreFileName; // File name to store the scores

public:
     // Constructor to initialize the game
    Game() : gmBoard(brdHght, std::string(brdWdth, ' ')), score(0), lives(GameConfig::maxLives), plyrX(brdWdth / 2), plyrY(brdHght / 2), ghstX(1), ghstY(1) {
        readTopScores(); // Load top scores from file
        IntGame(); // Initialize game board
    }
    // Initialize the game board with walls, player, and ghost
    void IntGame() {
        for (int i = 0; i < brdHght; ++i) {
            gmBoard[i] = std::string(brdWdth, ' ');
            if (i == 0 || i == brdHght - 1) gmBoard[i] = std::string(brdWdth, '#');
            else gmBoard[i][0] = gmBoard[i][brdWdth - 1] = '#';
        }
        gmBoard[plyrY][plyrX] = 'P';
        for (int y = 1; y < brdHght - 1; ++y) {
            for (int x = 1; x < brdWdth - 1; ++x) {
                if (gmBoard[y][x] == ' ') gmBoard[y][x] = '.';
            }
        }
        gmBoard[ghstY][ghstX] = 'G';
    }
    // Display the game board in the console
    void DispBrd() {
        system("clear"); // For Windows, use system("cls");
        for (const auto &row : gmBoard) {
            std::cout << row << std::endl;
        }
        // Display the current score and remaining live
        std::cout << "Score: " << score << " Lives: " << lives << std::endl;
    }
    // Get player input and update player position accordingly
    void GtInput() {
        char input;
        std::cin >> input;
        int oldX = plyrX, oldY = plyrY;
        switch (input) {
            case 'w': plyrY = std::max(1, plyrY - 1); break;
            case 's': plyrY = std::min(brdHght - 2, plyrY + 1); break;
            case 'a': plyrX = std::max(1, plyrX - 1); break;
            case 'd': plyrX = std::min(brdWdth - 2, plyrX + 1); break;
            case 'q': // Quit game
                std::cout << "Quitting game..." << std::endl;
                std::exit(0);
            default:
                std::cout << "Invalid input! Use WASD to move, Q to quit." << std::endl;
                return;
        }
        // If player moved, clear the old position
        if (oldX != plyrX || oldY != plyrY) {
            gmBoard[oldY][oldX] = '.';
        }
    }

        // Update the game state after each input
    void UpdGame() {
        if (gmBoard[plyrY][plyrX] == '.') score++;
        gmBoard[plyrY][plyrX] = 'P';
        // Check for collision with ghost
        if (plyrX == ghstX && plyrY == ghstY) {
            lives--; // Decrease lives
            if (lives > 0) ResetPositions(); // Reset positions if still alive
            else gmBoard[plyrY][plyrX] = '.';  // Clear player from board if dead
        }

        MvGhsts();
    }
    
    // Randomly move ghosts on the board
    void MvGhsts() {
        gmBoard[ghstY][ghstX] = ' '; // Clear old ghost position
        int direction = rand() % 4; // Choose a random direction
        // Update ghost position based on the chosen direction
        switch (direction) {
            case 0: ghstY = std::max(1, ghstY - 1); break;
            case 1: ghstY = std::min(brdHght - 2, ghstY + 1); break;
            case 2: ghstX = std::max(1, ghstX - 1); break;
            case 3: ghstX = std::min(brdWdth - 2, ghstX + 1); break;
        }
        gmBoard[ghstY][ghstX] = 'G'; // Place ghost at new position
    }
    // Check if the game is lost (no lives left)
    bool ChkWL() {
        return lives <= 0;
    }
    // End the game and display the final score
    void EndGame() {
        std::cout << "GAME OVER! Nice Try! Your score: " << score << std::endl;
        updateTopScores(score);
        displayTopScores();
    }

    void Run() {
        while (!ChkWL()) {
            DispBrd();
            GtInput();
            UpdGame();
        }
        EndGame();
    }

    void ResetPositions() {
        plyrX = brdWdth / 2;
        plyrY = brdHght / 2;
        ghstX = 1;
        ghstY = 1;
    }

    static void readTopScores() {
        topScores.clear();
        std::ifstream file(scoreFileName);
        int score;
        while (file >> score) {
            topScores.push_back(score);
        }
        file.close();
    }

    static void writeTopScores() {
        std::ofstream file(scoreFileName, std::ofstream::trunc);
        for (int score : topScores) {
            file << score << std::endl;
        }
        file.close();
    }

    static void updateTopScores(int newScore) {
        topScores.push_back(newScore);
        std::sort(topScores.begin(), topScores.end(), std::greater<int>());
        if (topScores.size() > 3) topScores.resize(3);
        writeTopScores();
    }

    static void displayTopScores() {
        std::cout << "Top Scores:\n";
        for (size_t i = 0; i < topScores.size(); ++i) {
            std::cout << i + 1 << ". " << topScores[i] << std::endl;
        }
    }
};

// Initialize static member
std::vector<int> Game::topScores;
const std::string Game::scoreFileName = "top_scores.txt";

int main() {
    GameConfig::displayConfig();
    Game pacManGame;
    pacManGame.Run();
    return 0;
}
