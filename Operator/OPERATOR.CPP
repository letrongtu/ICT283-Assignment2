#include "operator.h"

//----------------------------------------------------------------------------
// Date

// Less than operator for Date.
bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) return lhs.GetYear() < rhs.GetYear();
    if (lhs.GetMonth() != rhs.GetMonth()) return lhs.GetMonth() < rhs.GetMonth();
    return lhs.GetDate() < rhs.GetDate();
}

//----------------------------------------------------------------------------

// Greater than operator for Date.
bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) return lhs.GetYear() > rhs.GetYear();
    if (lhs.GetMonth() != rhs.GetMonth()) return lhs.GetMonth() > rhs.GetMonth();
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

// Equality operator for Time.
bool operator==(const Time& lhs, const Time& rhs) {
    return lhs.GetHour() == rhs.GetHour() &&
           lhs.GetMinute() == rhs.GetMinute();
}

//----------------------------------------------------------------------------
// WeatherRecord

// Less than operator for WeatherRecord.
bool operator<(const WeatherRecord& lhs, const WeatherRecord& rhs) {
    return lhs.date < rhs.date;
}

//----------------------------------------------------------------------------

// Greater than operator for WeatherRecord.
bool operator>(const WeatherRecord& lhs, const WeatherRecord& rhs) {
    return lhs.date > rhs.date;
}

//----------------------------------------------------------------------------

// Equality operator for WeatherRecord.
bool operator==(const WeatherRecord& lhs, const WeatherRecord& rhs) {
    return lhs.date == rhs.date &&
           lhs.time == rhs.time;
}
