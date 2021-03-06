
#ifndef _PAUSE_MENU_
#define _PAUSE_MENU_

// ------ Includes -----

#include "IO.h"
#include "Board.h"
#include "Game.h"
#include "Start_menu.h"

// --------------------------------------------------------------------------------
//									 Start Menu
// --------------------------------------------------------------------------------
class Pause_menu{
public:
	
	void Pause_Menu(IO startIO, Board &b, Game &g, Difficulty &difficulty, int& lines_cleared, int& temp_score, int& score);
	void Return_to_Start(IO mIO, Board & b, Game & g, Difficulty &difficulty);
	
	void Reset_Option(Board &b, Game &g, Difficulty &difficulty);	
};

#endif // _PAUSE_MENU_



