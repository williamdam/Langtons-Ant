#include <iostream>
#include "Ant.hpp"

/*********************************************************************
** Description: Default constructor for class Ant.  Initializes
** variables, allocates dynamic memory, and initializes game board.
*********************************************************************/
Ant::Ant() {
	
	boardRows = 12;		// Set board rows default value
	boardCols = 12;		// Set board columns default value
	antRow = 6;			// Set ant row default value
	antCol = 6;			// Set ant column default value
	onColor = 0;		// Set color of square default value
	orientation = 0;	// Set orientation default value

	// Allocate dynamic memory for ant farm
	gameBoard = new char* [boardRows];
	for (int i = 0; i < boardRows; i++) {
		gameBoard[i] = new char[boardCols];
	}

	// Open up the ant farm based on rows/cols
	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			gameBoard[i][j] = ' ';
		}
	}

}

/*********************************************************************
** Description: Constructor for class Ant.  Receives arguments from
** main to initialize variables, allocates dynamic memory, and 
** initializes game board.
*********************************************************************/
Ant::Ant(int br, int bc, int ar, int ac) {
	boardRows = br;		// Set board rows using passed argument
	boardCols = bc;		// Set board columns using passed argument
	antRow = ar;		// Set ant row using passed argument
	antCol = ac;		// Set ant column using passed argument
	onColor = 0;		// Set color of square default
	orientation = 0;	// Set orientation default

	// Allocate dynamic memory for ant farm
	gameBoard = new char* [boardRows];
	for (int i = 0; i < boardRows; i++) {
		gameBoard[i] = new char[boardCols];
	}

	// Open up the ant farm based on rows/cols
	for (int i = 0; i < boardRows; i++) {
		for (int j = 0; j < boardCols; j++) {
			gameBoard[i][j] = ' ';
		}
	}
}

/*********************************************************************
** Description: Print the game board to display values in each square.
*********************************************************************/
void Ant::printBoard() {
	
	// Print top border
	for (int i = 0; i < boardCols + 2; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;

	// Print array with ant position
	for (int i = 0; i < boardRows; i++) {
		std::cout << "|";		// Print left border
		for (int j = 0; j < boardCols; j++) {
			std::cout << gameBoard[i][j];
		}
		std::cout << "|";		// Print right border
		std::cout << std::endl;	// Line down between rows
	}

	// Print bottom border
	for (int i = 0; i < boardCols + 2; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}

/*********************************************************************
** Description: Switch display color of square between black and white.
*********************************************************************/
void Ant::switchColor() {

	// If square is white change square display color to black
	if (onColor == 0) {
		gameBoard[antRow][antCol] = '#';
	}
	// If square is black, change display color to white
	else if (onColor == 1) {
		gameBoard[antRow][antCol] = ' ';
	}
}

/*********************************************************************
** Description: Get color of square that ant is going to.
*********************************************************************/
void Ant::getColor() {	// Gets the next color before moving

	// Get next color if ant is facing up
	if (orientation == 0) {
		if (gameBoard[antRow - 1][antCol] == ' ') {
			onColor = 0;
		}
		else if (gameBoard[antRow - 1][antCol] == '#') {
			onColor = 1;
		}
	}

	// Get next color if ant is facing right
	else if (orientation == 1) {
		if (gameBoard[antRow][antCol + 1] == ' ') {
			onColor = 0;
		}
		else if (gameBoard[antRow][antCol + 1] == '#') {
			onColor = 1;
		}
	}

	// Get next color if ant is facing down
	else if (orientation == 2) {
		if (gameBoard[antRow + 1][antCol] == ' ') {
			onColor = 0;
		}
		else if (gameBoard[antRow + 1][antCol] == '#') {
			onColor = 1;
		}
	}

	// Get next color if ant is facing left
	else if (orientation == 3) {
		if (gameBoard[antRow][antCol - 1] == ' ') {
			onColor = 0;
		}
		else if (gameBoard[antRow][antCol - 1] == '#') {
			onColor = 1;
		}
	}
}

/*********************************************************************
** Description: Update orientation of ant based on color of square.
*********************************************************************/
void Ant::setOrientation() {
	
	// If square is white
	if (onColor == 0) {
		orientation++;	// Turn right
	}

	// If square is black
	else if (onColor == 1) {
		orientation--;	// Turn left
	}

	// Reset orientation if increments out of range
	if (orientation == -1) {
		orientation = 3;
	}
	else if (orientation == 4) {
		orientation = 0;
	}
}

/*********************************************************************
** Description: Populate square with '*' based on ant location.
*********************************************************************/
void Ant::placeAnt() {
	gameBoard[antRow][antCol] = '*';
}

/*********************************************************************
** Description: Get color of square that ant is on.
*********************************************************************/
void Ant::getOnColor() {
	if (gameBoard[antRow][antCol] == ' ') {
		onColor = 0;
	}
	else if (gameBoard[antRow][antCol] == '#') {
		onColor = 1;
	}
}

/*********************************************************************
** Description: Move ant forward 1 square, based on orientation.
*********************************************************************/
void Ant::moveForward() {

	// If ant is facing up
	if (orientation == 0) {
		switchColor();					// Switch display color of square
		if (antRow == 0) {				// Edge case
			antRow = boardRows - 1;
		}
		else {
			antRow--;					// Move forward
		}
		getOnColor();					// Get color of square
		placeAnt();						// Place ant
		setOrientation();				// Set orientation
	}

	// If ant is facing right
	else if (orientation == 1) {
		switchColor();					// Switch display color of square
		if (antCol == boardCols - 1) {	// Edge case
			antCol = 0;
		}
		else {
			antCol++;					// Move forward
		}
		getOnColor();					// Get color of square
		placeAnt();						// Place ant
		setOrientation();				// Set orientation
	}

	// If ant is facing left
	else if (orientation == 2) {
		switchColor();					// Switch display color of square
		if (antRow == boardRows - 1) {	// Edge case
			antRow = 0;
		}
		else {
			antRow++;					// Move forward
		}
		getOnColor();					// Get color of square
		placeAnt();						// Place ant
		setOrientation();				// Set orientation
	}

	// If ant is facing left
	else if (orientation == 3) {
		switchColor();					// Switch display color of square
		if (antCol == 0) {				// Edge case
			antCol = boardCols - 1;		
		}
		else {
			antCol--;					// Move forward
		}
		getOnColor();					// Get color of square
		placeAnt();						// Place ant
		setOrientation();				// Set orientation
	}
	
}

/*********************************************************************
** Description: Print position (row and column) of ant.
*********************************************************************/
void Ant::printPosition() {
	std::cout << "Ant is now at Row: " << antRow << " Col: " << antCol << std::endl;
}

/*********************************************************************
** Description: Print orientation of ant.
*********************************************************************/
void Ant::printOrientation() {
	if (orientation == 0) {
		std::cout << "Orientation: Up" << std::endl;
	}
	else if (orientation == 1) {
		std::cout << "Orientation: Right" << std::endl;
	}
	else if (orientation == 2) {
		std::cout << "Orientation: Down" << std::endl;
	}
	else if (orientation == 3) {
		std::cout << "Orientation: Left" << std::endl;
	}
}

/*********************************************************************
** Description: Print color of square that ant is on.
*********************************************************************/
void Ant::printColor() {
	if (onColor == 0) {
		std::cout << "Ant is on square color: White" << std::endl;
	}
	else if (onColor == 1) {
		std::cout << "Ant is on square color: Black" << std::endl;
	}
}

/*********************************************************************
** Description: Destructor deallocates dynamic memory.
*********************************************************************/
Ant::~Ant() {
	// Delete sub array
	for (int i = 0; i < boardRows; i++) {
		delete[] gameBoard[i];
	}

	// Delete outside array
	delete[] gameBoard;
}