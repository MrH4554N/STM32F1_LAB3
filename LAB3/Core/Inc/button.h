/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESS_STATE 0
//#define HOLD_STATE 2

extern int buttonFlag1;
extern int buttonFlag2;
extern int buttonFlag3;

//extern int buttonHoldFlag1;
//extern int buttonHoldFlag2;
//extern int buttonHoldFlag3;

void getbuttoninput();
int isButtonPress1();
int isButtonPress2();
int isButtonPress3();

//int isButtonHold1();
//int isButtonHold2();
//int isButtonHold3();
#endif /* INC_BUTTON_H_ */
