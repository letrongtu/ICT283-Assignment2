#include "SpeedCollector.h"

// Initialize the static member
Vector<double> SpeedCollector::windSpeeds;

//---------------------------------------------------------------------------------

/**
 * @brief Accumulates wind speed data from a weather record.
 *
 * @param record The weather record containing the wind speed data.
 */
void SpeedCollector::accumulateSpeed(const WeatherRecord& record) {
    windSpeeds.add(record.speed * SpeedExchangeRate);
}

//---------------------------------------------------------------------------------

/**
 * @brief Retrieves the collected wind speed data.
 *
 * @return A const reference to the vector of collected wind speed data.
 */
const Vector<double>& SpeedCollector::getWindSpeeds() {
    return windSpeeds;
}

//---------------------------------------------------------------------------------

/**
 * @brief Clears the collected wind speed data.
 */
void SpeedCollector::clear() {
    windSpeeds.Clear();
}

//---------------------------------------------------------------------------------

/**
 * @brief Retrieves the size of the collected wind speed data.
 *
 * @return The size of the collected wind speed data.
 */
int SpeedCollector::Size() {
    return windSpeeds.Size();
}
