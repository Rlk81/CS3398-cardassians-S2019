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
    * Debian & derivatives: `apt-get install libsdl-gfx1.2-dev libsdl-ttf1.2-dev libsdl1.2-dev`
    * Arch & derivatives: `pacman -S sdl_gfx sdl_ttf sdl`
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

## Individual Features / Accomplishments Sprint 1
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

 
## Project Status After Sprint 1/ Next Steps
Status of project: functional  
Current additional features: Start menu, pause menu, options menu, extended piece queue, piece rotation in multiple directions.
* Ralph
  * I plan on adding some form of grid pattern in the teetris and help condense and improve the current code we have.
* Brian
  * I plan on creating a base menu class for the various menus to remove redundant code.
* Fred
  * I plan on communicating with the rest of the team to determine my next course of action.
* Isaac
  * With the basic menus operational, I intend to move on to finding a way to track game scores and statistics. With access to a game score, I will be able to implement a change in color and/or speed at score thresholds to indicate moving up to a new level.
  
 ## Project Status & Added Features After Sprint 2 / Next Steps
 Status of project: functional and looking better than ever!
 Current additional features: Revamped UI, added difficulty settings, Lines to predict block placement, Hold Piece, revamped internal code.
* Ralph
  * I did follow through with my previous ambitions from the last sprint as i added lines to help predict where blocks would land inside of game.cpp and helped implenement a basic facade pattern. 
  * For the next sprint I would like the ability to change the color of blocks during the game.  
* Brian
  * For this sprint I created the ability to reset the game both in game by pressing "r" (in main) and from the pause menu (in pause menu class) which I added a button for. 
  * I added a difficulty class `difficulty.h` and `difficulty.cpp` that currently changes the speed at which the blocks drop based on the difficulty selected from the options menu. It currently is only able to be set before the game starts.
  * For the next sprint, I would like to make improvements to the difficulty settings like allowing the difficulty to be changed during a game and have the difficulty level effect the likelyhood of specific blocks being generated.
* Fred
  * I was not able to complete my tasks due to unforseen personal matters.
  * For the next sprint, I would like to enhance some of the visual aspects of the game.
* Isaac
  * Created all new GUI elements in Photoshop (bitmap images in the root directory).
  * Adjusted in-game colors to be more coherent (IO.h).
  * For the next sprint, I will be adding the ability to keep score in a game,and have statistics tracking across games. With access to a game score, I will be able to implement a change in color and/or speed at score thresholds to indicate moving up to a new level.
* John
  * implemented the HoldPiece feature/ display of held piece.  
  * added return to start menu in the Pause Menu.

## Project Status & Added Features After Sprint 3 / Retrospective
Status: Fully functional game with a variety of features added. Some features have had the groundwork laid out, but are not yet implemented entirely. Individual contributions are described below:
* Ralph
  * I implemented a few features this sprint, but do to lack of time and resources one was not able to be added to the final build.  I added a few extra buttons with the intent of being able to change the color of the blocks, but was unable to implent the changing color function though i did change the initial color of the block.  I also had a feature in which the user was able to change the resolution size of the game and pictures of these features are available in the research material folder, but the feature had to be cut due to the previously listed reasons.  
* John
  * Feature Added: 
      Before, the game would close after a gameover. 
      Now, the player returns to the Start Menu after gameover. Changes were made inside [Main.cpp](https://github.com/cs3398-cardassians-prime/CS3398-cardassians-S2019/blob/4909d3a2d730958b1962d4ca4312534183c64837/Main.cpp)
  * Bug Fix: 
        Before, changing difficulty would permanently change it unless Teetris was closed and reopened.
        Now, Diffculty change works as intended.
* Brian
  * Features added:
     The difficulty class `difficulty.h` and `difficulty.cpp` now changes the probability of getting certain blocks. In easy, you are much more likely to get the two easiest blocks, the squre and the line. And for hard you have a much higher chance to not get those easier blocks. Normal has no changes as it is the natural game mode. This addition is on top of the speed change from the last sprint. I also added the ability to change difficulty in game `main.cpp` by pressing the 1, 2, or 3 keys (for easy, normal, hard). 
* Isaac
  * Features added:
     Scorekeeping was added, counting lines cleared and appropriate score scheme for the game. Added the SDL TTF library to the project structure. Scores were displayed to the screen in-game using the SDL TTF library. Also created new buttons for the color scheme selection in the Options menu (New bitmap images). Score logic and display functionality can be found in `Moard.cpp`, `Main.cpp`, `IO.cpp`, and `Pause_menu.cpp`. Additional TTF library files were added in the /SDL/ directory.
* Fred
  * I was attempting to implement sound effects. I was unsuccessfull in implementing this feature due in part to my lack of understanding of this part of SDL and to my machine's unwillingness to properly function when working in visual studio. Additionally, I created two new bitmap images for a higher difficulty Extreme called `Extreme_button.bmp` and `Extreme_button_mouseover.bmp`. Evidence that I did make these can be found in commits. This difficultly is not implemented however, someone could extent the existing framework and create this difficulty, making the speed of blocks falling faster and/or manipulate the block chance to be less favorable to the player.
