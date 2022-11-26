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

int KeyReg2_0 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;

int KeyReg3_0 = NORMAL_STATE;
int KeyReg3_1 = NORMAL_STATE;
int KeyReg3_2 = NORMAL_STATE;
int KeyReg3_3 = NORMAL_STATE;

int TimerForButton1 = 200;
int TimerForButton2 = 200;
int TimerForButton3 = 200;
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Pressed() {
	if(button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}

	return 0;
}

int isButton2Pressed() {
	if(button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}

	return 0;
}

int isButton3Pressed() {
	if(button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}

	return 0;
}


void subKeyProcessForButton1() {
	button1_flag = 1;
}

void subKeyProcessForButton2() {
	button2_flag = 1;
}

void subKeyProcessForButton3() {
	button3_flag = 1;
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

void getKeyInputForButton2() {
	KeyReg2_0 = KeyReg2_1;
	KeyReg2_1 = KeyReg2_2;
	KeyReg2_2 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);

	if((KeyReg2_0 == KeyReg2_1) && (KeyReg2_1 == KeyReg2_2))
	{
		if(KeyReg2_3 != KeyReg2_2)
		{
			KeyReg2_3 = KeyReg2_2;
			if(KeyReg2_2 == PRESSED_STATE) {
				subKeyProcessForButton2();
				TimerForButton2 = 200;
			}
		}
		else
		{
			TimerForButton2--;
			if(TimerForButton2 == 0) {
				KeyReg2_3 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInputForButton3() {
	KeyReg3_0 = KeyReg3_1;
	KeyReg3_1 = KeyReg3_2;
	KeyReg3_2 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);

	if((KeyReg3_0 == KeyReg3_1) && (KeyReg3_1 == KeyReg3_2))
	{
		if(KeyReg3_3 != KeyReg3_2)
		{
			KeyReg3_3 = KeyReg3_2;
			if(KeyReg3_2 == PRESSED_STATE) {
			subKeyProcessForButton3();
			TimerForButton3 = 200;
			}
		}
		else
		{
			TimerForButton3--;
			if(TimerForButton3 == 0) {
			KeyReg3_3 = NORMAL_STATE;
			}
		}
	}
}
