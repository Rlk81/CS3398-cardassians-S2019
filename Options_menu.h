#ifndef _OPTIONS_MENU_
#define _OPTIONS_MENU_

// ------ Includes -----

#include "IO.h"
#include "Start_menu.h"
#include "Difficulty.h"
#include "Game.h"


// --------------------------------------------------------------------------------
// Options Menu
// --------------------------------------------------------------------------------



class Options_menu{
public:
	 color mColor = MAGENTA;

	void Options_Menu(IO startIO, Difficulty &difficulty, color *mColor);

	//May not need these
	int get_difficulty_index();
	int set_difficulty_index(int i);
	
	
	//Index into difficulty speed array in difficulty class
	int difficulty_index = 1;
	bool hold_button_easy = false;
	bool hold_button_normal = false;
	bool hold_button_hard = false;

	int color_index = 1;
	bool hold_button_grn = false;
	bool hold_button_cyn = false;
	bool hold_button_blu = false;
	bool hold_button_wht = false;
	bool hold_button_mgnt = false;

	
};

#endif // _OPTIONS_MENU_
