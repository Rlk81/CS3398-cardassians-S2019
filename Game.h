/*****************************************************************************************
/* File: Game.h
/* Desc: General class for the game
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

#ifndef _GAME_
#define _GAME_

// ------ Includes -----

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include "Difficulty.h"
#include "Options_menu.h"
#include <time.h>


// ------ Defines -----

//#define WAIT_TIME 700			// Number of milliseconds that the piece remains before going 1 block down */ 

struct Piece {

	int piecetype;
	int pieceRotation;
	int posX;
	int posY;

};

// --------------------------------------------------------------------------------
//									 Game
// --------------------------------------------------------------------------------

class Game
{
public:

	Game (Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

	void DrawScene (color *mColor);
	void resetHold();
	void CreateNewPiece (Difficulty &difficulty);
	void hold(Difficulty &difficulty);
	int mPosX, mPosY;				// Position of the piece that is falling down
	int mPiece, mRotation;			// Kind and rotation the piece that is falling down
	struct Piece pieceQueue[4]; 
	void DrawPiece(int pX, int pY, int pPiece, int pRotation, color *mColor);

private:

	int mScreenHeight;				// Screen height in pixels
	int mNextPosX, mNextPosY;		// Position of the next piece
	int mNextPiece, mNextRotation;	// Kind and rotation of the next piece

	int hPosX;
	int	hPosY;				// Position of the piece that is falling down
	int hPiece;
	int	hRotation;
	bool empty;
	bool swapped;

	Board *mBoard;
	Pieces *mPieces;
	IO *mIO;

	void InitGame();
	int GetRand (int pA, int pB);
	
	void DrawBoard ();
};

#endif // _GAME_
