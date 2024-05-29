#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include "date.h"
#include "time.h"
#include "vector.h"
#include "Map.h"
#include "BST.h"
#include <string>

//---------------------------------------------------------------------------------

/**
	 * @brief Contains needed variables and data structures
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------

using LongInt = long long int;

/// Months' Name
const string MonthsNames[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

/// Number of month in a year
const int MonthCounts = 12;

/// Exchange rate from m/s to km/h
const double SpeedExchangeRate = 3.6;

/// Exchange rate from W/m2 to kWh/m2
const double RadiationExchangeRate = 0.000167;

/// A struct to store weather record
struct WeatherRecord {
    Date date;        /// record date
    Time time;        /// record time
    double speed;     /// record wind speed
    double solarRad;  /// record solar radiation
    double airTemp;   /// record air temperature

    // Default constructor
    WeatherRecord() : speed(0), solarRad(0), airTemp(0) {}

    // Parameterized constructor
    WeatherRecord(const Date& d, const Time& t, double s, double sr, double at)
        : date(d), time(t), speed(s), solarRad(sr), airTemp(at) {}

    // Operator< for WeatherRecord
    bool operator<(const WeatherRecord& rhs) const {
        if (date < rhs.date) {
            return true;
        } else {
            return false;
        }
    }

    // Operator> for WeatherRecord
    bool operator>(const WeatherRecord& rhs) const {
        if (date > rhs.date) {
            return true;
        }else {
            return false;
        }
    }

    // Operator== for WeatherRecord
    bool operator==(const WeatherRecord& rhs) const {
        return (date == rhs.date);
    }
};

/// Data Structure to store weather data
typedef Map<int,Map<int, BST<WeatherRecord>>> WeatherLog;

#endif
