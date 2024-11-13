/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */
#include "fsm_auto.h"

int count0 = 0;
int count1= 0;

void Runfsm_Auto(){
	if(Manual == 1) return;
	if(Setting == 1) return;
	switch (AUTOLINE1){
		case initAuto:
			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, RESET);
			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);

			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);

			AUTOLINE1 = red;
			count0 = Redtime/1000;

			AUTOLINE2 = green;
			count1 = Greentime/1000;

			updateClockBuffer(count0, count1);

			setTimer(0, Redtime);
			setTimer(1, Greentime);
			setTimer(2, 1000);
			setTimer(3, 250);
			return;
		case red:
			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, SET);
			HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, RESET);
			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);

			if(timer_flag[0] == 1){
				AUTOLINE1 = green;
				count0 = Greentime/1000;
				updateClockBuffer(count0, count1);
				setTimer(0, Greentime);
			}
			break;
		case green:
			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, RESET);
			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, SET);

			if(timer_flag[0] == 1){
				AUTOLINE1 = yellow;
				count0 = Yellowtime/1000;
				updateClockBuffer(count0, count1);
				setTimer(0, Yellowtime);
			}
			break;
		case yellow:
			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, SET);
			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);

			if(timer_flag[0] == 1){
				AUTOLINE1 = red;
				count0 = Redtime/1000;
				updateClockBuffer(count0, count1);
				setTimer(0, Redtime);
			}
			break;
		default:
			break;
	}
	switch (AUTOLINE2) {  // LINE 2
		case red:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);

			if(timer_flag[1] == 1){
				AUTOLINE2 = green;
				count1 = Greentime/1000;
				updateClockBuffer(count0, count1);
				setTimer(1, Greentime);
			}
			break;
		case green:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);

			if(timer_flag[1] == 1){
				AUTOLINE2 = yellow;
				count1 = Yellowtime/1000;
				updateClockBuffer(count0, count1);
				setTimer(1, Yellowtime);
			}
			break;
		case yellow:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);

			if(timer_flag[1] == 1){
				AUTOLINE2 = red;
				count1 = Redtime/1000;
				updateClockBuffer(count0, count1);
				setTimer(1, Redtime);
			}
			break;
		default:
			break;
	}
	if(timer_flag[2] == 1){
		setTimer(2, 1000);
		count0--; count1--;
		updateClockBuffer(count0, count1);
	}
	if(timer_flag[3] == 1){
		setTimer(3, 250);
		Scan7SEG();
	}
}
