#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For random number generation and system clear

class GameConfig {
public:
    static const int maxLives; // Static variable for maximum lives
    static void displayConfig(std::ostream& out = std::cout) {
        out << "Maximum Lives: " << maxLives << std::endl;
    }
};

const int GameConfig::maxLives = 3;

class Game {
private:
    const int brdWdth = 20;
    const int brdHght = 10;
    std::vector<std::string> gmBoard;
    int plyrX, plyrY;
    int score, lives;
    int ghstX, ghstY;
    std::vector<int> highScores = {250, 100, 150}; // Made-up high scores

public:
    Game() : gmBoard(brdHght, std::string(brdWdth, ' ')), score(0), lives(GameConfig::maxLives), plyrX(brdWdth / 2), plyrY(brdHght / 2), ghstX(1), ghstY(1) {
        IntGame();
    }

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

    void DispBrd(std::ostream& out = std::cout) {
        system("clear"); // For Windows, use system("cls");
        for (const auto& row : gmBoard) {
            out << row << std::endl;
        }
        out << "Score: " << score << " Lives: " << lives << std::endl;
    }

    void GtInput() {
        char input;
        std::cin >> input;
        int oldX = plyrX, oldY = plyrY; // Store old position
        switch (input) {
            case 'w': plyrY = std::max(1, plyrY - 1); break;
            case 's': plyrY = std::min(brdHght - 2, plyrY + 1); break;
            case 'a': plyrX = std::max(1, plyrX - 1); break;
            case 'd': plyrX = std::min(brdWdth - 2, plyrX + 1); break;
            case 'q': // Quit game
                std::cout << "Quitting game..." << std::endl;
                std::exit(0);
                break;
            default:
                std::cout << "Invalid input! Use WASD to move, Q to quit." << std::endl;
                return; // Do not clear 'P' or move if input is invalid
        }

        // Clear old position if 'P' actually moved
        if (oldX != plyrX || oldY != plyrY) {
            gmBoard[oldY][oldX] = '.'; // Replace the old position with a dot
            gmBoard[plyrY][plyrX] = 'P'; // Move 'P' to the new position
        }
    }

    void UpdGame() {
       // Check if 'P' is on a dot and eat the dot
       if (gmBoard[plyrY][plyrX] == '.') {
           score++; // Increment score because a dot is eaten
           gmBoard[plyrY][plyrX] = ' '; // Remove the dot by setting the space to empty
       }

       // Update 'P's position on the game board
       for (int y = 0; y < brdHght; ++y) {
           for (int x = 0; x < brdWdth; ++x) {
               if (gmBoard[y][x] == 'P') {
                   gmBoard[y][x] = ' '; // Clear 'P's old position
                   break; // Exit the loop once 'P's old position is cleared
               }
           }
       }
       gmBoard[plyrY][plyrX] = 'P'; // Place 'P' at the new position

       // Check for collisions with ghosts
       if (plyrX == ghstX && plyrY == ghstY) {
           lives--;
           if (lives > 0) {
               ResetPositions(); // Reset positions if lives are remaining
           }
       }

       // Possibly add ghost movement logic here
       MvGhsts();
   }

    void MvGhsts() {
        gmBoard[ghstY][ghstX] = ' ';
        int direction = rand() % 4;
        switch (direction) {
            case 0: ghstY = std::max(1, ghstY - 1); break;
            case 1: ghstY = std::min(brdHght - 2, ghstY + 1); break;
            case 2: ghstX = std::max(1, ghstX - 1); break;
            case 3: ghstX = std::min(brdWdth - 2, ghstX + 1); break;
        }
        gmBoard[ghstY][ghstX] = 'G';
    }

    bool ChkWL() {
        return lives <= 0;
    }

    void EndGame() {
        std::cout << "GAME OVER! Your score: " << score << std::endl;
        addScoreToHighScores(score);
        displayHighScores();
    }

    void ResetPositions(int difficulty = 1) {
        plyrX = brdWdth / 2;
        plyrY = brdHght / 2;
        ghstX = 1 + difficulty; // Example of using the defaulted argument
        ghstY = 1;
    }

    void bubbleSortHighScores() {
        bool swapped;
        do {
            swapped = false;
            for (size_t i = 1; i < highScores.size(); i++) {
                if (highScores[i - 1] < highScores[i]) {
                    std::swap(highScores[i - 1], highScores[i]);
                    swapped = true;
                }
            }
        } while (swapped);
    }

    void addScoreToHighScores(int newScore) {
        highScores.push_back(newScore);
        bubbleSortHighScores();
    }

    void displayHighScores(std::ostream& out = std::cout) {
        out << "High Scores:" << std::endl;
        for (const auto& score : highScores) {
            out << score << std::endl;
        }
    }

    void Run() {
        while (!ChkWL()) {
            DispBrd();
            GtInput();
            UpdGame();
        }
    }
};

int main() {
    GameConfig::displayConfig();
    Game pacManGame;
    pacManGame.Run();
    return 0;
}
