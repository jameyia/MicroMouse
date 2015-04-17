/*
 * File:   PID.h
 * Author: Kelly Zheng
 *
 * Created on April 14, 2015, 2:14 AM
 */
#include "ADC.h"
#include "MOTOR.h"
#include "COMMON.h"

#ifndef PID_H
#define	PID_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PID_H */

/**
 * This is the PID controller.
 */
void PID(void);

// Test Helpers
/**
 * This is a PID tester for ml and mr.
 */
void PIDmlmr(void);

/**
 * This is a PID tester for ml.
 */
void PIDml(void);

/**
 * This is a PID tester for mr.
 */
void PIDmr(void);

/**
 * This is a PID tester for if mr and ml are equal.
 */
void PIDequal(void);