/*****************************************************************************************
/* Desc: Tetris tutorial
/*
/* gametuto.com - Javier López López (javilop.com)
/*
/*****************************************************************************************
/*
/* Creative Commons - Attribution 3.0 Unported
/* You are free:
/*	to Share — to copy, distribute and transmit the work
/*	to Remix — to adapt the work
/*
/* Under the following conditions:
/* Attribution. You must attribute the work in the manner specified by the author or licensor 
/* (but not in any way that suggests that they endorse you or your use of the work).
/*
/*****************************************************************************************/

#include "Game.h"
#include "Start_menu.h"
#include "Pause_menu.h"
#include "Options_menu.h"
#include "Difficulty.h"

#include <iostream>

#ifndef LINUX
#include <windows.h>
#endif





/*
==================
Main
==================
*/
#ifndef LINUX
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)	// Linux users should quit this line
#else
int main()
#endif
// int main ()  // Linux users should use this line instead the previous one
{


	IO mIO;
	
//	bool playing = true;
	// ----- Main Loop -----

	while (!mIO.IsKeyDown (SDLK_ESCAPE))
	{
		
		int mScreenHeight = mIO.GetScreenHeight();

		// Pieces
		Pieces mPieces;

		// Board
		Board mBoard(&mPieces, mScreenHeight);

		// Game
		Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

		// Get the actual clock milliseconds (SDL)
		unsigned long mTime1 = SDL_GetTicks();

		//Create difficulty 
		Difficulty diff(1);

		//Creates start menu
		Start_menu s;
		s.Start_Menu(mIO, diff);

        int lines_cleared = 0;
        int score = 0;

		bool playing = true;
        

		while (playing) {
			//while(!mboard.isGameOver())
            
			// ----- Draw -----

			mIO.ClearScreen(); 		// Clear screen
			mGame.DrawScene();			// Draw staff
			mIO.UpdateScreen();		// Put the graphic context in the screen

			// ----- Input -----

			int mKey = mIO.Pollkey();

			switch (mKey)
			{
			case (SDLK_RIGHT):
			case (SDLK_d):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX++;
				break;
			}

			case (SDLK_LEFT):
			case (SDLK_a):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX--;
				break;
			}

			case (SDLK_DOWN):
			case (SDLK_s):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
					mGame.mPosY++;
				break;
			}

			case (SDLK_x):
			{
				// Check collision from up to down
				while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) { mGame.mPosY++; }

				mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

				mBoard.DeletePossibleLines(lines_cleared);

				if (mBoard.IsGameOver())
				{
					playing = false;
					//mIO.Getkey();
					s.Start_Menu(mIO,diff);
					mBoard.ResetBoard();
					mGame.resetHold();
					break;
					//Creates new pieces/piece queue
					//mGame.CreateNewPiece();
					//exit(0);
				}

				mGame.CreateNewPiece(diff);

				break;
			}

			case (SDLK_z):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
					mGame.mRotation = (mGame.mRotation + 1) % 4;

				break;
			}
			case (SDLK_c):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 3) % 4))
					mGame.mRotation = (mGame.mRotation + 3) % 4;

				break;
			}
			case (SDLK_p):
			{

				Pause_menu p;
				p.Pause_Menu(mIO, mBoard, mGame, diff);

				break;
			}
			case (SDLK_h):
			{
				mGame.hold(diff);

				break;

			}
			case (SDLK_r):
			{
				//resets board
				mBoard.ResetBoard();
				mGame.resetHold();
				//Creates new pieces/piece queue
				mGame.CreateNewPiece(diff);

				break;
			}

			}

			// ----- Vertical movement -----
			unsigned long WAIT_TIME = 700;
			WAIT_TIME = diff.get_speed();
			unsigned long mTime2 = SDL_GetTicks();




			if ((mTime2 - mTime1) > WAIT_TIME)
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
				{
					mGame.mPosY++;
				}
				else
				{
					mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);

					mBoard.DeletePossibleLines(lines_cleared);

					if (mBoard.IsGameOver())
					{
						playing = false;

						//mIO.Getkey();
						s.Start_Menu(mIO,diff);
						mBoard.ResetBoard();
						mGame.resetHold();
						break;
						//Creates new pieces/piece queue
						//mGame.CreateNewPiece();
						//exit(0);
					}

					mGame.CreateNewPiece(diff);
				}

				mTime1 = SDL_GetTicks();
			}
		}
	}

	return 0;
}
