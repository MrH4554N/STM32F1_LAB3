/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define Size 10

extern int timer_flag[Size];
void setTimer(int index, int duration);
void TimerRun(int index);

#endif /* INC_TIMER_H_ */
