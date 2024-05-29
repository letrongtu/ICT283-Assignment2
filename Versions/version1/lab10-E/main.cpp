// MAIN.CPP
// Main program:
// Open an input file stream, read recorded data, display the menu, and handle the menu options.
#include "DataStructure.h"
#include "FileNameReader.h"
#include "MenuFunctions.h"

#include <iostream>
#include <fstream>
/**
 * @author Trong Tu Le
 * @version 1
 * Read the data from a csv file, store all required data into a WindRecType type Vector. Calculate average speed, standard deviation,
 * and find the data that match with the average speed
 * @version 2
 * Separate additional function declarations and implementations
 */

int main()
{
    using namespace std;
//-----------------------------------------------------
// Read and Store data
    WeatherLog weather_data = readFileFromSource("data/data_source.txt");

//-----------------------------------------------------
    menu(weather_data);
//-----------------------------------------------------
    cout << "Quit" << endl;
    return 0;
}
