/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "button.h"
#include "led_display.h"

// --- AUTO MODE--------
#define initAuto 0

#define red 1  // AUTO RED
#define yellow 2  // AUTO YELLOW
#define green 3   // AUTO GREEN

#define stop 4

extern int Auto;
extern int AUTOLINE1;  // LINE 1
extern int AUTOLINE2;  // LINE 2
//--- MANUAL MODE ------
#define initManual 0
#define MANUAL_LINE1_GO 1
#define MANUAL_LINE2_GO 2

#define MANUAL_LINE12_STOP 3

#define MANUAL_LINE12_SLOW	4

extern int MANUAL;
extern int Manual;  // FLAG MANUAL
//----SETTING MODE-------
#define initSetting 0

#define setRed 1
#define setYellow 2
#define setGreen 3

#define check 4

extern int SETTING;
extern int Setting; //FLAG SETTING

extern int Redtime, Yellowtime, Greentime; // TIME LED ON

#endif /* INC_GLOBAL_H_ */
