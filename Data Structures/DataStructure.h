#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include "Map.h"
#include "AVL.H"
#include "WeatherRecord.h"

#include <string>

//---------------------------------------------------------------------------------

/**
 * @brief Contains needed variables and data structures
 *
 * @author Trong Tu Le
 * @version 01
 */

//---------------------------------------------------------------------------------

/// Months' Name
const std::string MonthsNames[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

/// Number of months in a year
const int MonthCounts = 12;

//---------------------------------------------------------------------------------

/// Exchange rate from m/s to km/h
const double SpeedExchangeRate = 3.6;

//---------------------------------------------------------------------------------

/// Exchange rate from W/m2 to kWh/m2
const double RadiationExchangeRate = 0.000167;

//---------------------------------------------------------------------------------

/// Data Structure to store weather data
typedef Map<int, Map<int, AVL<WeatherRecord>>> WeatherLog;

#endif
