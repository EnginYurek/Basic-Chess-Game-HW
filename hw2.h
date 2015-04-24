/*
Object Oriented Programming HW2
Engin Yürek
040100524

CRN:22490


*/

//All of my class definitions are below

# include <iostream>
using namespace std;


class Exception {

	const char *mess;

public:

	Exception(const char *m) { mess = m; }

	void output() { cerr << mess << "\n"; }

};


// A piece with invalid color value is tried to be constructed
class InvalidColor : public Exception {

public:

	InvalidColor() : Exception(" Invalid piece color ") {}

};


// A move outside of the board is attempted
class OutofBoard : public Exception {

public:

	OutofBoard() : Exception(" Out of the Board ") {}

};


// A piece is tried to be placed on an already occupied cell
class Occupied : public Exception {

public:

	Occupied() : Exception(" Location is occupied ") {}

};


// An invalid move is targeted for the piece kind
class CannotMove : public Exception {

public:

	CannotMove() : Exception(" Cannot move there ") {}

};


// A piece is expected on the cell but , the cell is empty
class EmptyCell : public Exception {

public:

	EmptyCell() : Exception("The cell is empty , no piece there ") {}

};


enum Color { BLACK, WHITE };
enum Column { A, B, C, D, E, F, G, H, OUT };


const char ctoname[] = "ABCDEFGH "; // convert Column type to character
// for printing . ctoname [A] is ’A’


const char coltoname[][10] = { "BLACK", "WHITE" }; // convert Color type to color
// name . coltoname [ BLACK ] is " BLACK "


// macro to convert character input into Column name nametoc (’a ’) is A ,
// nametoc (’H ’) is H.
#define nametoc(a)(( 'a'<= a && a<='h')?( Column ) (a-'a'):('A' <= a && a <= 'H')?(Column) (a - 'A'):OUT)


// Base abstract class .
class Piece {

protected:
	static Piece * board[9][OUT];					// board is a class member variable

	Color color;									// BLACK or WHITE
	Column x;									// A to H

	int y;										// 1 to 8. 8 is top , 1 is bottom


	// each piece kind (Pawn , Knight , Bishop , Rook , Queen , King ) decides on its own f
	virtual int canmove(Column, int) const = 0;


	// each piece returns a string denoting itself (P, N, B, R, Q, K)
	virtual const char * draw() const = 0;

public:

	// throws OutofBoard , Occupied
	Piece(Color clr, Column clmn, int row);


	Color getcolor() const { return color; }


	// throws OutofBoard , CannotMove
	void move(Column clmn, int row);


	// throws EmptyCell
	static Piece * getpiece(Column clmn, int row);


	// draw the current state of the board , uses draw functions from pieces
	static void drawboard() {
		const char empty[] =
			"|       |       |       |       |       |       |       |       |\n";
		const char line[] =
			"+-------+-------+-------+-------+-------+-------+-------+-------+\n";
		cout << line << empty;
		for (int r = 8; r >0; r--) {
			for (int c = A; c <= H; ++c)
			if (board[r][c] == NULL)
				cout << "|       ";
			else
				cout << "| " << board[r][c]->draw() << " ";
			cout << "|\n" << empty << line;

			if (r > 1)
				cout << empty;
		}
	}

	virtual ~Piece(){
		
	};

	static bool isOnBoard(Column clmn, int row);
	static bool isOccupied(Column clmn, int row);
};



// initialize cells to be empty
// create a piece depending on the name given in first argument
// pawn , knight , bishop , rook , queen and king
// returns NULL if no such piece is defined
extern Piece *create(const char *piecename, Color clr, Column clmn, int row);


#ifndef PAWN_H
#define PAWN_H

class Pawn :public Piece{

	string pieceName;
	char *pNamePtr;

public:
	Pawn(Color clr, Column clmn, int row) :Piece(clr, clmn, row){

		if (clr == BLACK){
			pieceName = "* P *";
			pNamePtr = &pieceName[0];
		}
		else if (clr == WHITE){
			pieceName = ". P .";
			pNamePtr = &pieceName[0];
		}
		else throw InvalidColor();
		board[row][clmn] = this;
	}

	int canmove(Column clmn, int row)const;
	const char * draw() const;

	~Pawn(){
		cout << "Captured: " << draw() << " at " << ctoname[(int)x] << y << endl;
	};
};
#endif

#ifndef KNIGHT_H
#define KNIGHT_H
class Knight :public Piece{

	string pieceName;
	char *pNamePtr;

public:
	Knight(Color clr, Column clmn, int row) :Piece(clr, clmn, row){

		if (clr == BLACK){
			pieceName = "* N *";
			pNamePtr = &pieceName[0];
		}
		else if (clr == WHITE){
			pieceName = ". N .";
			pNamePtr = &pieceName[0];
		}
		else throw InvalidColor();
		board[row][clmn] = this;
	}

	int canmove(Column clmn, int row)const;
	const char * draw() const;

	~Knight(){
		cout << "Captured: " << draw() << " at " << ctoname[(int)x] << y << endl;
	};
};
#endif

#ifndef ROOK_H
#define ROOK_H
class Rook :public Piece{

	string pieceName;
	char *pNamePtr;

public:
	Rook(Color clr, Column clmn, int row) :Piece(clr, clmn, row){

		if (clr == BLACK){
			pieceName = "* R *";
			pNamePtr = &pieceName[0];
		}
		else if (clr == WHITE){
			pieceName = ". R .";
			pNamePtr = &pieceName[0];
		}
		else throw InvalidColor();
		board[row][clmn] = this;
	}

	int canmove(Column clmn, int row)const;
	const char * draw() const;

	~Rook(){
		cout << "Captured: " << draw() << " at " << ctoname[(int)x] << y << endl;
	};
};
#endif


#ifndef BISHOP_H
#define BISHOP_H
class Bishop :public Piece{

	string pieceName;
	char *pNamePtr;

public:
	Bishop(Color clr, Column clmn, int row) :Piece(clr, clmn, row){

		if (clr == BLACK){
			pieceName = "* B *";
			pNamePtr = &pieceName[0];
		}
		else if (clr == WHITE){
			pieceName = ". B .";
			pNamePtr = &pieceName[0];
		}
		else throw InvalidColor();
		board[row][clmn] = this;
	}

	int canmove(Column clmn, int row)const;
	const char * draw() const;

	~Bishop(){
		cout << "Captured: " << draw() << " at " << ctoname[x] << y << endl;
	}
};
#endif

#ifndef QUEEN_H
#define QUEEN_H
class Queen :public Piece{

	string pieceName;
	char *pNamePtr;

public:
	Queen(Color clr, Column clmn, int row) :Piece(clr, clmn, row){

		if (clr == BLACK){
			pieceName = "* Q *";
			pNamePtr = &pieceName[0];
		}
		else if (clr == WHITE){
			pieceName = ". Q .";
			pNamePtr = &pieceName[0];
		}
		else throw InvalidColor();
		board[row][clmn] = this;
	}

	int canmove(Column clmn, int row)const;
	const char * draw() const;

	~Queen(){
		cout << "Captured: " << draw() << " at " << ctoname[(int)x] << y << endl;
	}
};
#endif

#ifndef KING_H
#define KING_H
class King :public Piece{

	string pieceName;
	char *pNamePtr;

public:
	King(Color clr, Column clmn, int row) :Piece(clr, clmn, row){

		if (clr == BLACK){
			pieceName = "* K *";
			pNamePtr = &pieceName[0];
		}
		else if (clr == WHITE){
			pieceName = ". K .";
			pNamePtr = &pieceName[0];
		} 
		else throw InvalidColor();
		board[row][clmn] = this;
	}

	int canmove(Column clmn, int row)const;
	const char * draw() const;

	~King(){
		cout << "Captured: " << draw() << " at " << ctoname[(int)x] << y << endl;
		if (draw() == "* K *" || draw() == ". K .")
			cout << "Player with " << color << " color loses." << endl;
	}
};
#endif
