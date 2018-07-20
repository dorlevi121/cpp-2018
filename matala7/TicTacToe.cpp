
#include "TicTacToe.h"

TicTacToe::TicTacToe(uint size):sizeBoard(size),board_table(size){
}

bool TicTacToe::checkCoor(const Coordinate& c)const{
    if(board_table[c] == '.')
        return true;

    return false;
}

Board TicTacToe::board() const{
    return board_table;
}  

bool TicTacToe::isWin(Player& p){
   
	char check = p.getChar();
	char emptySlot = '.';
	int size = sizeBoard;
	bool hasWon = true;
	for (uint i = 0; i < size; i++)
	{
		for (uint j = 0; j < size; j++)
		{
			if (i*j == 0 || i == size - 1 || j == size - 1)
			{
				char curr = board_table[{i,j}].getAT();
				if (curr == emptySlot)
					continue;
				if (j == 0)			// look right
				{
					for (uint k = 1; k < size; k++)
					{
						if (board_table[{i, k}].getAT() != curr)
						{
							hasWon = false;
							break;
						}
					}
					if (hasWon)
						return true;
				}
				hasWon = true;
				if (i == 0)			// look down
				{
					for (uint k = 1; k < size; k++)
					{
						if (board_table[{k,j}].getAT() != curr)
						{
							hasWon = false;
							break;
						}
					}
					if (hasWon)
						return true;
					hasWon = true;
					if (j == 0) // look down right
					{
						for (uint k = 1; k < size; k++)
						{
							if (board_table[{i + k, j + k}].getAT() != curr)
							{
								hasWon = false;
								break;
							}
						}
						if (hasWon)
							return true;
					}
					hasWon = true;
					if (j == size - 1) // look down left
					{
						for (uint k = 1; k < size; k++)
						{
							if (board_table[{i + k, j - k}].getAT() != curr)
							{
								hasWon = false;
								break;
							}
						}
						if (hasWon)
							return true;
					}
				}
			}
		}
	}
	return false;
}

Player& TicTacToe::winner() const{
    return *iWin;
}

bool TicTacToe::boardFull(){
    	for (uint i = 0; i < board_table.size(); i++)
	{
		for (uint j = 0; j < board_table.size(); j++)
		{
			if (board_table[{i, j}] == '.')
			{
				return false;
			}
		}
	}
	return true;
}

void TicTacToe::play(Player& x, Player& o){
	clearBoard();
    bool win = false;
        x.setChar('X');
        o.setChar('O');
		
    while(!win){
		Coordinate coor = {0,0};

		try{
			        coor = x.play(board_table);
        if(checkCoor(coor)){
            board_table[coor] = x.getChar();
        }

		else{
			 IllegalCoordinateException ex;
			ex.setA(coor.x);
			ex.setB(coor.y);
			win = true;
            iWin = &o;
			
			throw ex;
		}
        
            if(isWin(x)){
                win = true;
                iWin = &x;
				return;
            }
		}//end try
		catch(...){
			cout << "Throw exception" << endl;

			win = true;
			iWin = &o;
			break;
		}

        //// O Turn////
		try{
		if(!win){
		coor = o.play(board_table);

		if(checkCoor(coor)){
            board_table[coor] = o.getChar();
        }

		else{
			 IllegalCoordinateException ex;
			ex.setA(coor.x);
			ex.setB(coor.y);
			win = true;
            iWin = &x;
			
			throw ex;
		}       
            if(isWin(o)){
                win = true;
                iWin = &o;
				return;
            }
        
		}
	}

				catch(...){
			cout << "Throw exception" << endl;

			win = true;
			iWin = &x;
			break;
		}

	if(boardFull()){
                ///game over
				win = true;
				iWin = &o;
				return;
            }
	
    }
}

void TicTacToe::clearBoard(){
	board_table = Board(sizeBoard);
}