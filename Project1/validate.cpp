/*********************************************************************
** Author: William Dam
** Date: 10-09-2019
** Description: validation.cpp is the validation implementation file.
** Both functions are used for input validation.  They receive string
** arguments, check to see if they can be converted to integers,
** then return bool.
*********************************************************************/

#include <iostream>
#include <string>
#include "validate.hpp"

/*********************************************************************
** Description: Input validation function receives string, checks to
** see if it each character is an integer, then returns bool.
** Special range limit: "Integer" must be > 5
*********************************************************************/
bool validateInteger(std::string& incomingString) {
	bool isInteger = 0;
	int errorCount = 0;
	int count = incomingString.length();

	// Step through character array to look for non-digit characters
	for (int i = 0; i < count; i++) {
		// If character is not digit or is decimal
		if (!(isdigit(incomingString[i])) || incomingString[i] == '.') {
			errorCount++;	// Count number of non-digit characters
		}
	}

	// If no errors found...
	if (errorCount == 0) {
		// Convert input to integer
		int convertedInteger;
		convertedInteger = stoi(incomingString);
		// Check integer for range violation
		if (convertedInteger < 6) {
			isInteger = 0;	// Bool false
		}
		else {
			isInteger = 1;	// Bool true
		}
	}

	else if (errorCount > 0) {
		isInteger = 0;	// Bool false
	}

	return isInteger;
}

/*********************************************************************
** Description: Input validation function receives string, checks to
** see if it each character is an integer, then returns bool.
** Special range limit: "Integer" must be 1 or 2.
*********************************************************************/
bool validateMenuInt(std::string& incomingString) {
	bool isInteger = 0;
	int errorCount = 0;
	int count = incomingString.length();

	// Step through character array to look for non-digit characters
	for (int i = 0; i < count; i++) {
		// If character is not digit or is decimal
		if (!(isdigit(incomingString[i])) || incomingString[i] == '.') {
			errorCount++;	// Count number of non-digit characters
		}
	}

	// If no errors found...
	if (errorCount == 0) {
		// Convert input to integer
		int convertedInteger;
		convertedInteger = stoi(incomingString);
		// Check integer for range violation
		if (convertedInteger < 1 || convertedInteger > 2) {
			isInteger = 0;	// Bool false
		}
		else {
			isInteger = 1;	// Bool true
		}
	}

	else if (errorCount > 0) {
		isInteger = 0;	// Bool false
	}

	return isInteger;
}

/*********************************************************************
** Description: Input validation function receives string, checks to
** see if it each character is an integer, then returns bool.
** Special range limit: "Integer" must be within board row range.
*********************************************************************/
bool validateBoardRow(std::string& incomingString, int r) {
	bool isInteger = 0;
	int errorCount = 0;
	int count = incomingString.length();
	int rowLimit = r - 1;

	// Step through character array to look for non-digit characters
	for (int i = 0; i < count; i++) {
		// If character is not digit or is decimal
		if (!(isdigit(incomingString[i])) || incomingString[i] == '.') {
			errorCount++;	// Count number of non-digit characters
		}
	}

	// If no errors found...
	if (errorCount == 0) {
		// Convert input to integer
		int convertedInteger;
		convertedInteger = stoi(incomingString);
		// Check integer for range violation
		if (convertedInteger < 0 || convertedInteger > rowLimit) {
			isInteger = 0;	// Bool false
		}
		else {
			isInteger = 1;	// Bool true
		}
	}

	else if (errorCount > 0) {
		isInteger = 0;	// Bool false
	}

	return isInteger;
}

/*********************************************************************
** Description: Input validation function receives string, checks to
** see if it each character is an integer, then returns bool.
** Special range limit: "Integer" must be within board column range.
*********************************************************************/
bool validateBoardCol(std::string& incomingString, int c) {
	bool isInteger = 0;
	int errorCount = 0;
	int count = incomingString.length();
	int colLimit = c - 1;

	// Step through character array to look for non-digit characters
	for (int i = 0; i < count; i++) {
		// If character is not digit or is decimal
		if (!(isdigit(incomingString[i])) || incomingString[i] == '.') {
			errorCount++;	// Count number of non-digit characters
		}
	}

	// If no errors found...
	if (errorCount == 0) {
		// Convert input to integer
		int convertedInteger;
		convertedInteger = stoi(incomingString);
		// Check integer for range violation
		if (convertedInteger < 0 || convertedInteger > colLimit) {
			isInteger = 0;	// Bool false
			}
		else {
			isInteger = 1;	// Bool true
		}
	}

	else if (errorCount > 0) {
		isInteger = 0;	// Bool false
	}

	return isInteger;
}