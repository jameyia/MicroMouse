/*
 * File:   MOTOR.h
 * Author: Kelly Zheng
 *
 * Created on April 14, 2015, 4:09 AM
 */
#include "CONCAT.h"
#include "COMMON.h"

#ifndef MOTOR_H
#define	MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_H */

/**
 * This sets the speed for the left motor.
 * @param speed, The speed given as an integer
 * @param upper, The pointer passed that will set TMR1H.
 * @param lower, The pointer passed that will set TMR1L.
 */
void set_left_speed(int speed, int *upper, int *lower);

/**
 * This sets the speed for the right motor.
 * @param speed, The speed given as an integer.
 * @param upper, The pointer passed that will set TMR3H.
 * @param lower, The pointer passed that will set TMR3L.
 */
void set_right_speed(int speed, int *upper, int *lower);

/**
 * Thiw will set the direction of the left motor.
 * @param direction, This is either FORWARD or REVERSE.
 * (any unexpected parameters will set the motor FORWARD)
 * (FOWARD and REVERSE are in COMMON)
 */
void set_direction_left(int direction);

/**
 * This will set the direction of the right motor.
 * @param direction, This is either FORWARD or REVERSE.
 * (any unexpected parameters will set the motor FORWARD)
 * (FORWARD and REVERSE are in COMMON)
 */
void set_direction_right(int direction);

// Pointer Tester
int test(int *x);
