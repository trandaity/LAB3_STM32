/*
 * firstLane.c
 *
 *  Created on: Nov 25, 2022
 *      Author: trand
 */

#include "firstLane.h"

void firstLaneTrafficLight() {
	switch (firstLaneStatus) {
		case 0:
		{
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
//			firstLaneCounter = redValue;
			setTimer1(redValue*100);
			firstLaneStatus = 1;
			break;
		}
		case 1: //RED
		{
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
			HAL_GPIO_WritePin(YLW1_GPIO_Port, YLW1_Pin, 0);
//			firstLaneCounter--;
//			if(firstLaneCounter == 0)
//			{
//				firstLaneCounter = grnValue;
//				firstLaneStatus = 3;
//			}
			if(timer1_flag == 1)
			{
				firstLaneStatus = 3;
				setTimer1(grnValue*100);
			}
			break;
		}
		case 2: //YELLOW
		{
			HAL_GPIO_WritePin(YLW1_GPIO_Port, YLW1_Pin, 1);
			HAL_GPIO_WritePin(GRN1_GPIO_Port, GRN1_Pin, 0);
//			firstLaneCounter--;
//			if(firstLaneCounter == 0) {
//				firstLaneCounter = redValue;
//				firstLaneStatus = 1;
//			}
			if(timer1_flag == 1)
			{
				firstLaneStatus = 1;
				setTimer1(redValue*100);
			}
			break;
		}
		case 3: //GREEN
		{
			HAL_GPIO_WritePin(GRN1_GPIO_Port, GRN1_Pin, 1);
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
//			firstLaneCounter--;
//			if(firstLaneCounter == 0){
//				firstLaneCounter = ylwValue;
//				firstLaneStatus = 2;
//			}

			if(timer1_flag == 1)
			{
				firstLaneStatus = 2;
				setTimer1(ylwValue*100);
			}
			break;
		}
		default:
			break;
	}
}
