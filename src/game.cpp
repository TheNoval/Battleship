/*

*/
#ifdef __linux__
  #include <cursesw.h>
#endif
#ifdef _WIN32
  #include <ncurses/cursesw.h>
#endif

#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "commands.h"

Game::Game() {
    /*
    Initiallizes a game
    stretch: add boardsize parameter
    */
}

Game::~Game() {
    /*
    deletes all pointers to players
    */
    for (int i = 0; i < players.size(); ++i) {
        delete players.at(i); // removes
        players.at(i) = nullptr; // stops referencing
    }
}

void Game::playGame() {
    /*
    does the gameloop
    */
    initPlayers(); // initializes players
    bool roundTwo; // whether the user wants to play another round with the same names _unimplemented_
    int playerTurn = 0; // starting player is player 1
    int oppTurn = 1;
    int y; // attack row
    int x; // attack column
    std::string yVals = "abcdefghij"; // row input options
    std::string xVals = "0123456789"; // column input options
    Player* currPlayer; // makes it easier to switch which player is being referenced
    Player* oppPlayer;

    setBoards(); // sets the boards with ships

    do {
        do {
            // To let the players not see each others board
            mvprintw(4, 15, "%s's turn", getName(playerTurn));
            mvprintw(5, 5, "Please switch places and hide the screen");
            getch();
            clear();
            // end in between screen

            currPlayer = players.at(playerTurn);
            oppPlayer = players.at(oppTurn);

            // Displays the boards
            mvprintw(0, 2, "%s's turn", getName(playerTurn));
            mvprintw(0, 26, "Opponents Board");

            // current players board
            vertPrint(2, 0, "abcdefghij"); // displays player coordinates
            mvprintw(1, 2, "0 1 2 3 4 5 6 7 8 9");
            currPlayer->printSelfBoard();

            // opponents board
            vertPrint(2, 24, "abcdefghij"); // displays opponent coordinates
            mvprintw(1, 26, "0 1 2 3 4 5 6 7 8 9");
            currPlayer->printOpponentBoard(*oppPlayer);
            // End board display

            mvprintw(13, 4, "Where would you like to attack?");

            mvprintw(14, 4, "row: ");
            echo();
            while (true) { // gets the row
                y = mvgetch(14, 9); // takes user input
                if (yVals.find(y) != std::string::npos) {
                    break;
                }
            }

            mvprintw(15, 4, "col: ");
            while (true) { // gets the column
                x = mvgetch(15, 9); // takes user input
                if (xVals.find(x) != std::string::npos) {
                    break;
                }
            }
            noecho();

            oppPlayer->attacked(y - 97, x - 48); // initializes an attack subtract because y and x are chars

            currPlayer->printSelfBoard();
            currPlayer->printOpponentBoard(*oppPlayer);
            getch(); // wait for input

             // checks if there is a winner, if there is, ends game and returns winner
            if (currPlayer->checkWin() == true) {
                winner = playerTurn;
                gameState = false;
            } else if (oppPlayer->checkWin() == true) {
                winner = oppTurn;
                gameState = false;
            }

            currPlayer = nullptr; // stops pointing so that current player can switch
            oppPlayer = nullptr;
            std::swap(playerTurn, oppTurn); // swaps first and second player

            clear();
        } while (gameState);
        printw("The winner is %s!!!!!", getName(winner)); // displays winner
        getch();
        clear();
        roundTwo = playAgain(); // currently does nothing, returns false
    } while (roundTwo);
}

void Game::setBoards() {
     // sets each ship individually
    std::vector<int> shipSizes = {2, 3, 3, 4, 5};
    for (int i = 0; i < 2; ++i) { // player 1 first the player 2
        mvprintw(0, 0, "%s please set your ships in private", getName(i));
        for (int size : shipSizes) { // goes through the list of ship sizes
            players.at(i)->setShips(size);
        }
    getch();
    clear();
    }
}

const char* Game::getName(int playerIndex) { // I did not want to type the below function 
    return players.at(playerIndex)->getName().c_str();
}

bool Game::playAgain() { // currently not used
    /*
    asks the user if they want to play again
    FIXME: do if have time
    */
    return false;
}

void Game::initPlayers() {
    /*
    initializes both of the players with names
    prints players names after
    */

    for (int i = 0; i < 2; i++){
        char name[3000]; // please do not enter a 3000 char name
        echo(); // allows player to see typing
        mvprintw(i, 1, "Player %d name: ", i + 1);
        move(i, 16); // moves to the end of the printed stuff
        refresh();
        getstr(name); // gets the player andd puts it into the player vector
        noecho(); // hides keypresses again

        players.push_back(new Player(name));
    }
    // clear(); // clears display
    // mvprintw(0, 1, "Player 1 is %s", getName(0)); //prints player 1 and 2s name
    // mvprintw(1, 1, "Player 2 is %s", getName(1));
    // refresh();
    // getch();
    clear();
}