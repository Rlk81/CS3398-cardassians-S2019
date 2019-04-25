#pragma once
#include "IO.h"
class Difficulty
{
private:
	//Current difficulty
	int difficulty_level = 1;
	static const int difficulty_levels = 3;
	//To be used for WAIT_TIME in main, default to normal
	unsigned long game_speed = 700;
	//easy, normal hard
	unsigned long difficulty[difficulty_levels] = { 900, 700, 200 };
	//To generate random for the easiest piece types
	int easy_piece_selection[2] = { 0, 1 };
	//To generate random for hardest piece types
	int hard_piece_selection[2] = { 2, 6 };

public:
	Difficulty(int i);
	unsigned long get_speed();
	unsigned long set_speed(int i);
	int get_difficulty_level();
	void set_difficulty_level(int i);


	int piece_selection(int i);
	
};

