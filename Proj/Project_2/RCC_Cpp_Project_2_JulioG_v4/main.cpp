#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For random number generation and system clear

class Game {
private:
    const int brdWdth = 20;
    const int brdHght = 10;
    std::vector<std::string> gmBoard;
    int plyrX, plyrY;
    int score, lives;
    int ghstX, ghstY;

public:
    Game() : gmBoard(brdHght, std::string(brdWdth, ' ')), score(0), lives(3), plyrX(brdWdth / 2), plyrY(brdHght / 2), ghstX(1), ghstY(1) {
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
        switch (input) {
            case 'w': plyrY = std::max(1, plyrY - 1); break;
            case 's': plyrY = std::min(brdHght - 2, plyrY + 1); break;
            case 'a': plyrX = std::max(1, plyrX - 1); break;
            case 'd': plyrX = std::min(brdWdth - 2, plyrX + 1); break;
        }
    }

    void UpdGame() {
        if (gmBoard[plyrY][plyrX] == '.') score++;
        gmBoard[plyrY][plyrX] = 'P';
        if (plyrX == ghstX && plyrY == ghstY) {
            lives--;
            if (lives > 0) ResetPositions();
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
    Game pacManGame;
    pacManGame.Run();
    return 0;
}
