#include "Pause_menu.h"

void Pause_menu::Pause_Menu(IO startIO, Board &b, Game &g) {


	//Images for menu
	SDL_Surface* start_background = SDL_LoadBMP("Start_menu_background.bmp");
	SDL_Surface* start_screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	SDL_Surface* start_button = SDL_LoadBMP("Resume_button.bmp");
	SDL_Surface* start_button_mouse_over = SDL_LoadBMP("Resume_button_mouseover.bmp");

	SDL_Surface* options_button = NULL;

	SDL_Surface* reset_button = SDL_LoadBMP("Reset_button.bmp");
	SDL_Surface* reset_button_mouseover = SDL_LoadBMP("Reset_button_mouseover.bmp");

	SDL_Surface* return_to_start = SDL_LoadBMP("MainMenu_button.bmp");
	SDL_Surface* return_to_start_mouseover = SDL_LoadBMP("MainMenu_button_mouseover.bmp");


	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	
	//Apply image to screen
	SDL_BlitSurface(start_background, NULL, start_screen, NULL);


	SDL_Rect srcrect;
	srcrect.x = 0;
	srcrect.y = 0;
	

	SDL_Rect start_rect;
	start_rect.x = 550 / 2;    //275
	start_rect.y = 400 / 2;    //200

	SDL_Rect options_rect;
	options_rect.x = 550 / 2;  //265
	options_rect.y = 600 / 2;  //300

	SDL_Rect reset_rect;
	reset_rect.x = 480 / 2;    //240
	reset_rect.y = 600 / 2;    //300

	SDL_Rect return_to_start_rect;
	return_to_start_rect.x = 550 / 2;    //275
	return_to_start_rect.y = 800 / 2;    //300

	//SDL_BlitSurface( start_button, &start_button_Rect, start_screen, NULL );
	SDL_BlitSurface(start_button, NULL, start_screen, &start_rect);
	//Add options button
	SDL_BlitSurface(options_button, NULL, start_screen, &options_rect);
	//Add reset button
	SDL_BlitSurface(reset_button, NULL, start_screen, &reset_rect);
	//Add Return to Start button
	SDL_BlitSurface(return_to_start, NULL, start_screen, &return_to_start_rect);

	//Coordinates for mouse
	int Mx = 0;
	int My = 0;
	bool play1 = false;





	//Update Screen
	SDL_Flip(start_screen);
	while (!startIO.IsKeyDown(SDLK_ESCAPE)) {
////////////////////
		//Pause Button
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
////////////////
		//Reset Button
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

	
////////////////////
	//Return to Main Button
	
	if ((Mx > 275) && (Mx < 375))
		if ((My < 458)& (My > 400)) {
			SDL_Flip(start_screen);
			SDL_BlitSurface(return_to_start_mouseover, NULL, start_screen, &return_to_start_rect);
		}
	//Click reset button	
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 275) && (Mx < 375)
		& (My < 458)& (My > 400)) {
		SDL_Delay(100);
		Return_to_Start(startIO, b,  g);
		break;
	}
	//if mouse not over button, turns back to original
	SDL_GetMouseState(&Mx, &My);

	if ((Mx < 275) || (Mx > 375) || (My > 458) || (My < 400)) {
		SDL_Flip(start_screen);
		SDL_BlitSurface(return_to_start, NULL, start_screen, &return_to_start_rect);
	}

	}


	SDL_FreeSurface(start_background);
	

}

void Pause_menu::Return_to_Start(IO mIO, Board &b, Game &g) {
	Start_menu s;
	//s.set_index(1);
	s.Start_Menu(mIO);
	Reset_Option(b, g);
	
}


//To be used in resetting game
void Pause_menu::Reset_Option(Board &b, Game &g)
{
	//resets board
	b.ResetBoard();
	//Creates new pieces/piece queue
	g.resetHold();
	g.CreateNewPiece();
}
