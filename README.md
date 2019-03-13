# Ｔｅｅｔｒｉｓ
![tetris](https://raw.githubusercontent.com/cs3398-cardassians-prime/CS3398-cardassians-S2019/master/tetris.jpg)

# Welcome to yet another teris clone

Original project source code from [Javier López](http://www.javilop.com)

## Vision Statement
We are working with our team "Cardassians" to create and improve upon the game of tetris. We hope to make this game appeal to both the casual and the hardcore tetris player with a variety of options. Why are we doing this? To improve upon the already great game of tetris.

## Description
This project will be a tetris clone where the Cardassians will take source code from a Tetris tutorial and add menus and extra functionality.

## Why is it special?
This project is special becuase in this project, our team will take a Tetris clone and through a series of added features, create a more exciting Tetris clone.

## Build and run
* Windows
  * The source code comes with SDL includes and libs ready to compile in Visual C++ Express Edition 2008. In “Release” folder there is also an executable file just in case you want to try it directly.
  * If you are using an updated version of Visual Studios you can also install the Windows 8.1 SDk via the associated installer application and you just have to find the right package for it.
* Linux
  * Install dependencies for sdl
    * Debian & derivatives: `apt-get install libsdl-gfx1.2-dev libsdl1.2-dev`
    * Arch & derivatives: `pacman -S sdl_gfx sdl`
  * Compile using the included makefile
  
## How to play
Keys | Operation
------------ | -------------
ESC | Quit the game
Z | Rotate piece clockwise
C | Rotate piece counter clockwise
X | Drop piece
P | Pause game
Left, A | Move piece left
Right, D | Move piece right
Down, S | Move piece down

## Individual Features / Accomplishments
* Ralph Kelley
  * I created the pause menu and all pause menu related items and implemented them into the code. The pause menu is activated when you press the "P" key which pops up a menu in which you can pause and unpause the game.  
  * `Pause_menu.h`, `Pause_menu.cpp`, added functionallity of pressing "p" into main under the input section
* Isaac van Til
  * Added an 'options' menu, integrated with the start menu.
  * Add sections in `Start_menu.cpp` for creating and displaying the options menu.
  * `Options_menu.h`, `Options_menu.cpp`, and associated image files.
* Brian Chase
  * Created a start menu class that creates the start menu in main.
  * `Start_menu.h`, `Start_menu.cpp`, and image files used in the class
* John Bringmann
  * Created the pieceQueue. This displays the next 4 Teetris pieces to the right of the game board. 
    Each Teetris piece's position inside the queue gets updated when pieceQueue[0] is pulled inside the game board.
    Then a new new Teetris piece is created for position pieceQueue[3]. 
  * Changes were made to functions of Game: InitGame(), CreateNewPiece(), and DrawScene().  
* Fred Hanson
  * Added counter clockwise rotation
  * Added alternate movement keys

 
## Project Status / Next Steps
Status of project: functional
### Current added features:
  * Start menu, pause menu, options menu, extended piece queue, piece rotation in multiple directions.
### Ralph
  * I plan on adding some form of grid pattern in the teetris and help condense and improve the current code we have.
### Brian
  * I plan on creating a base menu class for the various menus to remove redundant code.
## Fred
  * I plan on communicating with the rest of the team to determine my next course of action.
## Isaac
  * With the basic menus operational, I intend to move on to finding a way to track game scores and statistics. With access to a game score, I will be able to implement a change in color and/or speed at score thresholds to indicate moving up to a new level.
  
