#include "operator.h"

//----------------------------------------------------------------------------
// Date

// Less than operator for Date.
bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) return true;
    if (lhs.GetMonth() > rhs.GetMonth()) return false;
    return lhs.GetDate() < rhs.GetDate();
}

//----------------------------------------------------------------------------

// Greater than operator for Date.
bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() > rhs.GetYear()) return true;
    if (lhs.GetMonth() < rhs.GetMonth()) return false;
    return lhs.GetDate() > rhs.GetDate();
}

//----------------------------------------------------------------------------

// Equality operator for Date.
bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.GetYear() == rhs.GetYear() &&
           lhs.GetMonth() == rhs.GetMonth() &&
           lhs.GetDate() == rhs.GetDate();
}

//----------------------------------------------------------------------------
// Time

bool operator<(const Time& lhs, const Time& rhs) {
    if(lhs.GetHour() < rhs.GetHour()) return true;
    if(lhs.GetHour() > rhs.GetHour()) return false;
    return lhs.GetMinute() < rhs.GetMinute();
}

bool operator>(const Time& lhs, const Time& rhs) {
    if(lhs.GetHour() > rhs.GetHour()) return true;
    if(lhs.GetHour() < rhs.GetHour()) return false;
    return lhs.GetMinute() > rhs.GetMinute();
}

// Equality operator for Time.
bool operator==(const Time& lhs, const Time& rhs) {
    return lhs.GetHour() == rhs.GetHour() &&
           lhs.GetMinute() == rhs.GetMinute();
}

//----------------------------------------------------------------------------
// WeatherRecord

// Less than operator for WeatherRecord.
bool operator<(const WeatherRecord& lhs, const WeatherRecord& rhs) {
    if(lhs.date < rhs.date) return true;
    if(lhs.date > rhs.date) return false;
    return (lhs.time < rhs.time);
}

//----------------------------------------------------------------------------

// Greater than operator for WeatherRecord.
bool operator>(const WeatherRecord& lhs, const WeatherRecord& rhs) {
    if(lhs.date > rhs.date) return true;
    if(lhs.date < rhs.date) return false;
    return (lhs.time > rhs.time);
}

//----------------------------------------------------------------------------

// Equality operator for WeatherRecord.
bool operator==(const WeatherRecord& lhs, const WeatherRecord& rhs) {
    return lhs.date == rhs.date &&
           lhs.time == rhs.time;
}
