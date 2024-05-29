#ifndef FILENAMEREADER_H
#define FILENAMEREADER_H

//---------------------------------------------------------------------------------

#include "DataStructure.h"
#include "Map.h"
#include "BST.h"

/**
	 * @brief Contains all functions need to read the input file name
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------

void readFileFromSource(const string& sourceFile, Map<int,Map<int, BST<WeatherRecord>>>& weather_data);

#endif
