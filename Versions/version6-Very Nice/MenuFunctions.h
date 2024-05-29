#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "DataStructure.h"
#include <fstream>

//---------------------------------------------------------------------------------

/**
	 * @brief Contains all menu-related functions including displaying the menu, handling choices,...
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------

void menu(const WeatherLog& weather_data);
void showMenu();
bool processChoice(const WeatherLog& weather_data, int choice);

void firstCaseHandler(const WeatherLog& weather_data);
void accumulateSpeed(const WeatherRecord& record, Vector<double>& vector);
void firstCaseOutput(const Vector<double>& windSpeeds, int month, int year);
void secondCaseHandler(const WeatherLog& weather_data);
void accumulateAirTemp(const WeatherRecord& record, Vector<double>& vector);
void secondCaseOutput(const Vector<double>& temperatures, int month, int year);
void thirdCaseHandler(const WeatherLog& weather_data);
void accumulateSolarRad(const WeatherRecord& record, Vector<double>& vector);
void fourthCaseHandler(const WeatherLog& weather_data);
void fourthCaseOutput(ofstream& outFile, const Vector<double>& windSpeeds, const Vector<double>& temperatures, const Vector<double>& solarRadiations, int month);

#endif
