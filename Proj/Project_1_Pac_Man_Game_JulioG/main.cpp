/* 
 * File:   main.cpp
 * Author: Julio G.
 * Created on January 20, 2024, 10:30 AM
 * Purpose: Game Development - Pac-Man v1.0
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Global variables and constants
const int brdWdth = 20;
const int brdHght = 10;
std::vector<std::string> gmBoard(brdHght);
int plyrX, plyrY; // Player's position
int score, lives;
int ghstX, ghstY; // Ghost's position

// Function declarations
void InitGame();
void DispBoard();
void GetInput();
void UpdGame();
void ChkColl();
void MvGhosts();
bool ChkWL();
void EndGame();

int main() {
    InitGame();

    while (true) {
        DispBoard();
        GetInput();
        UpdGame();
        if (ChkWL()) {
            break;
        }
    }

    EndGame();
    return 0;
}

void InitGame() {
    for (int i = 0; i < brdHght; ++i) {
        gmBoard[i] = std::string(brdWdth, ' ');
        if (i == 0 || i == brdHght - 1) {
            gmBoard[i] = std::string(brdWdth, '#');
        } else {
            gmBoard[i][0] = gmBoard[i][brdWdth - 1] = '#';
        }
    }

    plyrX = brdWdth / 2;
    plyrY = brdHght / 2;
    gmBoard[plyrY][plyrX] = 'P';

    score = 0;
    lives = 3;
    
    for (int y = 1; y < brdHght - 1; ++y) {
        for (int x = 1; x < brdWdth - 1; ++x) {
            if (gmBoard[y][x] == ' ') {
                gmBoard[y][x] = '.';
            }
        }
    }

    gmBoard[plyrY][plyrX] = 'P';

    ghstX = 1;
    ghstY = 1;
    gmBoard[ghstY][ghstX] = 'G';    
}

void DispBoard() {
    system("clear");

    for (int i = 0; i < brdHght; ++i) {
        std::cout << gmBoard[i] << std::endl;
    }

    std::cout << "Score: " << score << " Lives: " << lives << std::endl;
}

void GetInput() {
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
    for (int y = 1; y < brdHght - 1; ++y) {
        for (int x = 1; x < brdWdth - 1; ++x) {
            if (gmBoard[y][x] == 'P') {
                gmBoard[y][x] = ' ';
            }
        }
    }

    if (gmBoard[plyrY][plyrX] == '.') {
        score++;
    }

    gmBoard[plyrY][plyrX] = 'P';

    if (plyrX == ghstX && plyrY == ghstY) {
        lives--;
        if (lives > 0) {
            plyrX = brdWdth / 2;
            plyrY = brdHght / 2;
            ghstX = 1;
            ghstY = 1;
        }
    }

    MvGhosts();

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
    // Collision checking logic
}

void MvGhosts() {
    gmBoard[ghstY][ghstX] = ' ';
    int direction = rand() % 4;
    switch (direction) {
        case 0: ghstY = std::max(1, ghstY - 1); break;
        case 1: ghstY = std::min(brdHght - 2, ghstY + 1); break;
        case 2: ghstX = std::max(1, ghstX - 1); break;
        case 3: ghstX = std::min(brdWdth - 2, ghstX + 1); break;
    }

    if (gmBoard[ghstY][ghstX] == ' ' || gmBoard[ghstY][ghstX] == '.') {
        gmBoard[ghstY][ghstX] = 'G';
    }
}

bool ChkWL() {
    // Win/Lose checking logic
    return false;
}

void EndGame() {
    // End game message
}
