#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include "DataStructure.h"
#include "vector.h"
#include "date.h"
#include "time.h"
#include <string>
#include <map>

//---------------------------------------------------------------------------------

/**
	 * @brief Contains all functions that read and store the read data from data file
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------

void readData(const string& fileName, WeatherLog& weather_data);
map<string, int> readHeader(ifstream& inFile);
bool isValidHeaders(const map<string, int>& headerMap);
Vector<string> getRow(const string& row);
bool isValidCell(const string& cell);
bool readWeatherRecord(const Vector<string>& rows, const map<string, int>& headerMap, WeatherRecord& record);
bool readDateAndTime(const string& dateTimeTemplate, Date& date, Time& time);
bool readDate(const string& dateTemplate, Date& date);
bool readTime(const string& timeTemplate, Time& time);

#endif
