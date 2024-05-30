#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "../Data Structures/DataStructure.h"
#include <fstream>

//---------------------------------------------------------------------------------
/**
 * @brief Contains all menu-related functions including displaying the menu, handling choices, etc.
 *
 * This file provides functions to interact with the user through a menu interface,
 * process their choices, and handle specific cases related to weather data.
 *
 * @version 01
 *
 * @file MenuFunctions.h
 * @author Trong Tu Le
 */
/**
 * @brief Displays the menu and processes user choices.
 */
void menu();

/**
 * @brief Displays the menu options.
 */
void showMenu();

/**
 * @brief Function to process user's menu choice and call the appropriate handler.
 *
 * @param choice The user's menu choice.
 * @return True if the user chooses to exit, false otherwise.
 */
bool processChoice(int choice);

/**
 * @brief Handles the first case: processes wind speed data for a specific month and year.
 */
void firstCaseHandler();

/**
 * @brief Accumulates wind speed data from weather records.
 *
 * @param windSpeeds Vector to store wind speed data.
 * @param record_data Vector of weather records.
 */
void accumulateSpeed(Vector<double>& windSpeeds, const Vector<WeatherRecord>& record_data);

/**
 * @brief Outputs the wind speed data for a specific month and year.
 *
 * @param windSpeeds Vector of wind speed data.
 * @param month The month for which data is being processed.
 * @param year The year for which data is being processed.
 */
void firstCaseOutput(const Vector<double>& windSpeeds, int month, int year);

/**
 * @brief Handles the second case: processes temperature data for a specific year.
 */
void secondCaseHandler();

/**
 * @brief Accumulates temperature data from weather records.
 *
 * @param temperatures Vector to store temperature data.
 * @param record_data Vector of weather records.
 */
void accumulateAirTemp(Vector<double>& temperatures, const Vector<WeatherRecord>& record_data);

/**
 * @brief Outputs the temperature data for a specific month.
 *
 * @param temperatures Vector of temperature data.
 * @param month The month for which data is being processed.
 */
void secondCaseOutput(const Vector<double>& temperatures, int month);

/**
 * @brief Handles the third case: processes and outputs correlation coefficients.
 */
void thirdCaseHandler();

/**
 * @brief Accumulates solar radiation data from weather records.
 *
 * @param solarRads Vector to store solar radiation data.
 * @param record_data Vector of weather records.
 */
void accumulateSolarRad(Vector<double>& solarRads, const Vector<WeatherRecord>& record_data);

/**
 * @brief Handles the fourth case: processes and outputs multiple types of weather data for a specific year.
 */
void fourthCaseHandler();

/**
 * @brief Outputs the weather data to a file for a specific month.
 *
 * @param outFile Output file stream.
 * @param windSpeeds Vector of wind speed data.
 * @param temperatures Vector of temperature data.
 * @param solarRadiations Vector of solar radiation data.
 * @param month The month for which data is being processed.
 */
void fourthCaseOutput(std::ofstream& outFile, const Vector<double>& windSpeeds, const Vector<double>& temperatures, const Vector<double>& solarRadiations, int month);

//---------------------------------------------------------------------------------
#endif
