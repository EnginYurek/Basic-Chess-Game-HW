/*

Engin Yürek
040100524
*/


#include < iostream > 
using namespace std;
# include  "hw2.h"



Piece::Piece(Color cl, Column co, int i){
	// write code here
	try{
		if (!isOnBoard(co, i)) throw OutofBoard();
		if (isOccupied(co, i)) throw Occupied();
		color = cl;
		x = co;
		y = i;
	}
	catch (Exception &e){
		 e.output();
	}
}

void Piece::move(Column clmn, int row){
	try{
		if (!isOnBoard(clmn, row)) throw OutofBoard();
		if (isOccupied(clmn, row) && board[row][clmn]->color == color) throw Occupied();
		if (this->canmove(clmn, row) == 0) throw CannotMove();
		if (x == clmn && y == row) throw CannotMove();
		if (board[row][clmn] == NULL){
			board[row][clmn] = board[y][x];
			board[y][x]= NULL;
			board[row][clmn]->x = clmn;
			board[row][clmn]->y = row;
		}
		else if (board[row][clmn] != NULL){
			//cout << "Captured: " << board[row][clmn]->draw() << " at " << board[row][clmn]->x << board[row][clmn]->y << endl;
			delete board[row][clmn];
			board[row][clmn] = board[y][x];
			board[y][x] = NULL;
			board[row][clmn]->x = clmn;
			board[row][clmn]->y = row;
		}
	}
	catch (Exception &e){
		e.output();
	}
}

Piece * Piece::getpiece(Column clmn, int row){
	// write code here
	try{
		if (board[row][clmn] == NULL) throw EmptyCell();
		return board[row][clmn];
	}
	catch (Exception &e){
		e.output();
		
	}
}

