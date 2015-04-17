#include "PID.h"

/* GLOBAL VARIABLES */
extern int errorP;
extern int errorD;
extern int old_errorP;
extern int total_error;
extern int left_base_speed;
extern int right_base_speed;
extern int adc_ml, adc_mr, adc_fl, adc_fr;
extern int left_upper, left_lower;
extern int right_upper, right_lower;

/**
 * This is the PID controller.
 */
void PID(void)
{
    if(sensor(ML, adc_ml) == 1 && sensor(MR, adc_mr) == 1)
    {
        errorP = adc_mr - adc_ml - OFFSET;
        errorD = errorP = old_errorP;
    }
    else if(sensor(ML, adc_ml))
    {
        errorP = 2 * (LEFTMID - adc_ml);
        errorD = errorP - old_errorP;
    }
    else if(sensor(MR, adc_mr))
    {
        errorP = 2 * (adc_mr - RIGHTMID);
        errorD = errorP - old_errorP;
    }
    else if(sensor(ML, adc_ml) == 0 && sensor(MR, adc_mr) == 0){
        errorP = 0;
        errorD = 0;
    }

    total_error = P * errorP + D * errorD;
    old_errorP = errorP;
    set_left_speed((left_base_speed - total_error), &left_upper, &left_lower);
    set_right_speed((right_base_speed + total_error), &right_upper, &right_lower);
}

/**
 * This is a PID tester for ml and mr.
 */
void PIDmlmr(void)
{
    if(sensor(0, adc_ml) == 1 && sensor(2, adc_mr) == 1)
    {
        errorP = adc_mr - adc_ml - OFFSET;
        errorD = errorP = old_errorP;
    }
    total_error = P * errorP + D * errorD;
    old_errorP = errorP;
    set_left_speed((left_base_speed - total_error), &left_upper, &left_lower);
    set_right_speed((right_base_speed + total_error), &right_upper, &right_lower);
}

/**
 * This is a PID tester for ml.
 */
void PIDml(void)
{
    if(sensor(0, adc_ml))
    {
        errorP = 2 * (LEFTMID - adc_ml);
        errorD = errorP - old_errorP;
    }
    
    total_error = P * errorP + D * errorD;
    old_errorP = errorP;
    set_left_speed((left_base_speed - total_error), &left_upper, &left_lower);
    set_right_speed((right_base_speed + total_error), &right_upper, &right_lower);
}

/**
 * This is a PID tester for mr.
 */
void PIDmr(void)
{
    if(sensor(2, adc_mr))
    {
        errorP = 2 * (adc_mr - RIGHTMID);
        errorD = errorP - old_errorP;
    }
    
    total_error = P * errorP + D * errorD;
    old_errorP = errorP;
    set_left_speed((left_base_speed - total_error), &left_upper, &left_lower);
    set_right_speed((right_base_speed + total_error), &right_upper, &right_lower);
}

/**
 * This is a PID tester for if mr and ml are equal.
 */
void PIDequal(void)
{
    if(sensor(0, adc_ml) == 0 && sensor(2, adc_mr) == 0){
        errorP = 0;
        errorD = 0;
    }

    total_error = P * errorP + D * errorD;
    old_errorP = errorP;
    set_left_speed((left_base_speed - total_error), &left_upper, &left_lower);
    set_right_speed((right_base_speed + total_error), &right_upper, &right_lower);
}
