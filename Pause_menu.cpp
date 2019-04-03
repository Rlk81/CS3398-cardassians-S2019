#include "Pause_menu.h"

void Pause_menu::Pause_Menu(IO startIO, Board &b, Game &g) {


	//Images for menu
	SDL_Surface* start_background = NULL;
	SDL_Surface* start_screen = NULL;
	SDL_Surface* start_button = NULL;
	SDL_Surface* start_button_mouse_over = NULL;
	SDL_Surface* options_button = NULL;
	SDL_Surface* reset_button = NULL;
	SDL_Surface* reset_button_mouseover = NULL;


	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up screen
	start_screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	//Load image
	start_background = SDL_LoadBMP("Start_menu_background.bmp");

	//Apply image to screen
	SDL_BlitSurface(start_background, NULL, start_screen, NULL);

	//Load start button
	start_button = SDL_LoadBMP("Pause_button.bmp");
	start_button_mouse_over = SDL_LoadBMP("Pause_mouseover.bmp");

	//Load reset button
	reset_button = SDL_LoadBMP("Reset_button.bmp");
	reset_button_mouseover = SDL_LoadBMP("Reset_button_mouseover.bmp");

	SDL_Rect srcrect;
	SDL_Rect start_rect;
	SDL_Rect options_rect;
	SDL_Rect reset_rect;
	srcrect.x = 0;
	srcrect.y = 0;
	start_rect.x = 550 / 2;
	start_rect.y = 400 / 2;
	options_rect.x = 530 / 2;
	options_rect.y = 600 / 2;
	reset_rect.x = 550 / 2;
	reset_rect.y = 600 / 2;


	//SDL_BlitSurface( start_button, &start_button_Rect, start_screen, NULL );
	SDL_BlitSurface(start_button, NULL, start_screen, &start_rect);
	//Add options button
	SDL_BlitSurface(options_button, NULL, start_screen, &options_rect);
	//Add reset button
	SDL_BlitSurface(reset_button, NULL, start_screen, &reset_rect);
	//Coordinates for mouse
	int Mx = 0;
	int My = 0;
	bool play1 = false;





	//Update Screen
	SDL_Flip(start_screen);
	while (!startIO.IsKeyDown(SDLK_s)) {

		//if over start button, button turns white
		SDL_GetMouseState(&Mx, &My);
		if ((Mx > 275) && (Mx < 375))
			if ((My < 258)& (My > 200)) {
				SDL_Flip(start_screen);
				SDL_BlitSurface(start_button_mouse_over, NULL, start_screen, &start_rect);
			}
		//Click start button	
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 275) && (Mx < 375)
			& (My < 258)& (My > 200)) {
			SDL_Delay(100);
			break;
		}
		//if mouse not over button, turns back to original
		SDL_GetMouseState(&Mx, &My);

		if ((Mx < 275) || (Mx > 375) || (My > 258) || (My < 200)) {
			SDL_Flip(start_screen);
			SDL_BlitSurface(start_button, NULL, start_screen, &start_rect);
		}

		//Add reset
		if ((Mx > 275) && (Mx < 375))
			if ((My < 358)& (My > 300)) {
				SDL_Flip(start_screen);
				SDL_BlitSurface(reset_button_mouseover, NULL, start_screen, &reset_rect);
			}
		//Click reset button	
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 275) && (Mx < 375)
			& (My < 358)& (My > 300)) {
			SDL_Delay(100);
			Reset_Option(b, g);
			break;
		}
		//if mouse not over button, turns back to original
		SDL_GetMouseState(&Mx, &My);

		if ((Mx < 275) || (Mx > 375) || (My > 358) || (My < 300)) {
			SDL_Flip(start_screen);
			SDL_BlitSurface(reset_button, NULL, start_screen, &reset_rect);
		}

	}


	SDL_FreeSurface(start_background);

}

//To be used in resetting game
void Pause_menu::Reset_Option(Board &b, Game &g)
{
	//resets board
	b.ResetBoard();
	//Creates new pieces/piece queue
	g.CreateNewPiece();
}
