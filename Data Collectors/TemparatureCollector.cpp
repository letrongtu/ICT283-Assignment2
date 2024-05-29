#include "TemperatureCollector.h"

// Initialize the static member
Vector<double> TemperatureCollector::temperatures;

//---------------------------------------------------------------------------------

/**
 * @brief Accumulates air temperature data from a weather record.
 *
 * @param record The weather record containing the air temperature data.
 */
void TemperatureCollector::accumulateAirTemp(const WeatherRecord& record) {
    temperatures.add(record.airTemp);
}

//---------------------------------------------------------------------------------

/**
 * @brief Retrieves the collected air temperature data.
 *
 * @return A const reference to the vector of collected air temperature data.
 */
const Vector<double>& TemperatureCollector::getTemperatures() {
    return temperatures;
}

//---------------------------------------------------------------------------------

/**
 * @brief Clears the collected air temperature data.
 */
void TemperatureCollector::clear() {
    temperatures.Clear();
}

//---------------------------------------------------------------------------------

/**
 * @brief Retrieves the size of the collected air temperature data.
 *
 * @return The size of the collected air temperature data.
 */
int TemperatureCollector::Size() {
    return temperatures.Size();
}
