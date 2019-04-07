
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
	
	void Pause_Menu(IO startIO, Board &b, Game &g);
	void Return_to_Start(IO mIO);
	void Reset_Option(Board &b, Game &g);	
};

#endif // _PAUSE_MENU_



