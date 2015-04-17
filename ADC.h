/*
 * File:   ADC.h
 * Author: Kelly Zheng
 *
 * Created on March 20, 2015, 1:10 AM
 */
#include "COMMON.h"

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

/**
 * This returns the front left distance based on linearized data.
 * @param adc_fl, The ADC value of the front left sensor.
 * @return distance_fl, The front left distance from the sensor.
 */
int fl_distance(int adc_fl);

/**
 * This returns the front right distance based on linearized data.
 * @param adc_fr, The ADC value of the front right sensor.
 * @return distance_fr, The front right distance from the sensor.
 */
int fr_distance(int adc_fr);

/**
 * This returns the middle left distance based on linearized data.
 * @param adc_ml, The ADC value of the middle left sensor.
 * @return distance_ml, The middle left distance from the sensor.
 */
int ml_distance(int adc_ml);

/**
 * This returns the middle right distance based on linearized data.
 * @param adc_mr, The ADC value of the middle right sensor.
 * @return distance_mr, The middle right distance from the sensor.
 */
int mr_distance(int adc_mr);

/**
 * This checks if there is a close wall.
 * @param distance, The distance from the ADC sensors.
 * @param check, The minimum distance for the wall.
 * @return 0 if the distance is greater than or equal to the check.
 *         1 if the distnace is less than the check.
 */
int has_wall(int distance, int check);

/**
 * This selects the sensor to check.
 * @param sensors, The sensor to check.
 * @param adc, The ADC value from the sensor.
 * @return The check for a wall.
 *         0 for default.
 */
int sensor(int sensor, int adc);
