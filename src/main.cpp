/**
 * Project III: Start here.
 */
#ifdef __linux__
  #include <cursesw.h>
#endif
#ifdef _WIN32
  #include <ncurses/cursesw.h>
#endif


#include "menu.h"
#include <iostream>

// Will have a title screen, then will start a menu, and then have a quit screen.

// have to use printw() instead of std::cout otherwise curses won't work

int main() {
    /* Curses Starting Functions */
    initscr(); // starts the curses window
    noecho(); // doesn't print input characters (turn on when menu options)
    keypad(stdscr, true); // allows for testing against predefined inputs such as KEY_UP
    start_color(); // allows colour to be used

    Menu menu;
    bool exit = false;
    do {
        int game = 0; // indices of the menu options
        // int options = 1;

        int choice = menu.MenuPicker(); // returns 0 as there is only 1 menu option
        if (choice == game) {
            std::string gameType = "normal"; // stretch: add gameTypes
            menu.StartGame(gameType);
        }
        exit = menu.CloseProgram(); // asks the user if they would like ot play again

        // stretch: Implement a menu system with selecting/highlighting
    } while (!exit);

    getch(); // waits for input before closing -- move to menu in closeprogram
    endwin(); // deallocates curses memory
    return 0;
}
