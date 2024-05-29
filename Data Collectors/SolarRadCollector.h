#ifndef SOLARRADCOLLECTOR_H
#define SOLARRADCOLLECTOR_H

#include "../Data Structures/vector.h"
#include "../Data Structures/DataStructure.h"

/**
 * @brief Collects and processes solar radiation data.
 *
 * This class provides static methods to accumulate solar radiation data, retrieve
 * the collected data, clear the data, and get the size of the collected data.
 *
 * @version 01
 * @autor Trong Tu Le
 */

class SolarRadCollector {
public:
    /**
     * @brief Accumulates solar radiation data from a weather record.
     *
     * @param record The weather record containing the solar radiation data.
     */
    static void accumulateSolarRad(const WeatherRecord& record);

    /**
     * @brief Retrieves the collected solar radiation data.
     *
     * @return A const reference to the vector of collected solar radiation data.
     */
    static const Vector<double>& getSolarRads();

    /**
     * @brief Clears the collected solar radiation data.
     */
    static void clear();

    /**
     * @brief Retrieves the size of the collected solar radiation data.
     *
     * @return The size of the collected solar radiation data.
     */
    static int Size();

private:
    static Vector<double> solarRads; /// Vector to store collected solar radiation data.
};

#endif
