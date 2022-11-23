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

void getKeyInputForButton1() {
	KeyReg1_0 = KeyReg1_1;
	KeyReg1_1 = KeyReg1_2;
	KeyReg1_2 =

}
