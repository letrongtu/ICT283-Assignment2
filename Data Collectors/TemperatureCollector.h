#ifndef TEMPERATURECOLLECTOR_H
#define TEMPERATURECOLLECTOR_H

#include "../Data Structures/vector.h"
#include "../Data Structures/DataStructure.h"

/**
 * @brief Collects and processes air temperature data.
 *
 * This class provides static methods to accumulate air temperature data,
 * retrieve the collected data, clear the data, and get the size of the collected data.
 *
 * @version 01
 * @autor Trong Tu Le
 */

class TemperatureCollector {
public:
    /**
     * @brief Accumulates air temperature data from a weather record.
     *
     * @param record The weather record containing the air temperature data.
     */
    static void accumulateAirTemp(const WeatherRecord& record);

    /**
     * @brief Retrieves the collected air temperature data.
     *
     * @return A const reference to the vector of collected air temperature data.
     */
    static const Vector<double>& getTemperatures();

    /**
     * @brief Clears the collected air temperature data.
     */
    static void clear();

    /**
     * @brief Retrieves the size of the collected air temperature data.
     *
     * @return The size of the collected air temperature data.
     */
    static int Size();

private:
    static Vector<double> temperatures; /// Vector to store collected air temperature data.
};

#endif
