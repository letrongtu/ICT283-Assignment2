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
 * @param fileName The name of the file containing the weather data.
 * @param weather_data The WeatherLog object to be populated with data from the file.
 */
void readData(const std::string& fileName, WeatherLog& weather_data);

/**
 * @brief Reads the header of the weather data file and fills the provided map with header names and their indices.
 *
 * @param inFile The input file stream of the weather data file.
 * @param headerMap The map to be filled with header names and their corresponding indices.
 */
void readHeader(std::ifstream& inFile, Map<std::string, int>& headerMap);

/**
 * @brief Validates the headers of the weather data file.
 *
 * @param headerMap The map of header names to indices.
 * @return true if the headers are valid.
 * @return false if the headers are invalid.
 */
bool isValidHeaders(const Map<std::string, int>& headerMap);

/**
 * @brief Splits a string by a delimiter and stores the result in a provided vector.
 *
 * @param str The string to split.
 * @param delimiter The delimiter to use for splitting.
 * @param tokens The vector to store the split tokens.
 */
void splitString(const std::string& str, char delimiter, Vector<std::string>& tokens);

/**
 * @brief Reads a weather record from a vector of strings and a header map.
 *
 * @param rows The vector of strings representing a row of data.
 * @param headerMap The map of header names to indices.
 * @param record The WeatherRecord object to be populated with data from the row.
 * @return true if the weather record was read successfully.
 * @return false if there was an error reading the weather record.
 */
bool readWeatherRecord(const Vector<std::string>& rows, const Map<std::string, int>& headerMap, WeatherRecord& record);

/**
 * @brief Reads a date and time from a template string.
 *
 * @param dateTimeTemplate The string template containing the date and time.
 * @param date The Date object to be populated with the date.
 * @param time The Time object to be populated with the time.
 * @return true if the date and time were read successfully.
 * @return false if there was an error reading the date and time.
 */
bool readDateAndTime(const std::string& dateTimeTemplate, Date& date, Time& time);

/**
 * @brief Reads a date from a template string.
 *
 * @param dateTemplate The string template containing the date.
 * @param date The Date object to be populated with the date.
 * @return true if the date was read successfully.
 * @return false if there was an error reading the date.
 */
bool readDate(const std::string& dateTemplate, Date& date);

/**
 * @brief Reads a time from a template string.
 *
 * @param timeTemplate The string template containing the time.
 * @param time The Time object to be populated with the time.
 * @return true if the time was read successfully.
 * @return false if there was an error reading the time.
 */
bool readTime(const std::string& timeTemplate, Time& time);

#endif
