#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

using namespace std;

//---------------------------------------------------------------------------------

/**
	 * @brief Contains all functions that do the validations of the user input
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------

bool isValidNumber(const string& string);
bool isValidDate(int day, int month, int year);
bool isValidTime(int hour, int minute);
bool isValidYear(int year);
bool isValidMonth(int month);

//---------------------------------------------------------------------------------

#endif
