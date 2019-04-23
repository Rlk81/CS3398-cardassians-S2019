
#ifndef _START_MENU_
#define _START_MENU_

// ------ Includes -----

#include "IO.h"
#include "Difficulty.h"


// --------------------------------------------------------------------------------
//									 Start Menu
// --------------------------------------------------------------------------------
class Start_menu{
public:
	
	void Start_Menu(IO startIO);
	int get_index();
	void set_index(int i);

private:
	//default is normal difficulty
	int diff_index = 1;
	
};

#endif // _START_MENU_

