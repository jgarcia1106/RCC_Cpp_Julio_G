#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For random number generation and system clear

class GameConfig {
public:
    static const int maxLives; // Static variable for maximum lives
    // Add other game configuration settings as static members if needed

    static void displayConfig() {
        std::cout << "Maximum Lives: " << maxLives << std::endl;
        // Display other configurations if necessary
    }
};

// Initialize static members of GameConfig
const int GameConfig::maxLives = 3;

class Game {
private:
    const int brdWdth = 20;
    const int brdHght = 10;
    std::vector<std::string> gmBoard;
    int plyrX, plyrY;
    int score, lives;
    int ghstX, ghstY;

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

    void DispBrd() {
        system("clear"); // For Windows, use system("cls");
        for (const auto &row : gmBoard) {
            std::cout << row << std::endl;
        }
        std::cout << "Score: " << score << " Lives: " << lives << std::endl;
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
        }
    }

    void UpdGame() {
        // If 'P' moves onto a dot, increase score. This check is necessary before setting 'P' to the new position.
        if (gmBoard[plyrY][plyrX] == '.') score++;

        // Update 'P' to new position
        gmBoard[plyrY][plyrX] = 'P';

        // Check for collision with ghost
        if (plyrX == ghstX && plyrY == ghstY) {
            lives--;
            if (lives > 0) ResetPositions();
            else {
                // Clear 'P' from the board on game over to prevent it from rendering after death
                gmBoard[plyrY][plyrX] = '.';
            }
        }

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
};

int main() {
    // Optionally display the game configuration before starting
    GameConfig::displayConfig();

    Game pacManGame;
    pacManGame.Run();
    return 0;
}
