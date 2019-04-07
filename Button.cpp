#include "Button.h"




Button::Button()
{
	

}


void Button::setButton(std::string button_image, std::string mouseover_image, int x, int y)
{
	_button_image = SDL_LoadBMP(button_image.c_str());
	_mouseover_image = SDL_LoadBMP(mouseover_image.c_str());
	box.x = x;
	box.y = y;
}

bool Button::isInsideButton(int mouse_x, int mouse_y)
{
	//bool inside = false;

	if ((mouse_x > BUTTON_WIDTH) && (mouse_x < BUTTON_WIDTH))
		if ((mouse_y < BUTTON_HEIGHT)& (mouse_y > BUTTON_HEIGHT)) {
			return true;
		}
    return false;
}

void Button::darkenButton(SDL_Surface *screen)
{
	SDL_BlitSurface(_mouseover_image, NULL, screen, &box);

}

void Button::undarkenButton(SDL_Surface * screen)
{
	SDL_BlitSurface(_button_image, NULL, screen, &box);
}


Button::~Button()
{

}

