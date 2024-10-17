/*

*/
#include <iostream>
#include <string>

class Menu {
public:
    Menu();
    void StartGame(std::string gameType);
    bool CloseProgram();
    int MenuPicker();
    void Options();

private:
    std::string menuOptions[2] = {"Start Game", "Options"};
    std::string rules; // Print Rules at the start of game
    void titleScreen();
    void shipScreen();
    void endScreen();
    // Stretch Goal: Make stats
};