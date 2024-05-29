// FileNameReader.cpp
// Purpose:
// Contains all functions need to read the input file name
//
// Version 1 - Trong Tu Le

#include "FileNameReader.h"
#include "DataProcessor.h"
#include <iostream>
#include <fstream>
#include <string>

//---------------------------------------------------------------------------------

// Function to read the file name and open the input stream using the file name.

void readFileFromSource(const string& sourceFile, Map<int,Map<int, BST<WeatherRecord>>>& weather_data){
    ifstream sourceInput(sourceFile);
    if (!sourceInput) {
        cout << "Error opening file: " << sourceFile << endl;
        return;
    }

    string fileName;
    while (getline(sourceInput, fileName)) {
        readData(fileName, weather_data);
    }

    sourceInput.close();
}

//---------------------------------------------------------------------------------
