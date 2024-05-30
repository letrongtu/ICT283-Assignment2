#include "../Data Processor/DataProcessor.h"
#include "../Helper Functions/Validator.h"
#include "../Operator/operator.h"
#include <iostream>
#include <fstream>
#include <sstream>

//---------------------------------------------------------------------------------

// Reads weather data from a file and stores it in the WeatherLog.
void readData(const std::string& fileName, WeatherLog& weather_data) {
    std::cout << "Reading file: " << fileName << std::endl;
    std::string fullFileName = "data/" + fileName;
    std::ifstream inFile(fullFileName);
    if (!inFile.is_open()) {
        std::cout << "Error opening file: " << fileName << std::endl;
        return;
    }

    Map<std::string, int> headerMap;
    readHeader(inFile, headerMap);
    if (!isValidHeaders(headerMap)) {
        std::cout << "Required headers missing in file: " << fileName << std::endl;
        return;
    }

    std::string line;
    WeatherRecord record;
    Vector<std::string> rows;

    while (getline(inFile, line)) {
        splitString(line, ',', rows);

        if (readWeatherRecord(rows, headerMap, record)) {
            int year = record.date.GetYear();
            int month = record.date.GetMonth();

            if (!weather_data.contains(year)) {
                weather_data[year] = Map<int, BST<WeatherRecord>>();
            }

            if (!weather_data[year].contains(month)) {
                weather_data[year][month] = BST<WeatherRecord>();
            }

            weather_data[year][month].insert(record);
        }
    }

    inFile.close();

    std::cout << "<<<Data read successfully>>>\n"
              << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
}

//---------------------------------------------------------------------------------

// Reads the header of the weather data file and fills the provided map with header names and their indices.
void readHeader(std::ifstream& inFile, Map<std::string, int>& headerMap) {
    std::string line;
    getline(inFile, line);

    std::istringstream headerStream(line);
    std::string header;
    int index = 0;

    while (std::getline(headerStream, header, ',')) {
        headerMap.insert(header, index);
        index++;
    }
}

//---------------------------------------------------------------------------------

// Validates the headers of the weather data file.
bool isValidHeaders(const Map<std::string, int>& headerMap) {
    return headerMap.contains("WAST") &&
           headerMap.contains("S") &&
           headerMap.contains("SR") &&
           headerMap.contains("T");
}

//---------------------------------------------------------------------------------

// Function to split a string by a delimiter and store the result in a provided Vector
void splitString(const std::string& str, char delimiter, Vector<std::string>& tokens) {
    tokens.Clear();
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.add(token);
    }
}

//---------------------------------------------------------------------------------

// Reads a weather record from a vector of strings and a header map.
bool readWeatherRecord(const Vector<std::string>& rows, const Map<std::string, int>& headerMap, WeatherRecord& record) {
    if (!readDateAndTime(rows[headerMap.at("WAST")], record.date, record.time)) {
        return false;
    }

    try {
        record.speed = std::stod(rows[headerMap.at("S")]);
        record.solarRad = std::stod(rows[headerMap.at("SR")]);
        record.airTemp = std::stod(rows[headerMap.at("T")]);
    } catch (const std::invalid_argument& e) {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------

// Reads a date and time from a template string.
bool readDateAndTime(const std::string& dateTimeTemplate, Date& date, Time& time) {
    std::istringstream ss(dateTimeTemplate);
    std::string dateTemplate, timeTemplate;

    if (!(std::getline(ss, dateTemplate, ' ') && std::getline(ss, timeTemplate))) {
        return false;
    }

    return readDate(dateTemplate, date) && readTime(timeTemplate, time);
}

//---------------------------------------------------------------------------------

// Reads a date from a template string.
bool readDate(const std::string& dateTemplate, Date& date) {
    std::istringstream ss(dateTemplate);
    int day, month, year;
    char firstDelimiter, secondDelimiter;

    if (!(ss >> day >> firstDelimiter >> month >> secondDelimiter >> year) ||
        (firstDelimiter != '/') || (secondDelimiter != '/')) {
        return false;
    }

    if (!isValidDate(day, month, year)) {
        return false;
    }

    date.SetDate(day);
    date.SetMonth(month);
    date.SetYear(year);

    return true;
}

//---------------------------------------------------------------------------------

// Reads a time from a template string.
bool readTime(const std::string& timeTemplate, Time& time) {
    std::istringstream ss(timeTemplate);
    int hour, minute;
    char delimiter;

    if (!(ss >> hour >> delimiter >> minute) || (delimiter != ':')) {
        return false;
    }

    if (!isValidTime(hour, minute)) {
        return false;
    }

    time.SetHour(hour);
    time.SetMinute(minute);

    return true;
}

//---------------------------------------------------------------------------------
