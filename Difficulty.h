#pragma once
#include "IO.h"
class Difficulty
{
private:
	static const int difficulty_levels = 3;
	//To be used for WAIT_TIME in main, default to normal
	unsigned long game_speed = 700;
	//easy, normal hard
	unsigned long difficulty[difficulty_levels] = { 900, 700, 200 };

public:
	Difficulty(int i);
	unsigned long get_speed();
	unsigned long set_speed(int i);
	
};

