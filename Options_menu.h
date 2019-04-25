#ifndef _OPTIONS_MENU_
#define _OPTIONS_MENU_

// ------ Includes -----

#include "IO.h"
#include "Start_menu.h"
#include "Difficulty.h"


// --------------------------------------------------------------------------------
// Options Menu
// --------------------------------------------------------------------------------
class Options_menu{
public:
	
	void Options_Menu(IO startIO, Difficulty &difficulty);

	//May not need these
	int get_difficulty_index();
	int set_difficulty_index(int i);
	
	
	//Index into difficulty speed array in difficulty class
	int difficulty_index = 1;
	bool hold_button_easy = false;
	bool hold_button_normal = false;
	bool hold_button_hard = false;
	
};

#endif // _OPTIONS_MENU_
