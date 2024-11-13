/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#include "fsm_manual.h"

void Runfsm_Manual(){
	if(Setting == 1) return;

	if(Manual != 1){
		if((isButtonPress3() == 1)){
			Manual = 1;
			AUTOLINE1 = -1;
			AUTOLINE2 = -1;
			MANUAL = MANUAL_LINE1_GO;

			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);

			HAL_GPIO_WritePin(YELLOW0_GPIO_Port, YELLOW0_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);

			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);

			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		}
	}
	switch (MANUAL) {
		case MANUAL_LINE1_GO:
			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, SET);
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);

			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, RESET);

			if(isButtonPress3() == 1){
				MANUAL = MANUAL_LINE2_GO;
			}
			break;
		case MANUAL_LINE2_GO:
			HAL_GPIO_WritePin(RED0_GPIO_Port, RED0_Pin, SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);

			HAL_GPIO_WritePin(GREEN0_GPIO_Port, GREEN0_Pin, RESET);
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);

			if(isButtonPress3() == 1){
				MANUAL = MANUAL_LINE1_GO;
			}
			break;
		default:
			break;
	}

	if(Manual == 1){
		if((isButtonPress1() == 1)){
			Manual = 0;
			AUTOLINE1 = initAuto;
			AUTOLINE2 = initAuto;
			MANUAL = -1;
		}
	}

}
