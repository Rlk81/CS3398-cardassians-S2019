#include "Options_menu.h"

void Options_menu::Options_Menu(IO startIO, Difficulty &difficulty) {


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
	//color buttons
	SDL_Surface* grn_button = NULL;
	SDL_Surface* grn_mouseover = NULL;
	SDL_Surface* cyn_button = NULL;
	SDL_Surface* cyn_mouseover = NULL;
	SDL_Surface* blu_button = NULL;
	SDL_Surface* blu_mouseover = NULL;
	SDL_Surface* wht_button = NULL;
	SDL_Surface* wht_mouseover = NULL;
	SDL_Surface* mgnt_button = NULL;
	SDL_Surface* mgnt_mouseover = NULL;
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

	//color buttons
	grn_button = SDL_LoadBMP("Easy_button.bmp");
	grn_mouseover = SDL_LoadBMP("Easy_button_mouseover.bmp");

	cyn_button = SDL_LoadBMP("Easy_button.bmp");
	cyn_mouseover = SDL_LoadBMP("Easy_button_mouseover.bmp");

	blu_button = SDL_LoadBMP("Easy_button.bmp");
	blu_mouseover = SDL_LoadBMP("Easy_button_mouseover.bmp");

	wht_button = SDL_LoadBMP("Easy_button.bmp");
	wht_mouseover = SDL_LoadBMP("Easy_button_mouseover.bmp");

	mgnt_button = SDL_LoadBMP("Easy_button.bmp");
	mgnt_mouseover = SDL_LoadBMP("Easy_button_mouseover.bmp");


	SDL_Rect srcrect;
	//SDL_Rect start_rect;
	SDL_Rect options_rect;
	SDL_Rect easy_rect;
	SDL_Rect normal_rect;
	SDL_Rect hard_rect;
	SDL_Rect grn_rect;
	SDL_Rect cyn_rect;
	SDL_Rect blu_rect;
	SDL_Rect wht_rect;
	SDL_Rect mgnt_rect;

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

	//each button is 120 pixels longs with 5 pixel space in 
	grn_rect.x = 25;
	grn_rect.y = 250;

	cyn_rect.x = 145;
	cyn_rect.y = 250;

	blu_rect.x = 265;
	blu_rect.y = 250;

	wht_rect.x = 385;
	wht_rect.y = 250;

	mgnt_rect.x = 505;
	mgnt_rect.y = 250;



	//SDL_BlitSurface( start_button, &start_button_Rect, start_screen, NULL );
	//SDL_BlitSurface(start_button, NULL, start_screen, &start_rect);
	//Add options button
	SDL_BlitSurface(options_button, NULL, start_screen, &options_rect);

	//easy button
	SDL_BlitSurface(easy_button, NULL, start_screen, &easy_rect);
	SDL_BlitSurface(normal_button, NULL, start_screen, &normal_rect);
	SDL_BlitSurface(hard_button, NULL, start_screen, &hard_rect);

	SDL_BlitSurface(grn_button, NULL, start_screen, &grn_rect);
	SDL_BlitSurface(cyn_button, NULL, start_screen, &cyn_rect);
	SDL_BlitSurface(blu_button, NULL, start_screen, &blu_rect);
	SDL_BlitSurface(wht_button, NULL, start_screen, &wht_rect);
	SDL_BlitSurface(mgnt_button, NULL, start_screen, &mgnt_rect);


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
                        s.Start_Menu(startIO, difficulty);
						//s.set_index(difficulty_index);
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
					difficulty.set_difficulty_level(0);
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
					difficulty.set_difficulty_level(1);
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
					difficulty.set_difficulty_level(2);
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

				//green button section
			//if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 25) && (Mx < 145))
					if ((My < 308)& (My > 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(grn_mouseover, NULL, start_screen, &grn_rect);
					}

				//Click green button
				// The button will stay clicked until clicked again and sets the difficulty index to 0
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 25) && (Mx < 145) & (My < 308) & (My > 250)) {
					this->difficulty_index = 0;
					if (this->hold_button_grn == false) {
						this->hold_button_grn = true;
						this->hold_button_cyn = false;
						this->hold_button_blu = false;
						this->hold_button_wht = false;
						this->hold_button_mgnt = false;
					}
					else
						this->hold_button_grn = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_grn == false) {
					if ((Mx < 25) || (Mx > 145) || (My > 308) || (My < 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(grn_button, NULL, start_screen, &grn_rect);
					}
				}

				//cyan button section
		//if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 145) && (Mx < 265))
					if ((My < 308)& (My > 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(cyn_mouseover, NULL, start_screen, &cyn_rect);
					}

				//Click cyan button
				// The button will stay clicked until clicked again and sets the difficulty index to 0
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 145) && (Mx < 265) & (My < 308) & (My > 250)) {
					this->difficulty_index = 0;
					if (this->hold_button_grn == false) {
						this->hold_button_grn = false;
						this->hold_button_cyn = true;
						this->hold_button_blu = false;
						this->hold_button_wht = false;
						this->hold_button_mgnt = false;
					}
					else
						this->hold_button_cyn = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_grn == false) {
					if ((Mx < 145) || (Mx > 265) || (My > 308) || (My < 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(cyn_button, NULL, start_screen, &cyn_rect);
					}
				}

				//Blue button section
		//if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 265) && (Mx < 385))
					if ((My < 308)& (My > 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(blu_mouseover, NULL, start_screen, &blu_rect);
					}

				//Click Blue button
				// The button will stay clicked until clicked again and sets the difficulty index to 0
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 265) && (Mx < 385) & (My < 308) & (My > 250)) {
					this->difficulty_index = 0;
					if (this->hold_button_grn == false) {
						this->hold_button_grn = false;
						this->hold_button_cyn = true;
						this->hold_button_blu = false;
						this->hold_button_wht = false;
						this->hold_button_mgnt = false;
					}
					else
						this->hold_button_blu = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_blu == false) {
					if ((Mx < 265) || (Mx > 385) || (My > 308) || (My < 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(blu_button, NULL, start_screen, &blu_rect);
					}
				}

				//White button section
		//if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 385) && (Mx < 505))
					if ((My < 308)& (My > 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(wht_mouseover, NULL, start_screen, &wht_rect);
					}

				//Click White button
				// The button will stay clicked until clicked again and sets the difficulty index to 0
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 385) && (Mx < 505) & (My < 308) & (My > 250)) {
					this->difficulty_index = 0;
					if (this->hold_button_grn == false) {
						this->hold_button_grn = false;
						this->hold_button_cyn = true;
						this->hold_button_blu = false;
						this->hold_button_wht = false;
						this->hold_button_mgnt = false;
					}
					else
						this->hold_button_grn = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_wht == false) {
					if ((Mx < 385) || (Mx > 505) || (My > 308) || (My < 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(wht_button, NULL, start_screen, &wht_rect);
					}
				}

				//Magenta button section
		//if over options button, button turns white
				SDL_GetMouseState(&Mx, &My);
				if ((Mx > 505) && (Mx < 625))
					if ((My < 308)& (My > 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(mgnt_mouseover, NULL, start_screen, &mgnt_rect);
					}

				//Click Magenta button
				// The button will stay clicked until clicked again and sets the difficulty index to 0
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &(Mx > 505) && (Mx < 625) & (My < 308) & (My > 250)) {
					this->difficulty_index = 0;
					if (this->hold_button_grn == false) {
						this->hold_button_grn = false;
						this->hold_button_cyn = false;
						this->hold_button_blu = false;
						this->hold_button_wht = false;
						this->hold_button_mgnt = false;
					}
					else
						this->hold_button_mgnt = false;
				}

				//if mouse not over button, turns back to original
				SDL_GetMouseState(&Mx, &My);
				if (hold_button_mgnt == false) {
					if ((Mx < 505) || (Mx > 625) || (My > 308) || (My < 250)) {
						SDL_Flip(start_screen);
						SDL_BlitSurface(mgnt_button, NULL, start_screen, &mgnt_rect);
					}
				}

	}


	SDL_FreeSurface(start_background);

}

//May not need these
int Options_menu::get_difficulty_index() {
	return this->difficulty_index;
}

int Options_menu::set_difficulty_index(int i) {
	this->difficulty_index = i;
}