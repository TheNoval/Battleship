#include <cursesw.h>

int main() {
    initscr();
    cbreak(); // breaks the program with ctrl-C - default but whatever - good for testing
    raw(); // only takes raw input
    noecho(); // getch() won't leave traces
    
    
    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = 2;
    start_x = 10;

    WINDOW * win = newwin(height, width, start_y, start_x); // initializing a window
    refresh();
    
    mvwprintw(win, 1, 1, "this is a box that I made");

    // wborder(win, 100, 102, 103, 104, 105, 106, 107, 108); // left right top bottom tlc trc blc brc
    box(win, 0, 0); // puts a box in the window
    wrefresh(win);


    int c = getch();
    getch();
    getch();


    endwin();
}