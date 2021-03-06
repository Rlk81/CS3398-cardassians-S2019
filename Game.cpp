/*****************************************************************************************
/* File: Game.cpp
/* Desc: General class for the game
/*
/* gametuto.com - Javier L�pez L�pez (javilop.com)
/*
/*****************************************************************************************
/*
/* Creative Commons - Attribution 3.0 Unported
/* You are free:
/*	to Share � to copy, distribute and transmit the work
/*	to Remix � to adapt the work
/*
/* Under the following conditions:
/* Attribution. You must attribute the work in the manner specified by the author or licensor 
/* (but not in any way that suggests that they endorse you or your use of the work).
/*
/*****************************************************************************************/

// ------ Includes -----
#ifndef LINUX
#include <windows.h>
#endif
#include "Game.h"
#include <iostream>

/* 
======================================									
Init
====================================== 
*/
Game::Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight) 
{
	mScreenHeight = pScreenHeight;

	// Get the pointer to the Board and Pieces classes
	mBoard = pBoard;
	mPieces = pPieces;
	mIO = pIO;

	// Game initialization
	InitGame ();
}


/* 
======================================									
Get a random int between to integers

Parameters:
>> pA: First number
>> pB: Second number
====================================== 
*/
int Game::GetRand (int pA, int pB)
{
	return rand () % (pB - pA + 1) + pA;
}


/* 
======================================									
Initial parameters of the game
====================================== 
*/
void Game::InitGame()
{
	// Init random numbers
	srand ((unsigned int) time(NULL));

	// First piece
	mPiece			= GetRand (0, 6);
	mRotation		= GetRand (0, 3);
	mPosX 			= (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition (mPiece, mRotation);
	mPosY 			= mPieces->GetYInitialPosition (mPiece, mRotation);

	for (int i = 0; i < 4; i++)
	{
		pieceQueue[i].piecetype = GetRand(0, 6);
		pieceQueue[i].pieceRotation = GetRand(0, 3);
		pieceQueue[i].posX = BOARD_WIDTH + 5;
		pieceQueue[i].posY = 5 * i;
	}

	// Set the Hold for new game
	empty = true;
	swapped = false;

	hPosX = -10;
	hPosY = 0;				// Position of the piece that is falling down
	hPiece = 0;
	hRotation = 0;

}


void Game::hold(Difficulty &difficulty)
{
	if (empty)
	{
		hPiece = mPiece;
		hRotation = mRotation;
		empty = false;
		swapped = true;
		CreateNewPiece(difficulty);
	}
	else if (!swapped)
	{

		int tPiece = mPiece;

		int tRot = mRotation;

		mRotation = hRotation;
		mPiece = hPiece;

		hPiece = tPiece;
	    hRotation = tRot;
		mRotation = 0;
		mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
		mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);
		swapped = true;
	}
}


/* 
======================================									
Create a random piece
====================================== 
*/
void Game::CreateNewPiece(Difficulty &difficulty)
{
	if (!empty) {

	if (swapped)
	   swapped = false;
	}

	// The new piece
	mPiece = pieceQueue[0].piecetype;
	mRotation = pieceQueue[0].pieceRotation;
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);
	
	//update pieceQueue
	for (int i = 0; i < 4; i++)
	{
		pieceQueue[i].piecetype = pieceQueue[i + 1].piecetype;
		pieceQueue[i].pieceRotation = pieceQueue[i + 1].pieceRotation;
	}

	// Random next piece
	if (difficulty.get_difficulty_level() == 0) {
		if (GetRand(0, 1) == 0 ) {
			pieceQueue[3].piecetype = GetRand(0, 1);
			pieceQueue[3].pieceRotation = GetRand(0, 3);
		}
		else {
			pieceQueue[3].piecetype = GetRand(0, 6);
			pieceQueue[3].pieceRotation = GetRand(0, 3);
		}
	}
	else if (difficulty.get_difficulty_level() == 2) {
		if (GetRand(0, 1) == 0) {
			pieceQueue[3].piecetype = GetRand(2, 6);
			pieceQueue[3].pieceRotation = GetRand(0, 3);
		}
		else {
			pieceQueue[3].piecetype = GetRand(0, 6);
			pieceQueue[3].pieceRotation = GetRand(0, 3);
		}
	}
	else if (difficulty.get_difficulty_level() == 1) {
		pieceQueue[3].piecetype = GetRand(0, 6);
		pieceQueue[3].pieceRotation = GetRand(0, 3);
	}
}


/* 
======================================									
Draw piece

Parameters:

>> pX:		Horizontal position in blocks
>> pY:		Vertical position in blocks
>> pPiece:	Piece to draw
>> pRotation:	1 of the 4 possible rotations
====================================== 
*/
void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation, color mColor)
{
					// Color of the block 

	// Obtain the position in pixel in the screen of the block we want to draw
	int mPixelsX = mBoard->GetXPosInPixels (pX);
	int mPixelsY = mBoard->GetYPosInPixels (pY);

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < PIECE_BLOCKS; i++)
	{
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			// Get the type of the block and draw it with the correct color
			switch (mPieces->GetBlockType (pPiece, pRotation, j, i))
			{
				case 1: mColor =CYAN ; break;	// For each block of the piece except the pivot
			
			}
			
			if (mPieces->GetBlockType (pPiece, pRotation, j, i) != 0)
				mIO->DrawRectangle	(mPixelsX + i * BLOCK_SIZE, 
									mPixelsY + j * BLOCK_SIZE, 
									(mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, 
									(mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, 
									mColor);
		}
	}
}


/* 
======================================									
Draw board

Draw the two lines that delimit the board
====================================== 
*/
void Game::DrawBoard ()
{
	// Calculate the limits of the board in pixels	
	int line = BOARD_POSITION;
	int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	//int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	double mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);
	
	// Check that the vertical margin is not to small
	//assert (mY > MIN_VERTICAL_MARGIN);

	// Rectangles that delimits the board
	mIO->DrawRectangle (mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->DrawRectangle (mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	for (mX2; mX2 > BOARD_WIDTH; mX2 -= 16.1) 
		if (mX2 >= mX1)
			mIO->DrawVLine(mX2, mY, mScreenHeight, BLUE);
	
	// Check that the horizontal margin is not to small
	//assert (mX1 > MIN_HORIZONTAL_MARGIN);

	// Drawing the blocks that are already stored in the board
	mX1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{	
			// Check if the block is filled, if so, draw it
			if (!mBoard->IsFreeBlock(i, j))	
				mIO->DrawRectangle (	mX1 + i * BLOCK_SIZE, 
										mY + j * BLOCK_SIZE, 
										(mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1, 
										(mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, 
										RED);
		}
	}	
}


/* 
======================================									
Draw scene

Draw all the objects of the scene
====================================== 
*/
void Game::DrawScene ()
{
	DrawBoard ();													// Draw the delimitation lines and blocks stored in the board
	DrawPiece (mPosX, mPosY, mPiece, mRotation, mColor);					// Draw the playing piece
	
	for (int i = 0; i < 4; i++)
	{
		DrawPiece(pieceQueue[i].posX, pieceQueue[i].posY, pieceQueue[i].piecetype, pieceQueue[i].pieceRotation, mColor);
	}

	if (!empty)
		DrawPiece(hPosX, hPosY, hPiece, hRotation, mColor);
}


void Game::resetHold() {
	empty = true;
	swapped = false;

}