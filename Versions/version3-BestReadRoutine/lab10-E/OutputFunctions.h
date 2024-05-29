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
void outputCorrelationCoef(double s_t, double s_r, double t_r, int month);

#endif
