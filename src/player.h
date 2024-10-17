/*

*/
#include <string>
#include "board.h"

class Player {
public:
    Player(std::string name);
    ~Player();
    void addHit();
    void addMiss();
    int getHits();
    int getMisses();

    std::string getName();
    void printSelfBoard(); // Print your board for yourself
    void printOpponentBoard(Player& opponent); // Print your opponent's board for yourself

    void setShips(int size);
    void attacked(int y, int x);
    bool checkWin();
private:
    void printSelfBoard_forOpponent(); // Print your board for your opponent

    std::string name;
    int hits;
    int misses;
    Board* board;

};