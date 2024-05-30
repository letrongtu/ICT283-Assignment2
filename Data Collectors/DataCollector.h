#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H

#include "../Data Structures/vector.h"
#include "../Data Structures/DataStructure.h"
#include "../Data Structures/Map.h"

/**
 * @brief Collects and processes weather data.
 *
 * This class provides static methods to accumulate weather data, retrieve
 * the collected data, clear the data, and get the size of the collected data.
 *
 * @version 01
 * @autor Trong Tu Le
 */

class DataCollector {
public:
    /**
     * @brief Accumulates weather data from a weather record.
     *
     * @param record The weather record containing the data.
     */
    static void accumulateData(const WeatherRecord& record);

    /**
     * @brief Retrieves the collected weather data.
     *
     * @return A const reference to the map of collected weather data.
     */
    static const Map<int, Map<int, Vector<WeatherRecord>>>& getData();

    /**
     * @brief Clears the collected weather data.
     */
    static void clear();

private:
    static Map<int, Map<int, Vector<WeatherRecord>>> weather_data; /// Map to store collected weather data.
};

#endif
