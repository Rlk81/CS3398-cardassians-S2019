#include "Start_menu.h"
#include "Options_menu.h"

void Start_menu::Start_Menu(IO startIO) {


	//Images for menu
	SDL_Surface* start_background = NULL;
	SDL_Surface* start_screen = NULL;
	SDL_Surface* start_button = NULL;
	SDL_Surface* start_button_mouse_over = NULL;
	SDL_Surface* options_button = NULL;
	SDL_Surface* options_button_mouse_over = NULL;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up screen
	start_screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	//Load image
	start_background = SDL_LoadBMP("Start_menu_background.bmp");

	//Apply image to screen
	SDL_BlitSurface(start_background, NULL, start_screen, NULL);

	//Load start button
	start_button = SDL_LoadBMP("Start_button.bmp");
	start_button_mouse_over = SDL_LoadBMP("Start_button_mouseover.bmp");

	//Options button
	options_button = SDL_LoadBMP("Options_button.bmp");
	options_button_mouse_over = SDL_LoadBMP("Options_button_mouseover.bmp");

	SDL_Rect srcrect;
	SDL_Rect start_rect;
	SDL_Rect options_rect;
	srcrect.x = 0;
	srcrect.y = 0;
	start_rect.x = 550 / 2;
	start_rect.y = 400 / 2;
	options_rect.x = 550 / 2;
	options_rect.y = 600 / 2;


	//SDL_BlitSurface( start_button, &start_button_Rect, start_screen, NULL );
	SDL_BlitSurface(start_button, NULL, start_screen, &start_rect);
	//Add options button
	SDL_BlitSurface(options_button, NULL, start_screen, &options_rect);

	//Coordinates for mouse
	int Mx = 0;
	int My = 0;
	bool play1 = false;

	//Update Screen
	SDL_Flip(start_screen);
	while (!startIO.IsKeyDown(SDLK_ESCAPE)) {
	
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

		//if over options button, button turns white
                SDL_GetMouseState(&Mx, &My); 
                if ((Mx > 275) && (Mx < 375))
                        if ((My < 358)& (My > 300)) {  
                                SDL_Flip(start_screen);
                                SDL_BlitSurface(options_button_mouse_over, NULL, start_screen, &options_rect);
                        }

		//Click options button
		// Creates new options menu- there's gotta be a better way to do this
                if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 265) && (Mx < 400) & (My < 358) & (My > 300)) {
                        Options_menu o;
                        o.Options_Menu(startIO);
						this->diff_index = o.get_difficulty_index();
                        break;
                }
		//if mouse not over button, turns back to original
                SDL_GetMouseState(&Mx, &My);

                if ((Mx < 275) || (Mx > 375) || (My > 358) || (My < 300)) {
                        SDL_Flip(start_screen);
                        SDL_BlitSurface(options_button, NULL, start_screen, &options_rect);
                }
	}
	SDL_FreeSurface(start_background);
}

int Start_menu::get_index() {
	return this->diff_index;
}

void Start_menu::set_index(int i)
{

}
