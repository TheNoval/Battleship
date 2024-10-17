/*

*/
#ifdef __linux__
  #include <cursesw.h>
#endif
#ifdef _WIN32
  #include <ncurses/cursesw.h>
#endif

#include "board.h"
#include <iostream>
#include <array>
#include <string>
#include <cctype>

// Constructor definition
Board::Board() {
    for (auto& row : board) {
        for (auto& space : row) {
            space = '.';
        }
    }
}

// Function to display the board                // NOTE: This function could probably work more efficiently
void Board::displayUserBoard() const {          //       if "board" was a pointer that pointed to the array.
    for (int i = 0; i < 10; ++i) { // rows : y
        for (int j = 0; j < 10; ++j) { // columns : x
            // std::cout << board[i][j] << " ";
            mvprintw(i + 2, j*2 + 2, "%c", board[i][j]);
        }
    }
}

// Function to display the board for the opponent
// this function also returns board, but removes sight of ships that have not been hit
void Board::displayOpponentBoard() const {
    for (int i = 0; i < 10; ++i) { // rows : y
        for (int j = 0; j < 10; ++j) { // columns : x
            if (board[i][j] == '#') {
                // std::cout << ". ";
                mvprintw(i + 2, j*2 + 26, "."); // x is +22 from the user board
            } else {
                // std::cout << board[i][j] << " ";
                mvprintw(i + 2, j*2 + 26, "%c", board[i][j]);
            }
        }
    }
}

// Function to mark a hit on the board
bool Board::hitOnBoard(int y, int x) {
    // Check if the coordinates are within the board boundaries
    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        board[y][x] = 'X';  // Mark the hit
        return true;
    } else {
        return false;
    }
}

// Function to mark a miss on the board
bool Board::missOnBoard(int y, int x) {
    // Check if the coordinates are within the board boundaries
    if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        board[y][x] = 'O';  // Mark the miss
        return true;
    } else {
        return false;
    }
}

void Board::attackBoard(int row, int col) {
    if (board[row][col] == '#') {
        hitOnBoard(row, col);
    } else {
        missOnBoard(row, col);
    }
}

// In board function which checks that an input leads to a spot in the board & checks for ship overlays
bool Board::inBoard(int i, int j, char direction, char symbol) {
    if ((direction == 'w') && (boardCopy[i][j] == symbol) && (((i - 1) < 0) || (boardCopy[i-1][j] == '#'))) { return false; }
    else if ((direction == 'a') && (boardCopy[i][j] == symbol) && (((j - 1) < 0) || (boardCopy[i][j-1] == '#'))) { return false; }
    else if ((direction == 's') && (boardCopy[i][j] == symbol) && (((i + 1) > 9) || (boardCopy[i+1][j] == '#'))) { return false; }
    else if ((direction == 'd') && (boardCopy[i][j] == symbol) && (((j + 1) > 9) || (boardCopy[i][j+1] == '#'))) { return false; }
    else { return true; }
}

// Set ships function which puts the ships in the board
void Board::setShips(int size) {
    char symbol = 'T';
    char character;
    char orientation;
    mvprintw(1, 1, "                                                                 "); // overwrites previous stuff
    mvprintw(1, 1, "Start your ship horizontal or vertical (h/v): ");
    refresh();

    do {
        orientation = getch();
    } while ((orientation != 'h') && (orientation != 'v') && (orientation != 'H') && (orientation != 'V'));
    clear();
    refresh();
    // std::cin >> orientation;
    // while ((orientation != "h") || (orientation != "v")) {
    //     std::cout << "Invalid choice. Please select 'h' or 'v': ";
    //     std::cin >> orientation;
    // }
    if (orientation == 'h') {
        for (int j = 0; j < size; ++j) {
            board[0][j] = symbol;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            board[i][0] = symbol;
        }
    }
    do {
        clear();
        displayUserBoard();
        mvprintw(1, 1, "Use WASD to move ship, press Q to finalize placement.");
        bool moveable = true;
        character = getch();
        refresh();
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                boardCopy[i][j] = board[i][j];
            }
        }
        if (character == 'w') {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (boardCopy[i][j] == symbol && ((i - 1) < 0 || boardCopy[i-1][j] == '#')) {
                        moveable = false;
                    }
                }
            }
        } else if (character == 'a') {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (boardCopy[i][j] == symbol && ((j - 1) < 0 || boardCopy[i][j-1] == '#')) {
                        moveable = false;
                    }
                }
            }
        } else if (character == 's') {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (boardCopy[i][j] == symbol && ((i + 1) > 9 || boardCopy[i+1][j] == '#')) {
                        moveable = false;
                    }
                }
            }
        } else if (character == 'd') {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (boardCopy[i][j] == symbol && ((j + 1) > 9 || boardCopy[i][j+1] == '#')) {
                        moveable = false;
                    }
                }
            }
        }
        if (moveable == false) {
            continue;
        }
        if (character == 'w' || character == 'a') {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    switch(character) {
                        case 'w': // Moves this ship up
                            if (inBoard(i, j, character, symbol)) {
                                if (boardCopy[i][j] ==  symbol) {
                                    board[i-1][j] = symbol;
                                    board[i][j] = '.';
                                }
                            }
                            break;
                        case 'a': // Moves the ship left
                            if (inBoard(i, j, character, symbol)) {
                                if (boardCopy[i][j] ==  symbol) {
                                    board[i][j-1] = symbol;
                                    board[i][j] = '.';
                                }
                            }
                            break;
                    }
                }
            }
        } else if (character == 's' || character == 'd') { 
            for (int i = 9; i >= 0; --i) {
                for (int j = 9; j >= 0; --j) {
                    switch(character) {
                        case 's': // Moves the ship down
                            if (inBoard(i, j, character, symbol)) {
                                if (boardCopy[i][j] ==  symbol) {
                                    board[i+1][j] = symbol;
                                    board[i][j] = '.';
                                }
                            }
                            break;
                        case 'd': // Moves the ship right
                            if (inBoard(i, j, character, symbol)) {
                                if (boardCopy[i][j] ==  symbol) {
                                    board[i][j+1] = symbol;
                                    board[i][j] = '.';
                                }
                            }
                            break;
                    }
                }
            }
        } else if (character == 'q') {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (board[i][j] ==  symbol) {
                        board[i][j] = '#';
                    }
                }
            }
        }
    } while (character != 'q');
}

bool Board::checkWin() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (board[i][j] == '#') {
                return false;
            }
        }
    }
    return true;
}