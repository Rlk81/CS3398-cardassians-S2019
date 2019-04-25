#include "Difficulty.h"


Difficulty::Difficulty(int i)
{
	this->game_speed = this->difficulty[i];
	this->difficulty_level = i;
}

unsigned long Difficulty::get_speed()
{
	return this->game_speed;
}

unsigned long Difficulty::set_speed(int i) {
	this->game_speed = this->difficulty[i];
}

int Difficulty::get_difficulty_level() {
	return this->difficulty_level;
}

void Difficulty::set_difficulty_level(int i) {
	this->difficulty_level = i;
	this->game_speed = this->difficulty[i];
}

int Difficulty::piece_selection(int i) {
	if (this->difficulty_level == 0) {
		return this->easy_piece_selection[i];
	}
	if (this->difficulty_level == 2) {
		return this->hard_piece_selection[i];
	}
}

