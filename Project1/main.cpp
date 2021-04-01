/*********************************************************************
** Author: William Dam
** Date: 10-09-2019
** Description: Langton's Ant program that receives user input for
** board size, ant position, and number of iterations of the game.
** EXTRA CREDIT: Random ant location spawning.
*********************************************************************/

#include <iostream>
#include "Ant.hpp"
#include "validate.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

int main() {

	std::cout << "Welcome to a simulation of Langtons Ant, by William Dam." << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "1. Start Langtons Ant simulation\n2. Quit" << std::endl;

	int setOption = 1;			// Option set to 1 for menu loop

	bool optionIsInt = 0;								// Set bool to false for input validation
	std::string enterOption;							// Declare string for input
	while (optionIsInt == 0) {							// Begin input validation loop
		std::cout << "Enter an option: ";
		std::cin >> enterOption;						// Get string input

		optionIsInt = validateMenuInt(enterOption);		// Validate input

		if (optionIsInt == 0) {							// Fail validation and restart looop
			std::cout << "Invalid entry!  You must enter 1 or 2." << std::endl;
		}
	}
	setOption = stoi(enterOption);						// Convert string to integer


	while (setOption == 1) {	// BEGIN GAME LOOP

		// Set rows for board
		bool rowsIsInt = 0;				// Set bool to false for input validation
		std::string enterRows;			// Declare string for input
		int setBoardRows;				// Declare integer for output
		while (rowsIsInt == 0) {		// Begin input validation loop
			std::cout << "Enter number of rows for board: ";
			std::cin >> enterRows;		// Get string input

			rowsIsInt = validateInteger(enterRows);	// Validate input

			if (rowsIsInt == 0) {		// Fail validation and restart loop
				std::cout << "Invalid entry!  You must enter an integer > 5" << std::endl;
			}
		}
		setBoardRows = stoi(enterRows);	// Convert string to integer

		// Set columns for board
		bool colsIsInt = 0;				// Set bool to false for input validation
		std::string enterCols;			// Declare string for input
		int setBoardCols;				// Declare integer for output
		while (colsIsInt == 0) {		// Begin input validation loop
			std::cout << "Enter number of columns for board: ";
			std::cin >> enterCols;		// Get string input

			colsIsInt = validateInteger(enterCols);	// Validate input

			if (colsIsInt == 0) {		// Fail validation and restart loop
				std::cout << "Invalid entry!  You must enter an integer > 5" << std::endl;
			}
		}
		setBoardCols = stoi(enterCols);	// Convert string to integer

		// EXTRA CREDIT: GENERATE RANDOM POSITION FOR ANT
		int setAntRow;					// Declare integers for output
		int setAntCol;
		bool randomAntIsInt = 0;		// Set bool to false for input validation
		std::string enterRandomAnt;		// Declare string for input
		int setRandomAnt;				// Declare integer for output
		while (randomAntIsInt == 0) {	// Begin input validation loop
			std::cout << "**EXTRA CREDIT: Would you like to generate random ant position?" << std::endl;
			std::cout << "Enter 1 for yes, or 2 for no: ";
			std::cin >> enterRandomAnt;	// Get string input

			randomAntIsInt = validateMenuInt(enterRandomAnt);	// Validate input

			if (randomAntIsInt == 0) {	// Fail validation and restart loop
				std::cout << "Invalid entry!  You must enter an integer 1 or 2" << std::endl;
			}
		}
		setRandomAnt = stoi(enterRandomAnt);	// Convert string to integer

		if (setRandomAnt == 1) {						// Generate random ant position
			srand(time(0));								// Seed the random number generator
			setAntRow = rand() % (setBoardRows - 1);	// Set random number for ant row
			setAntCol = rand() % (setBoardCols - 1);	// Set random number for ant column
		}

		else {
			// Set ant row 
			bool antRowIsInt = 0;			// Set bool to false for input validation
			std::string enterAntRow;		// Declare string for input
			while (antRowIsInt == 0) {		// Begin input validation loop
				std::cout << "Enter starting row for ant: ";
				std::cin >> enterAntRow;	// Get string input

				antRowIsInt = validateBoardRow(enterAntRow, setBoardRows);	// Validate input

				if (antRowIsInt == 0) {		// Fail validation and restart loop
					std::cout << "Invalid entry!  You must enter an integer between 0 and " << setBoardRows - 1 << std::endl;
				}
			}
			setAntRow = stoi(enterAntRow);	// Convert string to integer

			// Set ant column 
			bool antColIsInt = 0;			// Set bool to false for input validation
			std::string enterAntCol;		// Declare string for input
			while (antColIsInt == 0) {		// Begin input validation loop
				std::cout << "Enter starting column for ant: ";
				std::cin >> enterAntCol;	// Get string input

				antColIsInt = validateBoardCol(enterAntCol, setBoardCols);	// Validate input

				if (antColIsInt == 0) {		// Fail validation and restart loop
					std::cout << "Invalid entry!  You must enter an integer between 0 and " << setBoardCols - 1 << std::endl;
				}
			}
			setAntCol = stoi(enterAntCol);	// Convert string to integer
		}

		// Set iterations
		bool iterationsIsInt = 0;			// Set bool to false for input validation
		std::string enterIterations;		// Declare string for input
		int setIterations;					// Declare integer for output
		while (iterationsIsInt == 0) {		// Begin input validation loop
			std::cout << "Enter number of steps for simulation: ";
			std::cin >> enterIterations;	// Get string input

			iterationsIsInt = validateInteger(enterIterations);	// Validate input

			if (iterationsIsInt == 0) {		// Fail validation and restart loop
				std::cout << "Invalid entry!  You must enter an integer > 5" << std::endl;
			}
		}
		setIterations = stoi(enterIterations);	// Convert string to integer

		Ant langton(setBoardRows, setBoardCols, setAntRow, setAntCol);		// Declare Ant object

		// Main game loop
		for (int i = 0; i < setIterations; i++) {
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << "Iteration: " << i << std::endl;	// Print iteration
			langton.moveForward();
			langton.printPosition();
			langton.printColor();
			langton.printOrientation();
			std::cout << "---------------------------------------------" << std::endl;

			langton.printBoard();
		}
		
		// Get option to play again or quit
		bool optionIsInt = 0;								// Set bool to false for input validation
		std::string enterOption;							// Declare string for input
		while (optionIsInt == 0) {							// Begin input validation loop
			std::cout << "Enter 1 to play again, or 2 to quit: ";
			std::cin >> enterOption;						// Get string input

			optionIsInt = validateMenuInt(enterOption);		// Validate input

			if (optionIsInt == 0) {							// Fail validation and restart looop
				std::cout << "Invalid entry!  You must enter 1 or 2." << std::endl;
			}
		}
		setOption = stoi(enterOption);						// Convert string to integer

	}	// END GAME LOOP


	return 0;
}