#include "Options_menu.h"

void Options_menu::Options_Menu(IO startIO) {


	//Images for menu
	SDL_Surface* start_background = NULL;
	SDL_Surface* start_screen = NULL;
	SDL_Surface* start_button = NULL;
	SDL_Surface* start_button_mouse_over = NULL;
	SDL_Surface* options_button = NULL;
	SDL_Surface* options_button_mouse_over = NULL;
	//Difficulty buttons
	SDL_Surface* easy_button = NULL;
	SDL_Surface* easy_button_mouseover = NULL;
	SDL_Surface* normal_button = NULL;
	SDL_Surface* normal_button_mouseover = NULL;
	SDL_Surface* hard_button = NULL;
	SDL_Surface* hard_button_mouseover = NULL;
	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up screen
	start_screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	//Load image
	start_background = SDL_LoadBMP("Options_menu_background.bmp");

	//Apply image to screen
	SDL_BlitSurface(start_background, NULL, start_screen, NULL);

	//Load start button
	//start_button = SDL_LoadBMP("Coming_soon_button.bmp");
	//start_button_mouse_over = SDL_LoadBMP("Start_button_mouseover.bmp");

	//Options button
	options_button = SDL_LoadBMP("Return_to_main_button.bmp");
	options_button_mouse_over = SDL_LoadBMP("Return_to_main_button_mouseover.bmp");

	easy_button = SDL_LoadBMP("Easy_button.bmp");
	easy_button_mouseover = SDL_LoadBMP("Easy_button_mouseover.bmp");
	
	normal_button = SDL_LoadBMP("Normal_button.bmp");
	normal_button_mouseover = SDL_LoadBMP("Normal_button_mouseover.bmp");
	
	hard_button = SDL_LoadBMP("Hard_button.bmp");
	hard_button_mouseover = SDL_LoadBMP("Hard_button_mouseover.bmp");


	SDL_Rect srcrect;
	//SDL_Rect start_rect;
	SDL_Rect options_rect;
	SDL_Rect easy_rect;
	SDL_Rect normal_rect;
	SDL_Rect hard_rect;
	srcrect.x = 0;
	srcrect.y = 0;
	//start_rect.x = 530 / 2;
	//start_rect.y = 400 / 2;
	options_rect.x = 550 / 2;
	options_rect.y = 600 / 2;
	easy_rect.x = 130;
	easy_rect.y = 200;
	normal_rect.x = 265;
	normal_rect.y = 200;
	hard_rect.x = 400;
	hard_rect.y = 200;


	//SDL_BlitSurface( start_button, &start_button_Rect, start_screen, NULL );
	//SDL_BlitSurface(start_button, NULL, start_screen, &start_rect);
	//Add options button
	SDL_BlitSurface(options_button, NULL, start_screen, &options_rect);

	//easy button
	SDL_BlitSurface(easy_button, NULL, start_screen, &easy_rect);
	SDL_BlitSurface(normal_button, NULL, start_screen, &normal_rect);
	SDL_BlitSurface(hard_button, NULL, start_screen, &hard_rect);

	//Coordinates for mouse
	int Mx = 0;
	int My = 0;
	bool play1 = false;





	//Update Screen
	SDL_Flip(start_screen);
	while (!startIO.IsKeyDown(SDLK_s)) {

		//if over options button, button turns white
                SDL_GetMouseState(&Mx, &My); 
                if ((Mx > 265) && (Mx < 365))
                        if ((My < 358)& (My > 300)) {  
                                SDL_Flip(start_screen);
                                SDL_BlitSurface(options_button_mouse_over, NULL, start_screen, &options_rect);
                        }

		//Click return button
		// Creates new Main menu- there's gotta be a better way to do this
                if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 265) && (Mx < 365) & (My < 358) & (My > 300)) {
                        Start_menu s;
                        s.Start_Menu(startIO);
                        break;
                }

		//if mouse not over button, turns back to original
                SDL_GetMouseState(&Mx, &My);

                if ((Mx < 265) || (Mx > 365) || (My > 358) || (My < 300)) {
                        SDL_Flip(start_screen);
                        SDL_BlitSurface(options_button, NULL, start_screen, &options_rect);
                }


				//Easy button section
			    //if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 130) && (Mx < 265))
					if ((My < 258)& (My > 200)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(easy_button_mouseover, NULL, start_screen, &easy_rect);
					}

				//Click easy button
				// The button will stay clicked until clicked again and sets the difficulty index to 0
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 130) && (Mx < 265) & (My < 258) & (My > 200)) {
					this->difficulty_index = 0;
					if (this->hold_button_easy == false) {
						this->hold_button_easy = true;
						this->hold_button_normal = false;
						this->hold_button_hard = false;
					}
					else 
						this->hold_button_easy = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_easy == false) {
					if ((Mx < 130) || (Mx > 265) || (My > 258) || (My < 200)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(easy_button, NULL, start_screen, &easy_rect);
					}
				}

				//Normal button section
				//if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 265) && (Mx < 400))
					if ((My < 258)& (My > 200)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(normal_button_mouseover, NULL, start_screen, &normal_rect);
					}

				//Click normal button
				// The button will stay clicked until clicked again and sets the difficulty index to 1
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 265) && (Mx < 400) & (My < 258) & (My > 200)) {
					this->difficulty_index = 1;
					if (this->hold_button_normal == false) {
						this->hold_button_normal = true;
						this->hold_button_easy = false;
						this->hold_button_hard = false;
					}
					else
						this->hold_button_normal = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_normal == false) {
					if ((Mx < 265) || (Mx > 400) || (My > 258) || (My < 200)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(normal_button, NULL, start_screen, &normal_rect);
					}
				}

			
				//Hard button section
				//if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 425) && (Mx < 560))
					if ((My < 258)& (My > 200)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(hard_button_mouseover, NULL, start_screen, &hard_rect);
					}

				//Click hard button
				// The button will stay clicked until clicked again and sets the difficulty index to 2
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 425) && (Mx < 560) & (My < 258) & (My > 200)) {
					this->difficulty_index = 2;
					if (this->hold_button_hard == false) {
						this->hold_button_hard = true;
						this->hold_button_easy = false;
						this->hold_button_normal = false;
					}
					else
						this->hold_button_hard = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_hard == false) {
					if ((Mx < 425) || (Mx > 560) || (My > 258) || (My < 200)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(hard_button, NULL, start_screen, &hard_rect);
					}
				}

	}


	SDL_FreeSurface(start_background);

}

