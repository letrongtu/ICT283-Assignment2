#ifndef SPEEDCOLLECTOR_H
#define SPEEDCOLLECTOR_H

#include "../Data Structures/vector.h"
#include "../Data Structures/DataStructure.h"

/**
 * @brief Collects and processes wind speed data.
 *
 * This class provides static methods to accumulate wind speed data, retrieve
 * the collected data, clear the data, and get the size of the collected data.
 *
 * @version 01
 * @autor Trong Tu Le
 */

class SpeedCollector {
public:
    /**
     * @brief Accumulates wind speed data from a weather record.
     *
     * @param record The weather record containing the wind speed data.
     */
    static void accumulateSpeed(const WeatherRecord& record);

    /**
     * @brief Retrieves the collected wind speed data.
     *
     * @return A const reference to the vector of collected wind speed data.
     */
    static const Vector<double>& getWindSpeeds();

    /**
     * @brief Clears the collected wind speed data.
     */
    static void clear();

    /**
     * @brief Retrieves the size of the collected wind speed data.
     *
     * @return The size of the collected wind speed data.
     */
    static int Size();

private:
    static Vector<double> windSpeeds; /// Vector to store collected wind speed data.
};

#endif
