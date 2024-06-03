#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

//---------------------------------------------------------------------------------

/**
 * @brief Contains all functions that perform validations of the user input.
 *
 * This class provides static methods to validate various types of user input, such as numbers, dates, times, years, and months.
 *
 * @version 01
 * @autor Trong Tu Le
 */

//---------------------------------------------------------------------------------

/**
 * @brief Checks if the input string represents a valid positive number.
 *
 * @param string The input string to validate.
 * @return true if the input string is a valid positive number, false otherwise.
 */
bool isValidNumber(const std::string& string);

/**
 * @brief Validates if the given day, month, and year form a valid date.
 *
 * @param day The day to validate.
 * @param month The month to validate.
 * @param year The year to validate.
 * @return true if the date is valid, false otherwise.
 */
bool isValidDate(int day, int month, int year);

/**
 * @brief Validates if the given hour and minute form a valid time.
 *
 * @param hour The hour to validate.
 * @param minute The minute to validate.
 * @return true if the time is valid, false otherwise.
 */
bool isValidTime(int hour, int minute);

/**
 * @brief Validates if the given year is valid.
 *
 * @param year The year to validate.
 * @return true if the year is valid, false otherwise.
 */
bool isValidYear(int year);

/**
 * @brief Validates if the given month is valid.
 *
 * @param month The month to validate.
 * @return true if the month is valid, false otherwise.
 */
bool isValidMonth(int month);
//---------------------------------------------------------------------------------

#endif
