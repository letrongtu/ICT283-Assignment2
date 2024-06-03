// DATE.CPP
//
// Version
// 01 Trong Tu Le
// 02 Trong Tu Le
// Remove overloaded operators
// Date's variables will be initialised in the member initialization list
//
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
#include "date.h"
//----------------------------------------------------------------------------
//Function implementations

// Constructor initializing date, month, and year to zero
Date::Date() : date(0), month(0), year(0){
}

//----------------------------------------------------------------------------

// Constructor initializing date, month, and year with provided values
Date::Date(int d, int m, int y) : date(d), month(m), year(y){
}

//----------------------------------------------------------------------------

// Getter function for retrieving the date
int Date::GetDate() const {
    return date;
}

//----------------------------------------------------------------------------

// Setter function for setting the date
void Date::SetDate(int d) {
    date = d;
}

//----------------------------------------------------------------------------

// Getter function for retrieving the month
int Date::GetMonth() const {
    return month;
}

//----------------------------------------------------------------------------

// Setter function for setting the month
void Date::SetMonth(int m) {
    month = m;
}

//----------------------------------------------------------------------------

// Getter function for retrieving the year
int Date::GetYear() const {
    return year;
}

//----------------------------------------------------------------------------

// Setter function for setting the year
void Date::SetYear(int y) {
    year = y;
}

//----------------------------------------------------------------------------
