/*
 * button.c
 *
 *  Created on: Nov 23, 2022
 *      Author: trand
 */

#include "button.h"

int KeyReg1_0 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;

int TimerForButton1 = 200;
int button1_flag = 0;

int isButton1Pressed() {
	if(button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}

	return 0;
}

void subKeyProcessForButton1() {
	button1_flag = 1;
}

void getKeyInputForButton1() {
	KeyReg1_0 = KeyReg1_1;
	KeyReg1_1 = KeyReg1_2;
	KeyReg1_2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);

	if((KeyReg1_0 == KeyReg1_1) && (KeyReg1_1 == KeyReg1_2))
	{
		if(KeyReg1_3 != KeyReg1_2)
		{
			KeyReg1_3 = KeyReg1_2;
			if(KeyReg1_2 == PRESSED_STATE) {
				subKeyProcessForButton1();
				TimerForButton1 = 200;
			}
		}
		else
		{
			TimerForButton1--;
			if(TimerForButton1 == 0) {
				KeyReg1_3 = NORMAL_STATE;
			}
		}
	}
}
