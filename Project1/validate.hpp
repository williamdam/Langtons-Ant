/*********************************************************************
** Author: William Dam
** Date: 10-09-2019
** Description: validation.hpp is the specification file for the
** validation functions, contained in a separate implementation file.
*********************************************************************/

#ifndef validate_hpp
#define validate_hpp

#include <string>

bool validateInteger(std::string& incomingString);		// Function prototypes
bool validateMenuInt(std::string& incomingString);
bool validateBoardRow(std::string& incomingString, int r);
bool validateBoardCol(std::string& incomingString, int c);

#endif