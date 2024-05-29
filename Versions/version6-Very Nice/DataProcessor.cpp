// DataProcessor.cpp
// Purpose:
// Contains all functions that read and store the read data from data file
//
// Version 1 - Trong Tu Le

#include "DataProcessor.h"
#include "Validator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

//---------------------------------------------------------------------------------

// Reads and processes weather data from an input stream and stores it.
void readData(const string& fileName, WeatherLog& weather_data){

    cout << "Reading file: " << fileName << endl;
    string fullFileName = "data/" + fileName;
    ifstream inFile(fullFileName);
    if (!inFile.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }

    Map<string, int> headerMap = readHeader(inFile);
    if(!isValidHeaders(headerMap)){
        cout << "Required headers missing in file: " << fileName << endl;
        return;
    }

    string line;
    int lineRead = 0;
    int lineDrop = 0;
    while(getline(inFile, line)){
        WeatherRecord record;
        Vector<string> rows = getRow(line);

        if(isValidCell(rows[headerMap.at("WAST")]) && isValidCell(rows[headerMap.at("S")]) && isValidCell(rows[headerMap.at("SR")]) && isValidCell(rows[headerMap.at("T")])){
            if (readWeatherRecord(rows, headerMap, record)) {
                int year = record.date.GetYear();
                int month = record.date.GetMonth();

                if(!weather_data[year].contains(month)){
                    weather_data[year][month] =  BST<WeatherRecord>();
                }

                if(!weather_data.contains(year)){
                    weather_data[year] =  Map<int, BST<WeatherRecord>>();
                }

                weather_data[year][month].insert(record);

                lineRead++;
            }
            else{
                lineDrop++;
            }
        }
        else{
            lineDrop++;
        }
    }

    inFile.close();

    cout << "<<<Data read successfully>>>" << "\n"
         << "Line Read: " << lineRead << "\n"
         << "Line Drop: " << lineDrop << "\n"
         << "-------------------------------------------------------------------------------------------------------------------"
         << endl;
}

//---------------------------------------------------------------------------------

Map<string, int> readHeader(ifstream& inFile) {
    Map<string, int> headerMap;
    string line;

    getline(inFile, line);

    istringstream headerStream(line);
    string header;
    int index = 0;

    while (getline(headerStream, header, ',')) {
        headerMap[header] = index;
        index++;
    }

    return headerMap;
}

bool isValidHeaders(const Map<string, int>& headerMap){
    if (headerMap.contains("WAST")||
        headerMap.contains("S") ||
        headerMap.contains("SR") ||
        headerMap.contains("T")) {
        return true;
    }
    else{
        return false;
    }
}

Vector<string> getRow(const string& row){
    Vector<string> cells;

    stringstream ss(row);
    string cell;

    while(getline(ss, cell, ',')){
        cells.add(cell);
    }

    return cells;
}

bool isValidCell(const string& cell) {
    if(cell == "" || cell == "N/A"){
        return false;
    }
    else{
        return true;
    }
}

bool readWeatherRecord(const Vector<string>& rows, const Map<string, int>& headerMap, WeatherRecord& record){
    if(!readDateAndTime(rows[headerMap.at("WAST")], record.date, record.time)){
        return false;
    }

    string speedCell = rows[headerMap.at("S")];
    string solarRadCell = rows[headerMap.at("SR")];
    string temperatureCell = rows[headerMap.at("T")];

    try{
        record.speed = stod(speedCell);
        record.airTemp = stod(temperatureCell);
        record.solarRad = stod(solarRadCell);
    }
    catch (const invalid_argument& e){
        return false;
    }

    return true;
}

bool readDateAndTime(const string& dateTimeTemplate, Date& date, Time& time){
    istringstream ss(dateTimeTemplate);

    string dateTemplate, timeTemplate;

    if(!(getline(ss, dateTemplate, ' ') && getline(ss, timeTemplate))){
        return false;
    }

    if(!(readDate(dateTemplate, date) && readTime(timeTemplate, time))){
        return false;
    }

    return true;
}

bool readDate(const string& dateTemplate, Date& date){
    istringstream ss(dateTemplate);

    int day, month, year;
    char firstDelimiter, secondDelimiter;

    if(!(ss >> day >> firstDelimiter >> month >> secondDelimiter >> year) || (firstDelimiter != '/') || (secondDelimiter != '/')){
        return false;
    }

    if(!isValidDate(day, month, year)){
        return false;
    }

    date.SetDate(day);
    date.SetMonth(month);
    date.SetYear(year);

    return true;
}

bool readTime(const string& timeTemplate, Time& time){
    istringstream ss(timeTemplate);

    int hour, minute;
    char delimiter;

    if(!(ss >> hour >> delimiter >> minute) || (delimiter != ':')){
        return false;
    }

    if(!isValidTime(hour, minute)){
        return false;
    }

    time.SetHour(hour);
    time.SetMinute(minute);

    return true;
}
