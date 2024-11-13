/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#include "fsm_setting.h"

void Runfsm_Setting(){

	if(Manual == 1) return;
	if(isButtonPress1() == 1){
		HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, RESET);
		HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);

		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);

		Setting = 1;
		updateClockBuffer(0, 0);
		SETTING++;
	}
	switch(SETTING){
		case initSetting:
			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, RESET);
			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);

			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);

			setTimer(3, 250);
			Redtime = 0;
			Yellowtime = 0;
			Greentime = 0;
			updateClockBuffer(0, 0);
			SETTING = setRed;
		case setRed:
			if(isButtonPress2() == 1){
				Redtime += 1000;
				updateClockBuffer(Redtime/1000, Redtime/1000);
			}
			if(timer_flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(RED0_GPIO_Port, RED0_Pin);
				HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
				setTimer(3, 250);
			}
			break;
		case setYellow:
			if(isButtonPress2() == 1){
				Yellowtime += 1000;
				updateClockBuffer(Yellowtime/1000, Yellowtime/1000);
			}
			if(timer_flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(YELLOW0_GPIO_Port, YELLOW0_Pin);
				HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
				setTimer(3, 250);
			}
			break;
		case setGreen:
			if(isButtonPress2() == 1){
				Greentime += 1000;
				updateClockBuffer(Greentime/1000, Greentime/1000);
			}
			if(timer_flag[3] == 1){
				Scan7SEG();
				HAL_GPIO_TogglePin(GREEN0_GPIO_Port, GREEN0_Pin);
				HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
				setTimer(3, 250);
			}
			break;
		case check:
			if((Redtime != 0) && (Redtime == Yellowtime + Greentime)){
				SETTING = -1;
				AUTOLINE1 = initAuto;
				Setting = 0;
				return;
			}
			SETTING = initSetting;
			break;
		default:
			break;
	}
}
