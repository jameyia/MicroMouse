#include "TURN.h"

/**
 * This will cause the motor to turn right.
 * It will receive the motor counter when turn_right is called.
 * Then for each call in the isr, the counter will increment.
 * Once it has done a full TURNPERIOD, the counter will reset
 * and wait until the next call of turn_right.
 * @param counter, The motor counter from the main.
 * @return 0 if a full TURNPERIOD period was made.
 *         counter++ if it is still turning.
 */
int turn_right(int counter)
{
    if(counter == TURNPERIOD)
    {
        set_direction_left(FORWARD);
        set_direction_right(FORWARD);

        return 0;
    }
    else
    {
        set_direction_left(REVERSE);
        set_direction_right(FORWARD);

        return counter++;
    }
}

/**
 * This will cause the motor to turn left.
 * It will receive the motor counter when turn_right is called.
 * Then for each call in the isr, the counter will increment.
 * Once it has done a full TURNPERIOD, the counter will reset
 * and wait until the next call of turn_right.
 * @param counter, The motor counter from the main.
 * @return 0 if a full TURNPERIOD was made.
 *         counter++ if it is still turning.
 */
int turn_left(int counter)
{
    if(counter == TURNPERIOD)
    {
        set_direction_left(FORWARD);
        set_direction_right(FORWARD);

        return 0;
    }
    else
    {
        set_direction_left(FORWARD);
        set_direction_right(REVERSE);

        return counter++;
    }
}
