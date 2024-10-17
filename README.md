# Battleship
This is our take on a the battleship game in the terminal

## Notes

The program uses the ncurses/curses library to have a fancy display, do colours, etc.

### Known Issues
- If you place a ship in the top left of the board, the new ship will overwrite the old ship
- Not an issue, but there are some unused functions in the code.

### Notes
- We included the library in the makefile, so it should work, if it happens to not compile, paste this into the terminal while in the directory src

```bash
g++ main.cpp menu.cpp game.cpp player.cpp board.cpp commands.cpp -lncurses
./outputFileName
```
- replacing outputFileName with whatever the file name is

## Terminal Commands

Build and run the program.

```sh
make && ./a.out
```

Clean out build files.

```sh
make clean
```

Build and run testing program.

```sh
make DRIVER=src/test_driver.cpp && ./a.out
```

Clean out test build files.

```sh
make DRIVER=src/test_driver.cpp clean
```
