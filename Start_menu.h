
#ifndef _START_MENU_
#define _START_MENU_

// ------ Includes -----

#include "IO.h"


// --------------------------------------------------------------------------------
//									 Start Menu
// --------------------------------------------------------------------------------
class Start_menu{
public:
	
	void Start_Menu(IO startIO);
	int get_index();

private:
	//default is normal difficulty
	int diff_index = 1;
	
};

#endif // _START_MENU_

