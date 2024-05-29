#include "SolarRadCollector.h"

// Initialize the static member
Vector<double> SolarRadCollector::solarRads;

//---------------------------------------------------------------------------------

/**
 * @brief Accumulates solar radiation data from a weather record.
 *
 * @param record The weather record containing the solar radiation data.
 */
void SolarRadCollector::accumulateSolarRad(const WeatherRecord& record) {
    solarRads.add(record.solarRad * RadiationExchangeRate);
}

//---------------------------------------------------------------------------------

/**
 * @brief Retrieves the collected solar radiation data.
 *
 * @return A const reference to the vector of collected solar radiation data.
 */
const Vector<double>& SolarRadCollector::getSolarRads() {
    return solarRads;
}

//---------------------------------------------------------------------------------

/**
 * @brief Clears the collected solar radiation data.
 */
void SolarRadCollector::clear() {
    solarRads.Clear();
}

//---------------------------------------------------------------------------------

/**
 * @brief Retrieves the size of the collected solar radiation data.
 *
 * @return The size of the collected solar radiation data.
 */
int SolarRadCollector::Size() {
    return solarRads.Size();
}
