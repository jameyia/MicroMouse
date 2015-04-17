/* 
 * File:   TURN.h
 * Author: Kelly Zheng
 *
 * Created on April 15, 2015, 10:47 AM
 */

#include "COMMON.h"
#include "MOTOR.h"

#ifndef TURN_H
#define	TURN_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TURN_H */

/**
 * This will cause the motor to turn right.
 * It will receive the motor counter when turn_right is called.
 * Then for each call in the isr, the counter will increment.
 * Once it has done a full TURNCOUNTER, the counter will reset
 * and wait until the next call of turn_right.
 * @param counter, The motor counter from the main.
 * @return 0 if a full TURNCOUNTER period was made.
 *         counter++ if it is still turning.
 */
int turn_right(int counter);

/**
 * This will cause the motor to turn left.
 * It will receive the motor counter when turn_right is called.
 * Then for each call in the isr, the counter will increment.
 * Once it has done a full TURNCOUNTER, the counter will reset
 * and wait until the next call of turn_right.
 * @param counter, The motor counter from the main.
 * @return 0 if a full TURNCOUNTER period was made.
 *         counter++ if it is still turning.
 */
int turn_left(int counter);
