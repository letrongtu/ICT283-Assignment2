#ifndef OUTPUTFUNCTIONS_H
#define OUTPUTFUNCTIONS_H

#include "../Data Structures/DataStructure.h"

//---------------------------------------------------------------------------------

/**
 * @brief Contains all needed output functions.
 *
 * This header defines functions required to output weather-related data,
 * including average wind speed, air temperature, and correlation coefficients.
 *
 * @version 01
 * @author Trong Tu Le
 */

//---------------------------------------------------------------------------------

/**
 * @brief Outputs the average wind speed and standard deviation for a given month and year.
 *
 * @param avg The average wind speed.
 * @param sd The standard deviation of the wind speed.
 * @param month The month (1-12).
 * @param year The year.
 */
void outputWindSpeed(double avg, double sd, int month, int year);

/**
 * @brief Outputs the average air temperature and standard deviation for a given month.
 *
 * @param avg The average air temperature.
 * @param sd The standard deviation of the air temperature.
 * @param month The month (1-12).
 */
void outputAirTemp(double avg, double sd, int month);

/**
 * @brief Outputs the correlation coefficients of wind speed, air temperature, and solar radiation for a given month.
 *
 * @param s_t The correlation coefficient between speed and temperature.
 * @param s_r The correlation coefficient between speed and radiation.
 * @param t_r The correlation coefficient between temperature and radiation.
 * @param month The month (1-12).
 */
void outputCorrelationCoef(double s_t, double s_r, double t_r, int month);
//---------------------------------------------------------------------------------

#endif
