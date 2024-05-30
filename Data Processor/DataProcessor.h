#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include "../Data Structures/DataStructure.h"
#include "../Data Structures/vector.h"
#include "../Data Structures/Date.h"
#include "../Data Structures/Time.h"
#include "../Data Structures/Map.h"
#include <string>
#include <fstream>

/**
 * @brief Contains all functions that read and store the read data from a data file.
 *
 * This module provides functionality to read weather data from a file, process it,
 * and store it in the WeatherLog data structure.
 *
 * @version 01
 *
 * @file DataProcessor.h
 */

/**
 * @brief Reads weather data from a file and stores it in the WeatherLog.
 *
 * @param fileName The name of the file to read data from.
 * @param weather_data The WeatherLog to store the weather records.
 */
void readData(const std::string& fileName);

/**
 * @brief Reads the header of the weather data file and fills the provided map with header names and their indices.
 *
 * @param inFile The input file stream.
 * @param headerMap The map to store the header names and their indices.
 */
void readHeader(std::ifstream& inFile, Map<std::string, int>& headerMap);

/**
 * @brief Validates the headers of the weather data file.
 *
 * @param headerMap The map containing the header names and their indices.
 * @return True if the required headers are present, false otherwise.
 */
bool isValidHeaders(const Map<std::string, int>& headerMap);

/**
 * @brief Reads a weather record from a line and a header map.
 *
 * @param line The line from the weather data file.
 * @param wastIndex The index of the WAST header.
 * @param speedIndex The index of the speed header.
 * @param solarRadIndex The index of the solar radiation header.
 * @param airTempIndex The index of the air temperature header.
 * @param record The WeatherRecord to store the parsed data.
 * @return True if the record was successfully read, false otherwise.
 */
bool readWeatherRecord(const std::string& line, int wastIndex, int speedIndex, int solarRadIndex, int airTempIndex, WeatherRecord& record);

/**
 * @brief Reads a date and time from a template string.
 *
 * @param dateTimeTemplate The template string containing the date and time.
 * @param date The Date object to store the parsed date.
 * @param time The Time object to store the parsed time.
 * @return True if the date and time were successfully read, false otherwise.
 */
bool readDateAndTime(const std::string& dateTimeTemplate, Date& date, Time& time);

/**
 * @brief Reads a date from a template string.
 *
 * @param dateTemplate The template string containing the date.
 * @param date The Date object to store the parsed date.
 * @return True if the date was successfully read, false otherwise.
 */
bool readDate(const std::string& dateTemplate, Date& date);

/**
 * @brief Reads a time from a template string.
 *
 * @param timeTemplate The template string containing the time.
 * @param time The Time object to store the parsed time.
 * @return True if the time was successfully read, false otherwise.
 */
bool readTime(const std::string& timeTemplate, Time& time);

#endif
