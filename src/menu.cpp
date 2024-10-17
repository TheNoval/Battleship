/*

*/
#ifdef __linux__
  #include <cursesw.h>
#endif
#ifdef _WIN32
  #include <ncurses/cursesw.h>
#endif

#include <iostream>
#include <string>
#include "menu.h"
#include "game.h"
#include "commands.h"



/*
A list of most if not all of the curses functions used in this program, throughout the files.

initscr() sets up the curses window (stdscr)
cbreak() allows for ctrl c to break the program
endwin() dealocates curses memory and closes the program

echo() shows keyboard inputs
noecho() hides keyboard inputs
keypad(win, true/false) allows for using predefined inputs such as KEY_UP
getch() gets keyboard input without needing to press enter
mvgetch(y, x) gets keyboard input from a specified location

refresh() refreshes the specified window
printw(char*) prints to stdscr (main window)
mvprintw(y, x, char*) moves the cursor then prints
move(y, x) moves the cursor

start_color() allows for coloured output
init_pair(int id, foreground, background) initializes a colour for use
attron(COLOR_PAIR(id)) turns the colour off
attroff(COLOR_PAIR(id)) turns the colour on
Made colorOn(id) and colorOff(id) to deal with attron/off
*/

Menu::Menu() { // initializing menu will start the title screen
    titleScreen();
    refresh();
    getch();
    clear();

    shipScreen();
    refresh();
    getch(); // wait for input
    clear(); // clear and move on
}

void Menu::StartGame(std::string gameType) {
    if (gameType == "normal"){
        bool startAgain;
        do {
            Game game; // starts a game with 10x10 board
            game.playGame();
            startAgain = game.playAgain();
        } while (startAgain == true); // crash point for printOpponentBoard()

     // stretch: add more modes

    } else {
        // std::cout << RED << gameType << " is an invalid gametype" << RESET << std::endl;
    }
}

bool Menu::CloseProgram() {
    /*
    returns the result of whether the user wants to continue or not.
    */
    char done[3000]; // please do not enter a 3000 char string
    echo();
    printw("Would you like to play again? ('n' to quit): ");
    refresh();
    getstr(done);
    noecho();

    clear();
    if (done[0] == 'n' || done[0] == 'N') {
        endScreen();
        refresh();
        return true;
    } else if (done[0] == 'y' || done[0] == 'Y') {
        return false;
    } else {
        return CloseProgram();
     // stretch: make this a menu option
    }
    
}

int Menu::MenuPicker() {
    return 0; // 0 is the index of game, which is the only menu option atm
}

void Options() {
 // we currently only have one option 
}

void Menu::titleScreen() { // prints a fancy title screen :)
 // mvprintw(y, x, char*) prints at the specified location in the window
    mvprintw(1 , 2,   "88                                     88                      88                           ");
    mvprintw(2 , 2,   "88                       ,d      ,d    88                      88          88               ");
    mvprintw(3 , 2,   "88                       88      88    88                      88                           ");
    mvprintw(4 , 2,   "88,dPPYba,  ,adPPYYba, MM88MMM MM88MMM 88  ,adPPYba, ,adPPYba, 88,dPPYba,  88  8b,dPPYba,   ");
    mvprintw(5 , 2, R"(88P'    '8a ""     `Y8   88      88    88 a8P_____88 I8[    "" 88P'    "8a 88  88P'    "8a  )");
    mvprintw(6 , 2, R"(88       d8 ,adPPPPP88   88      88    88 8PP"""""""  `"Y8ba,  88       88 88  88       d8  )");
    mvprintw(7 , 2, R"(88b,   ,a8" 88,    ,88   88,     88,   88 "8b,   ,aa aa    ]8I 88       88 88  88b,   ,a8"  )");
    mvprintw(8 , 2, R"(8Y"Ybbd8"'  `"8bbdP"Y8   "Y888   "Y888 88  `"Ybbd8"' `"YbbdP"' 88       88 88  88`YbbdP"'   )");
    mvprintw(9 , 2,   "                                                                               88           ");
    mvprintw(10, 2,   "                                                                               88           ");

    mvprintw(12, 2,   "                                                                               Press any key");
}

void Menu::shipScreen() { // prints a fancy ship :)
    mvprintw(1 , 2,   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~oo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    mvprintw(2 , 2,   "                                 o o                                      ");
    mvprintw(3 , 2,   "                                 o ooo                                    ");
    mvprintw(4 , 2,   "                                   o oo                                   ");
    mvprintw(5 , 2,   "                                      o o      |   #)      art by:        ");
    mvprintw(6 , 2,   "                                       oo     _|_|_#_    -Scott Mason-    ");
    mvprintw(7 , 2,   "                                         o   | 751   |                    ");
    mvprintw(8 , 2,   "    __                    ___________________|       |_________________   ");
    mvprintw(9 , 2, R"(   |   -_______-----------                                              \\ )");
    mvprintw(10, 2,   "  >|    _____                                                   --->     )");
    mvprintw(11, 2,   "   |__ -     ---------_________________________________________________ / ");

    mvprintw(12, 2,   "                                                                               Press any key");
}

void Menu::endScreen() { // end credits basically
    init_pair(21, COLOR_YELLOW, COLOR_BLACK); // sets the colours that I want to use
    init_pair(22, COLOR_GREEN, COLOR_BLACK);
    init_pair(23, COLOR_RED, COLOR_BLACK);
    init_pair(24, COLOR_CYAN, COLOR_BLACK);

    mvprintw(getmaxy(stdscr)/2.5, getmaxx(stdscr)/3, "Thank you for playing battleship");
    mvprintw(getmaxy(stdscr)/2.5 + 1, getmaxx(stdscr)/3, "Have a good day :)");

    colorOn(21);
    mvprintw(getmaxy(stdscr)/2.5 + 2, getmaxx(stdscr)/3, "Jack, ");
    colorOff(21);

    colorOn(22);
    printw("Anna, ");
    colorOff(22);

    colorOn(23);
    printw("Nathanael,");
    colorOff(23);

    colorOn(24);
    printw(" and Nolan");
    colorOff(24);
}


// void Menu::titleScreen() {
//     mvprintw(1 , 2,   "88                                     88                      88                           ");
//     mvprintw(2 , 2,   "88                       ,d      ,d    88                      88          88               ");
//     mvprintw(3 , 2,   "88                       88      88    88                      88                           ");
//     mvprintw(4 , 2,   "88,dPPYba,  ,adPPYYba, MM88MMM MM88MMM 88  ,adPPYba, ,adPPYba, 88,dPPYba,  88  8b,dPPYba,   ");
//     mvprintw(5 , 2, R"(88P'    '8a ""     `Y8   88      88    88 a8P_____88 I8[    "" 88P'    "8a 88  88P'    "8a  )");
//     mvprintw(6 , 2, R"(88       d8 ,adPPPPP88   88      88    88 8PP"""""""  `"Y8ba,  88       88 88  88       d8  )");
//     mvprintw(7 , 2, R"(88b,   ,a8" 88,    ,88   88,     88,   88 "8b,   ,aa aa    ]8I 88       88 88  88b,   ,a8"  )");
//     mvprintw(8 , 2, R"(8Y"Ybbd8"'  `"8bbdP"Y8   "Y888   "Y888 88  `"Ybbd8"' `"YbbdP"' 88       88 88  88`YbbdP"'   )");
//     mvprintw(9 , 2,   "                                                                               88           ");
//     mvprintw(10, 2,   "                                                                               88           ");

//     mvprintw(12, 2,   "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~oo~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
//     mvprintw(13, 2,   "                                 o o                                      ");
//     mvprintw(14, 2,   "                                 o ooo                                    ");
//     mvprintw(15, 2,   "                                   o oo                                   ");
//     mvprintw(16, 2,   "                                      o o      |   #)      art by:        ");
//     mvprintw(17, 2,   "                                       oo     _|_|_#_    -Scott Mason-    ");
//     mvprintw(18, 2,   "                                         o   | 751   |                    ");
//     mvprintw(19, 2,   "    __                    ___________________|       |_________________   ");
//     mvprintw(20, 2, R"(   |   -_______-----------                                              \\ )");
//     mvprintw(21, 2,   "  >|    _____                                                   --->     )");
//     mvprintw(22, 2,   "   |__ -     ---------_________________________________________________ / ");

//     mvprintw(24, 2,   "                                                                             Enter to Continue");
// }