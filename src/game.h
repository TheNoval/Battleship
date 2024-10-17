/*

*/
#include <iostream>
#include <string>
#include <vector>
#include "player.h"

class Game {
public:
    Game();
    ~Game(); // removes player pointers

    void playGame(); // starts gameloop : called externally
    const char* getName(int playerNumber);
    void setBoards();
    bool playAgain(); // returns false currently

private:
    void initPlayers(); // adds a player to the game

    std::vector<Player *> players;
    bool gameState = true; // for the gameloop while loop (maybe offer the chance to change mind.)
    int winner;
};