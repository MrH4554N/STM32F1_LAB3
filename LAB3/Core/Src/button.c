/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#include "button.h"

int button1_temp0 = NORMAL_STATE;
int button1_temp1 = NORMAL_STATE;
int button1_temp2 = NORMAL_STATE;
int button1_temp3 = NORMAL_STATE;

int button2_temp0 = NORMAL_STATE;
int button2_temp1 = NORMAL_STATE;
int button2_temp2 = NORMAL_STATE;
int button2_temp3 = NORMAL_STATE;

int button3_temp0 = NORMAL_STATE;
int button3_temp1 = NORMAL_STATE;
int button3_temp2 = NORMAL_STATE;
int button3_temp3 = NORMAL_STATE;

int timePress = 0;
//int timeHold = 0;

int buttonFlag1 = 0;
int buttonFlag2 = 0;
int buttonFlag3 = 0;

//int buttonHoldFlag1 = 0;
//int buttonHoldFlag2 = 0;
//int buttonHoldFlag3 = 0;
void getbuttoninput(){
	//BUTTON 1
	button1_temp0 = button1_temp1;
	button1_temp1 = button1_temp2;
	button1_temp2 = HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin);

	button2_temp0 = button2_temp1;
	button2_temp1 = button2_temp2;
	button2_temp2 = HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin);

	if((button1_temp0 == button1_temp1) && (button1_temp1 == button1_temp2)){
		if(button1_temp3 != button1_temp2){
			button1_temp3 = button1_temp2;
			if(button1_temp2 == PRESS_STATE){
				buttonFlag1 = 1;
//				setTimer(7, timeHold);
				timePress = 200;
			}
		}
		else{
			timePress--;
			if(timePress <= 0){
				button1_temp3 = NORMAL_STATE;
				timePress = 200;
			}
		}
	}
//	if(timer_flag[7] == 1){
//		if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin) == GPIO_PIN_RESET){
//			buttonHoldFlag1 = 1;
//			buttonFlag1 = 0;
//		}
//		timer_flag[7] = 0;
//	}
//	else{
//		timePress--;
//		if(timePress <= 0){
//			button1_temp3 = NORMAL_STATE;
//			timePress = 200;
//		}
	//BUTTON 2

	if((button2_temp0 == button2_temp1) && (button2_temp1 == button2_temp2)){
		if(button2_temp3 != button2_temp2){
			button2_temp3 = button2_temp2;
			if(button2_temp2 == PRESS_STATE){
				buttonFlag2 = 1;
//				setTimer(7, timeHold);
				timePress = 200;
			}
		}
		else{
			timePress--;
			if(timePress <= 0){
				button2_temp3 = NORMAL_STATE;
				timePress = 200;
			}
		}
	}
//	if(timer_flag[7] == 1){
//			if(HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin) == GPIO_PIN_RESET){
//				buttonHoldFlag2 = 1;
//				buttonFlag2 = 0;
//			}
//			timer_flag[7] = 0;
//		}
//		else{
//			timePress--;
//			if(timePress <= 0){
//				button2_temp3 = NORMAL_STATE;
//				timePress = 200;
//		}
	//BUTTON 3
	button3_temp0 = button3_temp1;
	button3_temp1 = button3_temp2;
	button3_temp2 = HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin);
	if((button3_temp0 == button3_temp1) && (button3_temp1 == button3_temp2)){
		if(button3_temp3 != button3_temp2){
			button3_temp3 = button3_temp2;
			if(button3_temp2 == PRESS_STATE){
				buttonFlag3 = 1;
				//setTimer(7, timeHold);
				timePress = 200;
			}
		}
		else{
			timePress--;
			if(timePress <= 0){
				button3_temp3 = NORMAL_STATE;
				timePress = 200;
			}
		}
	}
}
//	if(timer_flag[7] == 1){
//				if(HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == GPIO_PIN_RESET){
//					buttonHoldFlag3 = 1;
//					buttonFlag3 = 0;
//				}
//				timer_flag[7] = 0;
//			}
//			else{
//				timePress--;
//				if(timePress <= 0){
//					button3_temp3 = NORMAL_STATE;
//					timePress = 200;
//			}
//}
int isButtonPress1(){
	if(buttonFlag1 == 1){
		buttonFlag1 = 0;
		return 1;
	}
	return 0;
}
int isButtonPress2(){
	if(buttonFlag2 == 1){
		buttonFlag2 =0;
		return 1;
	}
	return 0;
}
int isButtonPress3(){
	if(buttonFlag3 == 1){
		buttonFlag3 = 0;
		return 1;
	}
	return 0;
}


//int isButtonHold1(){
//	if(buttonHoldFlag1 == 1){
//		buttonHoldFlag1 = 0;
//		return 1;
//	}
//	return 0;
//}
//
//int isButtonHold2(){
//	if(buttonHoldFlag2 == 1){
//		buttonHoldFlag2 = 0;
//		return 1;
//	}
//	return 0;
//}
//
//int isButtonHold3(){
//	if(buttonHoldFlag3 == 1){
//		buttonHoldFlag3 = 0;
//		return 1;
//	}
//	return 0;
//}
