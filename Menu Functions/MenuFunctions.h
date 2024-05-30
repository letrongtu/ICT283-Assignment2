#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "../Data Structures/DataStructure.h"
#include "../Data Structures/vector.h"
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
 *
 * @param weather_data The WeatherLog object containing weather records.
 */
void menu(const WeatherLog& weather_data);

/**
 * @brief Displays the menu options.
 */
void showMenu();

/**
 * @brief Processes the user's choice from the menu.
 *
 * @param weather_data The WeatherLog object containing weather records.
 * @param choice The user's choice as an integer.
 * @return true if the choice was processed successfully.
 * @return false if the choice was invalid or indicated an exit.
 */
bool processChoice(const WeatherLog& weather_data, int choice);

/**
 * @brief Handles the first case from the menu.
 *
 * This function processes wind speed data for a specific month and year.
 *
 * @param weather_data The WeatherLog object containing weather records.
 */
void firstCaseHandler(const WeatherLog& weather_data);

void accumulateSpeed(Vector<double>& windSpeeds, const Vector<WeatherRecord>& data);

/**
 * @brief Outputs the wind speed data for a specific month and year.
 *
 * @param windSpeeds A vector containing the wind speed data.
 * @param month The month for which the data is output.
 * @param year The year for which the data is output.
 */
void firstCaseOutput(const Vector<double>& windSpeeds, int month, int year);

/**
 * @brief Handles the second case from the menu.
 *
 * This function processes temperature data for a specific month and year.
 *
 * @param weather_data The WeatherLog object containing weather records.
 */
void secondCaseHandler(const WeatherLog& weather_data);

void accumulateAirTemp(Vector<double>& temperatures, const Vector<WeatherRecord>& data);

/**
 * @brief Outputs the temperature data for a specific month and year.
 *
 * @param temperatures A vector containing the air temperature data.
 * @param month The month for which the data is output.
 * @param year The year for which the data is output.
 */
void secondCaseOutput(const Vector<double>& temperatures, int month);

/**
 * @brief Handles the third case from the menu.
 *
 * This function processes solar radiation data for a specific month and year.
 *
 * @param weather_data The WeatherLog object containing weather records.
 */
void thirdCaseHandler(const WeatherLog& weather_data);

void accumulateSolarRad(Vector<double>& solarRads, const Vector<WeatherRecord>& data);

/**
 * @brief Handles the fourth case from the menu.
 *
 * This function processes and outputs multiple types of weather data for a specific month.
 *
 * @param weather_data The WeatherLog object containing weather records.
 */
void fourthCaseHandler(const WeatherLog& weather_data);

/**
 * @brief Outputs the weather data to a file for a specific month.
 *
 * @param outFile The output file stream.
 * @param windSpeeds A vector containing the wind speed data.
 * @param temperatures A vector containing the temperature data.
 * @param solarRadiations A vector containing the solar radiation data.
 * @param month The month for which the data is output.
 */
void fourthCaseOutput(std::ofstream& outFile, const Vector<double>& windSpeeds, const Vector<double>& temperatures, const Vector<double>& solarRadiations, int month);

//---------------------------------------------------------------------------------
#endif
