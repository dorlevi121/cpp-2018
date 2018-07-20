#include "Champion.h"


const Coordinate Champion::play(const Board& board){
	    char emptySlot = '.';
	uint k = 0, m = board.size() - 1;
	Coordinate toCheck = { k, m };
	if (board[toCheck] == emptySlot)
	{
		return toCheck;
	}
	toCheck = { m, k };
	if (board[toCheck] == emptySlot)
	{
		return toCheck;
	}
	for (uint i = 0, j = board.size() - 1; i < board.size(), j >= 0; i++, j--)
	{
		Coordinate c{i,j};
		if (board[c] == emptySlot)
			return c;
	}
	return{ 0, 0 }; // did not find an empty square - play on the top-left 
}