// Validator.cpp
// Purpose:
// Contains all functions that perform validations of the user input
//
// Version 1 - Trong Tu Le

#include "Validator.h"
#include <regex>

//---------------------------------------------------------------------------------

// Function to check if input is a valid positive number
bool isValidNumber(const std::string& string) {
    std::regex positiveNumberPattern(R"(^\d+(\.\d+)?$)");
    return std::regex_match(string, positiveNumberPattern);
}

//---------------------------------------------------------------------------------

// Function to check if input is a valid date
bool isValidDate(int day, int month, int year) {
    if (!isValidYear(year)) return false;
    if (!isValidMonth(month)) return false;
    if (day < 1 || day > 31) return false;

    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check for leap year
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeapYear && (month == 2)) {
        if (day <= 29) return true;
    } else {
        if (day <= daysInMonth[month - 1]) return true;
    }

    return false;
}

//---------------------------------------------------------------------------------

// Function to check if input is a valid year
bool isValidYear(int year) {
    if (year < 1 || year > 9999) {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------

// Function to check if input is a valid month
bool isValidMonth(int month) {
    if (month < 1 || month > 12) {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------

// Function to check if input is a valid time
bool isValidTime(int hour, int minute) {
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute > 59) return false;

    return true;
}
