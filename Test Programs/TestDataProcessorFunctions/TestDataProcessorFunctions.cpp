// MAIN.CPP
// Main program:
// Open an input file stream, read recorded data, display the menu, and handle the menu options.
#include "../../Data Structures/DataStructure.h"
#include "../../Data Structures/Time.h"
#include "../../Data Structures/Time.cpp"
#include "../../Data Structures/Date.h"
#include "../../Data Structures/Date.cpp"
#include "../../Data Structures/WeatherRecord.h"
#include "../../Data Structures/WeatherRecord.cpp"
#include "../../Data Processor/FileNameReader.h"
#include "../../Data Processor/FileNameReader.cpp"
#include "../../Data Processor/DataProcessor.h"
#include "../../Data Processor/DataProcessor.cpp"
#include "../../Helper Functions/Validator.h"
#include "../../Helper Functions/Validator.cpp"
#include "../../Operator/operator.h"
#include "../../Operator/operator.cpp"
#include <iostream>

//---------------------------------------------------------------------------------

void TestReadTimeFunction() {
    std::string timeStr = "00:30";
    Time time;

    bool result = readTime(timeStr, time);

    std::cout << "Testing readTime function with timeStr: " << timeStr << std::endl;
    std::cout << "Expected: 1, Actual: " << result << std::endl;
    if (result) {
        std::cout << "Time: " << time.GetHour() << ":" << time.GetMinute() << std::endl;
    }
}

//---------------------------------------------------------------------------------

void TestReadDateFunction() {
    std::string dateStr = "01/01/2016";
    Date date;

    bool result = readDate(dateStr, date);

    std::cout << "Testing readDate function with dateStr: " << dateStr << std::endl;
    std::cout << "Expected: 1, Actual: " << result << std::endl;
    if (result) {
        std::cout << "Date: " << date.GetDate() << "/" << date.GetMonth() << "/" << date.GetYear() << std::endl;
    }
}

//---------------------------------------------------------------------------------

void TestReadDateAndTimeFunction() {
    std::string dateTimeStr = "01/01/2016 00:30";
    Date date;
    Time time;

    bool result = readDateAndTime(dateTimeStr, date, time);

    std::cout << "Testing readDateAndTime function with dateTimeStr: " << dateTimeStr << std::endl;
    std::cout << "Expected: 1, Actual: " << result << std::endl;
    if (result) {
        std::cout << "Date: " << date.GetDate() << "/" << date.GetMonth() << "/" << date.GetYear()
                  << ", Time: " << time.GetHour() << ":" << time.GetMinute() << std::endl;
    }
}

//---------------------------------------------------------------------------------

void TestReadWeatherRecordFunction() {
    std::string line = "01/01/2016 00:30,5.3,0.0,22.3";
    int wastIndex = 0;
    int speedIndex = 1;
    int solarRadIndex = 2;
    int airTempIndex = 3;
    WeatherRecord record;

    bool result = readWeatherRecord(line, wastIndex, speedIndex, solarRadIndex, airTempIndex, record);

    std::cout << "Testing readWeatherRecord function with line: " << line << std::endl;
    std::cout << "Expected: 1, Actual: " << result << std::endl;
    if (result) {
        std::cout << "Record: " << record.date.GetDate() << "/" << record.date.GetMonth() << "/" << record.date.GetYear()
                  << " " << record.time.GetHour() << ":" << record.time.GetMinute()
                  << ", " << record.speed << ", " << record.airTemp << ", " << record.solarRad << std::endl;
    }
}

//---------------------------------------------------------------------------------

void TestIsValidHeadersFunction() {
    Map<std::string, int> validHeaderMap;
    validHeaderMap.insert("WAST", 0);
    validHeaderMap.insert("S", 1);
    validHeaderMap.insert("SR", 2);
    validHeaderMap.insert("T", 3);



    Map<std::string, int> invalidHeaderMap;
    invalidHeaderMap.insert("WAST", 0);
    invalidHeaderMap.insert("S", 1);
    invalidHeaderMap.insert("T", 3);

    std::cout << "Testing isValidHeaders function with valid headers: " << std::endl;
    std::cout << "Expected: 1, Actual: " << isValidHeaders(validHeaderMap) << std::endl;

    std::cout << "Testing isValidHeaders function with invalid headers: " << std::endl;
    std::cout << "Expected: 0, Actual: " << isValidHeaders(invalidHeaderMap) << std::endl;
}

//---------------------------------------------------------------------------------

void TestReadHeaderFunction() {
    std::string testFileName = "./data/test.csv";
    std::ifstream inFile(testFileName);

    if (!inFile.is_open()) {
        std::cout << "Error opening file: " << testFileName << std::endl;
        return;
    }

    Map<std::string, int> headerMap;
    readHeader(inFile, headerMap);

    std::cout << "Testing readHeader function with file: " << testFileName << std::endl;
    for (Map<std::string, int>::const_iterator it = headerMap.begin(); it != headerMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    inFile.close();
}

//---------------------------------------------------------------------------------

void outputFunction(const WeatherRecord& data){
    std::cout << data.date.GetMonth() << "/" << data.date.GetMonth() << "/" << data.date.GetYear() << ", " << data.time.GetHour() << ":" << data.time.GetMinute() << ", "  << data.speed << ", " << data.airTemp << ", " << data.solarRad << std::endl;
}

//---------------------------------------------------------------------------------

void TestReadFileFromSourceFunction(WeatherLog& weather_data){
    std::cout << "Testing ReadFileFromSouce Function:" << std::endl;
    readFileFromSource("data/data_source.txt", weather_data);

    weather_data[2016][3].inOrder(outputFunction);
    weather_data[2015][3].inOrder(outputFunction);
}

//---------------------------------------------------------------------------------

void TestReadDataFunction() {
    std::cout << "Testing readData function: " << std::endl;
    WeatherLog weather_data;
    std::string testFileName = "test.csv";

    readData(testFileName, weather_data);

    weather_data[2016][3].inOrder(outputFunction);
}

int main()
{
//-----------------------------------------------------
// Read and Store data
    WeatherLog weather_data;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestReadDataFunction();

    std::cout << "*******************************************************************************************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestReadFileFromSourceFunction(weather_data);

    std::cout << "*******************************************************************************************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestReadHeaderFunction();

    std::cout << "*******************************************************************************************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestIsValidHeadersFunction();

    std::cout << "*******************************************************************************************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestReadWeatherRecordFunction();

    std::cout << "*******************************************************************************************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestReadDateAndTimeFunction();

    std::cout << "*******************************************************************************************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestReadDateFunction();

    std::cout << "*******************************************************************************************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "*******************************************************************************************************************" << std::endl;

    TestReadTimeFunction();

    std::cout << "*******************************************************************************************************************" << std::endl;

//-----------------------------------------------------
    std::cout << "Quit" << std::endl;
    return 0;
}
