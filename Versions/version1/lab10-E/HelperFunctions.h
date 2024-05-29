#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include "DataStructure.h"

//---------------------------------------------------------------------------------

/**
	 * @brief Contains all functions that calculate the required thing related to weather data.
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------

int readChoice();
int readYear();
int readMonth();
double calculateAverage(const Vector<double>& array);
double calculateStandardDeviation(const Vector<double>& array);
double calculateSumSquared(const Vector<double>& array, double mean);
double calculateTotal(const Vector<double>& array);

#endif
