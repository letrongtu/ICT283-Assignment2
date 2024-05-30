#ifndef FILENAMEREADER_H
#define FILENAMEREADER_H

//---------------------------------------------------------------------------------

#include "../Data Structures/DataStructure.h"

/**
	 * @brief Contains all functions need to read the input file name
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------
/**
 * @brief Reads weather data from a file and stores it in the WeatherLog structure.
 *
 * This function takes the name of a source file, reads the weather data from it,
 * and stores the data in the provided WeatherLog structure.
 *
 * @param sourceFile The name of the file to read weather data from.
 * @param weather_data The WeatherLog structure to store the read weather data.
 */
void readFileFromSource(const std::string& sourceFile);

#endif
