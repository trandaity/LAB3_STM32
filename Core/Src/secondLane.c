/*
 * secondLane.c
 *
 *  Created on: Nov 25, 2022
 *      Author: trand
 */

#include "secondLane.h"

void secondLaneTrafficLight() {
	switch (secondLaneStatus) {
		case 0:
		{
			HAL_GPIO_WritePin(GRN2_GPIO_Port, GRN2_Pin, 1);
			secondLaneCounter = grnValue;
			secondLaneStatus = 3;
			break;
		}
		case 1: //RED
		{
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
			HAL_GPIO_WritePin(YLW2_GPIO_Port, YLW2_Pin, 0);
			secondLaneCounter--;
			if(secondLaneCounter == 0)
			{
				secondLaneCounter = grnValue;
				secondLaneStatus = 3;
			}
			break;
		}
		case 2: //YELLOW
		{
			HAL_GPIO_WritePin(YLW2_GPIO_Port, YLW2_Pin, 1);
			HAL_GPIO_WritePin(GRN2_GPIO_Port, GRN2_Pin, 0);
			secondLaneCounter--;
			if(secondLaneCounter == 0) {
				secondLaneCounter = redValue;
				secondLaneStatus = 1;
			}
			break;
		}
		case 3: //GREEN
		{
			HAL_GPIO_WritePin(GRN2_GPIO_Port, GRN2_Pin, 1);
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
			secondLaneCounter--;
			if(secondLaneCounter == 0){
				secondLaneCounter = ylwValue;
				secondLaneStatus = 2;
			}
			break;
		}
		default:
			break;
	}
}
