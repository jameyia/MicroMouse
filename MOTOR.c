#include "MOTOR.h"

/* GLOBAL VARIABLES */
extern int direction_left;
extern int direction_right;

/**
 * This sets the speed for the left motor.
 * @param speed, The speed given as an integer
 * @param upper, The pointer passed that will set TMR1H.
 * @param lower, The pointer passed that will set TMR1L.
 */
void set_left_speed(int speed, int *upper, int *lower)
{
    int binary;
    binary = decimal_to_binary(speed);
    *upper = binary >> 8;
    *lower = binary & 0b11111111;
    
    //TMR1H = binary >> 8;
    //TMR1L = binary & 0b11111111;
}

/**
 * This sets the speed for the right motor.
 * @param speed, The speed given as an integer.
 * @param upper, The pointer passed that will set TMR3H.
 * @param lower, The pointer passed that will set TMR3L.
 */
void set_right_speed(int speed, int *upper, int *lower)
{
    int binary;
    binary = decimal_to_binary(speed);
    *upper = binary >> 8;
    *lower = binary & 0b11111111;

    //TMR3H = binary >> 8;           //Preload at 25356
    //TMR3L = binary & 0b11111111;
}

/**
 * Thiw will set the direction of the left motor.
 * @param direction, This is either FORWARD or REVERSE.
 * (any unexpected parameters will set the motor FORWARD)
 * (FOWARD and REVERSE are in COMMON)
 */
void set_direction_left(int direction)
{
    if(direction == REVERSE)
    {
        direction_left = REVERSE;
    }
    else
    {
        direction_right = FORWARD;
    }
}

/**
 * This will set the direction of the right motor.
 * @param direction, This is either FORWARD or REVERSE.
 * (any unexpected parameters will set the motor FORWARD)
 * (FORWARD and REVERSE are in COMMON)
 */
void set_direction_right(int direction)
{
    if(direction == REVERSE)
    {
        direction_right = REVERSE;
    }
    else
    {
        direction_left = FORWARD;
    }
}

/**
 * This tests pointer passing.
 */
int test(int *x)
{
    x = 1;
    return 0;
}
