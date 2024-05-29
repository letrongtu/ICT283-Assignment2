#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include "date.h"
#include "time.h"
#include "vector.h"
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
typedef struct {
    Date date; /// record date
    Time time; /// record time
    double speed; /// record wind speed
	double solarRad; /// record solar radiation
	double airTemp; /// record air temperatrue
} WeatherRecord;

/// a vector array of WeatherRecord
typedef Vector<WeatherRecord> WeatherLog;

#endif
