// TIME.CPP
//
// Version
// 01 Trong Tu Le
// 02 Trong Tu Le
// Time's variables will be initialised in the member initialization list
//
//---------------------------------------------------------------------------------

//Includes
#include "time.h"

//----------------------------------------------------------------------------
//Function implementations

// Constructor initializing hour and minute to zero
Time::Time() : hour(0), minute(0){
}

//----------------------------------------------------------------------------

// Constructor initializing hour and minute with provided values
Time::Time(int h, int m) : hour(h), minute(m){
}

//----------------------------------------------------------------------------

// Getter function for retrieving the hour
int Time::GetHour() const {
    return hour;
}

//----------------------------------------------------------------------------

// Setter function for setting the hour
void Time::SetHour(int h) {
    hour = h;
}

//----------------------------------------------------------------------------

// Getter function for retrieving the minute
int Time::GetMinute() const {
    return minute;
}

//----------------------------------------------------------------------------

// Setter function for setting the minute
void Time::SetMinute(int m) {
    minute = m;
}

//---------------------------------------------------------------------------------
