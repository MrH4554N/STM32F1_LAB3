/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

extern int led_buffer[4];

void Scan7SEG();
void display7SEG(int);
void updateClockBuffer(int, int);


#endif /* INC_LED_DISPLAY_H_ */
