/*
 * secondLane.c
 *
 *  Created on: Nov 25, 2022
 *      Author: trand
 */

#include "secondLane.h"

void secondLaneTrafficLight() {
	led_buffer[3] = secondLaneCounter/10;
	led_buffer[4] = secondLaneCounter%10;
	switch (secondLaneStatus) {
		case 0:
		{
			HAL_GPIO_WritePin(GRN2_GPIO_Port, GRN2_Pin, 1);
			secondLaneCounter = grnValue;
			setTimer2(grnValue*100);
			secondLaneStatus = 3;
			break;
		}
		case 1: //RED
		{
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
			HAL_GPIO_WritePin(YLW2_GPIO_Port, YLW2_Pin, 0);
//			secondLaneCounter--;
//			if(secondLaneCounter == 0)
//			{
//				secondLaneCounter = grnValue;
//				secondLaneStatus = 3;
//			}
//			led_buffer[3] = secondLaneCounter/10;
//			led_buffer[4] = secondLaneCounter%10;
			if(timer9_flag == 1)
			{
				secondLaneCounter--;
				setTimer9(100);
			}

			if(timer2_flag == 1)
			{
				secondLaneCounter = grnValue;
				secondLaneStatus = 3;
				setTimer2(grnValue*100);
			}
			break;
		}
		case 2: //YELLOW
		{
			HAL_GPIO_WritePin(YLW2_GPIO_Port, YLW2_Pin, 1);
			HAL_GPIO_WritePin(GRN2_GPIO_Port, GRN2_Pin, 0);
//			secondLaneCounter--;
//			if(secondLaneCounter == 0) {
//				secondLaneCounter = redValue;
//				secondLaneStatus = 1;
//			}
//			led_buffer[3] = secondLaneCounter/10;
//			led_buffer[4] = secondLaneCounter%10;
			if(timer9_flag == 1)
			{
				secondLaneCounter--;
				setTimer9(100);
			}

			if(timer2_flag == 1)
			{
				secondLaneCounter = redValue;
				secondLaneStatus = 1;
				setTimer2(redValue*100);
			}
			break;
		}
		case 3: //GREEN
		{
			HAL_GPIO_WritePin(GRN2_GPIO_Port, GRN2_Pin, 1);
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
//			secondLaneCounter--;
//			if(secondLaneCounter == 0){
//				secondLaneCounter = ylwValue;
//				secondLaneStatus = 2;
//			}
//			led_buffer[3] = secondLaneCounter/10;
//			led_buffer[4] = secondLaneCounter%10;
			if(timer9_flag == 1)
			{
				secondLaneCounter--;
				setTimer9(100);
			}

			if(timer2_flag == 1)
			{
				secondLaneCounter = ylwValue;
				secondLaneStatus = 2;
				setTimer2(ylwValue*100);
			}
			break;
		}
		default:
			break;
	}
}
