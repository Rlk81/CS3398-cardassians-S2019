#include "Difficulty.h"


Difficulty::Difficulty(int i)
{
	this->game_speed = this->difficulty[i];
}

unsigned long Difficulty::get_speed()
{
	return this->game_speed;
}

unsigned long Difficulty::set_speed(int i) {
	this->game_speed = this->difficulty[i];
}


