/*  ADC.c
 *
 *  File to convert ADC readings to distance
 *
 */

#include "ADC.h"

// Functions to convert from ADC readings to distance
/**
 * This returns the front left distance based on linearized data.
 * @param adc_fl, The ADC value of the front left sensor.
 * @return distance_fl, The front left distance from the sensor.
 */
int fl_distance(int adc_fl)
{
    int distance_fl;

         // Use voltages to determine distances of ADC
         if(adc_fl <= 794 && adc_fl > 781)
            distance_fl = (adc_fl - 794)/(-26);
         if(adc_fl <= 781 && adc_fl > 673)
            distance_fl= (adc_fl - 782)/(-108);
         if(adc_fl <= 673 && adc_fl > 377)
            distance_fl = (adc_fl - 670)/(-195);
         if(adc_fl <= 377 && adc_fl > 127)
            distance_fl = (adc_fl - 371)/(-125);
         if(adc_fl <= 127 && adc_fl > 42)
            distance_fl = (adc_fl - 126)/(-43);
         if(adc_fl <= 42 && adc_fl > 13)
            distance_fl = (adc_fl - 38)/(-9);
         if(adc_fl > 794)
            distance_fl = 1;
         if(adc_fl <= 13)
            distance_fl = 20;

         return distance_fl;
}

/**
 * This returns the front right distance based on linearized data.
 * @param adc_fr, The ADC value of the front right sensor.
 * @return distance_fr, The front right distance from the sensor.
 */
int fr_distance(int adc_fr)
{
    int distance_fr;

        // Use voltages to determine distances of ADC
        if(adc_fr <= 917 && adc_fr < 863)
            distance_fr = (adc_fr - 917) / (-54);
        if(adc_fr <= 863 && adc_fr > 266)
            distance_fr = (adc_fr - 1016) / (-174);
        if(adc_fr <= 266 && adc_fr > 54)
            distance_fr = (adc_fr - 402) / (-36);
        if(adc_fr > 917)
            distance_fr = 1;
        if(adc_fr <= 54)
            distance_fr = 20;

    return distance_fr;
}

/**
 * This returns the middle left distance based on linearized data.
 * @param adc_ml, The ADC value of the middle left sensor.
 * @return distance_ml, The middle left distance from the sensor.
 */
int ml_distance(int adc_ml)
{
    int distance_ml;

        if(adc_ml <= 958 && adc_ml > 947)
            distance_ml = (adc_ml - 958) / (-22);
        if(adc_ml <= 947 && adc_ml > 898)
            distance_ml = (adc_ml - 947) / (-98);
        if(adc_ml <= 898 && adc_ml > 449)
            distance_ml = (adc_ml - 898) / (-449);
        if(adc_ml <= 449 && adc_ml > 225)
            distance_ml = (adc_ml - 444) / (-224);
        if(adc_ml <= 225 && adc_ml > 78)
            distance_ml = (adc_ml - 212) / (-73);
        if(adc_ml <= 78 && adc_ml > 32)
            distance_ml = (adc_ml - 74) / (-19);
        if(adc_ml <= 32 && adc_ml > 19)
            distance_ml = (adc_ml - 30) / (-5);
        if(adc_ml > 958) // If voltage is above 910 distance is between 0-4cm
            distance_ml = 1;
        if(adc_ml <= 19)
            distance_ml = 20;

    return distance_ml;
}

/**
 * This returns the middle right distance based on linearized data.
 * @param adc_mr, The ADC value of the middle right sensor.
 * @return distance_mr, The middle right distance from the sensor.
 */
int mr_distance(int adc_mr)
{
    int distance_mr;

        if(adc_mr <= 959 && adc_mr > 937)
            distance_mr = (adc_mr - 955) / (-14);
        if(adc_mr <= 937 && adc_mr > 394)
            distance_mr = (adc_mr - 932) / (-224);
        if(adc_mr <= 394 && adc_mr > 186)
            distance_mr = (adc_mr - 391) / (-79);
        if(adc_mr <= 186 && adc_mr > 111)
            distance_mr = (adc_mr - 192) / (-25);
        if(adc_mr > 959) // If voltage is above 910, distance is between 0-4cm
            distance_mr = 1;
        if(adc_mr <= 111) // if voltage is less than 50, distance is far
            distance_mr = 20;

    return distance_mr;
}

/**
 * This checks if there is a close wall.
 * @param distance, The distance from the ADC sensors.
 * @param check, The minimum distance for the wall.
 * @return 0 if the distance is greater than or equal to the check.
 *         1 if the distnace is less than the check.
 */
int has_wall(int distance, int check)
{
    int wall;

    if(distance < check)
        wall = 1;
    else
        wall = 0;

    return wall;
}

/**
 * This selects the sensor to check.
 * @param sensors, The sensor to check.
 * @param adc, The ADC value from the sensor.
 * @return The check for a wall.
 *         0 for default.
 */
int sensor(int sensors, int adc)
{
    switch(sensors)
    {
        case MR: {float distance_mr = mr_distance(adc);
                return has_wall(distance_mr, CHECKMR);}
        case FR: {float distance_fr = fr_distance(adc);
                return has_wall(distance_fr, CHECKFR);}
        case ML: {float distance_ml = ml_distance(adc);
                return has_wall(distance_ml, CHECKML);}
        case FL: {float distance_fl = fl_distance(adc);
                return has_wall(distance_fl, CHECKFL);}
        default: return 0;
    }
}
