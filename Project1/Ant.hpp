#ifndef Ant_hpp
#define Ant_hpp

class Ant {

private:
	int boardRows;		// Number of rows in board
	int boardCols;		// Number of columns in board
	int antRow;			// Row position of ant
	int antCol;			// Column position of ant
	int onColor;		// Color of the square that ant is on (0 = white, 1 = black)
	int orientation;	// Orientation of ant (0 = up, 1 = right, 2 = down, 3 = left)
	char** gameBoard;	// Game board

public:		
	Ant();						// Default constructor
	Ant(int, int, int, int);	// Constructor
	void printBoard();			// Print board
	void switchColor();			// Removes * ant & places # or ' '
	void getColor();			// Gets color of next square
	void getOnColor();			// Gets color that ant is on now
	void setOrientation();		// Sets orientation of ant (0 = up, 1 = right, 2 = down, 3 = left)
	void placeAnt();			// Places * ant
	void moveForward();			// Move forward 1 square
	void printColor();			// Print color that ant is on
	void printOrientation();	// Print ant's orientation
	void printPosition();		// Print ant's position

	~Ant();
};

#endif