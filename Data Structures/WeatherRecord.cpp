#include "WeatherRecord.h"

// Constructor for WeatherRecord
WeatherRecord::WeatherRecord(const Date& d, const Time& t, double s, double sr, double at)
    : date(d), time(t), speed(s), solarRad(sr), airTemp(at) {}
