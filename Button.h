#pragma once
#include "SDL.h"
#include "IO.h"
#include <string>


const int BUTTON_WIDTH = 100;
const int BUTTON_HEIGHT = 58;

class Button : public SDL_Surface
{
public:
	Button();
	void setButton(std::string button_image, std::string mouseover_image, int x, int y);
	bool isInsideButton(int mouse_x, int mouse_y);
	void darkenButton(SDL_Surface* screen);
	void undarkenButton(SDL_Surface *screen);

	~Button();
	
	SDL_Rect box;
	SDL_Surface* _button_image = NULL;
	SDL_Surface* _mouseover_image = NULL;
	SDL_Surface* _screen = NULL;

private:
	//Images





};

