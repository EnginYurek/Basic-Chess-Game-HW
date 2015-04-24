/*

Engin Yürek
040100524

*/



#include "hw2.h"

// create all pieces from Piece class by inheritance and implement their own functions draw(), canmove()
	
	// Knight class
	//
	// Bishop class
	//
	// Rook class
	//
	// Queen class
	//
	// King class
	//
	// Pawn class
	//
// x=col y=row;
int Pawn::canmove(Column clmn, int row)const{
	
	bool canGo = false;

	if (color == WHITE){
		if (y == 2 && clmn==x && row==y+2 && board[row][clmn] == NULL && board[row - 1][clmn] == NULL)
			canGo = true;

		if (clmn == x && row == y + 1 && board[row][clmn] == NULL)
			canGo = true;

		if ((clmn == x - 1 || clmn == x + 1) && row == y + 1 && board[row][clmn] != NULL)
			canGo = true;
	}
	else if (color == BLACK){
		if (y == 7 && clmn == x &&row == y - 2 && board[row][clmn] == NULL && board[row + 1][clmn] == NULL)
			canGo = true;
		if (clmn == x && row == y - 1 && board[row][clmn] == NULL)
			canGo = true;
		if ((clmn == x + 1 || clmn == x - 1) && row == y - 1 && board[row][clmn] != NULL)
			canGo = true;
	}

	if (canGo)
		return 1;
	else return 0;
}
const char *Pawn::draw()const{
	return pNamePtr;
}

int Knight::canmove(Column clmn, int row)const{
	//x = col y = row
	if (x == clmn + 2 && (y == row + 1 || y == row - 1))
		return 1;
	if (x == clmn + 1 && (y == row + 2 || y == row - 2))
		return 1;
	if (x == clmn - 1 && (y == row + 2 || y == row - 2))
		return 1;
	if (x == clmn - 2 && (y == row + 1 || y == row - 1))
		return 1;

	return 0;
}
const char *Knight::draw()const{
	return pNamePtr;
}

int Rook::canmove(Column clmn, int row)const{
	//sadece yol üstündeki karelere baktık varış noktasındaki karenin dolulugu move içide kontrol ediliyor
	bool isRoadEmpty = true;
	if (x == clmn){
		if (y < row){
			for (int i = y + 1; i < row; i++)
				if (board[i][x] != NULL)
					isRoadEmpty = false;
		}
		else if (y > row)
			for (int i = y - 1; i > row; i--)
				if (board[i][x] != NULL)
					isRoadEmpty = false;
	}
	else if (y == row){
		if (x > clmn){
			for (int i = x - 1; i > clmn; i--)
				if (board[y][i]!=NULL)
					isRoadEmpty = false;
		}
		else if (x < clmn)
			for (int i = x + 1; i < clmn; i++)
				if (board[y][i]!=NULL)
					isRoadEmpty = false;
	}
	if (x == row && y == clmn)
		isRoadEmpty= false;

	if(isRoadEmpty)
		return 1;
	else return 0;
}
const char *Rook::draw()const{
	return pNamePtr;
}

int Bishop::canmove(Column clmn, int row)const{
	bool isRoadEmpty = true;
	int rw = y;  //row aşağıdaki for loopları içide arttırılacak. orjinal degerinin korunması için kopya üzerinden işlem yapıyoruz

	if (abs(clmn - x) != abs(row - y))  //böylece sadece çapraz hareket edebilecek
		isRoadEmpty = false;

	if (x < clmn && y < row){  
		rw += 1;
		for (int i = x + 1; i < clmn; i++, rw++){

			if (board[rw][i] != NULL)
				isRoadEmpty = false;
		}
	}
	else if (x>clmn && y > row){
		rw -= 1;
		for (int i = x - 1; i > clmn; i--, rw--){
			if (board[rw][i] != NULL)
				isRoadEmpty = false;
		}
	}
	else if (x > clmn && y < row){
		rw += 1;
		for (int i = x - 1; i > clmn; i--, rw++){
			if (board[rw][i] != NULL)
				isRoadEmpty = false;
		}
	}
	else if (x<clmn && y>row){
		rw -= 1;
		for (int i = x + 1; i < clmn; i++, rw--){
			if (board[rw][i] != NULL)
				isRoadEmpty = false;
		}
	}
	else isRoadEmpty = false;

	if (isRoadEmpty)	return 1;
	else	return 0;

}
const char *Bishop::draw()const{
	return pNamePtr; 
}

int Queen::canmove(Column clmn, int row)const{
	bool isRoadEmpty = true;

	if (abs(x - clmn) == abs(y - row) || x == clmn || y == row)
		isRoadEmpty = true;
	else
		isRoadEmpty = false;


	if (x == clmn){
		if (y < row){
			for (int i = y + 1; i < row; i++)
				if (board[i][x] != NULL)
					isRoadEmpty = false;
		}
		else if (y > row)
			for (int i = y - 1; i > row; i--)
				if (board[i][x] != NULL)
					isRoadEmpty = false;
	}
	else if (y == row){
		if (x > clmn){
			for (int i = x - 1; i > clmn; i--)
				if (board[y][i] != NULL)
					isRoadEmpty = false;
		}
		else if (x < clmn)
			for (int i = x + 1; i < clmn; i++)
				if (board[y][i] != NULL)
					isRoadEmpty = false;
	}
	if (x == row && y == clmn)
		isRoadEmpty = false;
	
	if (abs(x - clmn) == abs(y - row))
	{
		int rw = y;  //row aşağıdaki for loopları içide arttırılacak. orjinal degerinin korunması için kopya üzerinden işlem yapıyoruz

		if (x < clmn && y < row){
			rw += 1;
			for (int i = x + 1; i < clmn; i++, rw++){
				if (board[rw][i] != NULL)
					isRoadEmpty = false;
			}
		}
		else if (x>clmn && y > row){
			rw -= 1;
			for (int i = x - 1; i > clmn; i--, rw--){
				if (board[rw][i] != NULL)
					isRoadEmpty = false;
			}
		}
		else if (x > clmn && y < row){
			rw += 1;
			for (int i = x - 1; i > clmn; i--, rw++){
				if (board[rw][i] != NULL)
					isRoadEmpty = false;
			}
		}
		else if (x<clmn && y>row){
			rw -= 1;
			for (int i = x + 1; i < clmn; i++, rw--){
				if (board[rw][i] != NULL)
					isRoadEmpty = false;
			}
		}
		else isRoadEmpty = false;
	}
	
	if (isRoadEmpty) return 1; 
	else return 0;
}
const char *Queen::draw()const{
	return pNamePtr;
}

//
int King::canmove(Column clmn, int row)const{
	
	if (x == clmn && y == row)
		return 0;
	
	if ((x == clmn + 1 || x == clmn - 1 || x== clmn) && (y==row || y == row + 1 || y == row - 1))
		return 1;
	else
		return 0;



}
const char *King::draw()const{
	return pNamePtr;
}


Piece *create(const char *piecename, Color clr, Column clmn, int row){
	if (row < 1 || row > 8 || clmn < A || clmn > H){
		throw OutofBoard();

	}
	else{
		if (strcmp(piecename, "pawn") == 0){
			Pawn* created = new Pawn(clr, clmn, row);
			return created;
		}
		else if (strcmp(piecename, "knight") == 0){
			Knight* created = new Knight(clr, clmn, row);
			return created;
		}
		else if (strcmp(piecename, "bishop") == 0){
			Bishop* created = new Bishop(clr, clmn, row);
			return created;
		}
		else if (strcmp(piecename, "rook") == 0){
			Rook* created = new Rook(clr, clmn, row);
			return created;
		}
		else if (strcmp(piecename, "queen") == 0){
			Queen* created = new Queen(clr, clmn, row);
			return created;
		}
		else if (strcmp(piecename, "king") == 0){
			King* created = new King(clr, clmn, row);
			return created;
		}
		else return NULL;
	}
}

bool Piece::isOnBoard(Column clmn, int row){
	if ((clmn >= A && clmn <= H) && (row >= 1 && row <= 8))
		return true;
	else
		return false;
}

bool Piece::isOccupied(Column clmn, int row){
	if (Piece::board[row][clmn] == NULL)
		return false;
	else
		return true;
}
