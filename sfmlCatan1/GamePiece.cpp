#include "GamePiece.h"

GamePiece::GamePiece(int ptotalPieces, int ppieces)
{
	this->totalPieces = ptotalPieces;
	*this->pieces = ppieces;
}
