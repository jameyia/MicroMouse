/* 
 * File:   COMMON.h
 * Author: Kelly Zheng
 *
 * Created on April 14, 2015, 1:28 PM
 */

#ifndef COMMON_H
#define	COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_H */

// ADC
#define CHECKMR 10  // Check distance for MR
#define CHECKML 10  // Check distance for ML
#define CHECKFL 10  // Check distance for FL
#define CHECKFR 10  // CHeck distance for FR
#define MR 0        // MR sensor ID
#define ML 2        // ML sensor ID
#define FL 3        // FL sensor ID
#define FR 1        // FR sensor ID

// MAIN
#define _XTAL_FREQ 40000000 // CLOCK FREQUENCY
#define DEFAULTSPEED 53232  // DEFAULT motor speed
#define FORWARD 0           // Forward direction ID
#define REVERSE 1           // Reverse direction ID

// PID
#define OFFSET 63   // PID Offset value
#define LEFTMID 10  // PID value of ML at the middle of cell
#define RIGHTMID 10 // PID value of MR at the middle of cell
#define P 10        // PID P value
#define D 5         // PID D value

// TURN
#define TURNPERIOD 100  // Turn period for the motor