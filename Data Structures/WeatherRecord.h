#ifndef WEATHERRECORD_H
#define WEATHERRECORD_H

#include "Date.h"
#include "Time.h"

//---------------------------------------------------------------------------------

/**
 * @file WeatherRecord.h
 * @struct WeatherRecord
 * @brief A struct to store weather record
 */
struct WeatherRecord {
    Date date;        /// record date
    Time time;        /// record time
    double speed;     /// record wind speed
    double solarRad;  /// record solar radiation
    double airTemp;   /// record air temperature

    /**
     * @brief Constructor for WeatherRecord
     * @param d Date of the record
     * @param t Time of the record
     * @param s Wind speed of the record
     * @param sr Solar radiation of the record
     * @param at Air temperature of the record
     */
    explicit WeatherRecord(const Date& d = Date(), const Time& t = Time(), double s = 0, double sr = 0, double at = 0);
};

//---------------------------------------------------------------------------------

#endif
