#include "../Data Processor/DataProcessor.h"
#include "../Helper Functions/Validator.h"
#include "../Operator/operator.h"
#include "../Data Collectors/DataCollector.h"
#include <iostream>
#include <fstream>
#include <sstream>

//---------------------------------------------------------------------------------
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

    int lineRead = 0;
    int lineDropped = 0;
    std::string line;
    WeatherRecord record;

    const int wastIndex = headerMap.at("WAST");
    const int speedIndex = headerMap.at("S");
    const int solarRadIndex = headerMap.at("SR");
    const int airTempIndex = headerMap.at("T");

    while (std::getline(inFile, line)) {
        if (readWeatherRecord(line, wastIndex, speedIndex, solarRadIndex, airTempIndex, record)) {

            weather_data[record.date.GetYear()][record.date.GetMonth()].insert(record);
            lineRead++;
        } else {
            lineDropped++;
        }
    }

    inFile.close();

    std::cout << "<<<Data read successfully>>>\n"
              << "Line Read: " << lineRead << "\n"
              << "Line Dropped: " << lineDropped << "\n"
              << "-------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void readHeader(std::ifstream& inFile, Map<std::string, int>& headerMap) {
    std::string line;
    std::getline(inFile, line);

    std::istringstream headerStream(line);
    std::string header;
    int index = 0;

    while (std::getline(headerStream, header, ',')) {
        headerMap.insert(header, index++);
    }
}

bool isValidHeaders(const Map<std::string, int>& headerMap) {
    return headerMap.contains("WAST") &&
           headerMap.contains("S") &&
           headerMap.contains("SR") &&
           headerMap.contains("T");
}

bool readWeatherRecord(const std::string& line, int wastIndex, int speedIndex, int solarRadIndex, int airTempIndex, WeatherRecord& record) {
    std::istringstream lineStream(line);
    std::string cell;
    int currentIndex = 0;

    while (std::getline(lineStream, cell, ',')) {
        if (currentIndex == wastIndex) {
            if (!readDateAndTime(cell, record.date, record.time)) {
                return false;
            }
        }
        else if (currentIndex == speedIndex) {
            try {
                record.speed = std::stod(cell);
            } catch (const std::invalid_argument&) {
                return false;
            }
        }
        else if (currentIndex == solarRadIndex) {
            try {
                record.solarRad = std::stod(cell);
            } catch (const std::invalid_argument&) {
                return false;
            }
        }
        else if (currentIndex == airTempIndex) {
            try {
                record.airTemp = std::stod(cell);
            } catch (const std::invalid_argument&) {
                return false;
            }
        }
        currentIndex++;
    }

    return true;
}

bool readDateAndTime(const std::string& dateTimeTemplate, Date& date, Time& time) {
    std::istringstream ss(dateTimeTemplate);
    std::string dateTemplate, timeTemplate;

    if (!(std::getline(ss, dateTemplate, ' ') && std::getline(ss, timeTemplate))) {
        return false;
    }

    return readDate(dateTemplate, date) && readTime(timeTemplate, time);
}

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
