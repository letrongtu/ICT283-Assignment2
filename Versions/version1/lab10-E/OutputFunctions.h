#ifndef OUTPUTFUNCTIONS_H
#define OUTPUTFUNCTIONS_H

#include "DataStructure.h"

//---------------------------------------------------------------------------------

/**
	 * @brief Contains all needed output functions
	 *
	 * @author Trong Tu Le
	 * @version 01
	 */

//---------------------------------------------------------------------------------

void outputWindSpeed(double avg, double sd, int month, int year);
void outputAirTemp(double avg, double sd, int month);
void outputSolarRad(double total, int month);
void outputEverything(const double avgSpeedArray[], const double speedSdArray[], const double avgAirTempArray[], const double airTempSdArray[], const double totalSolarRadArray[], int year);

#endif
