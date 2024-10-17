#ifdef __linux__
  #include <cursesw.h>
#endif
#ifdef _WIN32
  #include <ncurses/cursesw.h>
#endif
#include <iostream>
#include <string>

// link using the compiler flag -lncursesw for both linux and windows


int main() {
    initscr();
    timeout(-1);
    keypad(stdscr, TRUE);
    int ch;
    while (ch != static_cast<int>('q')) {
        ch = getch();
        if (ch != ERR) {
            clear();
            if (ch == KEY_UP) {
                printw("Up arrow key pressed\n");
            } else if (ch == KEY_DOWN) {
                printw("Down arrow key pressed\n");
            } else if (ch == KEY_LEFT) {
                printw("Left arrow key pressed\n");
            } else if (ch == KEY_RIGHT) {
                printw("Right arrow key pressed\n");
            } else if (ch == '\r' || ch == '\n') {
                printw("Enter Pressed");
            } else {
                // Print other keys
                printw("Key pressed: %c\n", ch);
            }
        }
        printw("Bro wassup");
        // clear();
        // refresh();
    }
    endwin();
}