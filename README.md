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

## Collaborators
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="16.66%">
        <a href="https://github.com/TheNoval">
            <img src="https://avatars.githubusercontent.com/u/134335319?v=4" width="100px;" alt="TheNoval"/>
            <br />
            <sub><b>TheNoval</b></sub>
        </a>
      </td>
      <td align="center" valign="top" width="16.66%">
        <a href="https://github.com/anna-st-40">
            <img src="https://avatars.githubusercontent.com/u/134335292?v=4" width="100px;" alt="anna-st-40"/>
            <br />
            <sub><b>anna-st-40</b></sub>
        </a>
      </td>
      <td align="center" valign="top" width="16.66%">
        <a href="https://github.com/Wheylop">
            <img src="https://avatars.githubusercontent.com/u/160171684?v=4" width="100px;" alt="Wheylop"/>
            <br />
            <sub><b>Wheylop</b></sub>
        </a>
      </td>
      <td align="center" valign="top" width="16.66%">
        <!-- <a href=""> -->
            <img src="https://cdn.pixabay.com/photo/2016/08/08/09/17/avatar-1577909_1280.png" width="100px;" alt="No Avatar"/>
            <br />
            <sub><b>Jack</b></sub>
        <!-- </a> -->
      </td>
    </tr>    
  </tbody>
</table>